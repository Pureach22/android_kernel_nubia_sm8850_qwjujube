__int64 __fastcall csr_is_deauth_disassoc_cmd_active(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v10; // x0
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x26
  unsigned int v21; // w26
  __int64 active_cmd; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v50; // w9
  int v51; // w10
  int v52; // w11
  int v53; // w12
  int v54; // w13
  int v55; // w14
  int v56; // w15
  int v57; // w16
  __int16 v58; // w9
  int v59; // w10
  __int16 v60; // w8
  __int128 v62; // [xsp+50h] [xbp-30h] BYREF
  __int16 v63; // [xsp+60h] [xbp-20h]
  int v64; // [xsp+68h] [xbp-18h]
  unsigned __int16 v65; // [xsp+6Ch] [xbp-14h]
  __int64 v66; // [xsp+78h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64 = a3;
  v65 = WORD2(a3);
  v63 = 0;
  v62 = 0u;
  qdf_mem_set(&v62, 0x12u, 0);
  v10 = *(_QWORD *)(a1 + 21624);
  LODWORD(v62) = v64;
  WORD2(v62) = v65;
  wlan_find_peer_and_get_mac_and_mld_addr(v10, (unsigned __int8 *)&v62);
  v11 = csr_nonscan_pending_ll_peek_head(a1, 0);
  if ( v11 )
  {
    v20 = v11;
    while ( *(_DWORD *)(v20 + 24) != (unsigned __int8)a2
         || (csr_peer_mac_match_cmd(v20, 0, (char *)&v62 + 6, (char *)&v62 + 12) & 1) == 0 )
    {
      v20 = csr_nonscan_pending_ll_next(a1, v20, 0);
      if ( !v20 )
        goto LABEL_7;
    }
    v21 = 1;
  }
  else
  {
LABEL_7:
    active_cmd = wlan_serialization_get_active_cmd(
                   *(_QWORD *)(a1 + 21624),
                   a2,
                   3u,
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19);
    if ( !active_cmd || (v21 = 1, (csr_peer_mac_match_cmd(active_cmd, 1, (char *)&v62 + 6, (char *)&v62 + 12) & 1) == 0) )
    {
      v31 = wlan_serialization_get_active_cmd(*(_QWORD *)(a1 + 21624), a2, 2u, v23, v24, v25, v26, v27, v28, v29, v30);
      if ( !v31 || (v21 = 1, (csr_peer_mac_match_cmd(v31, 1, (char *)&v62 + 6, (char *)&v62 + 12) & 1) == 0) )
      {
        v40 = wlan_serialization_get_active_cmd(*(_QWORD *)(a1 + 21624), a2, 5u, v32, v33, v34, v35, v36, v37, v38, v39);
        if ( !v40 || (v21 = 1, (csr_peer_mac_match_cmd(v40, 1, (char *)&v62 + 6, (char *)&v62 + 12) & 1) == 0) )
        {
          v21 = 0;
          if ( a4 )
          {
            if ( a5 )
            {
              if ( *(_DWORD *)((char *)&v62 + 6) | WORD5(v62) )
              {
                if ( v64 != *(_DWORD *)((char *)&v62 + 6) || v65 != WORD5(v62) )
                {
                  v50 = BYTE6(v62);
                  v51 = BYTE7(v62);
                  v52 = BYTE8(v62);
                  v53 = BYTE11(v62);
                  v54 = BYTE12(v62);
                  v55 = BYTE13(v62);
                  v56 = BYTE14(v62);
                  v57 = HIBYTE(v63);
                  if ( &v62 == (__int128 *)-6LL )
                  {
                    v50 = 0;
                    v51 = 0;
                    v52 = 0;
                    v53 = 0;
                  }
                  if ( &v62 == (__int128 *)-12LL )
                  {
                    v54 = 0;
                    v55 = 0;
                    v56 = 0;
                    v57 = 0;
                  }
                  qdf_trace_msg(
                    0x34u,
                    4u,
                    "%s: Vdev %d, given mac %02x:%02x:%02x:**:**:%02x found: peer mac %02x:%02x:%02x:**:**:%02x mld %02x:"
                    "%02x:%02x:**:**:%02x",
                    v41,
                    v42,
                    v43,
                    v44,
                    v45,
                    v46,
                    v47,
                    v48,
                    "csr_is_deauth_disassoc_cmd_active",
                    (unsigned __int8)a2,
                    (unsigned __int8)a3,
                    BYTE1(a3),
                    BYTE2(a3),
                    BYTE5(a3),
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    v55,
                    v56,
                    v57);
                }
              }
              v58 = WORD5(v62);
              v21 = 0;
              v59 = HIDWORD(v62);
              *(_DWORD *)a4 = *(_DWORD *)((char *)&v62 + 6);
              v60 = v63;
              *(_WORD *)(a4 + 4) = v58;
              *(_DWORD *)a5 = v59;
              *(_WORD *)(a5 + 4) = v60;
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v21;
}
