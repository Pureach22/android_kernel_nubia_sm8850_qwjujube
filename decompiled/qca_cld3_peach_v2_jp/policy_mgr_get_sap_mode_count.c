__int64 __fastcall policy_mgr_get_sap_mode_count(__int64 a1, _DWORD *a2)
{
  int v4; // w0
  _DWORD *v5; // x2

  v4 = policy_mgr_mode_specific_connection_count(a1, 1, a2);
  if ( a2 )
    v5 = &a2[v4];
  else
    v5 = nullptr;
  return (unsigned int)policy_mgr_mode_specific_connection_count(a1, 6, v5) + v4;
}
