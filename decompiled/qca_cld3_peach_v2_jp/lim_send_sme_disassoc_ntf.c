__int64 __fastcall lim_send_sme_disassoc_ntf(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        unsigned int a4,
        unsigned __int16 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        __int64 a14,
        unsigned __int8 a15,
        __int64 a16)
{
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  int v25; // w8
  int v26; // w25
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w8
  __int64 v36; // x25
  unsigned __int64 v37; // x26
  __int64 v38; // x28
  __int64 v39; // x4
  unsigned __int16 *sta_ds; // x0
  __int64 result; // x0
  __int64 v42; // x24
  _WORD *v43; // x23
  char v44; // w25
  unsigned __int16 *v45; // x24
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v63; // w8
  int opmode_from_vdev_id; // w0
  __int64 v65; // x1
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int16 v74; // w8
  __int64 v75; // [xsp+20h] [xbp-40h] BYREF
  _WORD *v76; // [xsp+28h] [xbp-38h]
  __int64 v77; // [xsp+30h] [xbp-30h]
  __int64 v78; // [xsp+38h] [xbp-28h]
  __int64 v79; // [xsp+40h] [xbp-20h]
  __int64 v80; // [xsp+48h] [xbp-18h]
  __int16 v81; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v82; // [xsp+58h] [xbp-8h]

  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v22 = *a2;
    v23 = a2[1];
    v24 = a2[2];
    v25 = a2[5];
  }
  else
  {
    v24 = 0;
    v22 = 0;
    v23 = 0;
    v25 = 0;
  }
  v26 = a5;
  v81 = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdev %d: peer %02x:%02x:%02x:**:**:%02x trigger %d reason %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "lim_send_sme_disassoc_ntf",
    a15,
    v22,
    v23,
    v24,
    v25,
    a5,
    a4);
  if ( (unsigned int)(v26 - 1) < 2 )
    goto LABEL_21;
  if ( !v26 )
  {
    result = _qdf_mem_malloc(0x14u, "lim_send_sme_disassoc_ntf", 979);
    v42 = result;
    if ( result )
    {
      *(_BYTE *)(result + 4) = a15;
      *(_DWORD *)result = 1315849;
      *(_DWORD *)(result + 8) = a4;
      qdf_mem_copy((void *)(result + 12), a2, 6u);
      result = lim_diag_event_report(a1, 12, a16, a4);
      v43 = nullptr;
      v44 = 0;
      goto LABEL_28;
    }
LABEL_18:
    v43 = nullptr;
    v44 = 1;
    goto LABEL_28;
  }
  if ( v26 != 9 )
  {
    result = _qdf_mem_malloc(0x28u, "lim_send_sme_disassoc_ntf", 1017);
    v42 = result;
    if ( result )
    {
      *(_BYTE *)(result + 4) = a15;
      *(_DWORD *)result = 2626570;
      *(_DWORD *)(result + 32) = a4;
      *(_DWORD *)(result + 8) = a4;
      qdf_mem_copy((void *)(result + 12), (const void *)(a16 + 24), 6u);
      qdf_mem_copy((void *)(v42 + 18), a2, 6u);
      result = lim_diag_event_report(a1, 13, a16, a4);
      v44 = 0;
      v43 = (_WORD *)v42;
      goto LABEL_28;
    }
    goto LABEL_18;
  }
  v35 = *(unsigned __int16 *)(a1 + 3992);
  if ( !*(_WORD *)(a1 + 3992) )
    goto LABEL_21;
  v36 = 0;
  v37 = 0;
  while ( 1 )
  {
    v38 = *(_QWORD *)(a1 + 12264);
    v39 = v38 + v36;
    if ( !*(_BYTE *)(v38 + v36 + 70) || *(_DWORD *)(v39 + 7036) != 1 )
      goto LABEL_9;
    sta_ds = (unsigned __int16 *)lim_get_sta_ds(a1, a2, a3, &v81, v39, v27, v28, v29, v30, v31, v32, v33, v34);
    if ( sta_ds )
      break;
    v35 = *(unsigned __int16 *)(a1 + 3992);
LABEL_9:
    ++v37;
    v36 += 10792;
    if ( v37 >= v35 )
      goto LABEL_21;
  }
  v45 = sta_ds;
  if ( (unsigned int)lim_add_sta(a1, sta_ds, 0, v38 + v36) )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not Add STA with assocId: %d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "lim_send_sme_disassoc_ntf",
      v45[168]);
LABEL_21:
  v54 = _qdf_mem_malloc(0x14u, "lim_prepare_disconnect_done_ind", 1299);
  if ( v54 )
  {
    v42 = v54;
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Prepare eWNI_SME_DISCONNECT_DONE_IND withretCode: %d",
               v55,
               v56,
               v57,
               v58,
               v59,
               v60,
               v61,
               v62,
               "lim_prepare_disconnect_done_ind",
               a4);
    *(_BYTE *)(v42 + 4) = a15;
    *(_DWORD *)v42 = 1315855;
    if ( a2 )
      result = (__int64)qdf_mem_copy((void *)(v42 + 12), a2, 6u);
    v43 = nullptr;
    v44 = 0;
    if ( a4 == 505 )
      v63 = 0;
    else
      v63 = a4;
    *(_DWORD *)(v42 + 8) = v63;
LABEL_28:
    if ( a16 && *(_DWORD *)(a16 + 88) == 2 )
      result = pe_delete_session(a1);
    if ( (v44 & 1) == 0 )
    {
      opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), a15);
      if ( v43 && (opmode_from_vdev_id & 0xFFFFFFFD) == 0 && *v43 == 5130 )
      {
        v79 = 0;
        v80 = 0;
        v77 = 0;
        v78 = 0;
        v75 = 0;
        v76 = nullptr;
        v74 = *v43;
        v76 = v43;
        LOWORD(v75) = v74;
        result = lim_send_sta_disconnect_ind(a1, &v75);
      }
      else
      {
        result = lim_send_sme_disassoc_deauth_ntf(
                   a1,
                   v66,
                   v67,
                   v68,
                   v69,
                   v70,
                   v71,
                   v72,
                   v73,
                   v65,
                   (unsigned __int16 *)v42);
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Failed to prepare message",
               v55,
               v56,
               v57,
               v58,
               v59,
               v60,
               v61,
               v62,
               "lim_send_sme_disassoc_ntf");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
