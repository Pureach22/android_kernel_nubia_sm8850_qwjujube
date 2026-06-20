_DWORD *__fastcall lim_update_lost_link_info(
        _DWORD *result,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v11; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v23; // [xsp+10h] [xbp-30h]
  __int64 v24; // [xsp+18h] [xbp-28h]
  __int64 v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = nullptr;
  if ( result && a2 )
  {
    if ( *(_DWORD *)(a2 + 88) == 2 )
    {
      v11 = result;
      result = (_DWORD *)_qdf_mem_malloc(8u, "lim_update_lost_link_info", 3605);
      if ( result )
      {
        *result = *(unsigned __int8 *)(a2 + 10);
        result[1] = a3;
        v23 = result;
        LOWORD(v22) = 5254;
        HIDWORD(v22) = 0;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: post eWNI_SME_LOST_LINK_INFO_IND, bss_idx: %d rssi: %d",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_update_lost_link_info");
        result = (_DWORD *)sys_process_mmh_msg(v11, &v22);
      }
    }
  }
  else
  {
    result = (_DWORD *)qdf_trace_msg(
                         0x35u,
                         2u,
                         "%s: parameter NULL",
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10,
                         a11,
                         "lim_update_lost_link_info");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
