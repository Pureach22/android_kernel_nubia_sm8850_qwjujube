__int64 __fastcall _wlan_objmgr_peer_obj_destroy(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x4
  __int64 v19; // x20
  __int64 v20; // x21
  __int64 (__fastcall *v21)(__int64, __int64); // x8
  int v22; // w10
  __int64 v23; // x1
  unsigned __int64 StatusReg; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x4
  int v34; // w8
  int v35; // w20
  __int64 v36; // x8
  __int64 result; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7

  if ( !a1 )
    return qdf_trace_msg(
             0x57u,
             2u,
             "%s: PEER is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "__wlan_objmgr_peer_obj_destroy");
  qdf_trace_msg(
    0x57u,
    8u,
    "%s: Physically deleting peer %02x:%02x:%02x:**:**:%02x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "__wlan_objmgr_peer_obj_destroy",
    *(unsigned __int8 *)(a1 + 48),
    *(unsigned __int8 *)(a1 + 49),
    *(unsigned __int8 *)(a1 + 50),
    *(unsigned __int8 *)(a1 + 53));
  v18 = *(unsigned int *)(a1 + 752);
  if ( (_DWORD)v18 != 6 )
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: PEER object del is not invoked obj_state:%d peer %02x:%02x:%02x:**:**:%02x",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_objmgr_peer_obj_destroy",
      v18,
      *(unsigned __int8 *)(a1 + 48),
      *(unsigned __int8 *)(a1 + 49),
      *(unsigned __int8 *)(a1 + 50),
      *(unsigned __int8 *)(a1 + 53));
  v19 = 536;
  v20 = 9544;
  do
  {
    v21 = *(__int64 (__fastcall **)(__int64, __int64))(g_umac_glb_obj + v20 - 432);
    if ( v21 && ((v22 = *(_DWORD *)(a1 + v19), v23 = *(_QWORD *)(g_umac_glb_obj + v20), v22 == 40) || !v22) )
    {
      if ( *((_DWORD *)v21 - 1) != 154176445 )
        __break(0x8228u);
      *(_DWORD *)(a1 + v19) = v21(a1, v23);
    }
    else
    {
      *(_DWORD *)(a1 + v19) = 39;
    }
    v19 += 4;
    v20 += 8;
  }
  while ( v19 != 752 );
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
  v33 = 0;
  while ( 1 )
  {
    v34 = *(_DWORD *)(a1 + 4 * v33 + 536);
    if ( v34 != 40 )
      break;
    if ( !*(_QWORD *)(a1 + 8 * v33 + 104) )
    {
      v35 = 40;
      v36 = *(_QWORD *)(a1 + 768);
      if ( (v36 & 1) != 0 )
        goto LABEL_33;
LABEL_27:
      result = raw_spin_unlock(a1 + 760);
      if ( v35 == 16 )
        return result;
      goto LABEL_28;
    }
LABEL_19:
    if ( ++v33 == 54 )
    {
      v35 = 0;
      v36 = *(_QWORD *)(a1 + 768);
      if ( (v36 & 1) != 0 )
        goto LABEL_33;
      goto LABEL_27;
    }
  }
  if ( v34 != 2 && v34 != 16 )
    goto LABEL_19;
  qdf_trace_msg(
    0x57u,
    2u,
    "%s: Peer comp object(id:%d) alloc fail",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "wlan_objmgr_peer_object_status");
  v35 = 16;
  v36 = *(_QWORD *)(a1 + 768);
  if ( (v36 & 1) == 0 )
    goto LABEL_27;
LABEL_33:
  *(_QWORD *)(a1 + 768) = v36 & 0xFFFFFFFFFFFFFFFELL;
  result = raw_spin_unlock_bh(a1 + 760);
  if ( v35 == 16 )
    return result;
LABEL_28:
  if ( v35 != 40 )
    return wlan_objmgr_peer_obj_free(a1, v38, v39, v40, v41, v42, v43, v44, v45);
  *(_DWORD *)(a1 + 752) = 4;
  return result;
}
