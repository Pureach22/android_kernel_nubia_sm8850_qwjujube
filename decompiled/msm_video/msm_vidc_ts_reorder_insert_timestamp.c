__int64 __fastcall msm_vidc_ts_reorder_insert_timestamp(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  __int64 v5; // x4
  __int64 result; // x0

  v4 = (_QWORD *)msm_vidc_pool_alloc(a1, 2);
  if ( v4 )
  {
    *v4 = v4;
    v4[1] = v4;
    v4[2] = a2;
    result = msm_vidc_insert_sort((_QWORD *)(a1 + 3240), v4);
    if ( !(_DWORD)result )
      ++*(_DWORD *)(a1 + 3256);
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_92FBF, "err ", a1 + 340, "msm_vidc_ts_reorder_insert_timestamp", v5);
    return 4294967284LL;
  }
  return result;
}
