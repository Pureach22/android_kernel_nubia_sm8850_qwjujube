__int64 __fastcall policy_mgr_get_rd_type(__int64 a1)
{
  __int64 result; // x0

  result = policy_mgr_get_context(a1);
  if ( result )
    return *(unsigned int *)(result + 1660);
  return result;
}
