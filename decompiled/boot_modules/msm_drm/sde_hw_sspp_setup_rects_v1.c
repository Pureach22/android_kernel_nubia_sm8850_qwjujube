__int64 __fastcall sde_hw_sspp_setup_rects_v1(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  int v7; // w8
  int v8; // w8
  int v9; // w12
  unsigned int v10; // w2
  unsigned int v11; // w25
  unsigned int v12; // w23
  unsigned int v13; // w24
  unsigned int v14; // w21
  unsigned int v15; // w20
  unsigned int v16; // w22
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  result = sspp_subblk_offset(a1, 1, &v17);
  if ( a2 && !(_DWORD)result )
  {
    if ( a3 >= 2 )
      v7 = 12288;
    else
      v7 = 4096;
    v8 = v17 + v7;
    v9 = *(_DWORD *)(*(_QWORD *)(a1 + 56) + 32LL);
    v11 = *(_DWORD *)(a2 + 72);
    v10 = *(_DWORD *)(a2 + 76);
    v12 = *(_DWORD *)(a2 + 80);
    v13 = *(_DWORD *)(a2 + 84);
    v14 = *(_DWORD *)(a2 + 56) | (*(_DWORD *)(a2 + 64) << 16);
    v15 = *(_DWORD *)(a2 + 60) | (*(_DWORD *)(a2 + 68) << 16);
    v17 = v8;
    if ( (v9 & 0x40000C) != 0 )
      v16 = ~(-1 << *(_BYTE *)(a2 + 105)) | (~(-1 << *(_BYTE *)(a2 + 104)) << 8);
    else
      v16 = 0;
    sde_reg_write(a1, v8 + 20, v10, "SSPP_REC_SRC_SIZE + idx");
    sde_reg_write(a1, v17 + 24, v11, "SSPP_REC_SRC_XY + idx");
    sde_reg_write(a1, v17 + 28, v13, "SSPP_REC_OUT_SIZE + idx");
    sde_reg_write(a1, v17 + 32, v12, "SSPP_REC_OUT_XY + idx");
    sde_reg_write(a1, v17 + 92, v14, "SSPP_REC_SRC_YSTRIDE0 + idx");
    sde_reg_write(a1, v17 + 96, v15, "SSPP_REC_SRC_YSTRIDE1 + idx");
    result = sde_reg_write(a1, v17 + 152, v16, "SSPP_REC_UBWC_STATS_ROI + idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
