__int64 __fastcall dp_reset_monitor_mode_unlock(
        _QWORD *a1,
        char a2,
        char a3,
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
  __int64 v13; // x21
  __int64 v14; // x8
  int v15; // w22
  _DWORD *v16; // x8
  __int64 v17; // x0
  char v18; // w25
  __int64 v19; // x8
  __int64 v20; // x8
  void (__fastcall *v21)(_QWORD); // x8
  const char *v23; // x2
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x9
  __int64 v34; // x9
  __int64 v35; // x8

  if ( a2 )
    return 16;
  v11 = a1[9];
  if ( !v11 )
    return 16;
  v13 = *(_QWORD *)(v11 + 95560);
  v14 = *(_QWORD *)(*a1 + 24LL);
  v15 = *(unsigned __int8 *)(a1[5] + 804LL);
  if ( v14 )
  {
    v16 = *(_DWORD **)(v14 + 32);
    if ( v16 )
    {
      v17 = a1[9];
      v18 = a3;
      if ( *(v16 - 1) != 381362779 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v16)(v17, 0);
      a3 = v18;
      *(_BYTE *)(v13 + 37094) = 0;
      *(_WORD *)(v13 + 37092) = 0;
    }
  }
  if ( !*(_DWORD *)(v13 + 39100) )
  {
    if ( !a3 )
    {
      if ( (*(_BYTE *)(v13 + 39274) & 1) == 0 )
        dp_mon_filter_reset_mon_mode(v11);
      goto LABEL_22;
    }
    v19 = *(_QWORD *)(*(_QWORD *)(v11 + 8) + 20056LL);
    if ( v19 )
    {
      v20 = *(_QWORD *)(v19 + 416);
      if ( v20 )
      {
        v21 = *(void (__fastcall **)(_QWORD))(v20 + 984);
        if ( v21 )
        {
          if ( *((_DWORD *)v21 - 1) != -1557217772 )
            __break(0x8228u);
          v21(v11);
          goto LABEL_22;
        }
      }
      v23 = "%s: callback not registered";
    }
    else
    {
      v23 = "%s: monitor soc is NULL";
    }
    qdf_trace_msg(0x92u, 8u, v23, a4, a5, a6, a7, a8, a9, a10, a11, "dp_monitor_lite_mon_disable_rx");
  }
LABEL_22:
  if ( (unsigned int)dp_mon_filter_update(v11) )
    qdf_trace_msg(
      0x85u,
      2u,
      "%s: %pK: Failed to reset monitor filters",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "dp_reset_monitor_mode_unlock",
      a1);
  if ( !v15 )
    goto LABEL_28;
  v33 = *(_QWORD *)(v11 + 95560);
  *(_QWORD *)(v33 + 16) = 0;
  *(_BYTE *)(v33 + 9) = -1;
  if ( v15 == 1
    || (v34 = *(_QWORD *)(v11 + 95560), *(_QWORD *)(v34 + 18544) = 0, *(_BYTE *)(v34 + 18537) = -1, v15 == 2)
    || (v35 = *(_QWORD *)(v11 + 95560) + 36864LL, *(_QWORD *)(v35 + 208) = 0, *(_BYTE *)(v35 + 201) = -1, v15 == 3) )
  {
LABEL_28:
    *(_BYTE *)v13 = 0;
    return 0;
  }
  else
  {
    __break(0x5512u);
    __asm { STGP            XZR, X0, [X12],#-0xD8 }
    return dp_pdev_set_mu_sniffer();
  }
}
