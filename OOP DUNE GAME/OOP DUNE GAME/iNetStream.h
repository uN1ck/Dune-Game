#pragma once
using namespace System::IO;

class iNetStream
{
public:		virtual void saveToStream(BinaryWriter ^ value) = 0;
public:		virtual void loadFromStream(BinaryReader ^ value) = 0;
};