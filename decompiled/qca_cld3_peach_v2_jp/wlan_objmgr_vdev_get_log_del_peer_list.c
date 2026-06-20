__int64 __fastcall wlan_objmgr_vdev_get_log_del_peer_list(
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int *v21; // x8
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w8
  __int64 v32; // x23
  unsigned __int64 v33; // x25
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x26
  int v44; // w24
  __int64 v45; // x8
  _QWORD *v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x8
  __int64 v56; // x8
  __int64 v57; // x8
  unsigned int v65; // w9
  unsigned int v67; // w9
  _QWORD v68[2]; // [xsp+0h] [xbp-10h] BYREF

  v68[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 1264) != 1 )
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: Invalid state vdev:%d state:%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_objmgr_vdev_get_log_del_peer_list",
      *(unsigned __int8 *)(a1 + 104));
LABEL_42:
    v22 = 0;
    goto LABEL_43;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 1272);
      *(_QWORD *)(a1 + 1280) |= 1uLL;
      if ( *(_WORD *)(a1 + 160) )
        goto LABEL_6;
      goto LABEL_40;
    }
  }
  raw_spin_lock(a1 + 1272);
  if ( !*(_WORD *)(a1 + 160) )
  {
LABEL_40:
    v57 = *(_QWORD *)(a1 + 1280);
    if ( (v57 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1280) = v57 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1272);
    }
    else
    {
      raw_spin_unlock(a1 + 1272);
    }
    goto LABEL_42;
  }
LABEL_6:
  if ( a1 )
  {
    _X8 = (unsigned int *)(a1 + 168);
    __asm { PRFM            #0x11, [X8] }
    do
      v65 = __ldxr(_X8);
    while ( __stxr(v65 + 1, _X8) );
    if ( a2 < 0x6E )
      _X8 = (unsigned int *)(a1 + 4LL * a2 + 172);
    else
      __break(0x5512u);
    __asm { PRFM            #0x11, [X8] }
    do
      v67 = __ldxr(_X8);
    while ( __stxr(v67 + 1, _X8) );
  }
  else
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: vdev obj is NULL for id:%d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_objmgr_vdev_get_ref",
      a2);
  }
  v22 = _qdf_mem_malloc(0x18u, "wlan_obj_vdev_populate_logically_del_peerlist", 802);
  if ( !v22 )
    goto LABEL_36;
  v31 = *(unsigned __int16 *)(a1 + 162);
  *(_QWORD *)v22 = v22;
  *(_QWORD *)(v22 + 8) = v22;
  *(_DWORD *)(v22 + 16) = 0;
  *(_DWORD *)(v22 + 20) = v31;
  v68[0] = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 128), v68) )
    goto LABEL_34;
  v32 = v68[0] - 16LL;
  if ( v68[0] == 16 )
    goto LABEL_34;
  v33 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v33 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v32 + 760);
    }
    else
    {
      raw_spin_lock_bh(v32 + 760);
      *(__int64 *)((char *)&qword_2FC + v32 + 4) |= 1uLL;
    }
    v68[0] = 0;
    v34 = qdf_list_peek_next((_QWORD *)(a1 + 128), (_QWORD *)(v32 + 16), v68);
    v43 = v68[0];
    v44 = v34;
    if ( *(_DWORD *)((char *)&unk_2F0 + v32) == 6 )
    {
      if ( *(_DWORD *)((char *)&qword_60 + v32) )
        break;
    }
    v55 = *(__int64 *)((char *)&qword_2FC + v32 + 4);
    if ( (v55 & 1) != 0 )
    {
      *(__int64 *)((char *)&qword_2FC + v32 + 4) = v55 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v32 + 760);
      if ( v44 )
        goto LABEL_34;
    }
    else
    {
      raw_spin_unlock(v32 + 760);
      if ( v44 )
        goto LABEL_34;
    }
LABEL_16:
    v32 = v43 - 16;
    if ( v43 == 16 )
      goto LABEL_34;
  }
  wlan_objmgr_peer_get_ref(v32, a2, v35, v36, v37, v38, v39, v40, v41, v42);
  v45 = *(__int64 *)((char *)&qword_2FC + v32 + 4);
  if ( (v45 & 1) != 0 )
  {
    *(__int64 *)((char *)&qword_2FC + v32 + 4) = v45 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v32 + 760);
  }
  else
  {
    raw_spin_unlock(v32 + 760);
  }
  v46 = (_QWORD *)_qdf_mem_malloc(0x18u, "wlan_obj_vdev_populate_logically_del_peerlist", 818);
  if ( v46 )
  {
    v46[2] = v32;
    qdf_list_insert_front((_QWORD *)v22, v46);
    if ( v44 )
      goto LABEL_34;
    goto LABEL_16;
  }
  wlan_objmgr_peer_release_ref(v32, a2, v47, v48, v49, v50, v51, v52, v53, v54);
LABEL_34:
  if ( qdf_list_empty((_QWORD *)v22) )
  {
    _qdf_mem_free(v22);
    v22 = 0;
  }
LABEL_36:
  wlan_objmgr_vdev_release_ref(a1, a2, v21, v23, v24, v25, v26, v27, v28, v29, v30);
  v56 = *(_QWORD *)(a1 + 1280);
  if ( (v56 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1280) = v56 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1272);
  }
  else
  {
    raw_spin_unlock(a1 + 1272);
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return v22;
}
