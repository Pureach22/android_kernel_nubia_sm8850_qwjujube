__int64 __fastcall epping_destroy_adapter(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  __int64 v11; // x20
  int v12; // w8
  __int64 result; // x0
  __int64 v14; // x8
  __int64 *v15; // x0
  __int64 *v16; // x9

  if ( !a1 )
    return qdf_trace_msg(0x33u, 1u, "%s: adapter = NULL\n", a2, a3, a4, a5, a6, a7, a8, a9, "epping_destroy_adapter");
  v9 = *a1;
  if ( !*a1 )
    return qdf_trace_msg(0x33u, 1u, "%s: adapter = NULL\n", a2, a3, a4, a5, a6, a7, a8, a9, "epping_destroy_adapter");
  v11 = a1[2];
  epping_stop_adapter(a1);
  if ( *((_BYTE *)a1 + 132) == 1 )
  {
    unregister_netdev(a1[2]);
    *((_BYTE *)a1 + 132) = 0;
  }
  timer_delete_sync(a1 + 9);
  v12 = *((_DWORD *)a1 + 16);
  *((_DWORD *)a1 + 32) = 0;
  while ( v12 )
  {
    v15 = (__int64 *)a1[6];
    if ( v15 )
    {
      v16 = (__int64 *)a1[7];
      *((_DWORD *)a1 + 16) = v12 - 1;
      if ( v15 == v16 )
      {
        v14 = 0;
        a1[7] = 0;
      }
      else
      {
        v14 = *v15;
      }
      a1[6] = v14;
      *v15 = 0;
      _qdf_nbuf_free((__int64)v15);
      v12 = *((_DWORD *)a1 + 16);
    }
  }
  result = free_netdev(v11);
  *(_QWORD *)(v9 + 48) = 0;
  return result;
}
