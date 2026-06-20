__int64 __fastcall mlme_is_aid_set(
        __int64 a1,
        __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v12; // x21
  int v13; // w20
  __int64 v14; // x22
  __int64 v15; // x19

  result = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v12 = *(_QWORD *)(result + 248);
    if ( v12 )
    {
      v13 = *(_DWORD *)(v12 + 260);
      result = wlan_objmgr_get_mlo_ctx();
      if ( result )
      {
        if ( v13 >= 2 )
        {
          v14 = result;
          qdf_mutex_acquire(result + 64);
          result = v14;
        }
        v15 = (*(_QWORD *)(v12 + 8LL * (((a2 & 0x3FFFu) - 1) >> 6)) >> ((unsigned __int8)a2 - 1)) & 1LL;
        if ( v13 >= 2 )
          qdf_mutex_release(result + 64);
        return (unsigned int)v15;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
