void __fastcall scm_filter_6g_and_indoor_freq(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  unsigned __int64 v11; // x23
  unsigned int v12; // w20
  __int64 *v13; // x26
  unsigned __int64 v14; // x4
  __int64 v15; // x8
  __int64 v16; // x10

  if ( *(_BYTE *)(a10 + 120) )
  {
    v11 = 0;
    v12 = 0;
    v13 = (__int64 *)(a10 + 124);
    while ( v11 != 102 )
    {
      if ( !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)v13) && (wlan_reg_is_freq_indoor() & 1) == 0 )
      {
        if ( v12 > 0x66 )
          break;
        v15 = a10 + 124 + 12LL * v12;
        v16 = *v13;
        ++v12;
        *(_DWORD *)(v15 + 8) = *((_DWORD *)v13 + 2);
        *(_QWORD *)v15 = v16;
      }
      v14 = *(unsigned __int8 *)(a10 + 120);
      ++v11;
      v13 = (__int64 *)((char *)v13 + 12);
      if ( v11 >= v14 )
        goto LABEL_10;
    }
    __break(0x5512u);
    wlan_scan_cfg_get_passive_dwelltime();
  }
  else
  {
    v12 = 0;
    LODWORD(v14) = 0;
LABEL_10:
    if ( v12 < (unsigned int)v14 )
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: 6g and indoor channel chan skipped (%d, %d)",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "scm_filter_6g_and_indoor_freq");
    *(_BYTE *)(a10 + 120) = v12;
  }
}
