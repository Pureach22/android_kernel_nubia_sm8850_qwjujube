__int64 __fastcall gen8_hfi_send_acd_feature_ctrl(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 result; // x0
  int v5; // w0
  __int64 v6; // x20
  unsigned int v7; // w19
  const char *v8; // x0
  __int64 v9; // [xsp+8h] [xbp-98h] BYREF
  __int64 v10; // [xsp+10h] [xbp-90h]
  __int64 v11; // [xsp+18h] [xbp-88h] BYREF
  __int64 v12; // [xsp+20h] [xbp-80h]
  __int64 v13; // [xsp+28h] [xbp-78h]
  __int64 v14; // [xsp+30h] [xbp-70h]
  __int64 v15; // [xsp+38h] [xbp-68h]
  __int64 v16; // [xsp+40h] [xbp-60h]
  __int64 v17; // [xsp+48h] [xbp-58h]
  __int64 v18; // [xsp+50h] [xbp-50h]
  __int64 v19; // [xsp+58h] [xbp-48h]
  __int64 v20; // [xsp+60h] [xbp-40h]
  __int64 v21; // [xsp+68h] [xbp-38h]
  __int64 v22; // [xsp+70h] [xbp-30h]
  __int64 v23; // [xsp+78h] [xbp-28h]
  __int64 v24; // [xsp+80h] [xbp-20h]
  __int64 v25; // [xsp+88h] [xbp-18h]
  __int64 v26; // [xsp+90h] [xbp-10h]
  __int64 v27; // [xsp+98h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = to_gen8_gmu(a1);
  if ( *(_BYTE *)(a1 + 20433) != 1 )
  {
LABEL_8:
    result = 0;
    goto LABEL_9;
  }
  v3 = v2;
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
  v11 = 0;
  v12 = 0;
  v9 = 0xC0000000BLL;
  v10 = 1;
  result = gen8_hfi_send_generic_req_v5(a1, (int *)&v9, (int *)&v11, 0x10u);
  if ( (result & 0x80000000) != 0 )
  {
    v6 = *(_QWORD *)(a1 + 1544);
    v7 = result;
    v8 = hfi_feature_to_string(12);
    dev_err(v6 + 16, "Unable to %s feature %s (%d)\n", "enable", v8, 12);
    result = v7;
    goto LABEL_9;
  }
  if ( !(_DWORD)result )
  {
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
    v11 = 0;
    v12 = 0;
    result = gen8_hfi_send_cmd_wait_inline(a1, (int *)(v3 + 696), 0x114u, (int *)&v11);
    if ( !(_DWORD)result )
    {
      if ( HIDWORD(v12) )
      {
        dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n", v12, HIDWORD(v12));
        gmu_core_fault_snapshot(a1, 6);
        result = 4294967274LL;
        goto LABEL_9;
      }
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
      v11 = 0;
      v12 = 0;
      v9 = 0x700000000DLL;
      v10 = 44;
      v5 = gen8_hfi_send_generic_req_v5(a1, (int *)&v9, (int *)&v11, 0x10u);
      if ( v5 < 0 )
        dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Unable to set HFI Value %d, %d to %d, error = %d\n", 112, 44, 0, v5);
      goto LABEL_8;
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
