__int64 __fastcall qcrypto_suspend(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x0
  int v4; // w8
  __int64 v5; // x1
  void (__fastcall *v6)(__int64); // x8
  __int64 v7; // x0

  v1 = *(_QWORD *)(a1 + 168);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(v1 + 32);
  if ( *(_BYTE *)(v2 + 35) != 1 )
    return 0;
  v3 = raw_spin_lock_irqsave(v2 + 52);
  v4 = *(_DWORD *)(v1 + 112);
  v5 = v3;
  if ( v4 == 1 )
  {
    if ( *(int *)(v1 + 248) <= 0 && !*(_DWORD *)(v1 + 72) && !*(_DWORD *)(*(_QWORD *)(v1 + 32) + 216LL) )
    {
      *(_DWORD *)(v1 + 112) = 5;
      raw_spin_unlock_irqrestore(v2 + 52, v3);
      timer_delete_sync(v1 + 120);
      qcrypto_ce_set_bus(v1, 0);
      v5 = raw_spin_lock_irqsave(v2 + 52);
      goto LABEL_6;
    }
  }
  else if ( !v4 && (*(_BYTE *)(v1 + 116) & 1) == 0 )
  {
LABEL_6:
    *(_DWORD *)(v1 + 112) = 4;
    raw_spin_unlock_irqrestore(v2 + 52, v5);
    if ( qce_pm_table )
    {
      qcrypto_ce_set_bus(v1, 1);
      v6 = (void (__fastcall *)(__int64))qce_pm_table;
      v7 = *(_QWORD *)(v1 + 16);
      if ( *(_DWORD *)(qce_pm_table - 4LL) != -1066802076 )
        __break(0x8228u);
      v6(v7);
      qcrypto_ce_set_bus(v1, 0);
    }
    return 0;
  }
  raw_spin_unlock_irqrestore(v2 + 52, v3);
  return 4294967280LL;
}
