__int64 __fastcall coresight_csr_hwctrl_set(__int64 a1, __int64 a2, int a3)
{
  bool v4; // zf
  unsigned __int64 v5; // x19
  __int64 result; // x0
  __int64 v8; // x21
  __int64 v10; // x1
  __int64 v11; // x9
  unsigned int v12; // w20

  if ( !a1 )
    return 4294967274LL;
  v5 = a1 - 120;
  v4 = a1 == 120;
  result = 4294967274LL;
  if ( !v4 && v5 <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(a1 + 38) == 1 )
  {
    v8 = a1;
    v10 = raw_spin_lock_irqsave(a1 + 32);
    *(_DWORD *)(*(_QWORD *)(v8 - 120) + 4016LL) = -978530731;
    __dsb(0xFu);
    v11 = *(_QWORD *)(v8 - 112);
    if ( v11 + 32 == a2 )
    {
      *(_DWORD *)(*(_QWORD *)v5 + 32LL) = a3;
    }
    else if ( v11 + 36 == a2 )
    {
      *(_DWORD *)(*(_QWORD *)v5 + 36LL) = a3;
    }
    else if ( v11 + 40 == a2 )
    {
      *(_DWORD *)(*(_QWORD *)v5 + 40LL) = a3;
    }
    else
    {
      if ( v11 + 44 != a2 )
      {
        v12 = -22;
        goto LABEL_15;
      }
      *(_DWORD *)(*(_QWORD *)v5 + 44LL) = a3;
    }
    v12 = 0;
LABEL_15:
    __dsb(0xFu);
    *(_DWORD *)(*(_QWORD *)v5 + 4016LL) = 0;
    raw_spin_unlock_irqrestore(v8 + 32, v10);
    return v12;
  }
  return result;
}
