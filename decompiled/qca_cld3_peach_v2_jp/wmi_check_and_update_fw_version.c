__int64 __fastcall wmi_check_and_update_fw_version(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2408LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 532350945 )
    __break(0x8228u);
  return v1();
}
