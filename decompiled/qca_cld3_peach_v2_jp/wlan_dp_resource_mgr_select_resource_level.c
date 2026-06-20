__int64 __fastcall wlan_dp_resource_mgr_select_resource_level(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  unsigned __int64 v10; // x19
  int v11; // w8
  __int64 v12; // x9
  __int64 v13; // x8
  unsigned __int64 v14; // x8
  bool v15; // cc
  unsigned int v16; // w8
  unsigned int v17; // w9
  __int64 v18; // x0
  __int64 (*v19)(void); // x8
  const char *v20; // x2
  const char *v21; // x3
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  unsigned int multiplier; // w0
  unsigned __int64 v39; // x10

  v9 = a1;
  if ( *(_BYTE *)(a1 + 28) == 1 )
  {
    v10 = *(unsigned __int16 *)(a1 + 20);
    v11 = *(_DWORD *)(a1 + 136);
    if ( !v11 )
      goto LABEL_11;
  }
  else
  {
    v10 = 0;
    v11 = *(_DWORD *)(a1 + 136);
    if ( !v11 )
      goto LABEL_11;
  }
  if ( (unsigned int)(v11 - 3) < 0xFFFFFFFE )
  {
    __break(0x5512u);
    goto LABEL_31;
  }
  v12 = *(_QWORD *)(a1 + 200);
  if ( v12 )
    v10 += *(_QWORD *)(v12 + 72);
  if ( v11 != 1 )
  {
    v13 = *(_QWORD *)(a1 + 208);
    if ( v13 )
      v10 += *(_QWORD *)(v13 + 72);
  }
LABEL_11:
  v14 = *(unsigned __int16 *)(a1 + 12);
  *(_QWORD *)(a1 + 32) = v10;
  v15 = v10 > v14;
  v16 = *(_DWORD *)(a1 + 24);
  v17 = v15;
  *(_DWORD *)(a1 + 24) = v17;
  if ( v16 < v17 )
  {
    v18 = *(_QWORD *)(*(_QWORD *)a1 + 240LL);
    if ( v18 && *(_QWORD *)v18 )
    {
      v19 = *(__int64 (**)(void))(**(_QWORD **)v18 + 624LL);
      if ( v19 )
      {
        if ( *((_DWORD *)v19 - 1) != -1355198606 )
          __break(0x8228u);
        a1 = v19();
        goto LABEL_31;
      }
    }
    else
    {
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_soc_get_dp_txrx_handle");
    }
    a1 = 0;
LABEL_31:
    _X8 = (unsigned __int64 *)(a1 + 224);
    __asm { PRFM            #0x11, [X8] }
    do
      v39 = __ldxr(_X8);
    while ( __stxr(v39 & 0xFFFFFFFEFFFFFFFFLL, _X8) );
    *(_QWORD *)(a1 + 224) |= 0x10002uLL;
    _wake_up(a1 + 232, 1, 1, 0);
    return qdf_trace_msg(
             0x45u,
             5u,
             "%s: Resource level:%u selected for tput:%llu req_tput:%llu",
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             "wlan_dp_resource_mgr_select_resource_level",
             *(unsigned int *)(v9 + 24),
             *(_QWORD *)(v9 + 32),
             v10);
  }
  if ( v16 > v17 )
  {
    if ( *(_BYTE *)(a1 + 232) != 1 )
    {
      v30 = jiffies;
      multiplier = qdf_timer_get_multiplier();
      mod_timer(v9 + 144, v30 + 250LL * multiplier);
      return qdf_trace_msg(
               0x45u,
               5u,
               "%s: Resource level:%u selected for tput:%llu req_tput:%llu",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "wlan_dp_resource_mgr_select_resource_level",
               *(unsigned int *)(v9 + 24),
               *(_QWORD *)(v9 + 32),
               v10);
    }
    v20 = "%s: Downscale not required as refill de-init done";
    v21 = "wlan_dp_resource_mgr_post_downscale_resource_req";
  }
  else
  {
    v20 = "%s: Resource level change not required";
    v21 = "wlan_dp_resource_mgr_select_resource_level";
  }
  qdf_trace_msg(0x45u, 5u, v20, a2, a3, a4, a5, a6, a7, a8, a9, v21);
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: Resource level:%u selected for tput:%llu req_tput:%llu",
           v22,
           v23,
           v24,
           v25,
           v26,
           v27,
           v28,
           v29,
           "wlan_dp_resource_mgr_select_resource_level",
           *(unsigned int *)(v9 + 24),
           *(_QWORD *)(v9 + 32),
           v10);
}
