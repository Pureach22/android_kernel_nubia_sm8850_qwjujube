__int64 __fastcall drm_dp_mst_atomic_wait_for_dependencies(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x21
  _QWORD *v3; // x8
  _QWORD *v4; // x23
  __int64 v5; // x24
  unsigned __int64 v6; // x26
  int v7; // w25
  __int64 v8; // x0
  __int64 v9; // x8
  int v10; // w3
  _QWORD *i; // x8
  _QWORD *v12; // x23
  _QWORD *v13; // t1
  _QWORD *v14; // x10
  _QWORD *v15; // x10

  if ( *(int *)(result + 56) >= 1 )
  {
    v1 = result;
    v2 = 0;
    do
    {
      v3 = (_QWORD *)(*(_QWORD *)(v1 + 64) + 32 * v2);
      if ( *(__int64 (__fastcall ***)())(*v3 + 96LL) == drm_dp_mst_topology_state_funcs )
      {
        v4 = (_QWORD *)v3[2];
        v5 = v3[3];
        if ( v4[5] )
        {
          v6 = 0;
          v7 = 1;
          do
          {
            result = drm_crtc_commit_wait(*(_QWORD *)(v4[4] + 8 * v6));
            if ( (result & 0x80000000) != 0 )
            {
              v9 = *(_QWORD *)(v1 + 8);
              v10 = result;
              if ( v9 )
                v8 = *(_QWORD *)(v9 + 8);
              else
                v8 = 0;
              result = dev_err(
                         v8,
                         "[drm] *ERROR* Failed to wait for %s: %d\n",
                         *(const char **)(**(_QWORD **)(v4[4] + 8 * v6) + 32LL),
                         v10);
            }
            v6 = v7++;
          }
          while ( v4[5] > v6 );
        }
        v13 = (_QWORD *)v4[7];
        v12 = v4 + 7;
        for ( i = v13; i != v12; i = (_QWORD *)*i )
        {
          if ( (*((_BYTE *)i - 12) & 1) == 0 )
          {
            v15 = (_QWORD *)(v5 + 56);
            do
            {
              v15 = (_QWORD *)*v15;
              if ( v15 == (_QWORD *)(v5 + 56) )
              {
                v14 = nullptr;
                goto LABEL_16;
              }
            }
            while ( *(v15 - 4) != *(i - 4) );
            v14 = v15 - 4;
LABEL_16:
            *((_BYTE *)v14 + 8) = *((_BYTE *)i - 24);
            *((_DWORD *)v14 + 6) = *((_DWORD *)i - 2);
          }
        }
      }
      ++v2;
    }
    while ( v2 < *(int *)(v1 + 56) );
  }
  return result;
}
