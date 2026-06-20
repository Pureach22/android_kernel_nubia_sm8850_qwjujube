unsigned __int64 *__fastcall list_add_rcu(unsigned __int64 *result, unsigned __int64 *a2)
{
  unsigned __int64 *v2; // x2

  v2 = (unsigned __int64 *)*a2;
  if ( *(unsigned __int64 **)(*a2 + 8) != a2 || result == a2 || v2 == result )
    return (unsigned __int64 *)_list_add_valid_or_report(result, a2);
  *result = (unsigned __int64)v2;
  result[1] = (unsigned __int64)a2;
  atomic_store((unsigned __int64)result, a2);
  v2[1] = (unsigned __int64)result;
  return result;
}
