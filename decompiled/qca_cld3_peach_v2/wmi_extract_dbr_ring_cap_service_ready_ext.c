__int64 __fastcall wmi_extract_dbr_ring_cap_service_ready_ext(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3360LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 2027229034 )
    __break(0x8228u);
  return v1();
}
