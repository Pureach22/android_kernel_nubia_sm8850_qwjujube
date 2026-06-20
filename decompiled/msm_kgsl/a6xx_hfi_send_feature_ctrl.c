__int64 __fastcall a6xx_hfi_send_feature_ctrl(__int64 a1, int a2, int a3, int a4)
{
  unsigned int v7; // w0
  __int64 result; // x0
  unsigned int v9; // w22
  __int64 v10; // x21
  const char *v11; // x20
  const char *v12; // x0
  int v13[4]; // [xsp+8h] [xbp-98h] BYREF
  __int64 v14; // [xsp+18h] [xbp-88h] BYREF
  __int64 v15; // [xsp+20h] [xbp-80h]
  __int64 v16; // [xsp+28h] [xbp-78h]
  __int64 v17; // [xsp+30h] [xbp-70h]
  __int64 v18; // [xsp+38h] [xbp-68h]
  __int64 v19; // [xsp+40h] [xbp-60h]
  __int64 v20; // [xsp+48h] [xbp-58h]
  __int64 v21; // [xsp+50h] [xbp-50h]
  __int64 v22; // [xsp+58h] [xbp-48h]
  __int64 v23; // [xsp+60h] [xbp-40h]
  __int64 v24; // [xsp+68h] [xbp-38h]
  __int64 v25; // [xsp+70h] [xbp-30h]
  __int64 v26; // [xsp+78h] [xbp-28h]
  __int64 v27; // [xsp+80h] [xbp-20h]
  __int64 v28; // [xsp+88h] [xbp-18h]
  __int64 v29; // [xsp+90h] [xbp-10h]
  __int64 v30; // [xsp+98h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[2] = a3;
  v13[3] = a4;
  v13[0] = 11;
  v13[1] = a2;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v7 = a6xx_hfi_send_cmd_wait_inline(a1, v13, 0x10u, (int *)&v14);
  if ( v7 )
  {
    v9 = v7;
  }
  else
  {
    if ( !HIDWORD(v15) )
    {
      result = 0;
      goto LABEL_4;
    }
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n", v15, HIDWORD(v15));
    gmu_core_fault_snapshot(a1, 6);
    v9 = -22;
  }
  v10 = *(_QWORD *)(a1 + 1544);
  if ( a3 )
    v11 = "enable";
  else
    v11 = "disable";
  v12 = hfi_feature_to_string(a2);
  dev_err(v10 + 16, "Unable to %s feature %s (%d)\n", v11, v12, a2);
  result = v9;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
