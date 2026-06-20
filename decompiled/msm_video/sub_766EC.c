__int64 __fastcall sub_766EC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  char v9; // w18

  *(_BYTE *)(a4 + 3666) = v9;
  return venus_hfi_session_command(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}
