__int64 __fastcall dp_vdev_detach_wifi3(_QWORD *a1, unsigned __int8 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x20
  __int64 *v10; // x25
  unsigned int v11; // w8
  unsigned int v18; // w10
  _DWORD *v19; // x8
  __int64 v20; // x23
  __int64 v21; // x0
  __int64 v22; // x24
  unsigned __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x3
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  char is_target_ready; // w24
  unsigned __int64 v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned __int64 v52; // x8
  __int64 v53; // x8
  _QWORD *v54; // x24
  unsigned __int64 v55; // x8
  __int64 v56; // x22
  _QWORD *v57; // x0
  _QWORD *v58; // x21
  _QWORD *v59; // x9
  _QWORD *v60; // x10
  __int64 v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x8
  __int64 *v71; // x0
  __int64 *v72; // x9
  int v73; // w8
  unsigned __int64 v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x8
  __int64 v84; // x8
  unsigned int *v85; // x8
  unsigned __int64 v86; // x8
  __int64 *v87; // x8
  __int64 v88; // x8
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned int *v97; // x8
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  __int64 v107; // x8
  __int64 v108; // x8
  unsigned int **v109; // x9
  unsigned int ***v110; // x8
  unsigned int *v111; // x8
  unsigned int v114; // w9
  __int64 v115; // x8
  __int64 v116; // [xsp+8h] [xbp-8h]

  if ( a2 > 5u )
    return 16;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2373);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2373);
    a1[2374] |= 1uLL;
  }
  v9 = a1[a2 + 1620];
  if ( !v9 )
  {
LABEL_79:
    v107 = a1[2374];
    if ( (v107 & 1) != 0 )
    {
      a1[2374] = v107 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2373);
    }
    else
    {
      raw_spin_unlock(a1 + 2373);
    }
    return 16;
  }
  v10 = (__int64 *)(v9 + 43328);
  v11 = *(_DWORD *)(v9 + 43384);
  do
  {
    if ( !v11 )
      goto LABEL_79;
    _X12 = (unsigned int *)(v9 + 43384);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v18 = __ldxr(_X12);
      if ( v18 != v11 )
        break;
      if ( !__stlxr(v11 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v18 == v11;
    v11 = v18;
  }
  while ( !_ZF );
  while ( 1 )
  {
    _X8 = (unsigned int *)(v9 + 43416);
    __asm { PRFM            #0x11, [X8] }
    do
      v114 = __ldxr(_X8);
    while ( __stxr(v114 + 1, _X8) );
    v115 = a1[2374];
    if ( (v115 & 1) != 0 )
    {
      a1[2374] = v115 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2373);
    }
    else
    {
      raw_spin_unlock(a1 + 2373);
    }
    v19 = (_DWORD *)a1[154];
    if ( *(v19 - 1) != 1538590919 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64))v19)(a1, v9);
    v20 = *(_QWORD *)(v9 + 24);
    v21 = dp_sta_vdev_self_peer_ref_n_get(a1, v9, 12);
    if ( v21 )
    {
      v22 = v21;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v23 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v23 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v23 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 2204);
        if ( !*(_QWORD *)(v22 + 32) )
        {
LABEL_26:
          v24 = a1[2205];
          if ( (v24 & 1) != 0 )
          {
            a1[2205] = v24 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 2204);
          }
          else
          {
            raw_spin_unlock(a1 + 2204);
          }
          dp_peer_delete_wifi3(
            a1,
            *(unsigned __int8 *)(v9 + 59),
            (unsigned __int8 *)(v22 + 44),
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v25,
            1);
          dp_peer_unref_delete(v22, 0xCu, v34, v35, v36, v37, v38, v39, v40, v41);
          goto LABEL_29;
        }
      }
      else
      {
        raw_spin_lock_bh(a1 + 2204);
        a1[2205] |= 1uLL;
        if ( !*(_QWORD *)(v22 + 32) )
          goto LABEL_26;
      }
      dp_peer_del_ast(a1);
      *(_QWORD *)(v22 + 32) = 0;
      goto LABEL_26;
    }
