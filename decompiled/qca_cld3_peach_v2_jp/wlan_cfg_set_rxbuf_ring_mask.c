__int64 __fastcall wlan_cfg_set_rxbuf_ring_mask(__int64 result, __int64 a2, __int64 a3)
{
  if ( (unsigned int)a2 >= 0x12 )
  {
    __break(0x5512u);
    return wlan_cfg_set_rx_err_ring_mask(result, a2, a3);
  }
  else
  {
    *(_BYTE *)(result + (unsigned int)a2 + 170) = a3;
  }
  return result;
}
