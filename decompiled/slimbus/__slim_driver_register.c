__int64 __fastcall _slim_driver_register(_QWORD *a1, __int64 a2)
{
  if ( !a1[9] && !a1[26] || !*a1 )
    return 4294967274LL;
  a1[5] = &slimbus_bus;
  a1[6] = a2;
  return driver_register(a1 + 4);
}
