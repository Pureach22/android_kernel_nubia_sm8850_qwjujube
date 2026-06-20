__int64 __fastcall wma_pdev_div_info_evt_handler(
        __int64 *a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x20
  __int64 v22; // x22
  const char *v23; // x2
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int *v41; // x21
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned __int64 v50; // x23
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w8
  int v60; // w8
  void (__fastcall *v61)(__int64, __int64 *); // x8
  __int64 v62; // x0
  __int64 v63; // [xsp+0h] [xbp-70h] BYREF
  __int64 v64; // [xsp+8h] [xbp-68h]
  __int64 v65; // [xsp+10h] [xbp-60h]
  __int64 v66; // [xsp+18h] [xbp-58h]
  __int64 v67; // [xsp+20h] [xbp-50h] BYREF
  __int64 v68; // [xsp+28h] [xbp-48h]
  __int64 v69; // [xsp+30h] [xbp-40h]
  __int64 v70; // [xsp+38h] [xbp-38h]
  __int64 v71; // [xsp+40h] [xbp-30h] BYREF
  __int64 v72; // [xsp+48h] [xbp-28h]
  __int64 v73; // [xsp+50h] [xbp-20h]
  __int64 v74; // [xsp+58h] [xbp-18h]
  __int64 v75; // [xsp+60h] [xbp-10h]
  __int64 v76; // [xsp+68h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v75) = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  context = _cds_get_context(53, (__int64)"wma_pdev_div_info_evt_handler", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !a1 || (v21 = context) == nullptr )
  {
    v23 = "%s: Invalid pmac or wma";
    goto LABEL_12;
  }
  if ( !context[1806] )
  {
    v23 = "%s: Invalid get_chain_rssi_cb";
    goto LABEL_12;
  }
  if ( !a2 )
  {
    v23 = "%s: Invalid rssi antid event buffer";
    goto LABEL_12;
  }
  v22 = *a2;
  if ( !*a2 )
  {
    v23 = "%s: Invalid fixed param";
    goto LABEL_12;
  }
  if ( *(_DWORD *)(v22 + 4) >= 9u )
  {
    v23 = "%s: Invalid num of chains";
LABEL_12:
    qdf_trace_msg(
      0x36u,
      2u,
      v23,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_pdev_div_info_evt_handler",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76);
    result = 4294967274LL;
    goto LABEL_13;
  }
  qdf_mem_set(&v63, 0x64u, 0);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: macaddr: %02x:%02x:%02x:**:**:%02x",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "wma_pdev_div_info_evt_handler",
    (unsigned __int8)*(_DWORD *)(v22 + 72),
    (unsigned __int8)BYTE1(*(_DWORD *)(v22 + 72)),
    (unsigned __int8)BYTE2(*(_DWORD *)(v22 + 72)),
    *(unsigned __int8 *)(v22 + 77),
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: num_chains_valid: %d",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "wma_pdev_div_info_evt_handler",
    *(unsigned int *)(v22 + 4));
  LODWORD(v63) = *(_DWORD *)(v22 + 4);
  qdf_mem_copy((char *)&v63 + 4, (const void *)(v22 + 8), 0x20u);
  v41 = (unsigned int *)&v67 + 1;
  qdf_mem_copy((char *)&v67 + 4, (const void *)(v22 + 80), 0x20u);
  qdf_mem_copy((char *)&v71 + 4, (const void *)(v22 + 40), 0x20u);
  if ( (_DWORD)v63 )
  {
    v50 = 0;
    do
    {
      if ( v50 == 8 )
      {
        __break(0x5512u);
        __break(1u);
      }
      qdf_trace_msg(
        0x36u,
        8u,
        "chain_rssi: %d, chain_evm: %d,ant_id: %d",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        *(v41 - 8),
        *v41,
        v41[8]);
      if ( (wmi_service_enabled(*a1, 0xACu, v51, v52, v53, v54, v55, v56, v57, v58) & 1) == 0 )
      {
        v59 = *(v41 - 8);
        if ( v59 == 128 )
          v60 = 255;
        else
          v60 = v59 - 96;
        *(v41 - 8) = v60;
      }
      ++v50;
      ++v41;
    }
    while ( v50 < (unsigned int)v63 );
  }
  v61 = (void (__fastcall *)(__int64, __int64 *))v21[1806];
  v62 = v21[1807];
  if ( *((_DWORD *)v61 - 1) != -2011774531 )
    __break(0x8228u);
  v61(v62, &v63);
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
