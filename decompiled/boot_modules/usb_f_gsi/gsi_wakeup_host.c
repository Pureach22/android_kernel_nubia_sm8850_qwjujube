__int64 __fastcall gsi_wakeup_host(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x1
  __int64 v4; // x8
  unsigned int v5; // w19

  v1 = result;
  v2 = **(_QWORD **)(*(_QWORD *)(result + 48) + 48LL);
  if ( result )
  {
    ipc_log_string(*(_QWORD *)(result + 1344), "Entering %s", "gsi_wakeup_host");
    if ( !v2 )
    {
      ipc_log_string(*(_QWORD *)(v1 + 1344), "FAILED: d_port->cdev->gadget == NULL");
      return printk(&unk_118C5, v3);
    }
  }
  else if ( !v2 )
  {
    return result;
  }
  if ( *(_DWORD *)(v2 + 72) >= 5u && (*(_BYTE *)(v1 + 284) & 1) != 0 )
  {
    result = 4294967201LL;
LABEL_14:
    if ( v1 )
    {
      if ( (_DWORD)result )
      {
        v4 = *(_QWORD *)(v1 + 1344);
        v5 = result;
        ipc_log_string(v4, "wakeup failed. ret=%d.", result);
        return printk(&unk_10443, v5);
      }
    }
    return result;
  }
  if ( v1 )
    ipc_log_string(*(_QWORD *)(v1 + 1344), "%s: Calling usb_gadget_wakeup", "gsi_wakeup_host");
  result = usb_gadget_wakeup(v2);
  if ( (_DWORD)result != -11 && (_DWORD)result != -16 )
    goto LABEL_14;
  if ( v1 )
    return ipc_log_string(*(_QWORD *)(v1 + 1344), "RW delayed due to LPM exit.");
  return result;
}
