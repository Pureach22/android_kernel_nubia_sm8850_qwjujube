__int64 __fastcall qiib_restart_notifier_cb(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x0

  if ( a2 == 1 )
  {
    v4 = *(_QWORD *)(qiib_info + 88);
    if ( v4 )
      ipc_log_string(
        v4,
        "%s: %s: subsystem restart for %s\n",
        "qiib_restart_notifier_cb",
        "QCOM_SSR_AFTER_POWERUP",
        *(const char **)(a1 - 8));
    *(_BYTE *)(a1 + 32) = 0;
  }
  else if ( a2 == 2 )
  {
    v3 = *(_QWORD *)(qiib_info + 88);
    if ( v3 )
      ipc_log_string(
        v3,
        "%s: %s: subsystem restart for %s\n",
        "qiib_restart_notifier_cb",
        "QCOM_SSR_BEFORE_SHUTDOWN",
        *(const char **)(a1 - 8));
    *(_BYTE *)(a1 + 32) = 1;
    _wake_up(a1 - 48, 1, 1, 0);
  }
  return 0;
}
