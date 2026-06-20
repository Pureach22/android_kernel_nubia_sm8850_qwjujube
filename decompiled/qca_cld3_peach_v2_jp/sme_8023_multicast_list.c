__int64 __fastcall sme_8023_multicast_list(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v14; // t1
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // [xsp+8h] [xbp-38h] BYREF
  __int64 v44; // [xsp+10h] [xbp-30h]
  __int64 v45; // [xsp+18h] [xbp-28h]
  __int64 v46; // [xsp+20h] [xbp-20h]
  __int64 v47; // [xsp+28h] [xbp-18h]
  __int64 v48; // [xsp+30h] [xbp-10h]
  __int64 v49; // [xsp+38h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *a3;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: ulMulticastAddrCnt: %d, multicastAddr[0]: %pK",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sme_8023_multicast_list",
    v14,
    a3 + 1);
  if ( !a1
    || a2 > 5u
    || (v23 = *(_QWORD *)(a1 + 17224)) == 0
    || *(_BYTE *)(v23 + 96LL * a2 + 1) != 1
    || !cm_is_vdevid_connected(*(_QWORD *)(a1 + 21560), a2) && (csr_is_ndi_started(a1, a2) & 1) == 0 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Unable to find the vdev %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "sme_8023_multicast_list",
      a2);
LABEL_13:
    result = 16;
    goto LABEL_14;
  }
  v24 = _qdf_mem_malloc(0x5B4u, "sme_8023_multicast_list", 6274);
  if ( !v24 )
  {
    result = 2;
    goto LABEL_14;
  }
  v25 = v24;
  if ( !cm_is_vdevid_connected(*(_QWORD *)(a1 + 21560), a2) && (csr_is_ndi_started(a1, a2) & 1) == 0 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Request ignored, session %d is not connected or started",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "sme_8023_multicast_list",
      a2);
    goto LABEL_17;
  }
  qdf_mem_copy((void *)v25, a3, 0x5B4u);
  wlan_mlme_get_mac_vdev_id(*(_QWORD *)(a1 + 21560), a2, (void *)(v25 + 1444));
  wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21560), a2, (void *)(v25 + 1450));
  LODWORD(v43) = 4251;
  v44 = v25;
  qdf_trace(52, 0xFBu, a2, 4251);
  result = scheduler_post_message_debug(
             0x34u,
             0x36u,
             54,
             (unsigned __int16 *)&v43,
             0x189Du,
             (__int64)"sme_8023_multicast_list");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Not able to post WMA_8023_MULTICAST_LIST message to WMA",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "sme_8023_multicast_list");
LABEL_17:
    _qdf_mem_free(v25);
    goto LABEL_13;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
