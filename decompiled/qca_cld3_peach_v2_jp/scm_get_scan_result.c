_QWORD *__fastcall scm_get_scan_result(
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
  __int64 v10; // x20
  unsigned int v11; // w21
  const char *v12; // x2
  __int64 comp_private_obj; // x0
  __int64 v15; // x8
  __int64 v16; // x22
  _QWORD *v17; // x0
  __int64 v18; // x28
  __int64 v19; // x24
  __int64 next_node; // x25
  __int64 v21; // x8
  __int64 v22; // x26
  _QWORD *v23; // x0
  _QWORD *v24; // x27
  __int64 v25; // x0
  unsigned int v32; // w9
  _QWORD *result; // x0
  unsigned __int64 StatusReg; // [xsp+0h] [xbp-40h]
  _QWORD *v35; // [xsp+10h] [xbp-30h]
  _QWORD v36[3]; // [xsp+18h] [xbp-28h] BYREF
  _QWORD v37[2]; // [xsp+30h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 80);
    if ( v10 )
    {
      v11 = *(unsigned __int8 *)(a1 + 40);
      if ( v11 >= 2 )
      {
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: invalid pdev_id %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "wlan_pdevid_get_scan_db",
          *(unsigned __int8 *)(a1 + 40));
        goto LABEL_38;
      }
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 3u);
      if ( !comp_private_obj )
      {
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: %s:%u, Failed to get scan object",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "wlan_psoc_get_scan_obj_fl",
          "wlan_pdevid_get_scan_db",
          57);
        goto LABEL_38;
      }
      v15 = comp_private_obj + 1560LL * v11;
      v16 = v15 + 32;
      if ( v15 == -32 )
      {
LABEL_38:
        v12 = "%s: scan_db is NULL";
        goto LABEL_39;
      }
      v17 = qdf_mem_malloc_atomic_fl(0x18u, (__int64)"scm_get_scan_result", 0x672u);
      if ( !v17 )
      {
        v12 = "%s: failed tp allocate scan_result";
        goto LABEL_39;
      }
      *v17 = v17;
      v17[1] = v17;
      v35 = v17;
      v17[2] = 0x1F400000000LL;
      scm_age_out_entries(v10, v16, a3, a4, a5, a6, a7, a8, a9, a10);
      v18 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v16 + 8);
        }
        else
        {
          raw_spin_lock_bh(v16 + 8);
          *(_QWORD *)(v16 + 16) |= 1uLL;
        }
        v19 = v16 + 24 + 24 * v18;
        v36[0] = 0;
        v37[0] = 0;
        qdf_list_peek_front((_QWORD *)v19, v36);
        next_node = v36[0];
        if ( v36[0] )
        {
          while ( *(_DWORD *)(next_node + 20) != 306772034 )
          {
            qdf_list_peek_next((_QWORD *)v19, (_QWORD *)next_node, v37);
            next_node = v37[0];
            v37[0] = 0;
            v36[0] = next_node;
            if ( !next_node )
              goto LABEL_19;
          }
          _X8 = (unsigned int *)(next_node + 16);
          __asm { PRFM            #0x11, [X8] }
          do
            v32 = __ldxr(_X8);
          while ( __stxr(v32 + 1, _X8) );
          v21 = *(_QWORD *)(v16 + 16);
          if ( (v21 & 1) == 0 )
          {
LABEL_22:
            raw_spin_unlock(v16 + 8);
            if ( next_node )
              goto LABEL_23;
            goto LABEL_11;
          }
        }
        else
        {
LABEL_19:
          next_node = 0;
          v21 = *(_QWORD *)(v16 + 16);
          if ( (v21 & 1) == 0 )
            goto LABEL_22;
        }
        *(_QWORD *)(v16 + 16) = v21 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v16 + 8);
        if ( next_node )
        {
LABEL_23:
          if ( *(_DWORD *)(v19 + 16) )
          {
            do
            {
              v22 = *(_QWORD *)(next_node + 24);
              memset(v36, 0, sizeof(v36));
              if ( !a2 || (scm_filter_match(v10, v22, a2, v36) & 1) != 0 )
              {
                v23 = qdf_mem_malloc_atomic_fl(0x20u, (__int64)"scm_scan_apply_filter_get_entry", 0x603u);
                if ( v23 )
                {
                  v24 = v23;
                  v25 = util_scan_copy_cache_entry_0(v22);
                  v24[3] = v25;
                  if ( v25 )
                  {
                    qdf_mem_copy((void *)(v25 + 1136), v36, 0x18u);
                    qdf_list_insert_front(v35, v24);
                  }
                  else
                  {
                    _qdf_mem_free((__int64)v24);
                  }
                }
              }
              next_node = scm_get_next_node(v16, v19, next_node);
            }
            while ( next_node );
          }
        }
LABEL_11:
        if ( ++v18 == 64 )
        {
          result = v35;
          goto LABEL_40;
        }
      }
    }
    v12 = "%s: psoc is NULL";
  }
  else
  {
    v12 = "%s: pdev is NULL";
  }
LABEL_39:
  qdf_trace_msg(0x15u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "scm_get_scan_result");
  result = nullptr;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
