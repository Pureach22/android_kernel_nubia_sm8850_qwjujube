__int64 __fastcall pmo_core_is_vdev_supports_offload(
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
  unsigned int v9; // w19

  v9 = *(_DWORD *)(a1 + 16);
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: vdev opmode: %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "pmo_core_is_vdev_supports_offload",
    v9);
  return (v9 < 0xC) & (0x805u >> v9);
}
