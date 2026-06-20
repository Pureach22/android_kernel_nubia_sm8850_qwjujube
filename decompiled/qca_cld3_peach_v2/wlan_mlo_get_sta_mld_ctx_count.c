__int64 wlan_mlo_get_sta_mld_ctx_count()
{
  __int64 mlo_ctx; // x0
  __int64 v1; // x19
  unsigned int v2; // w20
  _QWORD *v3; // x1
  __int64 v4; // x8
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( mlo_ctx )
  {
    v1 = mlo_ctx;
    qdf_mutex_acquire(mlo_ctx);
    v6[0] = 0;
    v2 = 0;
    if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v1 + 192), v6) )
    {
      v3 = (_QWORD *)v6[0];
      if ( v6[0] )
      {
        v2 = 0;
        do
        {
          v4 = *(__int64 *)((char *)&qword_8B0 + (_QWORD)v3);
          v6[0] = 0;
          if ( v4 )
            ++v2;
          if ( (unsigned int)qdf_list_peek_next((_QWORD *)(v1 + 192), v3, v6) )
            break;
          v3 = (_QWORD *)v6[0];
        }
        while ( v6[0] );
      }
    }
    qdf_mutex_release(v1);
  }
  else
  {
    v2 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
