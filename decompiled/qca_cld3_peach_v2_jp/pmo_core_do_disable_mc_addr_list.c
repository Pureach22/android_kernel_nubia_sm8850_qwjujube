__int64 __fastcall pmo_core_do_disable_mc_addr_list(__int64 a1, __int64 a2, void *a3)
{
  unsigned __int64 v6; // x8
  __int64 v7; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x8
  __int64 v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v6 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v6 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v6 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 1056);
    if ( *(_BYTE *)(a2 + 672) )
      goto LABEL_5;
  }
  else
  {
    raw_spin_lock_bh(a2 + 1056);
    *(_QWORD *)(a2 + 1064) |= 1uLL;
    if ( *(_BYTE *)(a2 + 672) )
    {
LABEL_5:
      qdf_mem_copy(a3, (const void *)(a2 + 672), 0xC2u);
      v7 = *(_QWORD *)(a2 + 1064);
      if ( (v7 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 1064) = v7 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 1056);
      }
      else
      {
        raw_spin_unlock(a2 + 1056);
      }
      ((void (__fastcall *)(__int64, void *))pmo_core_clear_mc_filter_req)(a1, a3);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a2 + 1056);
        v9 = *(_QWORD *)(a2 + 1064);
        *(_BYTE *)(a2 + 672) = 0;
        if ( (v9 & 1) == 0 )
        {
LABEL_11:
          raw_spin_unlock(a2 + 1056);
          return 0;
        }
      }
      else
      {
        raw_spin_lock_bh(a2 + 1056);
        v9 = *(_QWORD *)(a2 + 1064) | 1LL;
        *(_QWORD *)(a2 + 1064) = v9;
        *(_BYTE *)(a2 + 672) = 0;
        if ( (v9 & 1) == 0 )
          goto LABEL_11;
      }
      *(_QWORD *)(a2 + 1064) = v9 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 1056);
      return 0;
    }
  }
  v11 = *(_QWORD *)(a2 + 1064);
  if ( (v11 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 1064) = v11 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 1056);
  }
  else
  {
    raw_spin_unlock(a2 + 1056);
  }
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: mc filter is not applied in fwr",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "pmo_core_do_disable_mc_addr_list");
  return 4;
}
