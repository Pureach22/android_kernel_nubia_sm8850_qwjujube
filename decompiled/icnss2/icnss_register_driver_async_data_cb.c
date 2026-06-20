__int64 __fastcall icnss_register_driver_async_data_cb(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x8

  v3 = *(_QWORD **)(a1 + 152);
  if ( !v3 )
    return 4294967277LL;
  if ( (v3[229] & 1) == 0 )
    return 4294967274LL;
  v3[685] = a3;
  v3[684] = a2;
  return 0;
}
