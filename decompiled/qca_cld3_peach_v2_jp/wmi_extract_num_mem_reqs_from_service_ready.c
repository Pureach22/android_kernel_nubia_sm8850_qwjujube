__int64 __fastcall wmi_extract_num_mem_reqs_from_service_ready(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2344LL);
  if ( !v1 )
    return 0;
  if ( *((_DWORD *)v1 - 1) != -1761073692 )
    __break(0x8228u);
  return v1();
}
