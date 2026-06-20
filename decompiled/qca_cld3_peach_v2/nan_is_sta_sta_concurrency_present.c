__int64 __fastcall nan_is_sta_sta_concurrency_present(__int64 a1)
{
  __int64 result; // x0

  result = policy_mgr_mode_specific_connection_count(a1, 0, nullptr);
  if ( (_DWORD)result )
    return (unsigned int)result > 2 || (_DWORD)result == 2 && (policy_mgr_is_non_ml_sta_present(a1) & 1) != 0;
  return result;
}
