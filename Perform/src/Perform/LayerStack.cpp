#include "pfpch.h"
#include "LayerStack.h"


namespace Perform {

	LayerStack::LayerStack()
	{
		m_LayerInsert = 0;
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		/* Add the overlay to the end */
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		/* Get the iterator position of where the layer is in the layer vector */
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			overlay->OnDetach();
			/* Delete the overlay */
			m_Layers.erase(it);
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		/* Add the layer to the next spot */
		m_Layers.emplace(m_Layers.begin() + m_LayerInsert, layer);
		m_LayerInsert++;
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		/* Get the iterator position of where the layer is in the layer vector */
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			/* Erase it and decrement the iterator position by one */
			layer->OnDetach();
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

}