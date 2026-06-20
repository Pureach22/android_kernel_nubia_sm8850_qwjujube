__int64 __fastcall adreno_get_bus_counters(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  _DWORD *v4; // x21
  _DWORD *v5; // x3
  int v6; // w20
  int v7; // w8
  bool v8; // cf
  bool v9; // w9
  int v10; // w22
  int v11; // w23
  int v12; // w24
  int v13; // w25
  _DWORD *v14; // x21
  int v15; // t1
  unsigned int v16; // w0
  int v17; // t1

  if ( *(_BYTE *)(result + 10368) == 1 )
  {
    v3 = result;
    v4 = (_DWORD *)(result + 20388);
    v5 = (_DWORD *)(result + 20404);
    if ( *(_DWORD *)(result + 20404) )
      v6 = 0;
    else
      v6 = adreno_perfcounter_get(result, 14, 0, v5, 0, 1);
    v7 = **(_DWORD **)(v3 + 14264);
    if ( (v7 & 0xFFFF0000) != 0x70000 && (v7 & 0xFFFF0000) != 0x80000 )
    {
      v8 = v7 == 203264 || (unsigned int)(v7 - 703) >= 0xFFFFFF99;
      v9 = !v8;
      if ( v7 == 630 || v9 )
      {
        if ( *v4 )
          result = 0;
        else
          result = adreno_perfcounter_get(v3, 13, 85, v4, 0, 1);
        goto LABEL_29;
      }
    }
    if ( v4[5] )
    {
      v10 = 0;
      if ( *v4 )
      {
LABEL_17:
        v11 = 0;
        goto LABEL_20;
      }
    }
    else
    {
      v10 = adreno_perfcounter_get(v3, 14, 1, v4 + 5, 0, 1);
      if ( *v4 )
        goto LABEL_17;
    }
    v11 = adreno_perfcounter_get(v3, 13, 34, v4, 0, 1);
LABEL_20:
    if ( v4[1] )
      v12 = 0;
    else
      v12 = adreno_perfcounter_get(v3, 13, 35, v4 + 1, 0, 1);
    v5 = v4 + 2;
    if ( v4[2] )
    {
      v13 = 0;
      v15 = v4[3];
      v14 = v4 + 3;
      if ( v15 )
      {
LABEL_25:
        v16 = 0;
LABEL_28:
        result = v10 | v11 | v12 | v13 | v16;
LABEL_29:
        if ( (unsigned int)result | v6 )
          return dev_err(*(_QWORD *)v3, "Unable to get perf counters for bus DCVS\n", a3, v5);
        return result;
      }
    }
    else
    {
      v13 = adreno_perfcounter_get(v3, 13, 46, v5, 0, 1);
      v17 = v4[3];
      v14 = v4 + 3;
      if ( v17 )
        goto LABEL_25;
    }
    v16 = adreno_perfcounter_get(v3, 13, 47, v14, 0, 1);
    goto LABEL_28;
  }
  return result;
}
