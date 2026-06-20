__int64 __fastcall extract_pasn_peer_create_req_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned __int8 *a11)
{
  unsigned int v11; // w8
  const char *v13; // x2
  unsigned int v15; // w4
  __int64 result; // x0
  __int64 v17; // x24
  __int64 v18; // x25
  __int64 v19; // x21
  unsigned __int8 v20; // w26
  __int64 v21; // x7
  __int64 v22; // x5
  __int64 v23; // x6
  int v24; // w10
  int v25; // w11
  int v26; // w12
  int v27; // w13
  int v28; // w14
  unsigned __int8 *v29; // x28
  size_t v30; // x2
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x8
  unsigned int v40; // w10
  size_t v41; // x2
  int v42; // w8
  int v43; // w9
  unsigned __int8 *v44; // x10
  int v45; // w8
  int v46; // w9
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x21
  __int64 v56; // [xsp+0h] [xbp-50h]
  __int64 v57; // [xsp+8h] [xbp-48h]
  __int64 v58; // [xsp+10h] [xbp-40h]
  __int64 v59; // [xsp+18h] [xbp-38h]
  __int64 v60; // [xsp+20h] [xbp-30h]
  __int64 v61; // [xsp+28h] [xbp-28h]
  __int64 v62; // [xsp+30h] [xbp-20h]
  __int64 v63; // [xsp+38h] [xbp-18h]
  __int64 v64; // [xsp+40h] [xbp-10h]
  __int64 v65; // [xsp+48h] [xbp-8h]

  if ( !a10 )
  {
    v13 = "%s: Invalid peer_create req buffer";
    goto LABEL_9;
  }
  v11 = *(_DWORD *)(a10 + 24);
  if ( v11 >= 0xD )
  {
    v13 = "%s: Invalid TLV size";
LABEL_9:
    qdf_trace_msg(0x31u, 2u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "extract_pasn_peer_create_req_event_tlv");
    return 4;
  }
  if ( !v11 )
  {
    v13 = "%s: Invalid num TLV:%d";
    goto LABEL_9;
  }
  v15 = (unsigned __int8)*(_DWORD *)(*(_QWORD *)a10 + 4LL);
  *a11 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
  if ( v15 >= 6 )
  {
    v13 = "%s: Invalid vdev id:%d";
    goto LABEL_9;
  }
  v17 = *(_QWORD *)(a10 + 16);
  if ( !v17 )
  {
    v13 = "%s: NULL peer param TLV";
    goto LABEL_9;
  }
  if ( !*(_DWORD *)(a10 + 24) )
    return 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  while ( 1 )
  {
    if ( v19 == 16 )
    {
      __break(0x5512u);
      JUMPOUT(0x239C44);
    }
    v29 = &a11[v18];
    *((_WORD *)v29 + 8) = *(_DWORD *)(v17 + 4);
    v29[18] = *(_WORD *)(v17 + 6);
    v29[19] = *(_BYTE *)(v17 + 7);
    *((_WORD *)v29 + 10) = *(_DWORD *)(v17 + 8);
    *(_WORD *)&a11[v18 + 4] = *(_DWORD *)(v17 + 12);
    v29[6] = *(_WORD *)(v17 + 14);
    v29[7] = *(_BYTE *)(v17 + 15);
    *((_WORD *)v29 + 4) = *(_DWORD *)(v17 + 16);
    *((_DWORD *)v29 + 94) = cm_wmi_auth_type_to_crypto_key_mgmt(*(unsigned int *)(v17 + 24));
    *((_DWORD *)v29 + 95) = *(_DWORD *)(v17 + 28);
    v30 = *(unsigned int *)(v17 + 48);
    if ( (unsigned int)(v30 - 1) <= 0x3F )
    {
      qdf_mem_copy(v29 + 28, (const void *)(v17 + 52), v30);
      *((_DWORD *)v29 + 6) = *(_DWORD *)(v17 + 48);
    }
    qdf_mem_copy(v29 + 96, (const void *)(v17 + 32), 0x10u);
    *((_DWORD *)v29 + 23) = 16;
    if ( *(_DWORD *)(v17 + 116) )
      break;
LABEL_26:
    v43 = *(_DWORD *)(v17 + 20);
    v44 = &a11[v18];
    v45 = v43 & 3;
    *(_DWORD *)&a11[v18 + 12] = v45 != 0;
    if ( (v43 & 2) != 0 )
      v44[23] = 1;
    v46 = (*(unsigned __int8 *)(v17 + 20) >> 2) & 1;
    v44[22] = (*(_BYTE *)(v17 + 20) & 4) != 0;
    if ( &a11[v18] == (unsigned __int8 *)-16LL )
    {
      v21 = 0;
      v22 = 0;
      v23 = 0;
      v24 = 0;
      if ( &a11[v18] == (unsigned __int8 *)-4LL )
        goto LABEL_30;
    }
    else
    {
      v22 = a11[v18 + 16];
      v23 = v29[17];
      v21 = v29[18];
      v24 = v29[21];
      if ( &a11[v18] == (unsigned __int8 *)-4LL )
      {
LABEL_30:
        v27 = 0;
        v25 = 0;
        v26 = 0;
        v28 = 0;
        goto LABEL_17;
      }
    }
    v25 = a11[v18 + 4];
    v26 = v29[5];
    v27 = v29[6];
    v28 = v29[9];
LABEL_17:
    LODWORD(v65) = *(_DWORD *)(v17 + 48);
    LODWORD(v64) = *((_DWORD *)v29 + 95);
    LODWORD(v63) = *((_DWORD *)v29 + 94);
    LODWORD(v62) = v46;
    LODWORD(v61) = v45;
    LODWORD(v60) = v28;
    LODWORD(v59) = v27;
    LODWORD(v58) = v26;
    LODWORD(v57) = v25;
    LODWORD(v56) = v24;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Peer[%d]: self_mac :%02x:%02x:%02x:**:**:%02x peer_mac :%02x:%02x:%02x:**:**:%02xsecurity_mode :0x%x force_sel"
      "f_mac:%d akm :0x%x cipher :0x%x passphrase_len:0x%x",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "extract_pasn_peer_create_req_event_tlv",
      (unsigned int)v19++,
      v22,
      v23,
      v21,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65);
    result = 0;
    v17 += 120;
    v18 += 380;
    ++a11[1];
    if ( *(_DWORD *)(a10 + 24) <= (unsigned int)v19 )
      return result;
  }
  v39 = *(_QWORD *)(a10 + 32);
  if ( v39 )
  {
    v40 = *(_DWORD *)(a10 + 40);
    if ( v40 )
    {
      v41 = (unsigned __int8)*(_DWORD *)(v17 + 116);
      if ( (unsigned int)v41 + v20 <= v40 )
      {
        qdf_mem_copy(&a11[v18 + 116], (const void *)(v39 + v20), v41);
        v42 = *(_DWORD *)(v17 + 116);
        v20 += v42;
        *(_DWORD *)&a11[v18 + 112] = v42;
        goto LABEL_26;
      }
    }
  }
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Invalid peer_create req buffer",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "extract_pasn_peer_cookie");
  v55 = jiffies;
  if ( extract_pasn_peer_create_req_event_tlv___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Error in extracting pasn pmkid TLV for vdev_id:%d",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "extract_pasn_peer_create_req_event_tlv",
      *a11);
    extract_pasn_peer_create_req_event_tlv___last_ticks = v55;
  }
  return 4;
}
