__int64 __fastcall sde_encoder_frame_done_callback(__int64 result, __int64 a2, unsigned int a3)
{
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x4
  __int64 v6; // x8
  int v7; // w23
  __int64 v10; // x22
  _DWORD *v11; // x8
  __int64 v12; // x8
  unsigned __int64 v13; // x8
  bool v14; // w26
  __int64 v15; // x23
  __int64 v16; // x25
  char v17; // w27
  int v19; // w8
  unsigned int v25; // w10
  _DWORD *v26; // x9
  __int64 v27; // x8
  unsigned int v28; // w11
  unsigned int v30; // w13
  void *v32; // x0
  char v33; // [xsp+0h] [xbp-10h]

  v3 = result;
  if ( !result )
  {
    printk(&unk_26FCAB, "sde_encoder_get_kms");
    return printk(&unk_27A1CE, "sde_encoder_frame_done_callback");
  }
  if ( !*(_QWORD *)result )
  {
    v32 = &unk_26FCAB;
    goto LABEL_58;
  }
  v4 = *(_QWORD *)(*(_QWORD *)result + 56LL);
  if ( !v4 || (v5 = *(_QWORD *)(v4 + 8)) == 0 )
  {
    v32 = &unk_234896;
LABEL_58:
    printk(v32, "sde_encoder_get_kms");
    return printk(&unk_27A1CE, "sde_encoder_frame_done_callback");
  }
  v6 = *(_QWORD *)(result + 328);
  if ( !v6 )
    return printk(&unk_27A1CE, "sde_encoder_frame_done_callback");
  v7 = *(_DWORD *)(result + 648);
  *(_QWORD *)(result + 616) = *(_QWORD *)(v6 + 8);
  if ( (*(_QWORD *)(*(_QWORD *)(v5 + 152) + 22008LL) & 0x1000000) == 0
    || (a3 & 0x16) != 0x10
    || (result = sde_encoder_calc_last_vsync_timestamp(result), (v10 = result) == 0) )
  {
    result = ktime_get(result);
    v10 = result;
  }
  if ( (a3 & 7) == 0 || v7 != 2 || (*(_BYTE *)(v3 + 4922) & 1) != 0 )
  {
    v11 = *(_DWORD **)(v3 + 600);
    if ( v11 )
    {
      if ( *(v11 - 1) != -458624868 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v11)(v3 + 608, a3, v10);
    }
    return result;
  }
  v12 = *(_QWORD *)(a2 + 8);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 2512)) == 0 )
  {
    v14 = 0;
    LODWORD(v13) = *(_DWORD *)(v3 + 196);
    if ( !(_DWORD)v13 )
      goto LABEL_38;
LABEL_22:
    v15 = 0;
    v16 = v3 + 576;
    v17 = 1;
    while ( v15 != 4 )
    {
      if ( *(_QWORD *)(v3 + 200 + 8 * v15) == a2 )
      {
        _X24 = (int *)(v16 + 4 * v15);
        result = sde_evtlog_log(
                   sde_dbg_base_evtlog,
                   "sde_encoder_frame_done_callback",
                   4969,
                   4,
                   *(_DWORD *)(v3 + 24),
                   v15,
                   *_X24,
                   -1059143953,
                   v33);
        v19 = *_X24;
        while ( v19 != 2 )
        {
          __asm { PRFM            #0x11, [X24] }
          while ( 1 )
          {
            v25 = __ldxr((unsigned int *)_X24);
            if ( v25 != v19 )
              break;
            if ( !__stlxr(v19 + 1, (unsigned int *)_X24) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v25 == v19;
          v19 = v25;
          if ( _ZF )
            goto LABEL_26;
        }
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_frame_done_callback",
          4974,
          -1,
          *(_DWORD *)(v3 + 24),
          a3,
          *(_DWORD *)(a2 + 672),
          60333,
          239);
        return printk(&unk_227352, "sde_encoder_frame_done_callback");
      }
LABEL_26:
      if ( !v14 )
        v17 &= *(_DWORD *)(v16 + 4 * v15) != 0;
      v13 = *(unsigned int *)(v3 + 196);
      if ( ++v15 >= v13 )
      {
        if ( (v17 & 1) == 0 )
          return result;
        goto LABEL_38;
      }
    }
    goto LABEL_62;
  }
  v14 = *(_DWORD *)(v13 + 1376) == 10;
  LODWORD(v13) = *(_DWORD *)(v3 + 196);
  if ( (_DWORD)v13 )
    goto LABEL_22;
LABEL_38:
  v26 = *(_DWORD **)(v3 + 600);
  if ( v26 )
  {
    if ( *(v26 - 1) != -458624868 )
      __break(0x8229u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v26)(v3 + 608, a3, v10);
    LODWORD(v13) = *(_DWORD *)(v3 + 196);
  }
  if ( (_DWORD)v13 )
  {
    v27 = 0;
    while ( v27 != 5 )
    {
      _X10 = (unsigned int *)(v3 + 576 + 4 * v27);
      v28 = *_X10;
      do
      {
        if ( !v28 )
          break;
        __asm { PRFM            #0x11, [X10] }
        while ( 1 )
        {
          v30 = __ldxr(_X10);
          if ( v30 != v28 )
            break;
          if ( !__stlxr(v28 - 1, _X10) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v30 == v28;
        v28 = v30;
      }
      while ( !_ZF );
      if ( ++v27 >= (unsigned __int64)*(unsigned int *)(v3 + 196) )
        return result;
    }
LABEL_62:
    __break(0x5512u);
    return sde_encoder_late_register();
  }
  return result;
}
