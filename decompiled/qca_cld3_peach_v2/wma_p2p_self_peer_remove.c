__int64 __fastcall wma_p2p_self_peer_remove(
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
  _QWORD *context; // x0
  _QWORD *v11; // x20
  __int64 v12; // x0
  const void *v13; // x1
  char v14; // w8
  __int64 v15; // x19

  context = _cds_get_context(54, (__int64)"wma_p2p_self_peer_remove", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4;
  v11 = context;
  v12 = _qdf_mem_malloc(0x18u, "wma_p2p_self_peer_remove", 599);
  if ( !v12 )
    return 2;
  *(_QWORD *)(v12 + 16) = a1;
  v13 = (const void *)(a1 + 74);
  v14 = *(_BYTE *)(a1 + 168);
  v15 = v12;
  *(_BYTE *)(v12 + 6) = v14;
  qdf_mem_copy((void *)v12, v13, 6u);
  return wma_self_peer_remove(v11, v15);
}
