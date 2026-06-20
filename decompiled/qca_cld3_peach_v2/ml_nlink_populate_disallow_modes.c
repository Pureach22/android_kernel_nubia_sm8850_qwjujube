__int64 __fastcall ml_nlink_populate_disallow_modes(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x21
  unsigned __int16 *v17; // x24
  int v18; // w8
  __int64 v19; // x8
  __int64 result; // x0
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  __int64 v22; // [xsp+8h] [xbp-18h]
  __int64 v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a2 + 1360);
  LOWORD(v23) = 0;
  v21 = 0;
  v22 = 0;
  if ( v12 && *(_QWORD *)(v12 + 2224) )
  {
    qdf_mutex_acquire(v12 + 1656);
    v17 = (unsigned __int16 *)&v21;
    qdf_mem_copy(&v21, (const void *)(*(_QWORD *)(v12 + 2224) + 1348LL), 0x12u);
    qdf_mutex_release(v12 + 1656);
    v18 = a3[8];
    if ( v18 == 6 || v18 == 1 )
      v17 = (unsigned __int16 *)a3 + 57;
    if ( (a4 & 0x20) == 0 )
      ml_nlink_update_disallow_modes(a1, a2, 0, 0, *v17);
    qdf_mutex_acquire(v12 + 1656);
    v19 = *(_QWORD *)(v12 + 2224);
    a3[30] = *(_DWORD *)(v19 + 1452);
    qdf_mem_copy(a3 + 31, (const void *)(v19 + 1456), 0x20u);
    result = qdf_mutex_release(v12 + 1656);
  }
  else
  {
    result = qdf_trace_msg(
               0x8Fu,
               2u,
               "%s: mlo_ctx or sta_ctx null",
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "ml_nlink_populate_disallow_modes",
               v21,
               v22,
               v23,
               v24);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
