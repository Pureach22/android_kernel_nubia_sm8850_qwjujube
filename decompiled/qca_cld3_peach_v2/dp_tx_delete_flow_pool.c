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
  unsigned __int64 v12; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x21
  unsigned int v15; // w9
  unsigned int v22; // w11
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int *v32; // x8
  unsigned __int64 v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x23
  char v43; // w22
  __int64 v44; // x0
  unsigned int v45; // w8
  unsigned int v48; // w10
  unsigned int v51; // w9
  __int64 v52; // x8
  __int64 v53; // x8
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned __int64 v71; // x8
  char v72; // w8
  char v73; // w8
  __int64 v74; // x8
  __int64 v75; // x4
  const char *v76; // x2
  unsigned int v77; // w1
  int v78; // w8
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x8
  void (__fastcall *v88)(__int64, __int64, __int64); // x8
  __int64 v89; // x0
  void (__fastcall *v90)(__int64, __int64, __int64); // x8
  __int64 v91; // x0
  void (__fastcall *v92)(__int64, __int64, __int64); // x8
  __int64 v93; // x0
  void (__fastcall *v94)(__int64, __int64, __int64); // x8
  __int64 v95; // x0
  __int64 v96; // x8
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned __int64 v105; // x20
  unsigned __int64 v106; // x8
  unsigned __int64 v107; // x8
  __int64 v108; // x20
  __int64 v109; // x8
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  unsigned int *v118; // x8
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  __int64 v127; // x8
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  unsigned int v138; // w9
  __int64 v139; // x8

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
  v12 = *(unsigned __int8 *)(a2 + 58);
  if ( v12 <= 5 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 18984);
    }
    else
    {
      raw_spin_lock_bh(a1 + 18984);
      *(_QWORD *)(a1 + 18992) |= 1uLL;
    }
    v14 = *(_QWORD *)(a1 + 8 * v12 + 12960);
    if ( v14 )
    {
      v15 = *(_DWORD *)(v14 + 43384);
      do
      {
        if ( !v15 )
          goto LABEL_41;
        _X13 = (unsigned int *)(v14 + 43384);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v22 = __ldxr(_X13);
          if ( v22 != v15 )
            break;
          if ( !__stlxr(v15 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v22 == v15;
        v15 = v22;
      }
      while ( !_ZF );
      _X8 = (unsigned int *)(v14 + 43472);
      __asm { PRFM            #0x11, [X8] }
      do
        v138 = __ldxr(_X8);
      while ( __stxr(v138 + 1, _X8) );
      v139 = *(_QWORD *)(a1 + 18992);
      if ( (v139 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 18992) = v139 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 18984);
      }
      else
      {
        raw_spin_unlock(a1 + 18984);
      }
      v32 = (unsigned int *)*(unsigned int *)(v14 + 32);
      if ( (_DWORD)v32 != 3 )
      {
        dp_vdev_unref_delete(a1, v14, 0x15u, v32, v24, v25, v26, v27, v28, v29, v30, v31);
        goto LABEL_51;
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v33 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v33 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v14 + 144);
        v42 = *(_QWORD *)(v14 + 128);
        if ( v42 )
          goto LABEL_26;
      }
      else
      {
        raw_spin_lock_bh(v14 + 144);
        *(_QWORD *)(v14 + 152) |= 1uLL;
        v42 = *(_QWORD *)(v14 + 128);
        if ( v42 )
        {
LABEL_26:
          v43 = 1;
          do
          {
            v44 = v42;
            v42 = *(_QWORD *)(v42 + 56);
            v45 = *(_DWORD *)(v44 + 40);
            while ( v45 )
            {
              _X12 = (unsigned int *)(v44 + 40);
              __asm { PRFM            #0x11, [X12] }
              while ( 1 )
              {
                v48 = __ldxr(_X12);
                if ( v48 != v45 )
                  break;
                if ( !__stlxr(v45 + 1, _X12) )
                {
                  __dmb(0xBu);
                  break;
                }
              }
              _ZF = v48 == v45;
              v45 = v48;
              if ( _ZF )
              {
                _X8 = (unsigned int *)(v44 + 312);
                __asm { PRFM            #0x11, [X8] }
                do
                  v51 = __ldxr(_X8);
                while ( __stxr(v51 + 1, _X8) );
                v43 &= (*(_BYTE *)(v44 + 120) & 0x14) != 4;
                dp_peer_unref_delete(v44, 0xCu, v34, v35, v36, v37, v38, v39, v40, v41);
                break;
              }
            }
          }
          while ( v42 );
LABEL_48:
          v53 = *(_QWORD *)(v14 + 152);
          if ( (v53 & 1) != 0 )
          {
            *(_QWORD *)(v14 + 152) = v53 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v14 + 144);
          }
          else
          {
            raw_spin_unlock(v14 + 144);
          }
          dp_vdev_unref_delete(a1, v14, 0x15u, v54, v55, v56, v57, v58, v59, v60, v61, v62);
          if ( (v43 & 1) == 0 )
          {
            v75 = *(unsigned __int8 *)(a2 + 58);
            v76 = "%s: skip pool id %d delete as it's not allowed";
            v77 = 5;
            goto LABEL_65;
          }
          goto LABEL_51;
        }
      }
      v43 = 1;
      goto LABEL_48;
    }
LABEL_41:
    v52 = *(_QWORD *)(a1 + 18992);
    if ( (v52 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18992) = v52 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18984);
    }
    else
    {
      raw_spin_unlock(a1 + 18984);
    }
  }
