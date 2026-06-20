__int64 __fastcall gen8_hfi_send_iff_pclx_feature_ctrl(_QWORD *a1)
{
  __int64 v1; // x22
  __int64 v2; // x8
  int v3; // w23
  unsigned int v5; // w20
  __int64 result; // x0
  _DWORD *v7; // x1
  int v8; // w3
  __int64 v9; // x20
  unsigned int v10; // w19
  const char *v11; // x0
  _QWORD v12[2]; // [xsp+8h] [xbp-98h] BYREF
  __int64 v13; // [xsp+18h] [xbp-88h] BYREF
  __int64 v14; // [xsp+20h] [xbp-80h]
  __int64 v15; // [xsp+28h] [xbp-78h]
  __int64 v16; // [xsp+30h] [xbp-70h]
  __int64 v17; // [xsp+38h] [xbp-68h]
  __int64 v18; // [xsp+40h] [xbp-60h]
  __int64 v19; // [xsp+48h] [xbp-58h]
  __int64 v20; // [xsp+50h] [xbp-50h]
  __int64 v21; // [xsp+58h] [xbp-48h]
  __int64 v22; // [xsp+60h] [xbp-40h]
  __int64 v23; // [xsp+68h] [xbp-38h]
  __int64 v24; // [xsp+70h] [xbp-30h]
  __int64 v25; // [xsp+78h] [xbp-28h]
  __int64 v26; // [xsp+80h] [xbp-20h]
  __int64 v27; // [xsp+88h] [xbp-18h]
  __int64 v28; // [xsp+90h] [xbp-10h]
  __int64 v29; // [xsp+98h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = a1[1783];
  v2 = *(_QWORD *)(v1 + 256);
  if ( !v2 )
    goto LABEL_9;
  v3 = *(_DWORD *)(v2 + 8);
  v5 = (32 * v3) | 0x14;
  if ( !gen8_hfi_send_iff_pclx_feature_ctrl_tbl_cmd )
  {
    gen8_hfi_send_iff_pclx_feature_ctrl_tbl_cmd = devm_kmalloc(a1[1396] + 16LL, (32 * v3) | 0x14u, 3520);
    if ( !gen8_hfi_send_iff_pclx_feature_ctrl_tbl_cmd )
    {
      result = 4294967284LL;
      goto LABEL_10;
    }
  }
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v12[0] = 0x200000000BLL;
  v12[1] = 1;
  result = gen8_hfi_send_generic_req_v5((__int64)a1, (int *)v12, (int *)&v13, 0x10u);
  if ( (result & 0x80000000) != 0 )
  {
    v9 = a1[193];
    v10 = result;
    v11 = hfi_feature_to_string(32);
    dev_err(v9 + 16, "Unable to %s feature %s (%d)\n", "enable", v11, 32);
    result = v10;
    goto LABEL_10;
  }
  if ( !(_DWORD)result )
  {
    v7 = (_DWORD *)gen8_hfi_send_iff_pclx_feature_ctrl_tbl_cmd;
    if ( !*(_DWORD *)gen8_hfi_send_iff_pclx_feature_ctrl_tbl_cmd )
    {
      *(_QWORD *)gen8_hfi_send_iff_pclx_feature_ctrl_tbl_cmd = 15;
      v7[2] = 10;
      v7[3] = v3;
      v7[4] = 8;
      memcpy(v7 + 5, **(const void ***)(v1 + 256), (unsigned int)(32 * v3));
      v27 = 0;
      v28 = 0;
      v25 = 0;
      v26 = 0;
      v23 = 0;
      v24 = 0;
      v21 = 0;
      v22 = 0;
      v19 = 0;
      v20 = 0;
      v17 = 0;
      v18 = 0;
      v15 = 0;
      v16 = 0;
      v13 = 0;
      v14 = 0;
      result = gen8_hfi_send_cmd_wait_inline(
                 (__int64)a1,
                 (int *)gen8_hfi_send_iff_pclx_feature_ctrl_tbl_cmd,
                 v5,
                 (int *)&v13);
      if ( (_DWORD)result )
        goto LABEL_10;
      v8 = HIDWORD(v14);
      if ( !HIDWORD(v14) )
        goto LABEL_9;
      goto LABEL_14;
    }
    v27 = 0;
    v28 = 0;
    v25 = 0;
    v26 = 0;
    v23 = 0;
    v24 = 0;
    v21 = 0;
    v22 = 0;
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = 0;
    v15 = 0;
    v16 = 0;
    v13 = 0;
    v14 = 0;
    result = gen8_hfi_send_cmd_wait_inline(
               (__int64)a1,
               (int *)gen8_hfi_send_iff_pclx_feature_ctrl_tbl_cmd,
               v5,
               (int *)&v13);
    if ( !(_DWORD)result )
    {
      v8 = HIDWORD(v14);
      if ( !HIDWORD(v14) )
      {
LABEL_9:
        result = 0;
        goto LABEL_10;
      }
LABEL_14:
      dev_err(a1[193] + 16LL, "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n", v14, v8);
      gmu_core_fault_snapshot(a1, 6);
      result = 4294967274LL;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
