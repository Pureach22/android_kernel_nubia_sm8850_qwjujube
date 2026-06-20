__int64 __fastcall slim_device_uevent(const char **a1, __int64 a2)
{
  const char *v2; // x2

  v2 = a1[14];
  if ( !v2 )
    v2 = *a1;
  return add_uevent_var(a2, "MODALIAS=slim:%s", v2);
}
