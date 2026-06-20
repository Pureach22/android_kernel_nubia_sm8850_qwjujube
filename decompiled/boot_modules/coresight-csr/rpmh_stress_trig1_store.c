__int64 __fastcall rpmh_stress_trig1_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  _QWORD *v6; // x22
  __int64 v7; // x20
  int v8; // w21
  int v9; // w0
  __int64 v11; // x0
  __int64 v12; // x10
  __int64 v13; // x20
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v14[0] = 0;
  v6 = *(_QWORD **)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 16, v14) )
  {
    a4 = -22;
  }
  else
  {
    v7 = v6[18];
    v8 = clk_prepare(v7);
    if ( !v8 )
    {
      v9 = clk_enable(v7);
      if ( !v9 )
      {
        v11 = raw_spin_lock_irqsave(v6 + 19);
        v12 = LOWORD(v14[0]);
        *((_DWORD *)v6 + 27) = v14[0];
        v14[0] = v12;
        *(_DWORD *)(*v6 + 4016LL) = -978530731;
        __dsb(0xFu);
        *(_DWORD *)(*v6 + 396LL) = v14[0];
        __dsb(0xFu);
        *(_DWORD *)(*v6 + 4016LL) = 0;
        raw_spin_unlock_irqrestore(v6 + 19, v11);
        v13 = v6[18];
        clk_disable(v13);
        clk_unprepare(v13);
        goto LABEL_7;
      }
      v8 = v9;
      clk_unprepare(v7);
    }
    a4 = v8;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return a4;
}
