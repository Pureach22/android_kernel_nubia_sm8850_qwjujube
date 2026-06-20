__int64 __fastcall load_cvp_fw_impl(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x8
  const char *v3; // x19
  __int64 v4; // x24
  __int64 v5; // x23
  void *v6; // x0
  unsigned __int64 StatusReg; // x8
  int v8; // w0
  __int64 v9; // x0
  int v10; // w0
  int v11; // w19
  unsigned __int64 v12; // x8
  __int64 v13; // x1
  __int64 v14; // x2
  void *v15; // x0
  unsigned __int64 v16; // x8
  __int64 v17; // x19
  __int64 v18; // x20
  __int64 v19; // x22
  int v20; // w0
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x21
  unsigned __int64 size; // x0
  __int64 v24; // x0
  __int64 v25; // x20
  int v26; // w0
  unsigned __int64 v27; // x8
  __int64 v28; // x1
  __int64 v29; // x2
  void *v30; // x0
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x8
  int v34; // w0
  unsigned __int64 v35; // x8
  unsigned int v36; // [xsp+Ch] [xbp-144h] BYREF
  __int64 v37; // [xsp+10h] [xbp-140h] BYREF
  __int64 v38; // [xsp+18h] [xbp-138h]
  __int64 v39; // [xsp+20h] [xbp-130h]
  __int64 v40; // [xsp+28h] [xbp-128h]
  __int64 v41; // [xsp+30h] [xbp-120h]
  __int64 v42; // [xsp+38h] [xbp-118h]
  __int64 v43; // [xsp+40h] [xbp-110h]
  __int64 v44; // [xsp+48h] [xbp-108h]
  __int64 v45; // [xsp+50h] [xbp-100h]
  __int64 v46; // [xsp+58h] [xbp-F8h]
  __int64 v47; // [xsp+60h] [xbp-F0h]
  __int64 v48; // [xsp+68h] [xbp-E8h]
  __int64 v49; // [xsp+70h] [xbp-E0h] BYREF
  _QWORD v50[16]; // [xsp+78h] [xbp-D8h] BYREF
  _QWORD v51[11]; // [xsp+F8h] [xbp-58h] BYREF

  v51[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 2200) )
    goto LABEL_2;
  v2 = *(_QWORD *)(a1 + 2208);
  v49 = 0;
  memset(v50, 0, sizeof(v50));
  v3 = *(const char **)(v2 + 360);
  v4 = *(_QWORD *)(v2 + 256);
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v36 = 0;
  if ( !v3 || !v4 || !*v3 )
  {
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_12;
    v5 = a1;
    v6 = &unk_8C40F;
    StatusReg = _ReadStatusReg(SP_EL0);
    goto LABEL_35;
  }
  v5 = a1;
  if ( strlen(v3) >= 0x7C )
  {
    a1 = v5;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_12;
    v6 = &unk_93919;
    StatusReg = _ReadStatusReg(SP_EL0);
LABEL_35:
    printk(v6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    a1 = v5;
LABEL_12:
    *(_DWORD *)(a1 + 2200) = -22;
    goto LABEL_13;
  }
  scnprintf(v50, 128, "%s.mbn", v3);
  v8 = of_property_read_variable_u32_array(*(_QWORD *)(v4 + 760), "pas-id", &v36, 1, 0);
  if ( v8 < 0 )
  {
    v11 = v8 & (v8 >> 31);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v31 = _ReadStatusReg(SP_EL0);
      v13 = *(unsigned int *)(v31 + 1800);
      v14 = *(unsigned int *)(v31 + 1804);
      v15 = &unk_96C3C;
      goto LABEL_48;
    }
LABEL_27:
    if ( v49 )
      release_firmware(v49);
    goto LABEL_29;
  }
  v9 = *(_QWORD *)(v4 + 760);
  memset(v51, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v9, "memory-region", 0, 0, 0, v51) || !v51[0] )
  {
    a1 = v5;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_12;
    v6 = &unk_8D94D;
    StatusReg = _ReadStatusReg(SP_EL0);
    goto LABEL_35;
  }
  v10 = of_address_to_resource(v51[0], 0, &v37);
  if ( v10 )
  {
    v11 = v10;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v12 = _ReadStatusReg(SP_EL0);
      v13 = *(unsigned int *)(v12 + 1800);
      v14 = *(unsigned int *)(v12 + 1804);
      v15 = &unk_92D3B;
LABEL_48:
      printk(v15, v13, v14, &unk_8E7CE);
      goto LABEL_27;
    }
    goto LABEL_27;
  }
  v19 = v37;
  v18 = v38;
  v20 = request_firmware(&v49, v50, v4 + 16);
  if ( v20 )
  {
    v11 = v20;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v21 = _ReadStatusReg(SP_EL0);
      printk(&unk_8800E, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
    }
    goto LABEL_27;
  }
  v22 = v18 - v19 + 1;
  size = qcom_mdt_get_size(v49);
  if ( (size & 0x8000000000000000LL) != 0 || v22 < size )
  {
    v11 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v32 = _ReadStatusReg(SP_EL0);
      printk(&unk_8370F, *(unsigned int *)(v32 + 1800), *(unsigned int *)(v32 + 1804), &unk_8E7CE);
    }
    goto LABEL_27;
  }
  v24 = memremap(v19, v18 - v19 + 1, 4);
  if ( !v24 )
  {
    v11 = -12;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v33 = _ReadStatusReg(SP_EL0);
      printk(&unk_869DD, *(unsigned int *)(v33 + 1800), *(unsigned int *)(v33 + 1804), &unk_8E7CE);
    }
    goto LABEL_27;
  }
  v25 = v24;
  v26 = qcom_mdt_load(v4 + 16, v49, v50, v36, v24, v19, v22, 0);
  if ( v26 )
  {
    v11 = v26;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_60;
    v27 = _ReadStatusReg(SP_EL0);
    v28 = *(unsigned int *)(v27 + 1800);
    v29 = *(unsigned int *)(v27 + 1804);
    v30 = &unk_8D994;
LABEL_59:
    printk(v30, v28, v29, &unk_8E7CE);
LABEL_60:
    memunmap(v25);
    goto LABEL_27;
  }
  v34 = qcom_scm_pas_auth_and_reset(v36);
  if ( v34 )
  {
    v11 = v34;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_60;
    v35 = _ReadStatusReg(SP_EL0);
    v28 = *(unsigned int *)(v35 + 1800);
    v29 = *(unsigned int *)(v35 + 1804);
    v30 = &unk_84192;
    goto LABEL_59;
  }
  memunmap(v25);
  release_firmware(v49);
  if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
    printk(&unk_84C5F, "core", "__load_fw_to_memory", v50);
  v11 = v36;
LABEL_29:
  a1 = v5;
  *(_DWORD *)(v5 + 2200) = v11;
  if ( v11 > 0 )
  {
LABEL_2:
    result = 0;
    goto LABEL_17;
  }
LABEL_13:
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v16 = _ReadStatusReg(SP_EL0);
    v17 = a1;
    printk(&unk_94B5E, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
    a1 = v17;
  }
  *(_DWORD *)(a1 + 2200) = 0;
  result = 4294967284LL;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
