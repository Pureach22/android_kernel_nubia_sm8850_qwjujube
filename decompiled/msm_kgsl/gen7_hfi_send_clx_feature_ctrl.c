__int64 __fastcall gen7_hfi_send_clx_feature_ctrl(__int64 a1)
{
  int v1; // w8
  __int64 result; // x0
  __int64 v4; // x20
  unsigned int v5; // w19
  const char *v6; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-D0h] BYREF
  int v8[2]; // [xsp+10h] [xbp-C0h] BYREF
  __int64 v9; // [xsp+18h] [xbp-B8h]
  __int64 v10; // [xsp+20h] [xbp-B0h]
  __int64 v11; // [xsp+28h] [xbp-A8h]
  __int64 v12; // [xsp+30h] [xbp-A0h]
  __int64 v13; // [xsp+38h] [xbp-98h]
  __int64 v14; // [xsp+40h] [xbp-90h]
  __int64 v15; // [xsp+48h] [xbp-88h] BYREF
  __int64 v16; // [xsp+50h] [xbp-80h]
  __int64 v17; // [xsp+58h] [xbp-78h]
  __int64 v18; // [xsp+60h] [xbp-70h]
  __int64 v19; // [xsp+68h] [xbp-68h]
  __int64 v20; // [xsp+70h] [xbp-60h]
  __int64 v21; // [xsp+78h] [xbp-58h]
  __int64 v22; // [xsp+80h] [xbp-50h]
  __int64 v23; // [xsp+88h] [xbp-48h]
  __int64 v24; // [xsp+90h] [xbp-40h]
  __int64 v25; // [xsp+98h] [xbp-38h]
  __int64 v26; // [xsp+A0h] [xbp-30h]
  __int64 v27; // [xsp+A8h] [xbp-28h]
  __int64 v28; // [xsp+B0h] [xbp-20h]
  __int64 v29; // [xsp+B8h] [xbp-18h]
  __int64 v30; // [xsp+C0h] [xbp-10h]
  __int64 v31; // [xsp+C8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned __int8 *)(a1 + 20438);
  v10 = 0;
  v11 = 0;
  v9 = 0;
  if ( v1 != 1 )
  {
LABEL_6:
    result = 0;
    goto LABEL_7;
  }
  v8[0] = 8;
  v29 = 0;
  v30 = 0;
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
  v7[0] = 0x150000000BLL;
  v7[1] = 1;
  result = gen7_hfi_send_generic_req_v5(a1, (int *)v7, (int *)&v15, 0x10u);
  if ( (result & 0x80000000) != 0 )
  {
    v4 = *(_QWORD *)(a1 + 1544);
    v5 = result;
    v6 = hfi_feature_to_string(21);
    dev_err(v4 + 16, "Unable to %s feature %s (%d)\n", "enable", v6, 21);
    result = v5;
    goto LABEL_7;
  }
  if ( !(_DWORD)result )
  {
    v8[1] = 131073;
    v12 = 812122112;
    v13 = 0x100000000LL;
    v14 = 0x3200000000LL;
    v15 = 0;
    v29 = 0;
    v30 = 0;
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
    v16 = 0;
    result = gen7_hfi_send_cmd_wait_inline(a1, v8, 0x38u, (int *)&v15);
    if ( !(_DWORD)result )
    {
      if ( HIDWORD(v16) )
      {
        dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n", v16, HIDWORD(v16));
        gmu_core_fault_snapshot(a1, 6);
        result = 4294967274LL;
        goto LABEL_7;
      }
      goto LABEL_6;
    }
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
