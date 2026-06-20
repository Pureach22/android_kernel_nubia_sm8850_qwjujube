__int64 __fastcall wmi_extract_tgtr2p_table_event(__int64 a1)
{
  __int64 (*v1)(void); // x8

  if ( !a1 )
    return 16;
  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 5016LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != -1934118367 )
    __break(0x8228u);
  return v1();
}
