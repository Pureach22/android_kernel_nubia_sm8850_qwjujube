__int64 __fastcall tdls_is_concurrency_allowed(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  const char *v10; // x2
  __int64 result; // x0

  if ( (policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr) & 1) != 0 )
  {
    v10 = "%s: eMLSR STA present. Don't allow TDLS";
LABEL_5:
    qdf_trace_msg(0, 8u, v10, v2, v3, v4, v5, v6, v7, v8, v9, "tdls_is_concurrency_allowed");
    return 0;
  }
  if ( (*(_BYTE *)(a1 + 25) & 1) == 0 )
  {
    v10 = "%s: fw cap is not advertised";
    goto LABEL_5;
  }
  if ( (unsigned int)policy_mgr_get_connection_count_with_mlo(a1) > 3 )
    return 0;
  if ( (unsigned int)policy_mgr_mode_specific_connection_count_with_mlo(a1, 0) > 1 )
  {
    v10 = "%s: More than one STA exist. Don't allow TDLS";
    goto LABEL_5;
  }
  if ( (policy_mgr_is_mcc_on_any_sta_vdev(a1) & 1) != 0 )
  {
    v10 = "%s: Base channel MCC. Don't allow TDLS";
    goto LABEL_5;
  }
  if ( (unsigned int)policy_mgr_get_connection_count_with_mlo(a1) < 2
    || (result = policy_mgr_mode_specific_connection_count(a1, 0, nullptr), (_DWORD)result) )
  {
    if ( !(unsigned int)policy_mgr_get_ll_lt_sap_freq(a1) )
      return 1;
    v10 = "%s: XPAN is present, Don't allow TDLS";
    goto LABEL_5;
  }
  return result;
}
