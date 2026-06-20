__int64 __fastcall fw_load(_QWORD *a1)
{
  __int64 v2; // x8
  _QWORD *v3; // x26
  const char *v4; // x20
  void *v5; // x0
  unsigned int v6; // w20
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 result; // x0
  unsigned int v11; // w8
  unsigned int v12; // w20
  __int64 v13; // x21
  __int64 v14; // x0
  int v15; // w0
  int v16; // w22
  __int64 v17; // x0
  unsigned int v18; // w20
  __int64 v19; // x23
  __int64 v20; // x25
  int v21; // w0
  unsigned __int64 v22; // x24
  unsigned __int64 size; // x0
  __int64 v24; // x0
  __int64 v25; // x23
  void *v26; // x0
  int v27; // w0
  __int64 v28; // x8
  void (__fastcall *v29)(__int64, const char *, __int64, __int64, unsigned __int64); // x8
  __int64 v30; // [xsp+8h] [xbp-148h]
  __int64 v31; // [xsp+10h] [xbp-140h] BYREF
  __int64 v32; // [xsp+18h] [xbp-138h]
  __int64 v33; // [xsp+20h] [xbp-130h]
  __int64 v34; // [xsp+28h] [xbp-128h]
  __int64 v35; // [xsp+30h] [xbp-120h]
  __int64 v36; // [xsp+38h] [xbp-118h]
  __int64 v37; // [xsp+40h] [xbp-110h]
  __int64 v38; // [xsp+48h] [xbp-108h]
  __int64 v39; // [xsp+50h] [xbp-100h]
  __int64 v40; // [xsp+58h] [xbp-F8h]
  __int64 v41; // [xsp+60h] [xbp-F0h]
  __int64 v42; // [xsp+68h] [xbp-E8h]
  __int64 v43; // [xsp+70h] [xbp-E0h] BYREF
  _QWORD v44[16]; // [xsp+78h] [xbp-D8h] BYREF
  _QWORD v45[11]; // [xsp+F8h] [xbp-58h] BYREF

  v45[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1[488] + 144LL) )
    goto LABEL_11;
  v2 = a1[489];
  v3 = (_QWORD *)*a1;
  v43 = 0;
  memset(v44, 0, sizeof(v44));
  v4 = *(const char **)(v2 + 192);
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  if ( !v4 || !v3 || !*v4 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v5 = &unk_8C85D;
      goto LABEL_39;
    }
    goto LABEL_9;
  }
  if ( strlen(v4) >= 0x7C )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v5 = &unk_95FCF;
LABEL_39:
      printk(v5, "err ", 0xFFFFFFFFLL, "codec", "__load_fw_to_memory");
      goto LABEL_9;
    }
    goto LABEL_9;
  }
  v13 = v3[21];
  if ( !v13 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_870EB, "err ", 0xFFFFFFFFLL, "codec", "__load_fw_to_memory");
    goto LABEL_9;
  }
  scnprintf(v44, 128, "%s.mbn", v4);
  v14 = v3[95];
  v6 = *(_DWORD *)(*(_QWORD *)(v13 + 3912) + 200LL);
  memset(v45, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v14, "memory-region", 0, 0, 0, v45) || !v45[0] )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v5 = &unk_8B237;
      goto LABEL_39;
    }
LABEL_9:
    v6 = -22;
    goto LABEL_10;
  }
  v15 = of_address_to_resource(v45[0], 0, &v31);
  if ( v15 )
  {
    v16 = v15;
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_83361, "err ", 0xFFFFFFFFLL, "codec", "__load_fw_to_memory");
      v17 = v43;
      if ( !v43 )
        goto LABEL_45;
      goto LABEL_44;
    }
LABEL_43:
    v17 = v43;
    if ( !v43 )
    {
LABEL_45:
      v6 = v16;
      goto LABEL_10;
    }
