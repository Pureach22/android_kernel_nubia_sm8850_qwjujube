__int64 __fastcall msm_vidc_add_buffer_stats(__int64 a1, _DWORD *a2, __int64 a3)
{
  unsigned __int64 v7; // x0
  int v8; // w11
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 *v11; // x1
  __int64 v12; // x8
  __int64 v13; // x9
  bool v14; // zf
  unsigned int v15; // w8
  __int64 v16; // x9

  if ( (msm_vidc_debug & 4) == 0 )
    return 0;
  if ( (unsigned int)(a2[6] - 1) > 1 )
    return 4294967274LL;
  v7 = ktime_get(a1);
  v8 = a2[6];
  a2[29] = (v7 / 0x3E8 - *(_QWORD *)(a1 + 38424)) / 0x3E8;
  if ( v8 == 1 )
  {
    v9 = msm_vidc_pool_alloc(a1, 6);
    if ( v9 )
    {
      *(_QWORD *)v9 = v9;
      v10 = a1 + 4088;
      *(_QWORD *)(v9 + 8) = v9;
      v11 = *(__int64 **)(a1 + 4096);
      if ( v9 == a1 + 4088 || v11 == (__int64 *)v9 || *v11 != v10 )
      {
        _list_add_valid_or_report(v9);
        v9 = v16;
        v12 = a1;
      }
      else
      {
        v12 = a1;
        *(_QWORD *)(a1 + 4096) = v9;
        *(_QWORD *)v9 = v10;
        *(_QWORD *)(v9 + 8) = v11;
        *v11 = v9;
      }
      v13 = *(_QWORD *)(v12 + 4232);
      *(_QWORD *)(v9 + 24) = a3;
      *(_DWORD *)(v9 + 56) = 0;
      *(_DWORD *)(v9 + 16) = v13;
      *(_DWORD *)(v9 + 32) = a2[29];
      v14 = *(_DWORD *)(v12 + 308) == 2;
      v15 = 0;
      if ( v14 )
      {
        v15 = 0;
        *(_DWORD *)(v9 + 48) = a2[12];
      }
    }
    else
    {
      return (unsigned int)-12;
    }
  }
  else
  {
    return 0;
  }
  return v15;
}
