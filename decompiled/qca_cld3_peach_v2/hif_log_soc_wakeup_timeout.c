__int64 __fastcall hif_log_soc_wakeup_timeout(__int64 a1)
{
  __int64 callbacks_handle; // x0
  __int64 v3; // x22
  __int64 *v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  void (__fastcall *v79)(__int64, __int64); // x8
  __int64 v80; // x0
  __int64 result; // x0
  unsigned int v82; // [xsp+0h] [xbp-10h] BYREF
  _WORD v83[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v84; // [xsp+8h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83[0] = 0;
  v82 = 0;
  hif_get_ini_handle();
  callbacks_handle = hif_get_callbacks_handle(a1);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = (__int64 *)callbacks_handle;
  qdf_trace_msg(
    0x3Du,
    5u,
    "%s: keep_awake_count = %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "hif_log_soc_wakeup_timeout",
    *(unsigned int *)(a1 + 27304));
  pld_pci_read_config_word(*(_QWORD *)(a1 + 30768), 0, (__int64)v83);
  qdf_trace_msg(
    0x3Du,
    5u,
    "%s: PCI Vendor ID = 0x%04x",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "hif_log_soc_wakeup_timeout",
    v83[0]);
  pld_pci_read_config_word(*(_QWORD *)(a1 + 30768), 2u, (__int64)v83);
  qdf_trace_msg(
    0x3Du,
    5u,
    "%s: PCI Device ID = 0x%04x",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "hif_log_soc_wakeup_timeout",
    v83[0]);
  pld_pci_read_config_word(*(_QWORD *)(a1 + 30768), 4u, (__int64)v83);
  qdf_trace_msg(
    0x3Du,
    5u,
    "%s: PCI Command = 0x%04x",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "hif_log_soc_wakeup_timeout",
    v83[0]);
  pld_pci_read_config_word(*(_QWORD *)(a1 + 30768), 6u, (__int64)v83);
  qdf_trace_msg(
    0x3Du,
    5u,
    "%s: PCI Status = 0x%04x",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "hif_log_soc_wakeup_timeout",
    v83[0]);
  pld_pci_read_config_dword(*(_QWORD *)(a1 + 30768), 0x10u, (__int64)&v82);
  qdf_trace_msg(
    0x3Du,
    5u,
    "%s: PCI BAR 0 = 0x%08x",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    "hif_log_soc_wakeup_timeout",
    v82);
  v53 = hif_read32_mb_reg_window(
          a1,
          v3 + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 160LL) + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 168LL));
  qdf_trace_msg(
    0x3Du,
    5u,
    "%s: SOC_WAKE_ADDR 0%08x",
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    "hif_log_soc_wakeup_timeout",
    v53);
  v62 = hif_read32_mb_reg_window(
          a1,
          v3 + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 160LL) + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 152LL));
  qdf_trace_msg(
    0x3Du,
    5u,
    "%s: RTC_STATE_ADDR 0x%08x",
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    "hif_log_soc_wakeup_timeout",
    v62);
  qdf_trace_msg(0x3Du, 5u, "%s: wakeup target", v71, v72, v73, v74, v75, v76, v77, v78, "hif_log_soc_wakeup_timeout");
  *(_BYTE *)(a1 + 648) = 1;
  v79 = (void (__fastcall *)(__int64, __int64))v4[1];
  if ( v79 )
  {
    v80 = *v4;
    if ( *((_DWORD *)v79 - 1) != -538254584 )
      __break(0x8228u);
    v79(v80, 1);
  }
  result = pld_is_pci_link_down(*(_QWORD *)(a1 + 30760));
  _ReadStatusReg(SP_EL0);
  return result;
}
