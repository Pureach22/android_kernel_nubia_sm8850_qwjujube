void __fastcall policy_mgr_fill_trim_chan(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w21
  unsigned int operation_chan_freq; // w0
  unsigned int v17; // w20
  __int16 v18; // w8
  __int64 v19; // [xsp+8h] [xbp-28h]

  if ( *(_DWORD *)(a2 + 16) == 1 )
  {
    v19 = v4;
    if ( !(unsigned int)wlan_vdev_is_up() )
    {
      v15 = *(unsigned __int16 *)(a2 + 160);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: vdev %d - peer count %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "policy_mgr_fill_trim_chan",
        *(unsigned __int8 *)(a2 + 104),
        *(unsigned __int16 *)(a2 + 160),
        v3,
        v19);
      if ( v15 >= 2 )
      {
        operation_chan_freq = wlan_get_operation_chan_freq(a2);
        if ( operation_chan_freq )
        {
          v17 = operation_chan_freq;
          if ( wlan_reg_is_5ghz_ch_freq(operation_chan_freq) )
          {
            v18 = 1;
LABEL_7:
            *(_WORD *)(a3 + 8) |= v18;
            return;
          }
          if ( wlan_reg_is_24ghz_ch_freq(v17) && *(_DWORD *)(a3 + 4) == 1 && (*(_BYTE *)a3 & 2) == 0 )
          {
            v18 = 2;
            goto LABEL_7;
          }
        }
      }
    }
  }
}
