__int64 __fastcall wmi_save_fw_version(__int64 a1)
{
  void (*v1)(void); // x8

  v1 = *(void (**)(void))(*(_QWORD *)(a1 + 728) + 2384LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 532350945 )
    __break(0x8228u);
  v1();
  return 0;
}
