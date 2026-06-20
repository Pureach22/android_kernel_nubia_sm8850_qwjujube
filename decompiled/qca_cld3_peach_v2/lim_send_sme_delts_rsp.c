__int64 __fastcall lim_send_sme_delts_rsp(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
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
  unsigned int v18; // w8
  __int64 v19; // x4
  __int64 result; // x0
  __int64 v21; // x24
  int v22; // w9
  __int16 v23; // w2
  __int64 v24; // [xsp+8h] [xbp-38h] BYREF
  __int64 v25; // [xsp+10h] [xbp-30h]
  __int64 v26; // [xsp+18h] [xbp-28h]
  __int64 v27; // [xsp+20h] [xbp-20h]
  __int64 v28; // [xsp+28h] [xbp-18h]
  __int64 v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(unsigned __int16 *)(a2 + 22);
  v19 = *(unsigned __int16 *)(a2 + 12);
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: SendSmeDeltsRsp aid: %d tsid: %d up: %d status: %d",
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             "lim_send_sme_delts_rsp",
             v19,
             (v18 >> 1) & 0xF,
             (v18 >> 11) & 7,
             a3);
  if ( *(_BYTE *)(a2 + 20) )
  {
    result = _qdf_mem_malloc(0x54u, "lim_send_sme_delts_rsp", 1527);
    if ( result )
    {
      if ( a4 )
      {
        v21 = result;
        *(_WORD *)(result + 12) = *(_WORD *)(a2 + 12);
        v22 = *(_DWORD *)(a2 + 14);
        *(_WORD *)(result + 18) = *(_WORD *)(a2 + 18);
        *(_DWORD *)(result + 14) = v22;
        qdf_mem_copy((void *)(result + 20), (const void *)(a2 + 21), 0x3Fu);
        *(_DWORD *)(v21 + 8) = a3;
        *(_WORD *)v21 = 5151;
        *(_BYTE *)(v21 + 4) = a5;
        v23 = *(_WORD *)(a4 + 8);
        LOWORD(v24) = 5151;
        v25 = v21;
      }
      else
      {
        v23 = 255;
        *(_DWORD *)(result + 8) = a3;
        *(_WORD *)result = 5151;
        *(_BYTE *)(result + 4) = a5;
        LOWORD(v24) = 5151;
        v25 = result;
      }
      HIDWORD(v24) = 0;
      qdf_trace(53, 6u, v23, 5151);
      lim_diag_event_report(a1, 32, a4, a3);
      result = sys_process_mmh_msg(a1, &v24);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
