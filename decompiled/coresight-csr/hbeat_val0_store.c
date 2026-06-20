__int64 __fastcall hbeat_val0_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 result; // x0
  unsigned __int64 v6; // x21
  __int64 v8; // x19
  int v9; // w20
  int v10; // w0
  __int64 v11; // x0
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x19
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  result = -22;
  v6 = *(_QWORD *)(v4 + 152);
  if ( v6 && v6 <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(v6 + 160) == 1 )
  {
    v15[0] = 0;
    if ( (unsigned int)kstrtoull(a3, 16, v15) )
    {
      result = -22;
    }
    else
    {
      v8 = *(_QWORD *)(v6 + 144);
      v9 = clk_prepare(v8);
      if ( !v9 )
      {
        v10 = clk_enable(v8);
        if ( !v10 )
        {
          v11 = raw_spin_lock_irqsave(v6 + 152);
          v12 = v15[0];
          v13 = *(_QWORD *)v6;
          *(_QWORD *)(v6 + 72) = v15[0];
          *(_DWORD *)(v13 + 4016) = -978530731;
          __dsb(0xFu);
          *(_QWORD *)(*(_QWORD *)v6 + 132LL) = v12;
          __dsb(0xFu);
          *(_DWORD *)(*(_QWORD *)v6 + 4016LL) = 0;
          raw_spin_unlock_irqrestore(v6 + 152, v11);
          v14 = *(_QWORD *)(v6 + 144);
          clk_disable(v14);
          clk_unprepare(v14);
          result = a4;
          goto LABEL_10;
        }
        v9 = v10;
        clk_unprepare(v8);
      }
      result = v9;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
