__int64 __fastcall wma_link_status_event_handler(
        __int64 a1,
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
  __int64 v10; // x20
  __int64 v11; // x25
  __int64 v13; // x26
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w4
  char is_vdev_valid; // w0
  __int64 v25; // x4
  __int64 v26; // x0
  __int64 cmpt_obj; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  unsigned int v37; // w27
  __int64 v38; // x22
  unsigned int v39; // w8
  __int64 v40; // x24
  int v41; // w9
  int v42; // w8
  char v43; // w8
  __int64 result; // x0
  const char *v45; // x2
  __int64 v46; // [xsp+0h] [xbp-50h]
  int v47; // [xsp+14h] [xbp-3Ch]
  __int64 v48; // [xsp+18h] [xbp-38h] BYREF
  __int64 v49; // [xsp+20h] [xbp-30h]
  __int64 v50; // [xsp+28h] [xbp-28h]
  __int64 v51; // [xsp+30h] [xbp-20h]
  __int64 v52; // [xsp+38h] [xbp-18h]
  __int64 v53; // [xsp+40h] [xbp-10h]
  __int64 v54; // [xsp+48h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v45 = "%s: Invalid stats event";
LABEL_31:
    qdf_trace_msg(0x36u, 2u, v45, a3, a4, a5, a6, a7, a8, a9, a10, "wma_link_status_event_handler");
LABEL_34:
    result = 4294967274LL;
    goto LABEL_35;
  }
  v10 = a2[2];
  if ( !v10 )
  {
    v45 = "%s: Invalid ht_info";
    goto LABEL_31;
  }
  v11 = *a2;
  v13 = *(_QWORD *)(a1 + 520);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: num_vdev_stats: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_link_status_event_handler",
    *(unsigned int *)(*a2 + 4));
  v23 = *(_DWORD *)(v11 + 4);
  if ( v23 > 0x3F || v23 > *((_DWORD *)a2 + 6) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: excess vdev_stats buffers:%d, num_ht_info:%d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_link_status_event_handler");
    goto LABEL_34;
  }
  is_vdev_valid = wma_is_vdev_valid(*(_DWORD *)(v10 + 4), v15, v16, v17, v18, v19, v20, v21, v22);
  v25 = *(unsigned int *)(v10 + 4);
  if ( (is_vdev_valid & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid vdevid %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_link_status_event_handler",
      v25);
    goto LABEL_34;
  }
  v26 = *(_QWORD *)(v13 + 488LL * (unsigned int)v25);
  if ( !v26 )
  {
    v45 = "%s: Vdev is NULL";
    goto LABEL_31;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v26, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cmpt_obj )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: ailed to get mlme_obj",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wma_get_vdev_rate_flag");
    v45 = "%s: Failed to get rate flag";
    goto LABEL_31;
  }
  if ( *(_DWORD *)(v11 + 4) )
  {
    v36 = v10 + 24;
    v37 = 1;
    v47 = *(_DWORD *)(cmpt_obj + 288) & 0xE0;
    do
    {
      v38 = v36;
      LODWORD(v46) = *(_DWORD *)(v36 - 4);
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: vdevId:%d  tx_nss:%d rx_nss:%d tx_preamble:%d rx_preamble:%d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "wma_link_status_event_handler",
        *(unsigned int *)(v36 - 20),
        *(unsigned int *)(v36 - 16),
        *(unsigned int *)(v36 - 12),
        *(unsigned int *)(v36 - 8),
        v46);
      v39 = *(_DWORD *)(v38 - 20);
      if ( v39 < *(unsigned __int16 *)(a1 + 162) )
      {
        v40 = *(_QWORD *)(v13 + 488LL * v39 + 248);
        if ( v40 )
        {
          if ( *(_DWORD *)(v38 - 16) || (v41 = *(_DWORD *)(v38 - 12)) != 0 )
            LOBYTE(v41) = 2;
          if ( *(_DWORD *)(v38 - 8) == 3 || *(_DWORD *)(v38 - 4) == 3 )
            LOBYTE(v41) = v41 | 1;
          v42 = *(unsigned __int8 *)(v13 + 488LL * v39 + 236);
          v52 = 0;
          v53 = 0;
          v50 = 0;
          v51 = 0;
          v48 = 0;
          v49 = 0;
          if ( v42 == 2 )
            v43 = v41 | 8;
          else
            v43 = v41;
          LOWORD(v48) = 5219;
          if ( v47 )
            v43 |= 4u;
          *(_BYTE *)(v40 + 4) = v43;
          v49 = v40;
          if ( (unsigned int)scheduler_post_message_debug(
                               0x36u,
                               0x34u,
                               52,
                               (unsigned __int16 *)&v48,
                               0xD31u,
                               (__int64)"wma_post_link_status") )
          {
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Fail to post link status ind msg",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "wma_post_link_status");
            _qdf_mem_free(v40);
          }
          *(_QWORD *)(v13 + 488LL * *(unsigned int *)(v38 - 20) + 248) = 0;
        }
      }
      result = 0;
      if ( v37 >= *(_DWORD *)(v11 + 4) )
        break;
      ++v37;
      v36 = v38 + 24;
    }
    while ( v38 );
  }
  else
  {
    result = 0;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
