__int64 __fastcall wmi_extract_cached_scan_report_ev_params(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 5136LL);
  if ( !v1 )
    return 0;
  if ( *((_DWORD *)v1 - 1) != -622488696 )
    __break(0x8228u);
  return v1();
}
