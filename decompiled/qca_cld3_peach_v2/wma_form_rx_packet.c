__int64 __fastcall wma_form_rx_packet(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  int v33; // w8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w8
  int v43; // w8
  unsigned int v44; // w4
  int v45; // w8
  const char *v46; // x2
  int v47; // w8
  __int64 result; // x0
  char v49; // w8
  unsigned int v50; // w4
  unsigned __int8 *v51; // x25
  int v52; // w8
  int v53; // w8
  unsigned int v54; // w24
  unsigned int v55; // w23
  unsigned int vdev_id_from_bssid; // w0
  unsigned __int8 v57; // w8
  unsigned __int8 v58; // w8
  __int64 v59; // x4
  __int64 v60; // x5
  __int64 v61; // x6
  __int64 v62; // x7
  unsigned __int8 *v63; // [xsp+10h] [xbp-20h] BYREF
  unsigned __int8 v64[4]; // [xsp+1Ch] [xbp-14h] BYREF
  int v65; // [xsp+20h] [xbp-10h] BYREF
  __int16 v66; // [xsp+24h] [xbp-Ch]
  __int64 v67; // [xsp+28h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64[0] = -1;
  context = _cds_get_context(54, (__int64)"wma_form_rx_packet", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
    goto LABEL_20;
  if ( a2 )
  {
    v23 = (__int64)context;
    if ( (cds_get_driver_state(v15, v16, v17, v18, v19, v20, v21, v22) & 6) != 0 )
    {
      v32 = (unsigned __int8)wma_form_rx_packet_limit_prints_load_unload++ + 1;
      if ( v32 == 16 )
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Load/Unload in progress",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wma_form_rx_packet");
        wma_form_rx_packet_limit_prints_load_unload = 0;
      }
      goto LABEL_20;
    }
    if ( (cds_get_driver_state(v24, v25, v26, v27, v28, v29, v30, v31) & 8) != 0 )
    {
      v45 = (unsigned __int8)wma_form_rx_packet_limit_prints_recovery++ + 1;
      if ( v45 != 16 )
        goto LABEL_20;
      v46 = "%s: Recovery in progress";
    }
    else
    {
      if ( (cds_get_driver_state(v34, v35, v36, v37, v38, v39, v40, v41) & 0x10) == 0 )
      {
        *(_DWORD *)a3 = *a2;
        *(_BYTE *)(a3 + 45) = a2[8];
        v42 = a2[2] - 96;
        *(_DWORD *)(a3 + 8) = v42;
        *(_BYTE *)(a3 + 4) = a2[2];
        if ( a2[9] )
          v42 = a2[9];
        *(_DWORD *)(a3 + 52) = v42;
        v43 = jiffies;
        *(_DWORD *)(a3 + 36) = 24;
        *(_DWORD *)(a3 + 12) = v43;
        v44 = a2[6];
        *(_DWORD *)(a3 + 32) = v44;
        if ( v44 <= 0x17 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: MPDU Len %d lesser than header len %d",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "wma_form_rx_packet");
          if ( !a1 )
            goto LABEL_22;
          goto LABEL_21;
        }
        v49 = *(_BYTE *)(a3 + 44);
        v50 = v44 - 24;
        *(_DWORD *)(a3 + 40) = v50;
        *(_BYTE *)(a3 + 44) = v49 & 0xFD;
        v51 = *(unsigned __int8 **)(a1 + 224);
        v63 = v51;
        if ( v50 >= 0x901 )
        {
          if ( v51 == (unsigned __int8 *)-16LL )
            v52 = 0;
          else
            v52 = v51[21];
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Data Len %d greater than max, dropping frame from %02x:%02x:%02x:**:**:%02x",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "wma_form_rx_packet",
            v52);
          if ( !a1 )
            goto LABEL_22;
          goto LABEL_21;
        }
        *(_QWORD *)(a3 + 16) = v51;
        *(_QWORD *)(a3 + 24) = v51 + 24;
        v53 = a2[10];
        *(_QWORD *)(a3 + 56) = a1;
        *(_QWORD *)(a3 + 64) = a1;
        *(_DWORD *)(a3 + 48) = v53;
        v54 = *v51 & 0xC;
        v55 = *v51 & 0xF0;
        if ( (*v51 & 0xC) != 0 )
        {
          *(_BYTE *)(a3 + 47) = 0;
        }
        else
        {
          if ( v55 - 160 <= 0x30 && ((1LL << ((unsigned __int8)v55 + 96)) & 0x1000100000001LL) != 0 )
          {
            if ( (unsigned int)wma_find_vdev_id_by_bssid(
                                 v23,
                                 (__int64)(v51 + 16),
                                 v64,
                                 v34,
                                 v35,
                                 v36,
                                 v37,
                                 v38,
                                 v39,
                                 v40,
                                 v41)
              && (unsigned int)wma_find_vdev_id_by_addr(v23, (__int64)(v51 + 4), v64) )
            {
              if ( v55 == 208 )
              {
                vdev_id_from_bssid = wlan_nan_get_vdev_id_from_bssid(*(_QWORD *)(v23 + 32), v51 + 16, 43);
                v64[0] = vdev_id_from_bssid;
                if ( (_BYTE)vdev_id_from_bssid == 0xFF )
                  goto LABEL_44;
                result = wma_check_and_process_rmf_frame(v23, vdev_id_from_bssid, &v63, a3, a1);
                if ( (_DWORD)result )
                  goto LABEL_24;
                v57 = v64[0];
                if ( v64[0] == 0xFF )
LABEL_44:
                  v57 = 0;
                *(_BYTE *)(a3 + 47) = v57;
                goto LABEL_32;
              }
            }
            else
            {
              result = wma_check_and_process_rmf_frame(v23, v64[0], &v63, a3, a1);
              if ( (_DWORD)result )
                goto LABEL_24;
            }
          }
          v58 = v64[0];
          if ( v64[0] == 255 )
            v58 = 0;
          *(_BYTE *)(a3 + 47) = v58;
          if ( v55 == 80 || v55 == 128 )
          {
            v51 = v63;
            if ( a2[6] <= 0x24u )
            {
              if ( v63 == (unsigned __int8 *)-16LL )
              {
                v61 = 0;
                v59 = 0;
                v60 = 0;
                v62 = 0;
              }
              else
              {
                v59 = v63[16];
                v60 = v63[17];
                v61 = v63[18];
                v62 = v63[21];
              }
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: Dropping frame from %02x:%02x:%02x:**:**:%02x",
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                "wma_form_rx_packet",
                v59,
                v60,
                v61,
                v62);
              goto LABEL_57;
            }
          }
          else
          {
            v51 = v63;
          }
        }
        v66 = 0;
        v65 = 26898256;
        if ( v55 != 128 || (unsigned int)qdf_mem_cmp(&v65, v51 + 16, 4u) )
        {
LABEL_32:
          wma_mgmt_pktdump_rx_handler(a2, a3, v23, v54, v55);
          result = 0;
          goto LABEL_24;
        }
LABEL_57:
        cds_pkt_return_packet(a3);
        goto LABEL_23;
      }
      v47 = (unsigned __int8)wma_form_rx_packet_limit_prints_recovery++ + 1;
      if ( v47 != 16 )
        goto LABEL_20;
      v46 = "%s: Driver in bad state";
    }
    qdf_trace_msg(0x36u, 8u, v46, v34, v35, v36, v37, v38, v39, v40, v41, "wma_form_rx_packet");
    wma_form_rx_packet_limit_prints_recovery = 0;
    goto LABEL_20;
  }
  v33 = (unsigned __int8)wma_form_rx_packet_limit_prints_invalid_len++ + 1;
  if ( v33 == 16 )
  {
    qdf_trace_msg(0x36u, 8u, "%s: mgmt rx params is NULL", v15, v16, v17, v18, v19, v20, v21, v22, "wma_form_rx_packet");
    wma_form_rx_packet_limit_prints_invalid_len = 0;
  }
LABEL_20:
  if ( a1 )
LABEL_21:
    _qdf_nbuf_free(a1);
LABEL_22:
  _qdf_mem_free(a3);
LABEL_23:
  result = 4294967274LL;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
