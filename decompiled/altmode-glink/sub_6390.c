__int64 __fastcall sub_6390(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v8; // x23

  return altmode_send_data(a1, a2, a3, a4, a5, a6, a7, a8 & 0xFFFFFFFFFFFE0000LL | (v8 >> 3) & 0x1FFFF);
}
