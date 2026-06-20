__int64 __fastcall sub_48DCC8(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x15
  __int64 v12; // d12

  *(_QWORD *)(v11 - 240) = v12;
  *(double *)(v11 - 232) = a11;
  return sme_set_no_ack_policy(a1, a2, a3, a4);
}
