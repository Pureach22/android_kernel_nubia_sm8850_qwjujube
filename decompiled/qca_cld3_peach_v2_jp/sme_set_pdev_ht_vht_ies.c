__int64 __fastcall sme_set_pdev_ht_vht_ies(__int64 result, char a2)
{
  unsigned int v2; // w8
  bool v3; // cc
  int v4; // w8
  bool v5; // zf
  __int64 v6; // x19
  __int64 v8; // x0
  _DWORD *v9; // x20
  int v10; // w8
  unsigned __int8 v11; // w0
  __int64 v12; // x4
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  v2 = *(_DWORD *)(result + 17132);
  v3 = v2 > 9;
  v4 = (1 << v2) & 0x3B0;
  v5 = v3 || v4 == 0;
  if ( !v5 )
  {
    v6 = result;
    result = qdf_mutex_acquire(result + 12776);
    if ( !(_DWORD)result )
    {
      v8 = _qdf_mem_malloc(0x10u, "sme_set_pdev_ht_vht_ies", 13326);
      if ( v8 )
      {
        v5 = (a2 & 1) == 0;
        v9 = (_DWORD *)v8;
        if ( v5 )
          v10 = 1;
        else
          v10 = 2;
        *(_DWORD *)(v8 + 4) = 0;
        *(_DWORD *)(v8 + 8) = v10;
        v11 = csr_translate_to_wni_cfg_dot11_mode(v6, *(unsigned int *)(v6 + 17132));
        v12 = (unsigned int)v9[2];
        v9[3] = v11;
        *v9 = 1053823;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: SET_HT_VHT_IE with nss: %d, dot11mode: %d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "sme_set_pdev_ht_vht_ies",
          v12);
        if ( (unsigned int)umac_send_mb_message_to_mac(v9) )
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Send SME_PDEV_SET_HT_VHT_IE fail",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "sme_set_pdev_ht_vht_ies");
      }
      return qdf_mutex_release(v6 + 12776);
    }
  }
  return result;
}
