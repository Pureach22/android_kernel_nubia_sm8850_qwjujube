__int64 __fastcall trace_event_raw_event_rdev_pmksa(__int64 a1, __int64 a2, __int64 a3, int **a4)
{
  double v4; // d10
  __int64 v8; // x8
  __int64 result; // x0
  const char *v10; // x23
  __int64 v11; // x21
  size_t v12; // x0
  unsigned __int64 v13; // x2
  __int64 v14; // x8
  int *v15; // x8
  __int16 v16; // w9
  int v17; // w8
  long double v18; // q0
  double v19; // d5
  double v20; // d18
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, 48);
  if ( (v8 & 0x2C0) != 0 && (v8 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_14;
  }
  result = trace_event_buffer_reserve(v21);
  if ( !result )
    goto LABEL_14;
  v10 = *(const char **)(a2 + 504);
  v11 = result;
  if ( !v10 )
    v10 = *(const char **)(a2 + 392);
  v12 = strnlen(v10, 0x20u);
  if ( v12 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v12 == 32 )
      v13 = 32;
    else
      v13 = v12 + 1;
    if ( v13 < 0x21 )
    {
      sized_strscpy(v11 + 8, v10);
      v14 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v11 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v11 + 48) = v14;
      *(_DWORD *)(v11 + 56) = *(_DWORD *)(a3 + 224);
      v15 = *a4;
      if ( *a4 )
      {
        v16 = *((_WORD *)v15 + 2);
        v17 = *v15;
        *(_WORD *)(v11 + 64) = v16;
        *(_DWORD *)(v11 + 60) = v17;
      }
      else
      {
        *(_WORD *)(v11 + 64) = 0;
        *(_DWORD *)(v11 + 60) = 0;
      }
      result = trace_event_buffer_commit(v21);
LABEL_14:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v18 = _fortify_panic(7, 32);
  return perf_trace_rdev_pmksa(v18, v4 + v19 * v20);
}
