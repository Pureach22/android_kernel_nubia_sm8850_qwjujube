__int64 __fastcall sde_hw_uidle_setup_ctl(__int64 a1, int *a2)
{
  int v4; // w0
  unsigned int v5; // w8
  int v6; // w9
  int v7; // w2
  unsigned int v8; // w19

  v4 = sde_reg_read(a1, 0);
  v5 = a2[3] - 1;
  v6 = *a2;
  v7 = v4 & 0x3F00FF88 | ((a2[3] == 1) << 30) | a2[2] & 7 | ((v5 < 2) << 31) | (16 * (a2[1] & 7));
  if ( v5 >= 2 )
    v8 = -2147483647;
  else
    v8 = 0;
  sde_reg_write(a1, 0, v7 & 0xFF00FFFF | ((unsigned __int8)v6 << 16), "UIDLE_CTL");
  return sde_reg_write(a1, 8, v8, "UIDLE_FAL10_VETO_OVERRIDE");
}
