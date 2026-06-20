__int64 __fastcall ol_rx_err(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 a10,
        const void *a11,
        __int64 a12,
        __int64 a13,
        int a14,
        __int64 a15,
        const void *a16,
        char a17)
{
  __int64 result; // x0
  int v23; // w8
  _BYTE *v24; // x23
  __int64 v25; // x24
  __int64 v26; // x20
  __int64 vdev_bssid; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w9
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // [xsp+8h] [xbp-38h] BYREF
  __int64 v46; // [xsp+10h] [xbp-30h]
  __int64 v47; // [xsp+18h] [xbp-28h]
  __int64 v48; // [xsp+20h] [xbp-20h]
  __int64 v49; // [xsp+28h] [xbp-18h]
  __int64 v50; // [xsp+30h] [xbp-10h]
  __int64 v51; // [xsp+38h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(54, (__int64)"ol_rx_err", a1, a2, a3, a4, a5, a6, a7, a8);
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  if ( a14 == 4 && result )
  {
    v23 = (*(_BYTE *)(a15 + 68) & 4) != 0 ? *(unsigned __int16 *)(a15 + 66) : 0;
    if ( (unsigned int)(*(_DWORD *)(a15 + 112) + v23) >= 0xE )
    {
      v24 = *(_BYTE **)(a15 + 224);
      v25 = result;
      result = _qdf_mem_malloc(0x2Cu, "ol_rx_err", 2909);
      if ( result )
      {
        *(_BYTE *)(result + 4) = a10;
        v26 = result;
        *(_DWORD *)result = 2888731;
        vdev_bssid = wma_get_vdev_bssid(*(_QWORD *)(*(_QWORD *)(v25 + 520) + 488LL * a10));
        if ( !vdev_bssid )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Failed to get bssid for vdev_%d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "ol_rx_err",
            a10);
          goto LABEL_12;
        }
        v36 = *(_DWORD *)vdev_bssid;
        *(_WORD *)(v26 + 9) = *(_WORD *)(vdev_bssid + 4);
        *(_DWORD *)(v26 + 5) = v36;
        qdf_mem_copy((void *)(v26 + 17), a11, 6u);
        qdf_mem_copy((void *)(v26 + 11), v24 + 6, 6u);
        qdf_mem_copy((void *)(v26 + 23), v24, 6u);
        *(_BYTE *)(v26 + 31) = a17;
        *(_BYTE *)(v26 + 29) = *v24 & 1;
        qdf_mem_copy((void *)(v26 + 32), a16, 6u);
        qdf_mem_set(&v45, 0x30u, 0);
        LOWORD(v45) = 5147;
        v46 = v26;
        result = scheduler_post_message_debug(0x3Fu, 0x34u, 52, (unsigned __int16 *)&v45, 0xB82u, (__int64)"ol_rx_err");
        if ( (_DWORD)result )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: could not post mic failure indication to SME",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "ol_rx_err");
LABEL_12:
          result = _qdf_mem_free(v26);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