LABEL_44:
    release_firmware(v17);
    goto LABEL_45;
  }
  v20 = v31;
  v19 = v32;
  v30 = v31;
  v21 = request_firmware(&v43, v44, v3 + 2);
  if ( v21 )
  {
    v16 = v21;
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_84BB6, "err ", 0xFFFFFFFFLL, "codec", "__load_fw_to_memory");
      v17 = v43;
      if ( !v43 )
        goto LABEL_45;
      goto LABEL_44;
    }
    goto LABEL_43;
  }
  v22 = v19 - v20 + 1;
  size = qcom_mdt_get_size(v43);
  if ( (size & 0x8000000000000000LL) != 0 || v22 < size )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_7F74B, "err ", 0xFFFFFFFFLL, "codec", "__load_fw_to_memory");
    v16 = -22;
    v17 = v43;
    if ( !v43 )
      goto LABEL_45;
    goto LABEL_44;
  }
  v24 = memremap(v20, v19 - v20 + 1, 4);
  if ( v24 )
  {
    v25 = v24;
    pm_stay_awake(v3[14]);
    v16 = qcom_mdt_load(v3 + 2, v43, v44, v6, v25, v20, v22, 0);
    pm_relax(v3[14]);
    if ( v16 )
    {
      if ( (msm_vidc_debug & 1) == 0 )
        goto LABEL_61;
      v26 = &unk_81ECC;
      goto LABEL_73;
    }
    v27 = qcom_scm_pas_auth_and_reset(v6);
    if ( v27 )
    {
      v16 = v27;
      if ( (msm_vidc_debug & 1) == 0 )
        goto LABEL_61;
      v26 = &unk_87126;
LABEL_73:
      printk(v26, "err ", 0xFFFFFFFFLL, "codec", "__load_fw_to_memory");
LABEL_61:
      memunmap(v25);
      v17 = v43;
      if ( !v43 )
        goto LABEL_45;
      goto LABEL_44;
    }
    v28 = *(_QWORD *)(v13 + 6592);
    if ( v28 )
    {
      v29 = *(void (__fastcall **)(__int64, const char *, __int64, __int64, unsigned __int64))(v28 + 16);
      if ( v29 )
      {
        if ( *((_DWORD *)v29 - 1) != -22655239 )
          __break(0x8228u);
        v29(v13, "vidc_core", v25, v30, v22);
      }
    }
    memunmap(v25);
    release_firmware(v43);
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8D535, "high", 0xFFFFFFFFLL, "codec", "__load_fw_to_memory");
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_920B9, "err ", 0xFFFFFFFFLL, "codec", "__load_fw_to_memory");
    v6 = -12;
  }
LABEL_10:
  *(_DWORD *)(a1[488] + 144LL) = v6;
  v7 = a1[488];
  if ( *(int *)(v7 + 144) <= 0 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
    {
      result = 4294967284LL;
      goto LABEL_25;
    }
    printk(&unk_912EE, "err ", 0xFFFFFFFFLL, "codec", "fw_load");
    result = 4294967284LL;
LABEL_21:
    v7 = a1[488];
LABEL_25:
    *(_DWORD *)(v7 + 144) = 0;
    goto LABEL_26;
  }
LABEL_11:
  if ( a1 && (v8 = a1[818]) != 0 && (v9 = *(__int64 (__fastcall **)(_QWORD))(v8 + 88)) != nullptr )
  {
    if ( *((_DWORD *)v9 - 1) != -1850880742 )
      __break(0x8228u);
    result = v9(a1);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v18 = result;
        printk(&unk_8C827, "err ", 0xFFFFFFFFLL, "codec", "fw_load");
        result = v18;
      }
      v7 = a1[488];
      v11 = *(_DWORD *)(v7 + 144);
      if ( !v11 )
        goto LABEL_25;
      v12 = result;
      qcom_scm_pas_shutdown(v11);
      result = v12;
      goto LABEL_21;
    }
  }
  else
  {
    result = 0;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
