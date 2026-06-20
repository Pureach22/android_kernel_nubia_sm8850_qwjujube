__int64 ipa_wigig_init_smmu_params()
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int smmu_params; // w19
  __int64 v3; // x0
  const char *v4; // x4
  const char *v5; // x5
  __int64 v6; // x0
  const char *v7; // x4
  const char *v8; // x5
  __int64 v10; // x0
  __int64 v11; // x0
  __int16 v12; // [xsp+0h] [xbp-10h] BYREF
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d \n", "ipa_wigig_init_smmu_params", 239);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d \n", "ipa_wigig_init_smmu_params", 239);
  }
  v13 = 2;
  smmu_params = ipa_get_smmu_params(&v13, &v12);
  if ( smmu_params )
  {
    printk(&unk_3D4607, "ipa_wigig_init_smmu_params");
    if ( ipa3_get_ipc_logbuf() )
    {
      v10 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v10,
        "ipa_wigig %s:%d couldn't get SMMU params %d\n",
        "ipa_wigig_init_smmu_params",
        244,
        smmu_params);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v11 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v11,
        "ipa_wigig %s:%d couldn't get SMMU params %d\n",
        "ipa_wigig_init_smmu_params",
        244,
        smmu_params);
    }
  }
  else
  {
    *(_WORD *)(ipa_wigig_ctx + 908) = v12;
    if ( ipa3_get_ipc_logbuf() )
    {
      v3 = ipa3_get_ipc_logbuf();
      if ( (_BYTE)v12 )
        v4 = "enabled";
      else
        v4 = "disabled";
      if ( HIBYTE(v12) )
        v5 = "shared";
      else
        v5 = "not shared";
      ipc_log_string(v3, "ipa_wigig %s:%d SMMU (%s), 11ad CB (%s)\n", "ipa_wigig_init_smmu_params", 251, v4, v5);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      if ( (_BYTE)v12 )
        v7 = "enabled";
      else
        v7 = "disabled";
      if ( HIBYTE(v12) )
        v8 = "shared";
      else
        v8 = "not shared";
      ipc_log_string(v6, "ipa_wigig %s:%d SMMU (%s), 11ad CB (%s)\n", "ipa_wigig_init_smmu_params", 251, v7, v8);
    }
  }
  _ReadStatusReg(SP_EL0);
  return smmu_params;
}
