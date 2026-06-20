__int64 __fastcall gen8_hfi_send_core_fw_start(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // [xsp+0h] [xbp-90h] BYREF
  __int64 v4; // [xsp+8h] [xbp-88h] BYREF
  __int64 v5; // [xsp+10h] [xbp-80h]
  __int64 v6; // [xsp+18h] [xbp-78h]
  __int64 v7; // [xsp+20h] [xbp-70h]
  __int64 v8; // [xsp+28h] [xbp-68h]
  __int64 v9; // [xsp+30h] [xbp-60h]
  __int64 v10; // [xsp+38h] [xbp-58h]
  __int64 v11; // [xsp+40h] [xbp-50h]
  __int64 v12; // [xsp+48h] [xbp-48h]
  __int64 v13; // [xsp+50h] [xbp-40h]
  __int64 v14; // [xsp+58h] [xbp-38h]
  __int64 v15; // [xsp+60h] [xbp-30h]
  __int64 v16; // [xsp+68h] [xbp-28h]
  __int64 v17; // [xsp+70h] [xbp-20h]
  __int64 v18; // [xsp+78h] [xbp-18h]
  __int64 v19; // [xsp+80h] [xbp-10h]
  __int64 v20; // [xsp+88h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 14;
  v4 = 0;
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
  v6 = 0;
  v7 = 0;
  v5 = 0;
  result = gen8_hfi_send_cmd_wait_inline(a1, (int *)&v3, 8u, (int *)&v4);
  if ( !(_DWORD)result )
  {
    if ( HIDWORD(v5) )
    {
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n", v5, HIDWORD(v5));
      gmu_core_fault_snapshot(a1, 6);
      result = 4294967274LL;
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
