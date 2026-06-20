bool __fastcall nan_is_sta_sta_concurrency_present(__int64 a1)
{
  return (unsigned int)policy_mgr_mode_specific_connection_count(a1, 0, nullptr) > 1;
}
