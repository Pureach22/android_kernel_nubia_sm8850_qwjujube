__int64 __fastcall dp_mon_reap_timer_stop(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  __int64 v3; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8
  int v7; // w19

  v2 = *(_QWORD *)(a1 + 20112);
  if ( !*(_BYTE *)(v2 + 320) )
    return 0;
  v3 = *(_QWORD *)(a1 + 800);
  if ( v3 )
  {
    if ( *(_DWORD *)(v3 + 52) && (*(_BYTE *)(v3 + 78) & 2) != 0 )
      return 0;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 328);
    if ( a2 == 4 )
      goto LABEL_10;
    goto LABEL_9;
  }
  raw_spin_lock_bh(v2 + 328);
  *(_QWORD *)(v2 + 336) |= 1uLL;
  if ( a2 != 4 )
LABEL_9:
    *(_QWORD *)(v2 + (((unsigned __int64)a2 >> 3) & 0x1FFFFFF8) + 344) &= ~(1LL << a2);
LABEL_10:
  v6 = *(_QWORD *)(v2 + 336);
  v7 = (a2 == 4) ^ ((*(_BYTE *)(v2 + 344) & 7) == 0);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(v2 + 336) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v2 + 328);
    if ( v7 )
      goto LABEL_12;
  }
  else
  {
    raw_spin_unlock(v2 + 328);
    if ( v7 )
    {
LABEL_12:
      timer_delete_sync(v2 + 264);
      return 1;
    }
  }
  return 0;
}
