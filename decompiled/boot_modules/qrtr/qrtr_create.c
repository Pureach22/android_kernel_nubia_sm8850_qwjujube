__int64 __fastcall qrtr_create(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v5; // x0
  __int64 v6; // x20
  int v7; // w9
  unsigned int v8; // w8

  if ( *(_WORD *)(a2 + 4) != 2 )
    return 4294967205LL;
  v5 = sk_alloc(a1, 42, 3264, &qrtr_proto, a4);
  if ( !v5 )
    return 4294967284LL;
  v6 = v5;
  v7 = *(_DWORD *)(v5 + 552) | 0x4000;
  *(_QWORD *)(v5 + 96) |= 0x100uLL;
  *(_DWORD *)(v5 + 552) = v7;
  sock_init_data(a2, v5);
  *(_QWORD *)(a2 + 32) = &qrtr_proto_ops;
  v8 = qrtr_local_nid;
  *(_WORD *)(v6 + 840) = 42;
  *(_QWORD *)(v6 + 844) = v8;
  *(_DWORD *)(v6 + 864) = -1;
  *(_BYTE *)(v6 + 904) = 0;
  *(_DWORD *)(v6 + 872) = 0;
  _init_swait_queue_head(v6 + 880, "&x->wait", &init_completion___key);
  *(_DWORD *)(v6 + 908) = 0;
  return 0;
}
