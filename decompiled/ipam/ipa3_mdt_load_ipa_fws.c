__int64 __fastcall ipa3_mdt_load_ipa_fws(const char *a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x23
  __int64 v6; // x0
  unsigned int matched; // w0
  __int64 v8; // x1
  unsigned int v9; // w20
  __int64 v10; // x0
  int v11; // w0
  int v12; // w0
  __int64 v13; // x21
  __int64 v14; // x24
  __int64 v15; // x0
  __int64 v16; // x20
  int v17; // w0
  int v18; // w21
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 result; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  const char *v25; // x1
  const char *v26; // x1
  unsigned int v27; // [xsp+Ch] [xbp-E4h] BYREF
  __int64 v28; // [xsp+10h] [xbp-E0h] BYREF
  __int64 v29; // [xsp+18h] [xbp-D8h]
  __int64 v30; // [xsp+20h] [xbp-D0h]
  __int64 v31; // [xsp+28h] [xbp-C8h]
  __int64 v32; // [xsp+30h] [xbp-C0h]
  __int64 v33; // [xsp+38h] [xbp-B8h]
  __int64 v34; // [xsp+40h] [xbp-B0h]
  __int64 v35; // [xsp+48h] [xbp-A8h]
  __int64 v36; // [xsp+50h] [xbp-A0h]
  __int64 v37; // [xsp+58h] [xbp-98h]
  __int64 v38; // [xsp+60h] [xbp-90h]
  __int64 v39; // [xsp+68h] [xbp-88h]
  __int64 v40; // [xsp+70h] [xbp-80h] BYREF
  _QWORD v41[4]; // [xsp+78h] [xbp-78h] BYREF
  _QWORD v42[11]; // [xsp+98h] [xbp-58h] BYREF

  v42[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d MDT FW loading process initiated sub_sys=%s\n", "ipa3_mdt_load_ipa_fws", 8481, a1);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d MDT FW loading process initiated sub_sys=%s\n", "ipa3_mdt_load_ipa_fws", 8481, a1);
      v2 = ipa3_ctx;
    }
  }
  v5 = *(_QWORD *)(v2 + 34208);
  v40 = 0;
  memset(v41, 0, sizeof(v41));
  v6 = *(_QWORD *)(v5 + 760);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v27 = 0;
  matched = of_property_match_string(v6, "firmware-names", a1);
  if ( (matched & 0x80000000) != 0 )
  {
    printk(&unk_3BD8F9, v8);
    goto LABEL_27;
  }
  v9 = matched;
  v10 = *(_QWORD *)(v5 + 760);
  memset(v42, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v10, "memory-regions", 0, 0, v9, v42) || !v42[0] )
  {
    dev_err(v5 + 16, "DT error getting \"memory-region\" property\n");
    goto LABEL_27;
  }
  v11 = of_address_to_resource(v42[0], 0, &v28);
  if ( v11 )
  {
    v25 = "error %d getting \"memory-region\" resource\n";
LABEL_36:
    v18 = v11;
    dev_err(v5 + 16, v25);
    goto LABEL_18;
  }
  scnprintf(v41, 32, "%s.mdt", a1);
  v11 = of_property_read_u32_index(*(_QWORD *)(v5 + 760), "pas-ids", v9, &v27);
  if ( v11 )
  {
    v25 = "error %d getting \"pass-ids\" property\n";
    goto LABEL_36;
  }
  v12 = request_firmware(&v40, v41, v5 + 16);
  if ( !v12 )
  {
    v13 = v28;
    v14 = v29 - v28;
    v15 = memremap(v28, v29 - v28 + 1, 4);
    if ( !v15 )
    {
      dev_err(v5 + 16, "unable to remap firmware memory\n");
      v18 = -12;
      goto LABEL_17;
    }
    v16 = v15;
    v17 = qcom_mdt_load(v5 + 16, v40, v41, v27, v15, v13, v14 + 1, 0);
    if ( v17 )
    {
      v26 = "error %d loading \"%s\"\n";
    }
    else
    {
      v17 = qcom_scm_pas_auth_and_reset(v27);
      if ( !v17 )
      {
        v18 = 0;
LABEL_16:
        memunmap(v16);
LABEL_17:
        release_firmware(v40);
        goto LABEL_18;
      }
      v26 = "error %d authenticating \"%s\"\n";
    }
    v18 = v17;
    dev_err(v5 + 16, v26);
    goto LABEL_16;
  }
  v18 = v12;
  dev_err(v5 + 16, "error %d requesting \"%s\"\n", v12, (const char *)v41);
LABEL_18:
  if ( v18 < 0 )
  {
LABEL_27:
    printk(&unk_3A93FB, "ipa3_mdt_load_ipa_fws");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d Unable to MDT load FW for sub_sys=%s\n", "ipa3_mdt_load_ipa_fws", 8485, a1);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
        ipc_log_string(v24, "ipa %s:%d Unable to MDT load FW for sub_sys=%s\n", "ipa3_mdt_load_ipa_fws", 8485, a1);
    }
    result = 4294967274LL;
    goto LABEL_33;
  }
  v19 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_24:
    result = 0;
    goto LABEL_33;
  }
  v20 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v20 )
  {
    ipc_log_string(v20, "ipa %s:%d MDT FW loading process is complete sub_sys=%s\n", "ipa3_mdt_load_ipa_fws", 8489, a1);
    v19 = ipa3_ctx;
  }
  result = *(_QWORD *)(v19 + 34160);
  if ( result )
  {
    ipc_log_string(
      result,
      "ipa %s:%d MDT FW loading process is complete sub_sys=%s\n",
      "ipa3_mdt_load_ipa_fws",
      8489,
      a1);
    goto LABEL_24;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
