__int64 __fastcall aw_pid_2113_reg_force_set(__int64 a1)
{
  void (__fastcall *v2)(__int64, __int64, __int64, __int64); // x8
  __int64 v3; // x0
  void (__fastcall *v4)(__int64, __int64, __int64, __int64); // x8
  __int64 v5; // x0
  void (__fastcall *v6)(__int64, __int64, __int64, __int64); // x8
  __int64 v7; // x0
  void (__fastcall *v8)(__int64, __int64, __int64, __int64); // x8
  __int64 v9; // x0
  _DWORD *v10; // x8
  __int64 v11; // x0
  __int64 (__fastcall *v12)(__int64, __int64, __int64, __int64); // x8
  __int64 v13; // x0
  __int64 *v15; // x8
  __int64 v16; // x1

  if ( *(_DWORD *)(a1 + 12) == 1 )
  {
    v2 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v3 = *(_QWORD *)(a1 + 120);
    if ( *((_DWORD *)v2 - 1) != 370515439 )
      __break(0x8228u);
    v2(v3, 98, 4294963199LL, 4096);
    v4 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v5 = *(_QWORD *)(a1 + 120);
    if ( *((_DWORD *)v4 - 1) != 370515439 )
      __break(0x8228u);
    v4(v5, 100, 4294967288LL, 4);
    v6 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v7 = *(_QWORD *)(a1 + 120);
    if ( *((_DWORD *)v6 - 1) != 370515439 )
      __break(0x8228u);
    v6(v7, 101, 4294967292LL, 2);
    v8 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v9 = *(_QWORD *)(a1 + 120);
    if ( *((_DWORD *)v8 - 1) != 370515439 )
      __break(0x8228u);
    v8(v9, 102, 4294918143LL, 0x8000);
    v10 = *(_DWORD **)(a1 + 1168);
    v11 = *(_QWORD *)(a1 + 120);
    if ( *(v10 - 1) != 370515439 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v10)(v11, 103, 4294967287LL, 0);
    v12 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v13 = *(_QWORD *)(a1 + 120);
    if ( *((_DWORD *)v12 - 1) != 370515439 )
      __break(0x8228u);
    return v12(v13, 104, 4294966399LL, 256);
  }
  else
  {
    v15 = *(__int64 **)(a1 + 112);
    v16 = v15[14];
    if ( !v16 )
      v16 = *v15;
    return printk(&unk_26359, v16, "aw_pid_2113_reg_force_set");
  }
}
