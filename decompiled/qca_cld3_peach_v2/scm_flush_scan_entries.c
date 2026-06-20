__int64 __fastcall scm_flush_scan_entries(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  __int64 v4; // x8
  __int64 v8; // x28
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0
  __int64 v11; // x27
  __int64 v12; // x8
  const char *v13; // x2
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 comp_private_obj; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  __int64 v32; // x0
  __int64 v40; // [xsp+8h] [xbp-28h]
  _QWORD v41[4]; // [xsp+10h] [xbp-20h] BYREF

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v40 = a2 + 24;
  v41[3] = v4;
  do
  {
    result = scm_get_next_node(a2, v40 + 24 * v8, 0);
    if ( result )
    {
      v11 = result;
      do
      {
        memset(v41, 0, 24);
        if ( a3 && (scm_filter_match(a1, *(_QWORD *)(v11 + 24), a3, v41) & 1) == 0 )
          goto LABEL_19;
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
        if ( *(_DWORD *)(v11 + 20) == 306772034 )
        {
          if ( *(_DWORD *)(v11 + 16) )
          {
            *(_DWORD *)(v11 + 20) = 0;
            scm_scan_entry_put_ref(a2, v11, 0, v14, v15, v16, v17, v18, v19, v20, v21);
            v12 = *(_QWORD *)(a2 + 16);
            if ( (v12 & 1) == 0 )
              goto LABEL_18;
            goto LABEL_7;
          }
          v13 = "%s: node is already deleted ref 0";
        }
        else
        {
          v13 = "%s: node is already deleted";
        }
        qdf_trace_msg(0x15u, 8u, v13, v14, v15, v16, v17, v18, v19, v20, v21, "scm_scan_entry_del");
        v12 = *(_QWORD *)(a2 + 16);
        if ( (v12 & 1) == 0 )
        {
LABEL_18:
          raw_spin_unlock(a2 + 8);
          goto LABEL_19;
        }
LABEL_7:
        *(_QWORD *)(a2 + 16) = v12 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 8);
LABEL_19:
        result = scm_get_next_node(a2, v40 + 24 * v8, v11);
        v11 = result;
      }
      while ( result );
    }
    ++v8;
  }
  while ( v8 != 64 );
  if ( a3 )
    goto LABEL_27;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
  {
    v31 = comp_private_obj;
    v32 = qdf_trace_msg(
            0x15u,
            8u,
            "%s: pdev %d, Reset all channel info",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "scm_reset_scan_chan_info",
            a4);
    if ( !a4 )
    {
      result = (__int64)qdf_mem_set((void *)(v31 + 17524), 0x334u, 0);
      goto LABEL_27;
    }
    __break(0x5512u);
    __asm { PRFM            #0xA, [X17,#0x3CD8] }
    return scm_filter_valid_channel(v32);
  }
  else
  {
    result = qdf_trace_msg(
               0x15u,
               2u,
               "%s: %s:%u, Failed to get scan object",
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               "wlan_psoc_get_scan_obj_fl",
               "scm_reset_scan_chan_info",
               1955);
LABEL_27:
    _ReadStatusReg(SP_EL0);
  }
  return result;
}
