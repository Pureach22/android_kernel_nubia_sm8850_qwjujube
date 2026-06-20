__int64 __fastcall dp_tx_delete_flow_pool(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 ref_by_id_5; // x0
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
  unsigned __int64 StatusReg; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x23
  char v33; // w22
  __int64 v34; // x0
  unsigned int v35; // w8
  unsigned int v42; // w10
  unsigned int v45; // w9
  __int64 v47; // x8
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned __int64 v65; // x8
  char v66; // w8
  char v67; // w8
  __int64 v68; // x8
  __int64 v69; // x4
  const char *v70; // x2
  unsigned int v71; // w1
  int v72; // w8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x8
  void (__fastcall *v82)(__int64, __int64, __int64); // x8
  __int64 v83; // x0
  void (__fastcall *v84)(__int64, __int64, __int64); // x8
  __int64 v85; // x0
  void (__fastcall *v86)(__int64, __int64, __int64); // x8
  __int64 v87; // x0
  void (__fastcall *v88)(__int64, __int64, __int64); // x8
  __int64 v89; // x0
  __int64 v90; // x8
  __int64 v91; // x0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x19
  unsigned int *v101; // x8
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 v110; // x8
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7

  if ( !a1 || !a2 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: pool or soc is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "dp_tx_delete_flow_pool");
    return 12;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: pool_id %d create_cnt=%d, avail_desc=%d, size=%d, status=%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_tx_delete_flow_pool",
    *(unsigned __int8 *)(a2 + 58),
    *(unsigned __int8 *)(a2 + 272),
    *(unsigned __int16 *)(a2 + 60),
    *(unsigned __int16 *)(a2 + 56),
    *(_DWORD *)(a2 + 64));
  ref_by_id_5 = dp_vdev_get_ref_by_id_5(a1, *(unsigned __int8 *)(a2 + 58), 21);
  if ( !ref_by_id_5 )
    goto LABEL_31;
  v21 = (unsigned int *)*(unsigned int *)(ref_by_id_5 + 32);
  v22 = ref_by_id_5;
  if ( (_DWORD)v21 != 3 )
  {
    dp_vdev_unref_delete(a1, ref_by_id_5, 0x15u, v21, v13, v14, v15, v16, v17, v18, v19, v20);
    goto LABEL_31;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(ref_by_id_5 + 136);
    v32 = *(_QWORD *)(v22 + 120);
    if ( v32 )
      goto LABEL_9;
LABEL_27:
    v33 = 1;
    goto LABEL_28;
  }
  raw_spin_lock_bh(ref_by_id_5 + 136);
  *(_QWORD *)(v22 + 144) |= 1uLL;
  v32 = *(_QWORD *)(v22 + 120);
  if ( !v32 )
    goto LABEL_27;
LABEL_9:
  v33 = 1;
  do
  {
    v34 = v32;
    v32 = *(_QWORD *)(v32 + 56);
    v35 = *(_DWORD *)(v34 + 40);
    while ( v35 )
    {
      _X12 = (unsigned int *)(v34 + 40);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v42 = __ldxr(_X12);
        if ( v42 != v35 )
          break;
        if ( !__stlxr(v35 + 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v42 == v35;
      v35 = v42;
      if ( _ZF )
      {
        _X8 = (unsigned int *)(v34 + 304);
        __asm { PRFM            #0x11, [X8] }
        do
          v45 = __ldxr(_X8);
        while ( __stxr(v45 + 1, _X8) );
        v33 &= (*(_BYTE *)(v34 + 120) & 0x14) != 4;
        dp_peer_unref_delete(v34, 0xCu, v24, v25, v26, v27, v28, v29, v30, v31);
        break;
      }
    }
  }
  while ( v32 );
LABEL_28:
  v47 = *(_QWORD *)(v22 + 144);
  if ( (v47 & 1) != 0 )
  {
    *(_QWORD *)(v22 + 144) = v47 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v22 + 136);
  }
  else
  {
    raw_spin_unlock(v22 + 136);
  }
  dp_vdev_unref_delete(a1, v22, 0x15u, v48, v49, v50, v51, v52, v53, v54, v55, v56);
  if ( (v33 & 1) == 0 )
  {
    v69 = *(unsigned __int8 *)(a2 + 58);
    v70 = "%s: skip pool id %d delete as it's not allowed";
    v71 = 5;
LABEL_45:
    qdf_trace_msg(0x45u, v71, v70, v57, v58, v59, v60, v61, v62, v63, v64, "dp_tx_delete_flow_pool", v69);
    return 4294967285LL;
  }
LABEL_31:
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v65 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v65 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v65 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 256);
    v66 = *(_BYTE *)(a2 + 272);
    if ( v66 )
      goto LABEL_35;
LABEL_72:
    v110 = *(_QWORD *)(a2 + 264);
    if ( (v110 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 264) = v110 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 256);
    }
    else
    {
      raw_spin_unlock(a2 + 256);
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: flow pool either not created or already deleted",
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      "dp_tx_delete_flow_pool");
    return 4294967294LL;
  }
  raw_spin_lock_bh(a2 + 256);
  *(_QWORD *)(a2 + 264) |= 1uLL;
  v66 = *(_BYTE *)(a2 + 272);
  if ( !v66 )
    goto LABEL_72;
