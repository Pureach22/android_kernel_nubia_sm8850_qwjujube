__int64 __fastcall msm_pcie_vreg_deinit(__int64 a1)
{
  __int64 i; // x24
  __int64 result; // x0
  __int64 v4; // x21
  __int64 v5; // x23
  const char *v6; // x26
  int v7; // w26

  if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: entry\n", "msm_pcie_vreg_deinit", *(_DWORD *)(a1 + 1348));
    ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: entry\n", "msm_pcie_vreg_deinit", *(_DWORD *)(a1 + 1348));
  }
  for ( i = 0; i != -192; i -= 32 )
  {
    v4 = a1 + i;
    result = *(_QWORD *)(a1 + i + 224);
    if ( result )
    {
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "DBG1:%s: Vreg %s is being disabled\n",
          "msm_pcie_vreg_deinit",
          *(const char **)(a1 + i + 232));
        ipc_log_string(
          *(_QWORD *)(a1 + 1696),
          "%s: Vreg %s is being disabled\n",
          "msm_pcie_vreg_deinit",
          *(const char **)(a1 + i + 232));
        result = *(_QWORD *)(v4 + 224);
      }
      regulator_disable(result);
      v5 = a1 + i;
      v6 = *(const char **)(a1 + i + 232);
      if ( !strcmp(v6, "vreg-cx") || (result = strcmp(v6, "vreg-mx"), !(_DWORD)result) )
      {
        if ( a1 )
        {
          ipc_log_string(
            *(_QWORD *)(a1 + 1704),
            "DBG1:%s: RC%d: Removing %s vote.\n",
            "msm_pcie_vreg_deinit",
            *(_DWORD *)(a1 + 1348),
            v6);
          ipc_log_string(
            *(_QWORD *)(a1 + 1696),
            "%s: RC%d: Removing %s vote.\n",
            "msm_pcie_vreg_deinit",
            *(_DWORD *)(a1 + 1348),
            *(const char **)(v5 + 232));
        }
        result = regulator_set_voltage(*(_QWORD *)(v4 + 224), 16, 0xFFFF);
      }
      if ( *(_DWORD *)(a1 + i + 248) )
      {
        result = regulator_set_load(*(_QWORD *)(v4 + 224));
        if ( (result & 0x80000000) != 0 )
        {
          v7 = result;
          if ( a1 )
          {
            ipc_log_string(
              *(_QWORD *)(a1 + 1704),
              "ERR:%s: PCIe: RC%d can't set mode for %s: %d\n",
              "msm_pcie_vreg_deinit",
              *(_DWORD *)(a1 + 1348),
              *(const char **)(v5 + 232),
              result);
            ipc_log_string(
              *(_QWORD *)(a1 + 1696),
              "%s: PCIe: RC%d can't set mode for %s: %d\n",
              "msm_pcie_vreg_deinit",
              *(_DWORD *)(a1 + 1348),
              *(const char **)(v5 + 232),
              v7);
          }
          result = printk(&unk_23B98);
        }
      }
    }
  }
  if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: exit\n", "msm_pcie_vreg_deinit", *(_DWORD *)(a1 + 1348));
    return ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: exit\n", "msm_pcie_vreg_deinit", *(_DWORD *)(a1 + 1348));
  }
  return result;
}
