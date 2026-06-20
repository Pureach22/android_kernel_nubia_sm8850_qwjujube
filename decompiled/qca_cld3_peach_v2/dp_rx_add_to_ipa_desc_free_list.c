__int64 __fastcall dp_rx_add_to_ipa_desc_free_list(__int64 a1, __int64 a2, char a3)
{
  unsigned __int64 StatusReg; // x8
  char v7; // w8
  __int64 v8; // x8
  __int64 v9; // x8

  if ( a3 && *(_QWORD *)a2 )
    _qdf_nbuf_free(*(_QWORD *)a2);
  if ( *(unsigned __int16 *)(a1 + 17920) > 0x3Fu )
    return 16;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 17904);
  }
  else
  {
    raw_spin_lock_bh(a1 + 17904);
    *(_QWORD *)(a1 + 17912) |= 1uLL;
  }
  v7 = *(_BYTE *)(a2 + 30);
  *(_QWORD *)a2 = 0;
  *(_BYTE *)(a2 + 30) = v7 & 0xFE;
  *(_QWORD *)a2 = *(_QWORD *)(a1 + 17888);
  v8 = *(_QWORD *)(a1 + 17896);
  *(_QWORD *)(a1 + 17888) = a2;
  if ( !v8 || !*(_QWORD *)a2 )
    *(_QWORD *)(a1 + 17896) = a2;
  v9 = *(_QWORD *)(a1 + 17912);
  ++*(_WORD *)(a1 + 17920);
  if ( (v9 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 17912) = v9 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 17904);
  }
  else
  {
    raw_spin_unlock(a1 + 17904);
  }
  return 0;
}
