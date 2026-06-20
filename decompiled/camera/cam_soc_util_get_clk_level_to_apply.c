__int64 __fastcall cam_soc_util_get_clk_level_to_apply(__int64 a1, unsigned int a2, int *a3)
{
  const char *v3; // x5
  __int64 v4; // x4
  __int64 v5; // x6
  unsigned int v6; // w9
  __int64 v7; // x10
  __int64 v8; // x9
  __int64 v9; // x10
  char v10; // w11
  __int64 result; // x0
  int v12; // w20
  char *string_from_level; // x0
  int v15; // w8
  const char *v16; // x19
  char *v17; // x0

  if ( a2 >= 0xA )
  {
    v3 = "Invalid clock level parameter %d";
    v4 = 1915;
    v5 = a2;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_clk_level_to_apply",
      v4,
      v3,
      v5);
    return 4294967274LL;
  }
  v5 = a2;
  v6 = a2;
  v7 = a1 + a2;
  if ( (*(_BYTE *)(v7 + 2860) & 1) == 0 )
  {
    v8 = 0;
    v9 = v7 + 2861;
    while ( (int)(a2 + v8) <= 8 )
    {
      v10 = *(_BYTE *)(v9 + v8++);
      if ( (v10 & 1) != 0 )
      {
        v6 = a2 + v8;
        goto LABEL_8;
      }
    }
    v3 = "No valid clock level found to apply, req=%d";
    v4 = 1933;
    goto LABEL_12;
  }
LABEL_8:
  *a3 = v6;
  result = 0;
  v12 = debug_mdl;
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    string_from_level = cam_soc_util_get_string_from_level(a2);
    v15 = *a3;
    v16 = string_from_level;
    v17 = cam_soc_util_get_string_from_level(v15);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      *(_QWORD *)&v12 & 0x20000LL,
      4,
      "cam_soc_util_get_clk_level_to_apply",
      1940,
      "Req level %s, Applying %s",
      v16,
      v17);
    return 0;
  }
  return result;
}
