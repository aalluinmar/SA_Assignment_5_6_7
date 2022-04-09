#pragma once
#include "AutomationBindingExports.h"
namespace AutomationAPI
{
	class BlockBuilder;
	class Block;

	class AUTOMATIONBINDING_API ManageCollection
	{
		public:
			ManageCollection(int guid);

			virtual ~ManageCollection();

			BlockBuilder* CreateBlockBuilder(Block* block);


		private:
			int m_guid;
	};
}
