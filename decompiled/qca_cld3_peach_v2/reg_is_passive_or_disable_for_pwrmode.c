bool __fastcall reg_is_passive_or_disable_for_pwrmode(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  return (reg_get_channel_state_for_pwrmode(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) & 0xFFFFFFFD) == 0;
}
