__int64 __fastcall scm_age_out_entries(
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
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 v21; // x23
  unsigned __int64 StatusReg; // x25
  _QWORD *v23; // x22
  __int64 next_node; // x21
  __int64 v25; // x8
  unsigned int v31; // w9
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 result; // x0
  __int64 v41; // x22
  _QWORD *v42; // x27
  __int64 v43; // x28
  __int64 v44; // x8
  unsigned int v47; // w9
  __int64 v48; // x8
  const char *v49; // x2
  __int64 v50; // x8
  __int64 v51; // x9
  int v52; // w11
  int v53; // w8
  int v54; // w10
  int v55; // w9
  unsigned __int64 v57; // x22
  __int64 v58; // x24
  __int64 v59; // x8
  unsigned int v60; // w24
  unsigned int v61; // w25
  unsigned int v62; // w26
  unsigned int v63; // w22
  __int64 v64; // x23
  __int64 system_time; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // [xsp+10h] [xbp-30h]
  __int64 v83; // [xsp+18h] [xbp-28h]
  unsigned __int64 v84; // [xsp+20h] [xbp-20h]
  __int64 v85; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v86[2]; // [xsp+30h] [xbp-10h] BYREF

  v86[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    qdf_trace_msg(0x15u, 2u, "%s: null psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_scan_psoc_get_def_params");
LABEL_26:
    result = qdf_trace_msg(
               0x15u,
               2u,
               "%s: wlan_scan_psoc_get_def_params failed",
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               "scm_age_out_entries");
    goto LABEL_75;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_psoc_get_def_params",
      878);
    goto LABEL_26;
  }
  v20 = comp_private_obj;
  v21 = 0;
  v82 = a2 + 24;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 8);
    }
    else
    {
      raw_spin_lock_bh(a2 + 8);
      *(_QWORD *)(a2 + 16) |= 1uLL;
    }
    v23 = (_QWORD *)(v82 + 24 * v21);
    v85 = 0;
    v86[0] = 0;
    qdf_list_peek_front(v23, v86);
    next_node = v86[0];
    if ( v86[0] )
    {
      while ( *(_DWORD *)(next_node + 20) != 306772034 )
      {
        qdf_list_peek_next(v23, (_QWORD *)next_node, &v85);
        next_node = v85;
        v85 = 0;
        v86[0] = next_node;
        if ( !next_node )
          goto LABEL_12;
      }
      _X8 = (unsigned int *)(next_node + 16);
      __asm { PRFM            #0x11, [X8] }
      do
        v31 = __ldxr(_X8);
      while ( __stxr(v31 + 1, _X8) );
      v25 = *(_QWORD *)(a2 + 16);
      if ( (v25 & 1) == 0 )
      {
LABEL_15:
        raw_spin_unlock(a2 + 8);
        if ( next_node )
          break;
        goto LABEL_4;
      }
    }
    else
    {
LABEL_12:
      next_node = 0;
      v25 = *(_QWORD *)(a2 + 16);
      if ( (v25 & 1) == 0 )
        goto LABEL_15;
    }
    *(_QWORD *)(a2 + 16) = v25 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 8);
    if ( next_node )
      break;
LABEL_4:
    if ( ++v21 == 64 )
    {
      next_node = 0;
      goto LABEL_28;
    }
  }
  while ( *(_DWORD *)(*(_QWORD *)(next_node + 24) + 1244LL) != 2 )
  {
    next_node = scm_get_next_node(a2, v23, next_node);
    if ( !next_node )
      goto LABEL_4;
  }
