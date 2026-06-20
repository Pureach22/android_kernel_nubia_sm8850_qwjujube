__int64 __fastcall msm_gpio_update_dual_edge_pos(_QWORD *a1, __int64 a2)
{
  int v4; // w23
  _QWORD *v5; // x24
  int v6; // w0
  unsigned __int64 v7; // x26
  int v8; // w21
  int v9; // w0
  int v10; // w0
  unsigned __int64 v11; // x27
  int v12; // w22
  __int64 result; // x0
  int v14; // w2
  int v15; // w3

  v4 = -101;
  v5 = a1 + 122;
  while ( 1 )
  {
    v6 = readl((unsigned int *)(v5[(*(_QWORD *)(a2 + 84) >> 5) & 3LL] + *(unsigned int *)(a2 + 64)));
    v7 = *(_QWORD *)(a2 + 84);
    v8 = v6;
    v9 = readl((unsigned int *)(v5[(v7 >> 5) & 3] + *(unsigned int *)(a2 + 68)));
    writel(
      v9 ^ (1 << (*(_QWORD *)(a2 + 92) >> 37)),
      (unsigned int *)(v5[(*(_QWORD *)(a2 + 84) >> 5) & 3LL] + *(unsigned int *)(a2 + 68)));
    v10 = readl((unsigned int *)(v5[(*(_QWORD *)(a2 + 84) >> 5) & 3LL] + *(unsigned int *)(a2 + 64)));
    v11 = *(_QWORD *)(a2 + 84);
    v12 = v10;
    result = readl((unsigned int *)(v5[(v11 >> 5) & 3] + *(unsigned int *)(a2 + 72)));
    if ( (_DWORD)result )
      break;
    v14 = v8 & (1 << (v7 >> 47));
    v15 = v12 & (1 << (v11 >> 47));
    if ( v14 == v15 )
      break;
    if ( __CFADD__(v4++, 1) )
      return dev_err(*a1, "dual-edge irq failed to stabilize, %#08x != %#08x\n", v14, v15);
  }
  return result;
}
