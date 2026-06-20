__int64 __fastcall sde_hw_sspp_setup_excl_rect(__int64 result, unsigned int *a2, unsigned int a3)
{
  unsigned int v3; // w19
  unsigned int v4; // w20
  int v5; // w23
  int v6; // w22
  int v7; // w8
  int v8; // w24
  int v9; // w25
  __int64 v10; // x21
  const char *v11; // x3
  unsigned int v12; // w1
  __int64 v13; // x0
  unsigned int v14; // w2

  if ( result && a2 )
  {
    v3 = *a2;
    v4 = a2[1];
    if ( a3 >= 2 )
      v5 = 392;
    else
      v5 = 440;
    v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    v7 = 1;
    if ( a3 >= 2 )
      v8 = 388;
    else
      v8 = 436;
    if ( a3 < 2 )
      v9 = 1;
    else
      v9 = 2;
    v10 = result;
    if ( a3 )
      v7 = sde_reg_read(result, v6 + 64);
    v11 = "SSPP_EXCL_REC_CTL + idx";
    if ( v4 )
    {
      sde_reg_write(v10, v6 + 64, v7 | v9, "SSPP_EXCL_REC_CTL + idx");
      sde_reg_write(v10, v6 + v8, v4, "reg_size + idx");
      v11 = "reg_xy + idx";
      v12 = v6 + v5;
      v13 = v10;
      v14 = v3;
    }
    else
    {
      v12 = v6 + 64;
      v14 = v7 & ~v9;
      v13 = v10;
    }
    return sde_reg_write(v13, v12, v14, v11);
  }
  return result;
}
