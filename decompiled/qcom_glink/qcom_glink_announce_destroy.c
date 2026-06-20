__int64 __fastcall qcom_glink_announce_destroy(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x8

  v1 = *(_QWORD *)(a1 + 968);
  v2 = *(_QWORD *)(v1 + 112);
  if ( v2 )
    ipc_log_string(
      *(_QWORD *)(v2 + 256),
      "%s[%d:%d] %s: Entered\n",
      *(const char **)(v1 + 128),
      *(_DWORD *)(v1 + 136),
      *(_DWORD *)(v1 + 140),
      "qcom_glink_announce_destroy");
  v3 = *(_QWORD *)(v1 + 216);
  if ( v3 )
    kthread_stop(v3);
  v4 = *(_QWORD *)(v1 + 112);
  if ( v4 )
    ipc_log_string(
      *(_QWORD *)(v4 + 256),
      "%s[%d:%d] %s: Exit\n",
      *(const char **)(v1 + 128),
      *(_DWORD *)(v1 + 136),
      *(_DWORD *)(v1 + 140),
      "qcom_glink_announce_destroy");
  return 0;
}
