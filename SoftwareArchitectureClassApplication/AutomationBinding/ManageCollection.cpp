#include "ManageCollection.h"
#include "Block.h"
#include "BlockBuilder.h"
#include <iostream>

AutomationAPI::ManageCollection::ManageCollection(int guid) : m_guid(guid)
{

}

AutomationAPI::ManageCollection::~ManageCollection()
{

}

AutomationAPI::BlockBuilder* AutomationAPI::ManageCollection::CreateBlockBuilder(AutomationAPI::Block* block)
{
	if (block == nullptr)
	{
		std::cout << "Block is creation mode" << std::endl;
	}
	else
	{
		std::cout << "Block is edit/query mode" << std::endl;
	}


	return nullptr;

}
