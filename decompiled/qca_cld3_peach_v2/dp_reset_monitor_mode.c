__int64 __fastcall dp_reset_monitor_mode(__int64 a1, char a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v6; // x21
  unsigned __int64 StatusReg; // x8
  unsigned int v8; // w0
  __int64 v9; // x8
  unsigned int v10; // w19

  if ( a2 )
    return 16;
  v3 = *(_QWORD *)(a1 + 72);
  if ( !v3 )
  {
    return 16;
  }
  else
  {
    v6 = *(_QWORD *)(v3 + 96456);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v6 + 40);
    }
    else
    {
      raw_spin_lock_bh(v6 + 40);
      *(_QWORD *)(v6 + 48) |= 1uLL;
    }
    v8 = dp_reset_monitor_mode_unlock(a1, 0, a3);
    v9 = *(_QWORD *)(v6 + 48);
    v10 = v8;
    if ( (v9 & 1) != 0 )
    {
      *(_QWORD *)(v6 + 48) = v9 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v6 + 40);
    }
    else
    {
      raw_spin_unlock(v6 + 40);
    }
  }
  return v10;
}
