__int64 __fastcall sub_58C640(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19

  *(_QWORD *)(a8 + 1776) = v8;
  return hal_srng_set_msi_config();
}
