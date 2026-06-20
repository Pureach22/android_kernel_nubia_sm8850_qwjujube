__int64 __fastcall mlme_vdev_reconfig_timer_cb(__int64 result)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 512);
    if ( v1 )
    {
      v2 = *(__int64 (**)(void))(v1 + 216);
      if ( v2 )
      {
        if ( *((_DWORD *)v2 - 1) != 329685504 )
          __break(0x8228u);
        return v2();
      }
    }
  }
  return result;
}
