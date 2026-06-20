__int64 __fastcall gen7_hfi_send_generic_req_v5(__int64 a1, int *a2, int *a3, unsigned int a4)
{
  __int64 result; // x0
  int v7; // w4
  __int64 v8; // [xsp+8h] [xbp-88h] BYREF
  __int64 v9; // [xsp+10h] [xbp-80h]
  __int64 v10; // [xsp+18h] [xbp-78h]
  __int64 v11; // [xsp+20h] [xbp-70h]
  __int64 v12; // [xsp+28h] [xbp-68h]
  __int64 v13; // [xsp+30h] [xbp-60h]
  __int64 v14; // [xsp+38h] [xbp-58h]
  __int64 v15; // [xsp+40h] [xbp-50h]
  __int64 v16; // [xsp+48h] [xbp-48h]
  __int64 v17; // [xsp+50h] [xbp-40h]
  __int64 v18; // [xsp+58h] [xbp-38h]
  __int64 v19; // [xsp+60h] [xbp-30h]
  __int64 v20; // [xsp+68h] [xbp-28h]
  __int64 v21; // [xsp+70h] [xbp-20h]
  __int64 v22; // [xsp+78h] [xbp-18h]
  __int64 v23; // [xsp+80h] [xbp-10h]
  __int64 v24; // [xsp+88h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (HIWORD(*(_DWORD *)(a1 + 8280)) & 0xFFFu) > 4 )
  {
    result = gen7_hfi_send_cmd_wait_inline(a1, a2, a4, a3);
    if ( (_DWORD)result )
      goto LABEL_6;
    v7 = a3[4];
    switch ( v7 )
    {
      case 8:
        result = 4294967294LL;
        goto LABEL_6;
      case 6:
LABEL_15:
        result = 4294967274LL;
        goto LABEL_6;
      case 0:
        result = (unsigned int)a3[3];
        goto LABEL_6;
    }
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "HFI ACK: Req=0x%8.8X, Result=0x%8.8X Error:0x%8.8X\n", a3[2], a3[3], v7);
LABEL_14:
    gmu_core_fault_snapshot(a1, 6);
    goto LABEL_15;
  }
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
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  result = gen7_hfi_send_cmd_wait_inline(a1, a2, a4, (int *)&v8);
  if ( !(_DWORD)result )
  {
    if ( !HIDWORD(v9) )
    {
      result = 0;
      goto LABEL_6;
    }
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n", v9, HIDWORD(v9));
    goto LABEL_14;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
