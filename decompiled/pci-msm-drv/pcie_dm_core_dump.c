__int64 __fastcall pcie_dm_core_dump(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x10
  unsigned __int64 v5; // x20
  __int64 v6; // x24
  int v7; // w25
  int v8; // w26
  int v9; // w27
  int v10; // w28
  int v11; // w21
  int v12; // w22
  int v13; // w23
  int v14; // w0
  unsigned __int64 v15; // [xsp+30h] [xbp-10h]
  int v16; // [xsp+3Ch] [xbp-4h]

  v1 = result;
  if ( result )
    result = ipc_log_string(
               *(_QWORD *)(result + 1712),
               "DUMP:%s: PCIe: RC%d DBI/dm_core register dump\n",
               "pcie_dm_core_dump",
               *(_DWORD *)(result + 1348));
  v2 = **(_QWORD **)(v1 + 408);
  v3 = *(_QWORD *)(*(_QWORD *)(v1 + 408) + 8LL) + 1LL;
  v4 = v3 - v2;
  if ( (unsigned __int64)(v3 - v2) >= 0x1000 )
    v4 = 4096;
  v15 = v4;
  if ( v3 != v2 )
  {
    v5 = 0;
    do
    {
      if ( v1 )
      {
        v6 = *(_QWORD *)(v1 + 1712);
        v16 = *(_DWORD *)(v1 + 1348);
        v7 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 904) + v5));
        v8 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 904) + v5 + 4));
        v9 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 904) + v5 + 8));
        v10 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 904) + v5 + 12));
        v11 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 904) + v5 + 16));
        v12 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 904) + v5 + 20));
        v13 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 904) + v5 + 24));
        v14 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 904) + v5 + 28));
        result = ipc_log_string(
                   v6,
                   "DUMP:%s: RC%d: 0x%04x %08x %08x %08x %08x %08x %08x %08x %08x\n",
                   "pcie_dm_core_dump",
                   v16,
                   v5,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   v13,
                   v14);
      }
      v5 += 32LL;
    }
    while ( v15 > v5 );
  }
  return result;
}
