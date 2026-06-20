__int64 __fastcall wlan_hdd_add_tx_ptrn(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  unsigned __int8 *v25; // x19
  unsigned int v26; // w22
  __int64 v27; // x8
  __int64 v28; // x1
  __int64 v29; // x23
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v39; // x2
  __int64 result; // x0
  unsigned int v41; // w20
  __int64 v42; // x1
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  _WORD *v51; // x8
  unsigned __int16 v52; // w8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x8
  unsigned int v62; // w4
  unsigned int v63; // w0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int16 v80[2]; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int8 v81[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v82; // [xsp+10h] [xbp-10h] BYREF
  __int16 v83; // [xsp+14h] [xbp-Ch]
  __int64 v84; // [xsp+18h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 52824);
  v81[0] = 0;
  v83 = 0;
  v82 = 0;
  v80[0] = 8;
  if ( (hdd_cm_is_vdev_associated(v6) & 1) != 0 )
  {
    v15 = _qdf_mem_malloc(0x610u, "wlan_hdd_add_tx_ptrn", 18356);
    if ( v15 )
    {
      v24 = a3[2];
      v25 = (unsigned __int8 *)v15;
      if ( v24 )
      {
        v26 = *(_DWORD *)(v24 + 4);
        if ( v26 == -1 )
        {
          v39 = "%s: request_id cannot be MAX";
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Request Id: %u",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "wlan_hdd_add_tx_ptrn",
            v26);
          v27 = a3[6];
          if ( v27 )
          {
            *((_DWORD *)v25 + 3) = *(_DWORD *)(v27 + 4);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Period: %u ms",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "wlan_hdd_add_tx_ptrn");
            if ( *((_DWORD *)v25 + 3) )
            {
              v28 = a3[4];
              if ( v28 )
              {
                v29 = a1 + 1617;
                nla_memcpy(v25, v28, 6);
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: input src mac address: %02x:%02x:%02x:**:**:%02x",
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  "wlan_hdd_add_tx_ptrn",
                  *v25,
                  v25[1],
                  v25[2],
                  v25[5]);
                if ( *(_DWORD *)v25 == *(_DWORD *)v29
                  && *((unsigned __int16 *)v25 + 2) == *(unsigned __int16 *)(v29 + 4) )
                {
                  v42 = a3[5];
                  if ( v42 )
                  {
                    nla_memcpy(&v82, v42, 6);
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: input dst mac address: %02x:%02x:%02x:**:**:%02x",
                      v43,
                      v44,
                      v45,
                      v46,
                      v47,
                      v48,
                      v49,
                      v50,
                      "wlan_hdd_add_tx_ptrn",
                      (unsigned __int8)v82,
                      BYTE1(v82),
                      BYTE2(v82),
                      HIBYTE(v83));
                    v51 = (_WORD *)a3[3];
                    if ( v51 )
                    {
                      v52 = *v51 - 4;
                      *((_WORD *)v25 + 4) = v52;
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: IP packet len: %u",
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        v22,
                        v23,
                        "wlan_hdd_add_tx_ptrn",
                        v52);
                      if ( *((unsigned __int16 *)v25 + 4) < 0x5F3u )
                      {
                        v61 = a3[7];
                        if ( v61 )
                          v62 = bswap32(*(unsigned __int16 *)(v61 + 4)) >> 16;
                        else
                          LOWORD(v62) = 8;
                        v80[0] = v62;
                        qdf_trace_msg(
                          0x33u,
                          8u,
                          "%s: packet proto type: %u",
                          v53,
                          v54,
                          v55,
                          v56,
                          v57,
                          v58,
                          v59,
                          v60,
                          "wlan_hdd_add_tx_ptrn");
                        qdf_mem_copy(v25 + 16, &v82, 6u);
                        qdf_mem_copy(v25 + 22, v25, 6u);
                        qdf_mem_copy(v25 + 28, v80, 2u);
                        qdf_mem_copy(v25 + 30, (const void *)(a3[3] + 4LL), *((unsigned __int16 *)v25 + 4));
                        *((_WORD *)v25 + 4) += 14;
                        v63 = hdd_map_req_id_to_pattern_id(a2, v26, v81);
                        if ( v63 )
                        {
                          v41 = v63;
                          qdf_trace_msg(
                            0x33u,
                            2u,
                            "%s: req id to pattern id failed (ret=%d)",
                            v64,
                            v65,
                            v66,
                            v67,
                            v68,
                            v69,
                            v70,
                            v71,
                            "wlan_hdd_add_tx_ptrn");
                        }
                        else
                        {
                          v25[6] = v81[0];
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: pattern id: %d",
                            v64,
                            v65,
                            v66,
                            v67,
                            v68,
                            v69,
                            v70,
                            v71,
                            "wlan_hdd_add_tx_ptrn");
                          v41 = sme_add_periodic_tx_ptrn(*(_QWORD *)(a2 + 16), v25);
                          if ( v41 )
                          {
                            qdf_trace_msg(
                              0x33u,
                              2u,
                              "%s: sme_add_periodic_tx_ptrn failed (err=%d)",
                              v72,
                              v73,
                              v74,
                              v75,
                              v76,
                              v77,
                              v78,
                              v79,
                              "wlan_hdd_add_tx_ptrn",
                              v41);
                            v41 = qdf_status_to_os_return(v41);
                          }
                          else
                          {
                            qdf_trace_msg(
                              0x33u,
                              8u,
                              "%s: exit",
                              v72,
                              v73,
                              v74,
                              v75,
                              v76,
                              v77,
                              v78,
                              v79,
                              "wlan_hdd_add_tx_ptrn");
                          }
                        }
                        goto LABEL_22;
                      }
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: Invalid IP packet len: %d",
                        v53,
                        v54,
                        v55,
                        v56,
                        v57,
                        v58,
                        v59,
                        v60,
                        "wlan_hdd_add_tx_ptrn");
LABEL_21:
                      v41 = -22;
LABEL_22:
                      _qdf_mem_free((__int64)v25);
                      result = v41;
                      goto LABEL_23;
                    }
                    v39 = "%s: attr ip packet failed";
                  }
                  else
                  {
                    v39 = "%s: attr dst mac address failed";
                  }
                }
                else
                {
                  v39 = "%s: input src mac address and connected ap bssid are different";
                }
              }
              else
              {
                v39 = "%s: attr source mac address failed";
              }
            }
            else
            {
              v39 = "%s: Invalid interval zero, return failure";
            }
          }
          else
          {
            v39 = "%s: attr period failed";
          }
        }
      }
      else
      {
        v39 = "%s: attr request id failed";
      }
      qdf_trace_msg(0x33u, 2u, v39, v16, v17, v18, v19, v20, v21, v22, v23, "wlan_hdd_add_tx_ptrn");
      goto LABEL_21;
    }
    result = 4294967284LL;
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Not in Connected state!", v7, v8, v9, v10, v11, v12, v13, v14, "wlan_hdd_add_tx_ptrn");
    result = 4294966772LL;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