LABEL_29:
    is_target_ready = hif_is_target_ready(a1[8]);
    if ( (is_target_ready & 1) == 0 || (unsigned int)hif_get_target_status(a1[8]) == 1 )
      dp_vdev_flush_peers(v9, is_target_ready & 1);
    *(_DWORD *)(v9 + 280) = 1;
    dp_rx_vdev_detach(v9);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v43 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v43 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v43 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 2373);
    }
    else
    {
      raw_spin_lock_bh(a1 + 2373);
      a1[2374] |= 1uLL;
    }
    v52 = *(unsigned __int8 *)(v9 + 59);
    if ( v52 < 6 )
      break;
    __break(0x5512u);
  }
  a1[v52 + 1620] = 0;
  dp_vdev_unref_delete((__int64)a1, v9, 0xCu, (unsigned int *)v52, v44, v45, v46, v47, v48, v49, v50, v51);
  v53 = a1[2374];
  if ( (v53 & 1) != 0 )
  {
    a1[2374] = v53 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2373);
    if ( v20 )
      goto LABEL_39;
  }
  else
  {
    raw_spin_unlock(a1 + 2373);
    if ( v20 )
    {
LABEL_39:
      v54 = *(_QWORD **)(v20 + 96456);
      if ( v54 )
      {
        v116 = a3;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v55 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v55 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v55 + 16) & 0xFF00) != 0 )
        {
          v56 = a4;
          raw_spin_lock(v54 + 4653);
        }
        else
        {
          v56 = a4;
          raw_spin_lock_bh(v54 + 4653);
          v54[4654] |= 1uLL;
        }
        if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v20 + 8) + 20112LL) + 256LL) )
        {
          v57 = (_QWORD *)v54[4655];
          if ( v57 )
          {
            do
            {
              v58 = (_QWORD *)v57[4];
              if ( v57[1] == v9 )
              {
                v59 = (_QWORD *)v57[5];
                v60 = v58 + 5;
                if ( !v58 )
                  v60 = v54 + 4656;
                *v60 = v59;
                *v59 = v57[4];
                v57[4] = 0;
                v57[5] = 0;
                _qdf_mem_free((__int64)v57);
              }
              v57 = v58;
            }
            while ( v58 );
          }
        }
        v61 = v54[4654];
        if ( (v61 & 1) != 0 )
        {
          v54[4654] = v61 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v54 + 4653);
        }
        else
        {
          raw_spin_unlock(v54 + 4653);
        }
        a4 = v56;
        a3 = v116;
      }
    }
  }
  dp_tx_vdev_multipass_deinit(v9);
  while ( 1 )
  {
    v71 = *(__int64 **)(v9 + 46144);
    if ( !v71 )
      break;
    v72 = *(__int64 **)(v9 + 46152);
    --*(_DWORD *)(v9 + 46160);
    if ( v71 == v72 )
    {
      v70 = 0;
      *(_QWORD *)(v9 + 46152) = 0;
    }
    else
    {
      v70 = *v71;
    }
    *(_QWORD *)(v9 + 46144) = v70;
    *v71 = 0;
    _qdf_nbuf_free((__int64)v71);
  }
  if ( *v10 )
  {
    _qdf_mem_free(*v10);
    *v10 = 0;
  }
  v73 = *(_DWORD *)(v9 + 32);
  *(_QWORD *)(v9 + 288) = a3;
  *(_QWORD *)(v9 + 296) = a4;
  if ( v73 != 4 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v74 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v74 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v74 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v20 + 312);
      v83 = *(_QWORD *)(v20 + 296);
      if ( v83 )
        goto LABEL_68;
LABEL_70:
      qdf_trace_msg(
        0x88u,
        8u,
        "%s: %pK: vdev:%pK not found in pdev:%pK vdevlist:%pK",
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        "dp_vdev_pdev_list_remove",
        a1,
        v9,
        v20,
        v20 + 296);
      v84 = *(_QWORD *)(v20 + 320);
      if ( (v84 & 1) == 0 )
        goto LABEL_71;
LABEL_86:
      *(_QWORD *)(v20 + 320) = v84 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v20 + 312);
    }
    else
    {
      raw_spin_lock_bh(v20 + 312);
      *(_QWORD *)(v20 + 320) |= 1uLL;
      v83 = *(_QWORD *)(v20 + 296);
      if ( !v83 )
        goto LABEL_70;
LABEL_68:
      while ( v83 != v9 )
      {
        v83 = *(_QWORD *)(v83 + 112);
        if ( !v83 )
          goto LABEL_70;
      }
      v108 = *(_QWORD *)(v9 + 112);
      v109 = *(unsigned int ***)(v9 + 120);
      if ( v108 )
        v110 = (unsigned int ***)(v108 + 120);
      else
        v110 = (unsigned int ***)(v20 + 304);
      *v110 = v109;
      v111 = *(unsigned int **)(v9 + 112);
      *v109 = v111;
      *(_QWORD *)(v9 + 112) = 0;
      *(_QWORD *)(v9 + 120) = 0;
      dp_vdev_unref_delete((__int64)a1, v9, 0xCu, v111, v75, v76, v77, v78, v79, v80, v81, v82);
      v84 = *(_QWORD *)(v20 + 320);
      if ( (v84 & 1) != 0 )
        goto LABEL_86;
LABEL_71:
      raw_spin_unlock(v20 + 312);
    }
  }
  v85 = (unsigned int *)((unsigned int)(unsigned __int16)(*(_WORD *)(v20 + 328))-- - 1);
  dp_vdev_unref_delete((__int64)a1, v9, 7u, v85, v62, v63, v64, v65, v66, v67, v68, v69);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v86 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v86 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v86 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2371);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2371);
    a1[2372] |= 1uLL;
  }
  *(_QWORD *)(v9 + 43352) = 0;
  v87 = (__int64 *)a1[2370];
  *(_QWORD *)(v9 + 43360) = v87;
  *v87 = v9;
  v88 = a1[2372];
  a1[2370] = v9 + 43352;
  if ( (v88 & 1) != 0 )
  {
    a1[2372] = v88 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2371);
  }
  else
  {
    raw_spin_unlock(a1 + 2371);
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: detach vdev %pK id %d pending refs %d",
    v89,
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    "dp_vdev_detach_wifi3",
    v9,
    *(unsigned __int8 *)(v9 + 59),
    *(unsigned int *)(v9 + 43384));
  dp_vdev_unref_delete((__int64)a1, v9, 0xCu, v97, v98, v99, v100, v101, v102, v103, v104, v105);
  return 0;
}
