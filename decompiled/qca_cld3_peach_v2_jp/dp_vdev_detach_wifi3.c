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
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  char is_target_ready; // w24
  unsigned __int64 v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int64 v43; // x8
  __int64 v44; // x8
  _QWORD *v45; // x24
  unsigned __int64 v46; // x8
  __int64 v47; // x22
  _QWORD *v48; // x0
  _QWORD *v49; // x21
  _QWORD *v50; // x9
  _QWORD *v51; // x10
  __int64 v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x8
  __int64 *v62; // x0
  __int64 *v63; // x9
  int v64; // w8
  unsigned __int64 v65; // x8
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x8
  __int64 v75; // x8
  unsigned int *v76; // x8
  unsigned __int64 v77; // x8
  __int64 *v78; // x8
  __int64 v79; // x8
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  unsigned int *v88; // x8
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v98; // x8
  __int64 v99; // x8
  unsigned int **v100; // x9
  unsigned int ***v101; // x8
  unsigned int *v102; // x8
  unsigned int v105; // w9
  __int64 v106; // x8
  __int64 v107; // [xsp+8h] [xbp-8h]

  if ( a2 > 5u )
    return 16;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2366);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2366);
    a1[2367] |= 1uLL;
  }
  v9 = a1[a2 + 1614];
  if ( !v9 )
  {
LABEL_79:
    v98 = a1[2367];
    if ( (v98 & 1) != 0 )
    {
      a1[2367] = v98 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2366);
    }
    else
    {
      raw_spin_unlock(a1 + 2366);
    }
    return 16;
  }
  v10 = (__int64 *)(v9 + 42504);
  v11 = *(_DWORD *)(v9 + 42560);
  do
  {
    if ( !v11 )
      goto LABEL_79;
    _X12 = (unsigned int *)(v9 + 42560);
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
    _X8 = (unsigned int *)(v9 + 42592);
    __asm { PRFM            #0x11, [X8] }
    do
      v105 = __ldxr(_X8);
    while ( __stxr(v105 + 1, _X8) );
    v106 = a1[2367];
    if ( (v106 & 1) != 0 )
    {
      a1[2367] = v106 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2366);
    }
    else
    {
      raw_spin_unlock(a1 + 2366);
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
        raw_spin_lock(a1 + 2197);
        if ( !*(_QWORD *)(v22 + 32) )
        {
LABEL_26:
          v24 = a1[2198];
          if ( (v24 & 1) != 0 )
          {
            a1[2198] = v24 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 2197);
          }
          else
          {
            raw_spin_unlock(a1 + 2197);
          }
          dp_peer_delete_wifi3(a1, *(unsigned __int8 *)(v9 + 59), (unsigned __int8 *)(v22 + 44));
          dp_peer_unref_delete(v22, 0xCu, v25, v26, v27, v28, v29, v30, v31, v32);
          goto LABEL_29;
        }
      }
      else
      {
        raw_spin_lock_bh(a1 + 2197);
        a1[2198] |= 1uLL;
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
    *(_DWORD *)(v9 + 272) = 1;
    dp_rx_vdev_detach(v9);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v34 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v34 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v34 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 2366);
    }
    else
    {
      raw_spin_lock_bh(a1 + 2366);
      a1[2367] |= 1uLL;
    }
    v43 = *(unsigned __int8 *)(v9 + 59);
    if ( v43 < 6 )
      break;
    __break(0x5512u);
  }
  a1[v43 + 1614] = 0;
  dp_vdev_unref_delete((__int64)a1, v9, 0xCu, (unsigned int *)v43, v35, v36, v37, v38, v39, v40, v41, v42);
  v44 = a1[2367];
  if ( (v44 & 1) != 0 )
  {
    a1[2367] = v44 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2366);
    if ( v20 )
      goto LABEL_39;
  }
  else
  {
    raw_spin_unlock(a1 + 2366);
    if ( v20 )
    {
LABEL_39:
      v45 = *(_QWORD **)(v20 + 95560);
      if ( v45 )
      {
        v107 = a3;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v46 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v46 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v46 + 16) & 0xFF00) != 0 )
        {
          v47 = a4;
          raw_spin_lock(v45 + 4653);
        }
        else
        {
          v47 = a4;
          raw_spin_lock_bh(v45 + 4653);
          v45[4654] |= 1uLL;
        }
        if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v20 + 8) + 20056LL) + 256LL) )
        {
          v48 = (_QWORD *)v45[4655];
          if ( v48 )
          {
            do
            {
              v49 = (_QWORD *)v48[4];
              if ( v48[1] == v9 )
              {
                v50 = (_QWORD *)v48[5];
                v51 = v49 + 5;
                if ( !v49 )
                  v51 = v45 + 4656;
                *v51 = v50;
                *v50 = v48[4];
                v48[4] = 0;
                v48[5] = 0;
                _qdf_mem_free((__int64)v48);
              }
              v48 = v49;
            }
            while ( v49 );
          }
        }
        v52 = v45[4654];
        if ( (v52 & 1) != 0 )
        {
          v45[4654] = v52 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v45 + 4653);
        }
        else
        {
          raw_spin_unlock(v45 + 4653);
        }
        a4 = v47;
        a3 = v107;
      }
    }
  }
  dp_tx_vdev_multipass_deinit(v9);
  while ( 1 )
  {
    v62 = *(__int64 **)(v9 + 45320);
    if ( !v62 )
      break;
    v63 = *(__int64 **)(v9 + 45328);
    --*(_DWORD *)(v9 + 45336);
    if ( v62 == v63 )
    {
      v61 = 0;
      *(_QWORD *)(v9 + 45328) = 0;
    }
    else
    {
      v61 = *v62;
    }
    *(_QWORD *)(v9 + 45320) = v61;
    *v62 = 0;
    _qdf_nbuf_free((__int64)v62);
  }
  if ( *v10 )
  {
    _qdf_mem_free(*v10);
    *v10 = 0;
  }
  v64 = *(_DWORD *)(v9 + 32);
  *(_QWORD *)(v9 + 280) = a3;
  *(_QWORD *)(v9 + 288) = a4;
  if ( v64 != 4 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v65 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v65 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v65 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v20 + 312);
      v74 = *(_QWORD *)(v20 + 296);
      if ( v74 )
        goto LABEL_68;
