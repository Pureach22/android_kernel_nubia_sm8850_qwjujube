__int64 __fastcall tgt_mc_cp_stats_extract_vdev_extd_stats(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  unsigned __int8 v14; // w8
  unsigned __int64 StatusReg; // x23
  __int64 v16; // x24
  __int64 v17; // x0
  __int64 v18; // x21
  __int64 comp_private_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x22
  __int64 v29; // x8
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  _QWORD v48[7]; // [xsp+8h] [xbp-38h] BYREF

  v48[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 192);
  memset(v48, 0, 48);
  if ( v2 )
  {
    v4 = result;
    result = ucfg_mc_cp_stats_get_pending_req(result, 1, v48);
    if ( (_DWORD)result )
    {
      v13 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
LABEL_4:
      result = qdf_trace_msg(
                 0x62u,
                 2u,
                 v13,
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 "tgt_mc_cp_stats_extract_vdev_extd_stats");
    }
    else if ( *(_DWORD *)(a2 + 188) )
    {
      v14 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v16 = v14;
        v17 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                v4,
                *(unsigned __int8 *)(*(_QWORD *)(a2 + 192) + 8LL * v14),
                38);
        if ( !v17 )
        {
          v13 = "%s: vdev is null";
          goto LABEL_4;
        }
        v18 = v17;
        comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v17, 0x1Bu);
        if ( !comp_private_obj )
          break;
        v28 = comp_private_obj;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(comp_private_obj + 24);
        }
        else
        {
          raw_spin_lock_bh(comp_private_obj + 24);
          *(_QWORD *)(v28 + 32) |= 1uLL;
        }
        qdf_mem_copy((void *)(*(_QWORD *)(v28 + 8) + 132LL), (const void *)(*(_QWORD *)(a2 + 192) + 8 * v16), 8u);
        v29 = *(_QWORD *)(v28 + 32);
        if ( (v29 & 1) != 0 )
        {
          *(_QWORD *)(v28 + 32) = v29 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v28 + 24);
        }
        else
        {
          raw_spin_unlock(v28 + 24);
        }
        result = wlan_objmgr_vdev_release_ref(v18, 0x26u, v30, v31, v32, v33, v34, v35, v36, v37, v38);
        v14 = v16 + 1;
        if ( *(_DWORD *)(a2 + 188) <= (unsigned int)(unsigned __int8)(v16 + 1) )
          goto LABEL_5;
      }
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: vdev cp stats object is null",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "tgt_mc_cp_stats_extract_vdev_extd_stats");
      result = wlan_objmgr_vdev_release_ref(v18, 0x26u, v39, v40, v41, v42, v43, v44, v45, v46, v47);
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
