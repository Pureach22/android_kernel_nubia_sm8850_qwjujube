__int64 __fastcall lim_send_mgmt_frame_tx(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x25
  __int64 v11; // x26
  unsigned __int16 *v12; // x22
  unsigned int v13; // w19
  size_t v14; // x20
  int v15; // w8
  __int64 v16; // x21
  __int64 session_by_vdev_id; // x0
  __int64 v18; // x23
  int v19; // w8
  __int64 v20; // x0
  __int64 sae_auth_retry; // x0
  __int64 v22; // x24
  __int64 v23; // x0
  bool v24; // w9
  const void *v25; // x1
  __int64 v26; // x22
  _QWORD *v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int8 *v36; // x8
  _QWORD *v37; // x21
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x6
  __int64 v41; // x7
  const char *v42; // x2
  unsigned int v43; // w1
  __int64 result; // x0
  bool v45[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v10 = a1 + 20480;
  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 8);
  v12 = *(unsigned __int16 **)(v11 + 8);
  v13 = *(unsigned __int8 *)(v11 + 4);
  v14 = (unsigned int)*(unsigned __int16 *)(v11 + 2) - 16;
  if ( (*v12 & 0xF0) == 0xB0 )
  {
    v15 = v12[12];
    if ( v15 == 2 )
    {
      v25 = v12 + 2;
      v26 = a1;
      v27 = lim_search_pre_auth_list(a1, v25);
      v36 = *(unsigned __int8 **)(v11 + 8);
      v37 = v27;
      if ( v36 == (unsigned __int8 *)-4LL )
      {
        v40 = 0;
        v38 = 0;
        v39 = 0;
        v41 = 0;
      }
      else
      {
        v38 = v36[4];
        v39 = v36[5];
        v40 = v36[6];
        v41 = v36[9];
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: FT Auth TX to %02x:%02x:%02x:**:**:%02x",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "lim_send_mgmt_frame_tx",
        v38,
        v39,
        v40,
        v41);
      a1 = v26;
      if ( v37 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: STA is AUTHENTICATED_STATE",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "lim_send_mgmt_frame_tx");
        a1 = v26;
        *((_DWORD *)v37 + 5) = 9;
      }
    }
    else if ( v15 == 3 )
    {
      v45[0] = 0;
      v16 = a1;
      session_by_vdev_id = pe_find_session_by_vdev_id(a1, v13);
      if ( !session_by_vdev_id )
      {
        v42 = "%s: session not found for given vdev_id %d";
LABEL_23:
        v43 = 2;
        goto LABEL_24;
      }
      v18 = session_by_vdev_id;
      if ( (*(_DWORD *)(session_by_vdev_id + 7036) | 2) != 2 )
      {
LABEL_25:
        a1 = v16;
        goto LABEL_26;
      }
      v19 = *(_DWORD *)(session_by_vdev_id + 72);
      v20 = *(_QWORD *)(v16 + 21624);
      if ( v19 == 29 )
      {
        wlan_mlme_get_sae_auth_retry_count(v20, v45);
        if ( v45[0] )
        {
LABEL_8:
          sae_auth_retry = mlme_get_sae_auth_retry(*(_QWORD *)(v18 + 16), a3, a4, a5, a6, a7, a8, a9, a10);
          if ( sae_auth_retry )
          {
            v22 = sae_auth_retry;
            if ( *(_QWORD *)(sae_auth_retry + 16) )
              lim_sae_auth_cleanup_retry(v16, v13);
            v23 = _qdf_mem_malloc(v14, "lim_handle_sae_auth_retry", 8900);
            *(_QWORD *)(v22 + 16) = v23;
            if ( v23 )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: SAE auth frame queued vdev_id %d seq_num %d",
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                "lim_handle_sae_auth_retry",
                v13,
                (unsigned int)*(unsigned __int16 *)(v10 + 1124) + 1);
              qdf_mem_copy(*(void **)(v22 + 16), v12, (unsigned int)v14);
              v24 = v45[0];
              *(_BYTE *)(v16 + 2978) = *(_BYTE *)(v18 + 8);
              *(_DWORD *)(v22 + 8) = v14;
              *(_BYTE *)v22 = v24;
              tx_timer_change(v16 + 2928, *(unsigned int *)(*(_QWORD *)(v16 + 8) + 3736LL) / 0xAuLL, 0);
              if ( (unsigned int)tx_timer_activate((char *)(v16 + 2928)) )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: failed to start periodic auth retry timer",
                  a3,
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  a10,
                  "lim_handle_sae_auth_retry");
                lim_sae_auth_cleanup_retry(v16, v13);
              }
            }
            goto LABEL_25;
          }
          v42 = "%s: sae retry pointer is NULL for vdev_id %d";
          goto LABEL_23;
        }
      }
      else
      {
        wlan_mlme_get_sae_roam_auth_retry_count(v20, v45);
        if ( v45[0] )
          goto LABEL_8;
      }
      v42 = "%s: vdev %d: SAE Auth retry disabled";
      v43 = 8;
LABEL_24:
      qdf_trace_msg(0x35u, v43, v42, a3, a4, a5, a6, a7, a8, a9, a10, "lim_handle_sae_auth_retry", v13);
      goto LABEL_25;
    }
  }
LABEL_26:
  *(_DWORD *)(v10 + 1180) = 0;
  result = lim_send_frame(a1, v13, *(unsigned __int8 **)(v11 + 8), v14, a3, a4, a5, a6, a7, a8, a9, a10);
  _ReadStatusReg(SP_EL0);
  return result;
}
