__int64 __fastcall sde_crtc_get_dfps_maxfps(__int64 *a1)
{
  __int64 v1; // x8
  __int64 *i; // x21
  void *v5; // x0
  const char *v6; // x1

  if ( a1 && (v1 = *a1) != 0 )
  {
    for ( i = *(__int64 **)(v1 + 816); i != (__int64 *)(v1 + 816); i = (__int64 *)*i )
    {
      if ( ((*(_DWORD *)(a1[251] + 20) >> *((_DWORD *)i + 15)) & 1) != 0 )
      {
        if ( !(unsigned int)sde_encoder_in_cont_splash(i - 1) )
        {
          if ( i != (__int64 *)&unk_8 )
            return *((unsigned int *)i + 992);
          v5 = &unk_26FCAB;
          v6 = "sde_encoder_get_dfps_maxfps";
          goto LABEL_12;
        }
        v1 = *a1;
      }
    }
  }
  else
  {
    v5 = &unk_25E167;
    v6 = "sde_crtc_get_dfps_maxfps";
LABEL_12:
    printk(v5, v6);
  }
  return 0;
}
