__int64 __fastcall vdev_start_add_mlo_params(
        __int64 a1,
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
  char v11; // w8
  int v12; // w4
  unsigned int v13; // w4
  unsigned int v14; // w9
  unsigned int v15; // w4
  unsigned int v16; // w4
  unsigned int v17; // w4

  *(_DWORD *)(a1 + 8) = 0;
  *(_QWORD *)a1 = 0x3D600080012000CLL;
  v11 = *(_DWORD *)(a2 + 132);
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a2 + 132) & 1;
  v12 = *(_DWORD *)(a2 + 132) & 2 | v11 & 1;
  *(_DWORD *)(a1 + 8) = v12;
  v13 = v12 & 0xFFFFFEFF | (((*(_DWORD *)(a2 + 132) >> 4) & 1) << 8);
  *(_DWORD *)(a1 + 8) = v13;
  v14 = *(_DWORD *)(a2 + 132);
  v15 = v13 & 0xFFFDFFFF | (((v14 >> 7) & 1) << 17);
  *(_DWORD *)(a1 + 8) = v15;
  v16 = v15 & 0xFFFFBFFF | (((*(_DWORD *)(a2 + 132) >> 5) & 1) << 14);
  *(_DWORD *)(a1 + 8) = v16;
  v17 = v16 & 0xFFFFFFBF | (((*(_DWORD *)(a2 + 132) >> 3) & 1) << 6);
  *(_DWORD *)(a1 + 8) = v17;
  *(_DWORD *)(a1 + 8) = v17 & 0xFFFBFFFF | (((*(_DWORD *)(a2 + 132) >> 6) & 1) << 18);
  *(_DWORD *)(a1 + 12) = 15;
  qdf_trace_msg(
    0x31u,
    4u,
    "%s: mlo_flags 0x%x emlsr_support %d link id 0x%x mlo_link_add %d start_as_active %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "vdev_start_add_mlo_params",
    (v14 >> 7) & 1);
  return a1 + 16;
}
