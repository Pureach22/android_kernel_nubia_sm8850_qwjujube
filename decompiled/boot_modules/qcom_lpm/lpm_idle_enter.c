void __fastcall lpm_idle_enter(__int64 a1, _DWORD *a2)
{
  unsigned __int64 StatusReg; // x8
  _BYTE *v3; // x19
  __int64 v5; // x1

  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *a2 )
  {
    v3 = &lpm_cpu_data[StatusReg];
    if ( *(_DWORD *)&lpm_cpu_data[StatusReg + 4] )
    {
      v5 = raw_spin_lock_irqsave(v3 + 320);
      if ( v3[316] == 1 )
        *a2 = 0;
      raw_spin_unlock_irqrestore(v3 + 320, v5);
    }
  }
}
