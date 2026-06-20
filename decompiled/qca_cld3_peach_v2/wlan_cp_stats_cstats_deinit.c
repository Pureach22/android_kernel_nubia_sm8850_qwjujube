__int64 __fastcall wlan_cp_stats_cstats_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x8
  unsigned __int64 v10; // x8
  __int64 v11; // x8
  __int64 result; // x0

  if ( byte_925CF8 != 1 )
    return qdf_trace_msg(
             0x38u,
             4u,
             "%s: Chipset Stats feature is disabled",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "wlan_cp_stats_cstats_deinit");
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&dword_925CA0);
    v9 = qword_925CA8;
  }
  else
  {
    raw_spin_lock_bh(&dword_925CA0);
    v9 = qword_925CA8 | 1;
    qword_925CA8 |= 1uLL;
  }
  qword_925CC0 = 0;
  dword_925CD0 = 0;
  if ( (v9 & 1) != 0 )
  {
    qword_925CA8 = v9 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(&dword_925CA0);
  }
  else
  {
    raw_spin_unlock(&dword_925CA0);
  }
  if ( gcstats_buffer[0] )
  {
    _qdf_mem_vfree(gcstats_buffer[0]);
    gcstats_buffer[0] = 0;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v10 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v10 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&dword_925CB0);
    v11 = qword_925CB8;
  }
  else
  {
    raw_spin_lock_bh(&dword_925CB0);
    v11 = qword_925CB8 | 1;
    qword_925CB8 |= 1uLL;
  }
  qword_925CC8 = 0;
  dword_925CD4 = 0;
  if ( (v11 & 1) != 0 )
  {
    qword_925CB8 = v11 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(&dword_925CB0);
  }
  else
  {
    raw_spin_unlock(&dword_925CB0);
  }
  result = qword_925D08;
  if ( qword_925D08 )
  {
    result = _qdf_mem_vfree(qword_925D08);
    qword_925D08 = 0;
  }
  return result;
}
