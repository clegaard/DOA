#pragma once
template<class T>
struct Node
{
	Node(T info = T(), Node<T>* next = nullptr): info(info), next(next)
	{}
	T info;
	Node<T>* next;
	Node<T>* previous;
};
