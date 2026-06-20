__int64 __fastcall pcie_phy_dump(__int64 result)
{
  __int64 v1; // x19
  int i; // w20
  __int64 v3; // x24
  int v4; // w25
  int v5; // w26
  int v6; // w27
  int v7; // w28
  int v8; // w21
  int v9; // w22
  int v10; // w23
  int v11; // w0
  int v12; // [xsp+28h] [xbp-8h]
  int v13; // [xsp+2Ch] [xbp-4h]

  v12 = *(_DWORD *)(*(_QWORD *)(result + 384) + 8LL) - **(_DWORD **)(result + 384) + 1;
  if ( v12 >= 1 )
  {
    v1 = result;
    for ( i = 0; i < v12; i += 32 )
    {
      if ( v1 )
      {
        v3 = *(_QWORD *)(v1 + 1712);
        v13 = *(_DWORD *)(v1 + 1348);
        v4 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 880) + i));
        v5 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 880) + i + 4));
        v6 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 880) + i + 8));
        v7 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 880) + i + 12));
        v8 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 880) + i + 16));
        v9 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 880) + i + 20));
        v10 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 880) + i + 24));
        v11 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 880) + i + 28));
        result = ipc_log_string(
                   v3,
                   "DUMP:%s: PCIe PHY of RC%d: 0x%04x %08x %08x %08x %08x %08x %08x %08x %08x\n",
                   "pcie_phy_dump",
                   v13,
                   i,
                   v4,
                   v5,
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11);
      }
    }
  }
  return result;
}
