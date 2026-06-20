__int64 __fastcall msm_pcie_ssr_notifier(__int64 a1, __int64 a2)
{
  __int64 *v2; // x8
  __int64 v4; // x20
  _BYTE *v5; // x22
  __int64 v6; // x20
  _BYTE *v7; // x22
  __int64 v8; // x20
  _BYTE *v9; // x22
  __int64 v10; // x20
  _BYTE *v11; // x22
  __int64 v12; // x19
  _BYTE *v13; // x21

  if ( a2 == 2 )
  {
    v2 = *(__int64 **)(a1 - 144);
    *(_QWORD *)(a1 - 152) = 0;
    *(_QWORD *)(a1 - 136) = 0;
    v4 = *v2;
    if ( *v2 )
    {
      v5 = *(_BYTE **)(v4 + 1792);
      if ( v5 )
      {
        ipc_log_string(
          *(_QWORD *)(v4 + 1704),
          "DBG1:%s: PCIe: RC%d: event %d received\n",
          "msm_pcie_drv_notify_client",
          *(_DWORD *)(v4 + 1348),
          4);
        ipc_log_string(
          *(_QWORD *)(v4 + 1696),
          "%s: PCIe: RC%d: event %d received\n",
          "msm_pcie_drv_notify_client",
          *(_DWORD *)(v4 + 1348),
          4);
        if ( *v5 == 1 )
          msm_pcie_notify_client(v4, 4);
      }
    }
    v6 = *(_QWORD *)(*(_QWORD *)(a1 - 144) + 8LL);
    if ( v6 )
    {
      v7 = *(_BYTE **)(v6 + 1792);
      if ( v7 )
      {
        ipc_log_string(
          *(_QWORD *)(v6 + 1704),
          "DBG1:%s: PCIe: RC%d: event %d received\n",
          "msm_pcie_drv_notify_client",
          *(_DWORD *)(v6 + 1348),
          4);
        ipc_log_string(
          *(_QWORD *)(v6 + 1696),
          "%s: PCIe: RC%d: event %d received\n",
          "msm_pcie_drv_notify_client",
          *(_DWORD *)(v6 + 1348),
          4);
        if ( *v7 == 1 )
          msm_pcie_notify_client(v6, 4);
      }
    }
    v8 = *(_QWORD *)(*(_QWORD *)(a1 - 144) + 16LL);
    if ( v8 )
    {
      v9 = *(_BYTE **)(v8 + 1792);
      if ( v9 )
      {
        ipc_log_string(
          *(_QWORD *)(v8 + 1704),
          "DBG1:%s: PCIe: RC%d: event %d received\n",
          "msm_pcie_drv_notify_client",
          *(_DWORD *)(v8 + 1348),
          4);
        ipc_log_string(
          *(_QWORD *)(v8 + 1696),
          "%s: PCIe: RC%d: event %d received\n",
          "msm_pcie_drv_notify_client",
          *(_DWORD *)(v8 + 1348),
          4);
        if ( *v9 == 1 )
          msm_pcie_notify_client(v8, 4);
      }
    }
    v10 = *(_QWORD *)(*(_QWORD *)(a1 - 144) + 24LL);
    if ( v10 )
    {
      v11 = *(_BYTE **)(v10 + 1792);
      if ( v11 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: PCIe: RC%d: event %d received\n",
          "msm_pcie_drv_notify_client",
          *(_DWORD *)(v10 + 1348),
          4);
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: PCIe: RC%d: event %d received\n",
          "msm_pcie_drv_notify_client",
          *(_DWORD *)(v10 + 1348),
          4);
        if ( *v11 == 1 )
          msm_pcie_notify_client(v10, 4);
      }
    }
    v12 = *(_QWORD *)(*(_QWORD *)(a1 - 144) + 32LL);
    if ( v12 )
    {
      v13 = *(_BYTE **)(v12 + 1792);
      if ( v13 )
      {
        ipc_log_string(
          *(_QWORD *)(v12 + 1704),
          "DBG1:%s: PCIe: RC%d: event %d received\n",
          "msm_pcie_drv_notify_client",
          *(_DWORD *)(v12 + 1348),
          4);
        ipc_log_string(
          *(_QWORD *)(v12 + 1696),
          "%s: PCIe: RC%d: event %d received\n",
          "msm_pcie_drv_notify_client",
          *(_DWORD *)(v12 + 1348),
          4);
        if ( *v13 == 1 )
          msm_pcie_notify_client(v12, 4);
      }
    }
  }
  return 1;
}
