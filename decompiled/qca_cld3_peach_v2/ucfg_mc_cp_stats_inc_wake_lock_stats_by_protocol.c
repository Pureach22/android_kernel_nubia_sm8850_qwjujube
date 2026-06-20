__int64 __fastcall ucfg_mc_cp_stats_inc_wake_lock_stats_by_protocol(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        int a11)
{
  __int64 comp_private_obj; // x0
  __int64 v13; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8
  __int64 v16; // x9
  const char *v17; // x2
  __int64 v19; // x8

  if ( !a1
    || (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) == 0
    || (v13 = *(_QWORD *)(comp_private_obj + 24)) == 0 )
  {
    v17 = "%s: psoc cp stats object is null";
LABEL_12:
    qdf_trace_msg(0x62u, 2u, v17, a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_mc_cp_stats_inc_wake_lock_stats_by_protocol");
    return 29;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v13 + 16);
    v15 = *(_QWORD *)(v13 + 40);
    if ( v15 )
      goto LABEL_8;
    goto LABEL_29;
  }
  raw_spin_lock_bh(v13 + 16);
  *(_QWORD *)(v13 + 24) |= 1uLL;
  v15 = *(_QWORD *)(v13 + 40);
  if ( !v15 )
  {
LABEL_29:
    v17 = "%s: psoc mc stats is null";
    goto LABEL_12;
  }
LABEL_8:
  if ( a11 > 19 )
  {
    if ( a11 <= 21 )
    {
      ++*(_DWORD *)(v15 + 392);
      if ( a11 == 20 )
        v16 = 372;
      else
        v16 = 376;
      goto LABEL_23;
    }
    if ( a11 == 22 )
    {
      ++*(_DWORD *)(v15 + 392);
      v16 = 380;
      goto LABEL_23;
    }
    if ( a11 == 23 )
    {
      ++*(_DWORD *)(v15 + 392);
      v16 = 384;
      goto LABEL_23;
    }
  }
  else
  {
    if ( (unsigned int)(a11 - 17) < 3 )
    {
      v16 = 392;
LABEL_23:
      ++*(_DWORD *)(v15 + v16);
      goto LABEL_24;
    }
    if ( (unsigned int)(a11 - 15) < 2 )
    {
      v16 = 388;
      goto LABEL_23;
    }
  }
LABEL_24:
  v19 = *(_QWORD *)(v13 + 24);
  if ( (v19 & 1) != 0 )
  {
    *(_QWORD *)(v13 + 24) = v19 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 16);
  }
  else
  {
    raw_spin_unlock(v13 + 16);
  }
  return 0;
}
