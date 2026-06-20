void __fastcall csr_process_sap_ch_width_update(
        _QWORD *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w8
  __int64 v13; // x4
  __int64 v14; // x9
  _DWORD *v15; // x8
  const char *v16; // x2
  unsigned int v17; // w1
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w8
  _DWORD *v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  _DWORD *v37; // x21
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v47; // [xsp+8h] [xbp-38h] BYREF
  __int64 v48; // [xsp+10h] [xbp-30h]
  __int64 v49; // [xsp+18h] [xbp-28h]
  __int64 v50; // [xsp+20h] [xbp-20h]
  __int64 v51; // [xsp+28h] [xbp-18h]
  __int64 v52; // [xsp+30h] [xbp-10h]
  __int64 v53; // [xsp+38h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a2[10];
  v13 = a2[6];
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v46 = v12;
  if ( !a1
    || (unsigned int)v13 > 5
    || (v14 = a1[2162]) == 0
    || (*(_BYTE *)(v14 + 96LL * (unsigned int)v13 + 1) & 1) == 0 )
  {
    v16 = "%s: Invalid session id %d";
    v17 = 2;
    goto LABEL_12;
  }
  if ( v12 == 4 )
  {
    v15 = (_DWORD *)a1[1800];
    if ( *(v15 - 1) != -1366728445 )
      __break(0x8228u);
    if ( (((__int64 (__fastcall *)(_QWORD, _QWORD))v15)(0, 0) & 1) != 0 )
    {
      policy_mgr_restart_opportunistic_timer(a1[2703], 0);
      v13 = a2[6];
      v16 = "%s: Vdev %d : Avoid set BW as conn in progress";
LABEL_10:
      v17 = 4;
LABEL_12:
      qdf_trace_msg(0x34u, v17, v16, a3, a4, a5, a6, a7, a8, a9, a10, "csr_process_sap_ch_width_update", v13);
      goto LABEL_13;
    }
    if ( v46 == 4 && !(unsigned int)policy_mgr_need_opportunistic_upgrade(a1[2703], &v46) )
    {
      v13 = a2[6];
      v16 = "%s: Vdev %d: BW update not needed anymore";
      goto LABEL_10;
    }
  }
  v28 = (_DWORD *)_qdf_mem_malloc(0xCu, "csr_process_sap_ch_width_update", 7902);
  if ( v28 )
  {
    *v28 = 791601;
    v37 = v28;
    v28[1] = a2[8];
    v28[2] = a2[9];
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Posting eWNI_SME_SAP_CH_WIDTH_UPDATE_REQ to PE",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "csr_process_sap_ch_width_update");
    if ( !(unsigned int)umac_send_mb_message_to_mac(v37) )
      goto LABEL_16;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Posting to PE failed",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "csr_process_sap_ch_width_update");
  }
LABEL_13:
  v18 = _qdf_mem_malloc(0xCu, "csr_process_sap_ch_width_update", 7923);
  if ( v18 )
  {
    *(_DWORD *)(v18 + 8) = 16;
    v27 = a2[9];
    *(_DWORD *)(v18 + 4) = 8;
    *(_BYTE *)v18 = v27;
  }
  v48 = v18;
  LOWORD(v47) = 5170;
  HIDWORD(v47) = 0;
  sys_process_mmh_msg(v19, v20, v21, v22, v23, v24, v25, v26, (__int64)a1, (unsigned __int16 *)&v47);
LABEL_16:
  _ReadStatusReg(SP_EL0);
}
