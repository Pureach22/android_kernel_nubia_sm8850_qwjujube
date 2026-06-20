__int64 DP_PRINT_STATS(
        const char *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        ...)
{
  __int64 result; // x0
  __int64 v11; // x19
  __int64 v12; // x8
  int v13; // w21
  __int64 v14; // x8
  __int64 v15; // x22
  int v16; // w23
  __int64 v17; // x8
  __int64 v18; // x9
  __int16 v19; // w0
  __int64 v20; // x1
  __int16 v21; // w20
  __int16 v22; // w0
  gcc_va_list va; // [xsp+38h] [xbp-48h] BYREF
  gcc_va_list va1; // [xsp+58h] [xbp-28h] BYREF
  __int64 v25; // [xsp+78h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(va1, 0, sizeof(va1));
  result = (__int64)_cds_get_context(71, (__int64)"DP_PRINT_STATS", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v11 = result;
    va_start(va1, a9);
    va_start(va, a9);
    va[0].__vr_top = va1[0].__vr_top;
    result = qdf_vtrace_msg(0x45u, 5u, (__int64)a1, va);
    v12 = *(_QWORD *)(v11 + 17584);
    if ( v12 )
    {
      if ( *(_DWORD *)(v12 + 148) == 1 )
      {
        v13 = *(_DWORD *)(v12 + 152);
        result = qdf_get_current_pid();
        if ( v13 == (_DWORD)result )
        {
          v14 = *(_QWORD *)(v11 + 17584);
          v15 = *(unsigned __int16 *)(v14 + 156);
          v16 = *(unsigned __int16 *)(v14 + 158);
          if ( v16 - (int)v15 >= 2 )
          {
            qdf_spinlock_acquire(v14 + 80);
            v17 = *(_QWORD *)(v11 + 17584);
            v18 = *(_QWORD *)(v17 + 160);
            if ( v18 )
            {
              va_end(va);
              va_copy(va, va1);
              v19 = vscnprintf(v18 + v15, (unsigned int)(v16 - v15), a1, va);
              v17 = *(_QWORD *)(v11 + 17584);
              v20 = v16 - (unsigned int)(unsigned __int16)(v15 + v19);
              if ( (int)v20 >= 2 )
              {
                v21 = v19;
                scnprintf(*(_QWORD *)(v17 + 160) + (unsigned __int16)(v15 + v19), v20, "\n");
                *(_WORD *)(*(_QWORD *)(v11 + 17584) + 156LL) += v21 + v22;
                v17 = *(_QWORD *)(v11 + 17584);
              }
            }
            result = qdf_spinlock_release(v17 + 80);
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
