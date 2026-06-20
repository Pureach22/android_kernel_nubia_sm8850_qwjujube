__int64 __fastcall wma_chan_info_event_handler(
        __int64 *a1,
        int **a2,
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
  int **v21; // x8
  int *v22; // x19
  int *v23; // x23
  unsigned int v24; // w20
  __int64 v25; // x8
  _QWORD *v26; // x21
  unsigned __int8 v27; // w0
  __int64 v28; // x8
  _QWORD *v29; // x22
  unsigned __int8 v30; // w21
  void (__fastcall *v31)(_QWORD); // x8
  int v32; // w10
  int v33; // w9
  int v34; // w12
  int v35; // w10
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x22
  __int64 v46; // x24
  __int64 v47; // x27
  int *v48; // x28
  int v49; // t1
  __int64 result; // x0
  const char *v51; // x2
  int v52; // w8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v61; // w10
  unsigned int v62; // w6
  unsigned int v63; // w7
  int v64; // w9
  int v65; // w11
  int v66; // w12
  unsigned int v67; // w12
  int v68; // w9
  __int64 v69; // [xsp+68h] [xbp-A8h] BYREF
  __int64 v70; // [xsp+70h] [xbp-A0h]
  __int64 v71; // [xsp+78h] [xbp-98h]
  __int64 v72; // [xsp+80h] [xbp-90h]
  __int64 v73; // [xsp+88h] [xbp-88h]
  __int64 v74; // [xsp+90h] [xbp-80h]
  __int64 v75; // [xsp+98h] [xbp-78h] BYREF
  __int64 v76; // [xsp+A0h] [xbp-70h]
  __int64 v77; // [xsp+A8h] [xbp-68h]
  __int64 v78; // [xsp+B0h] [xbp-60h]
  __int64 v79; // [xsp+B8h] [xbp-58h]
  __int64 v80; // [xsp+C0h] [xbp-50h]
  __int64 v81; // [xsp+C8h] [xbp-48h]
  __int64 v82; // [xsp+D0h] [xbp-40h]
  __int64 v83; // [xsp+D8h] [xbp-38h]
  __int64 v84; // [xsp+E0h] [xbp-30h]
  __int64 v85; // [xsp+E8h] [xbp-28h]
  __int64 v86; // [xsp+F0h] [xbp-20h]
  int v87; // [xsp+F8h] [xbp-18h]
  __int64 v88; // [xsp+100h] [xbp-10h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v87 = 0;
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  if ( !a1
    || !a1[1]
    || (context = _cds_get_context(53, (__int64)"wma_chan_info_event_handler", a3, a4, a5, a6, a7, a8, a9, a10)) == nullptr )
  {
    result = 4294967274LL;
    goto LABEL_24;
  }
  if ( !a2 )
  {
    v51 = "%s: Invalid chan info event buffer";
LABEL_27:
    qdf_trace_msg(0x36u, 2u, v51, v13, v14, v15, v16, v17, v18, v19, v20, "wma_chan_info_event_handler");
    result = 4294967274LL;
    goto LABEL_24;
  }
  v21 = a2;
  v22 = *a2;
  if ( !v22 )
  {
    v51 = "%s: Invalid fixed param";
    goto LABEL_27;
  }
  if ( v22[3] == 1 )
  {
LABEL_37:
    result = 0;
    goto LABEL_24;
  }
  v23 = v21[4];
  v24 = *((_DWORD *)v21 + 10);
  v25 = *a1;
  v26 = context;
  v27 = wmi_service_enabled(v25, 0x126u, v13, v14, v15, v16, v17, v18, v19, v20);
  v28 = v26[2703];
  v29 = v26;
  v30 = v27;
  if ( (wlan_scan_is_snr_monitor_enabled(v28) & 1) != 0 )
  {
    v31 = (void (__fastcall *)(_QWORD))v29[2705];
    if ( v31 )
    {
      v32 = v22[13];
      HIDWORD(v77) = v22[12];
      LODWORD(v78) = v32;
      v33 = v22[3];
      v34 = v22[6];
      LODWORD(v75) = v22[2];
      HIDWORD(v75) = v33;
      v35 = v22[5];
      LODWORD(v76) = v22[4];
      HIDWORD(v76) = v34;
      LODWORD(v77) = v35;
      if ( (v30 & (v24 != 0)) == 1 )
      {
        wma_update_scan_channel_info_buf(v22, &v75, v23, v24);
        v31 = (void (__fastcall *)(_QWORD))v29[2705];
      }
      if ( *((_DWORD *)v31 - 1) != -2079570912 )
        __break(0x8228u);
      v31(&v75);
    }
  }
  v36 = _qdf_mem_malloc(0x7Cu, "wma_chan_info_event_handler", 6135);
  if ( v36 )
  {
    v45 = v36;
    *(_DWORD *)v36 = v22[2];
    *(_DWORD *)(v36 + 4) = v22[4];
    if ( (v30 & (v24 != 0)) == 1 )
    {
      if ( v23 )
      {
        v46 = 0;
        if ( v24 >= 0x10 )
          v47 = 16;
        else
          v47 = v24;
        v48 = v23 + 1;
        *(_BYTE *)(v36 + 56) = 0;
        do
        {
          v49 = *v48;
          v48 += 2;
          *(_DWORD *)(v45 + 60 + 4 * v46) = v49;
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: cca_info->rx_clear_count[%d]: %d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "wma_update_scan_channel_subband_info",
            (unsigned int)v46++);
          ++*(_BYTE *)(v45 + 56);
        }
        while ( v47 != v46 );
        *(_BYTE *)(v45 + 57) = 1;
        *(_DWORD *)(v45 + 52) = v22[14];
      }
    }
    else
    {
      *(_DWORD *)(v36 + 8) = v22[5];
    }
    *(_DWORD *)(v45 + 12) = v22[6];
    *(_DWORD *)(v45 + 16) = v22[7];
    *(_DWORD *)(v45 + 20) = v22[8];
    *(_DWORD *)(v45 + 24) = v22[9];
    *(_DWORD *)(v45 + 28) = v22[10];
    *(_DWORD *)(v45 + 32) = v22[11];
    *(_DWORD *)(v45 + 36) = v22[12];
    *(_DWORD *)(v45 + 40) = v22[13];
    v52 = (unsigned __int8)cds_freq_to_chan(v22[2]);
    *(_DWORD *)(v45 + 44) = v52;
    v61 = v22[3];
    *(_DWORD *)(v45 + 48) = v61;
    v62 = v22[5];
    v63 = v22[6];
    v64 = v22[12];
    v65 = v22[10];
    if ( v63 )
    {
      v66 = v65 + v64;
      if ( v62 <= v65 + v64 )
        v66 = 0;
      v67 = 100 * (v62 - v66) / v63;
    }
    else
    {
      v67 = 0;
    }
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: freq %d, nf %d, rcc %u, cc %u, tx_r %d, tx_t %d, tx_frm %u rx_frm %u my_rx_cc %u mac_clk_mhz %u rx_11b_data_du"
      "r %d chan_id:%d, flags:%d, cap: %d, cu percent %d num_tlvs:%d",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "wma_chan_info_event_handler",
      (unsigned int)v22[2],
      (unsigned int)v22[4],
      v22[7],
      v22[8],
      v22[12],
      v22[9],
      v22[10],
      v22[13],
      v22[11],
      v52,
      v61,
      v30 & 1,
      v67,
      v24);
    v68 = v22[14];
    LOWORD(v69) = 5298;
    v70 = v45;
    HIDWORD(v69) = v68;
    result = scheduler_post_message_debug(
               0x36u,
               0x34u,
               52,
               (unsigned __int16 *)&v69,
               0x182Bu,
               (__int64)"wma_chan_info_event_handler");
    if ( (_DWORD)result )
    {
      _qdf_mem_free(v45);
      goto LABEL_37;
    }
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
