__int64 __fastcall sde_hw_sspp_setup_pe_config_0(__int64 result, __int64 a2, char a3)
{
  __int64 v4; // x19
  __int64 v5; // x8
  __int64 v6; // x9
  int v7; // w21
  __int64 v8; // x9
  int v9; // w13
  int v10; // w17
  int v11; // w16
  unsigned __int16 v12; // w15
  __int64 v13; // [xsp+8h] [xbp-38h]
  __int64 v14; // [xsp+10h] [xbp-30h]
  __int64 v15; // [xsp+18h] [xbp-28h]
  __int64 v16; // [xsp+20h] [xbp-20h]
  __int64 v17; // [xsp+28h] [xbp-18h]
  __int64 v18; // [xsp+30h] [xbp-10h]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    if ( a2 )
    {
      v4 = result;
      v5 = 0;
      v6 = *(_QWORD *)(*(_QWORD *)(result + 56) + 48LL);
      v17 = 0;
      v18 = 0;
      v15 = 0;
      v16 = 0;
      v7 = *(_DWORD *)(v6 + 72);
      v8 = a2 + 276;
      v13 = 0;
      v14 = 0;
      do
      {
        v9 = *(unsigned __int8 *)(v8 + v5 - 48);
        v10 = *(_DWORD *)(v8 + v5 - 176) + *(_DWORD *)(v8 + v5) + *(_DWORD *)(v8 + v5 - 160);
        v11 = (*(_DWORD *)(v8 + v5 - 96) << 24)
            | ((unsigned __int8)*(_DWORD *)(v8 + v5 - 32) << 16)
            | ((unsigned __int8)*(_DWORD *)(v8 + v5 - 112) << 8);
        v12 = *(_WORD *)(v8 + v5 - 208) + *(_WORD *)(v8 + v5 - 16) + *(_DWORD *)(v8 + v5 - 192);
        *(_DWORD *)((char *)&v17 + v5) = (*(_DWORD *)(v8 + v5 - 128) << 24)
                                       | ((unsigned __int8)*(_DWORD *)(v8 + v5 - 64) << 16)
                                       | ((unsigned __int8)*(_DWORD *)(v8 + v5 - 144) << 8)
                                       | *(unsigned __int8 *)(v8 + v5 - 80);
        *(_DWORD *)((char *)&v15 + v5) = v11 | v9;
        *(_DWORD *)((char *)&v13 + v5) = v12 | ((unsigned __int16)v10 << 16);
        v5 += 4;
      }
      while ( v5 != 16 );
      sde_reg_write(result, v7 + 256, v17, "SSPP_SW_PIX_EXT_C0_LR + idx");
      sde_reg_write(v4, v7 + 260, v15, "SSPP_SW_PIX_EXT_C0_TB + idx");
      sde_reg_write(v4, v7 + 264, v13, "SSPP_SW_PIX_EXT_C0_REQ_PIXELS + idx");
      sde_reg_write(v4, v7 + 272, HIDWORD(v17), "SSPP_SW_PIX_EXT_C1C2_LR + idx");
      sde_reg_write(v4, v7 + 276, HIDWORD(v15), "SSPP_SW_PIX_EXT_C1C2_TB + idx");
      sde_reg_write(v4, v7 + 280, HIDWORD(v13), "SSPP_SW_PIX_EXT_C1C2_REQ_PIXELS + idx");
      sde_reg_write(v4, v7 + 288, HIDWORD(v18), "SSPP_SW_PIX_EXT_C3_LR + idx");
      sde_reg_write(v4, v7 + 292, HIDWORD(v16), "SSPP_SW_PIX_EXT_C3_TB + idx");
      result = sde_reg_write(v4, v7 + 296, HIDWORD(v14), "SSPP_SW_PIX_EXT_C3_REQ_PIXELS + idx");
      if ( (a3 & 1) != 0 )
      {
        sde_reg_write(v4, v7 + 800, v18, "SSPP_SW_PIX_EXT_C2_LR + idx");
        result = sde_reg_write(v4, v7 + 804, v16, "SSPP_SW_PIX_EXT_C2_TB + idx");
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
