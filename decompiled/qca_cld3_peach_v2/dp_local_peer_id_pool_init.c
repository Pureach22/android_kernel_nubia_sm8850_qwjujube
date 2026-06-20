__int64 __fastcall dp_local_peer_id_pool_init(
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
  *(_BYTE *)(a1 + 94408) = 1;
  *(_BYTE *)(a1 + 94444) = 0;
  *(_QWORD *)(a1 + 94409) = 0x908070605040302LL;
  *(_QWORD *)(a1 + 94472) = 0;
  *(_QWORD *)(a1 + 94480) = 0;
  *(_DWORD *)(a1 + 94417) = 218893066;
  *(_BYTE *)(a1 + 94421) = 14;
  *(_WORD *)(a1 + 94422) = 4111;
  *(_BYTE *)(a1 + 94424) = 17;
  *(_QWORD *)(a1 + 94488) = 0;
  *(_QWORD *)(a1 + 94496) = 0;
  *(_QWORD *)(a1 + 94504) = 0;
  *(_QWORD *)(a1 + 94512) = 0;
  *(_QWORD *)(a1 + 94520) = 0;
  *(_QWORD *)(a1 + 94528) = 0;
  *(_QWORD *)(a1 + 94425) = 0x1918171615141312LL;
  *(_WORD *)(a1 + 94433) = 6938;
  *(_BYTE *)(a1 + 94435) = 28;
  *(_QWORD *)(a1 + 94536) = 0;
  *(_QWORD *)(a1 + 94544) = 0;
  *(_QWORD *)(a1 + 94552) = 0;
  *(_QWORD *)(a1 + 94560) = 0;
  *(_QWORD *)(a1 + 94568) = 0;
  *(_QWORD *)(a1 + 94576) = 0;
  *(_QWORD *)(a1 + 94584) = 0;
  *(_QWORD *)(a1 + 94592) = 0;
  *(_QWORD *)(a1 + 94600) = 0;
  *(_QWORD *)(a1 + 94608) = 0;
  *(_QWORD *)(a1 + 94616) = 0;
  *(_QWORD *)(a1 + 94624) = 0;
  *(_QWORD *)(a1 + 94632) = 0;
  *(_QWORD *)(a1 + 94640) = 0;
  *(_QWORD *)(a1 + 94648) = 0;
  *(_QWORD *)(a1 + 94656) = 0;
  *(_QWORD *)(a1 + 94664) = 0;
  *(_QWORD *)(a1 + 94672) = 0;
  *(_QWORD *)(a1 + 94436) = 0x23232221201F1E1DLL;
  *(_QWORD *)(a1 + 94680) = 0;
  *(_QWORD *)(a1 + 94688) = 0;
  *(_QWORD *)(a1 + 94696) = 0;
  *(_QWORD *)(a1 + 94704) = 0;
  *(_QWORD *)(a1 + 94712) = 0;
  *(_QWORD *)(a1 + 94720) = 0;
  *(_QWORD *)(a1 + 94728) = 0;
  *(_QWORD *)(a1 + 94736) = 0;
  *(_DWORD *)(a1 + 94448) = 0;
  *(_QWORD *)(a1 + 94456) = 0;
  *(_QWORD *)(a1 + 94464) = 0;
  return qdf_trace_msg(0x45u, 5u, "%s: Peer pool init", a2, a3, a4, a5, a6, a7, a8, a9, "dp_local_peer_id_pool_init");
}
