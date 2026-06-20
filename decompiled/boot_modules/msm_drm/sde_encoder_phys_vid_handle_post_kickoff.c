__int64 __fastcall sde_encoder_phys_vid_handle_post_kickoff(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *v2; // x23
  __int64 v4; // x22
  __int64 result; // x0
  unsigned int v6; // w21
  int v7; // w4
  __int64 v8; // x8
  int v9; // w5
  int v10; // w4
  int v11; // w9
  __int64 v12; // x22
  __int64 v13; // x0
  void (__fastcall *v14)(__int64, __int64); // x9
  int v15; // w8
  void (*v16)(void); // x8
  void (__fastcall *v17)(__int64, __int64); // x8
  void (__fastcall *v18)(__int64, __int64); // x8
  __int64 v19; // x0
  __int64 v20; // x22
  void (*v21)(void); // x8
  int v22; // w4
  void *v23; // x0
  __int64 v24; // x8
  int v25; // w5
  _DWORD *v26; // x8
  __int64 v27; // x0
  __int64 v28; // x22
  void (*v29)(void); // x8
  int v30; // w4
  __int64 v31; // x8
  int v32; // w5
  _DWORD *v33; // x8
  __int64 v34; // x0
  __int64 v35; // x8
  void (*v36)(void); // x8
  int v37; // w4
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    v23 = &unk_26FCAB;
    return printk(v23, "sde_encoder_phys_vid_handle_post_kickoff");
  }
  v1 = *(_QWORD *)a1;
  v2 = *(_QWORD **)(a1 + 8);
  v4 = v2[314];
  result = sde_encoder_get_disp_op(*(_QWORD *)a1);
  v6 = result;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
    {
      v7 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      v8 = *(_QWORD *)(a1 + 424);
      if ( v8 )
      {
LABEL_5:
        v9 = *(_DWORD *)(v8 + 32) - 1;
LABEL_8:
        result = _drm_dev_dbg(0, 0, 0, "enc%d intf%d enable_state %d\n", v7, v9, *(_DWORD *)(a1 + 832));
        goto LABEL_9;
      }
    }
    else
    {
      v7 = -1;
      v8 = *(_QWORD *)(a1 + 424);
      if ( v8 )
        goto LABEL_5;
    }
    v9 = -1;
    goto LABEL_8;
  }
LABEL_9:
  if ( *(_DWORD *)(a1 + 832) == 2 )
  {
    v10 = *(_QWORD *)a1 ? *(_DWORD *)(*(_QWORD *)a1 + 24LL) : -1;
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_encoder_phys_vid_handle_post_kickoff",
               2603,
               -1,
               v10,
               *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
               *(_DWORD *)(a1 + 664),
               -1059143953,
               vars0);
    if ( *(_DWORD *)(a1 + 832) == 2 )
    {
      v11 = *(_DWORD *)(a1 + 664);
      if ( (v11 & 0xFFFFFFFE) != 2 )
      {
        if ( *(_BYTE *)(v1 + 753) == 1 )
        {
          if ( v6 >= 3 )
            goto LABEL_92;
          v16 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + 8LL * v6 + 920);
          if ( v16 )
          {
            if ( *((_DWORD *)v16 - 1) != -1839426449 )
              __break(0x8228u);
            v16();
          }
          v17 = (void (__fastcall *)(__int64, __int64))v2[400];
          if ( v17 )
          {
            if ( *((_DWORD *)v17 - 1) != 657136229 )
              __break(0x8228u);
            v17(v4, 25);
          }
        }
        v18 = (void (__fastcall *)(__int64, __int64))v2[406];
        if ( v18 )
        {
          v19 = v2[345];
          if ( *((_DWORD *)v18 - 1) != -1297827279 )
            __break(0x8228u);
          v18(v19, 1);
        }
        result = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 824));
        if ( v6 > 2 )
          goto LABEL_92;
        v20 = result;
        v21 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + 8LL * v6 + 176);
        if ( v21 )
        {
          if ( *((_DWORD *)v21 - 1) != -1839426449 )
            __break(0x8228u);
          v21();
        }
        raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v20);
        result = ((__int64 (__fastcall *)(__int64))sde_encoder_phys_vid_poll_for_active_region)(a1);
        if ( (_DWORD)result && (_drm_debug & 4) != 0 )
        {
          if ( *(_QWORD *)a1 )
            v22 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
          else
            v22 = -1;
          v24 = *(_QWORD *)(a1 + 424);
          if ( v24 )
            v25 = *(_DWORD *)(v24 + 32) - 1;
          else
            v25 = -1;
          result = _drm_dev_dbg(0, 0, 0, "enc%d intf%d poll for active failed ret:%d\n", v22, v25, result);
        }
        v26 = (_DWORD *)v2[406];
        if ( v26 )
        {
          v27 = v2[345];
          if ( *(v26 - 1) != -1297827279 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64, _QWORD))v26)(v27, 0);
        }
        v15 = 4;
        goto LABEL_58;
      }
      if ( *(_QWORD *)a1 && v11 == 2 && (*(_BYTE *)(*(_QWORD *)a1 + 4936LL) & 1) != 0 )
      {
        if ( v6 > 2 )
          goto LABEL_92;
        if ( *(_QWORD *)(*(_QWORD *)(a1 + 424) + 8LL * v6 + 1280) )
        {
          v12 = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 824));
          v13 = *(_QWORD *)(a1 + 424);
          v14 = *(void (__fastcall **)(__int64, __int64))(v13 + 8LL * v6 + 1280);
          if ( *((_DWORD *)v14 - 1) != -1913620264 )
            __break(0x8229u);
          v14(v13, 1);
          result = raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v12);
          v15 = 3;
