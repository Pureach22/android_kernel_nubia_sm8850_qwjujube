__int64 __fastcall target_if_cfr_subscribe_ppdu_desc(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x8
  __int64 *v13; // x19
  __int64 v14; // x8
  _DWORD *v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  _DWORD *v18; // x8
  __int64 v19; // x8
  __int64 v20; // x8
  _DWORD *v21; // x8
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  const char *v32; // x2
  __int64 v33; // x8
  _DWORD *v34; // x8
  const char *v35; // x3

  if ( !a1 )
  {
    v32 = "%s: Null pdev";
LABEL_29:
    qdf_trace_msg(0x6Au, 2u, v32, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cfr_subscribe_ppdu_desc");
    return 4;
  }
  if ( !wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu) )
  {
    v32 = "%s: pcfr is NULL";
    goto LABEL_29;
  }
  v12 = *(_QWORD *)(a1 + 80);
  if ( !v12 )
  {
    v32 = "%s: Null psoc";
    goto LABEL_29;
  }
  v13 = *(__int64 **)(v12 + 2808);
  if ( !v13 )
  {
    v32 = "%s: Null soc";
    goto LABEL_29;
  }
  g_cfr_subscribe = (__int64)target_cfr_callback;
  qword_92E570 = a1;
  if ( *v13 )
  {
    v14 = *(_QWORD *)(*v13 + 168);
    if ( v14 )
    {
      v15 = *(_DWORD **)(v14 + 8);
      if ( v15 )
      {
        if ( *(v15 - 1) != 1944199495 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64 *, _QWORD, _QWORD))v15)(v13, 0, a2 & 1);
      }
    }
    v16 = *v13;
    if ( *v13 )
    {
LABEL_12:
      v17 = *(_QWORD *)(v16 + 24);
      if ( v17 )
      {
        v18 = *(_DWORD **)(v17 + 48);
        if ( v18 )
        {
          if ( *(v18 - 1) != 1150052289 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64 *, __int64, _QWORD))v18)(v13, 1, a2 & 1);
        }
      }
      v19 = *v13;
      if ( (a2 & 1) != 0 )
        goto LABEL_18;
      goto LABEL_33;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", a3, a4, a5, a6, a7, a8, a9, a10, "cdp_set_cfr_rcc");
    v16 = *v13;
    if ( *v13 )
      goto LABEL_12;
  }
  qdf_trace_msg(0x45u, 1u, "%s invalid instance", a3, a4, a5, a6, a7, a8, a9, a10, "cdp_enable_mon_reap_timer");
  v19 = *v13;
  if ( (a2 & 1) != 0 )
  {
LABEL_18:
    if ( v19 )
    {
      v20 = *(_QWORD *)(v19 + 8);
      if ( v20 )
      {
        v21 = *(_DWORD **)(v20 + 64);
        if ( v21 )
        {
          if ( *(v21 - 1) != -1878000702 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64 *, _QWORD, __int64 *, __int64))v21)(v13, 0, &g_cfr_subscribe, 268);
          if ( (_DWORD)result )
          {
            v31 = "%s: wdi event sub fail";
LABEL_40:
            qdf_trace_msg(0x6Au, 2u, v31, v23, v24, v25, v26, v27, v28, v29, v30, "target_if_cfr_subscribe_ppdu_desc");
            return 16;
          }
          return result;
        }
      }
      return 0;
    }
    v35 = "cdp_wdi_event_sub";
LABEL_43:
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", a3, a4, a5, a6, a7, a8, a9, a10, v35);
    return 0;
  }
LABEL_33:
  if ( !v19 )
  {
    v35 = "cdp_wdi_event_unsub";
    goto LABEL_43;
  }
  v33 = *(_QWORD *)(v19 + 8);
  if ( !v33 )
    return 0;
  v34 = *(_DWORD **)(v33 + 72);
  if ( !v34 )
    return 0;
  if ( *(v34 - 1) != -1878000702 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64 *, _QWORD, __int64 *, __int64))v34)(v13, 0, &g_cfr_subscribe, 268);
  if ( (_DWORD)result )
  {
    v31 = "%s: wdi event unsub fail";
    goto LABEL_40;
  }
  return result;
}
