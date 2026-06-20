__int64 __fastcall trace_event_raw_event_rdev_assoc_ml_reconf(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 *a4,
        __int16 a5)
{
  __int64 v9; // x8
  __int64 result; // x0
  const char *v11; // x24
  __int64 v12; // x20
  size_t v13; // x0
  unsigned __int64 v14; // x2
  __int64 v15; // x8
  __int64 v16; // x8
  long double v17; // q0
  __int64 v18; // x0
  _QWORD v19[7]; // [xsp+8h] [xbp-38h] BYREF

  v19[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v19, 0, 48);
  if ( (v9 & 0x2C0) != 0 && (v9 & 0x100) == 0 && (result = _trace_trigger_soft_disabled(a1), (result & 1) != 0)
    || (result = trace_event_buffer_reserve(v19)) == 0 )
  {
LABEL_42:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v11 = *(const char **)(a2 + 504);
  v12 = result;
  if ( !v11 )
    v11 = *(const char **)(a2 + 392);
  v13 = strnlen(v11, 0x20u);
  if ( v13 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v13 == 32 )
      v14 = 32;
    else
      v14 = v13 + 1;
    if ( v14 < 0x21 )
    {
      sized_strscpy(v12 + 8, v11);
      v15 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v12 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v12 + 48) = v15;
      LODWORD(v15) = *(_DWORD *)(a3 + 224);
      *(_WORD *)(v12 + 60) = 0;
      *(_WORD *)(v12 + 62) = a5;
      *(_DWORD *)(v12 + 56) = v15;
      if ( a4 )
      {
        v16 = *a4;
        if ( *a4 )
        {
          LOWORD(v16) = 1;
          *(_WORD *)(v12 + 60) = 1;
        }
        if ( a4[4] )
        {
          LOWORD(v16) = v16 | 2;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[8] )
        {
          LOWORD(v16) = v16 | 4;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[12] )
        {
          LOWORD(v16) = v16 | 8;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[16] )
        {
          LOWORD(v16) = v16 | 0x10;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[20] )
        {
          LOWORD(v16) = v16 | 0x20;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[24] )
        {
          LOWORD(v16) = v16 | 0x40;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[28] )
        {
          LOWORD(v16) = v16 | 0x80;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[32] )
        {
          LOWORD(v16) = v16 | 0x100;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[36] )
        {
          LOWORD(v16) = v16 | 0x200;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[40] )
        {
          LOWORD(v16) = v16 | 0x400;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[44] )
        {
          LOWORD(v16) = v16 | 0x800;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[48] )
        {
          LOWORD(v16) = v16 | 0x1000;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[52] )
        {
          LOWORD(v16) = v16 | 0x2000;
          *(_WORD *)(v12 + 60) = v16;
        }
        if ( a4[56] )
          *(_WORD *)(v12 + 60) = v16 | 0x4000;
      }
      result = trace_event_buffer_commit(v19);
      goto LABEL_42;
    }
  }
  v17 = _fortify_panic(7, 32);
  v18 = MEMORY[0x4DE6700](v17);
  return perf_trace_rdev_assoc_ml_reconf(v18);
}
