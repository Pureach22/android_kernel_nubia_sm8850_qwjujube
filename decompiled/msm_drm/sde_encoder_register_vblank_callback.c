_QWORD *__fastcall sde_encoder_register_vblank_callback(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  bool v8; // w23
  _BOOL4 v12; // w22
  __int64 v13; // x0
  __int64 v14; // x8
  _QWORD *result; // x0
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 (__fastcall *v18)(__int64, __int64, bool); // x8
  __int64 (*v19)(void); // x8
  void *v20; // x0
  __int64 (*v21)(void); // x8
  __int64 (*v22)(void); // x8
  __int64 (*v23)(void); // x8
  char v24; // [xsp+0h] [xbp+0h]

  v8 = a2 != 0;
  if ( !a1 )
    return (_QWORD *)printk(&unk_26C69D, "sde_encoder_register_vblank_callback");
  v12 = a2 != 0;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "enc%d enable:%d\n", *(unsigned int *)(a1 + 24), a2 != 0);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_register_vblank_callback",
    4862,
    -1,
    *(_DWORD *)(a1 + 24),
    v12,
    -1059143953,
    a8,
    v24);
  v13 = raw_spin_lock_irqsave(a1 + 128);
  *(_QWORD *)(a1 + 504) = a2;
  *(_QWORD *)(a1 + 512) = a3;
  raw_spin_unlock_irqrestore(a1 + 128, v13);
  if ( !*(_QWORD *)a1 )
  {
    v20 = &unk_26FCAB;
    goto LABEL_34;
  }
  v14 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v14 || !*(_QWORD *)(v14 + 8) )
  {
    v20 = &unk_234896;
LABEL_34:
    printk(v20, "sde_encoder_get_kms");
    result = nullptr;
LABEL_8:
    v18 = *(__int64 (__fastcall **)(__int64, __int64, bool))(a1 + 8LL * (unsigned int)result + 5272);
    if ( v18 )
    {
      if ( *((_DWORD *)v18 - 1) != -1597007658 )
        __break(0x8228u);
      result = (_QWORD *)v18(a1, 2, a2 != 0);
      goto LABEL_12;
    }
    if ( !*(_DWORD *)(a1 + 196) )
      goto LABEL_12;
    result = *(_QWORD **)(a1 + 200);
    if ( result )
    {
      if ( *(_BYTE *)(a1 + 748) == 1 )
      {
        if ( *(_BYTE *)(a1 + 750) != 1 || (v19 = (__int64 (*)(void))result[14]) == nullptr )
        {
          v19 = (__int64 (*)(void))result[15];
          if ( !v19 )
            goto LABEL_25;
        }
      }
      else
      {
        v19 = (__int64 (*)(void))result[13];
        if ( !v19 )
          goto LABEL_25;
      }
      if ( *((_DWORD *)v19 - 1) != -320796721 )
        __break(0x8228u);
      result = (_QWORD *)v19();
    }
LABEL_25:
    if ( *(_DWORD *)(a1 + 196) < 2u )
      goto LABEL_12;
    result = *(_QWORD **)(a1 + 208);
    if ( result )
    {
      if ( (*(_BYTE *)(a1 + 748) & 1) != 0 )
      {
        if ( *(_BYTE *)(a1 + 750) != 1 || (v21 = (__int64 (*)(void))result[14]) == nullptr )
        {
          v21 = (__int64 (*)(void))result[15];
          if ( !v21 )
            goto LABEL_39;
        }
      }
      else
      {
        v21 = (__int64 (*)(void))result[13];
        if ( !v21 )
          goto LABEL_39;
      }
      if ( *((_DWORD *)v21 - 1) != -320796721 )
        __break(0x8228u);
      result = (_QWORD *)v21();
    }
LABEL_39:
    if ( *(_DWORD *)(a1 + 196) < 3u )
      goto LABEL_12;
    result = *(_QWORD **)(a1 + 216);
    if ( result )
    {
      if ( (*(_BYTE *)(a1 + 748) & 1) != 0 )
      {
        if ( *(_BYTE *)(a1 + 750) != 1 || (v22 = (__int64 (*)(void))result[14]) == nullptr )
        {
          v22 = (__int64 (*)(void))result[15];
          if ( !v22 )
            goto LABEL_50;
        }
      }
      else
      {
        v22 = (__int64 (*)(void))result[13];
        if ( !v22 )
          goto LABEL_50;
      }
      if ( *((_DWORD *)v22 - 1) != -320796721 )
        __break(0x8228u);
      result = (_QWORD *)v22();
    }
LABEL_50:
    if ( *(_DWORD *)(a1 + 196) < 4u )
      goto LABEL_12;
    result = *(_QWORD **)(a1 + 224);
    if ( !result )
      goto LABEL_61;
    if ( (*(_BYTE *)(a1 + 748) & 1) != 0 )
    {
      if ( *(_BYTE *)(a1 + 750) != 1 || (v23 = (__int64 (*)(void))result[14]) == nullptr )
      {
        v23 = (__int64 (*)(void))result[15];
        if ( !v23 )
          goto LABEL_61;
      }
    }
    else
    {
      v23 = (__int64 (*)(void))result[13];
      if ( !v23 )
        goto LABEL_61;
    }
    if ( *((_DWORD *)v23 - 1) != -320796721 )
      __break(0x8228u);
    result = (_QWORD *)v23();
LABEL_61:
    if ( *(_DWORD *)(a1 + 196) > 4u )
      goto LABEL_62;
LABEL_12:
    *(_BYTE *)(a1 + 1312) = v8;
    return result;
  }
  result = (_QWORD *)sde_kms_get_disp_op();
  if ( (unsigned int)result < 3 )
    goto LABEL_8;
LABEL_62:
  __break(0x5512u);
  return (_QWORD *)sde_encoder_register_frame_event_callback(result, v16, v17);
}
