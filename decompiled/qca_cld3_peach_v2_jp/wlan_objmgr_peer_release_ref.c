__int64 __fastcall wlan_objmgr_peer_release_ref(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v19; // w9
  unsigned int v20; // w9
  __int64 v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int64 v30; // x8
  __int64 v31; // x9
  __int64 v32; // x20
  __int64 v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x2
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  if ( !a1 )
    return qdf_trace_msg(
             0x57u,
             2u,
             "%s: peer obj is NULL for %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_objmgr_peer_release_ref",
             a2);
  if ( !*(_DWORD *)(a1 + 96) )
    return qdf_trace_msg(
             0x57u,
             2u,
             "%s: peer(%02x:%02x:%02x:**:**:%02x) ref cnt is 0",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_objmgr_peer_release_ref",
             *(unsigned __int8 *)(a1 + 48),
             *(unsigned __int8 *)(a1 + 49),
             *(unsigned __int8 *)(a1 + 50),
             *(unsigned __int8 *)(a1 + 53));
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 760);
  }
  else
  {
    raw_spin_lock_bh(a1 + 760);
    *(_QWORD *)(a1 + 768) |= 1uLL;
  }
  _X8 = (unsigned int *)(a1 + 96);
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v19 = __ldxr(_X8);
    v20 = v19 - 1;
  }
  while ( __stlxr(v20, _X8) );
  __dmb(0xBu);
  v21 = *(_QWORD *)(a1 + 768);
  if ( v20 )
  {
    if ( (v21 & 1) == 0 )
      return raw_spin_unlock(a1 + 760);
    *(_QWORD *)(a1 + 768) = v21 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(a1 + 760);
  }
  if ( (v21 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 768) = v21 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 760);
  }
  else
  {
    raw_spin_unlock(a1 + 760);
  }
  v30 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v30 + 16) & 0xFFFF00) == 0
    && !*(_DWORD *)(v30 + 16)
    && (_ReadStatusReg(DAIF) & 0x80) == 0
    && !*(_DWORD *)(v30 + 1412) )
  {
    return _wlan_objmgr_peer_obj_destroy(a1);
  }
  v31 = *(_QWORD *)(a1 + 88);
  if ( !v31 )
  {
    v42 = "%s: VDEV is NULL for peer(%02x:%02x:%02x:**:**:%02x)";
LABEL_33:
    qdf_trace_msg(
      0x57u,
      2u,
      v42,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlan_peer_obj_free_enqueue",
      *(unsigned __int8 *)(a1 + 48),
      *(unsigned __int8 *)(a1 + 49),
      *(unsigned __int8 *)(a1 + 50),
      *(unsigned __int8 *)(a1 + 53));
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: enqueue failure, call free obj directly",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "wlan_objmgr_peer_obj_destroy");
    return _wlan_objmgr_peer_obj_destroy(a1);
  }
  v32 = *(_QWORD *)(v31 + 152);
  if ( !v32 )
  {
    v42 = "%s: PDEV is NULL for peer(%02x:%02x:%02x:**:**:%02x)";
    goto LABEL_33;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (*(_DWORD *)(v30 + 16) & 0xF0000) != 0
    || (*(_DWORD *)(v30 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v32 + 1256);
  }
  else
  {
    raw_spin_lock_bh(v32 + 1256);
    *(_QWORD *)(v32 + 1264) |= 1uLL;
  }
  qdf_list_insert_back((_QWORD *)(v32 + 1272), (_QWORD *)(a1 + 32));
  v33 = *(_QWORD *)(v32 + 1264);
  ++*(_DWORD *)(v32 + 1344);
  if ( (v33 & 1) != 0 )
  {
    *(_QWORD *)(v32 + 1264) = v33 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v32 + 1256);
  }
  else
  {
    raw_spin_unlock(v32 + 1256);
  }
  qdf_trace_msg(
    0x57u,
    8u,
    "%s: active_work_cnt %u list size %u peer 0x%pK(%02x:%02x:%02x:**:**:%02x)",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "wlan_peer_obj_free_enqueue",
    *(unsigned int *)(v32 + 1344),
    *(unsigned int *)(v32 + 1288),
    a1,
    *(unsigned __int8 *)(a1 + 48),
    *(unsigned __int8 *)(a1 + 49),
    *(unsigned __int8 *)(a1 + 50),
    *(unsigned __int8 *)(a1 + 53));
  return queue_work_on(32, system_wq, v32 + 1296);
}
