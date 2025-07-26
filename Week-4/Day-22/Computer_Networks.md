# Day 22 - CRT Training: Computer Networks

This file includes essential topics discussed in Day 22 of CRT training including OSI layers, protocols, routing, IP addressing, TCP vs UDP, basic socket programming in C, and network tools. Great for interview prep & revision!

# 📘 1. OSI Model (Open Systems Interconnection)
The OSI model is a conceptual framework used to understand network interactions in 7 layers:
```

| Layer No | Layer Name   | Description                                         | Example Protocols/Technologies |
| -------- | ------------ | --------------------------------------------------- | ------------------------------ |
| 7        | Application  | User interaction; interface for network services    | HTTP, FTP, SMTP                |
| 6        | Presentation | Data translation, encryption, compression           | SSL/TLS, JPEG, ASCII           |
| 5        | Session      | Manages sessions between applications               | NetBIOS, RPC                   |
| 4        | Transport    | Ensures reliable data transfer with error checking  | TCP, UDP                       |
| 3        | Network      | Handles routing and logical addressing              | IP, ICMP, IGMP                 |
| 2        | Data Link    | Physical addressing, error detection                | MAC, PPP, Ethernet             |
| 1        | Physical     | Transmission of raw bitstreams over physical medium | Cables, Switches, Hubs         |
```

🔐 Encryption occurs in Presentation Layer.

📡 Routing is handled in Network Layer.

# 📘 2. Common Protocols
# ✅ Web Protocols
```

| Protocol | Purpose                 | Port |
| -------- | ----------------------- | ---- |
| HTTP     | Web browsing (insecure) | 80   |
| HTTPS    | Secure web browsing     | 443  |
| FTP      | File transfer           | 21   |
| SFTP     | Secure file transfer    | 22   |
```

# ✅ Email Protocols

```
| Protocol | Function                          | Port   |
| -------- | --------------------------------- | ------ |
| SMTP     | Send emails                       | 25/587 |
| POP3     | Download & delete from server     | 110    |
| IMAP     | Sync emails with multiple devices | 143    |
```

# 📘 3. IP Addressing
✅ Types:
IPv4: 32-bit address (e.g., 192.168.1.1)

IPv6: 128-bit address (e.g., 2001:0db8:85a3::8a2e:0370:7334)

```
| Class | Range                     | Default Subnet Mask |
| ----- | ------------------------- | ------------------- |
| A     | 1.0.0.0 - 126.0.0.0       | 255.0.0.0           |
| B     | 128.0.0.0 - 191.255.0.0   | 255.255.0.0         |
| C     | 192.0.0.0 - 223.255.255.0 | 255.255.255.0       |
```

# ✅ Subnetting:
Used to divide a network into sub-networks.

Example:

IP: 192.168.1.0/24

Subnet mask: 255.255.255.0

# 📘 4. TCP vs UDP
```

| Feature     | TCP                                    | UDP                        |
| ----------- | -------------------------------------- | -------------------------- |
| Type        | Connection-oriented                    | Connectionless             |
| Reliability | Reliable, with ACKs and retransmission | Unreliable, best-effort    |
| Use Cases   | HTTP, FTP, Email                       | DNS, VoIP, Video streaming |
| Speed       | Slower due to overhead                 | Faster                     |

Number of hosts = 2^8 - 2 = 254

```

🛠 TCP is used where accuracy is critical; UDP is preferred where speed matters more.

# 📘 5. Routing
✅ What is Routing?
Routing is the process of selecting a path for traffic in a network. It occurs at the Network Layer.

✅ Types of Routing:
Static Routing: Manually configured paths.

Dynamic Routing: Automatically adjusts routes using protocols.

✅ Dynamic Routing Protocols:
```

| Protocol | Description             |
| -------- | ----------------------- |
| RIP      | Uses hop count (max 15) |
| OSPF     | Uses link state info    |
| BGP      | Border gateway for ISPs |
```

# 📘 6. Network Devices
```
| Device   | Function                                            |
| -------- | --------------------------------------------------- |
| Router   | Routes packets between different networks (Layer 3) |
| Switch   | Connects devices in a LAN using MAC addresses (L2)  |
| Hub      | Broadcasts data to all devices (Layer 1)            |
| Modem    | Converts analog to digital signals                  |
| Repeater | Amplifies signals to extend range                   |
```

📢 Hub broadcasts to all, while Switch sends only to target device.

# 📘 7. Network Communication Types
```

| Type      | Description              | Example                  |
| --------- | ------------------------ | ------------------------ |
| Unicast   | One-to-one communication | Web browsing             |
| Multicast | One-to-many (selected)   | IPTV, Video conferencing |
| Broadcast | One-to-all on a network  | ARP request              |
```

# 📘 8. Networking Tools
```

| Tool         | Use                                    |
| ------------ | -------------------------------------- |
| `ping`       | Checks connectivity to a host          |
| `traceroute` | Shows path packets take to destination |
| `nslookup`   | Resolves domain names to IPs           |
| `netstat`    | Displays active connections & ports    |
```
```
ping google.com
traceroute yahoo.com
netstat -an
```

# 📘 9. Security: SSL/TLS and HTTPS
HTTPS = HTTP + SSL/TLS

Ensures:

Encryption: Your data is hidden from third parties.

Authentication: Ensures you're talking to the intended website.

Data Integrity: No tampering during transmission.

🔐 Encryption occurs at the Presentation Layer (Layer 6) in OSI Model.

# 📘 10. Basic Socket Programming in C

✅ TCP Server (Simplified)

```
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>

int main() {
    int serverSocket, clientSocket;
    char buffer[1024] = "Hello Client";
    struct sockaddr_in serverAddr;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);
    clientSocket = accept(serverSocket, NULL, NULL);

    send(clientSocket, buffer, strlen(buffer), 0);
    close(serverSocket);
    return 0;
}
```

## OSI → Protocols → Routing → IP Addressing → TCP/UDP → Devices → Tools → Security
