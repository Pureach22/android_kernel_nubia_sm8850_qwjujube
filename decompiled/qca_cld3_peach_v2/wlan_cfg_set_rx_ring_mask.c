__int64 __fastcall wlan_cfg_set_rx_ring_mask(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x15
  int v4; // s27
  int v5; // s28

  if ( (unsigned int)a2 >= 0x12 )
  {
    __break(0x5512u);
    *(_DWORD *)(v3 - 120) = v5;
    *(_DWORD *)(v3 - 116) = v4;
    return wlan_cfg_set_rx_mon_ring_mask(result, a2, a3);
  }
  else
  {
    *(_BYTE *)(result + (unsigned int)a2 + 170) = a3;
  }
  return result;
}
