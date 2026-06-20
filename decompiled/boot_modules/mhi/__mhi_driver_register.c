__int64 __fastcall _mhi_driver_register(_QWORD *a1, __int64 a2)
{
  if ( !a1[1] || !a1[2] )
    return 4294967274LL;
  a1[7] = mhi_bus_type;
  a1[8] = a2;
  a1[13] = mhi_driver_probe;
  a1[15] = mhi_driver_remove;
  return driver_register(a1 + 6);
}
