bool __fastcall dp_rx_check_pkt_len(_QWORD *a1, unsigned int a2)
{
  unsigned int v4; // w8
  __int64 v7; // x10

  v4 = (unsigned __int16)wlan_cfg_rx_buffer_size(a1[5]);
  if ( v4 < a2 && a1 != nullptr )
  {
    v7 = a1[1720] + a2;
    ++a1[1719];
    a1[1720] = v7;
  }
  return v4 < a2;
}
