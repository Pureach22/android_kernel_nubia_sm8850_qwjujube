__int64 __fastcall scm_scan_update_mlme_by_bssinfo(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x0
  unsigned int v13; // w19
  const char *v14; // x2
  __int64 comp_private_obj; // x0
  __int64 v18; // x8
  __int64 v19; // x19
  __int64 v20; // x23
  unsigned __int64 StatusReg; // x8
  __int64 next_node; // x21
  __int64 v23; // x8
  __int64 result; // x0
  __int64 v25; // x26
  unsigned int v26; // w24
  size_t v28; // x2
  unsigned __int64 v29; // x8
  unsigned int v30; // w22
  unsigned int v31; // w23
  unsigned int v32; // w25
  int v33; // w20
  __int64 v34; // x26
  __int64 system_time; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x8
  unsigned int v58; // w9
  __int64 v59; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v60[2]; // [xsp+20h] [xbp-10h] BYREF

  v60[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 80);
  if ( !v12 )
  {
    v14 = "%s: psoc is NULL";
LABEL_21:
    qdf_trace_msg(0x15u, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "scm_scan_update_mlme_by_bssinfo");
LABEL_22:
    result = 4;
    goto LABEL_23;
  }
  if ( !a1 )
  {
    qdf_trace_msg(0x15u, 2u, "%s: pdev is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_pdev_get_scan_db");
    goto LABEL_20;
  }
  v13 = *(unsigned __int8 *)(a1 + 40);
  if ( v13 >= 2 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: invalid pdev_id %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_pdevid_get_scan_db",
      *(unsigned __int8 *)(a1 + 40));
    goto LABEL_20;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v12, 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdevid_get_scan_db",
      57);
    goto LABEL_20;
  }
  v18 = comp_private_obj + 1560LL * v13;
  v19 = v18 + 32;
  if ( v18 == -32 )
  {
LABEL_20:
    v14 = "%s: scan_db is NULL";
    goto LABEL_21;
  }
  v20 = v19 + 24LL * (*(_BYTE *)(a2 + 42) & 0x3F);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v19 + 8);
  }
  else
  {
    raw_spin_lock_bh(v19 + 8);
    *(_QWORD *)(v19 + 16) |= 1uLL;
  }
  v60[0] = 0;
  v59 = 0;
  qdf_list_peek_front((_QWORD *)(v20 + 24), v60);
  next_node = v60[0];
  if ( !v60[0] )
  {
LABEL_16:
    next_node = 0;
    v23 = *(_QWORD *)(v19 + 16);
    if ( (v23 & 1) != 0 )
      goto LABEL_25;
LABEL_17:
    raw_spin_unlock(v19 + 8);
    if ( next_node )
      goto LABEL_28;
    goto LABEL_22;
  }
  while ( *(_DWORD *)(next_node + 20) != 306772034 )
  {
    qdf_list_peek_next((_QWORD *)(v20 + 24), (_QWORD *)next_node, &v59);
    next_node = v59;
    v59 = 0;
    v60[0] = next_node;
    if ( !next_node )
      goto LABEL_16;
  }
  _X8 = (unsigned int *)(next_node + 16);
  __asm { PRFM            #0x11, [X8] }
  do
    v58 = __ldxr(_X8);
  while ( __stxr(v58 + 1, _X8) );
  v23 = *(_QWORD *)(v19 + 16);
  if ( (v23 & 1) == 0 )
    goto LABEL_17;
LABEL_25:
  *(_QWORD *)(v19 + 16) = v23 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v19 + 8);
  if ( !next_node )
    goto LABEL_22;
LABEL_28:
  while ( 1 )
  {
    v25 = *(_QWORD *)(next_node + 24);
    v26 = v25 + 1;
    if ( *(_DWORD *)(a2 + 37) == *(_DWORD *)(v25 + 1)
      && *(unsigned __int16 *)(a2 + 41) == *(unsigned __int16 *)(v25 + 5) )
    {
      v28 = *(unsigned __int8 *)(a2 + 4);
      if ( (_DWORD)v28 == *(unsigned __int8 *)(v25 + 13)
        && !(unsigned int)qdf_mem_cmp((const void *)(a2 + 5), (const void *)(v25 + 14), v28)
        && *(_DWORD *)a2 == *(_DWORD *)(v25 + 1192) )
      {
        break;
      }
    }
    next_node = scm_get_next_node(v19, v20 + 24, next_node);
    if ( !next_node )
      goto LABEL_22;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v29 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v29 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v29 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v19 + 8);
  }
  else
  {
    raw_spin_lock_bh(v19 + 8);
    *(_QWORD *)(v19 + 16) |= 1uLL;
  }
  qdf_mem_copy((void *)(v25 + 1224), a3, 0x20u);
  if ( v25 == -1 )
  {
    v31 = 0;
    v30 = 0;
    v32 = 0;
  }
  else
  {
    v30 = *(unsigned __int8 *)(v25 + 1);
    v26 = *(unsigned __int8 *)(v25 + 2);
    v31 = *(unsigned __int8 *)(v25 + 3);
    v32 = *(unsigned __int8 *)(v25 + 6);
  }
  v33 = a3[5];
  v34 = *(_QWORD *)(v25 + 88);
  system_time = qdf_mc_timer_get_system_time();
  qdf_trace_msg(
    0x15u,
    8u,
    "%s: BSSID: %02x:%02x:%02x:**:**:%02x set assoc_state to %d with age %lu ms",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "scm_scan_update_mlme_by_bssinfo",
    v30,
    v26,
    v31,
    v32,
    v33,
    system_time - v34);
  scm_scan_entry_put_ref(v19, next_node, 0, v44, v45, v46, v47, v48, v49, v50, v51);
  v52 = *(_QWORD *)(v19 + 16);
  if ( (v52 & 1) != 0 )
  {
    *(_QWORD *)(v19 + 16) = v52 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v19 + 8);
  }
  else
  {
    raw_spin_unlock(v19 + 8);
  }
  result = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
