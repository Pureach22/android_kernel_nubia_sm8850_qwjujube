__int64 __fastcall policy_mgr_get_beaconing_mode_count(__int64 a1, _DWORD *a2)
{
  int v4; // w0
  _DWORD *v5; // x2
  int v6; // w21
  _DWORD *v7; // x2

  v4 = policy_mgr_mode_specific_connection_count(a1, 1, a2);
  if ( a2 )
    v5 = &a2[v4];
  else
    v5 = nullptr;
  v6 = policy_mgr_mode_specific_connection_count(a1, 6, v5) + v4;
  if ( a2 )
    v7 = &a2[v6];
  else
    v7 = nullptr;
  return v6 + (unsigned int)policy_mgr_mode_specific_connection_count(a1, 3, v7);
}
