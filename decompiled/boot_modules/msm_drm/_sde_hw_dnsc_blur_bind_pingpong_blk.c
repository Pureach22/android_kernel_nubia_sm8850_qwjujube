__int64 __fastcall sde_hw_dnsc_blur_bind_pingpong_blk(__int64 a1, char a2, unsigned int a3, char a4)
{
  int v4; // w8
  unsigned int v5; // w2

  if ( a3 - 14 <= 0xFFFFFFF2 && (a2 & 1) != 0 )
    return printk(&unk_274C74, 1);
  if ( a3 <= 8 && (a4 & 1) != 0 )
    return printk(&unk_21AB75, a3 - 1);
  if ( (a2 & 1) != 0 )
  {
    if ( a3 >= 0xB )
      v4 = 11;
    else
      v4 = 13;
    if ( (a4 & 1) != 0 )
      v5 = v4;
    else
      v5 = ((_BYTE)a3 - 1) & 7;
  }
  else
  {
    v5 = 15;
  }
  return sde_reg_write(a1, 0x24u, v5, "DNSC_BLUR_MUX");
}
