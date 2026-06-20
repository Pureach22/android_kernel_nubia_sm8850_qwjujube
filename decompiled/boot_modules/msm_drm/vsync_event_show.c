__int64 __fastcall vsync_event_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 *v4; // x21
  __int64 v5; // x8
  __int64 *i; // x23
  int avr_status; // w20

  if ( a1 && a3 )
  {
    v4 = *(__int64 **)(a1 + 152);
    mutex_lock(v4 + 577);
    if ( *((_BYTE *)v4 + 4512) == 1 )
    {
      v5 = *v4;
      for ( i = *(__int64 **)(*v4 + 816); i != (__int64 *)(v5 + 816); i = (__int64 *)*i )
      {
        if ( ((*(_DWORD *)(v4[251] + 20) >> *((_DWORD *)i + 15)) & 1) != 0 )
        {
          if ( (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(i - 1) & 1) == 0 )
          {
            avr_status = sde_encoder_get_avr_status(i - 1);
            goto LABEL_11;
          }
          v5 = *v4;
        }
      }
    }
    avr_status = -32;
LABEL_11:
    mutex_unlock(v4 + 577);
    return (int)scnprintf(a3, 4096, "VSYNC=%llu\nAVR_STATUS=%d\n", v4[554], avr_status);
  }
  else
  {
    printk(&unk_2120FD, "vsync_event_show");
    return -11;
  }
}
