__int64 __fastcall sde_hw_set_limit_conf(__int64 a1, int a2, char a3, int a4)
{
  int v4; // w22
  unsigned int v5; // w23
  char v6; // w21
  int v9; // w0

  if ( (a3 & 1) != 0 )
    v4 = 176;
  else
    v4 = 192;
  v5 = a2 & 0xFFFFFFFC;
  v6 = 8 * (a2 & 3);
  v9 = sde_reg_read(a1, v4 + (a2 & 0xFFFFFFFC));
  return sde_reg_write(a1, v4 + v5, v9 & ~(255 << v6) | (unsigned int)(a4 << v6), "reg_off");
}
