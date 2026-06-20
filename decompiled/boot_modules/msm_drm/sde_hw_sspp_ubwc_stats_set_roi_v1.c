__int64 __fastcall sde_hw_sspp_ubwc_stats_set_roi_v1(__int64 a1, unsigned int a2, unsigned __int16 *a3)
{
  __int64 result; // x0
  int v7; // w10
  int v8; // w8
  int v9; // w0
  unsigned int v10; // w20
  unsigned int v11; // w2
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  result = sspp_subblk_offset(a1, 1, &v12);
  if ( !(_DWORD)result )
  {
    v7 = v12;
    if ( a2 >= 2 )
      v8 = 12288;
    else
      v8 = 4096;
    v12 += v8;
    v9 = sde_reg_read(a1, v7 + v8 + 144);
    if ( a3 )
    {
      v10 = *a3;
      if ( *a3 )
      {
        if ( a3[1] )
        {
          v10 |= a3[1] << 16;
          v11 = v9 | 0x7000000;
        }
        else
        {
          v11 = v9 | 0x3000000;
        }
      }
      else
      {
        v11 = v9 | 0x1000000;
      }
    }
    else
    {
      v10 = 0;
      v11 = v9 & 0xF8FFFFFF;
    }
    sde_reg_write(a1, v12 + 144, v11, "SSPP_REC_UBWC_STATIC_CTRL + idx");
    result = sde_reg_write(a1, v12 + 152, v10, "SSPP_REC_UBWC_STATS_ROI + idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
