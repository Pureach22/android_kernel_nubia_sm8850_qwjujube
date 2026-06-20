__int64 __fastcall lim_send_sme_start_bss_rsp(__int64 a1, unsigned int a2, __int64 a3, char a4)
{
  __int64 v8; // x4
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  __int16 v18; // w2
  __int64 v19; // [xsp+8h] [xbp-38h] BYREF
  __int64 v20; // [xsp+10h] [xbp-30h]
  __int64 v21; // [xsp+18h] [xbp-28h]
  __int64 v22; // [xsp+20h] [xbp-20h]
  __int64 v23; // [xsp+28h] [xbp-18h]
  __int64 v24; // [xsp+30h] [xbp-10h]
  __int64 v25; // [xsp+38h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v8 = lim_result_code_str(a2);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sending start bss response with reasonCode: %s",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "lim_send_sme_start_bss_rsp",
    v8);
  result = _qdf_mem_malloc(0xCu, "lim_send_sme_start_bss_rsp", 758);
  if ( result )
  {
    *(_BYTE *)result = a4;
    *(_DWORD *)(result + 4) = a2;
    LOWORD(v19) = 5140;
    v20 = result;
    HIDWORD(v19) = 0;
    if ( a3 )
      v18 = *(_WORD *)(a3 + 8);
    else
      v18 = 255;
    qdf_trace(53, 6u, v18, 5140);
    lim_diag_event_report(a1, 19, a3, a2);
    result = sys_process_mmh_msg(a1, &v19);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
