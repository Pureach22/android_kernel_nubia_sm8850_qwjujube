__int64 __fastcall scm_update_rnr_from_scan_cache(
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
  __int64 v10; // x0
  unsigned int v11; // w20
  const char *v12; // x2
  __int64 comp_private_obj; // x0
  __int64 v14; // x8
  __int64 v15; // x20
  __int64 v16; // x23
  __int64 v17; // x24
  unsigned __int64 StatusReg; // x26
  __int64 v19; // x22
  __int64 v20; // x8
  __int64 result; // x0
  unsigned int v28; // w9
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 80);
  if ( v10 )
  {
    if ( !a1 )
    {
      qdf_trace_msg(0x15u, 2u, "%s: pdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_pdev_get_scan_db");
      goto LABEL_30;
    }
    v11 = *(unsigned __int8 *)(a1 + 40);
    if ( v11 >= 2 )
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: invalid pdev_id %d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_pdevid_get_scan_db",
        *(unsigned __int8 *)(a1 + 40));
      goto LABEL_30;
    }
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v10, 3u);
    if ( !comp_private_obj )
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: %s:%u, Failed to get scan object",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_psoc_get_scan_obj_fl",
        "wlan_pdevid_get_scan_db",
        57);
      goto LABEL_30;
    }
    v14 = comp_private_obj + 1560LL * v11;
    v15 = v14 + 32;
    if ( v14 == -32 )
    {
LABEL_30:
      v12 = "%s: scan_db is NULL";
      goto LABEL_31;
    }
    v16 = 0;
    v17 = v14 + 56;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v15 + 8);
      }
      else
      {
        raw_spin_lock_bh(v15 + 8);
        *(_QWORD *)(v15 + 16) |= 1uLL;
      }
      v29 = 0;
      v30[0] = 0;
      qdf_list_peek_front((_QWORD *)(v17 + 24 * v16), v30);
      v19 = v30[0];
      if ( v30[0] )
      {
        while ( *(_DWORD *)(v19 + 20) != 306772034 )
        {
          qdf_list_peek_next((_QWORD *)(v17 + 24 * v16), (_QWORD *)v19, &v29);
          v19 = v29;
          v29 = 0;
          v30[0] = v19;
          if ( !v19 )
            goto LABEL_18;
        }
        _X8 = (unsigned int *)(v19 + 16);
        __asm { PRFM            #0x11, [X8] }
        do
          v28 = __ldxr(_X8);
        while ( __stxr(v28 + 1, _X8) );
        v20 = *(_QWORD *)(v15 + 16);
        if ( (v20 & 1) == 0 )
        {
LABEL_21:
          result = raw_spin_unlock(v15 + 8);
          if ( v19 )
            goto LABEL_22;
          goto LABEL_10;
        }
      }
      else
      {
LABEL_18:
        v19 = 0;
        v20 = *(_QWORD *)(v15 + 16);
        if ( (v20 & 1) == 0 )
          goto LABEL_21;
      }
      *(_QWORD *)(v15 + 16) = v20 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v15 + 8);
      if ( v19 )
      {
        do
        {
LABEL_22:
          scm_add_rnr_channel_db(a1, *(_QWORD *)(v19 + 24));
          result = scm_get_next_node(v15, v17 + 24 * v16, v19);
          v19 = result;
        }
        while ( result );
      }
LABEL_10:
      if ( ++v16 == 64 )
        goto LABEL_32;
    }
  }
  v12 = "%s: psoc is NULL";
LABEL_31:
  result = qdf_trace_msg(0x15u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "scm_update_rnr_from_scan_cache");
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
