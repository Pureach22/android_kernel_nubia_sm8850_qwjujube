__int64 __fastcall dp_mon_reap_timer_start(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  __int64 v3; // x8
  unsigned __int64 StatusReg; // x8
  _BOOL4 v6; // w21
  __int64 v7; // x8
  __int64 v8; // x19
  unsigned int multiplier; // w0

  v2 = *(_QWORD *)(a1 + 20112);
  if ( *(_BYTE *)(v2 + 320) )
  {
    v3 = *(_QWORD *)(a1 + 800);
    if ( !v3 || !*(_DWORD *)(v3 + 52) || (*(_BYTE *)(v3 + 78) & 2) == 0 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v2 + 328);
      }
      else
      {
        raw_spin_lock_bh(v2 + 328);
        *(_QWORD *)(v2 + 336) |= 1uLL;
      }
      v6 = (*(_QWORD *)(v2 + 344) & 7LL) == 0;
      if ( a2 == 4 )
        v6 = (*(_QWORD *)(v2 + 344) & 7LL) != 0;
      else
        *(_QWORD *)(v2 + 344 + (((unsigned __int64)a2 >> 3) & 0x1FFFFFF8)) |= 1LL << a2;
      v7 = *(_QWORD *)(v2 + 336);
      if ( (v7 & 1) != 0 )
      {
        *(_QWORD *)(v2 + 336) = v7 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v2 + 328);
        if ( v6 )
          goto LABEL_14;
      }
      else
      {
        raw_spin_unlock(v2 + 328);
        if ( v6 )
        {
LABEL_14:
          v8 = jiffies;
          multiplier = qdf_timer_get_multiplier();
          mod_timer(v2 + 264, v8 + 2LL * multiplier);
          return 1;
        }
      }
    }
  }
  return 0;
}
