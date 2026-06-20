__int64 __fastcall msm_gsi_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v5; // x8
  long double v6; // q0
  int variable_u32_array; // w0
  __int64 v8; // x8
  unsigned int v9; // w4
  __int64 inited; // x0

  v1 = a1 + 16;
  v3 = devm_kmalloc(a1 + 16, 29272, 3520);
  gsi_ctx = v3;
  if ( v3 )
  {
    v5 = *(_QWORD *)(v3 + 8);
    *(_QWORD *)(v3 + 28648) = 0;
    v6 = dev_err(v5, "%s:%d failed to create IPC log, continue...\n", "msm_gsi_probe", 5966);
    variable_u32_array = of_property_read_variable_u32_array(
                           *(_QWORD *)(a1 + 760),
                           "qcom,num-msi",
                           gsi_ctx + 28680,
                           1,
                           0,
                           v6);
    v8 = gsi_ctx;
    if ( variable_u32_array < 0 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d No MSIs configured\n", "msm_gsi_probe", 5971);
      v8 = gsi_ctx;
    }
    else
    {
      v9 = *(_DWORD *)(gsi_ctx + 28680);
      if ( v9 >= 3 )
      {
        dev_err(
          *(_QWORD *)(gsi_ctx + 8),
          "%s:%d Num MSIs %u larger than max %u, normalizing\n",
          "msm_gsi_probe",
          5976,
          v9,
          2);
        v8 = gsi_ctx;
        *(_DWORD *)(gsi_ctx + 28680) = 2;
      }
    }
    *(_DWORD *)(v8 + 28616) = 0;
    *(_QWORD *)(v8 + 8) = v1;
    inited = _init_swait_queue_head(v8 + 28624, "&x->wait", &init_completion___key);
    gsi_debugfs_init(inited);
    return 0;
  }
  else
  {
    dev_err(v1, "failed to allocated gsi context\n");
    return 4294967284LL;
  }
}