LABEL_70:
      qdf_trace_msg(
        0x88u,
        8u,
        "%s: %pK: vdev:%pK not found in pdev:%pK vdevlist:%pK",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "dp_vdev_pdev_list_remove",
        a1,
        v9,
        v20,
        v20 + 296);
      v75 = *(_QWORD *)(v20 + 320);
      if ( (v75 & 1) == 0 )
        goto LABEL_71;
LABEL_86:
      *(_QWORD *)(v20 + 320) = v75 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v20 + 312);
    }
    else
    {
      raw_spin_lock_bh(v20 + 312);
      *(_QWORD *)(v20 + 320) |= 1uLL;
      v74 = *(_QWORD *)(v20 + 296);
      if ( !v74 )
        goto LABEL_70;
LABEL_68:
      while ( v74 != v9 )
      {
        v74 = *(_QWORD *)(v74 + 104);
        if ( !v74 )
          goto LABEL_70;
      }
      v99 = *(_QWORD *)(v9 + 104);
      v100 = *(unsigned int ***)(v9 + 112);
      if ( v99 )
        v101 = (unsigned int ***)(v99 + 112);
      else
        v101 = (unsigned int ***)(v20 + 304);
      *v101 = v100;
      v102 = *(unsigned int **)(v9 + 104);
      *v100 = v102;
      *(_QWORD *)(v9 + 104) = 0;
      *(_QWORD *)(v9 + 112) = 0;
      dp_vdev_unref_delete((__int64)a1, v9, 0xCu, v102, v66, v67, v68, v69, v70, v71, v72, v73);
      v75 = *(_QWORD *)(v20 + 320);
      if ( (v75 & 1) != 0 )
        goto LABEL_86;
LABEL_71:
      raw_spin_unlock(v20 + 312);
    }
  }
  v76 = (unsigned int *)((unsigned int)(unsigned __int16)(*(_WORD *)(v20 + 328))-- - 1);
  dp_vdev_unref_delete((__int64)a1, v9, 7u, v76, v53, v54, v55, v56, v57, v58, v59, v60);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v77 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v77 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v77 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2364);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2364);
    a1[2365] |= 1uLL;
  }
  *(_QWORD *)(v9 + 42528) = 0;
  v78 = (__int64 *)a1[2363];
  *(_QWORD *)(v9 + 42536) = v78;
  *v78 = v9;
  v79 = a1[2365];
  a1[2363] = v9 + 42528;
  if ( (v79 & 1) != 0 )
  {
    a1[2365] = v79 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2364);
  }
  else
  {
    raw_spin_unlock(a1 + 2364);
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: detach vdev %pK id %d pending refs %d",
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    v87,
    "dp_vdev_detach_wifi3",
    v9,
    *(unsigned __int8 *)(v9 + 59),
    *(unsigned int *)(v9 + 42560));
  dp_vdev_unref_delete((__int64)a1, v9, 0xCu, v88, v89, v90, v91, v92, v93, v94, v95, v96);
  return 0;
}
