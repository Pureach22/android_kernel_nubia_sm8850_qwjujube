__int64 __fastcall wmi_ready_extract_init_status(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2392LL);
  if ( !v1 )
    return 1;
  if ( *((_DWORD *)v1 - 1) != -1761073692 )
    __break(0x8228u);
  return v1();
}
