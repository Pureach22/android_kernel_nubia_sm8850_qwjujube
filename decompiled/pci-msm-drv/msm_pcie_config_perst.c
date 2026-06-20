__int64 __fastcall msm_pcie_config_perst(__int64 a1, char a2)
{
  __int64 v4; // x0
  unsigned int v5; // w19
  __int64 v6; // x0

  if ( *(_BYTE *)(a1 + 3156) == 1 )
    return printk(&unk_27E32);
  if ( (a2 & 1) != 0 )
  {
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "INFO:%s: PCIe: RC%d: assert PERST\n",
        "msm_pcie_config_perst",
        *(_DWORD *)(a1 + 1348));
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d: assert PERST\n",
        "msm_pcie_config_perst",
        *(_DWORD *)(a1 + 1348));
    }
    printk(&unk_2B2E9);
    v4 = *(unsigned int *)(a1 + 264);
    v5 = *(_DWORD *)(a1 + 272);
  }
  else
  {
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "INFO:%s: PCIe: RC%d: de-assert PERST\n",
        "msm_pcie_config_perst",
        *(_DWORD *)(a1 + 1348));
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d: de-assert PERST\n",
        "msm_pcie_config_perst",
        *(_DWORD *)(a1 + 1348));
    }
    printk(&unk_2FABA);
    v4 = *(unsigned int *)(a1 + 264);
    v5 = 1 - *(_DWORD *)(a1 + 272);
  }
  v6 = gpio_to_desc(v4);
  return gpiod_set_raw_value(v6, v5);
}
