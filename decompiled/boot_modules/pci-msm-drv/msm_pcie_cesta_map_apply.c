__int64 __fastcall msm_pcie_cesta_map_apply(__int64 a1, unsigned int a2)
{
  __int64 v4; // x21
  const char *v5; // x0
  __int64 v6; // x21
  const char *v7; // x0
  unsigned __int64 v8; // x22
  char *v9; // x24
  const char *v10; // x20
  unsigned int v11; // w0
  unsigned int v12; // w20
  unsigned int v13; // w21
  unsigned int v14; // w0
  int v15; // w0
  __int64 v16; // x20
  const char *v17; // x0
  __int64 v18; // x20
  const char *v19; // x0

  _ReadStatusReg(SP_EL0);
  if ( !*(_QWORD *)(a1 + 3128) )
    goto LABEL_20;
  if ( a1 )
  {
    v4 = *(_QWORD *)(a1 + 1704);
    v5 = (const char *)msm_pcie_cesta_curr_perf_ol(a1);
    ipc_log_string(v4, "DBG1:%s: Current perf ol is %s\n", "msm_pcie_cesta_map_apply", v5);
    v6 = *(_QWORD *)(a1 + 1696);
    v7 = (const char *)msm_pcie_cesta_curr_perf_ol(a1);
    ipc_log_string(v6, "%s: Current perf ol is %s\n", "msm_pcie_cesta_map_apply", v7);
    if ( a2 > 3 )
      goto LABEL_22;
    v8 = a2;
    if ( ((8LL * a2) | 4uLL) > 0x18 )
      goto LABEL_22;
    v9 = (char *)&msm_pcie_cesta_map + 8 * a2;
    v10 = msm_pcie_cesta_states[a2];
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: Setting the scenario to %s and perf_idx %d\n",
      "msm_pcie_cesta_map_apply",
      msm_pcie_cesta_states[v8],
      *((_DWORD *)v9 + 1));
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: Setting the scenario to %s and perf_idx %d\n",
      "msm_pcie_cesta_map_apply",
      v10,
      *((_DWORD *)v9 + 1));
  }
  else
  {
    v8 = a2;
  }
  if ( v8 > 2 )
    goto LABEL_22;
  v11 = crm_write_perf_ol(*(_QWORD *)(a1 + 3120), 0);
  if ( v11 )
  {
    v12 = v11;
    v13 = 0;
    if ( !a1 )
      goto LABEL_21;
    goto LABEL_14;
  }
  if ( ((8 * v8) | 4) > 0x18 )
LABEL_22:
    __break(1u);
  v14 = crm_write_perf_ol(*(_QWORD *)(a1 + 3120), 0);
  if ( !v14 )
  {
    v15 = crm_write_pwr_states(*(_QWORD *)(a1 + 3120), *(unsigned int *)(a1 + 1348));
    if ( v15 )
    {
      v12 = v15;
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "DBG1:%s: PCIe: RC%d: pwr_st %d pwr_states %d\n",
          "msm_pcie_cesta_map_apply",
          *(_DWORD *)(a1 + 1348),
          2,
          v15);
        ipc_log_string(
          *(_QWORD *)(a1 + 1696),
          "%s: PCIe: RC%d: pwr_st %d pwr_states %d\n",
          "msm_pcie_cesta_map_apply",
          *(unsigned int *)(a1 + 1348),
          2,
          v12);
      }
      goto LABEL_21;
    }
    if ( a1 )
    {
      v16 = *(_QWORD *)(a1 + 1704);
      v17 = (const char *)msm_pcie_cesta_curr_perf_ol(a1);
      ipc_log_string(v16, "DBG1:%s: New perf ol is %s\n", "msm_pcie_cesta_map_apply", v17);
      v18 = *(_QWORD *)(a1 + 1696);
      v19 = (const char *)msm_pcie_cesta_curr_perf_ol(a1);
      ipc_log_string(v18, "%s: New perf ol is %s\n", "msm_pcie_cesta_map_apply", v19);
    }
LABEL_20:
    v12 = 0;
    goto LABEL_21;
  }
  v12 = v14;
  v13 = 1;
  if ( a1 )
  {
LABEL_14:
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: PCIe: RC%d: pwr_st %d perf_ol %d\n",
      "msm_pcie_cesta_map_apply",
      *(_DWORD *)(a1 + 1348),
      v13,
      v12);
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: pwr_st %d perf_ol %d\n",
      "msm_pcie_cesta_map_apply",
      *(unsigned int *)(a1 + 1348),
      v13,
      v12);
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v12;
}