LABEL_28:
  v41 = 0;
  v84 = _ReadStatusReg(SP_EL0);
  while ( 2 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v84 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v84 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 8);
    }
    else
    {
      raw_spin_lock_bh(a2 + 8);
      *(_QWORD *)(a2 + 16) |= 1uLL;
    }
    v42 = (_QWORD *)(v82 + 24 * v41);
    v83 = v41;
    v85 = 0;
    v86[0] = 0;
    qdf_list_peek_front(v42, v86);
    v43 = v86[0];
    if ( v86[0] )
    {
      while ( *(_DWORD *)(v43 + 20) != 306772034 )
      {
        qdf_list_peek_next(v42, (_QWORD *)v43, &v85);
        v43 = v85;
        v85 = 0;
        v86[0] = v43;
        if ( !v43 )
          goto LABEL_37;
      }
      _X8 = (unsigned int *)(v43 + 16);
      __asm { PRFM            #0x11, [X8] }
      do
        v47 = __ldxr(_X8);
      while ( __stxr(v47 + 1, _X8) );
      v44 = *(_QWORD *)(a2 + 16);
      if ( (v44 & 1) != 0 )
      {
LABEL_45:
        *(_QWORD *)(a2 + 16) = v44 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(a2 + 8);
        if ( !v43 )
          goto LABEL_29;
LABEL_51:
        while ( 2 )
        {
          if ( !next_node
            || (v50 = *(_QWORD *)(v43 + 24), *(_DWORD *)(v50 + 1244) != 2)
            && (!*(_BYTE *)(v50 + 112)
             || ((v51 = *(_QWORD *)(next_node + 24),
                  v52 = *(_DWORD *)(v50 + 114),
                  v53 = *(unsigned __int16 *)(v50 + 118),
                  v54 = *(_DWORD *)(v51 + 114),
                  v55 = *(unsigned __int16 *)(v51 + 118),
                  v54 == v52)
               ? (_ZF = v55 == v53)
               : (_ZF = 0),
                 !_ZF)) )
          {
            v57 = *(_QWORD *)(v20 + 1704);
            v58 = *(_QWORD *)(*(_QWORD *)(v43 + 24) + 88LL);
            if ( qdf_mc_timer_get_system_time() - v58 >= v57 )
            {
              v59 = *(_QWORD *)(v43 + 24);
              if ( v59 == -1 )
              {
                v62 = 0;
                v60 = 0;
                v61 = 0;
                v63 = 0;
              }
              else
              {
                v60 = *(unsigned __int8 *)(v59 + 1);
                v61 = *(unsigned __int8 *)(v59 + 2);
                v62 = *(unsigned __int8 *)(v59 + 3);
                v63 = *(unsigned __int8 *)(v59 + 6);
              }
              v64 = *(_QWORD *)(v59 + 88);
              system_time = qdf_mc_timer_get_system_time();
              qdf_trace_msg(
                0x15u,
                8u,
                "%s: Aging out BSSID: %02x:%02x:%02x:**:**:%02x with age %lu ms",
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                "scm_check_and_age_out",
                v60,
                v61,
                v62,
                v63,
                system_time - v64);
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(v84 + 16) & 0xF0000) != 0
                || (*(_DWORD *)(v84 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(a2 + 8);
              }
              else
              {
                raw_spin_lock_bh(a2 + 8);
                *(_QWORD *)(a2 + 16) |= 1uLL;
              }
              if ( *(_DWORD *)(v43 + 20) == 306772034 )
              {
                if ( !*(_DWORD *)(v43 + 16) )
                {
                  v49 = "%s: node is already deleted ref 0";
                  goto LABEL_68;
                }
                *(_DWORD *)(v43 + 20) = 0;
                scm_scan_entry_put_ref(a2, v43, 0);
                v48 = *(_QWORD *)(a2 + 16);
                if ( (v48 & 1) != 0 )
                  goto LABEL_49;
LABEL_69:
                raw_spin_unlock(a2 + 8);
              }
              else
              {
                v49 = "%s: node is already deleted";
LABEL_68:
                qdf_trace_msg(0x15u, 8u, v49, v74, v75, v76, v77, v78, v79, v80, v81, "scm_scan_entry_del");
                v48 = *(_QWORD *)(a2 + 16);
                if ( (v48 & 1) == 0 )
                  goto LABEL_69;
LABEL_49:
                *(_QWORD *)(a2 + 16) = v48 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(a2 + 8);
              }
            }
          }
          result = scm_get_next_node(a2, v42, v43);
          v43 = result;
          if ( !result )
            goto LABEL_29;
          continue;
        }
      }
    }
    else
    {
LABEL_37:
      v43 = 0;
      v44 = *(_QWORD *)(a2 + 16);
      if ( (v44 & 1) != 0 )
        goto LABEL_45;
    }
    result = raw_spin_unlock(a2 + 8);
    if ( v43 )
      goto LABEL_51;
LABEL_29:
    v41 = v83 + 1;
    if ( v83 != 63 )
      continue;
    break;
  }
  if ( next_node )
    result = scm_scan_entry_put_ref(a2, next_node, 1);
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return result;
}
