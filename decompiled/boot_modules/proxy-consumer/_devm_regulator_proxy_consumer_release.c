__int64 *__fastcall devm_regulator_proxy_consumer_release(__int64 a1, __int64 **a2)
{
  __int64 *result; // x0
  __int64 *v3; // x9

  result = *a2;
  v3 = (__int64 *)&proxy_consumer_list;
  while ( 1 )
  {
    v3 = (__int64 *)*v3;
    if ( v3 == (__int64 *)&proxy_consumer_list )
      break;
    if ( v3 == result )
      return (__int64 *)regulator_proxy_consumer_remove(result);
  }
  return result;
}
