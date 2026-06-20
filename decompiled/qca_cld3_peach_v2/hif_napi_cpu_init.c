__int64 __fastcall hif_napi_cpu_init(__int64 a1)
{
  __int64 result; // x0
  char v3; // w8
  _DWORD *v4; // x27
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x21
  __int64 v7; // x9
  int v8; // w8
  char *v9; // x26
  unsigned int max; // w0
  unsigned int v11; // w21
  int v12; // w25
  unsigned int v13; // w23
  int v14; // w27
  unsigned int v15; // w26
  int v16; // w8
  unsigned int *v17; // x24
  __int64 v18; // x28
  int v19; // w20
  int v20; // w22
  unsigned int v21; // w19
  _QWORD **v22; // x21
  unsigned int v23; // w0
  unsigned int v24; // w19
  unsigned int *v25; // [xsp+0h] [xbp-80h]
  _DWORD *s; // [xsp+8h] [xbp-78h]
  __int64 v27; // [xsp+10h] [xbp-70h]
  unsigned int v28; // [xsp+1Ch] [xbp-64h]

  if ( *(_DWORD *)(a1 + 880) )
    return 4294967182LL;
  v3 = 0;
  v4 = (_DWORD *)(a1 + 880);
  do
  {
    v5 = (unsigned int)(-1LL << v3) & _cpu_possible_mask;
    if ( !(_DWORD)v5 )
      break;
    v6 = __clz(__rbit64(v5));
    v7 = 12 * v6;
    v8 = ((_cpu_online_mask >> v6) & 1LL) != 0 ? 2 : 1;
    v9 = (char *)&v4[v7];
    *(_DWORD *)v9 = v8;
    *((_DWORD *)v9 + 1) = cpu_topology[v7 + 1];
    *((_DWORD *)v9 + 2) = cpu_topology[v7 + 3];
    *((_QWORD *)v9 + 2) = *(_QWORD *)&cpu_topology[v7 + 6];
    *((_QWORD *)v9 + 3) = *(_QWORD *)&cpu_topology[v7 + 4];
    max = cpufreq_quick_get_max((unsigned int)v6);
    v3 = v6 + 1;
    *((_QWORD *)v9 + 4) = max;
    *((_DWORD *)v9 + 11) = -1;
  }
  while ( v6 < 0x1F );
  s = v4;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  *(_QWORD *)(a1 + 2416) = -1;
  v15 = 0x7FFFFFFF;
  v28 = 0;
  v27 = a1;
  v25 = (unsigned int *)(a1 + 912);
  while ( 2 )
  {
    v17 = v25;
    v18 = 0;
    v19 = 0;
    v20 = -1;
    do
    {
      v21 = *(v17 - 6);
      if ( v21 <= 1 && (unsigned int)_sw_hweight64(*(v17 - 4)) && ((v11 >> v21) & 1) == 0 )
      {
        if ( !v19 )
        {
          v13 = *v17;
          v14 = -1;
          v12 = v18;
          v20 = v21;
LABEL_24:
          if ( v13 >= v28 )
          {
            v28 = v13;
            *(_DWORD *)(v27 + 2420) = v12;
            if ( v13 < v15 )
              goto LABEL_29;
LABEL_26:
            if ( v14 != -1 )
LABEL_30:
              s[12 * v14 + 11] = v18;
          }
          else
          {
            if ( v13 >= v15 )
              goto LABEL_26;
LABEL_29:
            v15 = v13;
            *(_DWORD *)(v27 + 2416) = v12;
            if ( v14 != -1 )
              goto LABEL_30;
          }
          v19 = 1;
          v14 = v18;
          goto LABEL_15;
        }
        if ( v20 < 0 || v20 == v21 )
          goto LABEL_24;
        v19 = 1;
      }
LABEL_15:
      ++v18;
      v17 += 12;
    }
    while ( v18 != 32 );
    v16 = 1 << v20;
    if ( v20 < 0 )
      v16 = 0;
    v11 |= v16;
    if ( v19 )
      continue;
    break;
  }
  if ( (*(_DWORD *)(v27 + 2416) & 0x80000000) != 0 && (*(_DWORD *)(v27 + 2420) & 0x80000000) != 0 )
  {
    v24 = -14;
    goto LABEL_36;
  }
  v22 = (_QWORD **)(v27 + 2432);
  v23 = qdf_cpuhp_register((_QWORD *)(v27 + 2432), v27, (__int64)hnc_cpu_online_cb, (__int64)hnc_cpu_before_offline_cb);
  result = qdf_status_to_os_return(v23);
  if ( (_DWORD)result )
  {
    v24 = result;
    if ( *v22 )
      qdf_cpuhp_unregister(v22);
LABEL_36:
    memset(s, 0, 0x600u);
    return v24;
  }
  return result;
}
