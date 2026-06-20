__int64 __fastcall sde_hw_uidle_get_status(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0

  *a2 = sde_reg_read(a1, 32);
  a2[1] = sde_reg_read(a1, 36);
  a2[2] = sde_reg_read(a1, 48);
  a2[3] = sde_reg_read(a1, 52);
  a2[4] = sde_reg_read(a1, 56);
  a2[5] = sde_reg_read(a1, 60);
  a2[6] = sde_reg_read(a1, 64);
  a2[7] = sde_reg_read(a1, 68);
  result = sde_reg_read(a1, 4);
  a2[8] = result;
  a2[9] = ((unsigned int)result >> 2) & 1;
  return result;
}
