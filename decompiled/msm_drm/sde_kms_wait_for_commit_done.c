__int64 __fastcall sde_kms_wait_for_commit_done(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v9; // x8
  __int64 v10; // x22
  __int64 v11; // x25
  __int64 *v12; // x24
  __int64 v13; // x26
  __int64 v14; // x22
  __int64 v15; // x19
  __int64 *v16; // x21
  __int64 v17; // x28
  _BOOL4 v18; // w22
  int v19; // w0
  int v20; // w23
  int v21; // w24
  char v22; // [xsp+0h] [xbp-20h]

  if ( !result )
    return printk(&unk_223EAA, "sde_kms_wait_for_commit_done");
  if ( !a2 )
    return printk(&unk_223EAA, "sde_kms_wait_for_commit_done");
  v9 = *(_QWORD *)(a2 + 2008);
  if ( !v9 )
    return printk(&unk_223EAA, "sde_kms_wait_for_commit_done");
  if ( (*(_BYTE *)(v9 + 8) & 1) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "[crtc:%d] not enable\n", *(unsigned int *)(a2 + 112));
    return result;
  }
  if ( (*(_BYTE *)(v9 + 9) & 1) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "[crtc:%d] not active\n", *(unsigned int *)(a2 + 112));
    return result;
  }
  v10 = *(_QWORD *)a2;
  if ( !*(_QWORD *)a2 || (*(_WORD *)(*(_QWORD *)(v10 + 8) + 488LL) & 7) != 0 )
    return printk(&unk_24FBDF, "sde_kms_wait_for_commit_done");
  v11 = result;
  _ReadStatusReg(SP_EL0);
  v12 = *(__int64 **)(v10 + 816);
  v13 = v10 + 816;
  if ( v12 == (__int64 *)(v10 + 816) )
    goto LABEL_31;
  v14 = 0;
  while ( 1 )
  {
    v15 = v12[9];
    v16 = v12 - 1;
    if ( v15 == a2 )
    {
      v17 = v14;
    }
    else
    {
      result = sde_encoder_is_cwb_disabling((__int64)(v12 - 1), a2);
      v17 = (__int64)(v12 - 1);
      if ( (result & 1) == 0 )
        goto LABEL_11;
    }
    v18 = v15 != a2;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_kms_wait_for_commit_done",
      1858,
      4,
      *(_DWORD *)(a2 + 112),
      -1059143953,
      a7,
      a8,
      v22);
    v19 = sde_encoder_wait_for_event((__int64)(v12 - 1), v18);
    if ( v19 != -11 )
    {
      if ( v19 )
        break;
    }
    ((void (__fastcall *)(__int64 *))sde_encoder_hw_fence_error_handle)(v12 - 1);
    result = sde_crtc_complete_flip((__int64 *)a2, 0);
    v14 = v17;
LABEL_11:
    v12 = (__int64 *)*v12;
    if ( v12 == (__int64 *)v13 )
      goto LABEL_29;
  }
  v20 = v19;
  if ( v12 == (__int64 *)&unk_8 )
  {
    v21 = -1;
    printk(&unk_2692AF, "sde_kms_wait_for_commit_done");
  }
  else
  {
    printk(&unk_2692AF, "sde_kms_wait_for_commit_done");
    v21 = *((_DWORD *)v12 + 4);
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_kms_wait_for_commit_done",
    1865,
    -1,
    *(_DWORD *)(a2 + 112),
    v21,
    v18,
    v20,
    173);
  result = sde_crtc_request_frame_reset(a2, v16);
  v14 = v17;
LABEL_29:
  if ( v14 )
    result = sde_encoder_virt_reset(v14);
LABEL_31:
  if ( (*(_QWORD *)(*(_QWORD *)(v11 + 152) + 22008LL) & 0x20000000000LL) == 0 )
    return sde_crtc_static_cache_read_kickoff(a2);
  return result;
}
