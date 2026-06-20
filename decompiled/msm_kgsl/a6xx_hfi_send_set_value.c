__int64 __fastcall a6xx_hfi_send_set_value(__int64 a1, int a2, int a3, int a4)
{
  int v8; // w0
  __int64 result; // x0
  int v10; // w8
  int v11; // w4
  unsigned int v12; // w19
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
  v13[0] = 13;
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
  v8 = a6xx_hfi_send_cmd_wait_inline(a1, v13, 0x10u, (int *)&v14);
  if ( v8 )
  {
    v10 = v8;
LABEL_7:
    v11 = a4;
    v12 = v10;
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Unable to set HFI Value %d, %d to %d, error = %d\n", a2, a3, v11, v10);
    result = v12;
    goto LABEL_4;
  }
  if ( HIDWORD(v15) )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n", v15, HIDWORD(v15));
    gmu_core_fault_snapshot(a1, 6);
    v10 = -22;
    goto LABEL_7;
  }
  result = 0;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
