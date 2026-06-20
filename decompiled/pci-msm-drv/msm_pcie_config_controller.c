__int64 __fastcall msm_pcie_config_controller(__int64 a1)
{
  __int64 v2; // x21
  int v3; // w0
  __int64 v4; // x20
  int v5; // w21
  unsigned int *v6; // x0
  unsigned int v7; // w0
  __int64 v8; // x20
  int v9; // w0
  unsigned int v10; // w0
  __int64 v11; // x20
  __int64 result; // x0
  int v13; // w20
  __int64 v14; // x21
  int v15; // w0
  __int64 v16; // x20
  int v17; // w0
  __int64 v18; // x20
  int v19; // w0
  __int64 v20; // x20
  int v21; // w0
  __int64 v22; // x20
  int v23; // w0

  if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d\n", "msm_pcie_config_controller", *(_DWORD *)(a1 + 1348));
    ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d\n", "msm_pcie_config_controller", *(_DWORD *)(a1 + 1348));
    v2 = *(_QWORD *)(a1 + 1696);
    v3 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 1804LL));
    ipc_log_string(v2, "DBG2:%s: Original PCIE20_ACK_F_ASPM_CTRL_REG:0x%x\n", "msm_pcie_config_controller", v3);
  }
  v4 = *(_QWORD *)(a1 + 904);
  v5 = *(_DWORD *)(a1 + 1264);
  v6 = (unsigned int *)(v4 + 1804);
  if ( v5 )
    v7 = readl_relaxed_0(v6) & 0xFFFF00FF | (v5 << 8);
  else
    v7 = readl_relaxed_0(v6) | 0x8000;
  writel_relaxed_0(v7, (unsigned int *)(v4 + 1804));
  readl_relaxed_0((unsigned int *)(v4 + 1804));
  if ( a1 )
  {
    v8 = *(_QWORD *)(a1 + 1696);
    v9 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 1804LL));
    ipc_log_string(v8, "DBG2:%s: Updated PCIE20_ACK_F_ASPM_CTRL_REG:0x%x\n", "msm_pcie_config_controller", v9);
  }
  v10 = *(_DWORD *)(a1 + 1324);
  if ( v10 )
  {
    v11 = *(_QWORD *)(a1 + 904);
    writel_relaxed_0(v10, (unsigned int *)(v11 + 2880));
    readl_relaxed_0((unsigned int *)(v11 + 2880));
  }
  result = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 2880LL));
  v13 = *(_DWORD *)(a1 + 1304);
  *(_DWORD *)(a1 + 1324) = result;
  if ( v13 && *(_BYTE *)(a1 + 1664) == 1 )
  {
    v14 = *(_QWORD *)(a1 + 904);
    v15 = readl_relaxed_0((unsigned int *)(v14 + 152));
    writel_relaxed_0(v15 & 0xFFFFFFF0 | v13, (unsigned int *)(v14 + 152));
    result = readl_relaxed_0((unsigned int *)(v14 + 152));
  }
  if ( *(_BYTE *)(a1 + 1235) == 1 )
  {
    v16 = *(_QWORD *)(a1 + 904);
    v17 = readl_relaxed_0((unsigned int *)(v16 + 60));
    writel_relaxed_0(v17 | 0x30000, (unsigned int *)(v16 + 60));
    readl_relaxed_0((unsigned int *)(v16 + 60));
    v18 = *(_QWORD *)(a1 + 904);
    v19 = readl_relaxed_0((unsigned int *)(v18 + 120));
    writel_relaxed_0(v19 | 0xF, (unsigned int *)(v18 + 120));
    result = readl_relaxed_0((unsigned int *)(v18 + 120));
    if ( a1 )
    {
      v20 = *(_QWORD *)(a1 + 1704);
      v21 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 120LL));
      ipc_log_string(v20, "DBG1:%s: RC's PCIE20_CAP_DEVCTRLSTATUS:0x%x\n", "msm_pcie_config_controller", v21);
      v22 = *(_QWORD *)(a1 + 1696);
      v23 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 120LL));
      return ipc_log_string(v22, "%s: RC's PCIE20_CAP_DEVCTRLSTATUS:0x%x\n", "msm_pcie_config_controller", v23);
    }
  }
  return result;
}
