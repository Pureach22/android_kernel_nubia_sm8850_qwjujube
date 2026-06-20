__int64 __fastcall wma_process_set_mimops_req(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w4
  int v13; // w4
  int v15; // [xsp+0h] [xbp-10h]
  int v16; // [xsp+8h] [xbp-8h]

  v10 = *(_DWORD *)a2;
  if ( *(_DWORD *)a2 == 3 )
  {
    v13 = 0;
    goto LABEL_7;
  }
  if ( v10 == 1 )
  {
    v13 = 2;
    goto LABEL_7;
  }
  if ( !v10 )
  {
    v13 = 1;
LABEL_7:
    *(_DWORD *)a2 = v13;
  }
  v16 = *(unsigned __int8 *)(a2 + 14);
  v15 = *(unsigned __int8 *)(a2 + 11);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: htMIMOPSState = %d, sessionId = %d peerMac <%02x:%02x:%02x:**:**:%02x>",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_process_set_mimops_req",
    v15,
    v16);
  return wma_set_peer_param(a1, a2 + 9, 1u, *(_DWORD *)a2, *(unsigned __int8 *)(a2 + 15));
}
