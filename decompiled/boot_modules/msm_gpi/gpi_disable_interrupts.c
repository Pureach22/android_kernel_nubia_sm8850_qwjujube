__int64 __fastcall gpi_disable_interrupts(__int64 a1)
{
  __int64 v1; // x24
  __int64 v3; // x23
  __int64 v4; // x25
  __int64 v5; // x26
  __int64 v6; // x27
  __int64 v7; // x22
  __int64 v8; // x21
  __int64 v9; // x20
  int v10; // w0
  __int64 v11; // x23
  int v12; // w0
  __int64 v13; // x23
  int v14; // w0
  __int64 v15; // x23
  int v16; // w0
  __int64 v17; // x23
  int v18; // w0
  __int64 v19; // x22
  int v20; // w0
  __int64 v21; // x21
  int v22; // w0
  __int64 v23; // x0
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 816);
  v3 = (unsigned int)((*(_DWORD *)a1 << 14) + 143496);
  v4 = (unsigned int)v3 | 0x30;
  v5 = (unsigned int)v3 | 0x10;
  v6 = (unsigned int)v3 | 0x14;
  v7 = (unsigned int)((*(_DWORD *)a1 << 14) + 143624);
  v8 = (unsigned int)((*(_DWORD *)a1 << 14) + 143648);
  v9 = (unsigned int)((*(_DWORD *)a1 << 14) + 143744);
  v10 = readl_relaxed((unsigned int *)(v1 + v3));
  writel_relaxed(v10 & 0xFFFFFF80, (unsigned int *)(v1 + v3));
  v11 = *(_QWORD *)(a1 + 816);
  v12 = readl_relaxed((unsigned int *)(v11 + v4));
  writel_relaxed(v12 & 0xFFFFFFFE, (unsigned int *)(v11 + v4));
  v13 = *(_QWORD *)(a1 + 816);
  v14 = readl_relaxed((unsigned int *)(v13 + v5));
  writel_relaxed(v14 & 0xFFFFFFFC, (unsigned int *)(v13 + v5));
  v15 = *(_QWORD *)(a1 + 816);
  v16 = readl_relaxed((unsigned int *)(v15 + v6));
  writel_relaxed(v16 & 0xFFFFFFFE, (unsigned int *)(v15 + v6));
  v17 = *(_QWORD *)(a1 + 816);
  v18 = readl_relaxed((unsigned int *)(v17 + v7));
  writel_relaxed(v18 & 0xFFFFFFF0, (unsigned int *)(v17 + v7));
  v19 = *(_QWORD *)(a1 + 816);
  v20 = readl_relaxed((unsigned int *)(v19 + v8));
  writel_relaxed(v20 & 0xFFFFFFF0, (unsigned int *)(v19 + v8));
  v21 = *(_QWORD *)(a1 + 816);
  v22 = readl_relaxed((unsigned int *)(v21 + v9));
  writel_relaxed(v22 & 0xFFFFFFFE, (unsigned int *)(v21 + v9));
  v23 = *(unsigned int *)(a1 + 808);
  *(_DWORD *)(a1 + 1052) = 0;
  result = free_irq(v23, a1);
  *(_BYTE *)(a1 + 940) = 0;
  return result;
}
