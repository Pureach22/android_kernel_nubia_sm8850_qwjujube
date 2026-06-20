__int64 __fastcall sde_hw_uidle_get_status_ext1(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0

  a2[10] = sde_reg_read(a1, 112);
  a2[14] = sde_reg_read(a1, 128);
  a2[11] = sde_reg_read(a1, 116);
  a2[15] = sde_reg_read(a1, 132);
  a2[12] = sde_reg_read(a1, 120);
  a2[16] = sde_reg_read(a1, 136);
  a2[13] = sde_reg_read(a1, 124);
  result = sde_reg_read(a1, 140);
  a2[17] = result;
  return result;
}
