__int64 __fastcall wmi_rx_event_work(__int64 a1)
{
  unsigned __int64 StatusReg; // x21
  __int64 v3; // x20
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x24
  int v8; // w8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x9
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 result; // x0
  __int64 v21; // [xsp+8h] [xbp-58h] BYREF
  __int64 v22; // [xsp+10h] [xbp-50h]
  unsigned __int64 current_task; // [xsp+18h] [xbp-48h]
  _QWORD timerid[2]; // [xsp+20h] [xbp-40h] BYREF
  __int64 v25; // [xsp+30h] [xbp-30h]
  __int64 v26; // [xsp+38h] [xbp-28h]
  __int64 v27; // [xsp+40h] [xbp-20h]
  __int64 (__fastcall *v28)(); // [xsp+48h] [xbp-18h]
  __int64 *v29; // [xsp+50h] [xbp-10h]
  __int64 v30; // [xsp+58h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = wmi_workqueue_watchdog_bite;
  StatusReg = _ReadStatusReg(SP_EL0);
  v25 = 0;
  v26 = 0;
  timerid[0] = 0;
  timerid[1] = 0;
  v22 = 0;
  current_task = 0;
  v29 = &v21;
  v21 = 0;
  init_timer_key(timerid, _os_timer_shim_6, 0x80000, 0, 0);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 72);
    v3 = *(_QWORD *)(a1 + 88);
    if ( !v3 )
      goto LABEL_9;
  }
  else
  {
    raw_spin_lock_bh(a1 + 72);
    *(_QWORD *)(a1 + 80) |= 1uLL;
    v3 = *(_QWORD *)(a1 + 88);
    if ( !v3 )
      goto LABEL_9;
  }
  v4 = *(_QWORD *)(a1 + 96);
  --*(_DWORD *)(a1 + 104);
  if ( v3 == v4 )
  {
    v5 = 0;
    *(_QWORD *)(a1 + 96) = 0;
  }
  else
  {
    v5 = *(_QWORD *)v3;
  }
  *(_QWORD *)(a1 + 88) = v5;
  *(_QWORD *)v3 = 0;
LABEL_9:
  v6 = *(_QWORD *)(a1 + 80);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 80) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 72);
    if ( v3 )
      goto LABEL_11;
  }
  else
  {
    raw_spin_unlock(a1 + 72);
    if ( v3 )
    {
      while ( 1 )
      {
LABEL_11:
        v7 = jiffies;
        v25 = v7 + 7500LL * (unsigned int)qdf_timer_get_multiplier();
        add_timer(timerid);
        v8 = **(_DWORD **)(v3 + 224);
        v22 = *(_QWORD *)(a1 + 160);
        LODWORD(v21) = v8 & 0xFFFFFF;
        current_task = qdf_get_current_task();
        _wmi_control_rx((__int64 *)a1, v3, v9, v10, v11, v12, v13, v14, v15, v16);
        timer_delete(timerid);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 72);
          v3 = *(_QWORD *)(a1 + 88);
          if ( v3 )
            goto LABEL_15;
        }
        else
        {
          raw_spin_lock_bh(a1 + 72);
          *(_QWORD *)(a1 + 80) |= 1uLL;
          v3 = *(_QWORD *)(a1 + 88);
          if ( v3 )
          {
LABEL_15:
            v17 = *(_QWORD *)(a1 + 96);
            --*(_DWORD *)(a1 + 104);
            if ( v3 == v17 )
            {
              v18 = 0;
              *(_QWORD *)(a1 + 96) = 0;
            }
            else
            {
              v18 = *(_QWORD *)v3;
            }
            *(_QWORD *)(a1 + 88) = v18;
            *(_QWORD *)v3 = 0;
          }
        }
        v19 = *(_QWORD *)(a1 + 80);
        if ( (v19 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 80) = v19 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 72);
          if ( !v3 )
            break;
        }
        else
        {
          raw_spin_unlock(a1 + 72);
          if ( !v3 )
            break;
        }
      }
    }
  }
  result = timer_delete_sync(timerid);
  _ReadStatusReg(SP_EL0);
  return result;
}
