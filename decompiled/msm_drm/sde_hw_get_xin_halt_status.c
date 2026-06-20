unsigned __int64 __fastcall sde_hw_get_xin_halt_status(__int64 a1, char a2)
{
  return ((unsigned __int64)((unsigned int)sde_reg_read(a1, 0x204u) >> 16) >> a2) & 1;
}
