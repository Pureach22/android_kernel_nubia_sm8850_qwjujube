__int64 __fastcall wma_set_eht_txbf_vdev_params(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x9
  __int64 v12; // x10
  unsigned int v13; // w8
  unsigned int v14; // w9
  unsigned int v15; // w20

  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1501LL);
  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1509LL);
  v13 = ((unsigned int)v12 >> 20) & 2 | 5;
  if ( (v12 & 0x400000) == 0 )
    v13 = ((unsigned int)v12 >> 20) & 2;
  if ( (v11 & 0x30000) != 0 )
    v14 = 8;
  else
    v14 = ((unsigned int)v11 >> 15) & 8;
  v15 = v13 | v14 | 0x30;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: set EHTMU_MODE (ehtmu_mode = 0x%x)",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_set_eht_txbf_vdev_params",
    v15);
  *a2 = v15;
  return 0;
}
