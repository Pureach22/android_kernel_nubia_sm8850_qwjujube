__int64 __fastcall swr_port_response(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x8
  __int64 v4; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 8392);
  v4 = *(_QWORD *)(v2 + 8LL * a2);
  if ( v4 )
  {
    *(_QWORD *)(v2 + 8LL * a2) = 0;
    return kfree(v4);
  }
  else
  {
    result = __ratelimit(&swr_port_response__rs, "swr_port_response");
    if ( (_DWORD)result )
      return dev_err(a1, "%s: transaction is already NULL\n", "swr_port_response");
  }
  return result;
}
