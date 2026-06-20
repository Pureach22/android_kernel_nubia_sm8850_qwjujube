__int64 __fastcall sde_hw_uidle_setup_wd_timer(__int64 a1, __int64 a2)
{
  int v4; // w21
  int v5; // w22
  unsigned int v6; // w8
  int v7; // w10
  int v8; // w9
  unsigned int v9; // w22

  v4 = sde_reg_read(a1, 16);
  v5 = sde_reg_read(a1, 20);
  sde_reg_read(a1, 24);
  v6 = v5 & 0xFFFFFEE0 | *(_BYTE *)(a2 + 13) & 0xE1 | (2 * (*(_DWORD *)a2 & 0xF));
  v7 = *(unsigned __int8 *)(a2 + 12);
  v8 = *(_DWORD *)(a2 + 4) != 0;
  LODWORD(a2) = *(_DWORD *)(a2 + 8);
  v9 = v6 | (v8 << 8);
  sde_reg_write(a1, 16, v4 & 0xFFFFFFFE | v7, "UIDLE_WD_TIMER_CTL");
  sde_reg_write(a1, 20, v9, "UIDLE_WD_TIMER_CTL2");
  return sde_reg_write(a1, 24, (unsigned int)a2, "UIDLE_WD_TIMER_LOAD_VALUE");
}
