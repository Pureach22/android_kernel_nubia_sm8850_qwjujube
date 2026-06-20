void __fastcall rmnet_get_strings(int a1, int a2, char *dest)
{
  if ( a2 == 1 )
  {
    memcpy(dest, "Checksum ok", 0x700u);
    memcpy(dest + 1792, "MAP Cmd last version", 0x3E0u);
    memcpy(dest + 2784, "LL TX queues", 0x200u);
    memcpy(dest + 3296, "QMAP RX success", 0xA0u);
  }
}
