__int64 __fastcall wma_set_sta_keep_alive(
        _QWORD *a1,
        unsigned __int8 a2,
        int a3,
        unsigned int a4,
        const void *a5,
        const void *a6,
        const void *a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // [xsp+8h] [xbp-28h] BYREF
  __int64 v33; // [xsp+10h] [xbp-20h] BYREF
  __int64 v34; // [xsp+18h] [xbp-18h] BYREF
  int v35; // [xsp+20h] [xbp-10h]
  __int64 v36; // [xsp+28h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v33 = 0;
  v34 = 0;
  v32 = 0;
  result = _wma_validate_handle((__int64)a1, (__int64)"wma_set_sta_keep_alive", a8, a9, a10, a11, a12, a13, a14, a15);
  if ( !(_DWORD)result )
  {
    if ( a4 < 0x3E9 )
    {
      v31 = a1[65] + 488LL * a2;
      LOBYTE(v32) = a2;
      HIDWORD(v32) = a3;
      LODWORD(v33) = a4;
      if ( v31 )
      {
        if ( *(_WORD *)(v31 + 480) )
        {
          if ( *(unsigned __int16 *)(v31 + 480) < a4 )
          {
            LOWORD(a4) = *(_WORD *)(v31 + 480);
            LODWORD(v33) = (unsigned __int16)a4;
          }
          if ( a3 == 1 )
            HIDWORD(v32) = 5;
        }
        wlan_mlme_set_keepalive_period(*(_QWORD *)v31, a4, v23, v24, v25, v26, v27, v28, v29, v30);
      }
      if ( a5 )
        qdf_mem_copy((char *)&v33 + 4, a5, 4u);
      if ( a6 )
        qdf_mem_copy(&v34, a6, 4u);
      if ( a7 )
        qdf_mem_copy((char *)&v34 + 4, a7, 6u);
      result = wmi_unified_set_sta_keep_alive_cmd(*a1, &v32);
    }
    else
    {
      result = qdf_trace_msg(
                 0x31u,
                 2u,
                 "%s: Invalid period %d Max limit %d",
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 "wma_set_sta_keep_alive",
                 a4,
                 1000);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
