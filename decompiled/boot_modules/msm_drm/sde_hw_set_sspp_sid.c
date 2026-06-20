__int64 __fastcall sde_hw_set_sspp_sid(__int64 result, int a2, int a3, _DWORD *a4)
{
  int v4; // w8
  unsigned int v5; // w1
  int v6; // w8

  if ( result )
  {
    if ( a4[8] == 512 )
      v4 = 64;
    else
      v4 = 16;
    if ( (unsigned int)(a2 - 1) > 7 )
    {
      if ( (unsigned int)(a2 - 9) > 5 )
        return result;
      v5 = v4 + 4 * a2 - 36;
    }
    else
    {
      v5 = 4 * a2 - 4;
    }
    if ( *a4 >> 28 <= 0xCu )
      v6 = 0;
    else
      v6 = a3 << 10;
    return sde_reg_write(result, v5, v6 | (unsigned int)(4 * a3), "offset");
  }
  return result;
}
