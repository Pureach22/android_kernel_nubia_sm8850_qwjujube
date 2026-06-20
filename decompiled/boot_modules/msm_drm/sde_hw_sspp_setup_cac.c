__int64 __fastcall sde_hw_sspp_setup_cac(__int64 result, int a2, char a3, int a4)
{
  __int64 v7; // x19
  int v8; // w23
  int v9; // w0
  unsigned int v10; // w9
  int v11; // w8
  unsigned int v12; // w8
  int v13; // w9

  if ( result )
  {
    v7 = result;
    v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    v9 = sde_reg_read(result, v8 + 808);
    if ( a2 == 8 )
    {
      v11 = v9 | 0x101;
      if ( (unsigned int)(*(_DWORD *)(v7 + 48) - 1) <= 7 )
        v11 = v9 & (a4 << 24) | 0x10101;
    }
    else
    {
      v10 = v9 & 0xF0FEFEFE | 0xF000000;
      v11 = v9 | 0x101;
      if ( a2 == 1 )
        v10 = v9 | 0x100;
      if ( a2 != 2 )
        v11 = v10;
    }
    v12 = v11 & 0xFFFFEFFF;
    if ( (a3 & 1) != 0 )
      v13 = 4096;
    else
      v13 = 0;
    return sde_reg_write(v7, v8 + 808, v12 | v13, "SSPP_CAC_CTRL + idx");
  }
  return result;
}
