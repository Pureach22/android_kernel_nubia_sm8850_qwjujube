bool __fastcall dp_rx_is_sg_formation_required(_DWORD *a1)
{
  return (*a1 & 0x7C000007) == 2 || (*a1 & 0xF80007) == 2621441;
}
