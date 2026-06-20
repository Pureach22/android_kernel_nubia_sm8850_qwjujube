__int64 __fastcall wmi_extract_scan_radio_cap_service_ready_ext2(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3360LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != -512562373 )
    __break(0x8228u);
  return v1();
}
