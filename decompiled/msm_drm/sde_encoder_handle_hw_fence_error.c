__int64 __fastcall sde_encoder_handle_hw_fence_error(int a1, __int64 a2, unsigned int a3, int a4)
{
  int v8; // w7
  __int64 v9; // x9
  _QWORD *v10; // x8
  _QWORD *v11; // x9
  __int64 v12; // x22
  __int64 v13; // x10
  int v14; // w7
  __int64 v15; // x8
  __int64 v16; // x9
  unsigned int v17; // w8
  unsigned int v24; // w10
  int v25; // w0
  int v26; // w2
  int v27; // w4
  int v28; // w5
  int v29; // w6
  char v31; // [xsp+0h] [xbp-10h]

  sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_handle_hw_fence_error", 6628, -1, a1, a3, a4, 4369, 239);
  if ( !a2 )
    return printk(&unk_23BA37, "sde_encoder_handle_hw_fence_error");
  v9 = *(_QWORD *)(a2 + 136);
  if ( !v9 )
    return printk(&unk_23BA37, "sde_encoder_handle_hw_fence_error");
  v10 = *(_QWORD **)(v9 + 816);
  v11 = (_QWORD *)(v9 + 816);
  while ( 1 )
  {
    if ( v10 == v11 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "failed to get the sde_encoder_phys.\n");
      v25 = sde_dbg_base_evtlog;
      v26 = 6649;
      v27 = a1;
      v28 = 17476;
      goto LABEL_28;
    }
    if ( v10 != (_QWORD *)&unk_8 )
    {
      v12 = v10[24];
      if ( v12 )
      {
        v13 = *(_QWORD *)(v12 + 416);
        if ( v13 )
        {
          if ( *(_DWORD *)(v13 + 64) == a1 )
            break;
        }
      }
    }
    v10 = (_QWORD *)*v10;
  }
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_handle_hw_fence_error", 6642, -1, a1, 13107, -1059143953, v8, v31);
  if ( !*(_QWORD *)v12 || (v15 = *(_QWORD *)(*(_QWORD *)v12 + 80LL)) == 0 || (v16 = *(_QWORD *)(v15 + 2008)) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "unexpected null pointer in cur_master.\n");
    v25 = sde_dbg_base_evtlog;
    v26 = 6655;
    v27 = a1;
    v28 = 21845;
LABEL_28:
    v29 = 60333;
    return sde_evtlog_log(v25, "sde_encoder_handle_hw_fence_error", v26, -1, v27, v28, v29, -1059143953, v31);
  }
  if ( *(_QWORD *)(v16 + 1664) )
  {
    *(_QWORD *)(v12 + 2320) = a3;
    if ( a4 )
    {
      *(_BYTE *)(v15 + 7944) = 1;
      *(_BYTE *)(v12 + 2308) = 1;
      *(_DWORD *)(v12 + 2312) = a4;
    }
    v17 = *(_DWORD *)(v12 + 880);
    do
    {
      if ( !v17 )
        break;
      _X12 = (unsigned int *)(v12 + 880);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v24 = __ldxr(_X12);
        if ( v24 != v17 )
          break;
        if ( !__stlxr(v17 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v24 == v17;
      v17 = v24;
    }
    while ( !_ZF );
    _wake_up(v12 + 896, 3, 0, 0);
    v25 = sde_dbg_base_evtlog;
    v26 = 6679;
    v27 = a1;
    v28 = a4;
    v29 = 8738;
    return sde_evtlog_log(v25, "sde_encoder_handle_hw_fence_error", v26, -1, v27, v28, v29, -1059143953, v31);
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "userspace not enabled handle fence error in kernel.\n");
  return sde_evtlog_log(
           sde_dbg_base_evtlog,
           "sde_encoder_handle_hw_fence_error",
           6664,
           -1,
           a1,
           26214,
           -1059143953,
           v14,
           v31);
}
