__int64 __fastcall hdd_capture_tsf_internal(
        __int64 a1,
        int *a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  const char *v14; // x2
  __int64 v16; // x9
  __int64 v17; // x0
  unsigned int v18; // w22
  int v19; // w19
  const char *v20; // x2
  const char *v21; // x2
  int v22; // w8
  unsigned int v29; // w9
  signed int v30; // w9
  unsigned int v31; // w20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  if ( !a1 || !a2 )
  {
    v14 = "%s: invalid pointer";
    goto LABEL_8;
  }
  if ( a3 == 1 )
  {
    v11 = *(_QWORD *)(a1 + 24);
    if ( !v11 )
    {
      v14 = "%s: invalid hdd context";
      goto LABEL_8;
    }
    if ( (unsigned int)_wlan_hdd_validate_context(
                         *(_QWORD *)(a1 + 24),
                         (__int64)"hdd_capture_tsf_internal",
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10,
                         a11) )
    {
      v14 = "%s: hdd context validation failed";
LABEL_8:
      qdf_trace_msg(0x33u, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_capture_tsf_internal");
      return 1;
    }
    v16 = *(_QWORD *)(a1 + 24);
    if ( v16 )
    {
      if ( *(_DWORD *)(v16 + 3232) )
      {
        v17 = *(_QWORD *)(a1 + 52824);
        v18 = *(_DWORD *)(a1 + 40) & 0xFFFFFFFD;
        if ( (*(_QWORD *)(v17 + 4416) & 2) == 0 && v18 == 1 )
        {
          v19 = 7;
          v20 = "%s: Soft AP / P2p GO not beaconing";
LABEL_24:
          qdf_trace_msg(0x33u, 2u, v20, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_tsf_check_conn_state");
          *a2 = v19;
          return 0;
        }
        if ( !hdd_cm_is_vdev_associated((_DWORD *)v17) && !v18 )
        {
          v19 = 1;
          v20 = "%s: failed to cap tsf, not connect with ap";
          goto LABEL_24;
        }
        _X8 = (unsigned int *)(v11 + 3236);
        *a2 = 0;
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v29 = __ldxr(_X8);
          v30 = v29 + 1;
        }
        while ( __stlxr(v30, _X8) );
        __dmb(0xBu);
        if ( v30 < 2 )
        {
          *(_QWORD *)(v11 + 3240) = a1;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: +ioctl issue cap tsf cmd",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "hdd_capture_tsf_internal");
          qdf_mc_timer_start(a1 + 38976, 0x1F4u);
          *(_QWORD *)(a1 + 38936) = 0;
          *a2 = 0;
          v31 = hdd_capture_tsf_internal(a1, a2);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: -ioctl return cap tsf cmd",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "hdd_capture_tsf_internal");
          return v31;
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: current in capture state",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "hdd_capture_tsf_internal");
        v22 = 3;
LABEL_20:
        *a2 = v22;
        return 0;
      }
      v21 = "%s: TSF is not initialized";
    }
    else
    {
      v21 = "%s: invalid hdd context";
    }
    qdf_trace_msg(0x33u, 2u, v21, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_tsf_is_initialized");
    v22 = 8;
    goto LABEL_20;
  }
  return 1;
}
