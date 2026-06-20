__int64 __fastcall scm_filter_valid_channel(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  unsigned int v23; // w21
  const char *v24; // x2
  __int64 comp_private_obj; // x0
  __int64 v26; // x8
  __int64 v27; // x21
  __int64 v28; // x27
  unsigned __int64 StatusReg; // x22
  _QWORD *v30; // x25
  __int64 v31; // x26
  __int64 v32; // x8
  __int64 result; // x0
  unsigned int v40; // w9
  __int64 v41; // x8
  const char *v42; // x2
  int v43; // w9
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // [xsp+0h] [xbp-20h]
  __int64 v53; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v54[2]; // [xsp+10h] [xbp-10h] BYREF

  v54[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x15u, 8u, "%s: num_chan = %d", a4, a5, a6, a7, a8, a9, a10, a11, "scm_filter_valid_channel", a3);
  if ( a1 )
  {
    v22 = *(_QWORD *)(a1 + 80);
    if ( v22 )
    {
      v23 = *(unsigned __int8 *)(a1 + 40);
      if ( v23 >= 2 )
      {
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: invalid pdev_id %d",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_pdevid_get_scan_db",
          v23);
        goto LABEL_48;
      }
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v22, 3u);
      if ( !comp_private_obj )
      {
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: %s:%u, Failed to get scan object",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_psoc_get_scan_obj_fl",
          "wlan_pdevid_get_scan_db",
          57);
        goto LABEL_48;
      }
      v26 = comp_private_obj + 1560LL * v23;
      v27 = v26 + 32;
      if ( v26 == -32 )
      {
LABEL_48:
        v24 = "%s: scan_db is NULL";
        goto LABEL_49;
      }
      v28 = 0;
      v52 = v26 + 56;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v27 + 8);
        }
        else
        {
          raw_spin_lock_bh(v27 + 8);
          *(_QWORD *)(v27 + 16) |= 1uLL;
        }
        v30 = (_QWORD *)(v52 + 24 * v28);
        v53 = 0;
        v54[0] = 0;
        qdf_list_peek_front(v30, v54);
        v31 = v54[0];
        if ( v54[0] )
        {
          while ( *(_DWORD *)(v31 + 20) != 306772034 )
          {
            qdf_list_peek_next(v30, (_QWORD *)v31, &v53);
            v31 = v53;
            v53 = 0;
            v54[0] = v31;
            if ( !v31 )
              goto LABEL_18;
          }
          _X8 = (unsigned int *)(v31 + 16);
          __asm { PRFM            #0x11, [X8] }
          do
            v40 = __ldxr(_X8);
          while ( __stxr(v40 + 1, _X8) );
          v32 = *(_QWORD *)(v27 + 16);
          if ( (v32 & 1) == 0 )
          {
LABEL_21:
            result = raw_spin_unlock(v27 + 8);
            if ( v31 )
              goto LABEL_32;
            goto LABEL_10;
          }
        }
        else
        {
LABEL_18:
          v31 = 0;
          v32 = *(_QWORD *)(v27 + 16);
          if ( (v32 & 1) == 0 )
            goto LABEL_21;
        }
        *(_QWORD *)(v27 + 16) = v32 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v27 + 8);
        if ( v31 )
          break;
LABEL_10:
        if ( ++v28 == 64 )
          goto LABEL_50;
      }
      while ( 1 )
      {
LABEL_32:
        if ( a3 )
        {
          v43 = 0;
          while ( *(_DWORD *)(a2 + 4LL * v43) != *(_DWORD *)(*(_QWORD *)(v31 + 24) + 1064LL) )
          {
            if ( a3 == ++v43 )
              goto LABEL_36;
          }
          goto LABEL_44;
        }
LABEL_36:
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v27 + 8);
        }
        else
        {
          raw_spin_lock_bh(v27 + 8);
          *(_QWORD *)(v27 + 16) |= 1uLL;
        }
        if ( *(_DWORD *)(v31 + 20) == 306772034 )
        {
          if ( *(_DWORD *)(v31 + 16) )
          {
            *(_DWORD *)(v31 + 20) = 0;
            scm_scan_entry_put_ref(v27, v31, 0, v44, v45, v46, v47, v48, v49, v50, v51);
            v41 = *(_QWORD *)(v27 + 16);
            if ( (v41 & 1) == 0 )
              goto LABEL_43;
            goto LABEL_30;
          }
          v42 = "%s: node is already deleted ref 0";
        }
        else
        {
          v42 = "%s: node is already deleted";
        }
        qdf_trace_msg(0x15u, 8u, v42, v44, v45, v46, v47, v48, v49, v50, v51, "scm_scan_entry_del", v52);
        v41 = *(_QWORD *)(v27 + 16);
        if ( (v41 & 1) == 0 )
        {
LABEL_43:
          raw_spin_unlock(v27 + 8);
          goto LABEL_44;
        }
LABEL_30:
        *(_QWORD *)(v27 + 16) = v41 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v27 + 8);
LABEL_44:
        result = scm_get_next_node(v27, (__int64)v30, v31);
        v31 = result;
        if ( !result )
          goto LABEL_10;
      }
    }
    v24 = "%s: psoc is NULL";
  }
  else
  {
    v24 = "%s: pdev is NULL";
  }
LABEL_49:
  result = qdf_trace_msg(0x15u, 2u, v24, v14, v15, v16, v17, v18, v19, v20, v21, "scm_filter_valid_channel");
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
