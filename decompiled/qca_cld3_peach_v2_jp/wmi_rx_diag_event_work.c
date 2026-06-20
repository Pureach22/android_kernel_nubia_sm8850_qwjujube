__int64 __fastcall wmi_rx_diag_event_work(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int64 StatusReg; // x21
  __int64 v11; // x20
  __int64 v12; // x9
  __int64 v13; // x8
  __int64 result; // x0
  __int64 v15; // x8
  int v16; // w22
  __int64 v17; // x25
  int v18; // w8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // [xsp+8h] [xbp-58h] BYREF
  __int64 v31; // [xsp+10h] [xbp-50h]
  unsigned __int64 current_task; // [xsp+18h] [xbp-48h]
  _QWORD timerid[2]; // [xsp+20h] [xbp-40h] BYREF
  __int64 v34; // [xsp+30h] [xbp-30h]
  __int64 v35; // [xsp+38h] [xbp-28h]
  __int64 v36; // [xsp+40h] [xbp-20h]
  __int64 (__fastcall *v37)(); // [xsp+48h] [xbp-18h]
  __int64 *v38; // [xsp+50h] [xbp-10h]
  __int64 v39; // [xsp+58h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  timerid[1] = 0;
  v34 = 0;
  current_task = 0;
  timerid[0] = 0;
  v30 = 0;
  v31 = 0;
  if ( !a1 )
  {
    result = qdf_trace_msg(
               0x31u,
               2u,
               "%s: Invalid WMI handle",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "wmi_rx_diag_event_work");
    goto LABEL_32;
  }
  v37 = wmi_workqueue_watchdog_bite;
  v38 = &v30;
  StatusReg = _ReadStatusReg(SP_EL0);
  init_timer_key(timerid, _os_timer_shim_6, 0x80000, 0, 0);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 176);
    v11 = *(_QWORD *)(a1 + 192);
    if ( v11 )
    {
LABEL_6:
      v12 = *(_QWORD *)(a1 + 200);
      --*(_DWORD *)(a1 + 208);
      if ( v11 == v12 )
      {
        v13 = 0;
        *(_QWORD *)(a1 + 200) = 0;
      }
      else
      {
        v13 = *(_QWORD *)v11;
      }
      *(_QWORD *)(a1 + 192) = v13;
      *(_QWORD *)v11 = 0;
    }
  }
  else
  {
    raw_spin_lock_bh(a1 + 176);
    *(_QWORD *)(a1 + 184) |= 1uLL;
    v11 = *(_QWORD *)(a1 + 192);
    if ( v11 )
      goto LABEL_6;
  }
  v15 = *(_QWORD *)(a1 + 184);
  if ( (v15 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 176);
    if ( !v11 )
      goto LABEL_31;
    goto LABEL_13;
  }
  *(_QWORD *)(a1 + 184) = v15 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 176);
  if ( v11 )
  {
LABEL_13:
    v16 = 502;
    while ( 1 )
    {
      v17 = jiffies;
      v34 = v17 + 7500LL * (unsigned int)qdf_timer_get_multiplier();
      add_timer(timerid);
      v18 = **(_DWORD **)(v11 + 224);
      v31 = 0;
      LODWORD(v30) = v18 & 0xFFFFFF;
      current_task = qdf_get_current_task();
      _wmi_control_rx((__int64 *)a1, v11, v19, v20, v21, v22, v23, v24, v25, v26);
      timer_delete(timerid);
      if ( !--v16 )
      {
        queue_work_on(32, *(_QWORD *)(a1 + 168), a1 + 216);
        break;
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 176);
        v11 = *(_QWORD *)(a1 + 192);
        if ( v11 )
          goto LABEL_19;
      }
      else
      {
        raw_spin_lock_bh(a1 + 176);
        *(_QWORD *)(a1 + 184) |= 1uLL;
        v11 = *(_QWORD *)(a1 + 192);
        if ( v11 )
        {
LABEL_19:
          v27 = *(_QWORD *)(a1 + 200);
          --*(_DWORD *)(a1 + 208);
          if ( v11 == v27 )
          {
            v28 = 0;
            *(_QWORD *)(a1 + 200) = 0;
          }
          else
          {
            v28 = *(_QWORD *)v11;
          }
          *(_QWORD *)(a1 + 192) = v28;
          *(_QWORD *)v11 = 0;
        }
      }
      v29 = *(_QWORD *)(a1 + 184);
      if ( (v29 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 184) = v29 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 176);
        if ( !v11 )
          break;
      }
      else
      {
        raw_spin_unlock(a1 + 176);
        if ( !v11 )
          break;
      }
    }
  }
LABEL_31:
  result = timer_delete_sync(timerid);
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
