__int64 __fastcall pcie_pdc_cfg_irq(int a1, int a2, char a3)
{
  int v3; // w9
  int v4; // w22
  int v5; // w11
  _DWORD *v6; // x10
  int v8; // w9
  unsigned int v9; // w9
  __int64 v10; // x24
  unsigned int v11; // w10
  int v12; // w23
  _DWORD *v13; // t2
  unsigned int v14; // w19
  unsigned int v15; // w20
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x22

  if ( !d )
    return 4294967277LL;
  v3 = *(_DWORD *)(d + 8);
  if ( !v3 )
    return 4294967274LL;
  v4 = 0;
  v5 = 0;
  while ( 1 )
  {
    v6 = (_DWORD *)(*(_QWORD *)d + 12LL * v5);
    if ( *v6 == a1 )
      break;
    ++v5;
    v4 += 20;
    if ( v3 == v5 )
      return 4294967274LL;
  }
  v8 = a2 - 1;
  if ( (unsigned int)(a2 - 1) >= 8 || ((0x8Fu >> v8) & 1) == 0 )
  {
    __break(0x800u);
    return 4294967274LL;
  }
  v9 = dword_6A30[v8];
  v10 = *(unsigned int *)(d + 12);
  v13 = v6 + 1;
  v11 = v6[1];
  v12 = v13[1];
  if ( (a3 & 1) != 0 )
    v14 = v9 | 8;
  else
    v14 = v9;
  if ( (a3 & 1) != 0 )
    v15 = v11;
  else
    v15 = 0;
  v16 = raw_spin_lock_irqsave(&pdc_lock);
  v17 = pcie_pdc_base + v10 + v4;
  v18 = v16;
  writel_relaxed(v15, v17);
  writel_relaxed(v14, pcie_pdc_base + (unsigned int)(4 * v12) + 272);
  raw_spin_unlock_irqrestore(&pdc_lock, v18);
  return 0;
}
