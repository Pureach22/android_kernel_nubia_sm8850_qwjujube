__int64 __fastcall sde_core_perf_crtc_update_bus(__int64 result, _QWORD *a2, unsigned int a3)
{
  __int64 v5; // x19
  __int64 v6; // x8
  int v7; // w25
  __int64 v8; // x8
  unsigned __int64 v9; // x23
  __int64 v10; // x27
  __int64 v11; // x24
  __int64 v12; // x9
  __int64 v13; // x6
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x22
  unsigned __int64 v17; // x23
  unsigned __int64 v18; // x8
  int v19; // w8
  const char *v20; // x4
  int v21; // w8

  v5 = result;
  if ( a2 && (v6 = a2[251]) != 0 )
    v7 = 2 * (*(_QWORD *)(v6 + 472) != 0);
  else
    v7 = 0;
  v8 = *a2;
  v9 = 0;
  v10 = *(_QWORD *)(*a2 + 864LL);
  v11 = *(_QWORD *)(*(_QWORD *)(result + 136) + 56LL);
  if ( v10 != *a2 + 864LL )
  {
    do
    {
      if ( v10 != 16 && *(_BYTE *)(v10 + 156) )
      {
        if ( *(_DWORD *)(v5 + 2088) != 2 || *(_BYTE *)(v5 + 2092) != 1 )
          goto LABEL_15;
        v12 = *(_QWORD *)(v10 + 1992);
        if ( v12 )
          LODWORD(v12) = 2 * (*(_QWORD *)(v12 + 472) != 0);
        if ( (_DWORD)v12 == v7 )
        {
LABEL_15:
          if ( a3 >= 4 )
          {
            __break(0x5512u);
            if ( (v10 & 0x1000) != 0 )
              JUMPOUT(0x10A72C);
            return sde_core_perf_crtc_reserve_res(result, a2);
          }
          v13 = *(_QWORD *)(v10 + 8LL * a3 + 7408);
          v9 += v13;
          if ( (_drm_debug & 4) != 0 )
          {
            result = _drm_dev_dbg(0, 0, 0, "crtc=%d bus_id=%d bw=%llu\n", *(_DWORD *)(v10 + 96), a3, v13);
            v8 = *a2;
          }
        }
      }
      v10 = *(_QWORD *)v10;
    }
    while ( v10 != v8 + 864 );
  }
  v14 = *(_QWORD *)(v5 + 2040);
  if ( v9 > v14 )
    v14 = v9;
  v15 = *(unsigned int *)(*(_QWORD *)(v5 + 152) + 21872LL);
  if ( v14 >= 1000 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(v5 + 152) + 21708LL) )
    v16 = 1000LL * *(unsigned int *)(*(_QWORD *)(v5 + 152) + 21708LL);
  else
    v16 = v14;
  if ( (_DWORD)v15 )
  {
    v17 = 0;
    if ( a3 != 3 )
    {
      v18 = *(unsigned int *)(*(_QWORD *)(v5 + 152) + 21876LL);
      if ( (_DWORD)v18 )
        v17 = 100 * (v16 / v15) / v18;
    }
  }
  else
  {
    v17 = 0;
  }
  if ( *(_DWORD *)(v5 + 2024) == 2 )
  {
    if ( *(_QWORD *)(v5 + 2080) > v16 )
      v16 = *(_QWORD *)(v5 + 2080);
    if ( *(_QWORD *)(v5 + 2072) > v17 )
      v17 = *(_QWORD *)(v5 + 2072);
  }
  v19 = *(_DWORD *)(v5 + 2088);
  if ( v19 )
  {
    if ( v19 == 2 )
    {
      if ( *(_BYTE *)(v5 + 2092) == 1 && v7 )
      {
LABEL_37:
        if ( (_drm_debug & 4) != 0 )
        {
          v20 = "rt_rsc";
LABEL_42:
          result = _drm_dev_dbg(0, 0, 0, "client:%s bus_id=%d ab=%llu ib=%llu\n", v20, a3, v16, v17);
          goto LABEL_43;
        }
        goto LABEL_43;
      }
    }
    else if ( (*(_BYTE *)(v5 + 2092) & 1) != 0 )
    {
      goto LABEL_37;
    }
  }
  result = sde_power_data_bus_set_quota(v11 + 16, a3, v16, v17);
  if ( (_drm_debug & 4) != 0 )
  {
    v20 = "rt";
    goto LABEL_42;
  }
LABEL_43:
  if ( *(_BYTE *)(v5 + 2093) != 1 )
    return result;
  v21 = *(_DWORD *)(v5 + 2088);
  if ( v21 )
  {
    if ( v21 != 1 )
      return result;
    result = sde_power_data_bus_set_quota(v11 + 16, a3, 0, 0);
  }
  else if ( !*(_QWORD *)(a2[251] + 472LL) )
  {
    return result;
  }
  *(_BYTE *)(v5 + 2093) = 0;
  return result;
}
