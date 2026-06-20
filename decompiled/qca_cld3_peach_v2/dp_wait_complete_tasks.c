__int64 __fastcall dp_wait_complete_tasks(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x27
  __int64 v4; // x22
  __int64 v5; // x8
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned __int64 v15; // x23
  __int64 v16; // x26
  unsigned int v17; // w22
  __int64 v18; // x28
  __int64 v19; // x8
  _QWORD *v20; // x1
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 264);
  }
  else
  {
    raw_spin_lock_bh(a1 + 264);
    *(_QWORD *)(a1 + 272) |= 1uLL;
  }
  v21[0] = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 280), v21) )
  {
    v3 = 0;
    goto LABEL_7;
  }
  v20 = (_QWORD *)v21[0];
  v3 = v21[0] - 32LL;
  if ( v21[0] == 32 || (v21[0] = 0, (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 280), v20, v21)) )
  {
LABEL_7:
    v4 = 0;
    v5 = *(_QWORD *)(a1 + 272);
    if ( (v5 & 1) == 0 )
      goto LABEL_8;
    goto LABEL_34;
  }
  v4 = v21[0] - 32LL;
  v5 = *(_QWORD *)(a1 + 272);
  if ( (v5 & 1) == 0 )
  {
LABEL_8:
    result = raw_spin_unlock(a1 + 264);
    if ( !v3 )
      goto LABEL_30;
    goto LABEL_9;
  }
LABEL_34:
  *(_QWORD *)(a1 + 272) = v5 & 0xFFFFFFFFFFFFFFFELL;
  result = raw_spin_unlock_bh(a1 + 264);
  if ( !v3 )
    goto LABEL_30;
LABEL_9:
  v15 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v16 = v4;
    if ( *(_DWORD *)(v3 + 3576) )
      break;
LABEL_16:
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v15 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 264);
      if ( v16 )
        goto LABEL_22;
    }
    else
    {
      raw_spin_lock_bh(a1 + 264);
      *(_QWORD *)(a1 + 272) |= 1uLL;
      if ( v16 )
      {
LABEL_22:
        v21[0] = 0;
        v4 = 0;
        if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 280), (_QWORD *)(v16 + 32), v21) )
          v4 = v21[0] - 32LL;
        goto LABEL_24;
      }
    }
    v4 = 0;
LABEL_24:
    v19 = *(_QWORD *)(a1 + 272);
    if ( (v19 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 272) = v19 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(a1 + 264);
      v3 = v16;
      if ( !v16 )
        goto LABEL_30;
    }
    else
    {
      result = raw_spin_unlock(a1 + 264);
      v3 = v16;
      if ( !v16 )
        goto LABEL_30;
    }
  }
  v17 = 99;
  while ( v17 )
  {
    v18 = jiffies;
    if ( dp_intf_wait_for_task_complete___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Waiting for DP task to complete: %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "dp_intf_wait_for_task_complete",
        v17);
      dp_intf_wait_for_task_complete___last_ticks = v18;
    }
    qdf_sleep();
    --v17;
    if ( !*(_DWORD *)(v3 + 3576) )
      goto LABEL_16;
  }
  result = qdf_trace_msg(
             0x45u,
             2u,
             "%s: Timed-out waiting for DP task completion",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "dp_intf_wait_for_task_complete");
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
