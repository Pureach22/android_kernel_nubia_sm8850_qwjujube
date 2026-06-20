__int64 __fastcall gen8_hfi_send_clx_feature_ctrl(__int64 a1)
{
  __int64 *v2; // x8
  __int64 v3; // x10
  __int64 v4; // x11
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x8
  __int64 v8; // x11
  _QWORD *v9; // t2
  __int64 result; // x0
  __int64 v11; // x20
  unsigned int v12; // w19
  const char *v13; // x0
  _QWORD v14[2]; // [xsp+0h] [xbp-D0h] BYREF
  int v15[2]; // [xsp+10h] [xbp-C0h] BYREF
  __int64 v16; // [xsp+18h] [xbp-B8h]
  __int64 v17; // [xsp+20h] [xbp-B0h]
  __int64 v18; // [xsp+28h] [xbp-A8h]
  __int64 v19; // [xsp+30h] [xbp-A0h]
  __int64 v20; // [xsp+38h] [xbp-98h]
  __int64 v21; // [xsp+40h] [xbp-90h]
  __int64 v22; // [xsp+48h] [xbp-88h] BYREF
  __int64 v23; // [xsp+50h] [xbp-80h]
  __int64 v24; // [xsp+58h] [xbp-78h]
  __int64 v25; // [xsp+60h] [xbp-70h]
  __int64 v26; // [xsp+68h] [xbp-68h]
  __int64 v27; // [xsp+70h] [xbp-60h]
  __int64 v28; // [xsp+78h] [xbp-58h]
  __int64 v29; // [xsp+80h] [xbp-50h]
  __int64 v30; // [xsp+88h] [xbp-48h]
  __int64 v31; // [xsp+90h] [xbp-40h]
  __int64 v32; // [xsp+98h] [xbp-38h]
  __int64 v33; // [xsp+A0h] [xbp-30h]
  __int64 v34; // [xsp+A8h] [xbp-28h]
  __int64 v35; // [xsp+B0h] [xbp-20h]
  __int64 v36; // [xsp+B8h] [xbp-18h]
  __int64 v37; // [xsp+C0h] [xbp-10h]
  __int64 v38; // [xsp+C8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 20438) == 1 )
  {
    v2 = *(__int64 **)(*(_QWORD *)(a1 + 14264) + 264LL);
    if ( v2 )
    {
      v3 = v2[5];
      v4 = v2[6];
      v19 = v2[4];
      v20 = v3;
      v5 = *v2;
      v6 = v2[1];
      v21 = v4;
      v9 = v2 + 2;
      v7 = v2[2];
      v8 = v9[1];
      v36 = 0;
      v37 = 0;
      v15[1] = HIDWORD(v5);
      v16 = v6;
      v15[0] = 8;
      v17 = v7;
      v18 = v8;
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
      v22 = 0;
      v23 = 0;
      v14[0] = 0x150000000BLL;
      v14[1] = 1;
      result = gen8_hfi_send_generic_req_v5(a1, (int *)v14, (int *)&v22, 0x10u);
      if ( (result & 0x80000000) != 0 )
      {
        v11 = *(_QWORD *)(a1 + 1544);
        v12 = result;
        v13 = hfi_feature_to_string(21);
        dev_err(v11 + 16, "Unable to %s feature %s (%d)\n", "enable", v13, 21);
        result = v12;
      }
      else if ( !(_DWORD)result )
      {
        v36 = 0;
        v37 = 0;
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
        v22 = 0;
        v23 = 0;
        result = gen8_hfi_send_cmd_wait_inline(a1, v15, 0x38u, (int *)&v22);
        if ( !(_DWORD)result )
        {
          if ( HIDWORD(v23) )
          {
            dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n", v23, HIDWORD(v23));
            gmu_core_fault_snapshot(a1, 6);
            result = 4294967274LL;
          }
          else
          {
            result = gen8_hfi_send_iff_pclx_feature_ctrl((_QWORD *)a1);
          }
        }
      }
    }
    else
    {
      result = 0;
      __break(0x800u);
      *(_BYTE *)(a1 + 20438) = 0;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
