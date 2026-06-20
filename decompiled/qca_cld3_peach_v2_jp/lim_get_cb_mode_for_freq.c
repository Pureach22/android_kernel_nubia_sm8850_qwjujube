__int64 __fastcall lim_get_cb_mode_for_freq(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x21
  unsigned int v5; // w20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22

  v3 = a1 + 0x4000;
  v5 = *(_DWORD *)(a1 + 17124);
  if ( wlan_reg_is_24ghz_ch_freq(a3) )
  {
    if ( (wlan_cm_get_force_20mhz_in_24ghz(*(_QWORD *)(a2 + 16), v6, v7, v8, v9, v10, v11, v12, v13) & 1) != 0 )
    {
      v22 = jiffies;
      if ( lim_get_cb_mode_for_freq___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev %d force 20 Mhz in 2.4 GHz",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_get_cb_mode_for_freq",
          *(unsigned __int8 *)(a2 + 10));
        v5 = 0;
        lim_get_cb_mode_for_freq___last_ticks = v22;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return *(unsigned int *)(v3 + 736);
    }
  }
  return v5;
}
