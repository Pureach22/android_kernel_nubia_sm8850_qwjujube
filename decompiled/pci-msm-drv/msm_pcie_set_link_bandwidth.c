__int64 __fastcall msm_pcie_set_link_bandwidth(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  int v4; // w21
  __int64 v5; // x19
  unsigned int v6; // w8
  __int64 v8; // x20
  int v9; // w25
  int v10; // w0
  unsigned int v11; // w21
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  while ( !*(_BYTE *)(a1 + 108) || (*(_WORD *)(a1 + 114) & 0xF0) != 0x40 )
  {
    if ( (*(_BYTE *)(a1 + 2851) & 0x80) != 0 )
      a1 = *(_QWORD *)(a1 + 3288);
    v2 = *(_QWORD *)(a1 + 16);
    if ( *(_QWORD *)(v2 + 16) )
    {
      a1 = *(_QWORD *)(v2 + 56);
      if ( a1 )
        continue;
    }
    result = 4294967277LL;
    goto LABEL_15;
  }
  v4 = (unsigned __int16)a2;
  v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 232LL) + 200LL);
  if ( *(_DWORD *)(v5 + 992) < (unsigned int)(unsigned __int16)a2
    || (v6 = *(_DWORD *)(v5 + 1244)) != 0 && v6 < (unsigned __int16)a2 )
  {
    if ( v5 )
    {
      ipc_log_string(
        *(_QWORD *)(v5 + 1704),
        "DBG1:%s: PCIe: RC%d: invalid target link speed: %d\n",
        "msm_pcie_set_link_bandwidth",
        *(_DWORD *)(v5 + 1348),
        (unsigned __int16)a2);
      ipc_log_string(
        *(_QWORD *)(v5 + 1696),
        "%s: PCIe: RC%d: invalid target link speed: %d\n",
        "msm_pcie_set_link_bandwidth",
        *(_DWORD *)(v5 + 1348),
        v4);
    }
    goto LABEL_14;
  }
  v8 = a1;
  pcie_capability_read_word();
  if ( (_WORD)a2 )
  {
    if ( v5 )
    {
      ipc_log_string(
        *(_QWORD *)(v5 + 1704),
        "DBG1:%s: PCIe: RC%d: switching from Gen%d to Gen%d\n",
        "msm_pcie_set_link_bandwidth",
        *(_DWORD *)(v5 + 1348),
        0,
        v4);
      ipc_log_string(
        *(_QWORD *)(v5 + 1696),
        "%s: PCIe: RC%d: switching from Gen%d to Gen%d\n",
        "msm_pcie_set_link_bandwidth",
        *(_DWORD *)(v5 + 1348),
        0,
        v4);
      ipc_log_string(
        *(_QWORD *)(v5 + 1704),
        "DBG1:%s: PCIe: RC%d: current link width:%d max link width:%d\n",
        "msm_pcie_set_link_bandwidth",
        *(_DWORD *)(v5 + 1348),
        0,
        *(_DWORD *)(v5 + 996));
      ipc_log_string(
        *(_QWORD *)(v5 + 1696),
        "%s: PCIe: RC%d: current link width:%d max link width:%d\n",
        "msm_pcie_set_link_bandwidth",
        *(_DWORD *)(v5 + 1348),
        0,
        *(_DWORD *)(v5 + 996));
    }
    v9 = *(unsigned __int8 *)(v8 + 108);
    v12 = 0;
    pci_read_config_dword(v8, (unsigned int)(v9 + 48), &v12);
    v12 = v12 & 0xFFFFFFF0 | v4;
    pci_write_config_dword(v8, (unsigned int)(v9 + 48));
    result = msm_pcie_prevent_l1(v8);
    if ( !(_DWORD)result )
    {
      msm_pcie_config_l0s_disable_all(v5, *(_QWORD *)(v8 + 16));
      msm_pcie_poll_for_l0_from_l0s(v5);
      msm_pcie_scale_link_bandwidth(v5, a2);
      v10 = msm_pcie_link_retrain(v5, v8);
      if ( !v10 )
      {
        if ( *(_DWORD *)(v5 + 1252) == v4 )
        {
          if ( v5 )
          {
            ipc_log_string(
              *(_QWORD *)(v5 + 1704),
              "DBG1:%s: PCIe: RC%d: successfully switched link bandwidth\n",
              "msm_pcie_set_link_bandwidth",
              *(_DWORD *)(v5 + 1348));
            ipc_log_string(
              *(_QWORD *)(v5 + 1696),
              "%s: PCIe: RC%d: successfully switched link bandwidth\n",
              "msm_pcie_set_link_bandwidth",
              *(_DWORD *)(v5 + 1348));
          }
          v10 = 0;
        }
        else
        {
          if ( v5 )
          {
            ipc_log_string(
              *(_QWORD *)(v5 + 1704),
              "ERR:%s: PCIe: RC%d: failed to switch bandwidth: target speed: %d\n",
              "msm_pcie_set_link_bandwidth",
              *(_DWORD *)(v5 + 1348),
              v4);
            ipc_log_string(
              *(_QWORD *)(v5 + 1696),
              "%s: PCIe: RC%d: failed to switch bandwidth: target speed: %d\n",
              "msm_pcie_set_link_bandwidth",
              *(_DWORD *)(v5 + 1348),
              v4);
          }
          printk(&unk_27D7E);
          v10 = -5;
        }
      }
      v11 = v10;
      if ( *(_BYTE *)(v5 + 1217) == 1 )
        pci_walk_bus(*(_QWORD *)(*(_QWORD *)(v5 + 8) + 16LL), msm_pcie_config_l0s_enable, v5);
      msm_pcie_allow_l1(v8);
      result = v11;
    }
  }
  else
  {
    result = 0;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
