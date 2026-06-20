__int64 __fastcall sub_4345B0(__int64 a1)
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return sme_set_idle_powersave_config(a1);
}
