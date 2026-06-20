__int64 __fastcall sme_update_nss(_QWORD *a1, char a2)
{
  __int64 v3; // x24
  __int64 result; // x0
  __int64 v6; // x20
  __int64 v7; // x25
  __int64 v8; // x24
  __int64 v9; // x8
  __int16 v10; // w26
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x21
  __int64 cmpt_obj; // x0
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  v3 = a1[1];
  result = qdf_mutex_acquire((__int64)(a1 + 1597));
  if ( !(_DWORD)result )
  {
    v6 = 0;
    v7 = 1;
    *(_BYTE *)(v3 + 2667) = a2 != 1;
    v8 = a1[1];
    do
    {
      if ( a1 )
      {
        v9 = a1[2153];
        if ( v9 )
        {
          if ( *(_BYTE *)(v9 + v7) == 1 )
          {
            v10 = *(_WORD *)(v8 + 1268);
            v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                    a1[2694],
                    (unsigned int)v6,
                    11);
            if ( v11 )
            {
              v20 = v11;
              cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v11, v12, v13, v14, v15, v16, v17, v18, v19);
              if ( cmpt_obj )
              {
                v22 = (unsigned int *)(*(_DWORD *)(cmpt_obj + 60) & 0xFFFFFF7F | v10 & 0x80);
                *(_DWORD *)(cmpt_obj + 60) = (_DWORD)v22;
              }
              wlan_objmgr_vdev_release_ref(v20, 0xBu, v22, v23, v24, v25, v26, v27, v28, v29, v30);
            }
          }
        }
      }
      ++v6;
      v7 += 96;
    }
    while ( v6 != 6 );
    qdf_mutex_release((__int64)(a1 + 1597));
    return 0;
  }
  return result;
}
