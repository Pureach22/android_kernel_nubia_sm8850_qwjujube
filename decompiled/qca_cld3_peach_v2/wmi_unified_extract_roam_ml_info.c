__int64 __fastcall wmi_unified_extract_roam_ml_info(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  v1 = *(_QWORD *)(a1 + 728);
  if ( !*(_QWORD *)(v1 + 80) )
    return 16;
  v2 = *(__int64 (**)(void))(v1 + 4784);
  if ( *((_DWORD *)v2 - 1) != -1438400082 )
    __break(0x8228u);
  return v2();
}
