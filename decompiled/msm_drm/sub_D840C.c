__int64 __fastcall sub_D840C(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        long double a10)
{
  __int128 v10; // q25

  *(_OWORD *)(a3 + 768) = v10;
  *(long double *)(a3 + 784) = a10;
  return sde_encoder_event_timestamp_adjust(a1, a2, a3);
}
