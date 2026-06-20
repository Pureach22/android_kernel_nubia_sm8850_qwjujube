__int64 __fastcall wmi_extract_fips_event_data(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2656LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != -246267469 )
    __break(0x8228u);
  return v1();
}
