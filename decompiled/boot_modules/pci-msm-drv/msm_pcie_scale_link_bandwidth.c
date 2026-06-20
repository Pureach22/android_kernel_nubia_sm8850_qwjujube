__int64 __fastcall msm_pcie_scale_link_bandwidth(__int64 result, unsigned __int16 a2)
{
  __int64 v2; // x8
  int v3; // w20
  __int64 v4; // x19
  unsigned int v5; // w9
  int v6; // w20
  unsigned int *v7; // x20
  __int64 v8; // x8
  __int64 v9; // x8

  v2 = *(_QWORD *)(result + 984);
  if ( v2 )
  {
    v3 = a2;
    v4 = result;
    v5 = a2 - 1;
    if ( v5 >= *(_DWORD *)(result + 992) )
    {
      if ( result )
      {
        ipc_log_string(
          *(_QWORD *)(result + 1704),
          "ERR:%s: PCIe: RC%d: invalid target link speed: %d\n",
          "msm_pcie_scale_link_bandwidth",
          *(_DWORD *)(result + 1348),
          a2);
        ipc_log_string(
          *(_QWORD *)(v4 + 1696),
          "%s: PCIe: RC%d: invalid target link speed: %d\n",
          "msm_pcie_scale_link_bandwidth",
          *(_DWORD *)(v4 + 1348),
          v3);
      }
      return printk(&unk_2E12C);
    }
    else if ( *(_QWORD *)(result + 3128) )
    {
      if ( a2 + 1 != dword_4C0 )
      {
        dword_4BC = a2 + 1;
        dword_4C0 = a2 + 1;
        dword_4C8 = a2 + 1;
        result = msm_pcie_cesta_map_apply(result, 1);
        if ( (_DWORD)result )
        {
          v6 = result;
          if ( v4 )
          {
            ipc_log_string(
              *(_QWORD *)(v4 + 1704),
              "ERR:%s: Failed to move to D0 state %d\n",
              "msm_pcie_scale_link_bandwidth",
              result);
            ipc_log_string(
              *(_QWORD *)(v4 + 1696),
              "%s: Failed to move to D0 state %d\n",
              "msm_pcie_scale_link_bandwidth",
              v6);
          }
          return printk(&unk_2A141);
        }
      }
    }
    else
    {
      v7 = (unsigned int *)(v2 + 12LL * v5);
      v8 = *(_QWORD *)(result + 968);
      if ( v8 )
        regulator_set_voltage(*(_QWORD *)v8, *v7, *(unsigned int *)(v8 + 16));
      v9 = *(_QWORD *)(v4 + 976);
      if ( v9 )
        regulator_set_voltage(*(_QWORD *)v9, v7[1], *(unsigned int *)(v9 + 16));
      result = *(_QWORD *)(v4 + 1008);
      if ( result )
        return clk_set_rate(result, v7[2]);
    }
  }
  return result;
}
