__int64 __fastcall sde_hw_sspp_ubwc_stats_set_roi(__int64 result, unsigned int a2, unsigned __int16 *a3)
{
  __int64 v4; // x19
  int v5; // w22
  int v6; // w21
  int v7; // w23
  int v8; // w0
  unsigned int v9; // w2

  if ( result )
  {
    v4 = result;
    if ( a2 >= 2 )
      v5 = 180;
    else
      v5 = 124;
    v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    if ( a2 >= 2 )
      v7 = 448;
    else
      v7 = 68;
    v8 = sde_reg_read(result, v6 + v7);
    if ( a3 )
    {
      if ( *a3 )
      {
        if ( a3[1] )
          v9 = v8 | 0x7000000;
        else
          v9 = v8 | 0x3000000;
        if ( a3[1] )
          LODWORD(a3) = *a3 | (a3[1] << 16);
        else
          LODWORD(a3) = *a3;
      }
      else
      {
        LODWORD(a3) = 0;
        v9 = v8 | 0x1000000;
      }
    }
    else
    {
      v9 = v8 & 0xF8FFFFFF;
    }
    sde_reg_write(v4, v6 + v7, v9, "ctrl_off");
    return sde_reg_write(v4, v6 + v5, (unsigned int)a3, "roi_off");
  }
  return result;
}
