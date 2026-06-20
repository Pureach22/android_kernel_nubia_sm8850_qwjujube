_QWORD *__fastcall wlan_mlo_get_mld_ctx_by_mldaddr(const void *a1)
{
  __int64 mlo_ctx; // x0
  __int64 v3; // x19
  _QWORD *v4; // x21
  _QWORD *v5; // x22
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( mlo_ctx )
  {
    v3 = mlo_ctx;
    qdf_mutex_acquire(mlo_ctx);
    v7[0] = 0;
    v4 = nullptr;
    if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v3 + 192), v7) )
    {
      v5 = (_QWORD *)v7[0];
      if ( v7[0] )
      {
        v4 = nullptr;
        while ( (unsigned int)qdf_mem_cmp((char *)v5 + 17, a1, 6u) )
        {
          v7[0] = 0;
          if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v3 + 192), v5, v7) )
          {
            v5 = (_QWORD *)v7[0];
            if ( v7[0] )
              continue;
          }
          goto LABEL_11;
        }
        v4 = v5;
      }
    }
LABEL_11:
    qdf_mutex_release(v3);
  }
  else
  {
    v4 = nullptr;
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
