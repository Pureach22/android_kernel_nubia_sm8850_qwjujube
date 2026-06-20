__int64 __fastcall sde_hw_sspp_update_multirect_v1(__int64 a1, char a2, int a3, int a4)
{
  __int64 result; // x0
  int v9; // w0
  int v10; // w8
  unsigned int v11; // w2
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  result = sspp_subblk_offset(a1, 1, &v12);
  if ( !(_DWORD)result )
  {
    if ( a3 )
    {
      v9 = sde_reg_read(a1, v12 + 16);
      v10 = v9 | a3;
      if ( (a2 & 1) == 0 )
        v10 = v9 & ~a3;
      if ( a4 == 2 && (a2 & 1) != 0 )
        v11 = v10 | 4;
      else
        v11 = v10 & 0xFFFFFFFB;
    }
    else
    {
      v11 = 0;
    }
    result = sde_reg_write(a1, v12 + 16, v11, "SSPP_CMN_MULTI_REC_OP_MODE + idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
