__int64 __fastcall adreno_ioctl_perfcounter_get(__int64 *a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x19
  int v6; // w22
  int v7; // w22
  unsigned int v8; // w24
  __int64 v9; // x0
  _QWORD *v10; // x2
  _QWORD *v11; // x20
  __int64 v12; // t1
  _QWORD *v13; // x8

  v3 = *a1;
  rt_mutex_lock(*a1 + 11088);
  v6 = adreno_active_count_get(v3);
  if ( !v6 )
  {
    v6 = gmu_core_dev_oob_set(v3, 1);
    if ( !v6 )
    {
      v6 = adreno_perfcounter_get(v3, *a3, a3[1], a3 + 2, a3 + 3, 0);
      if ( !v6 )
      {
        v7 = *a3;
        v8 = a3[1];
        v9 = _kmalloc_cache_noprof(idr_find, 3264, 24);
        if ( v9 )
        {
          v12 = a1[2];
          v11 = a1 + 2;
          v10 = (_QWORD *)v12;
          *(_DWORD *)v9 = v7;
          *(_DWORD *)(v9 + 4) = v8;
          v13 = (_QWORD *)(v9 + 8);
          if ( *(_QWORD **)(v12 + 8) != v11 || v13 == v11 || v10 == v13 )
          {
            _list_add_valid_or_report(v9 + 8, v11);
            v6 = 0;
          }
          else
          {
            v6 = 0;
            v10[1] = v13;
            *(_QWORD *)(v9 + 8) = v10;
            *(_QWORD *)(v9 + 16) = v11;
            *v11 = v13;
          }
        }
        else
        {
          adreno_perfcounter_put(v3, *a3, a3[1], 0);
          v6 = -12;
        }
      }
      gmu_core_dev_oob_clear(v3, 1);
    }
    adreno_active_count_put(v3);
  }
  rt_mutex_unlock(v3 + 11088);
  return v6;
}
