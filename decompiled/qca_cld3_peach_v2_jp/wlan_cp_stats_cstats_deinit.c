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

  if ( byte_85CAD0 != 1 )
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
    raw_spin_lock(&dword_85CA78);
    v9 = qword_85CA80;
  }
  else
  {
    raw_spin_lock_bh(&dword_85CA78);
    v9 = qword_85CA80 | 1;
    qword_85CA80 |= 1uLL;
  }
  qword_85CA98 = 0;
  dword_85CAA8 = 0;
  if ( (v9 & 1) != 0 )
  {
    qword_85CA80 = v9 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(&dword_85CA78);
  }
  else
  {
    raw_spin_unlock(&dword_85CA78);
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
    raw_spin_lock(&dword_85CA88);
    v11 = qword_85CA90;
  }
  else
  {
    raw_spin_lock_bh(&dword_85CA88);
    v11 = qword_85CA90 | 1;
    qword_85CA90 |= 1uLL;
  }
  qword_85CAA0 = 0;
  dword_85CAAC = 0;
  if ( (v11 & 1) != 0 )
  {
    qword_85CA90 = v11 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(&dword_85CA88);
  }
  else
  {
    raw_spin_unlock(&dword_85CA88);
  }
  result = qword_85CAE0;
  if ( qword_85CAE0 )
  {
    result = _qdf_mem_vfree(qword_85CAE0);
    qword_85CAE0 = 0;
  }
  return result;
}
