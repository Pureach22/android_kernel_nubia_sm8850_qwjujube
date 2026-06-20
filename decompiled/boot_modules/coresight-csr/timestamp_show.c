__int64 __fastcall timestamp_show(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x22
  __int64 v4; // x20
  int v6; // w21
  int v7; // w0
  __int64 v9; // x0
  int v10; // w9
  unsigned int v11; // w21
  __int64 v12; // x23
  __int64 v13; // x20

  v3 = *(_QWORD **)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( v3 && (unsigned __int64)v3 <= 0xFFFFFFFFFFFFF000LL && (v3[20] & 1) != 0 )
  {
    v4 = v3[18];
    v6 = clk_prepare(v4);
    if ( !v6 )
    {
      v7 = clk_enable(v4);
      if ( !v7 )
      {
        v9 = raw_spin_lock_irqsave(v3 + 19);
        *(_DWORD *)(*v3 + 4016LL) = -978530731;
        __dsb(0xFu);
        v10 = *(_DWORD *)(*v3 + 56LL);
        *(_DWORD *)(*v3 + 56LL) = v10 & 0xFFFFFFFE;
        *(_DWORD *)(*v3 + 56LL) = v10 | 1;
        v11 = *(_DWORD *)(*v3 + 68LL);
        v12 = *(unsigned int *)(*v3 + 72LL);
        __dsb(0xFu);
        *(_DWORD *)(*v3 + 4016LL) = 0;
        raw_spin_unlock_irqrestore(v3 + 19, v9);
        v13 = v3[18];
        clk_disable(v13);
        clk_unprepare(v13);
        return (int)scnprintf(a3, 4096, "%llu\n", v11 | (unsigned __int64)(v12 << 32));
      }
      v6 = v7;
      clk_unprepare(v4);
    }
    return v6;
  }
  else
  {
    dev_err();
    return 0;
  }
}
