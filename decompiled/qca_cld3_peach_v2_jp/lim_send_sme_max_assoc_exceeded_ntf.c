__int64 __fastcall lim_send_sme_max_assoc_exceeded_ntf(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
{
  __int64 result; // x0
  __int64 v7; // x22
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  int v19; // w8
  __int64 v20; // [xsp+18h] [xbp-38h] BYREF
  __int64 v21; // [xsp+20h] [xbp-30h]
  __int64 v22; // [xsp+28h] [xbp-28h]
  __int64 v23; // [xsp+30h] [xbp-20h]
  __int64 v24; // [xsp+38h] [xbp-18h]
  __int64 v25; // [xsp+40h] [xbp-10h]
  __int64 v26; // [xsp+48h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  result = _qdf_mem_malloc(0xCu, "lim_send_sme_max_assoc_exceeded_ntf", 2637);
  if ( result )
  {
    v7 = result;
    qdf_mem_copy((void *)(result + 5), a2, 6u);
    *(_BYTE *)(v7 + 4) = a3;
    *(_DWORD *)v7 = 791609;
    LOWORD(v20) = 5177;
    v21 = v7;
    if ( a2 )
    {
      v16 = *a2;
      v17 = a2[1];
      v18 = a2[2];
      v19 = a2[5];
    }
    else
    {
      v18 = 0;
      v16 = 0;
      v17 = 0;
      v19 = 0;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: msgType: %s peerMacAddr %02x:%02x:%02x:**:**:%02xsme session id %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "lim_send_sme_max_assoc_exceeded_ntf",
      "eWNI_SME_MAX_ASSOC_EXCEEDED",
      v16,
      v17,
      v18,
      v19,
      a3);
    qdf_trace(53, 6u, a3, 5177);
    result = sys_process_mmh_msg(a1, &v20);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
