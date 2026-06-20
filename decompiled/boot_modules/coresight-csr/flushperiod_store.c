__int64 __fastcall flushperiod_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  _DWORD *v5; // x22
  __int64 v8; // x20
  int v9; // w9
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  v11[0] = 0;
  v5 = *(_DWORD **)(v4 + 152);
  if ( !v5 || (unsigned __int64)v5 > 0xFFFFFFFFFFFFF000LL || (v5[39] & 1) == 0 )
  {
    dev_err();
    goto LABEL_12;
  }
  v8 = raw_spin_lock_irqsave(v5 + 38);
  if ( (unsigned int)kstrtoull(a3, 0, v11) || v11[0] >= 0x10000u )
  {
    raw_spin_unlock_irqrestore(v5 + 38, v8);
LABEL_12:
    a4 = -22;
    goto LABEL_13;
  }
  if ( v11[0] != v5[17] )
  {
    v9 = *((unsigned __int8 *)v5 + 161);
    v5[17] = v11[0];
    if ( v9 == 1 )
    {
      *(_DWORD *)(*(_QWORD *)v5 + 4016LL) = -978530731;
      __dsb(0xFu);
      *(_DWORD *)(*(_QWORD *)v5 + 52LL) = *(_DWORD *)(*(_QWORD *)v5 + 52LL) & 0xFFFC0003 | (4 * v5[17]);
      __dsb(0xFu);
      *(_DWORD *)(*(_QWORD *)v5 + 4016LL) = 0;
    }
  }
  raw_spin_unlock_irqrestore(v5 + 38, v8);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return a4;
}
