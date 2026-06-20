__int64 __fastcall pcie_parf_dump(__int64 a1)
{
  unsigned int v2; // w20
  int v3; // w26
  unsigned int v4; // w27
  unsigned int *v5; // x23
  int v6; // w0
  __int64 v7; // x23
  int v8; // w24
  int v9; // w25
  int v10; // w0
  unsigned int *v11; // x21
  __int64 result; // x0
  unsigned __int64 v13; // x22
  __int64 v14; // x23
  int v15; // w24
  int v16; // w25
  int v17; // w26
  int v18; // w27
  int v19; // w28
  int v20; // w20
  int v21; // w21
  int v22; // w0
  int v23; // [xsp+2Ch] [xbp-4h]

  if ( a1 )
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DUMP:%s: PCIe: RC%d PARF testbus\n",
      "pcie_parf_dump",
      *(_DWORD *)(a1 + 1348));
  v2 = readl_relaxed_0(*(unsigned int **)(a1 + 872));
  v3 = 0;
  v4 = 0;
  do
  {
    v5 = *(unsigned int **)(a1 + 872);
    v6 = readl_relaxed_0(v5);
    writel_relaxed_0(v6 & 0xFF00FFFF | v3, v5);
    readl_relaxed_0(v5);
    if ( a1 )
    {
      v7 = *(_QWORD *)(a1 + 1712);
      v8 = *(_DWORD *)(a1 + 1348);
      v9 = readl_relaxed_0(*(unsigned int **)(a1 + 872));
      v10 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + 228LL));
      ipc_log_string(v7, "DUMP:%s: RC%d: PARF_SYS_CTRL: 0%08x PARF_TEST_BUS: 0%08x\n", "pcie_parf_dump", v8, v9, v10);
    }
    ++v4;
    v3 += 0x10000;
  }
  while ( v4 <= *(_DWORD *)(a1 + 1616) );
  v11 = *(unsigned int **)(a1 + 872);
  writel_relaxed_0(v2, v11);
  result = readl_relaxed_0(v11);
  if ( a1 )
    result = ipc_log_string(
               *(_QWORD *)(a1 + 1712),
               "DUMP:%s: PCIe: RC%d PARF register dump\n",
               "pcie_parf_dump",
               *(_DWORD *)(a1 + 1348));
  v13 = -32;
  do
  {
    if ( a1 )
    {
      v14 = *(_QWORD *)(a1 + 1712);
      v23 = *(_DWORD *)(a1 + 1348);
      v15 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + v13 + 32));
      v16 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + v13 + 36));
      v17 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + v13 + 40));
      v18 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + v13 + 44));
      v19 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + v13 + 48));
      v20 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + v13 + 52));
      v21 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + v13 + 56));
      v22 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + v13 + 60));
      result = ipc_log_string(
                 v14,
                 "DUMP:%s: RC%d: 0x%04x %08x %08x %08x %08x %08x %08x %08x %08x\n",
                 "pcie_parf_dump",
                 v23,
                 (int)v13 + 32,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22);
    }
    v13 += 32LL;
  }
  while ( v13 >> 5 < 0xFF );
  return result;
}
