__int64 __fastcall policy_mgr_get_sap_mode_info(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned int mode_specific_conn_info; // w0
  unsigned __int64 v7; // x1
  unsigned __int64 v8; // x2

  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, a2, a3, 1u);
  if ( a2 )
    v7 = a2 + 4LL * mode_specific_conn_info;
  else
    v7 = 0;
  if ( a3 )
    v8 = a3 + mode_specific_conn_info;
  else
    v8 = 0;
  return (unsigned int)policy_mgr_get_mode_specific_conn_info(a1, v7, v8, 6u) + mode_specific_conn_info;
}
