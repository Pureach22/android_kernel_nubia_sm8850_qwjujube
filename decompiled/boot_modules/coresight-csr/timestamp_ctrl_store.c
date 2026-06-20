__int64 __fastcall timestamp_ctrl_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v4; // x9
  _QWORD *v5; // x22
  __int64 v7; // x20
  int v8; // w21
  int v9; // w0
  __int64 v10; // x0
  __int64 v11; // x20
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  v13 = 0;
  v5 = *(_QWORD **)(v4 + 152);
  if ( v5 && (unsigned __int64)v5 <= 0xFFFFFFFFFFFFF000LL && (v5[20] & 1) != 0 )
  {
    if ( sscanf(s, "%x", &v13) == 1 )
    {
      v7 = v5[18];
      v8 = clk_prepare(v7);
      if ( !v8 )
      {
        v9 = clk_enable(v7);
        if ( !v9 )
        {
          v10 = raw_spin_lock_irqsave(v5 + 19);
          *(_DWORD *)(*v5 + 4016LL) = -978530731;
          __dsb(0xFu);
          *(_DWORD *)(*v5 + 56LL) = v13;
          __dsb(0xFu);
          *(_DWORD *)(*v5 + 4016LL) = 0;
          raw_spin_unlock_irqrestore(v5 + 19, v10);
          v11 = v5[18];
          clk_disable(v11);
          clk_unprepare(v11);
          goto LABEL_12;
        }
        v8 = v9;
        clk_unprepare(v7);
      }
      a4 = v8;
    }
    else
    {
      a4 = -22;
    }
  }
  else
  {
    dev_err();
    a4 = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return a4;
}
