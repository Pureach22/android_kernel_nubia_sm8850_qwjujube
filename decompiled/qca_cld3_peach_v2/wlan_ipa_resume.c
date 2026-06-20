__int64 __fastcall wlan_ipa_resume(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8

  queue_work_on(32, system_wq, a1 + 3312);
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 3360);
      v3 = *(_QWORD *)(a1 + 3368) | 1LL;
      *(_QWORD *)(a1 + 3368) = v3;
      *(_BYTE *)(a1 + 3376) = 0;
      if ( (v3 & 1) == 0 )
        goto LABEL_5;
LABEL_8:
      *(_QWORD *)(a1 + 3368) = v3 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 3360);
      return 0;
    }
  }
  raw_spin_lock(a1 + 3360);
  v3 = *(_QWORD *)(a1 + 3368);
  *(_BYTE *)(a1 + 3376) = 0;
  if ( (v3 & 1) != 0 )
    goto LABEL_8;
LABEL_5:
  raw_spin_unlock(a1 + 3360);
  return 0;
}
