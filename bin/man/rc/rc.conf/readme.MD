man rc.conf

The first modifications are:

    Set “rc_configured=YES” (this modification should already have been done by the installation software.)

    Set “dhcpcd=YES” to configure your system's network using DHCP.

    Define a hostname for your machine (use a fully qualified hostname, i.e., one including domain). If you have a standalone machine you can use any name (for example, vigor3.your.domain). If your machine is connected to a network, you should supply the correct name.

    If your machine is connected to a local network or the Internet through a router, set the defaultroute variable to the IP address of your router (sometimes called a default gateway). For example, “defaultroute=192.168.1.1”.
