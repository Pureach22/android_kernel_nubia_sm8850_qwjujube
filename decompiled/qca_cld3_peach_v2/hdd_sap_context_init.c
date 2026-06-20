__int64 __fastcall hdd_sap_context_init(__int64 a1)
{
  _qdf_wake_lock_create((_QWORD *)(a1 + 920), (__int64)"sap_dfs_wakelock");
  *(_DWORD *)(a1 + 1120) = 0;
  _mutex_init(a1 + 192, "&hdd_ctx->sap_lock", &hdd_sap_context_init___key);
  _qdf_wake_lock_create((_QWORD *)(a1 + 288), (__int64)"qcom_sap_wakelock");
  return 0;
}
