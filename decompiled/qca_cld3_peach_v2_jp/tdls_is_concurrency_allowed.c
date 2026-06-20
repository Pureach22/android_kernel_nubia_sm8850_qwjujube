__int64 __fastcall tdls_is_concurrency_allowed(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v9; // x2
  __int64 result; // x0

  if ( (*(_BYTE *)(a1 + 25) & 1) == 0 )
  {
    v9 = "%s: fw cap is not advertised";
LABEL_3:
    qdf_trace_msg(0, 8u, v9, a2, a3, a4, a5, a6, a7, a8, a9, "tdls_is_concurrency_allowed");
    return 0;
  }
  if ( (unsigned int)policy_mgr_get_connection_count_with_mlo(a1) > 3 )
    return 0;
  if ( (unsigned int)policy_mgr_mode_specific_connection_count_with_mlo(a1, 0) > 1 )
  {
    v9 = "%s: More than one STA exist. Don't allow TDLS";
    goto LABEL_3;
  }
  if ( (policy_mgr_is_mcc_on_any_sta_vdev(a1) & 1) != 0 )
  {
    v9 = "%s: Base channel MCC. Don't allow TDLS";
    goto LABEL_3;
  }
  if ( (unsigned int)policy_mgr_get_connection_count_with_mlo(a1) < 2
    || (result = policy_mgr_mode_specific_connection_count(a1, 0, nullptr), (_DWORD)result) )
  {
    if ( !(unsigned int)policy_mgr_get_ll_lt_sap_freq(a1) )
      return 1;
    v9 = "%s: XPAN is present, Don't allow TDLS";
    goto LABEL_3;
  }
  return result;
}
