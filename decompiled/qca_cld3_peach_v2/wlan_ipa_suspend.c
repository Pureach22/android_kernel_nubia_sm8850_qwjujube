__int64 __fastcall wlan_ipa_suspend(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x8
  __int64 v5; // x8

  if ( *(_DWORD *)(a1 + 3284) )
    return 3;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 3360);
    v4 = *(_QWORD *)(a1 + 3368);
  }
  else
  {
    raw_spin_lock_bh(a1 + 3360);
    v4 = *(_QWORD *)(a1 + 3368) | 1LL;
    *(_QWORD *)(a1 + 3368) = v4;
  }
  *(_BYTE *)(a1 + 3376) = 1;
  if ( (v4 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 3368) = v4 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 3360);
  }
  else
  {
    raw_spin_unlock(a1 + 3360);
  }
  v5 = *(_QWORD *)(a1 + 1464);
  if ( *(_BYTE *)(v5 + 36) == 1 && (*(_BYTE *)(a1 + 3440) & 1) == 0 )
    wlan_ipa_set_perf_level(a1, *(unsigned int *)(v5 + 12), *(unsigned int *)(v5 + 12));
  return 0;
}
