__int64 __fastcall target_if_get_psoc_from_scn_hdl(__int64 a1)
{
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v4; // x8
  __int64 (__fastcall *v5)(_QWORD); // x9
  __int64 v6; // x0
  __int64 v7; // x9
  __int64 v9; // x21

  v2 = g_target_if_ctx;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 32);
    v4 = g_target_if_ctx;
    if ( !a1 )
      goto LABEL_10;
  }
  else
  {
    v9 = v2;
    raw_spin_lock_bh(v2 + 32);
    *(_QWORD *)(v9 + 40) |= 1uLL;
    v4 = g_target_if_ctx;
    if ( !a1 )
      goto LABEL_10;
  }
  v5 = *(__int64 (__fastcall **)(_QWORD))(v4 + 8);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != -1248559596 )
      __break(0x8229u);
    v6 = v5(a1);
    v4 = g_target_if_ctx;
    a1 = v6;
  }
  else
  {
    a1 = 0;
  }
LABEL_10:
  v7 = *(_QWORD *)(v4 + 40);
  if ( (v7 & 1) != 0 )
  {
    *(_QWORD *)(v4 + 40) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v4 + 32);
  }
  else
  {
    raw_spin_unlock(v4 + 32);
  }
  return a1;
}
