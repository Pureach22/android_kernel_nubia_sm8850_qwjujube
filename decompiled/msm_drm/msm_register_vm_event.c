__int64 __fastcall msm_register_vm_event(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v9; // x23
  _QWORD *v10; // x22
  __int64 v11; // x8
  __int64 v12; // x9
  _QWORD *v13; // x0
  __int64 v14; // x10
  _QWORD *v15; // x2
  _QWORD *v16; // x1

  result = 4294967274LL;
  if ( a2 && a3 )
  {
    v9 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 56LL);
    v10 = (_QWORD *)_kmalloc_cache_noprof(_drm_debug, 3520, 64);
    if ( v10 )
    {
      mutex_lock(v9 + 5704);
      v12 = a3[2];
      v11 = a3[3];
      v13 = v10 + 6;
      v10[4] = a2;
      v10[5] = a4;
      v10[2] = v12;
      v10[3] = v11;
      v14 = a3[1];
      *v10 = *a3;
      v10[1] = v14;
      v15 = *(_QWORD **)(v9 + 5752);
      v16 = (_QWORD *)(v9 + 5752);
      if ( v15[1] != v9 + 5752 || v13 == v16 || v15 == v13 )
      {
        _list_add_valid_or_report(v13, v16);
      }
      else
      {
        v15[1] = v13;
        v10[6] = v15;
        v10[7] = v16;
        *v16 = v13;
      }
      mutex_unlock(v9 + 5704);
      return 0;
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
