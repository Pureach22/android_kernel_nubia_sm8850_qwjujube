__int64 __fastcall wmi_ready_extract_mac_addr_list(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 (*v3)(void); // x8

  v3 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2408LL);
  if ( v3 )
  {
    if ( *((_DWORD *)v3 - 1) != -2029091495 )
      __break(0x8228u);
    return v3();
  }
  else
  {
    *a3 = 0;
    return 0;
  }
}
