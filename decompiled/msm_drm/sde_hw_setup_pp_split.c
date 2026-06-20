__int64 __fastcall sde_hw_setup_pp_split(__int64 result, __int64 a2)
{
  int v2; // w8
  bool v3; // zf
  int v4; // w8
  int v5; // w9
  int v6; // w10
  __int64 v7; // x22
  unsigned int v8; // w2
  unsigned int v9; // w19
  unsigned int v10; // w20
  unsigned int v11; // w21

  if ( result && a2 )
  {
    if ( *(_BYTE *)a2 == 1 )
    {
      v2 = *(_DWORD *)(a2 + 12);
      v3 = v2 == 10;
      if ( v2 == 10 )
        v4 = 0;
      else
        v4 = (v2 << 20) | 0x10000;
      if ( v3 )
        v5 = 0;
      else
        v5 = 32;
    }
    else
    {
      v4 = 0;
      v5 = 0;
    }
    v6 = *(_DWORD *)(a2 + 16);
    v7 = result;
    if ( v6 )
      v8 = 0;
    else
      v8 = v4;
    if ( v6 )
      v9 = 0;
    else
      v9 = v5;
    if ( v6 )
      v10 = v4;
    else
      v10 = 0;
    if ( v6 )
      v11 = v5;
    else
      v11 = 0;
    sde_reg_write(result, 0x334u, v8, "PPB0_CONFIG");
    sde_reg_write(v7, 0x330u, v9, "PPB0_CNTL");
    sde_reg_write(v7, 0x33Cu, v10, "PPB1_CONFIG");
    return sde_reg_write(v7, 0x338u, v11, "PPB1_CNTL");
  }
  return result;
}
