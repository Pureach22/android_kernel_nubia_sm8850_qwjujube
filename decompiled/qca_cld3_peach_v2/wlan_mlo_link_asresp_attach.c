__int64 __fastcall wlan_mlo_link_asresp_attach(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x8
  const char *v15; // x2
  __int64 v17; // x20
  __int64 v18; // x0

  if ( !a1 )
  {
    v15 = "%s:  ml peer is NULL";
LABEL_8:
    qdf_trace_msg(0x8Fu, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_mlo_link_asresp_attach");
    return 16;
  }
  if ( !a2 )
  {
    v15 = "%s:  ml peer or link peer pointer is NULL";
    ++*(_BYTE *)(a1 + 98);
    goto LABEL_8;
  }
  qdf_mutex_acquire(a1 + 120);
  if ( *(_QWORD *)(a1 + 16) == a2 )
  {
    v14 = 16;
    goto LABEL_10;
  }
  if ( *(_QWORD *)(a1 + 56) == a2 )
  {
    v14 = 56;
LABEL_10:
    v17 = a1 + v14;
    v18 = *(_QWORD *)(a1 + v14 + 24);
    ++*(_BYTE *)(a1 + 98);
    if ( v18 )
      _qdf_nbuf_free(v18);
    *(_QWORD *)(v17 + 24) = a3;
  }
  qdf_mutex_release(a1 + 120);
  return 0;
}
