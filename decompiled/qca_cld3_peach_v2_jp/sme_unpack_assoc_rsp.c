__int64 __fastcall sme_unpack_assoc_rsp(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  return dot11f_parse_assoc_response(a1, *(_QWORD *)(a2 + 128), *(unsigned int *)(a2 + 120), a3, 0, a6, a7, a8);
}
