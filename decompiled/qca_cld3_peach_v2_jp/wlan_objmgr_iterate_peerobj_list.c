__int64 __fastcall wlan_objmgr_iterate_peerobj_list(
        __int64 a1,
        double (__fastcall *a2)(__int64, __int64, __int64),
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int64 StatusReg; // x8
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x23
  int v27; // w0
  __int64 v28; // x25
  int v29; // w24
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  __int64 result; // x0
  __int64 v48; // x8
  unsigned int v49; // w20
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v64; // w9
  unsigned int v66; // w9
  _QWORD v67[2]; // [xsp+0h] [xbp-10h] BYREF

  v67[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    qdf_trace_msg(0x57u, 2u, "%s: VDEV is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_objmgr_iterate_peerobj_list");
LABEL_24:
    result = 16;
    goto LABEL_25;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1272);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1272);
    *(_QWORD *)(a1 + 1280) |= 1uLL;
  }
  if ( *(_DWORD *)(a1 + 1264) != 1 )
  {
    v48 = *(_QWORD *)(a1 + 1280);
    v49 = *(unsigned __int8 *)(a1 + 104);
    if ( (v48 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1280) = v48 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1272);
    }
    else
    {
      raw_spin_unlock(a1 + 1272);
    }
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: VDEV is not in create state:%d: vdev-id:%d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wlan_objmgr_iterate_peerobj_list",
      *(unsigned int *)(a1 + 1264),
      v49);
    goto LABEL_24;
  }
  _X8 = (unsigned int *)(a1 + 168);
  __asm { PRFM            #0x11, [X8] }
  do
    v64 = __ldxr(_X8);
  while ( __stxr(v64 + 1, _X8) );
  if ( a4 < 0x6E )
    _X8 = (unsigned int *)(a1 + 4LL * a4 + 172);
  else
    __break(0x5512u);
  __asm { PRFM            #0x11, [X8] }
  do
    v66 = __ldxr(_X8);
  while ( __stxr(v66 + 1, _X8) );
  v67[0] = 0;
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 128), v67) )
  {
    v17 = (unsigned int *)v67[0];
    v26 = v67[0] - 16LL;
    if ( v67[0] != 16 )
    {
      do
      {
        v67[0] = 0;
        v27 = qdf_list_peek_next((_QWORD *)(a1 + 128), (_QWORD *)(v26 + 16), v67);
        v28 = v67[0];
        v29 = v27;
        if ( !(unsigned int)wlan_objmgr_peer_try_get_ref(v26, a4, v30, v31, v32, v33, v34, v35, v36, v37) )
        {
          if ( *((_DWORD *)a2 - 1) != -1796333613 )
            __break(0x8236u);
          v38 = a2(a1, v26, a3);
          wlan_objmgr_peer_release_ref(v26, a4, v38, v39, v40, v41, v42, v43, v44, v45);
        }
        if ( v29 )
          break;
        v26 = v28 - 16;
      }
      while ( v28 != 16 );
    }
  }
  wlan_objmgr_vdev_release_ref(a1, a4, v17, v18, v19, v20, v21, v22, v23, v24, v25);
  v46 = *(_QWORD *)(a1 + 1280);
  if ( (v46 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1280) = v46 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1272);
  }
  else
  {
    raw_spin_unlock(a1 + 1272);
  }
  result = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
