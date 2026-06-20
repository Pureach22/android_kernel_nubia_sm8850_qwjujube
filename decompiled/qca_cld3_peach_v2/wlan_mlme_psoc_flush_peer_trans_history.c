__int64 __fastcall wlan_mlme_psoc_flush_peer_trans_history(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  unsigned __int64 StatusReg; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  __int64 v22; // x8
  __int64 v23[2]; // [xsp+0h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 2816);
    }
    else
    {
      raw_spin_lock_bh(a1 + 2816);
      *(_QWORD *)(a1 + 2824) |= 1uLL;
    }
    while ( *(_DWORD *)(v11 + 2144) )
    {
      v23[0] = 0;
      qdf_list_remove_back(v11 + 2128, v23);
      _qdf_mem_free(v23[0]);
    }
    v22 = *(_QWORD *)(a1 + 2824);
    if ( (v22 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v22 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      result = raw_spin_unlock(a1 + 2816);
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: PSOC MLME component object is NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_psoc_mlme_get_cmpt_obj");
    result = qdf_trace_msg(
               0x68u,
               2u,
               "%s: PSOC MLME component object is NULL",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "wlan_mlme_psoc_flush_peer_trans_history");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
