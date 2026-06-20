__int64 __fastcall mlo_update_connected_links_bmap(
        __int64 result,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x10
  __int64 v11; // x8
  char i; // w12
  __int64 v13; // x13
  __int64 v14; // x11
  char v15; // w9
  _QWORD *v16; // x13
  __int64 v17; // x12
  __int64 v18; // x14
  __int64 v19; // x12
  _QWORD *v20; // x13
  __int64 v21; // x11
  __int64 v22; // x14
  __int64 v23; // x14
  __int64 v24; // x13
  __int64 v25; // x11
  _QWORD *v26; // x12
  __int64 v27; // x10
  __int64 v28; // x13
  __int64 v29; // x12

  if ( result )
  {
    v10 = 0;
    v11 = result + 24;
    for ( i = 1; ; i = 0 )
    {
      v14 = *(_QWORD *)(v11 + 8 * v10);
      v15 = i;
      if ( !v14 || !*a2 )
        goto LABEL_8;
      if ( *(unsigned __int8 *)(v14 + 93) == a2[14] )
      {
        v16 = *(_QWORD **)(v14 + 1360);
        if ( v16 )
        {
          v17 = v16[278];
          if ( v17 )
          {
            if ( v16[3] == v14 )
            {
              v18 = *(_QWORD *)(v17 + 8) | 1LL;
              *(_QWORD *)(v17 + 8) = v18;
              if ( v16[4] != v14 )
                goto LABEL_19;
            }
            else
            {
              if ( v16[4] != v14 )
                goto LABEL_19;
              v18 = *(_QWORD *)(v17 + 8);
            }
            *(_QWORD *)(v17 + 8) = v18 | 2;
          }
        }
      }
LABEL_19:
      if ( *a2 < 2u )
        goto LABEL_8;
      v19 = *(_QWORD *)(v11 + 8 * v10);
      if ( *(unsigned __int8 *)(v19 + 93) == a2[62] )
      {
        v20 = *(_QWORD **)(v19 + 1360);
        if ( v20 )
        {
          v21 = v20[278];
          if ( v21 )
          {
            v22 = v20[3];
            if ( v22 && v22 == v19 )
            {
              v23 = *(_QWORD *)(v21 + 8) | 1LL;
              *(_QWORD *)(v21 + 8) = v23;
              if ( v20[4] != v19 )
                goto LABEL_31;
              goto LABEL_30;
            }
            v24 = v20[4];
            if ( v24 && v24 == v19 )
            {
              v23 = *(_QWORD *)(v21 + 8);
LABEL_30:
              *(_QWORD *)(v21 + 8) = v23 | 2;
            }
          }
        }
      }
LABEL_31:
      if ( *a2 < 3u )
        goto LABEL_8;
      v25 = *(_QWORD *)(v11 + 8 * v10);
      if ( *(unsigned __int8 *)(v25 + 93) != a2[110] )
        goto LABEL_7;
      v26 = *(_QWORD **)(v25 + 1360);
      if ( !v26 )
        goto LABEL_7;
      v27 = v26[278];
      if ( !v27 )
        goto LABEL_7;
      v28 = v26[3];
      if ( v28 && v28 == v25 )
      {
        v13 = *(_QWORD *)(v27 + 8) | 1LL;
        *(_QWORD *)(v27 + 8) = v13;
        if ( v26[4] == v25 )
          goto LABEL_6;
      }
      else
      {
        v29 = v26[4];
        if ( v29 && v29 == v25 )
        {
          v13 = *(_QWORD *)(v27 + 8);
LABEL_6:
          *(_QWORD *)(v27 + 8) = v13 | 2;
        }
      }
LABEL_7:
      if ( *a2 > 3u )
      {
        __break(0x5512u);
        return mlo_update_connected_links();
      }
LABEL_8:
      v10 = 1;
      if ( (v15 & 1) == 0 )
        return result;
    }
  }
  return qdf_trace_msg(
           0x8Fu,
           2u,
           "%s: ML dev ctx is NULL",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "mlo_update_connected_links_bmap");
}
