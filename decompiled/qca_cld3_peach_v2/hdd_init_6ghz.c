__int64 __fastcall hdd_init_6ghz(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x2
  unsigned int v20; // w1
  __int64 v21; // x22
  char *v22; // x23
  int v23; // w24
  unsigned __int8 v24; // w0
  __int64 result; // x0
  int v26; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a1[3];
  v26 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_init_6ghz");
  if ( (unsigned int)wlan_mlme_get_band_capability(*a1, &v26) )
  {
    v19 = "%s: Failed to get MLME Band Capability";
    v20 = 2;
  }
  else
  {
    if ( (v26 & 4) != 0 )
    {
      qdf_mem_set(&hdd_channels_6_ghz, 0xF00u, 0);
      v21 = 0;
      v22 = (char *)&unk_8D590A;
      v23 = (unsigned __int16)wlan_reg_min_6ghz_chan_freq();
      do
      {
        *(_DWORD *)(v22 - 10) = 3;
        *(_DWORD *)(v22 - 6) = v23 + v21;
        v24 = wlan_reg_freq_to_chan(a1[1], v23 + (int)v21, v11, v12, v13, v14, v15, v16, v17, v18);
        v21 += 20;
        *(_QWORD *)(v22 + 2) = 1;
        *(_WORD *)v22 = v24;
        *(_DWORD *)(v22 + 10) = 0;
        v22 += 64;
      }
      while ( v21 != 1200 );
      *(_QWORD *)(v10 + 352) = &wlan_hdd_band_6_ghz;
      v19 = "%s: exit";
      wlan_hdd_band_6_ghz = (__int64)&hdd_channels_6_ghz;
      *(_DWORD *)(*(_QWORD *)(v10 + 352) + 20LL) = 60;
    }
    else
    {
      v19 = "%s: 6ghz band not enabled";
    }
    v20 = 8;
  }
  result = qdf_trace_msg(0x33u, v20, v19, v11, v12, v13, v14, v15, v16, v17, v18, "hdd_init_6ghz");
  _ReadStatusReg(SP_EL0);
  return result;
}
