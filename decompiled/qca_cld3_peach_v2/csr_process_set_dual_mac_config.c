void __fastcall csr_process_set_dual_mac_config(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x20
  const char *v23; // x2
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _DWORD *v33; // x20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v43; // [xsp+10h] [xbp-30h]
  __int64 v44; // [xsp+18h] [xbp-28h]
  __int64 v45; // [xsp+20h] [xbp-20h]
  __int64 v46; // [xsp+28h] [xbp-18h]
  __int64 v47; // [xsp+30h] [xbp-10h]
  __int64 v48; // [xsp+38h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = nullptr;
  if ( a2 )
  {
    v12 = _qdf_mem_malloc(0x20u, "csr_process_set_dual_mac_config", 7691);
    if ( !v12 )
      goto LABEL_7;
    *(_DWORD *)v12 = 2102387;
    *(_DWORD *)(v12 + 8) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(v12 + 12) = *(_DWORD *)(a2 + 36);
    v21 = *(_QWORD *)(a2 + 40);
    v22 = v12;
    *(_QWORD *)(v12 + 16) = v21;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Posting eWNI_SME_SET_DUAL_MAC_CFG_REQ to PE: %x %x",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "csr_process_set_dual_mac_config");
    if ( !(unsigned int)umac_send_mb_message_to_mac(v22) )
      goto LABEL_9;
    v23 = "%s: Posting to PE failed";
  }
  else
  {
    v23 = "%s: Set HW mode param is NULL";
  }
  qdf_trace_msg(0x34u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "csr_process_set_dual_mac_config");
LABEL_7:
  v24 = _qdf_mem_malloc(4u, "csr_process_set_dual_mac_config", 7721);
  if ( v24 )
  {
    v33 = (_DWORD *)v24;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Sending set dual mac fail response to SME",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "csr_process_set_dual_mac_config");
    *v33 = 2;
    LOWORD(v42) = 5236;
    v43 = v33;
    HIDWORD(v42) = 0;
    sys_process_mmh_msg(v34, v35, v36, v37, v38, v39, v40, v41, a1, (unsigned __int16 *)&v42);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
}
