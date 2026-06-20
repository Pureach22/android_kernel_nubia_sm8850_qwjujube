__int64 __fastcall qcom_soc_sleep_stats_show(__int64 a1)
{
  __int64 v2; // x22
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x21
  __int64 (__fastcall *v6)(__int64); // x8
  __int64 v7; // x0
  __int64 v9; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int64 v10; // [xsp+10h] [xbp-30h]
  unsigned __int64 v11; // [xsp+18h] [xbp-28h]
  __int64 v12; // [xsp+20h] [xbp-20h]
  _QWORD v13[3]; // [xsp+28h] [xbp-18h] BYREF

  v13[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v3 = *(_QWORD *)(v2 + 8);
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v4 = _memcpy_fromio(&v9, v3, 32);
  v5 = v12;
  if ( v10 > v11 )
  {
    v6 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
    if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
      __break(0x8228u);
    v7 = v6(v4);
    v5 = v7 + v5 - v10;
  }
  seq_printf(a1, "Count: %u\n", HIDWORD(v9));
  seq_printf(a1, "Last Entered At: %llu\n", v10);
  seq_printf(a1, "Last Exited At: %llu\n", v11);
  seq_printf(a1, "Accumulated Duration: %llu\n", v5);
  if ( *(_BYTE *)v2 == 1 )
  {
    v13[0] = 0;
    v13[1] = 0;
    _memcpy_fromio(v13, v3 + 32, 16);
    seq_printf(a1, "Client Votes: %#x\n", LODWORD(v13[0]));
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