LABEL_35:
  v67 = v66 - 1;
  *(_BYTE *)(a2 + 272) = v67;
  if ( v67 )
  {
    v68 = *(_QWORD *)(a2 + 264);
    if ( (v68 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 264) = v68 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 256);
    }
    else
    {
      raw_spin_unlock(a2 + 256);
    }
    v69 = *(unsigned __int8 *)(a2 + 272);
    v70 = "%s: pool is still attached, pending detach %d";
    v71 = 2;
    goto LABEL_45;
  }
  if ( *(unsigned __int16 *)(a2 + 60) >= (unsigned int)*(unsigned __int16 *)(a2 + 56) )
  {
    v73 = ((double (__fastcall *)(__int64, _QWORD, _QWORD))dp_tx_desc_pool_deinit)(a1, *(unsigned __int8 *)(a2 + 58), 0);
    dp_tx_desc_pool_free(a1, *(_BYTE *)(a2 + 58), v73, v74, v75, v76, v77, v78, v79, v80);
    v81 = *(_QWORD *)(a2 + 264);
    if ( (v81 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 264) = v81 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 256);
    }
    else
    {
      raw_spin_unlock(a2 + 256);
    }
    return 0;
  }
  v72 = *(_DWORD *)(a2 + 64);
  *(_DWORD *)(a2 + 64) = 5;
  if ( v72 > 2 )
  {
    if ( v72 == 3 )
    {
LABEL_58:
      v86 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 12872);
      v87 = *(unsigned __int8 *)(a2 + 58);
      if ( *((_DWORD *)v86 - 1) != 694643930 )
        __break(0x8228u);
      v86(v87, 14, 10);
      goto LABEL_61;
    }
    if ( v72 != 4 )
      goto LABEL_64;
LABEL_55:
    v84 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 12872);
    v85 = *(unsigned __int8 *)(a2 + 58);
    if ( *((_DWORD *)v84 - 1) != 694643930 )
      __break(0x8228u);
    v84(v85, 12, 11);
    goto LABEL_58;
  }
  if ( v72 == 1 )
  {
    v82 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 12872);
    v83 = *(unsigned __int8 *)(a2 + 58);
    if ( *((_DWORD *)v82 - 1) != 694643930 )
      __break(0x8228u);
    v82(v83, 10, 12);
    goto LABEL_55;
  }
  if ( v72 == 2 )
  {
LABEL_61:
    v88 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 12872);
    v89 = *(unsigned __int8 *)(a2 + 58);
    if ( *((_DWORD *)v88 - 1) != 694643930 )
      __break(0x8228u);
    v88(v89, 17, 9);
  }
LABEL_64:
  v90 = *(_QWORD *)(a2 + 264);
  if ( (v90 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 264) = v90 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 256);
  }
  else
  {
    raw_spin_unlock(a2 + 256);
  }
  v91 = dp_vdev_get_ref_by_id_5(a1, *(unsigned __int8 *)(a2 + 58), 21);
  if ( v91 )
  {
    v100 = v91;
    dp_tx_desc_flush(*(_QWORD *)(v91 + 24), v91, 0, v92, v93, v94, v95, v96, v97, v98, v99);
    dp_vdev_unref_delete(a1, v100, 0x15u, v101, v102, v103, v104, v105, v106, v107, v108, v109);
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: avail desc less than pool size",
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    v99,
    "dp_tx_delete_flow_pool");
  return 4294967285LL;
}
