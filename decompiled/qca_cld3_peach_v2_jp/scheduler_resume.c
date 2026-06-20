__int64 __fastcall scheduler_resume(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x1

  result = scheduler_get_context(a1);
  if ( result )
    return qdf_event_set(result + 624, v2);
  return result;
}
