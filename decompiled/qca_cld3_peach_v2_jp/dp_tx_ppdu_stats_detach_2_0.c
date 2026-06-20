__int64 __fastcall dp_tx_ppdu_stats_detach_2_0(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x9
  __int64 v11; // x23
  char v12; // w8
  __int64 v13; // x24
  unsigned __int64 StatusReg; // x26
  char v15; // w27
  __int64 v16; // x9
  __int64 v17; // x8
  _DWORD *v18; // x8
  const char *v19; // x2
  __int64 v20; // x23
  __int64 v21; // x20
  __int64 *v22; // x28
  __int64 v23; // x8
  __int64 v24; // x20
  __int64 *v25; // x28
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x9
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x9
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x9
  __int64 v37; // x8
  __int64 v38; // x9

  if ( !result )
    return result;
  v9 = result;
  v10 = *(_QWORD *)(result + 95560);
  if ( !v10 )
    return result;
  v11 = 0;
  v12 = 1;
  v13 = v10 + 39344;
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    v15 = v12;
    v16 = *(_QWORD *)(*(_QWORD *)(v9 + 8) + 20056LL);
    if ( !v16 )
    {
      v19 = "%s: monitor soc is NULL";
      goto LABEL_12;
    }
    v17 = *(_QWORD *)(v16 + 416);
    if ( !v17 || (v18 = *(_DWORD **)(v17 + 408)) == nullptr )
    {
      v19 = "%s: callback not registered";
LABEL_12:
      qdf_trace_msg(0x92u, 8u, v19, a2, a3, a4, a5, a6, a7, a8, a9, "dp_monitor_config_enh_tx_capture");
      goto LABEL_13;
    }
    if ( *(v18 - 1) != -1460143776 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, _QWORD))v18)(v9, 0, (unsigned int)v11);
LABEL_13:
    v20 = v13 + 2576 * v11;
    _flush_workqueue(*(_QWORD *)(v20 + 96));
    destroy_workqueue(*(_QWORD *)(v20 + 96));
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v20 + 32);
    }
    else
    {
      raw_spin_lock_bh(v20 + 32);
      *(_QWORD *)(v20 + 40) |= 1uLL;
    }
    v22 = (__int64 *)(v20 + 112);
    v21 = *(_QWORD *)(v20 + 112);
    while ( v21 )
    {
      v27 = *v22;
      v28 = v21;
      v21 = *(_QWORD *)(v21 + 8);
      if ( *v22 == v28 )
      {
        v32 = *(_QWORD *)(v27 + 8);
        v31 = v20 + 112;
        *v22 = v32;
        if ( v32 )
          goto LABEL_29;
      }
      else
      {
        do
        {
          v29 = v27;
          v27 = *(_QWORD *)(v27 + 8);
        }
        while ( v27 != v28 );
        v30 = *(_QWORD *)(v27 + 8);
        *(_QWORD *)(v29 + 8) = v30;
        v31 = v29 + 8;
        if ( v30 )
          goto LABEL_29;
      }
      *(_QWORD *)(v20 + 120) = v31;
LABEL_29:
      --*(_DWORD *)(v20 + 104);
      dp_tx_mon_free_ppdu_info(v28, v20);
    }
    v23 = *(_QWORD *)(v20 + 40);
    if ( (v23 & 1) != 0 )
    {
      *(_QWORD *)(v20 + 40) = v23 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v20 + 32);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_22;
    }
    else
    {
      raw_spin_unlock(v20 + 32);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_22;
    }
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
LABEL_22:
      raw_spin_lock(v20 + 32);
      goto LABEL_23;
    }
    raw_spin_lock_bh(v20 + 32);
    *(_QWORD *)(v20 + 40) |= 1uLL;
LABEL_23:
    v25 = (__int64 *)(v20 + 136);
    v24 = *(_QWORD *)(v20 + 136);
    while ( v24 )
    {
      v33 = *v25;
      v34 = v24;
      v24 = *(_QWORD *)(v24 + 8);
      if ( *v25 == v34 )
      {
        v38 = *(_QWORD *)(v33 + 8);
        v37 = v20 + 136;
        *v25 = v38;
        if ( v38 )
          goto LABEL_37;
      }
      else
      {
        do
        {
          v35 = v33;
          v33 = *(_QWORD *)(v33 + 8);
        }
        while ( v33 != v34 );
        v36 = *(_QWORD *)(v33 + 8);
        *(_QWORD *)(v35 + 8) = v36;
        v37 = v35 + 8;
        if ( v36 )
          goto LABEL_37;
      }
      *(_QWORD *)(v20 + 144) = v37;
LABEL_37:
      --*(_DWORD *)(v20 + 128);
      dp_tx_mon_free_ppdu_info(v34, v20);
    }
    v26 = *(_QWORD *)(v20 + 40);
    if ( (v26 & 1) != 0 )
    {
      *(_QWORD *)(v20 + 40) = v26 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v20 + 32);
    }
    else
    {
      result = raw_spin_unlock(v20 + 32);
    }
    v12 = 0;
    v11 = 1;
  }
  while ( (v15 & 1) != 0 );
  return result;
}
