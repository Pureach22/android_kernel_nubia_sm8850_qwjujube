__int64 __fastcall cam_icp_validate_fw(__int64 a1, int a2)
{
  const char *v2; // x5
  __int64 v3; // x4
  int v5; // w6

  if ( a1 )
  {
    if ( *(_DWORD *)a1 == 1179403647 )
    {
      v5 = *(unsigned __int16 *)(a1 + 18);
      if ( v5 != a2 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_validate_fw",
          31,
          "unsupported arch: 0x%x",
          v5);
        return 4294967274LL;
      }
      if ( *(_BYTE *)(a1 + 4) == 1 )
        return 0;
      v2 = "elf doesn't support 32 bit format";
      v3 = 37;
    }
    else
    {
      v2 = "ICP elf identifier is failed";
      v3 = 25;
    }
  }
  else
  {
    v2 = "Invalid params";
    v3 = 18;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_validate_fw",
    v3,
    v2);
  return 4294967274LL;
}
