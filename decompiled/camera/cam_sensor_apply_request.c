__int64 __fastcall cam_sensor_apply_request(__int64 a1)
{
  unsigned int v1; // w21
  __int64 device_priv; // x0
  __int64 v4; // x20
  unsigned int v5; // w0
  unsigned int v6; // w2
  __int64 v7; // x3
  unsigned int v8; // w4
  __int64 v9; // x7
  unsigned int v10; // w19
  unsigned __int64 v12; // x7
  __int64 v13; // x8
  unsigned int v14; // w21
  unsigned __int64 v15; // x9
  unsigned __int64 StatusReg; // x22
  __int64 v17; // x0
  __int64 v18; // x8

  if ( !a1 )
    return 4294967274LL;
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
  if ( !device_priv )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_apply_request",
      2345,
      "Device data is NULL");
    return 4294967274LL;
  }
  v4 = device_priv;
  v5 = cam_sensor_apply_deferred_meta(device_priv, a1);
  if ( v5 )
  {
    v9 = *(_QWORD *)(a1 + 8);
    v10 = v5;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_apply_request",
      2353,
      "Sensor[%d] failed to apply deferred meta for req:%lld",
      *(_DWORD *)(v4 + 52),
      v9);
    return v10;
  }
  if ( *(_BYTE *)(a1 + 41) == 1 && (v12 = *(_QWORD *)(a1 + 8)) != 0 && (v13 = *(_QWORD *)(v4 + 7608), v12 <= v13) )
  {
    if ( v13 <= 0 )
      v15 = -(-v13 & 0x1F);
    else
      v15 = *(_QWORD *)(v4 + 7608) & 0x1FLL;
    if ( v15 >= 0x20 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v17 = _traceiter_cam_apply_req(0, (__int64)"Sensor", v6, v7, v8);
        v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v18;
        if ( !v18 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule_notrace(v17);
      }
      goto LABEL_14;
    }
    v1 = 11;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16777248,
      3,
      "cam_sensor_apply_request",
      2370,
      "Sensor[%d] update req id: %lld [last_applied: %lld] with opcode:%d recovery: %d last_applied_res_idx: %u current_res_idx: %u",
      *(_DWORD *)(v4 + 52),
      v12,
      *(_QWORD *)(v4 + 7608),
      11,
      1,
      *(unsigned __int16 *)(v4 + 3664 + 88 * v15),
      *(unsigned __int16 *)(v4 + 3664 + 88 * (*(_QWORD *)(a1 + 8) & 0x1FLL)));
  }
  else
  {
    v1 = 1;
  }
  if ( (debug_mdl & 0x1000020) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000020,
      4,
      "cam_sensor_apply_request",
      2377,
      "Sensor[%d] update req id: %lld [last_applied: %lld] with opcode:%d recovery: %d",
      *(_DWORD *)(v4 + 52),
      *(_QWORD *)(a1 + 8),
      *(_QWORD *)(v4 + 7608),
      v1,
      *(unsigned __int8 *)(a1 + 41));
LABEL_14:
  mutex_lock(v4 + 3608);
  v14 = cam_sensor_apply_settings(v4, *(_QWORD *)(a1 + 8), v1);
  *(_QWORD *)(a1 + 32) = *(_QWORD *)(v4 + 7624);
  mutex_unlock(v4 + 3608);
  return v14;
}
