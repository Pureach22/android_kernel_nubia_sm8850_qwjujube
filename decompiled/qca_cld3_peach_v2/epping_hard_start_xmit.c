__int64 __fastcall epping_hard_start_xmit(
        _QWORD *a1,
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
  epping_tx_send(a1, a2 + 2688, a3, a4, a5, a6, a7, a8, a9, a10);
  return 0;
}
