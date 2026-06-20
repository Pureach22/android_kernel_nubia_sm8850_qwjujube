__int64 __fastcall sde_debug_bus_lm_dump(__int64 result, int a2, int a3, int a4)
{
  if ( (a4 & 0xFFF000) != 0 )
    return dev_err(qword_2942C8, "%s 0x%x %d %d 0x%x\n", "lm", result, a2, a3, a4);
  return result;
}
