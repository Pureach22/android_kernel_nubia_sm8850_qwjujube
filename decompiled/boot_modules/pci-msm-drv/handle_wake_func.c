__int64 __fastcall handle_wake_func(__int64 a1)
{
  __int64 v2; // x21
  int *v3; // x23
  __int64 v4; // x19
  __int64 v5; // x0
  int v6; // w3
  void *v8; // x0

  v2 = a1 - 1360;
  if ( a1 == 1360 )
  {
    v4 = 1424;
    mutex_lock(1424);
    if ( (byte_54D & 1) == 0 )
    {
      if ( (unsigned int)msm_pcie_enumerate(dword_544) )
        goto LABEL_9;
      goto LABEL_7;
    }
LABEL_11:
    v8 = &unk_2DD5B;
    goto LABEL_12;
  }
  v3 = (int *)(a1 - 12);
  ipc_log_string(*(_QWORD *)(a1 + 344), "DBG1:%s: PCIe: Wake work for RC%d\n", "handle_wake_func", *(_DWORD *)(a1 - 12));
  ipc_log_string(*(_QWORD *)(a1 + 336), "%s: PCIe: Wake work for RC%d\n", "handle_wake_func", *v3);
  v4 = a1 + 64;
  mutex_lock(a1 + 64);
  v5 = *(_QWORD *)(a1 + 344);
  v6 = *v3;
  if ( *(_BYTE *)(a1 - 3) == 1 )
  {
    ipc_log_string(v5, "ERR:%s: PCIe: The enumeration for RC%d has already been done.\n", "handle_wake_func", v6);
    ipc_log_string(
      *(_QWORD *)(a1 + 336),
      "%s: PCIe: The enumeration for RC%d has already been done.\n",
      "handle_wake_func",
      *(_DWORD *)(a1 - 12));
    goto LABEL_11;
  }
  ipc_log_string(v5, "DBG1:%s: PCIe: Start enumeration for RC%d upon the wake from endpoint.\n", "handle_wake_func", v6);
  ipc_log_string(
    *(_QWORD *)(a1 + 336),
    "%s: PCIe: Start enumeration for RC%d upon the wake from endpoint.\n",
    "handle_wake_func",
    *(_DWORD *)(a1 - 12));
  if ( (unsigned int)msm_pcie_enumerate(*(_DWORD *)(a1 - 12)) )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 344),
      "ERR:%s: PCIe: failed to enable RC%d upon wake request from the device.\n",
      "handle_wake_func",
      *(_DWORD *)(a1 - 12));
    ipc_log_string(
      *(_QWORD *)(a1 + 336),
      "%s: PCIe: failed to enable RC%d upon wake request from the device.\n",
      "handle_wake_func",
      *(_DWORD *)(a1 - 12));
LABEL_9:
    v8 = &unk_29C32;
LABEL_12:
    printk(v8);
    return mutex_unlock(v4);
  }
LABEL_7:
  msm_pcie_notify_client(v2, 2);
  return mutex_unlock(v4);
}
