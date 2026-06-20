__int64 __fastcall cm_calculate_scores(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        _QWORD *a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 result; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  unsigned int *v21; // x24
  unsigned int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a3 + 16) )
    goto LABEL_2;
  v19 = _qdf_mem_malloc(0x204u, "cm_calculate_scores", 2000);
  v20 = *a1;
  v21 = (unsigned int *)v19;
  v22 = 0;
  if ( v19 && v20 )
  {
    if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, unsigned int *, __int64, __int64, _QWORD))policy_mgr_get_pcl)(
                          *(_QWORD *)(a2 + 80),
                          0,
                          v19 + 4,
                          &v22,
                          v19 + 412,
                          102,
                          *(unsigned __int8 *)(v20 + 168)) )
      *v21 = v22;
  }
  else if ( !v19 )
  {
    goto LABEL_2;
  }
  if ( *v21 )
  {
    wlan_cm_calculate_bss_score(
      a2,
      v21,
      a4,
      a3 + 64,
      (unsigned __int8 *)(*a1 + 74),
      a5 & 1,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13);
    result = _qdf_mem_free((__int64)v21);
    goto LABEL_3;
  }
  _qdf_mem_free((__int64)v21);
LABEL_2:
  result = wlan_cm_calculate_bss_score(
             a2,
             nullptr,
             a4,
             a3 + 64,
             (unsigned __int8 *)(*a1 + 74),
             a5 & 1,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13);
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
