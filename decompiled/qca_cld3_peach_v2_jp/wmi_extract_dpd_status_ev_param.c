__int64 __fastcall wmi_extract_dpd_status_ev_param(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 4536LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 850860733 )
    __break(0x8228u);
  return v1();
}
