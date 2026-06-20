__int64 __fastcall a6xx_hfi_send_lm_feature_ctrl(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8
  int v4; // w3
  int v5; // [xsp+4h] [xbp-9Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-98h] BYREF
  int v7; // [xsp+10h] [xbp-90h]
  int v8; // [xsp+14h] [xbp-8Ch]
  __int64 v9; // [xsp+18h] [xbp-88h] BYREF
  __int64 v10; // [xsp+20h] [xbp-80h]
  __int64 v11; // [xsp+28h] [xbp-78h]
  __int64 v12; // [xsp+30h] [xbp-70h]
  __int64 v13; // [xsp+38h] [xbp-68h]
  __int64 v14; // [xsp+40h] [xbp-60h]
  __int64 v15; // [xsp+48h] [xbp-58h]
  __int64 v16; // [xsp+50h] [xbp-50h]
  __int64 v17; // [xsp+58h] [xbp-48h]
  __int64 v18; // [xsp+60h] [xbp-40h]
  __int64 v19; // [xsp+68h] [xbp-38h]
  __int64 v20; // [xsp+70h] [xbp-30h]
  __int64 v21; // [xsp+78h] [xbp-28h]
  __int64 v22; // [xsp+80h] [xbp-20h]
  __int64 v23; // [xsp+88h] [xbp-18h]
  __int64 v24; // [xsp+90h] [xbp-10h]
  __int64 v25; // [xsp+98h] [xbp-8h]

  result = 0;
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int8 *)(a1 + 20432);
  v5 = 0;
  if ( v3 == 1 )
  {
    nvmem_cell_read_u32(*(_QWORD *)(a1 + 11168) + 16LL, "isense_slope", &v5);
    v4 = *(_DWORD *)(a1 + 10072);
    v6 = 0x730000000DLL;
    v7 = 0;
    v8 = v5;
    result = a6xx_hfi_send_feature_ctrl(a1, 7, 1, v4);
    if ( !(_DWORD)result )
    {
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
      v9 = 0;
      v10 = 0;
      result = a6xx_hfi_send_cmd_wait_inline(a1, (int *)&v6, 0x10u, (int *)&v9);
      if ( !(_DWORD)result )
      {
        if ( HIDWORD(v10) )
        {
          dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n", v10, HIDWORD(v10));
          gmu_core_fault_snapshot(a1, 6);
          result = 4294967274LL;
        }
        else
        {
          result = 0;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