LABEL_58:
          *(_DWORD *)(a1 + 832) = v15;
        }
      }
    }
  }
  if ( *(_BYTE *)(a1 + 2348) != 1 )
    goto LABEL_79;
  result = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 824));
  if ( v6 > 2 )
    goto LABEL_92;
  v28 = result;
  v29 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + 8LL * v6 + 176);
  if ( v29 )
  {
    if ( *((_DWORD *)v29 - 1) != -1839426449 )
      __break(0x8228u);
    v29();
  }
  raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v28);
  result = ((__int64 (__fastcall *)(__int64))sde_encoder_phys_vid_poll_for_active_region)(a1);
  if ( (_DWORD)result && (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
    {
      v30 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      v31 = *(_QWORD *)(a1 + 424);
      if ( v31 )
      {
LABEL_69:
        v32 = *(_DWORD *)(v31 + 32) - 1;
LABEL_72:
        result = _drm_dev_dbg(0, 0, 0, "enc%d intf%d poll for active failed ret:%d\n", v30, v32, result);
        goto LABEL_73;
      }
    }
    else
    {
      v30 = -1;
      v31 = *(_QWORD *)(a1 + 424);
      if ( v31 )
        goto LABEL_69;
    }
    v32 = -1;
    goto LABEL_72;
  }
LABEL_73:
  if ( !*(_DWORD *)(v1 + 4912) )
  {
    v33 = (_DWORD *)v2[406];
    if ( v33 )
    {
      v34 = v2[345];
      if ( *(v33 - 1) != -1297827279 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD))v33)(v34, 0);
    }
  }
  *(_BYTE *)(a1 + 2348) = 0;
LABEL_79:
  v35 = *(_QWORD *)(a1 + 8);
  if ( !v35 || !*(_DWORD *)(v35 + 4676) )
    return result;
  if ( v6 > 2 )
  {
LABEL_92:
    __break(0x5512u);
    return sde_encoder_phys_needs_single_flush(result);
  }
  result = *(_QWORD *)(a1 + 424);
  v36 = *(void (**)(void))(result + 8LL * v6 + 704);
  if ( v36 && (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 512) + 152LL) + 22140LL) & 1) == 0 )
  {
    if ( *((_DWORD *)v36 - 1) != -1596594834 )
      __break(0x8228u);
    v36();
    v37 = *(_QWORD *)a1 ? *(_DWORD *)(*(_QWORD *)a1 + 24LL) : -1;
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_encoder_phys_vid_handle_post_kickoff",
               2674,
               -1,
               v37,
               *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
               48059,
               -1059143953,
               vars0);
    if ( *(_BYTE *)(v1 + 749) == 1 )
    {
      v23 = &unk_231AA3;
      return printk(v23, "sde_encoder_phys_vid_handle_post_kickoff");
    }
  }
  return result;
}
