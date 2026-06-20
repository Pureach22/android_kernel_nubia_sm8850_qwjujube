__int64 __fastcall sde_hw_sspp_setup_img_size_v1(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w8
  unsigned int v6; // w2
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  result = sspp_subblk_offset(a1, 1, &v7);
  if ( !(_DWORD)result )
  {
    v5 = v7;
    v6 = *(_DWORD *)(a2 + 4);
    v7 += 4096;
    result = sde_reg_write(a1, v5 + 4112, v6, "SSPP_REC_SRC_IMG_SIZE + idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
