__int64 __fastcall cam_ife_csid_ver2_handle_rx_debug_event(__int64 a1, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  __int64 *v4; // x8
  __int64 v7; // x28
  __int64 v8; // x26
  __int64 v10; // x19
  unsigned int *v11; // x25
  _BYTE *v12; // x27
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x8
  __int64 v19; // x21
  __int64 v20; // x22
  int v21; // w24
  int v22; // w0
  __int64 v23; // x8
  int v24; // w20
  unsigned int v25; // w8
  int v26; // w23
  int v27; // w0
  __int64 v28; // x8
  int v29; // w20
  unsigned int v30; // w8
  const char *v31; // x7
  int v32; // w0
  __int64 v33; // x8
  int v34; // w20
  int v35; // w8
  int v36; // w24
  char v37; // w8

  v4 = *(__int64 **)(a1 + 31136);
  v7 = *(_QWORD *)(a1 + 31128);
  v8 = *v4;
  v10 = 1LL << a3;
  v11 = *(unsigned int **)(*v4 + 128);
  v12 = *(_BYTE **)(*v4 + 624);
  v13 = ktime_get_with_offset(1);
  result = ns_to_timespec64(v13);
  v18 = *(_QWORD *)&v12[8 * a2];
  v19 = result;
  v20 = v15;
  if ( (v18 & 0x100) != 0 && 1LL << v12[24] == (unsigned int)v10 )
  {
    v21 = cam_io_r_mb(*(_QWORD *)(v7 + 384) + v11[18]);
    v22 = cam_io_r_mb(*(_QWORD *)(v7 + 384) + v11[19]);
    v23 = *(_QWORD *)(a1 + 31120);
    v24 = v22;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver2_handle_rx_debug_event",
      1770,
      "CSID[%u] LONG_PKT_CAPTURED occurred at [%llu: %09llu]",
      *(_DWORD *)(v23 + 4),
      v19,
      v20);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver2_handle_rx_debug_event",
      1772,
      "The header of the first long pkt matching the configured vc-dt has been captured");
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "cam_ife_csid_ver2_handle_rx_debug_event",
               1777,
               "Virtual Channel: %u, Data Type: %u, Word Count: %u, Error Correction Code: %u",
               (v11[58] & v21) >> v11[61],
               (v11[60] & v21) >> v11[62],
               (v11[59] & v21) >> v11[63],
               v24);
    v25 = v11[73];
LABEL_11:
    v35 = 1 << v25;
LABEL_24:
    *a4 |= v35;
    return result;
  }
  if ( (v18 & 0x200) != 0 && 1LL << v12[25] == (unsigned int)v10 )
  {
    v26 = cam_io_r_mb(*(_QWORD *)(v7 + 384) + v11[16]);
    v27 = cam_io_r_mb(*(_QWORD *)(v7 + 384) + v11[17]);
    v28 = *(_QWORD *)(a1 + 31120);
    v29 = v27;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver2_handle_rx_debug_event",
      1788,
      "CSID[%u] SHORT_PKT_CAPTURED occurred at [%llu: %09llu]",
      *(_DWORD *)(v28 + 4),
      v19,
      v20);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver2_handle_rx_debug_event",
      1790,
      "The header of the first short pkt matching the configured vc-dt has been captured");
    v30 = (v11[60] & v26) >> v11[62];
    if ( v30 > 7 )
      v31 = "Invalid";
    else
      v31 = off_44C638[v30];
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "cam_ife_csid_ver2_handle_rx_debug_event",
               1796,
               "Virtual Channel: %u, Data Type: %s, Frame Line Count: %u, Error Correction Code: %u",
               (v11[58] & v26) >> v11[61],
               v31,
               (v11[59] & v26) >> v11[63],
               v29);
    v35 = 1 << v11[74];
    goto LABEL_24;
  }
  if ( (v18 & 0x400) != 0 && 1LL << v12[26] == (unsigned int)v10 )
  {
    v32 = cam_io_r_mb(*(_QWORD *)(v7 + 384) + v11[21]);
    v33 = *(_QWORD *)(a1 + 31120);
    v34 = v32;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver2_handle_rx_debug_event",
      1805,
      "CSID[%u] CPHY_PKT_HDR_CAPTURED occurred at [%llu: %09llu]",
      *(_DWORD *)(v33 + 4),
      v19,
      v20);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver2_handle_rx_debug_event",
      1807,
      "The header of the first cphy pkt matching the configured vc-dt has been captured");
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "cam_ife_csid_ver2_handle_rx_debug_event",
               1812,
               "Virtual Channel: %u, Data Type: %u, Word Count: %u",
               (v11[58] & v34) >> v11[61],
               (v11[60] & v34) >> v11[62],
               (v11[59] & v34) >> v11[63]);
    v25 = v11[75];
    goto LABEL_11;
  }
  if ( (v18 & 0x400000) != 0 && 1LL << v12[38] == (unsigned int)v10 )
  {
    v36 = cam_io_r_mb(*(_QWORD *)(v7 + 384) + v11[14]);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_handle_rx_debug_event",
      1823,
      "CSID[%u] UNMAPPED_VC_DT occurred at [%llu: %09llu]",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      v19,
      v20);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_handle_rx_debug_event",
      1825,
      "Sensor: A long packet has a VC_DT combination that is not configured for IPP or RDIs");
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_handle_rx_debug_event",
      1830,
      "Virtual Channel: %u, Data Type: %u, Word Count: %u",
      (v11[58] & v36) >> v11[61],
      (v11[60] & v36) >> v11[62],
      (v11[59] & v36) >> v11[63]);
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               8,
               1,
               "cam_ife_csid_ver2_handle_rx_debug_event",
               1832,
               "SW Programming: Populate or Disable the VC DT in sensor driver XML");
    v37 = debug_mdl;
    ++*(_DWORD *)(a1 + 2136);
    if ( (v37 & 8) != 0 && !debug_priority )
      result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                 3,
                 v37 & 8,
                 4,
                 "cam_ife_csid_ver2_handle_rx_debug_event",
                 1838,
                 "CSID[%u] Recoverable Error Count:%u",
                 *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL));
    v35 = 1 << v11[76];
    goto LABEL_24;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    if ( a3 > 0x1F )
    {
      __break(0x5512u);
      return cam_ife_csid_ver2_rx_err_process_top_half(result, v15, v16, v17);
    }
    else
    {
      return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 8,
               4,
               "cam_ife_csid_ver2_handle_rx_debug_event",
               1846,
               "CSID[%u] RX_IRQ: %s",
               *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
               *(const char **)(*(_QWORD *)(v8 + 568) + 1280LL * a2 + 40LL * a3 + 16));
    }
  }
  return result;
}
