__int64 __fastcall hdd_update_country_code(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( country_code && (ucfg_reg_is_user_country_set_allowed(*a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
    return hdd_reg_set_country(a1, country_code);
  else
    return 0;
}
