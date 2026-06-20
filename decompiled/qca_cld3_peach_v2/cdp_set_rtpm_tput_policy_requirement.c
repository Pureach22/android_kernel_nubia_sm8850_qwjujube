__int64 **__fastcall cdp_set_rtpm_tput_policy_requirement(
        __int64 **result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 (*v10)(void); // x8

  if ( !result || !*result )
    return (__int64 **)qdf_trace_msg(
                         0x89u,
                         8u,
                         "%s: Invalid Instance",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "cdp_set_rtpm_tput_policy_requirement");
  v9 = **result;
  if ( v9 )
  {
    v10 = *(__int64 (**)(void))(v9 + 888);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != -251540498 )
        __break(0x8228u);
      return (__int64 **)v10();
    }
  }
  return result;
}
