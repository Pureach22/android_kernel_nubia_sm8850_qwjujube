bool __fastcall policy_mgr_is_multiple_active_sta_sessions(__int64 a1)
{
  return (unsigned int)policy_mgr_mode_specific_connection_count(a1, 0, nullptr) > 1;
}
