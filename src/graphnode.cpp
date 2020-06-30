#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //========== Task 0 Solved here ========//
    //==== chatbot deleted here without allocation, should be done by the owner ====//
    
    //  delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

//==========Task 4=========//
// Create a vector of unique ptr.
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    // push back copies, so move it
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////

//======== Task 5============//
//here is the move constructor called
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    //======== Task 5============//
    // Here is the move assignment called
    _chatBot = std::move(chatbot);

    //======== Task 5============//
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    //======== Task 5============//
    // Use of move semantics for passing to new node
    newNode->MoveChatbotHere(std::move(_chatBot));

    //======== Task 5============//
    // Move already invalidates, so here not required.
   // _chatBot = nullptr; // invalidate pointer at source
}

////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //==========Task 4=========//
    // Return the raw pointer
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}