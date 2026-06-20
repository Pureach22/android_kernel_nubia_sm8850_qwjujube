__int64 __fastcall msm_pcie_drv_send_rpmsg(__int64 a1, __int64 a2)
{
  __int64 v4; // x22
  __int64 v6; // x23
  __int16 v7; // w8
  unsigned int v8; // w0
  __int64 v9; // x0
  unsigned int v10; // w20

  if ( *(_QWORD *)(a1 + 3128) )
    return 0;
  v4 = *(_QWORD *)(a1 + 1792);
  mutex_lock(&unk_30D08);
  v6 = qword_30CB0;
  if ( qword_30CB0 )
  {
    v7 = *(_WORD *)(v4 + 248);
    *(_DWORD *)(v4 + 256) = 0;
    *(_WORD *)(v4 + 250) = v7;
    *(_WORD *)(v4 + 248) = v7 + 1;
    *(_WORD *)(a2 + 6) = v7;
    if ( *(__int16 *)(v4 + 248) == -1 )
    {
      *(_WORD *)(v4 + 248) = 0;
      if ( !a1 )
        goto LABEL_7;
    }
    else if ( !a1 )
    {
LABEL_7:
      v8 = rpmsg_trysend(*(_QWORD *)(v6 + 968), a2, 40);
      if ( !v8 )
        goto LABEL_18;
      if ( v8 != -16 )
        goto LABEL_24;
      usleep_range_state(5000, 5001, 2);
      v8 = rpmsg_trysend(*(_QWORD *)(v6 + 968), a2, 40);
      if ( !v8 )
        goto LABEL_18;
      if ( v8 != -16 )
        goto LABEL_24;
      usleep_range_state(5000, 5001, 2);
      v8 = rpmsg_trysend(*(_QWORD *)(v6 + 968), a2, 40);
      if ( !v8 )
        goto LABEL_18;
      if ( v8 != -16
        || (usleep_range_state(5000, 5001, 2), (v8 = rpmsg_trysend(*(_QWORD *)(v6 + 968), a2, 40)) != 0)
        && (v8 != -16
         || (usleep_range_state(5000, 5001, 2), (v8 = rpmsg_trysend(*(_QWORD *)(v6 + 968), a2, 40)) != 0)
         && (v8 != -16 || (usleep_range_state(5000, 5001, 2), (v8 = rpmsg_trysend(*(_QWORD *)(v6 + 968), a2, 40)) != 0))) )
      {
LABEL_24:
        v10 = v8;
        if ( a1 )
        {
          ipc_log_string(
            *(_QWORD *)(a1 + 1704),
            "ERR:%s: PCIe: RC%d: DRV: failed to send rpmsg, ret:%d\n",
            "msm_pcie_drv_send_rpmsg",
            *(_DWORD *)(a1 + 1348),
            v8);
          ipc_log_string(
            *(_QWORD *)(a1 + 1696),
            "%s: PCIe: RC%d: DRV: failed to send rpmsg, ret:%d\n",
            "msm_pcie_drv_send_rpmsg",
            *(_DWORD *)(a1 + 1348),
            v10);
        }
        printk(&unk_2D071);
      }
      else
      {
LABEL_18:
        v9 = _msecs_to_jiffies(*(unsigned int *)(v4 + 252));
        if ( (unsigned int)wait_for_completion_timeout(v4 + 256, v9) )
        {
          if ( a1 )
          {
            ipc_log_string(
              *(_QWORD *)(a1 + 1704),
              "DBG1:%s: PCIe: RC%d: DRV: rpmsg successfully sent\n",
              "msm_pcie_drv_send_rpmsg",
              *(_DWORD *)(a1 + 1348));
            ipc_log_string(
              *(_QWORD *)(a1 + 1696),
              "%s: PCIe: RC%d: DRV: rpmsg successfully sent\n",
              "msm_pcie_drv_send_rpmsg",
              *(_DWORD *)(a1 + 1348));
          }
          v10 = 0;
        }
        else
        {
          if ( a1 )
          {
            ipc_log_string(
              *(_QWORD *)(a1 + 1704),
              "ERR:%s: PCIe: RC%d: DRV: completion timeout for rpmsg\n",
              "msm_pcie_drv_send_rpmsg",
              *(_DWORD *)(a1 + 1348));
            ipc_log_string(
              *(_QWORD *)(a1 + 1696),
              "%s: PCIe: RC%d: DRV: completion timeout for rpmsg\n",
              "msm_pcie_drv_send_rpmsg",
              *(_DWORD *)(a1 + 1348));
          }
          printk(&unk_2FF64);
          v10 = -110;
        }
      }
      goto LABEL_23;
    }
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: PCIe: RC%d: DRV: sending rpmsg: command: 0x%x\n",
      "msm_pcie_drv_send_rpmsg",
      *(_DWORD *)(a1 + 1348),
      *(_DWORD *)(a2 + 24));
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: DRV: sending rpmsg: command: 0x%x\n",
      "msm_pcie_drv_send_rpmsg",
      *(_DWORD *)(a1 + 1348),
      *(_DWORD *)(a2 + 24));
    goto LABEL_7;
  }
  v10 = -5;
LABEL_23:
  mutex_unlock(&unk_30D08);
  return v10;
}
