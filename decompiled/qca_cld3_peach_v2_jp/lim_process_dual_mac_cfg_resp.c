_DWORD *__fastcall lim_process_dual_mac_cfg_resp(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _DWORD *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _DWORD *v30; // x21
  __int64 v31; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v32; // [xsp+10h] [xbp-30h]
  __int64 v33; // [xsp+18h] [xbp-28h]
  __int64 v34; // [xsp+20h] [xbp-20h]
  __int64 v35; // [xsp+28h] [xbp-18h]
  __int64 v36; // [xsp+30h] [xbp-10h]
  __int64 v37; // [xsp+38h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = nullptr;
  if ( a2 )
  {
    result = (_DWORD *)_qdf_mem_malloc(4u, "lim_process_dual_mac_cfg_resp", 298);
    if ( result )
    {
      v21 = *a2;
LABEL_6:
      *result = v21;
      v32 = result;
      LOWORD(v31) = 5236;
      HIDWORD(v31) = 0;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Send eWNI_SME_SET_DUAL_MAC_CFG_RESP to SME",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "lim_process_dual_mac_cfg_resp");
      result = (_DWORD *)sys_process_mmh_msg(a1, &v31);
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Set dual mac cfg param is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_process_dual_mac_cfg_resp");
    result = (_DWORD *)_qdf_mem_malloc(4u, "lim_process_dual_mac_cfg_resp", 298);
    if ( result )
    {
      v30 = result;
      v21 = 2;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Send fail status to SME",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "lim_process_dual_mac_cfg_resp");
      result = v30;
      goto LABEL_6;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
