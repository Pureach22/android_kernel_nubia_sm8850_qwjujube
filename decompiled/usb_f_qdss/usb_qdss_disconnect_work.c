__int64 __fastcall usb_qdss_disconnect_work(__int64 a1)
{
  _DWORD *v2; // x8
  __int64 v3; // x0
  const char *v4; // x20
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 v7; // x0

  ipc_log_string(qdss_ipc_log, "%s: channel:%s\n", "usb_qdss_disconnect_work", *(const char **)(a1 - 128));
  v2 = *(_DWORD **)(a1 - 104);
  if ( v2 )
  {
    v3 = *(_QWORD *)(a1 - 96);
    if ( *(v2 - 1) != 840361381 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v2)(v3, 1, 0, 0);
  }
  mutex_lock(a1 + 48);
  if ( *(_BYTE *)(a1 + 96) == 1
    && (v4 = *(const char **)(a1 - 128), strcmp(v4, "qdss_mdm"))
    && strcmp(v4, "qdss_sw")
    && (unsigned int)set_qdss_data_connection(a1 - 424, 0) )
  {
    printk(&unk_85BF, v5);
    v6 = *(_QWORD *)(a1 - 160);
    if ( !v6 )
      return mutex_unlock(a1 + 48);
  }
  else
  {
    v6 = *(_QWORD *)(a1 - 160);
    if ( !v6 )
      return mutex_unlock(a1 + 48);
  }
  v7 = *(_QWORD *)(v6 + 200);
  if ( v7 )
    _pm_runtime_idle(v7, 5);
  return mutex_unlock(a1 + 48);
}
