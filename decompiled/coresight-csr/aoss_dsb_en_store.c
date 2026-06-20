__int64 __fastcall aoss_dsb_en_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 result; // x0
  unsigned __int64 v6; // x22
  __int64 v8; // x19
  int v9; // w20
  int v10; // w0
  __int64 v11; // x0
  __int64 v12; // x10
  __int64 v13; // x19
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  result = -22;
  v6 = *(_QWORD *)(v4 + 152);
  if ( v6 && v6 <= 0xFFFFFFFFFFFFF000LL )
  {
    v14[0] = 0;
    if ( (unsigned int)kstrtobool(a3, v14) )
    {
      result = -22;
      goto LABEL_12;
    }
    if ( v14[0] == 1 )
    {
      v8 = *(_QWORD *)(v6 + 144);
      v9 = clk_prepare(v8);
      if ( v9 )
      {
LABEL_9:
        result = v9;
        goto LABEL_12;
      }
      v10 = clk_enable(v8);
      if ( v10 )
      {
        v9 = v10;
        clk_unprepare(v8);
        goto LABEL_9;
      }
      v11 = raw_spin_lock_irqsave(v6 + 152);
      v12 = *(_QWORD *)v6;
      *(_DWORD *)(v6 + 112) = v14[0];
      *(_DWORD *)(v12 + 4016) = -978530731;
      __dsb(0xFu);
      *(_DWORD *)(*(_QWORD *)v6 + 304LL) = *(_DWORD *)(v6 + 112);
      *(_DWORD *)(*(_QWORD *)v6 + 308LL) = *(_DWORD *)(v6 + 112);
      *(_DWORD *)(*(_QWORD *)v6 + 312LL) = *(_DWORD *)(v6 + 112);
      *(_DWORD *)(*(_QWORD *)v6 + 316LL) = *(_DWORD *)(v6 + 112);
      *(_DWORD *)(*(_QWORD *)v6 + 320LL) = *(_DWORD *)(v6 + 112);
      __dsb(0xFu);
      *(_DWORD *)(*(_QWORD *)v6 + 4016LL) = 0;
      raw_spin_unlock_irqrestore(v6 + 152, v11);
      v13 = *(_QWORD *)(v6 + 144);
      clk_disable(v13);
      clk_unprepare(v13);
    }
    result = a4;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
