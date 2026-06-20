__int64 __fastcall msm_vidc_update_timestamp_rate(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  __int64 v5; // x4
  _QWORD *v6; // x20
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x4
  int v10; // w8
  unsigned int v11; // w11
  unsigned int v12; // w9
  _QWORD *v13; // x9
  _QWORD *v14; // x1
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x11
  _QWORD *v17; // x8
  __int64 v18; // x9
  _QWORD *v19; // x8
  _QWORD *v20; // x12
  unsigned int v21; // w10
  __int64 v22; // x9
  unsigned __int64 v23; // x13
  __int64 v24; // x2
  _QWORD *v25; // x9

  v4 = (_QWORD *)msm_vidc_pool_alloc(a1, 2);
  if ( !v4 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967284LL;
    printk(&unk_92FBF, "err ", a1 + 340, "msm_vidc_update_timestamp_rate", v5);
    return 4294967284LL;
  }
  *v4 = v4;
  v4[1] = v4;
  v4[2] = a2;
  v6 = (_QWORD *)(a1 + 3208);
  v7 = *(_QWORD *)(a1 + 3232);
  *(_QWORD *)(a1 + 3232) = v7 + 1;
  v4[3] = v7;
  result = msm_vidc_insert_sort(a1 + 3208, v4);
  if ( (_DWORD)result )
    return result;
  v10 = *(_DWORD *)(a1 + 3224);
  v11 = v10 + 1;
  if ( *(_DWORD *)(a1 + 308) == 1 )
    v12 = 3;
  else
    v12 = 10;
  *(_DWORD *)(a1 + 3224) = v11;
  if ( v11 > v12 )
  {
    v13 = (_QWORD *)*v6;
    if ( (_QWORD *)*v6 == v6 )
      goto LABEL_34;
    v14 = nullptr;
    v15 = 0x7FFFFFFF;
    do
    {
      v16 = v13[3];
      if ( v16 < v15 )
        v14 = v13;
      v13 = (_QWORD *)*v13;
      if ( v16 < v15 )
        v15 = v16;
    }
    while ( v13 != v6 );
    if ( !v14 )
    {
LABEL_34:
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 4294967274LL;
      printk(&unk_88F9E, "err ", a1 + 340, "msm_vidc_update_timestamp_rate", v9);
      return 4294967274LL;
    }
    *(_DWORD *)(a1 + 3224) = v10;
    v17 = (_QWORD *)v14[1];
    if ( (_QWORD *)*v17 == v14 && (v18 = *v14, *(_QWORD **)(*v14 + 8LL) == v14) )
    {
      *(_QWORD *)(v18 + 8) = v17;
      *v17 = v18;
    }
    else
    {
      _list_del_entry_valid_or_report(v14);
      v14 = v25;
    }
    *v14 = 0xDEAD000000000100LL;
    v14[1] = 0xDEAD000000000122LL;
    msm_vidc_pool_free(a1);
  }
  v19 = (_QWORD *)*v6;
  if ( (_QWORD *)*v6 == v6 )
    goto LABEL_31;
  v20 = nullptr;
  v21 = 0;
  v22 = 0;
  do
  {
    if ( !v20 )
      goto LABEL_21;
    v23 = v19[2] - v20[2];
    if ( v23 )
    {
      ++v21;
      v22 += v23 / 0xF4240;
LABEL_21:
      v20 = v19;
    }
    v19 = (_QWORD *)*v19;
  }
  while ( v19 != v6 );
  if ( v22 )
  {
    v24 = (unsigned int)(1000 * (unsigned __int64)v21 / (unsigned int)v22) << 16;
    goto LABEL_32;
  }
LABEL_31:
  v24 = 0;
LABEL_32:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    93,
    v24,
    "msm_vidc_update_timestamp_rate");
  return 0;
}
