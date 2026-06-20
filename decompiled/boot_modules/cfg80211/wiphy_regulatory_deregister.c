_UNKNOWN **__fastcall wiphy_regulatory_deregister(__int64 a1)
{
  _DWORD *v2; // x20
  _UNKNOWN **result; // x0

  v2 = last_request;
  result = *(_UNKNOWN ***)(a1 + 384);
  if ( result )
    result = (_UNKNOWN **)kvfree_call_rcu(result, result);
  *(_QWORD *)(a1 + 384) = 0;
  if ( v2 )
  {
    result = wiphy_idx_to_wiphy((unsigned int)v2[4]);
    if ( result )
    {
      if ( result == (_UNKNOWN **)a1 )
      {
        v2[10] = 0;
        v2[4] = -1;
      }
    }
  }
  return result;
}
