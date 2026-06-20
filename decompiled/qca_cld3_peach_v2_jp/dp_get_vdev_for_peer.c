__int64 __fastcall dp_get_vdev_for_peer(
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
  qdf_trace_msg(0x45u, 8u, "peer %pK vdev %pK", a2, a3, a4, a5, a6, a7, a8, a9, a1, *(_QWORD *)(a1 + 24));
  return *(_QWORD *)(a1 + 24);
}
