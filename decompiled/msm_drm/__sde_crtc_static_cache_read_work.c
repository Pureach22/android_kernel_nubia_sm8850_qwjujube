__int64 __fastcall _sde_crtc_static_cache_read_work(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v8; // w8
  __int64 v9; // x21
  __int64 v10; // x19
  _DWORD *v11; // x20
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x9
  unsigned int v15; // w23
  void *v16; // x0
  const char *v17; // x1
  __int64 v18; // x8
  __int64 *v19; // x24
  __int64 *v20; // x22
  int v21; // w4
  _DWORD *v22; // x0
  void (__fastcall *v23)(_QWORD); // x8
  __int64 v24; // x8
  __int64 *v25; // x23
  int v26; // w7
  int v27; // w4
  char v28; // [xsp+0h] [xbp-20h]
  char v29; // [xsp+0h] [xbp-20h]
  _QWORD v30[3]; // [xsp+8h] [xbp-18h] BYREF

  v30[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_DWORD *)(result + 80);
  v9 = *(_QWORD *)(result - 5568);
  v30[0] = 0;
  v30[1] = 0;
  if ( v8 != 4 )
    goto LABEL_39;
  v10 = result;
  v11 = (_DWORD *)(result - 7776);
  if ( result == 7776 || !*(_QWORD *)v11 || (v12 = *(_QWORD *)(*(_QWORD *)v11 + 56LL)) == 0 )
  {
    v16 = &unk_25E167;
    v17 = "sde_crtc_get_disp_op";
LABEL_11:
    printk(v16, v17);
LABEL_12:
    v15 = 0;
    goto LABEL_13;
  }
  v13 = *(_QWORD *)(v12 + 8);
  if ( !v13 )
  {
    v16 = &unk_234896;
    v17 = "_sde_crtc_get_kms";
    goto LABEL_11;
  }
  v14 = *(_QWORD *)(v13 + 152);
  if ( !v14 || (*(_QWORD *)(v14 + 22008) & 0x8000000000000LL) == 0 )
    goto LABEL_12;
  v15 = *(_DWORD *)(v12 + 5912);
LABEL_13:
  v18 = *(_QWORD *)v11;
  v19 = *(__int64 **)(*(_QWORD *)v11 + 816LL);
  if ( v19 == (__int64 *)(*(_QWORD *)v11 + 816LL) )
    goto LABEL_40;
  v20 = nullptr;
  do
  {
    if ( ((*(_DWORD *)(*(_QWORD *)(v10 - 5768) + 20LL) >> *((_DWORD *)v19 + 15)) & 1) != 0 )
    {
      v20 = v19 - 1;
      result = ((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(v19 - 1);
      if ( (result & 1) != 0 )
        goto LABEL_39;
      v18 = *(_QWORD *)v11;
    }
    v19 = (__int64 *)*v19;
  }
  while ( v19 != (__int64 *)(v18 + 816) );
  if ( !v20 || !v9 || !*(_DWORD *)(v10 - 5584) )
  {
LABEL_40:
    result = printk(&unk_23811B, "__sde_crtc_static_cache_read_work");
LABEL_39:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v11 )
    v21 = *(_DWORD *)(v10 - 7664);
  else
    v21 = -1;
  sde_evtlog_log(sde_dbg_base_evtlog, "__sde_crtc_static_cache_read_work", 9169, -1, v21, 4369, -1059143953, a8, v28);
  v22 = sde_crtc_static_img_control(v11, 5, 0);
  if ( v15 <= 2 )
  {
    v23 = *(void (__fastcall **)(_QWORD))(v9 + 8LL * v15 + 688);
    if ( v23 )
    {
      if ( *((_DWORD *)v23 - 1) != 1800103338 )
        __break(0x8228u);
      v23(v9);
    }
    v24 = *(_QWORD *)v11;
    v25 = *(__int64 **)(*(_QWORD *)v11 + 840LL);
    if ( v25 != (__int64 *)(*(_QWORD *)v11 + 840LL) )
    {
      do
      {
        if ( ((*(_DWORD *)(*(_QWORD *)(v10 - 5768) + 12LL) >> *((_DWORD *)v25 + 437)) & 1) != 0 )
        {
          ((void (__fastcall *)(__int64 *, __int64, __int64))sde_plane_ctl_flush)(v25 - 1, v9, 1);
          v24 = *(_QWORD *)v11;
        }
        v25 = (__int64 *)*v25;
      }
      while ( v25 != (__int64 *)(v24 + 840) );
    }
    v30[0] = (unsigned int)sde_crtc_get_displays_affected((__int64)v11, *(_QWORD *)(v10 - 5768));
    sde_encoder_prepare_for_kickoff(v20, v30);
    sde_encoder_kickoff(v20, 0);
    sde_encoder_wait_for_event(v20, 2);
    if ( v11 )
      v27 = *(_DWORD *)(v10 - 7664);
    else
      v27 = -1;
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "__sde_crtc_static_cache_read_work",
               9186,
               -1,
               v27,
               8738,
               -1059143953,
               v26,
               v29);
    goto LABEL_39;
  }
  __break(0x5512u);
  return sde_crtc_static_cache_read_kickoff(v22);
}
