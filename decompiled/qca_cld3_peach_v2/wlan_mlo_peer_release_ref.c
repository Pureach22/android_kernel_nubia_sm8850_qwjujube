__int64 __fastcall wlan_mlo_peer_release_ref(
        __int64 result,
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v18; // x2
  unsigned int v25; // w8
  unsigned int v26; // w8

  _X9 = (unsigned int *)(result + 188);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v25 = __ldxr(_X9);
    v26 = v25 - 1;
  }
  while ( __stlxr(v26, _X9) );
  __dmb(0xBu);
  if ( !v26 )
  {
    if ( result )
    {
      if ( *(_QWORD *)(result + 192) )
      {
        v9 = result;
        mlo_dev_mlpeer_detach(*(_QWORD *)(result + 192), result);
        return mlo_peer_free(v9, v10, v11, v12, v13, v14, v15, v16, v17);
      }
      v18 = "%s: ML DEV is NULL";
    }
    else
    {
      v18 = "%s: ML PEER is NULL";
    }
    return qdf_trace_msg(0x8Fu, 2u, v18, a2, a3, a4, a5, a6, a7, a8, a9, "mlo_peer_cleanup");
  }
  return result;
}
