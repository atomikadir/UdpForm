#pragma once

using namespace System::Net::Sockets;
using namespace System;
using namespace System::Net;

ref class UdpManager
{
public:
	UdpManager(UdpClient^ udpClient);

private:
	UdpClient^ UdpClientInstance;
};

