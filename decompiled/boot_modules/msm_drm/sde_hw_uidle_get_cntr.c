__int64 __fastcall sde_hw_uidle_get_cntr(__int64 a1, _DWORD *a2)
{
  _DWORD *v2; // x20

  v2 = a2;
  *a2 = sde_reg_read(a1, 84);
  v2[1] = sde_reg_read(a1, 88);
  v2[2] = sde_reg_read(a1, 92);
  v2[3] = sde_reg_read(a1, 96);
  v2[4] = sde_reg_read(a1, 100);
  v2[5] = sde_reg_read(a1, 104);
  v2[6] = sde_reg_read(a1, 108);
  LODWORD(v2) = sde_reg_read(a1, 80);
  sde_reg_write(a1, 80, (unsigned int)v2 | 0x80000000, "UIDLE_GATE_CNTR_CTL");
  return sde_reg_write(a1, 80, (unsigned int)v2 & 0x7FFFFFFF, "UIDLE_GATE_CNTR_CTL");
}
