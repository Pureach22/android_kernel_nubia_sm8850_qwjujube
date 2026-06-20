__int64 __fastcall mlme_set_aid(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v12; // x20
  unsigned int link_vdev_ix; // w0
  __int64 cmpt_obj; // x0
  __int64 v16; // x21
  int v17; // w22
  __int64 mlo_ctx; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  __int64 v28; // x5
  __int16 v29; // w20
  unsigned int v30; // w19

  v10 = *(_QWORD *)(a1 + 1360);
  if ( v10 )
  {
    v12 = *(_QWORD *)(*(_QWORD *)(v10 + 2232) + 8LL);
    if ( v12 )
    {
      link_vdev_ix = mlo_get_link_vdev_ix(*(_QWORD *)(a1 + 1360), a1);
      return wlan_mlo_peer_set_aid(v12, 0, link_vdev_ix, a2);
    }
    return 16;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cmpt_obj )
    return 16;
  v16 = *(_QWORD *)(cmpt_obj + 248);
  if ( !v16 )
    return 16;
  v17 = *(_DWORD *)(v16 + 260);
  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !mlo_ctx )
    return 16;
  if ( v17 >= 2 )
  {
    v27 = mlo_ctx;
    qdf_mutex_acquire(mlo_ctx + 64);
    mlo_ctx = v27;
  }
  v28 = *(unsigned __int16 *)(v16 + 256);
  v29 = a2;
  if ( (unsigned int)v28 > (unsigned __int16)a2
    || *(unsigned __int16 *)(v16 + 258) <= (unsigned int)(unsigned __int16)a2 )
  {
    if ( v17 >= 2 )
    {
      qdf_mutex_release(mlo_ctx + 64);
      v28 = *(unsigned __int16 *)(v16 + 256);
    }
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Assoc id %d is not in bounds, start aid %d, max aid %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_mlme_peer_set_aid",
      (unsigned __int16)a2,
      v28,
      *(unsigned __int16 *)(v16 + 258));
    return 16;
  }
  if ( ((*(_QWORD *)(v16 + (((unsigned __int64)((a2 & 0x3FFF) - 1) >> 3) & 0x1FFFFFF8)) >> ((unsigned __int8)a2 - 1)) & 1) != 0 )
  {
    v30 = 16;
  }
  else
  {
    v30 = 0;
    *(_QWORD *)(v16 + (((unsigned __int64)((v29 & 0x3FFFu) - 1) >> 3) & 0x1FFFFFF8)) |= 1LL << ((unsigned __int8)v29 - 1);
  }
  if ( v17 >= 2 )
    qdf_mutex_release(mlo_ctx + 64);
  return v30;
}
