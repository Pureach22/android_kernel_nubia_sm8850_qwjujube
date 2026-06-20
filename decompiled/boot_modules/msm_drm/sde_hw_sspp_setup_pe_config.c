__int64 __fastcall sde_hw_sspp_setup_pe_config(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w8
  int v6; // w24
  int v7; // w25
  int v8; // w21
  int v9; // w23
  int v10; // w10
  int v11; // w22
  int v12; // w9
  int v13; // w11
  int v14; // w20
  unsigned int v15; // w21
  int v16; // w11
  unsigned int v17; // w23
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  result = sspp_subblk_offset(a1, 1, &v18);
  if ( a2 && !(_DWORD)result )
  {
    v5 = *(unsigned __int8 *)(a2 + 196);
    v6 = *(unsigned __int8 *)(a2 + 228);
    v7 = *(unsigned __int8 *)(a2 + 200);
    v8 = (*(_DWORD *)(a2 + 180) << 24) | ((unsigned __int8)*(_DWORD *)(a2 + 244) << 16);
    v9 = (*(_DWORD *)(a2 + 184) << 24) | ((unsigned __int8)*(_DWORD *)(a2 + 248) << 16);
    v10 = (*(_DWORD *)(a2 + 148) << 24)
        | ((unsigned __int8)*(_DWORD *)(a2 + 212) << 16)
        | ((unsigned __int8)*(_DWORD *)(a2 + 132) << 8);
    v11 = (*(_DWORD *)(a2 + 152) << 24)
        | ((unsigned __int8)*(_DWORD *)(a2 + 216) << 16)
        | ((unsigned __int8)*(_DWORD *)(a2 + 136) << 8);
    v13 = *(_DWORD *)(a2 + 164);
    v12 = *(_DWORD *)(a2 + 168);
    v14 = *(unsigned __int8 *)(a2 + 232);
    v15 = v8 & 0xFFFF00FF | ((unsigned __int8)v13 << 8);
    v16 = v18;
    v17 = v9 & 0xFFFF00FF | ((unsigned __int8)v12 << 8);
    v18 += 4096;
    sde_reg_write(a1, v16 + 4132, v10 | v5, "SSPP_REC_SW_PIX_EXT_LR + idx");
    sde_reg_write(a1, v18 + 40, v15 | v6, "SSPP_REC_SW_PIX_EXT_TB + idx");
    sde_reg_write(a1, v18 + 64, v11 | v7, "SSPP_REC_SW_PIX_EXT_LR_ODX + idx");
    result = sde_reg_write(a1, v18 + 68, v17 | v14, "SSPP_REC_SW_PIX_EXT_TB_ODX + idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
