__int64 __fastcall sde_hw_sspp_setup_uidle_v1(__int64 a1, _DWORD *a2, unsigned int a3)
{
  __int64 result; // x0
  int v7; // w10
  int v8; // w8
  int v9; // w0
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  result = sspp_subblk_offset(a1, 1, &v10);
  if ( !(_DWORD)result )
  {
    v7 = v10;
    if ( a3 >= 2 )
      v8 = 12288;
    else
      v8 = 4096;
    v10 += v8;
    v9 = sde_reg_read(a1, v7 + v8 + 140);
    result = sde_reg_write(
               a1,
               v10 + 140,
               v9 & 0x7000F0F0
             | ((unsigned __int8)(*a2 == 0) << 31)
             | (a2[1] << 20)
             | (a2[2] << 16)
             | (a2[3] << 8)
             | a2[4],
               "offset + idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
