__int64 __fastcall gdsc_genpd_debug_hwctrl_fops_open(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  return simple_attr_open(a1, a2, gdsc_genpd_hwctrl_get, gdsc_genpd_hwctrl_set, "%llu\n", a6);
}
