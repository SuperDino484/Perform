#pragma once

#include "Perform/Core.h"
#include "Layer.h"

#include <vector>

namespace Perform {

	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);
		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

		std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }

	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsert;
	};

}

