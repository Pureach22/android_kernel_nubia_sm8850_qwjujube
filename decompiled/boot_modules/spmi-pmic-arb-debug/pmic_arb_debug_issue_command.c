__int64 __fastcall pmic_arb_debug_issue_command(__int64 a1, unsigned __int8 a2, int a3, __int16 a4, __int64 a5)
{
  int v5; // w25
  unsigned __int8 *v7; // x24
  _QWORD *v9; // x23
  unsigned int v10; // w8
  unsigned int v11; // w2
  unsigned int v13; // w22
  _BYTE *v14; // x9
  int v15; // w8
  __int64 v16; // x8
  int v17; // w22
  __int64 v18; // x21
  unsigned int v19; // w20

  v5 = a5 + 255;
  if ( (((_DWORD)a5 + 255) & 0xF8) != 0 )
  {
    dev_err(a1, "pmic-arb supports 1 to %d bytes per transaction, but %zu requested\n", 8, a5);
    return 4294967274LL;
  }
  v7 = *(unsigned __int8 **)(a1 + 152);
  v9 = *(_QWORD **)v7;
  v10 = (unsigned __int8)a3;
  v11 = (unsigned __int8)~(-1 << **(_BYTE **)(*(_QWORD *)v7 + 24LL));
  if ( v11 < v10 )
  {
    dev_err(a1, "pmic-arb supports sid 0 to %u, but %u requested\n", v11, v10);
    return 4294967274LL;
  }
  v13 = HIBYTE(a4);
  writel_relaxed((unsigned __int8)a4, *v9 + 12LL);
  writel_relaxed(v13, *v9 + 8LL);
  v14 = (_BYTE *)v9[3];
  v15 = (v5 << *v14) | a3;
  if ( v14[2] == 4 )
    v15 |= v7[8] << v14[3];
  writel_relaxed((unsigned __int8)v15, *v9 + 4LL);
  v16 = v9[3];
  if ( *(_BYTE *)(v16 + 2) == 96 )
    writel_relaxed(v7[8] << *(_BYTE *)(v16 + 3), *v9 + 96LL);
  writel_relaxed(2 * (unsigned int)a2, *v9);
  v17 = -100;
  v18 = **(_QWORD **)(a1 + 152);
  while ( 1 )
  {
    v19 = readl_relaxed((unsigned int *)(*(_QWORD *)v18 + 20LL));
    if ( (v19 & 1) != 0 )
      break;
    _const_udelay(4295);
    if ( __CFADD__(v17++, 1) )
    {
      dev_err(a1, "%s: timeout, status 0x%x\n", "pmic_arb_debug_wait_for_done", v19);
      return 4294967186LL;
    }
  }
  if ( (v19 & 4) != 0 )
  {
    dev_err(a1, "%s: transaction denied (0x%x)\n", "pmic_arb_debug_wait_for_done", v19);
    return 0xFFFFFFFFLL;
  }
  if ( (v19 & 2) != 0 )
  {
    dev_err(a1, "%s: transaction failed (0x%x)\n", "pmic_arb_debug_wait_for_done", v19);
    return 4294967291LL;
  }
  if ( (v19 & 8) != 0 )
  {
    dev_err(a1, "%s: transaction dropped (0x%x)\n", "pmic_arb_debug_wait_for_done", v19);
    return 4294967291LL;
  }
  return 0;
}
