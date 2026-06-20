__int64 __fastcall qpace_urgent_compress(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x24
  __int64 v5; // x20
  unsigned __int64 *v6; // x8
  unsigned int i; // w0
  __int64 v8; // x8
  unsigned int v9; // w20
  __int64 v10; // x26
  __int64 v11; // x8
  unsigned int v13; // w20
  unsigned int v14; // w19

  StatusReg = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(StatusReg + 16);
  v5 = (int)(*(_DWORD *)(StatusReg + 40) << 12);
  v6 = (unsigned __int64 *)(qpace_urg_regs + v5);
  *v6 = a2 & 0xFFFFFFFFFFFFFF00LL;
  v6[1] = a1;
  for ( i = readl(qpace_urg_regs + v5 + 24); (~i & 0xF00000) == 0; i = readl(qpace_urg_regs + v5 + 24) )
    ;
  v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v8;
  if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
  {
    v13 = i;
    preempt_schedule();
    i = v13;
    if ( (v13 & 0xF00000) == 0 )
      return i & 0xFFFFF;
LABEL_6:
    ++*(_DWORD *)(StatusReg + 16);
    v9 = *(_DWORD *)(StatusReg + 40);
    v10 = (int)(v9 << 12);
    writel((unsigned int)a2 & 0xFFFFFF00, qpace_urg_regs + v10);
    writel(HIDWORD(a2), qpace_urg_regs + v10 + 4);
    writel((unsigned int)a1, qpace_urg_regs + v10 + 8);
    writel(HIDWORD(a1), qpace_urg_regs + v10 + 12);
    for ( i = readl(qpace_urg_regs + v10 + 24); (~i & 0xF00000) == 0; i = readl(qpace_urg_regs + v10 + 24) )
      ;
    v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v11;
    if ( v11 && *(_QWORD *)(StatusReg + 16) )
    {
      if ( ((i >> 20) & 0xF) == 0 )
        return i & 0xFFFFF;
    }
    else
    {
      v14 = i;
      preempt_schedule();
      i = v14;
      if ( ((v14 >> 20) & 0xF) == 0 )
        return i & 0xFFFFF;
    }
    printk(&unk_7D84, "qpace_urgent_compress", v9);
    return 4294967274LL;
  }
  if ( (i & 0xF00000) != 0 )
    goto LABEL_6;
  return i & 0xFFFFF;
}
