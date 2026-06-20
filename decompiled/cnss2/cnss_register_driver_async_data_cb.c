__int64 __fastcall cnss_register_driver_async_data_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v7; // x8

  v5 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( !v5 )
    return 4294967277LL;
  if ( (*(_QWORD *)(v5 + 552) & 1) == 0 )
    return 4294967274LL;
  v7 = v5;
  *(_QWORD *)(v7 + 7480) = a3;
  *(_QWORD *)(v7 + 7472) = a2;
  return 0;
}
