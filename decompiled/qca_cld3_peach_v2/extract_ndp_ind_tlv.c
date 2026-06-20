__int64 __fastcall extract_ndp_ind_tlv(
        __int64 a1,
        __int64 *a2,
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
  __int64 v11; // x19
  __int64 v12; // x4
  const char *v13; // x2
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x10
  const char *v18; // x2
  unsigned __int64 v19; // x9
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w8
  int v32; // w10
  unsigned __int8 v33; // w11
  int v34; // w12
  int v35; // w13
  int v36; // w14
  unsigned __int8 v37; // w15
  int v38; // w16
  int v39; // w17
  int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x8
  __int64 *v50; // x9
  unsigned int v51; // w10
  size_t v52; // x2
  unsigned int v53; // w10
  size_t v54; // x2
  unsigned int v55; // w10
  size_t v56; // x2
  __int64 v57; // x10
  unsigned int v58; // w8

  v11 = *a2;
  v12 = *(unsigned int *)(*a2 + 40);
  if ( (unsigned int)v12 <= *((_DWORD *)a2 + 6) )
  {
    v14 = *(unsigned int *)(v11 + 44);
    if ( (unsigned int)v14 > *((_DWORD *)a2 + 10) )
    {
      v13 = "%s: FW message ndp app info length %d more than TLV hdr %d";
      goto LABEL_9;
    }
    v15 = *(unsigned int *)(v11 + 52);
    if ( (unsigned int)v15 > *((_DWORD *)a2 + 14) )
    {
      v13 = "%s: FW msg ndp scid info len %d more than TLV hdr %d";
      goto LABEL_9;
    }
    v16 = *(unsigned int *)(v11 + 64);
    if ( (unsigned int)v16 > *((_DWORD *)a2 + 22) )
    {
      v13 = "%s: FW msg service id len %d more than TLV hdr %d";
      goto LABEL_9;
    }
    if ( (unsigned int)v12 < 0x5B5 )
    {
      if ( 1460 - v12 >= v14 )
      {
        v19 = v14 + v12 + 76;
        if ( 1536 - v19 >= v15 )
        {
          if ( 1536 - v15 - v19 >= v16 )
          {
            v22 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                    **(_QWORD **)(a1 + 760),
                    *(unsigned int *)(v11 + 4),
                    20);
            *(_QWORD *)a3 = v22;
            if ( !v22 )
            {
              qdf_trace_msg(
                0x31u,
                2u,
                "%s: vdev is null",
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                "extract_ndp_ind_tlv");
              return 4;
            }
            *(_DWORD *)(a3 + 8) = *(_DWORD *)(v11 + 16);
            *(_DWORD *)(a3 + 24) = *(_DWORD *)(v11 + 36);
            *(_DWORD *)(a3 + 28) = *(_DWORD *)(v11 + 8);
            *(_DWORD *)(a3 + 32) = *(_DWORD *)(v11 + 12);
            v31 = *(_DWORD *)(v11 + 68);
            *(_DWORD *)(a3 + 844) = v31;
            v32 = *(_DWORD *)(v11 + 72);
            *(_DWORD *)(a3 + 848) = v32;
            v33 = *(_DWORD *)(v11 + 28);
            *(_BYTE *)(a3 + 18) = v33;
            v34 = *(_DWORD *)(v11 + 28);
            *(_BYTE *)(a3 + 19) = BYTE1(v34);
            v35 = *(_DWORD *)(v11 + 28);
            *(_BYTE *)(a3 + 20) = BYTE2(v35);
            *(_BYTE *)(a3 + 21) = *(_BYTE *)(v11 + 31);
            *(_BYTE *)(a3 + 22) = *(_DWORD *)(v11 + 32);
            v36 = *(_DWORD *)(v11 + 32);
            *(_BYTE *)(a3 + 23) = BYTE1(v36);
            v37 = *(_DWORD *)(v11 + 20);
            *(_BYTE *)(a3 + 12) = v37;
            v38 = *(_DWORD *)(v11 + 20);
            *(_BYTE *)(a3 + 13) = BYTE1(v38);
            v39 = *(_DWORD *)(v11 + 20);
            *(_BYTE *)(a3 + 14) = BYTE2(v39);
            *(_BYTE *)(a3 + 15) = *(_BYTE *)(v11 + 23);
            *(_BYTE *)(a3 + 16) = *(_DWORD *)(v11 + 24);
            v40 = *(_DWORD *)(v11 + 24);
            *(_BYTE *)(a3 + 17) = BYTE1(v40);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: WMI_NDP_INDICATION_EVENTID(0x%X) received. vdev %d service_instance %d, ndp_instance %d, role %d, poli"
              "cy %d csid: %d, scid_len: %d, peer_addr: %02x:%02x:%02x:**:**:%02x, peer_disc_addr: %02x:%02x:%02x:**:**:%"
              "02x ndp_cfg - %d bytes ndp_app_info - %d bytes ndp_csid_caps %d, ndp_gtk_required %d",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "extract_ndp_ind_tlv",
              229381,
              *(unsigned int *)(v11 + 4),
              *(unsigned int *)(v11 + 16),
              *(unsigned int *)(v11 + 36),
              *(_DWORD *)(v11 + 8),
              *(_DWORD *)(v11 + 12),
              *(_DWORD *)(v11 + 48),
              *(_DWORD *)(v11 + 52),
              v33,
              BYTE1(v34),
              BYTE2(v35),
              BYTE1(v36),
              v37,
              BYTE1(v38),
              BYTE2(v39),
              BYTE1(v40),
              *(_DWORD *)(v11 + 40),
              *(_DWORD *)(v11 + 44),
              v31,
              v32);
            v49 = a3;
            *(_DWORD *)(a3 + 556) = *(_DWORD *)(v11 + 48);
            v50 = a2;
            if ( a2[2] )
            {
              v51 = *(_DWORD *)(v11 + 40);
              if ( v51 >= 0xFF )
                v52 = 255;
              else
                v52 = v51;
              *(_DWORD *)(a3 + 36) = v52;
              qdf_mem_copy((void *)(a3 + 40), (const void *)a2[2], v52);
              v50 = a2;
              v49 = a3;
            }
            if ( v50[4] )
            {
              v53 = *(_DWORD *)(v11 + 44);
              if ( v53 >= 0xFF )
                v54 = 255;
              else
                v54 = v53;
              *(_DWORD *)(v49 + 296) = v54;
              qdf_mem_copy((void *)(v49 + 300), (const void *)v50[4], v54);
              v50 = a2;
              v49 = a3;
            }
            if ( v50[6] )
            {
              v55 = *(_DWORD *)(v11 + 52);
              if ( v55 >= 0x100 )
                v56 = 256;
              else
                v56 = v55;
              *(_DWORD *)(v49 + 560) = v56;
              qdf_mem_copy((void *)(v49 + 564), (const void *)v50[6], v56);
              v50 = a2;
              v49 = a3;
            }
            v57 = v50[8];
            if ( v57 && *((_DWORD *)v50 + 18) && *(_DWORD *)(v57 + 4) )
            {
              *(_BYTE *)(v49 + 820) = 1;
              qdf_mem_copy((void *)(v49 + 821), (const void *)(v50[8] + 16), 0x10u);
              v49 = a3;
            }
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: IPv6 addr present: %d, addr: %pI6",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "extract_ndp_ind_tlv",
              *(unsigned __int8 *)(v49 + 820),
              v49 + 821);
            *(_BYTE *)(a3 + 837) = 0;
            v58 = *(_DWORD *)(v11 + 64);
            if ( v58 && a2[10] )
            {
              if ( v58 <= 5 )
              {
                v12 = *((unsigned int *)a2 + 22);
                v18 = "%s: Invalid service id length %d";
                goto LABEL_20;
              }
              *(_BYTE *)(a3 + 837) = 1;
              qdf_mem_copy((void *)(a3 + 838), (const void *)a2[10], 6u);
            }
            return 0;
          }
          v18 = "%s: excess wmi buffer: service_cfg_len %d";
          v12 = (unsigned int)v16;
        }
        else
        {
          v18 = "%s: excess wmi buffer: ndp_cfg_len %d";
          v12 = (unsigned int)v15;
        }
      }
      else
      {
        v18 = "%s: excess wmi buffer: ndp_cfg_len %d";
        v12 = (unsigned int)v14;
      }
    }
    else
    {
      v18 = "%s: excess wmi buffer: ndp_cfg_len %d";
    }
LABEL_20:
    qdf_trace_msg(0x31u, 2u, v18, a4, a5, a6, a7, a8, a9, a10, a11, "extract_ndp_ind_tlv", v12);
    return 4;
  }
  v13 = "%s: FW message ndp cfg length %d larger than TLV hdr %d";
LABEL_9:
  qdf_trace_msg(0x31u, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "extract_ndp_ind_tlv");
  return 4;
}
