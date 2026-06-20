__int64 __fastcall sub_201B80(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x13
  __int64 v9; // x22

  *(_QWORD *)(a8 + 472) = v9;
  *(_QWORD *)(a8 + 480) = v8;
  return dsi_parser_read_u64(a1, a2, a3, a4, a5, a6, a7, a8 + 472);
}
