__int64 __fastcall sde_crtc_get_fps_mode(__int64 *a1)
{
  __int64 v1; // x8
  _QWORD *i; // x21

  if ( a1 && (v1 = *a1) != 0 )
  {
    for ( i = *(_QWORD **)(v1 + 816); i != (_QWORD *)(v1 + 816); i = (_QWORD *)*i )
    {
      if ( (__int64 *)i[9] == a1 )
      {
        if ( !(unsigned int)sde_encoder_in_cont_splash(i - 1) )
          return sde_encoder_get_fps(i - 1);
        v1 = *a1;
      }
    }
  }
  else
  {
    printk(&unk_25E167, "sde_crtc_get_fps_mode");
  }
  return 0;
}
