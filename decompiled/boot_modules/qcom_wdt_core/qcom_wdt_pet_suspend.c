__int64 __fastcall qcom_wdt_pet_suspend(__int64 a1)
{
  __int64 v1; // x19
  void (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x0
  __int64 (__fastcall *v4)(_QWORD); // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    if ( *(_BYTE *)(v1 + 209) == 1 )
      timer_delete_sync(v1 + 960);
    raw_spin_lock(v1 + 956);
    *(_BYTE *)(v1 + 952) = 1;
    raw_spin_unlock(v1 + 956);
    v2 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v1 + 16) + 16LL);
    if ( *((_DWORD *)v2 - 1) != 2060914831 )
      __break(0x8228u);
    v2(v1);
    v3 = timer_delete_sync(v1 + 224);
    if ( *(_BYTE *)(v1 + 38) != 1 || (*(_BYTE *)(v1 + 1000) & 1) != 0 || pm_suspend_target_state == 3 )
    {
      v4 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v1 + 16) + 32LL);
      if ( *((_DWORD *)v4 - 1) != 2060914831 )
        __break(0x8228u);
      v3 = v4(v1);
      *(_BYTE *)(v1 + 208) = 0;
    }
    *(_QWORD *)(v1 + 40) = sched_clock(v3);
  }
  return 0;
}
