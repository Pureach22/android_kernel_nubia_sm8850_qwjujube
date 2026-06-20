__int64 __fastcall qdf_try_allowing_sleep(__int64 result)
{
  if ( (_DWORD)result == 1 )
    --persistent_timer_count;
  return result;
}
