__int64 __fastcall cam_cpas_configure_staling_cache_slice(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  __int64 v6; // x24
  __int64 v7; // x6
  unsigned __int64 v8; // x28
  int v9; // w9
  __int64 v10; // x27
  int *v11; // x22
  unsigned int v12; // w22
  int v13; // w7
  int v14; // w8
  int v15; // w9
  __int64 v16; // x8
  __int64 v17; // x23
  __int64 v18; // x6
  const char *v19; // x5
  __int64 v20; // x4
  const char *v21; // x5
  __int64 v22; // x4
  __int64 v23; // x7
  unsigned int v24; // w21
  int v26; // [xsp+0h] [xbp-40h]
  __int64 v27; // [xsp+28h] [xbp-18h] BYREF
  int v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 3392);
  v7 = *(unsigned int *)(v6 + 1592);
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    v24 = *(_DWORD *)(v6 + 1592);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_configure_staling_cache_slice",
      4489,
      "configuring cache type: %d",
      a2);
    v7 = v24;
    if ( !v24 )
      goto LABEL_39;
  }
  else if ( !(_DWORD)v7 )
  {
LABEL_39:
    v12 = -22;
    v21 = "Invalid num_cache: %d or Invalid Cache Type: %d rc: %d";
    v22 = 4494;
    v23 = (unsigned int)a2;
    v26 = -22;
    goto LABEL_40;
  }
  if ( (unsigned int)a2 > 0xD )
    goto LABEL_39;
  v8 = HIDWORD(a2);
  v9 = 0;
  while ( 1 )
  {
    v10 = v9;
    v11 = (int *)(*(_QWORD *)(v6 + 1600) + ((__int64)v9 << 6));
    if ( v11[1] == (_DWORD)a2 )
      break;
    ++v9;
    if ( (_DWORD)v7 == (_DWORD)v10 + 1 )
    {
      v12 = 0;
      goto LABEL_41;
    }
  }
  mutex_lock(a1);
  v13 = *v11;
  if ( !*v11 )
  {
LABEL_13:
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_cpas_is_configuration_allowed",
        4470,
        "scid_id: %d ref_cnt: %d mode: %d op_type: %d",
        v11[1],
        v13,
        v11[13],
        v11[14]);
    goto LABEL_17;
  }
  v14 = v11[13];
  v15 = v11[14];
  if ( v14 == (_DWORD)a3 )
  {
    if ( v15 != HIDWORD(a3) || !v11[15] )
      goto LABEL_17;
    goto LABEL_13;
  }
  if ( v15 != HIDWORD(a3) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_is_configuration_allowed",
      4461,
      "Can not be configured in middle of usage, ref_cnt = %d old param: scid %d  mode: %d op_type: %d new param: scid %d"
      " mode: %d op_type: %d",
      v13,
      a2,
      a3,
      HIDWORD(a3),
      v11[1],
      v14,
      v15);
    mutex_unlock(a1);
    v12 = 0;
    goto LABEL_41;
  }
LABEL_17:
  mutex_unlock(a1);
  v16 = *(_QWORD *)(v6 + 1600);
  v28 = 0;
  v27 = 0;
  v17 = v16 + (v10 << 6);
  mutex_lock(a1);
  if ( (_DWORD)a3 == 2 )
  {
    LODWORD(v27) = 1;
    if ( HIDWORD(a3) != 2 )
      goto LABEL_22;
    goto LABEL_25;
  }
  if ( (_DWORD)a3 != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_configure_staling_cache",
      4263,
      "CPAS LLCC sys cache mode is not valid =%d",
      a3);
    if ( HIDWORD(a3) != 2 )
      goto LABEL_22;
LABEL_25:
    v28 = 1;
    goto LABEL_27;
  }
  LODWORD(v27) = 0;
  if ( HIDWORD(a3) == 2 )
    goto LABEL_25;
LABEL_22:
  if ( HIDWORD(a3) == 1 )
    v28 = 0;
  else
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_configure_staling_cache",
      4280,
      "CPAS LLCC sys cache op_type is not valid =%d",
      HIDWORD(a3));
LABEL_27:
  BYTE4(v27) = v8;
  v12 = llcc_configure_staling_mode(*(_QWORD *)(v17 + 40), &v27);
  if ( v12 == -95 )
  {
    v18 = *(_QWORD *)(v17 + 32);
    v19 = "llcc staling feature is not supported cache:%s";
    v20 = 4293;
  }
  else
  {
    if ( !v12 )
    {
      *(_DWORD *)(v17 + 48) = v8;
      *(_QWORD *)(v17 + 52) = a3;
      goto LABEL_33;
    }
    v18 = *(_QWORD *)(v17 + 32);
    v19 = "Failed to enable llcc notif cache:%s";
    v20 = 4296;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    4,
    1,
    "cam_cpas_configure_staling_cache",
    v20,
    v19,
    v18);
LABEL_33:
  mutex_unlock(a1);
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_configure_staling_cache",
      4303,
      "llcc notif cache scid = %d, name:%s staling_distance %d cache mode :%d cache op_type :%d",
      *(_DWORD *)(v17 + 24),
      *(const char **)(v17 + 32),
      *(_DWORD *)(v17 + 48),
      *(_DWORD *)(v17 + 52),
      *(_DWORD *)(v17 + 56));
    if ( !v12 )
      goto LABEL_41;
    goto LABEL_36;
  }
  if ( v12 )
  {
LABEL_36:
    v21 = "cache type %d config failed, rc: %d";
    v22 = 4507;
    v23 = v12;
    v7 = *(unsigned int *)(*(_QWORD *)(v6 + 1600) + (v10 << 6) + 4);
LABEL_40:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_configure_staling_cache_slice",
      v22,
      v21,
      v7,
      v23,
      v26);
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return v12;
}
