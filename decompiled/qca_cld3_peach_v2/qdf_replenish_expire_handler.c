__int64 qdf_replenish_expire_handler()
{
  __int64 result; // x0

  if ( dword_7CF500 >= 51 )
    return qdf_trace_msg(
             56,
             2,
             "%s: ERROR: NBUF allocation timer expired Fail count %d",
             "qdf_replenish_expire_handler",
             dword_7CF500);
  return result;
}
