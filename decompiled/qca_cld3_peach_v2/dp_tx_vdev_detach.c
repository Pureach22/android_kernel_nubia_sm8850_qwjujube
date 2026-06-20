__int64 __fastcall dp_tx_vdev_detach(
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
  dp_tx_desc_flush(*(_QWORD *)(a1 + 24), a1, 0, a2, a3, a4, a5, a6, a7, a8, a9);
  return 0;
}
