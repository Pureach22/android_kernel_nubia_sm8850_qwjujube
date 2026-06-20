__int64 __fastcall lim_send_sme_rsp(__int64 a1, unsigned __int16 a2, unsigned int a3, unsigned __int8 a4)
{
  __int64 v8; // x23
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
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
  v8 = lim_msg_str(a2);
  v9 = lim_result_code_str(a3);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sending message: %s with reasonCode: %s",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "lim_send_sme_rsp",
    v8,
    v9);
  result = _qdf_mem_malloc(0x18u, "lim_send_sme_rsp", 76);
  if ( result )
  {
    *(_WORD *)result = a2;
    *(_WORD *)(result + 2) = 24;
    *(_DWORD *)(result + 8) = a3;
    *(_BYTE *)(result + 4) = a4;
    v20 = result;
    LOWORD(v19) = a2;
    HIDWORD(v19) = 0;
    qdf_trace(53, 6u, a4, a2);
    result = sys_process_mmh_msg(a1, &v19);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
