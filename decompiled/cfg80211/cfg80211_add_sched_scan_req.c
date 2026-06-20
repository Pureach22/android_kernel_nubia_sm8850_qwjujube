unsigned __int64 *__fastcall cfg80211_add_sched_scan_req(__int64 a1, __int64 a2)
{
  unsigned __int64 *result; // x0
  __int64 v3; // x2
  __int64 v4; // t1
  unsigned __int64 v5; // x8

  v4 = *(_QWORD *)(a1 + 248);
  result = (unsigned __int64 *)(a1 + 248);
  v3 = v4;
  v5 = a2 + 168;
  if ( *(unsigned __int64 **)(v4 + 8) != result || v5 == (_QWORD)result || v3 == v5 )
    return (unsigned __int64 *)_list_add_valid_or_report(v5, result);
  *(_QWORD *)(a2 + 168) = v3;
  *(_QWORD *)(a2 + 176) = result;
  atomic_store(v5, result);
  *(_QWORD *)(v3 + 8) = v5;
  return result;
}
