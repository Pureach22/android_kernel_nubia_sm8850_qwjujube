__int64 __fastcall sde_hw_intf_bind_pingpong_blk(__int64 result, char a2, char a3)
{
  __int64 v3; // x19
  int v5; // w8
  unsigned int v6; // w8
  __int64 v7; // x2

  if ( result )
  {
    if ( (a2 & 1) != 0 )
    {
      v3 = result;
      v5 = sde_reg_read(result, 604) & 0xFFFFFFF0;
      result = v3;
      v6 = v5 & 0xFFFFFFF8 | (a3 - 1) & 7;
      if ( *(_BYTE *)(v3 + 77) )
        v7 = 0x10000;
      else
        v7 = v6;
    }
    else
    {
      v7 = 983055;
    }
    return sde_reg_write(result, 604, v7, "INTF_MUX");
  }
  return result;
}
