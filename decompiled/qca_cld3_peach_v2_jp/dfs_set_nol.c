__int64 __fastcall dfs_set_nol(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x21
  _DWORD *v13; // x22
  unsigned __int64 StatusReg; // x24
  unsigned __int64 v15; // x8
  unsigned int v16; // w26
  __int16 v17; // w8
  __int64 v18; // x8
  __int64 result; // x0
  __int64 v20; // [xsp+8h] [xbp-28h] BYREF
  __int64 v21; // [xsp+10h] [xbp-20h]
  __int64 v22; // [xsp+18h] [xbp-18h]
  __int64 v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  if ( a1 )
  {
    if ( a3 >= 1 )
    {
      v12 = (unsigned int)a3;
      v13 = (_DWORD *)(a2 + 16);
      StatusReg = _ReadStatusReg(SP_EL0);
      do
      {
        v15 = (ktime_get_with_offset(1) / 1000 - *((_QWORD *)v13 - 1)) / 0x3E8uLL;
        v16 = *v13 - v15;
        if ( *v13 > (unsigned int)v15 )
        {
          v17 = *((_WORD *)v13 - 8);
          v21 = 0;
          LOWORD(v22) = 0;
          LOWORD(v20) = v17;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(a1 + 14968);
          }
          else
          {
            raw_spin_lock_bh(a1 + 14968);
            *(_QWORD *)(a1 + 14976) |= 1uLL;
          }
          dfs_nol_addchan(a1, (unsigned __int16)v20, v16 / 0x3E8uLL);
          v18 = *(_QWORD *)(a1 + 14976);
          if ( (v18 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 14976) = v18 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 14968);
          }
          else
          {
            raw_spin_unlock(a1 + 14968);
          }
          utils_dfs_deliver_event(*(_QWORD *)(a1 + 14936), (unsigned __int16)v20, 4);
          utils_dfs_reg_update_nol_chan_for_freq(*(_QWORD *)(a1 + 14936), &v20, 1, 1);
        }
        --v12;
        v13 += 6;
      }
      while ( v12 );
    }
    result = dfs_nol_update(a1);
  }
  else
  {
    result = qdf_trace_msg(
               0x27u,
               2u,
               "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "dfs_set_nol");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
