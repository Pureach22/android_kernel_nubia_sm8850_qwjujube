__int64 __fastcall msm_pcie_clk_dump(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w8
  __int64 *v4; // x20
  unsigned int i; // w21
  unsigned int v6; // w8
  __int64 *v7; // x20
  unsigned int j; // w21

  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "ERR:%s: PCIe: RC%d: Dump PCIe clocks\n",
      "msm_pcie_clk_dump",
      *(_DWORD *)(a1 + 1348));
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: Dump PCIe clocks\n",
      "msm_pcie_clk_dump",
      *(_DWORD *)(a1 + 1348));
  }
  result = printk(&unk_22517);
  v3 = *(_DWORD *)(a1 + 856);
  if ( v3 )
  {
    v4 = *(__int64 **)(a1 + 864);
    for ( i = 0; i < v3; ++i )
    {
      result = *v4;
      if ( *v4 )
      {
        result = qcom_clk_dump(result, 0, 0);
        v3 = *(_DWORD *)(a1 + 856);
      }
      v4 += 3;
    }
  }
  v6 = *(_DWORD *)(a1 + 840);
  if ( v6 )
  {
    v7 = *(__int64 **)(a1 + 848);
    for ( j = 0; j < v6; ++j )
    {
      result = *v7;
      if ( *v7 )
      {
        result = qcom_clk_dump(result, 0, 0);
        v6 = *(_DWORD *)(a1 + 840);
      }
      v7 += 3;
    }
  }
  return result;
}
