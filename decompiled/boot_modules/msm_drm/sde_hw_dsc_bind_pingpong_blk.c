__int64 __fastcall sde_hw_dsc_bind_pingpong_blk(__int64 result, char a2, char a3)
{
  int v3; // w8
  unsigned int v4; // w8
  unsigned int v5; // w2

  if ( result )
  {
    v3 = *(_DWORD *)(result + 32);
    if ( (unsigned int)(v3 - 9) >= 0xFFFFFFF8 )
    {
      v4 = -1020 * v3 + 7164;
      if ( v4 )
      {
        if ( (a2 & 1) != 0 )
          v5 = (a3 - 1) & 7;
        else
          v5 = 15;
        return sde_reg_write(result, v4, v5, "dsc_ctl_offset");
      }
    }
  }
  return result;
}
