__int64 __fastcall wlan_mlme_psoc_peer_tbl_trans_add_entry(__int64 a1, _QWORD *a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  unsigned __int64 StatusReg; // x8
  unsigned int inserted; // w0
  __int64 v16; // x8
  unsigned int v17; // w20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0);
  if ( comp_private_obj )
  {
    v13 = comp_private_obj;
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
    if ( *(_DWORD *)(v13 + 2144) == 256 )
    {
      v27[0] = 0;
      qdf_list_remove_back(v13 + 2128, v27);
      _qdf_mem_free(v27[0]);
    }
    inserted = qdf_list_insert_front((_QWORD *)(v13 + 2128), a2);
    v16 = *(_QWORD *)(a1 + 2824);
    v17 = inserted;
    if ( (v16 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v16 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: PSOC MLME component object is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_psoc_mlme_get_cmpt_obj");
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: PSOC MLME component object is NULL",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_mlme_psoc_peer_tbl_trans_add_entry");
    v17 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
