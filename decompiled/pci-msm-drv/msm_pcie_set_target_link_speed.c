__int64 __fastcall msm_pcie_set_target_link_speed(unsigned int a1, unsigned int a2, char a3)
{
  __int64 v3; // x21
  unsigned int v4; // w8
  unsigned int v5; // w9
  __int64 v8; // x0
  int v9; // w3
  int v10; // w4

  if ( a1 >= 5 )
  {
    printk(&unk_254F2);
    return 4294967274LL;
  }
  v3 = msm_pcie_dev[a1];
  if ( !v3 )
    return 4294966779LL;
  if ( (*(_BYTE *)(v3 + 1356) & 1) == 0 )
  {
    ipc_log_string(
      *(_QWORD *)(v3 + 1704),
      "DBG1:%s: PCIe: RC%d: has not been successfully probed yet\n",
      "msm_pcie_set_target_link_speed",
      *(_DWORD *)(v3 + 1348));
    ipc_log_string(
      *(_QWORD *)(v3 + 1696),
      "%s: PCIe: RC%d: has not been successfully probed yet\n",
      "msm_pcie_set_target_link_speed",
      *(_DWORD *)(v3 + 1348));
    return 4294966779LL;
  }
  v4 = *(_DWORD *)(v3 + 992);
  if ( v4 >= a2 && ((v5 = *(_DWORD *)(v3 + 1248)) == 0 || v5 >= a2 || (a3 & 1) != 0) )
  {
    v8 = *(_QWORD *)(v3 + 1704);
    v9 = *(_DWORD *)(v3 + 1348);
    if ( !((v5 == 0) | a3 & 1) )
      v4 = *(_DWORD *)(v3 + 1248);
    if ( a2 )
      v10 = a2;
    else
      v10 = v4;
    *(_DWORD *)(v3 + 1244) = v10;
    ipc_log_string(
      v8,
      "DBG1:%s: PCIe: RC%d: target_link_speed is now: 0x%x.\n",
      "msm_pcie_set_target_link_speed",
      v9,
      v10);
    ipc_log_string(
      *(_QWORD *)(v3 + 1696),
      "%s: PCIe: RC%d: target_link_speed is now: 0x%x.\n",
      "msm_pcie_set_target_link_speed",
      *(_DWORD *)(v3 + 1348),
      *(_DWORD *)(v3 + 1244));
    return 0;
  }
  else
  {
    ipc_log_string(
      *(_QWORD *)(v3 + 1704),
      "DBG1:%s: PCIe: RC%d: invalid target link speed: %d\n",
      "msm_pcie_set_target_link_speed",
      *(_DWORD *)(v3 + 1348),
      a2);
    ipc_log_string(
      *(_QWORD *)(v3 + 1696),
      "%s: PCIe: RC%d: invalid target link speed: %d\n",
      "msm_pcie_set_target_link_speed",
      *(_DWORD *)(v3 + 1348),
      a2);
    return 4294967274LL;
  }
}
