__int64 __fastcall lim_send_sme_delts_ind(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v16; // w8
  __int64 result; // x0
  __int64 v18; // x22
  char v19; // w8
  __int64 v20; // x1
  __int64 v21; // [xsp+8h] [xbp-38h] BYREF
  __int64 v22; // [xsp+10h] [xbp-30h]
  __int64 v23; // [xsp+18h] [xbp-28h]
  __int64 v24; // [xsp+20h] [xbp-20h]
  __int64 v25; // [xsp+28h] [xbp-18h]
  __int64 v26; // [xsp+30h] [xbp-10h]
  __int64 v27; // [xsp+38h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(unsigned __int16 *)(a2 + 1);
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: SendSmeDeltsInd aid: %d tsid: %d up: %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "lim_send_sme_delts_ind",
    a3,
    (v16 >> 1) & 0xF,
    (v16 >> 11) & 7);
  result = _qdf_mem_malloc(0x54u, "lim_send_sme_delts_ind", 1571);
  if ( result )
  {
    *(_DWORD *)(result + 8) = 0;
    *(_WORD *)result = 5152;
    *(_WORD *)(result + 12) = a3;
    v18 = result;
    qdf_mem_copy((void *)(result + 20), (const void *)a2, 0x3Fu);
    v19 = *(_BYTE *)(a4 + 10);
    LOWORD(v21) = 5152;
    *(_BYTE *)(v18 + 4) = v19;
    v20 = *(unsigned __int8 *)(a4 + 8);
    v22 = v18;
    HIDWORD(v21) = 0;
    mac_trace_msg_tx(a1, v20, 5152);
    lim_diag_event_report(a1, 33, a4, 0);
    result = sys_process_mmh_msg(a1, &v21);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
