const char *__fastcall qdf_wake_lock_name(__int64 a1)
{
  if ( a1 )
    return *(const char **)a1;
  else
    return "UNNAMED_WAKELOCK";
}
