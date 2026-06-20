__int64 __fastcall tpg_hw_request_set_opcode(__int64 *a1, int a2)
{
  int v2; // w7
  __int64 v4; // x6

  if ( a1 )
  {
    if ( (unsigned int)(a2 - 1) > 2 )
      v2 = 0;
    else
      v2 = dword_454BA0[a2 - 1];
    v4 = *a1;
    *((_DWORD *)a1 + 2) = v2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x200000000LL,
      3,
      "tpg_hw_request_set_opcode",
      1385,
      "req[%d] type = %d",
      v4);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_request_set_opcode",
      1366,
      "Invalid params");
    return 4294967274LL;
  }
}
