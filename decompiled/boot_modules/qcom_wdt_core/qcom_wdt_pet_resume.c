__int64 __fastcall qcom_wdt_pet_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x0
  void (__fastcall *v4)(__int64, __int64); // x8
  void (__fastcall *v5)(__int64, __int64); // x8
  __int64 v6; // x0
  void (__fastcall *v7)(__int64, __int64); // x8
  __int64 (__fastcall *v8)(_QWORD); // x8
  __int64 v9; // x0
  void (__fastcall *v10)(__int64, __int64); // x8
  __int64 (__fastcall *v11)(_QWORD); // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    if ( *(_BYTE *)(v1 + 209) == 1 )
    {
      *(_QWORD *)(v1 + 976) = jiffies + _msecs_to_jiffies((unsigned int)(*(_DWORD *)(v1 + 28) + 3000));
      add_timer(v1 + 960);
    }
    v2 = _msecs_to_jiffies(*(unsigned int *)(v1 + 24));
    raw_spin_lock(v1 + 956);
    *(_QWORD *)(v1 + 240) = jiffies + v2;
    add_timer(v1 + 224);
    *(_BYTE *)(v1 + 952) = 0;
    raw_spin_unlock(v1 + 956);
    if ( *(_BYTE *)(v1 + 38) == 1 )
    {
      if ( (*(_BYTE *)(v1 + 1000) & 1) != 0 || pm_suspend_target_state == 3 )
      {
        v3 = *(unsigned int *)(v1 + 28);
        v4 = **(void (__fastcall ***)(__int64, __int64))(v1 + 16);
        if ( *((_DWORD *)v4 - 1) != -872624411 )
          __break(0x8228u);
        v4(v3, v1);
        v5 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v1 + 16) + 8LL);
        v6 = (unsigned int)(*(_DWORD *)(v1 + 28) + 3000);
        if ( *((_DWORD *)v5 - 1) != -872624411 )
          __break(0x8228u);
        v5(v6, v1);
        v7 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v1 + 16) + 24LL);
        if ( *((_DWORD *)v7 - 1) != -872624411 )
          __break(0x8228u);
        v7(3, v1);
        *(_BYTE *)(v1 + 208) = 1;
      }
      v8 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v1 + 16) + 16LL);
      if ( *((_DWORD *)v8 - 1) != 2060914831 )
        __break(0x8228u);
      v9 = v8(v1);
    }
    else
    {
      v10 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v1 + 16) + 24LL);
      if ( *((_DWORD *)v10 - 1) != -872624411 )
        __break(0x8228u);
      v10(1, v1);
      v11 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v1 + 16) + 16LL);
      if ( *((_DWORD *)v11 - 1) != 2060914831 )
        __break(0x8228u);
      v9 = v11(v1);
      *(_BYTE *)(v1 + 208) = 1;
    }
    *(_QWORD *)(v1 + 40) = sched_clock(v9);
  }
  return 0;
}
