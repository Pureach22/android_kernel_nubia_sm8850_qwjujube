__int64 __fastcall wlan_cfg_set_rx_wbm_rel_ring_mask(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  if ( a2 >= 0x12 )
  {
    __break(0x5512u);
    JUMPOUT(0x519F40);
  }
  *(_BYTE *)(a1 + a2 + 296) = a3;
  return a3;
}
