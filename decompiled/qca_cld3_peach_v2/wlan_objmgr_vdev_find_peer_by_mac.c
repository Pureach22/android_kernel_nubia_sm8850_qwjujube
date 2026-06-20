__int64 __fastcall wlan_objmgr_vdev_find_peer_by_mac(
        __int64 a1,
        const void *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 StatusReg; // x8
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  int v25; // w0
  __int64 v26; // x24
  int v27; // w23
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int *v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x8
  __int64 v46; // x8
  unsigned int v47; // w20
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v57; // x8
  unsigned int v64; // w9
  unsigned int v66; // w9
  _QWORD v67[2]; // [xsp+0h] [xbp-10h] BYREF

  v67[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    qdf_trace_msg(0x57u, 2u, "%s: VDEV is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_objmgr_vdev_find_peer_by_mac");
LABEL_22:
    v24 = 0;
    goto LABEL_23;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1344);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1344);
    *(_QWORD *)(a1 + 1352) |= 1uLL;
  }
  if ( *(_DWORD *)(a1 + 1336) != 1 )
  {
    v46 = *(_QWORD *)(a1 + 1352);
    v47 = *(unsigned __int8 *)(a1 + 168);
    if ( (v46 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v46 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
    }
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: VDEV is not in create state:%d: vdev-id:%d",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "wlan_objmgr_vdev_find_peer_by_mac",
      *(unsigned int *)(a1 + 1336),
      v47);
    goto LABEL_22;
  }
  _X8 = (unsigned int *)(a1 + 240);
  __asm { PRFM            #0x11, [X8] }
  do
    v64 = __ldxr(_X8);
  while ( __stxr(v64 + 1, _X8) );
  if ( a3 < 0x6E )
    _X8 = (unsigned int *)(a1 + 4LL * a3 + 244);
  else
    __break(0x5512u);
  __asm { PRFM            #0x11, [X8] }
  do
    v66 = __ldxr(_X8);
  while ( __stxr(v66 + 1, _X8) );
  v67[0] = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 192), v67)
    || (v15 = (unsigned int *)v67[0], v24 = v67[0] - 16LL, v67[0] == 16) )
  {
LABEL_16:
    wlan_objmgr_vdev_release_ref(a1, a3, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    v45 = *(_QWORD *)(a1 + 1352);
    if ( (v45 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v45 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
    }
    goto LABEL_22;
  }
  while ( 1 )
  {
    v67[0] = 0;
    v25 = qdf_list_peek_next((_QWORD *)(a1 + 192), (_QWORD *)(v24 + 16), v67);
    v26 = v67[0];
    v27 = v25;
    if ( (unsigned int)wlan_objmgr_peer_try_get_ref(v24, a3, v28, v29, v30, v31, v32, v33, v34, v35) )
      goto LABEL_14;
    if ( !(unsigned int)qdf_mem_cmp(a2, (const void *)(v24 + 48), 6u) )
      break;
    wlan_objmgr_peer_release_ref(v24, a3, v37, v38, v39, v40, v41, v42, v43, v44);
LABEL_14:
    if ( !v27 )
    {
      v24 = v26 - 16;
      if ( v26 != 16 )
        continue;
    }
    goto LABEL_16;
  }
  wlan_objmgr_vdev_release_ref(a1, a3, v36, v37, v38, v39, v40, v41, v42, v43, v44);
  v57 = *(_QWORD *)(a1 + 1352);
  if ( (v57 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1352) = v57 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1344);
  }
  else
  {
    raw_spin_unlock(a1 + 1344);
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v24;
}
