__int64 __fastcall wlan_dp_resource_mgr_timer_handler(
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
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x9
  _DWORD *v12; // x9
  unsigned __int64 StatusReg; // x9
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x9
  __int64 *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  __int64 v35; // x0
  __int64 (*v36)(void); // x8
  __int64 v37; // x9
  unsigned __int64 v44; // x10
  __int64 v45; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v46[2]; // [xsp+10h] [xbp-10h] BYREF

  v46[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v45 = 0;
  v46[0] = 0;
  v10 = *(_QWORD *)(v9 + 240);
  if ( !v10 || !*(_QWORD *)v10 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_get_num_buff_descs_info");
LABEL_17:
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: Unable to fetch DP rx desc info",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "wlan_dp_resource_mgr_timer_handler");
    goto LABEL_18;
  }
  v11 = *(_QWORD *)(*(_QWORD *)v10 + 8LL);
  if ( !v11 )
    goto LABEL_17;
  v12 = *(_DWORD **)(v11 + 264);
  if ( !v12 )
    goto LABEL_17;
  if ( *(v12 - 1) != 1944558820 )
    __break(0x8229u);
  if ( ((unsigned int (__fastcall *)(__int64, _QWORD *, __int64 *, _QWORD))v12)(v10, v46, &v45, 0) )
    goto LABEL_17;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v15 = raw_spin_lock(a1 + 27);
  }
  else
  {
    v15 = raw_spin_lock_bh(a1 + 27);
    a1[28] |= 1uLL;
  }
  v24 = *((unsigned int *)a1 + 6);
  if ( (unsigned int)v24 >= 2 )
  {
    __break(0x5512u);
    goto LABEL_33;
  }
  v25 = a1;
  if ( v46[0] <= (unsigned __int64)HIWORD(a1[v24 + 1]) )
    goto LABEL_28;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Downscale required cur_rx_buf:%llu to req_rx_buf:%llu",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wlan_dp_resource_mgr_timer_handler");
  if ( *((_BYTE *)a1 + 232) != 1 )
  {
    v35 = *(_QWORD *)(*a1 + 240);
    if ( v35 && *(_QWORD *)v35 )
    {
      v36 = *(__int64 (**)(void))(**(_QWORD **)v35 + 624LL);
      if ( v36 )
      {
        if ( *((_DWORD *)v36 - 1) != -1355198606 )
          __break(0x8228u);
        v15 = v36();
        goto LABEL_33;
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "cdp_soc_get_dp_txrx_handle");
    }
    v15 = 0;
LABEL_33:
    _X8 = (unsigned __int64 *)(v15 + 224);
    __asm { PRFM            #0x11, [X8] }
    do
      v44 = __ldxr(_X8);
    while ( __stxr(v44 & 0xFFFFFFFFFFFEFFFFLL, _X8) );
    *(_QWORD *)(v15 + 224) |= 0x100000002uLL;
    _wake_up(v15 + 232, 1, 1, 0);
    goto LABEL_27;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Downscale not required as refill de-init done",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wlan_dp_resource_mgr_post_downscale_resource_req");
LABEL_27:
  v25 = a1;
LABEL_28:
  v37 = v25[28];
  if ( (v37 & 1) != 0 )
  {
    v25[28] = v37 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v25 + 27);
  }
  else
  {
    result = raw_spin_unlock(v25 + 27);
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
