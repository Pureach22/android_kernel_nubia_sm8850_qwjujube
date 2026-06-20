__int64 __fastcall wmi_extract_dfs_ocac_complete_event(__int64 a1)
{
  __int64 (*v1)(void); // x8

  if ( !a1 )
    return 16;
  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3648LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 140118972 )
    __break(0x8228u);
  return v1();
}
