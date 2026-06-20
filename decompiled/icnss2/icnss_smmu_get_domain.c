__int64 __fastcall icnss_smmu_get_domain(_QWORD *a1)
{
  __int64 v1; // x8

  v1 = a1[19];
  if ( v1 )
    return *(_QWORD *)(v1 + 576);
  printk("%sicnss2: Invalid drvdata: dev %pK\n", byte_130B32, a1);
  ipc_log_string(icnss_ipc_log_context, "%sicnss2: Invalid drvdata: dev %pK\n", (const char *)&unk_12DBF3, a1);
  return 0;
}
