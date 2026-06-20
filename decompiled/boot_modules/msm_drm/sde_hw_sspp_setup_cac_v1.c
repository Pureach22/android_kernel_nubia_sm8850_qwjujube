__int64 __fastcall sde_hw_sspp_setup_cac_v1(__int64 a1, int a2, char a3, int a4)
{
  __int64 result; // x0
  int v9; // w0
  unsigned int v10; // w8
  unsigned int v11; // w8
  int v12; // w9
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  result = sspp_subblk_offset(a1, 1, &v13);
  if ( (_DWORD)result )
    goto LABEL_14;
  v9 = sde_reg_read(a1, v13 + 32);
  switch ( a2 )
  {
    case 8:
      if ( (unsigned int)(*(_DWORD *)(a1 + 48) - 1) <= 7 )
      {
        v10 = v9 & (a4 << 24) | 0x10101;
        break;
      }
LABEL_8:
      v10 = v9 | 0x101;
      break;
    case 2:
      goto LABEL_8;
    case 1:
      v10 = v9 | 0x100;
      break;
    default:
      v10 = v9 & 0xF0FEFEFE | 0xF000000;
      break;
  }
  v11 = v10 & 0xFFFFEFFF;
  if ( (a3 & 1) != 0 )
    v12 = 4096;
  else
    v12 = 0;
  result = sde_reg_write(a1, v13 + 32, v11 | v12, "SSPP_CMN_CAC_CTRL + idx");
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
