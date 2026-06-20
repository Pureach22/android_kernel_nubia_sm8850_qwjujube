__int64 __fastcall cam_sensor_apply_deferred_meta(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x23
  int v5; // w21
  __int64 v6; // x22
  int v7; // w24
  __int64 v8; // x21
  __int64 result; // x0
  __int64 v10; // x6
  __int64 v11; // x7
  const char *v12; // x5
  __int64 v13; // x1
  __int64 v14; // x4
  unsigned int v15; // w20
  unsigned int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 8);
  if ( v2 < 2 )
    goto LABEL_11;
  v5 = 0;
  v6 = a1 + 7640;
  v7 = -1;
  do
  {
    v16 = *(_DWORD *)(a1 + 7636);
    cam_common_dec_idx(&v16, v5, 32);
    if ( v16 >= 0x20 )
      goto LABEL_24;
    ++v5;
    if ( *(_QWORD *)(v6 + 8LL * v16) == v2 )
      v7 = v16;
  }
  while ( v5 != 32 );
  v16 = v7;
  if ( v7 < 0 )
  {
    result = 0;
    if ( (debug_mdl & 0x20) == 0 || debug_priority )
      goto LABEL_12;
    v10 = *(unsigned int *)(a1 + 52);
    v11 = *(_QWORD *)(a2 + 8);
    v12 = "Sensor[%d] can't find req:%llu in req table";
    v13 = debug_mdl & 0x20;
    v14 = 2302;
LABEL_19:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      v13,
      4,
      "cam_sensor_apply_deferred_meta",
      v14,
      v12,
      v10,
      v11);
    goto LABEL_11;
  }
  cam_common_dec_idx(&v16, 1, 32);
  if ( v16 >= 0x20 )
LABEL_24:
    __break(0x5512u);
  v8 = *(_QWORD *)(v6 + 8LL * v16);
  if ( !v8 )
  {
    result = 0;
    if ( (debug_mdl & 0x20) == 0 || debug_priority )
      goto LABEL_12;
    v10 = *(unsigned int *)(a1 + 52);
    v11 = *(_QWORD *)(a2 + 8);
    v12 = "Sensor[%d] req:%llu doesn't have a previous valid req";
    v13 = debug_mdl & 0x20;
    v14 = 2310;
    goto LABEL_19;
  }
  if ( (*(_WORD *)(a1 + 88 * (*(_QWORD *)(v6 + 8LL * v16) & 0x1FLL) + 3666) & 0x20) == 0 )
  {
LABEL_11:
    result = 0;
    goto LABEL_12;
  }
  mutex_lock(a1 + 3608);
  v15 = cam_sensor_apply_settings(a1, v8, 0xCu);
  mutex_unlock(a1 + 3608);
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_apply_deferred_meta",
      2324,
      "Sensor[%d] applying deferred settings from req id: %lld",
      *(_DWORD *)(a1 + 52),
      v8);
  result = v15;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
