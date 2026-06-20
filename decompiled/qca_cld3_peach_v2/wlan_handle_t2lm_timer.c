void __fastcall wlan_handle_t2lm_timer(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v11; // x1
  __int64 v12; // x0

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 1360);
    if ( v9 )
    {
      if ( wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9) )
      {
        if ( *(_BYTE *)(v9 + 2250) == 1 )
        {
          v11 = *(unsigned int *)(v9 + 2256);
          v12 = a1;
          if ( (_DWORD)v11 == 0xFFFFFF )
            return;
        }
        else
        {
          if ( *(_BYTE *)(v9 + 2305) != 1 )
            return;
          v11 = *(unsigned __int16 *)(v9 + 2308);
          v12 = a1;
        }
        wlan_mlo_t2lm_timer_start(v12, v11);
      }
    }
  }
}
