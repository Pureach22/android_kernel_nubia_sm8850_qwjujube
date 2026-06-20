__int64 __fastcall cm_cp_stats_cstats_log_connecting_event(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w9
  char v6; // w8
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x9
  size_t v9; // x2
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 result; // x0
  int v13; // [xsp+8h] [xbp-48h] BYREF
  char v14; // [xsp+Ch] [xbp-44h]
  char v15; // [xsp+Dh] [xbp-43h]
  unsigned __int64 time_of_the_day_us; // [xsp+Eh] [xbp-42h]
  unsigned __int64 v17; // [xsp+16h] [xbp-3Ah]
  char v18; // [xsp+1Eh] [xbp-32h]
  _BYTE v19[37]; // [xsp+1Fh] [xbp-31h] BYREF
  __int16 v20; // [xsp+44h] [xbp-Ch]
  __int64 v21; // [xsp+48h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 16);
  v13 = 3801095;
  v6 = *(_BYTE *)(a1 + 104);
  memset(v19, 0, sizeof(v19));
  v14 = v5;
  v15 = v6;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v8 = *(_QWORD *)(a2 + 56);
  v9 = *(unsigned __int8 *)(a3 + 52);
  v17 = StatusReg;
  v10 = *(_QWORD *)(v8 + 24);
  v18 = v9;
  v20 = *(_DWORD *)(v10 + 1064);
  qdf_mem_copy(v19, (const void *)(a3 + 53), v9);
  v11 = *(_QWORD *)(a2 + 56);
  *(_WORD *)&v19[33] = *(_WORD *)(*(_QWORD *)(v11 + 24) + 1LL);
  v19[35] = *(_BYTE *)(*(_QWORD *)(v11 + 24) + 3LL);
  v19[36] = *(_BYTE *)(*(_QWORD *)(v11 + 24) + 6LL);
  result = wlan_cp_stats_cstats_write_to_buff(0, &v13, 62);
  _ReadStatusReg(SP_EL0);
  return result;
}
