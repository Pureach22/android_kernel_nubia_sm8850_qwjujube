__int64 __fastcall sde_kms_wait_for_frame_transfer_complete(
        __int64 result,
        __int64 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v9; // x9
  __int64 v10; // x8
  _QWORD *v11; // x22
  _QWORD *v12; // x23
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !result )
    return printk(&unk_223EAA, "sde_kms_wait_for_frame_transfer_complete");
  if ( !a2 )
    return printk(&unk_223EAA, "sde_kms_wait_for_frame_transfer_complete");
  v9 = a2[251];
  if ( !v9 )
    return printk(&unk_223EAA, "sde_kms_wait_for_frame_transfer_complete");
  v10 = *a2;
  if ( !*a2 )
    return printk(&unk_223EAA, "sde_kms_wait_for_frame_transfer_complete");
  if ( (*(_BYTE *)(v9 + 8) & 1) != 0 )
  {
    if ( (*(_BYTE *)(v9 + 9) & 1) != 0 )
    {
      v11 = *(_QWORD **)(v10 + 816);
      v12 = (_QWORD *)(v10 + 816);
      if ( v11 != (_QWORD *)(v10 + 816) )
      {
        while ( 1 )
        {
          if ( (__int64 *)v11[9] == a2 )
          {
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "sde_kms_wait_for_frame_transfer_complete",
              294,
              4,
              *((_DWORD *)a2 + 28),
              -1059143953,
              a7,
              a8,
              vars0);
            result = sde_encoder_wait_for_event((__int64)(v11 - 1), 1u);
            if ( (_DWORD)result != -11 )
            {
              if ( (_DWORD)result )
                break;
            }
          }
          v11 = (_QWORD *)*v11;
          if ( v11 == v12 )
            return result;
        }
        return printk(&unk_27DB3E, "sde_kms_wait_for_frame_transfer_complete");
      }
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      return _drm_dev_dbg(0, 0, 0, "[crtc:%d] not active\n", *((unsigned int *)a2 + 28));
    }
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    return _drm_dev_dbg(0, 0, 0, "[crtc:%d] not enable\n", *((unsigned int *)a2 + 28));
  }
  return result;
}
