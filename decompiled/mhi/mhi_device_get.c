__int64 __fastcall mhi_device_get(__int64 a1)
{
  __int64 v1; // x19
  void (__fastcall *v2)(_QWORD); // x8
  void (__fastcall *v3)(_QWORD); // x8
  void (__fastcall *v4)(__int64, __int64); // x8

  v1 = *(_QWORD *)(a1 + 16);
  ++*(_DWORD *)(a1 + 972);
  raw_read_lock_bh(v1 + 320);
  if ( (*(_BYTE *)(v1 + 336) & 0x30) != 0 )
  {
    pm_wakeup_dev_event(*(_QWORD *)(v1 + 16) + 40LL, 0, 0);
    v2 = *(void (__fastcall **)(_QWORD))(v1 + 512);
    if ( *((_DWORD *)v2 - 1) != -700558418 )
      __break(0x8228u);
    v2(v1);
    v3 = *(void (__fastcall **)(_QWORD))(v1 + 528);
    if ( *((_DWORD *)v3 - 1) != -2145957670 )
      __break(0x8228u);
    v3(v1);
  }
  v4 = *(void (__fastcall **)(__int64, __int64))(v1 + 488);
  if ( *((_DWORD *)v4 - 1) != 598874997 )
    __break(0x8228u);
  v4(v1, 1);
  return raw_read_unlock_bh(v1 + 320);
}
