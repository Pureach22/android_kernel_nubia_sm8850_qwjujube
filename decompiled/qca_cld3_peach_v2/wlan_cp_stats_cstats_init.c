__int64 __fastcall wlan_cp_stats_cstats_init(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  char *v10; // x28
  char v11; // w8
  unsigned __int64 StatusReg; // x23
  char *v13; // x20
  char *v14; // x20
  char v15; // w26
  void *v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD *v25; // x21
  __int64 v26; // x22
  __int64 v27; // x19
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 v30; // x8
  unsigned __int64 v31; // x8
  __int64 v32; // x8
  __int64 result; // x0
  _QWORD v34[2]; // [xsp+0h] [xbp-10h] BYREF

  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[0] = 0;
  if ( (wlan_cp_stats_get_chipset_stats_enable(a1) & 1) != 0 )
  {
    byte_925CF8 = 1;
    qword_925CD8 = wlan_cp_stats_get_user_delay_value_ms(a1);
    qword_925CE0 = wlan_cp_stats_get_user_delay_interval(a1);
    v10 = nullptr;
    byte_925CF9 = wlan_cp_stats_is_debug_logging_enabled(a1) & 1;
    v11 = 1;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v13 = (char *)&cstats + 16 * (_QWORD)v10;
      *((_DWORD *)v13 + 24) = 0;
      v14 = v13 + 96;
      v15 = v11;
      *((_QWORD *)v14 + 1) = 0;
      v16 = (void *)_qdf_mem_valloc(532480, "wlan_cp_stats_cstats_init", 52);
      gcstats_buffer[(_QWORD)v10] = (__int64)v16;
      if ( !v16 )
        break;
      qdf_mem_set(v16, 0x82000u, 0);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v14);
      }
      else
      {
        raw_spin_lock_bh(v14);
        *((_QWORD *)v14 + 1) |= 1uLL;
      }
      v25 = (_QWORD *)((char *)&cstats + 24 * (_QWORD)v10);
      v26 = 0;
      v27 = 0;
      *v25 = v25;
      v25[1] = v25;
      v25[6] = v25 + 6;
      v25[7] = v25 + 6;
      v28 = gcstats_buffer[(_QWORD)v10];
      do
      {
        qdf_list_insert_front((_QWORD *)&cstats + 3 * (_QWORD)v10, (_QWORD *)(v28 + v26));
        v28 = gcstats_buffer[(_QWORD)v10];
        v29 = v28 + v26;
        v26 += 2080;
        *(_DWORD *)(v29 + 20) = v27++;
      }
      while ( v27 != 256 );
      qdf_list_remove_front((_DWORD *)&cstats + 6 * (_QWORD)v10, v34);
      v30 = *((_QWORD *)v14 + 1);
      *((_QWORD *)&cstats + (_QWORD)v10 + 16) = v34[0];
      *((_BYTE *)&cstats + (_QWORD)v10 + 168) = 1;
      if ( (v30 & 1) != 0 )
      {
        *((_QWORD *)v14 + 1) = v30 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v14);
      }
      else
      {
        raw_spin_unlock(v14);
      }
      v11 = 0;
      v10 = (char *)&off_0 + 1;
      if ( (v15 & 1) == 0 )
      {
        result = 0;
        goto LABEL_27;
      }
    }
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Could not allocate memory for chipset stats",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_cp_stats_cstats_init");
    result = 2;
    if ( (v15 & 1) == 0 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v31 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v31 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v31 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(&dword_925CA0);
        v32 = qword_925CA8;
      }
      else
      {
        raw_spin_lock_bh(&dword_925CA0);
        v32 = qword_925CA8 | 1;
        qword_925CA8 |= 1uLL;
      }
      qword_925CC0 = 0;
      if ( (v32 & 1) != 0 )
      {
        qword_925CA8 = v32 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(&dword_925CA0);
      }
      else
      {
        raw_spin_unlock(&dword_925CA0);
      }
      if ( gcstats_buffer[0] )
        _qdf_mem_vfree(gcstats_buffer[0]);
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      4u,
      "%s: Chipset Stats feature is disabled",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_cp_stats_cstats_init");
    result = 0;
    byte_925CF8 = 0;
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
