__int64 __fastcall qpace_queue_compress_wrapper(__int64 a1, __int64 a2, __int64 a3)
{
  return qpace_queue_compress(
           a1,
           (a2 - (0xFFFFFFFEC0000000LL - ((__int64)memstart_addr >> 12 << 6))) << 6,
           (a3 - (0xFFFFFFFEC0000000LL - ((__int64)memstart_addr >> 12 << 6))) << 6);
}
