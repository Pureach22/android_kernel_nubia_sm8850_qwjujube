__int64 __fastcall policy_mgr_clear_concurrent_session_count(__int64 a1)
{
  __int64 result; // x0

  result = policy_mgr_get_context(a1);
  if ( result )
  {
    *(_BYTE *)(result + 1005) = 0;
    *(_QWORD *)(result + 989) = 0;
    *(_QWORD *)(result + 997) = 0;
  }
  return result;
}
