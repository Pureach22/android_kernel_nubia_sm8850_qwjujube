__int64 __fastcall sde_hw_sspp_setup_line_insertion(__int64 result, unsigned int a2, __int64 a3)
{
  bool v4; // cf
  unsigned int v5; // w1
  unsigned int v6; // w20
  unsigned int v7; // w2
  __int64 v8; // x21

  if ( result && a3 )
  {
    v4 = a2 >= 2;
    if ( a2 >= 2 )
      v5 = 484;
    else
      v5 = 480;
    if ( v4 )
      v6 = 492;
    else
      v6 = 488;
    if ( *(_BYTE *)a3 == 1 )
      v7 = (*(_DWORD *)(a3 + 4) << 16) | (*(_DWORD *)(a3 + 8) << 8) | *(_DWORD *)(a3 + 12) | 0x80000000;
    else
      v7 = 0;
    v8 = result;
    sde_reg_write(result, v5, v7, "ctl_off");
    return sde_reg_write(v8, v6, *(_DWORD *)(a3 + 16) << 16, "size_off");
  }
  return result;
}
