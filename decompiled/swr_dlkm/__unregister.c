__int64 __fastcall _unregister(__int64 a1)
{
  if ( a1 && a1 != 72 )
    device_unregister(a1);
  return 0;
}
