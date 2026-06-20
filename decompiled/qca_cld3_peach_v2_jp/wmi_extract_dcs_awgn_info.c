__int64 __fastcall wmi_extract_dcs_awgn_info(__int64 a1)
{
  __int64 (*v1)(void); // x8

  if ( !a1 )
    return 16;
  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2632LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != -1762206050 )
    __break(0x8228u);
  return v1();
}
