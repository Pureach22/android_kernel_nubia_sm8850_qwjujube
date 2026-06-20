__int64 __fastcall cam_vfe_top_ver3_blanking_update(__int64 a1)
{
  __int64 v1; // x0
  __int64 (*v2)(void); // x8
  const char *v4; // x5
  __int64 v5; // x4

  v1 = *(_QWORD *)(a1 + 8);
  if ( !v1 )
  {
    v4 = "Invalid input res %pK";
    v5 = 150;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x2000000,
      1,
      "cam_vfe_top_ver3_blanking_update",
      v5,
      v4,
      0);
    return 4294967274LL;
  }
  v2 = *(__int64 (**)(void))(v1 + 104);
  if ( !v2 )
  {
    v4 = "Invalid input res process_cmd %pK";
    v5 = 156;
    goto LABEL_8;
  }
  if ( *((_DWORD *)v2 - 1) != -1380041226 )
    __break(0x8228u);
  return v2();
}
