bool __fastcall policy_mgr_is_sta_active_connection_exists(__int64 a1)
{
  return (unsigned int)policy_mgr_mode_specific_connection_count(a1, 0, nullptr) != 0;
}
