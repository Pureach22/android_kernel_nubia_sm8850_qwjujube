__int64 __fastcall sde_crtc_complete_commit(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // x10
  _BOOL4 v14; // w21
  __int64 v15; // x9
  __int64 *i; // x22
  __int64 v17; // x8
  void *v18; // x0
  const char *v19; // x1
  char v20; // [xsp+0h] [xbp-10h]
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 1;
  if ( !a1 || !a1[251] )
  {
    v18 = &unk_25E167;
    v19 = "sde_crtc_complete_commit";
LABEL_28:
    result = printk(v18, v19);
    goto LABEL_29;
  }
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_crtc_complete_commit",
             3844,
             4,
             *((_DWORD *)a1 + 28),
             -1059143953,
             a7,
             a8,
             v20);
  v10 = *a1;
  if ( !*a1 || (v11 = *(_QWORD *)(v10 + 56)) == 0 )
  {
    v18 = &unk_25E167;
    v19 = "_sde_crtc_get_kms";
    goto LABEL_28;
  }
  v12 = *(_QWORD *)(v11 + 8);
  if ( !v12 )
  {
    v18 = &unk_234896;
    v19 = "_sde_crtc_get_kms";
    goto LABEL_28;
  }
  v14 = (*(_BYTE *)(v12 + 2712) & 1) != 0 && (v13 = *(_QWORD *)(v12 + 2720)) != 0 && *(_QWORD *)(v13 + 80) == (_QWORD)a1;
  if ( *(_BYTE *)(v12 + 2792) == 1 )
  {
    v15 = *(_QWORD *)(v12 + 2800);
    if ( v15 )
    {
      if ( *(__int64 **)(v15 + 80) == a1 )
        v14 = 1;
    }
  }
  if ( a1[1002] )
  {
    for ( i = *(__int64 **)(v10 + 816); i != (__int64 *)(v10 + 816); i = (__int64 *)*i )
    {
      if ( ((*(_DWORD *)(a1[251] + 20) >> *((_DWORD *)i + 15)) & 1) != 0 )
      {
        result = ((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(i - 1);
        if ( (result & 1) == 0 )
          result = sde_encoder_complete_commit(i - 1);
      }
      v10 = *a1;
    }
  }
  else
  {
    result = sde_core_perf_crtc_update(a1, 2);
  }
  v17 = a1[251];
  if ( (v14 | ((unsigned __int8)(*(_BYTE *)(v17 + 10) & 4) >> 2)) == 1 && *(_BYTE *)(v17 + 9) == 1 )
    result = sde_crtc_event_notify(a1, 2147483650LL, &v21, 4);
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
