__int64 __fastcall glink_probe_smem_unreg(__int64 a1)
{
  const char *v2; // x2
  __int64 v3; // x0

  if ( *(_QWORD *)(a1 + 48) )
    qcom_glink_smem_unregister();
  v2 = *(const char **)(a1 + 32);
  v3 = glink_ilc;
  *(_QWORD *)(a1 + 48) = 0;
  return ipc_log_string(v3, "unregister for %s\n", v2);
}
