__int64 __fastcall mlme_get_aid(
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
  __int64 v10; // x0
  __int64 v11; // x19
  unsigned int link_vdev_ix; // w0
  __int64 cmpt_obj; // x0
  __int64 v15; // x19
  int v16; // w20
  __int64 mlo_ctx; // x0
  __int64 v18; // x21
  unsigned __int64 v19; // x8
  __int64 v20; // x21
  unsigned int v21; // w22

  v10 = *(_QWORD *)(a1 + 1360);
  if ( v10 )
  {
    v11 = *(_QWORD *)(*(_QWORD *)(v10 + 2232) + 8LL);
    if ( v11 )
    {
      link_vdev_ix = mlo_get_link_vdev_ix(v10, a1);
      return wlan_mlo_peer_alloc_aid(v11, 0, 0, link_vdev_ix);
    }
    return 0xFFFF;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !cmpt_obj )
    return 0xFFFF;
  v15 = *(_QWORD *)(cmpt_obj + 248);
  if ( !v15 )
    return 0xFFFF;
  v16 = *(_DWORD *)(v15 + 260);
  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !mlo_ctx )
    return 0xFFFF;
  if ( v16 >= 2 )
  {
    v18 = mlo_ctx;
    qdf_mutex_acquire(mlo_ctx + 64);
    mlo_ctx = v18;
  }
  v19 = *(unsigned __int16 *)(v15 + 256);
  v20 = *(unsigned __int16 *)(v15 + 258);
  if ( (unsigned int)v19 >= (unsigned int)v20 )
  {
    v21 = 0xFFFF;
    LOWORD(v20) = *(_WORD *)(v15 + 256);
    if ( v16 >= 2 )
LABEL_17:
      qdf_mutex_release(mlo_ctx + 64);
  }
  else
  {
    while ( ((*(_QWORD *)(v15 + ((v19 >> 3) & 0x1FFFFFFFFFFFFFF8LL)) >> v19) & 1) != 0 )
    {
      if ( v20 == ++v19 )
      {
        v21 = 0xFFFF;
        if ( v16 >= 2 )
          goto LABEL_17;
        goto LABEL_18;
      }
    }
    v21 = v19 + 1;
    LOWORD(v20) = v19;
    *(_QWORD *)(v15 + 8LL * ((unsigned __int16)v19 >> 6)) |= 1LL << v19;
    if ( v16 >= 2 )
      goto LABEL_17;
  }
LABEL_18:
  if ( *(unsigned __int16 *)(v15 + 258) == (unsigned __int16)v20 )
    return 0xFFFFFFFFLL;
  else
    return v21;
}
