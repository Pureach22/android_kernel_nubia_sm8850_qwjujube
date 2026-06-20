__int64 __fastcall wlan_crypto_pmksa_flush(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x20
  void *v11; // x0

  v9 = 0;
  v10 = a1 + 24;
  do
  {
    v11 = *(void **)(v10 + v9);
    if ( v11 )
    {
      qdf_mem_set(v11, 0x98u, 0);
      _qdf_mem_free(*(_QWORD *)(v10 + v9));
      *(_QWORD *)(v10 + v9) = 0;
    }
    v9 += 8;
  }
  while ( v9 != 128 );
  qdf_trace_msg(0x1Cu, 8u, "%s: Flushed the pmksa table", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_crypto_pmksa_flush");
  return 0;
}
