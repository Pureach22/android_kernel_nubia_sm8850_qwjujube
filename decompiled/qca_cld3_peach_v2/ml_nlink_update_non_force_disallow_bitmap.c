__int64 __fastcall ml_nlink_update_non_force_disallow_bitmap(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v18; // x24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w4
  __int64 result; // x0
  unsigned int v29; // w1
  int v30; // w9
  unsigned int v35; // w21
  __int64 v36; // [xsp+0h] [xbp-20h] BYREF
  __int64 v37; // [xsp+8h] [xbp-18h]
  __int64 v38; // [xsp+10h] [xbp-10h] BYREF
  __int64 v39; // [xsp+18h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(_QWORD *)(a2 + 1360);
  BYTE4(v38) = 0;
  LOWORD(v38) = 0;
  v36 = 0;
  v37 = 0;
  if ( v18 && *(_QWORD *)(v18 + 2224) )
  {
    qdf_mutex_acquire(v18 + 1656);
    qdf_mem_copy(&v36, (const void *)(*(_QWORD *)(v18 + 2224) + 1348LL), 0x12u);
    qdf_mutex_release(v18 + 1656);
    v27 = (unsigned __int16)v36;
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx or sta_ctx null",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "ml_nlink_get_curr_force_state",
      v36,
      v37,
      v38,
      v39);
    v27 = 0;
  }
  ml_nlink_update_disallow_modes(a1, a2, 0, (char *)&v38 + 4, v27, v19, v20, v21, v22, v23, v24, v25, v26);
  result = 0;
  if ( BYTE4(v38) == 1 )
  {
    v29 = *(unsigned __int8 *)(a2 + 168);
    if ( a3 == 21 )
      v30 = 48;
    else
      v30 = 32;
    if ( (a3 & 0xFFFFFFFA) == 0xA || a3 == 4 || a3 == 7 || a3 == 24 || a3 == 21 )
      v35 = v30 | a5 | 0x40;
    else
      v35 = v30 | a5;
    result = policy_mgr_mlo_sta_set_nlink(a1, v29, a4, 7u, 0, 0, 0, v35);
    if ( (v35 & 0x10) != 0 && (_DWORD)result == 24 )
      result = policy_mgr_wait_for_set_link_update(a1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
