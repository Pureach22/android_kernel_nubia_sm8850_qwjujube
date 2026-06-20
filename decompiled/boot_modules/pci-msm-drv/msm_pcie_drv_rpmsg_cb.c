__int64 __fastcall msm_pcie_drv_rpmsg_cb(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x24
  unsigned int v4; // w20
  __int64 v6; // x23
  __int64 v8; // x1
  __int64 v9; // x22
  __int64 v10; // x26
  int v11; // w4
  int v12; // w4
  unsigned int v13; // w21
  int v14; // w5
  int v15; // w4
  void *v17; // x0

  if ( !a3 )
    return 0;
  v3 = *(_QWORD *)(a1 + 152);
  v4 = a3;
  v6 = 0;
  while ( 1 )
  {
    if ( v4 <= 0x17 )
    {
      printk(&unk_2B701);
      return 4294967274LL;
    }
    v8 = *(unsigned int *)(a2 + v6 + 12);
    if ( (unsigned int)v8 >= 5 )
    {
      printk(&unk_25A1F);
      return 4294967274LL;
    }
    v9 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 8 * v8);
    v10 = *(_QWORD *)(v9 + 1792);
    if ( !v10 )
      break;
    v11 = *(unsigned __int16 *)(a2 + v6 + 4);
    if ( v11 != 10 )
    {
      if ( v9 )
      {
        ipc_log_string(
          *(_QWORD *)(v9 + 1704),
          "ERR:%s: PCIe: RC%d: DRV: unsupported command: 0x%x\n",
          "msm_pcie_drv_rpmsg_cb",
          *(_DWORD *)(v9 + 1348),
          v11);
        ipc_log_string(
          *(_QWORD *)(v9 + 1696),
          "%s: PCIe: RC%d: DRV: unsupported command: 0x%x\n",
          "msm_pcie_drv_rpmsg_cb",
          *(_DWORD *)(v9 + 1348),
          *(unsigned __int16 *)(a2 + v6 + 4));
      }
      v17 = &unk_2F289;
LABEL_25:
      printk(v17);
      return 4294967274LL;
    }
    v12 = *(unsigned __int16 *)(a2 + v6 + 10);
    if ( v12 != 4 )
    {
      if ( v9 )
      {
        ipc_log_string(
          *(_QWORD *)(v9 + 1704),
          "ERR:%s: PCIe: RC%d: DRV: invalid payload size: %d\n",
          "msm_pcie_drv_rpmsg_cb",
          *(_DWORD *)(v9 + 1348),
          v12);
        ipc_log_string(
          *(_QWORD *)(v9 + 1696),
          "%s: PCIe: RC%d: DRV: invalid payload size: %d\n",
          "msm_pcie_drv_rpmsg_cb",
          *(_DWORD *)(v9 + 1348),
          *(unsigned __int16 *)(a2 + v6 + 10));
      }
      v17 = &unk_2CBB4;
      goto LABEL_25;
    }
    v13 = v4 - 24;
    if ( v4 - 24 <= 3 )
    {
      if ( v9 )
      {
        ipc_log_string(
          *(_QWORD *)(v9 + 1704),
          "ERR:%s: PCIe: RC%d: DRV: invalid status length: %d\n",
          "msm_pcie_drv_rpmsg_cb",
          *(_DWORD *)(v9 + 1348),
          v13);
        ipc_log_string(
          *(_QWORD *)(v9 + 1696),
          "%s: PCIe: RC%d: DRV: invalid status length: %d\n",
          "msm_pcie_drv_rpmsg_cb",
          *(_DWORD *)(v9 + 1348),
          v13);
      }
      printk(&unk_2C4E1);
      return 4294967274LL;
    }
    v14 = *(unsigned __int16 *)(v10 + 250);
    v15 = *(unsigned __int16 *)(a2 + v6 + 8);
    if ( v15 != v14 )
    {
      if ( v9 )
      {
        ipc_log_string(
          *(_QWORD *)(v9 + 1704),
          "ERR:%s: PCIe: RC%d: DRV: incorrect reply seq: %d: expected seq: %d\n",
          "msm_pcie_drv_rpmsg_cb",
          *(_DWORD *)(v9 + 1348),
          v15,
          v14);
        ipc_log_string(
          *(_QWORD *)(v9 + 1696),
          "%s: PCIe: RC%d: DRV: incorrect reply seq: %d: expected seq: %d\n",
          "msm_pcie_drv_rpmsg_cb",
          *(_DWORD *)(v9 + 1348),
          *(unsigned __int16 *)(a2 + v6 + 8),
          *(unsigned __int16 *)(v10 + 250));
      }
      printk(&unk_237A5);
      return 4294967274LL;
    }
    if ( *(_DWORD *)(a2 + v6 + 24) )
    {
      if ( v9 )
      {
        ipc_log_string(
          *(_QWORD *)(v9 + 1704),
          "ERR:%s: PCIe: RC%d: DRV: invalid status\n",
          "msm_pcie_drv_rpmsg_cb",
          *(_DWORD *)(v9 + 1348));
        ipc_log_string(
          *(_QWORD *)(v9 + 1696),
          "%s: PCIe: RC%d: DRV: invalid status\n",
          "msm_pcie_drv_rpmsg_cb",
          *(_DWORD *)(v9 + 1348));
      }
      printk(&unk_2B729);
      return 4294967274LL;
    }
    complete(v10 + 256);
    v6 += 28;
    v4 -= 28;
    if ( a3 == (_DWORD)v6 )
      return 0;
  }
  if ( v9 )
  {
    ipc_log_string(
      *(_QWORD *)(v9 + 1704),
      "ERR:%s: PCIe: RC%d: DRV: no device info found\n",
      "msm_pcie_drv_rpmsg_cb",
      *(_DWORD *)(v9 + 1348));
    ipc_log_string(
      *(_QWORD *)(v9 + 1696),
      "%s: PCIe: RC%d: DRV: no device info found\n",
      "msm_pcie_drv_rpmsg_cb",
      *(_DWORD *)(v9 + 1348));
  }
  printk(&unk_30172);
  return 4294967277LL;
}
