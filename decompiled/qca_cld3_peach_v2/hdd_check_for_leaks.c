_QWORD *__fastcall hdd_check_for_leaks(
        _QWORD *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x21
  __int64 v10; // x8
  _QWORD *v11; // x22
  _QWORD *v12; // x23
  __int64 v13; // x24
  __int64 v14; // x20
  __int64 v15; // x19
  __int64 v16; // x8
  _QWORD *v17; // x22
  _QWORD *v18; // x23
  __int64 v19; // x24
  __int64 v20; // x20
  __int64 v21; // x19
  __int64 v22; // x8
  _QWORD *v23; // x22
  _QWORD *v24; // x23
  __int64 v25; // x24
  __int64 v26; // x20
  __int64 v27; // x19
  __int64 v28; // x8
  _QWORD *v29; // x22
  _QWORD *v30; // x23
  __int64 v31; // x24
  __int64 v32; // x20
  __int64 v33; // x19
  __int64 v34; // x8
  _QWORD *v35; // x22
  _QWORD *v36; // x23
  __int64 v37; // x24
  __int64 v38; // x20
  __int64 v39; // x19
  __int64 v40; // x8
  _QWORD *v41; // x22
  _QWORD *v42; // x23
  __int64 v43; // x24
  __int64 v44; // x20
  __int64 v45; // x19
  __int64 v46; // x19
  __int64 i; // x20
  unsigned int *v48; // x8
  __int64 v49; // x19
  __int64 j; // x20
  unsigned int *v51; // x8
  __int64 v52; // x19
  __int64 k; // x20
  unsigned int *v54; // x8
  __int64 v55; // x19
  __int64 m; // x20
  unsigned int *v57; // x8
  __int64 v58; // x19
  __int64 n; // x20
  unsigned int *v60; // x8
  __int64 v61; // x19
  __int64 ii; // x20
  unsigned int *v63; // x8
  __int64 v64; // x19
  __int64 jj; // x20
  unsigned int *v66; // x8

  v9 = (_QWORD *)*result;
  if ( *result )
  {
    v10 = v9[9];
    if ( v10 )
    {
      v11 = (_QWORD *)(v10 + 192);
      v12 = *(_QWORD **)(v10 + 192);
      if ( v12 != (_QWORD *)(v10 + 192) )
      {
        v13 = v10 + 244;
        do
        {
          v14 = 0;
          v15 = (__int64)(v12 - 2);
          v12 = (_QWORD *)*v12;
          do
          {
            if ( *(int *)(v13 + 4 * v14) >= 1 )
              result = (_QWORD *)wlan_objmgr_peer_release_ref(v15, v14, a2, a3, a4, a5, a6, a7, a8, a9);
            ++v14;
          }
          while ( v14 != 109 );
        }
        while ( v12 != v11 );
      }
    }
    v16 = v9[10];
    if ( v16 )
    {
      v17 = (_QWORD *)(v16 + 192);
      v18 = *(_QWORD **)(v16 + 192);
      if ( v18 != (_QWORD *)(v16 + 192) )
      {
        v19 = v16 + 244;
        do
        {
          v20 = 0;
          v21 = (__int64)(v18 - 2);
          v18 = (_QWORD *)*v18;
          do
          {
            if ( *(int *)(v19 + 4 * v20) >= 1 )
              result = (_QWORD *)wlan_objmgr_peer_release_ref(v21, v20, a2, a3, a4, a5, a6, a7, a8, a9);
            ++v20;
          }
          while ( v20 != 109 );
        }
        while ( v18 != v17 );
      }
    }
    v22 = v9[11];
    if ( v22 )
    {
      v23 = (_QWORD *)(v22 + 192);
      v24 = *(_QWORD **)(v22 + 192);
      if ( v24 != (_QWORD *)(v22 + 192) )
      {
        v25 = v22 + 244;
        do
        {
          v26 = 0;
          v27 = (__int64)(v24 - 2);
          v24 = (_QWORD *)*v24;
          do
          {
            if ( *(int *)(v25 + 4 * v26) >= 1 )
              result = (_QWORD *)wlan_objmgr_peer_release_ref(v27, v26, a2, a3, a4, a5, a6, a7, a8, a9);
            ++v26;
          }
          while ( v26 != 109 );
        }
        while ( v24 != v23 );
      }
    }
    v28 = v9[12];
    if ( v28 )
    {
      v29 = (_QWORD *)(v28 + 192);
      v30 = *(_QWORD **)(v28 + 192);
      if ( v30 != (_QWORD *)(v28 + 192) )
      {
        v31 = v28 + 244;
        do
        {
          v32 = 0;
          v33 = (__int64)(v30 - 2);
          v30 = (_QWORD *)*v30;
          do
          {
            if ( *(int *)(v31 + 4 * v32) >= 1 )
              result = (_QWORD *)wlan_objmgr_peer_release_ref(v33, v32, a2, a3, a4, a5, a6, a7, a8, a9);
            ++v32;
          }
          while ( v32 != 109 );
        }
        while ( v30 != v29 );
      }
    }
    v34 = v9[13];
    if ( v34 )
    {
      v35 = (_QWORD *)(v34 + 192);
      v36 = *(_QWORD **)(v34 + 192);
      if ( v36 != (_QWORD *)(v34 + 192) )
      {
        v37 = v34 + 244;
        do
        {
          v38 = 0;
          v39 = (__int64)(v36 - 2);
          v36 = (_QWORD *)*v36;
          do
          {
            if ( *(int *)(v37 + 4 * v38) >= 1 )
              result = (_QWORD *)wlan_objmgr_peer_release_ref(v39, v38, a2, a3, a4, a5, a6, a7, a8, a9);
            ++v38;
          }
          while ( v38 != 109 );
        }
        while ( v36 != v35 );
      }
    }
    v40 = v9[14];
    if ( v40 )
    {
      v41 = (_QWORD *)(v40 + 192);
      v42 = *(_QWORD **)(v40 + 192);
      if ( v42 != (_QWORD *)(v40 + 192) )
      {
        v43 = v40 + 244;
        do
        {
          v44 = 0;
          v45 = (__int64)(v42 - 2);
          v42 = (_QWORD *)*v42;
          do
          {
            if ( *(int *)(v43 + 4 * v44) >= 1 )
              result = (_QWORD *)wlan_objmgr_peer_release_ref(v45, v44, a2, a3, a4, a5, a6, a7, a8, a9);
            ++v44;
          }
          while ( v44 != 109 );
        }
        while ( v42 != v41 );
      }
    }
    v46 = v9[9];
    if ( v46 )
    {
      for ( i = 0; i != 109; ++i )
      {
        v48 = (unsigned int *)*(unsigned int *)(v46 + 4 * i + 244);
        if ( (int)v48 >= 1 )
          result = (_QWORD *)wlan_objmgr_vdev_release_ref(v46, i, v48, a2, a3, a4, a5, a6, a7, a8, a9);
      }
    }
    v49 = v9[10];
    if ( v49 )
    {
      for ( j = 0; j != 109; ++j )
      {
        v51 = (unsigned int *)*(unsigned int *)(v49 + 4 * j + 244);
        if ( (int)v51 >= 1 )
          result = (_QWORD *)wlan_objmgr_vdev_release_ref(v49, j, v51, a2, a3, a4, a5, a6, a7, a8, a9);
      }
    }
    v52 = v9[11];
    if ( v52 )
    {
      for ( k = 0; k != 109; ++k )
      {
        v54 = (unsigned int *)*(unsigned int *)(v52 + 4 * k + 244);
        if ( (int)v54 >= 1 )
          result = (_QWORD *)wlan_objmgr_vdev_release_ref(v52, k, v54, a2, a3, a4, a5, a6, a7, a8, a9);
      }
    }
    v55 = v9[12];
    if ( v55 )
    {
      for ( m = 0; m != 109; ++m )
      {
        v57 = (unsigned int *)*(unsigned int *)(v55 + 4 * m + 244);
        if ( (int)v57 >= 1 )
          result = (_QWORD *)wlan_objmgr_vdev_release_ref(v55, m, v57, a2, a3, a4, a5, a6, a7, a8, a9);
      }
    }
    v58 = v9[13];
    if ( v58 )
    {
      for ( n = 0; n != 109; ++n )
      {
        v60 = (unsigned int *)*(unsigned int *)(v58 + 4 * n + 244);
        if ( (int)v60 >= 1 )
          result = (_QWORD *)wlan_objmgr_vdev_release_ref(v58, n, v60, a2, a3, a4, a5, a6, a7, a8, a9);
      }
    }
    v61 = v9[14];
    if ( v61 )
    {
      for ( ii = 0; ii != 109; ++ii )
      {
        v63 = (unsigned int *)*(unsigned int *)(v61 + 4 * ii + 244);
        if ( (int)v63 >= 1 )
          result = (_QWORD *)wlan_objmgr_vdev_release_ref(v61, ii, v63, a2, a3, a4, a5, a6, a7, a8, a9);
      }
    }
    v64 = v9[8];
    if ( v64 )
    {
      for ( jj = 0; jj != 109; ++jj )
      {
        v66 = (unsigned int *)*(unsigned int *)(v64 + 4 * jj + 92);
        if ( (int)v66 >= 1 )
          result = (_QWORD *)wlan_objmgr_pdev_release_ref(v64, jj, v66, a2, a3, a4, a5, a6, a7, a8, a9);
      }
    }
  }
  return result;
}
