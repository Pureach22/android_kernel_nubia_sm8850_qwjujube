__int64 __fastcall mlo_link_recfg_abort_if_in_progress(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v6; // x8
  int v7; // w22
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  int v19; // w19
  __int64 v20; // x19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( result )
  {
    v2 = *(_QWORD *)(result + 1360);
    v3 = result;
    if ( v2 )
    {
      v4 = *(_QWORD *)(v2 + 3888);
      if ( v4 )
      {
        qdf_mutex_acquire(v4 + 760);
        v6 = *(_QWORD *)(*(_QWORD *)(v3 + 1360) + 3888LL);
        v7 = *(_DWORD *)(v6 + 832);
        result = qdf_mutex_release(v6 + 760);
        if ( !v7 || (a2 & 1) == 0 )
        {
          result = wlan_vdev_mlme_is_mlo_vdev(v3, v8, v9, v10, v11, v12, v13, v14, v15);
          if ( (result & 1) != 0 )
          {
            v16 = *(_QWORD *)(v3 + 1360);
            if ( v16 )
            {
              v17 = *(_QWORD *)(v16 + 3888);
              if ( v17 )
              {
                qdf_mutex_acquire(v17 + 760);
                v18 = *(_QWORD *)(*(_QWORD *)(v3 + 1360) + 3888LL);
                v19 = *(_DWORD *)(v18 + 832);
                result = qdf_mutex_release(v18 + 760);
                if ( v19 )
                {
                  v20 = *(_QWORD *)(v4 + 8);
                  if ( v20 )
                  {
                    qdf_mutex_acquire(*(_QWORD *)(v20 + 3888) + 760LL);
                    wlan_sm_dispatch(
                      *(_QWORD *)(*(_QWORD *)(v20 + 3888) + 824LL),
                      0xDu,
                      0,
                      0,
                      v21,
                      v22,
                      v23,
                      v24,
                      v25,
                      v26,
                      v27,
                      v28);
                    return qdf_mutex_release(*(_QWORD *)(v20 + 3888) + 760LL);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
