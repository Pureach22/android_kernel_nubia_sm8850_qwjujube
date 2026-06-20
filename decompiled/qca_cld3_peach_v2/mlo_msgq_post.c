__int64 __fastcall mlo_msgq_post(int a1, __int64 a2, __int64 *a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  __int64 v21; // x0
  unsigned int *v22; // x8
  unsigned int v30; // w8
  unsigned int v33; // w8
  unsigned int v36; // w8

  if ( a1 > 2 )
  {
    if ( a1 <= 5 )
    {
      if ( a1 == 3 )
      {
        mlo_mlme_peer_delete(*a3);
        goto LABEL_23;
      }
      if ( a1 == 4 )
      {
        mlo_mlme_peer_deauth(*a3, *((unsigned __int8 *)a3 + 8));
LABEL_23:
        wlan_objmgr_peer_release_ref(*a3, 0x5Au, v4, v5, v6, v7, v8, v9, v10, v11);
        return 0;
      }
      return 0;
    }
    if ( a1 == 6 )
    {
      mlo_mlme_bridge_peer_create(*a3, a3[1], (__int64)(a3 + 2), a3[3]);
      _X9 = (unsigned int *)(a3[1] + 188);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v36 = __ldxr(_X9);
        v22 = (unsigned int *)(v36 - 1);
      }
      while ( __stlxr((unsigned int)v22, _X9) );
      __dmb(0xBu);
      if ( (_DWORD)v22 )
        goto LABEL_19;
    }
    else
    {
      if ( a1 != 7 )
        return 0;
      mlo_mlme_peer_reassoc(*a3, a3[1], (__int64)(a3 + 2), a3[3]);
      v20 = a3[3];
      if ( v20 )
        _qdf_nbuf_free(v20);
      _X9 = (unsigned int *)(a3[1] + 188);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v30 = __ldxr(_X9);
        v22 = (unsigned int *)(v30 - 1);
      }
      while ( __stlxr((unsigned int)v22, _X9) );
      __dmb(0xBu);
      if ( (_DWORD)v22 )
      {
LABEL_19:
        wlan_objmgr_vdev_release_ref(*a3, 0x5Au, v22, v12, v13, v14, v15, v16, v17, v18, v19);
        return 0;
      }
    }
LABEL_18:
    v12 = mlo_peer_cleanup();
    goto LABEL_19;
  }
  switch ( a1 )
  {
    case 0:
      mlo_mlme_peer_create(*a3, a3[1], (__int64)(a3 + 2), a3[3]);
      v21 = a3[3];
      if ( v21 )
        _qdf_nbuf_free(v21);
      _X9 = (unsigned int *)(a3[1] + 188);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v33 = __ldxr(_X9);
        v22 = (unsigned int *)(v33 - 1);
      }
      while ( __stlxr((unsigned int)v22, _X9) );
      __dmb(0xBu);
      if ( (_DWORD)v22 )
        goto LABEL_19;
      goto LABEL_18;
    case 1:
      mlo_mlme_peer_assoc(*a3);
      goto LABEL_23;
    case 2:
      mlo_mlme_peer_assoc_fail(*a3);
      goto LABEL_23;
  }
  return 0;
}