LABEL_51:
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v71 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v71 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v71 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 256);
    v72 = *(_BYTE *)(a2 + 272);
    if ( v72 )
      goto LABEL_55;
LABEL_100:
    v127 = *(_QWORD *)(a2 + 264);
    if ( (v127 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 264) = v127 & 0xFFFFFFFFFFFFFFFELL;
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
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      "dp_tx_delete_flow_pool");
    return 4294967294LL;
  }
  raw_spin_lock_bh(a2 + 256);
  *(_QWORD *)(a2 + 264) |= 1uLL;
  v72 = *(_BYTE *)(a2 + 272);
  if ( !v72 )
    goto LABEL_100;
LABEL_55:
  v73 = v72 - 1;
  *(_BYTE *)(a2 + 272) = v73;
  if ( !v73 )
  {
    if ( *(unsigned __int16 *)(a2 + 60) >= (unsigned int)*(unsigned __int16 *)(a2 + 56) )
    {
      v79 = ((double (__fastcall *)(__int64, _QWORD, _QWORD))dp_tx_desc_pool_deinit)(
              a1,
              *(unsigned __int8 *)(a2 + 58),
              0);
      dp_tx_desc_pool_free(a1, *(_BYTE *)(a2 + 58), v79, v80, v81, v82, v83, v84, v85, v86);
      v87 = *(_QWORD *)(a2 + 264);
      if ( (v87 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 264) = v87 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 256);
      }
      else
      {
        raw_spin_unlock(a2 + 256);
      }
      return 0;
    }
    v78 = *(_DWORD *)(a2 + 64);
    *(_DWORD *)(a2 + 64) = 5;
    if ( v78 > 2 )
    {
      if ( v78 == 3 )
      {
LABEL_78:
        v92 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 12920);
        v93 = *(unsigned __int8 *)(a2 + 58);
        if ( *((_DWORD *)v92 - 1) != 694643930 )
          __break(0x8228u);
        v92(v93, 14, 10);
        goto LABEL_81;
      }
      if ( v78 != 4 )
        goto LABEL_84;
    }
    else
    {
      if ( v78 != 1 )
      {
        if ( v78 != 2 )
        {
LABEL_84:
          v96 = *(_QWORD *)(a2 + 264);
          if ( (v96 & 1) != 0 )
          {
            *(_QWORD *)(a2 + 264) = v96 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a2 + 256);
          }
          else
          {
            raw_spin_unlock(a2 + 256);
          }
          v105 = *(unsigned __int8 *)(a2 + 58);
          if ( v105 <= 5 )
          {
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (v106 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v106 + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(v106 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(a1 + 18984);
            }
            else
            {
              raw_spin_lock_bh(a1 + 18984);
              *(_QWORD *)(a1 + 18992) |= 1uLL;
            }
            v107 = a1 + 8 * v105;
            v108 = *(_QWORD *)(v107 + 12960);
            if ( v108 && !(unsigned int)dp_vdev_get_ref(*(_QWORD *)(v107 + 12960), 21) )
            {
              qdf_spin_unlock_bh_24(a1 + 18984);
              dp_tx_desc_flush(*(_QWORD *)(v108 + 24), v108, 0, v110, v111, v112, v113, v114, v115, v116, v117);
              dp_vdev_unref_delete(a1, v108, 0x15u, v118, v119, v120, v121, v122, v123, v124, v125, v126);
            }
            else
            {
              v109 = *(_QWORD *)(a1 + 18992);
              if ( (v109 & 1) != 0 )
              {
                *(_QWORD *)(a1 + 18992) = v109 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(a1 + 18984);
              }
              else
              {
                raw_spin_unlock(a1 + 18984);
              }
            }
          }
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: avail desc less than pool size",
            v97,
            v98,
            v99,
            v100,
            v101,
            v102,
            v103,
            v104,
            "dp_tx_delete_flow_pool");
          return 4294967285LL;
        }
LABEL_81:
        v94 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 12920);
        v95 = *(unsigned __int8 *)(a2 + 58);
        if ( *((_DWORD *)v94 - 1) != 694643930 )
          __break(0x8228u);
        v94(v95, 17, 9);
        goto LABEL_84;
      }
      v88 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 12920);
      v89 = *(unsigned __int8 *)(a2 + 58);
      if ( *((_DWORD *)v88 - 1) != 694643930 )
        __break(0x8228u);
      v88(v89, 10, 12);
    }
    v90 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 12920);
    v91 = *(unsigned __int8 *)(a2 + 58);
    if ( *((_DWORD *)v90 - 1) != 694643930 )
      __break(0x8228u);
    v90(v91, 12, 11);
    goto LABEL_78;
  }
  v74 = *(_QWORD *)(a2 + 264);
  if ( (v74 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 264) = v74 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 256);
  }
  else
  {
    raw_spin_unlock(a2 + 256);
  }
  v75 = *(unsigned __int8 *)(a2 + 272);
  v76 = "%s: pool is still attached, pending detach %d";
  v77 = 2;
LABEL_65:
  qdf_trace_msg(0x45u, v77, v76, v63, v64, v65, v66, v67, v68, v69, v70, "dp_tx_delete_flow_pool", v75);
  return 4294967285LL;
}
