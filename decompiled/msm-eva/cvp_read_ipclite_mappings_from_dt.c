__int64 __fastcall cvp_read_ipclite_mappings_from_dt(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v4; // x0
  __int64 result; // x0
  unsigned __int64 v6; // x8
  __int64 v7; // x1
  __int64 v8; // x2
  void *v9; // x8
  unsigned int v10; // w19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x9
  __int64 v14; // x1
  __int64 v15; // x2
  void *v16; // x0
  unsigned __int64 v17; // x8
  int v18; // w8
  int v19; // w0
  __int64 v20; // x2
  char v21; // w8
  unsigned __int64 v22; // x8
  unsigned int v23; // [xsp+4h] [xbp-BCh] BYREF
  __int64 v24; // [xsp+8h] [xbp-B8h] BYREF
  __int64 v25; // [xsp+10h] [xbp-B0h]
  __int64 v26; // [xsp+18h] [xbp-A8h]
  __int64 v27; // [xsp+20h] [xbp-A0h]
  __int64 v28; // [xsp+28h] [xbp-98h]
  __int64 v29; // [xsp+30h] [xbp-90h]
  __int64 v30; // [xsp+38h] [xbp-88h]
  __int64 v31; // [xsp+40h] [xbp-80h]
  __int64 v32; // [xsp+48h] [xbp-78h]
  __int64 v33; // [xsp+50h] [xbp-70h]
  __int64 v34; // [xsp+58h] [xbp-68h]
  __int64 v35; // [xsp+60h] [xbp-60h]
  _QWORD v36[11]; // [xsp+68h] [xbp-58h] BYREF

  v36[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8D714, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
    goto LABEL_30;
  }
  v1 = *(_QWORD *)(a1 + 112);
  if ( !v1 )
  {
    result = 4294967277LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v12 = _ReadStatusReg(SP_EL0);
      printk(&unk_849F0, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
      result = 4294967277LL;
    }
    goto LABEL_30;
  }
  v2 = *(_QWORD *)(v1 + 152);
  if ( !v2 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_30;
    v13 = _ReadStatusReg(SP_EL0);
    v14 = *(unsigned int *)(v13 + 1800);
    v15 = *(unsigned int *)(v13 + 1804);
    v16 = &unk_8D745;
LABEL_23:
    printk(v16, v14, v15, &unk_8E7CE);
    result = 4294967274LL;
    goto LABEL_30;
  }
  v4 = *(_QWORD *)(a1 + 760);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v23 = 0;
  memset(v36, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v4, "memory-region", 0, 0, 0, v36) || !v36[0] )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_30;
    v17 = _ReadStatusReg(SP_EL0);
    v14 = *(unsigned int *)(v17 + 1800);
    v15 = *(unsigned int *)(v17 + 1804);
    v16 = &unk_8AF1C;
    goto LABEL_23;
  }
  result = of_address_to_resource(v36[0], 0, &v24);
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v6 = _ReadStatusReg(SP_EL0);
      v7 = *(unsigned int *)(v6 + 1800);
      v8 = *(unsigned int *)(v6 + 1804);
      v9 = &unk_8FCDB;
LABEL_10:
      v10 = result;
      printk(v9, v7, v8, &unk_8E7CE);
      result = v10;
    }
  }
  else
  {
    v18 = v25 - v24 + 1;
    *(_QWORD *)(v2 + 664) = (unsigned int)v24;
    *(_DWORD *)(v2 + 672) = v18;
    v19 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "iova-region-start", &v23, 1, 0);
    if ( v19 < 0 )
    {
      result = v19 & (unsigned int)(v19 >> 31);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v22 = _ReadStatusReg(SP_EL0);
        v7 = *(unsigned int *)(v22 + 1800);
        v8 = *(unsigned int *)(v22 + 1804);
        v9 = &unk_95575;
        goto LABEL_10;
      }
    }
    else
    {
      v20 = v23;
      result = 0;
      v21 = BYTE1(msm_cvp_debug);
      *(_QWORD *)(v2 + 656) = v23;
      if ( (v21 & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_87E44, "core", v20, *(unsigned int *)(v2 + 672));
        result = 0;
      }
    }
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
