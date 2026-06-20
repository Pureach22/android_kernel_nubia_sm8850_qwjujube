__int64 __fastcall csr_issue_set_context_req_helper(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        char a5,
        unsigned int a6)
{
  unsigned int v10; // w22
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x21
  unsigned int cipher; // w24
  unsigned __int8 default_key_idx; // w27
  __int64 key; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  void *v32; // x0
  const void *v33; // x1
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w26
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7

  v10 = a2;
  v11 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 21624),
          a2,
          7);
  if ( v11 )
  {
    v20 = v11;
    cipher = wlan_crypto_get_cipher(v11, a3, a5 & 1, a6);
    if ( cipher <= 0x10 && ((1 << cipher) & 0x18001) != 0 )
    {
      default_key_idx = wlan_crypto_get_default_key_idx(v20, (a5 & 1) == 0);
      key = wlan_crypto_get_key(v20, a3, default_key_idx);
      if ( key )
      {
        if ( (a5 & 1) != 0 || (*(_DWORD *)(v20 + 16) | 2) == 2 )
        {
          v32 = (void *)(key + 16);
          v33 = (const void *)a3;
        }
        else
        {
          v32 = (void *)(key + 16);
          v33 = (const void *)(v20 + 74);
        }
        qdf_mem_copy(v32, v33, 6u);
        v43 = default_key_idx;
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: vdev or crytpo_key null",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "csr_update_wep_key_peer_macaddr");
        v43 = default_key_idx;
      }
    }
    else
    {
      wlan_crypto_get_key(v20, a3, a6);
      v43 = 0;
    }
    wlan_objmgr_vdev_release_ref(v20, 7u, v34, v35, v36, v37, v38, v39, v40, v41, v42);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: session:%d, cipher:%d, ucast:%d, idx:%d, wep:%d, add:%d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "csr_roam_issue_set_context_req",
      v10,
      cipher,
      a5 & 1,
      (unsigned __int8)a6,
      v43,
      a4 & 1);
    if ( cipher <= 0x10 && ((1 << cipher) & 0x18001) != 0 || (a4 & 1) != 0 )
      return ucfg_crypto_set_key_req(v20, v53, v54, v55, v56, v57, v58, v59, v60);
    else
      return 4;
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: VDEV object not found for session_id %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "csr_roam_issue_set_context_req",
      v10);
    return 4;
  }
}
