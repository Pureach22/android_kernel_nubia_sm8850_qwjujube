__int64 __fastcall hfi_kms_prepare_commit(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v5; // x23
  __int64 *v6; // x8
  __int64 v7; // x24
  __int64 v8; // x25
  unsigned int v9; // w26
  __int64 v10; // x8
  __int64 *i; // x22
  int display_id; // w0

  if ( !a1 )
    return 4294967274LL;
  if ( *(int *)(*(_QWORD *)(a2 + 8) + 860LL) >= 1 )
  {
    v3 = *(_QWORD *)(a1 + 6440);
    v5 = 0;
    while ( 1 )
    {
      v6 = (__int64 *)(*(_QWORD *)(a2 + 32) + 56 * v5);
      v7 = *v6;
      if ( *v6 )
        break;
LABEL_4:
      if ( ++v5 >= *(int *)(*(_QWORD *)(a2 + 8) + 860LL) )
        goto LABEL_21;
    }
    v8 = v6[3];
    v9 = *(_DWORD *)(v8 + 20);
    if ( v9 )
    {
      if ( (_drm_debug & 4) == 0 )
        goto LABEL_9;
    }
    else
    {
      v9 = *(_DWORD *)(v7 + 7872);
      if ( (_drm_debug & 4) == 0 )
      {
LABEL_9:
        v10 = *(_QWORD *)(a1 + 136);
        for ( i = *(__int64 **)(v10 + 816); i != (__int64 *)(v10 + 816); i = (__int64 *)*i )
        {
          if ( ((v9 >> *((_DWORD *)i + 15)) & 1) != 0 )
          {
            display_id = hfi_crtc_get_display_id((__int64 *)v7, v8);
            if ( display_id == -1 )
            {
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "no display for encoder%p\n", i - 1);
            }
            else
            {
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "creating cmd buffer for disp_id:%d\n", display_id);
              if ( !hfi_adapter_get_cmd_buf(v3 + 8) )
              {
                printk(&unk_211E26, "hfi_kms_prepare_commit");
                return 4294967274LL;
              }
            }
          }
          v10 = *(_QWORD *)(a1 + 136);
        }
        goto LABEL_4;
      }
    }
    _drm_dev_dbg(0, 0, 0, "crtc:%d encoder_mask:0x%x\n", *(_DWORD *)(v7 + 112), v9);
    goto LABEL_9;
  }
LABEL_21:
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "done\n");
  return 0;
}
