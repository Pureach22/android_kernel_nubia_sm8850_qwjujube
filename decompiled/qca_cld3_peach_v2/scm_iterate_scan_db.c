__int64 __fastcall scm_iterate_scan_db(
        __int64 a1,
        __int64 (__fastcall *a2)(__int64, __int64),
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x22
  unsigned int v12; // w21
  const char *v13; // x2
  __int64 comp_private_obj; // x0
  __int64 v17; // x8
  __int64 v18; // x21
  __int64 v19; // x24
  __int64 v20; // x25
  unsigned __int64 StatusReg; // x27
  __int64 result; // x0
  __int64 next_node; // x23
  __int64 v24; // x8
  __int64 v25; // x1
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v41; // w9
  unsigned int v42; // w19
  __int64 v43; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v44[2]; // [xsp+10h] [xbp-10h] BYREF

  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v13 = "%s: func is NULL";
LABEL_36:
    qdf_trace_msg(0x15u, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "scm_iterate_scan_db");
    result = 4;
    goto LABEL_37;
  }
  if ( !a1 )
  {
    v13 = "%s: pdev is NULL";
    goto LABEL_36;
  }
  v11 = *(_QWORD *)(a1 + 80);
  if ( !v11 )
  {
    v13 = "%s: psoc is NULL";
    goto LABEL_36;
  }
  v12 = *(unsigned __int8 *)(a1 + 40);
  if ( v12 >= 2 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: invalid pdev_id %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_pdevid_get_scan_db",
      *(unsigned __int8 *)(a1 + 40));
    goto LABEL_35;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdevid_get_scan_db",
      57);
    goto LABEL_35;
  }
  v17 = comp_private_obj + 1560LL * v12;
  v18 = v17 + 32;
  if ( v17 == -32 )
  {
LABEL_35:
    v13 = "%s: scan_db is NULL";
    goto LABEL_36;
  }
  scm_age_out_entries(v11, v17 + 32, a4, a5, a6, a7, a8, a9, a10, a11);
  v19 = 0;
  v20 = v18 + 24;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v18 + 8);
    }
    else
    {
      raw_spin_lock_bh(v18 + 8);
      *(_QWORD *)(v18 + 16) |= 1uLL;
    }
    v43 = 0;
    v44[0] = 0;
    qdf_list_peek_front((_QWORD *)(v20 + 24 * v19), v44);
    next_node = v44[0];
    if ( v44[0] )
    {
      while ( *(_DWORD *)(next_node + 20) != 306772034 )
      {
        qdf_list_peek_next((_QWORD *)(v20 + 24 * v19), (_QWORD *)next_node, &v43);
        next_node = v43;
        v43 = 0;
        v44[0] = next_node;
        if ( !next_node )
          goto LABEL_20;
      }
      _X8 = (unsigned int *)(next_node + 16);
      __asm { PRFM            #0x11, [X8] }
      do
        v41 = __ldxr(_X8);
      while ( __stxr(v41 + 1, _X8) );
      v24 = *(_QWORD *)(v18 + 16);
      if ( (v24 & 1) == 0 )
      {
LABEL_21:
        raw_spin_unlock(v18 + 8);
        if ( next_node )
          goto LABEL_22;
        goto LABEL_12;
      }
    }
    else
    {
LABEL_20:
      next_node = 0;
      v24 = *(_QWORD *)(v18 + 16);
      if ( (v24 & 1) == 0 )
        goto LABEL_21;
    }
    *(_QWORD *)(v18 + 16) = v24 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v18 + 8);
    if ( next_node )
      break;
LABEL_12:
    ++v19;
    result = 0;
    if ( v19 == 64 )
      goto LABEL_37;
  }
  while ( 1 )
  {
LABEL_22:
    v25 = *(_QWORD *)(next_node + 24);
    if ( *((_DWORD *)a2 - 1) != 689384279 )
      __break(0x8234u);
    v26 = a2(a3, v25);
    if ( v26 )
      break;
    next_node = scm_get_next_node(v18, v20 + 24 * v19, next_node);
    if ( !next_node )
      goto LABEL_12;
  }
  v42 = v26;
  scm_scan_entry_put_ref(v18, next_node, 1, v27, v28, v29, v30, v31, v32, v33, v34);
  result = v42;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
