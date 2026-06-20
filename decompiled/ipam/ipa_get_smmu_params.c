__int64 __fastcall ipa_get_smmu_params(int *a1, _BYTE *a2)
{
  int v2; // w8
  char v3; // w8
  _BYTE *v4; // x20
  __int64 v5; // x8
  __int64 v6; // x8
  char v7; // w8
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0

  if ( !a1 || !a2 )
  {
    printk(&unk_3EB9DD, "ipa_get_smmu_params");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d bad parms for Client SMMU out params\n", "ipa_get_smmu_params", 12231);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d bad parms for Client SMMU out params\n", "ipa_get_smmu_params", 12231);
    }
    return 4294967274LL;
  }
  if ( !ipa3_ctx )
  {
    printk(&unk_3B74E7, "ipa_get_smmu_params");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d IPA not yet initialized\n", "ipa_get_smmu_params", 12236);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d IPA not yet initialized\n", "ipa_get_smmu_params", 12236);
    }
    return 4294967274LL;
  }
  a2[1] = 0;
  v2 = *a1;
  if ( *a1 > 2 )
  {
    switch ( v2 )
    {
      case 3:
        if ( (*(_BYTE *)(ipa3_ctx + 43310) & 1) != 0 )
          goto LABEL_29;
        v3 = *(_BYTE *)(ipa3_ctx + 43312);
        break;
      case 4:
        if ( (*(_BYTE *)(ipa3_ctx + 43310) & 1) == 0 )
        {
          v3 = *(_BYTE *)(ipa3_ctx + 43315);
          break;
        }
        goto LABEL_29;
      case 5:
        if ( (*(_BYTE *)(ipa3_ctx + 43310) & 1) != 0 )
          goto LABEL_29;
        v3 = *(_BYTE *)(ipa3_ctx + 43316);
        break;
      default:
LABEL_54:
        printk(&unk_3C313C, "ipa_get_smmu_params");
        v18 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v19 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v19 )
          {
            ipc_log_string(v19, "ipa %s:%d Trying to get illegal clients SMMU status", "ipa_get_smmu_params", 12304);
            v18 = ipa3_ctx;
          }
          v20 = *(_QWORD *)(v18 + 34160);
          if ( v20 )
            ipc_log_string(v20, "ipa %s:%d Trying to get illegal clients SMMU status", "ipa_get_smmu_params", 12304);
        }
        return 4294967274LL;
    }
LABEL_31:
    v7 = v3 ^ 1;
    goto LABEL_35;
  }
  if ( !v2 )
  {
    v4 = a2;
    if ( (int)ipa_get_wdi_version() > 1 )
      goto LABEL_18;
    v6 = ipa3_ctx;
    a2 = v4;
    if ( *(_BYTE *)(ipa3_ctx + 32265) == 1 )
    {
      if ( (unsigned int)ipa_get_wdi_version() == 1 )
      {
LABEL_18:
        a2 = v4;
        v5 = ipa3_ctx + 40960;
        if ( (*(_BYTE *)(ipa3_ctx + 43310) & 1) == 0 )
          goto LABEL_30;
        goto LABEL_29;
      }
      v6 = ipa3_ctx;
      a2 = v4;
    }
    v5 = v6 + 40960;
    if ( (*(_BYTE *)(v5 + 2353) & 1) == 0 )
    {
LABEL_30:
      v3 = *(_BYTE *)(v5 + 2351);
      goto LABEL_31;
    }
LABEL_29:
    v7 = 0;
LABEL_35:
    result = 0;
    *a2 = v7 & 1;
    return result;
  }
  if ( v2 == 1 )
  {
    v3 = *(_BYTE *)(ipa3_ctx + 43310);
    goto LABEL_31;
  }
  if ( v2 != 2 )
    goto LABEL_54;
  if ( (*(_BYTE *)(ipa3_ctx + 43313) & 1) == 0 )
  {
    if ( (*(_BYTE *)(ipa3_ctx + 43314) & 1) != 0 || (*(_BYTE *)(ipa3_ctx + 43310) & 1) != 0 )
      goto LABEL_48;
    goto LABEL_34;
  }
  if ( *(_BYTE *)(ipa3_ctx + 43314) && (*(_BYTE *)(ipa3_ctx + 43310) & 1) != 0 )
  {
LABEL_34:
    v7 = *(_BYTE *)(ipa3_ctx + 43313) ^ 1;
    a2[1] = byte_1F7924;
    goto LABEL_35;
  }
LABEL_48:
  printk(&unk_3DDA91, "ipa_get_smmu_params");
  v15 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v16 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v16 )
    {
      ipc_log_string(
        v16,
        "ipa %s:%d 11AD SMMU Discrepancy (%d %d %d)\n",
        "ipa_get_smmu_params",
        12291,
        *(unsigned __int8 *)(ipa3_ctx + 43313),
        *(unsigned __int8 *)(ipa3_ctx + 43310),
        *(unsigned __int8 *)(ipa3_ctx + 43314));
      v15 = ipa3_ctx;
    }
    v17 = *(_QWORD *)(v15 + 34160);
    if ( v17 )
      ipc_log_string(
        v17,
        "ipa %s:%d 11AD SMMU Discrepancy (%d %d %d)\n",
        "ipa_get_smmu_params",
        12291,
        *(unsigned __int8 *)(v15 + 43313),
        *(unsigned __int8 *)(v15 + 43310),
        *(unsigned __int8 *)(v15 + 43314));
  }
  __break(0x800u);
  return 4294967274LL;
}
