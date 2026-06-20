__int64 __fastcall sub_3E70AC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v8; // w20

  return dot11f_unpack_de_auth(a1, a2, a3, a4, a5, a6, a7, v8 | (unsigned int)~(a8 >> 31));
}
