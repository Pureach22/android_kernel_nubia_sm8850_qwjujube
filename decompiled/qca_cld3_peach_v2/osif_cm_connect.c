__int64 __fastcall osif_cm_connect(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x1
  __int64 v9; // x25
  int v10; // w23
  __int64 vdev_by_macaddr_from_pdev; // x0
  __int64 v12; // x19
  __int64 result; // x0
  __int64 v14; // x26
  int v15; // w5
  __int64 v16; // x13
  unsigned __int8 *v17; // x8
  unsigned __int8 *v18; // x8
  unsigned __int8 *v19; // x8
  __int64 i; // x22
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x22
  __int64 v25; // x1
  int v26; // w0
  __int64 v27; // x1
  size_t v28; // x2
  __int64 v29; // x8
  int v30; // w0
  int v31; // w8
  char v32; // w8
  int v33; // w0
  char v34; // w0
  int v35; // w8
  int v36; // w8
  __int64 v37; // x0
  __int64 v38; // x0
  unsigned int v39; // w23
  int v40; // w8
  int v41; // w9
  char v42; // w9
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  int v47; // [xsp+40h] [xbp-10h] BYREF
  __int16 v48; // [xsp+44h] [xbp-Ch]
  __int64 v49; // [xsp+48h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a3 + 16);
  v9 = *(_QWORD *)(a3 + 24);
  v10 = *(unsigned __int8 *)(a2 + 168);
  v48 = -1;
  v47 = -1;
  if ( v8 || (LODWORD(v8) = v9, v9) )
    qdf_mem_copy((int)&v47, v8, 6u);
  vdev_by_macaddr_from_pdev = wlan_objmgr_get_vdev_by_macaddr_from_pdev(*(_QWORD *)(a2 + 216), &v47, 88);
  if ( vdev_by_macaddr_from_pdev )
  {
    v12 = vdev_by_macaddr_from_pdev;
    qdf_trace_msg(
      72,
      2,
      "%s: vdev %d already exist with same mac address%02x:%02x:%02x:**:**:%02x",
      "osif_cm_connect",
      *(unsigned __int8 *)(vdev_by_macaddr_from_pdev + 168),
      (unsigned __int8)v47,
      BYTE1(v47),
      BYTE2(v47),
      HIBYTE(v48));
    wlan_objmgr_vdev_release_ref(v12, 88);
    result = 4294967274LL;
LABEL_28:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v14 = *(unsigned int *)(a3 + 112);
  if ( *(_QWORD *)a3 )
    v15 = *(_DWORD *)(*(_QWORD *)a3 + 4LL);
  else
    v15 = 0;
  v16 = *(_QWORD *)(a3 + 8);
  if ( v16 )
    LODWORD(v16) = *(_DWORD *)(v16 + 4);
  qdf_trace_msg(
    72,
    8,
    "connect req for %s(vdevid-%d) freq %d SSID %.*s auth type %d WPA ver %d n_akm %d n_cipher %d grp_cipher %x mfp %d freq hint %d",
    (const char *)(a1 + 296),
    v10,
    v15,
    *(_DWORD *)(a3 + 40),
    *(const char **)(a3 + 32),
    *(_DWORD *)(a3 + 48),
    *(_DWORD *)(a3 + 80),
    v14,
    *(_DWORD *)(a3 + 88),
    *(_DWORD *)(a3 + 84),
    *(_DWORD *)(a3 + 76),
    v16);
  v17 = *(unsigned __int8 **)(a3 + 16);
  if ( v17 )
    qdf_trace_msg(72, 8, "BSSID %02x:%02x:%02x:**:**:%02x", *v17, v17[1], v17[2], v17[5]);
  v18 = *(unsigned __int8 **)(a3 + 24);
  if ( v18 )
    qdf_trace_msg(72, 8, "BSSID hint %02x:%02x:%02x:**:**:%02x", *v18, v18[1], v18[2], v18[5]);
  v19 = *(unsigned __int8 **)(a3 + 312);
  if ( v19 )
    qdf_trace_msg(72, 8, "prev BSSID %02x:%02x:%02x:**:**:%02x", *v19, v19[1], v19[2], v19[5]);
  if ( (_DWORD)v14 )
  {
    for ( i = 0; i != v14; ++i )
      qdf_trace_msg(72, 8, "akm[%d] = %x", i, *(_DWORD *)(a3 + 116 + 4 * i));
  }
  if ( !*(_DWORD *)(a3 + 88)
    || (qdf_trace_msg(72, 8, "cipher_pairwise[%d] = %x", 0, *(_DWORD *)(a3 + 92)), *(_DWORD *)(a3 + 88) <= 1u)
    || (qdf_trace_msg(72, 8, "cipher_pairwise[%d] = %x", 1, *(_DWORD *)(a3 + 96)), *(_DWORD *)(a3 + 88) < 3u)
    || (qdf_trace_msg(72, 8, "cipher_pairwise[%d] = %x", 2, *(_DWORD *)(a3 + 100)), *(_DWORD *)(a3 + 88) < 4u)
    || (qdf_trace_msg(72, 8, "cipher_pairwise[%d] = %x", 3, *(_DWORD *)(a3 + 104)), *(_DWORD *)(a3 + 88) < 5u)
    || (v21 = qdf_trace_msg(72, 8, "cipher_pairwise[%d] = %x", 4, *(_DWORD *)(a3 + 108)), *(_DWORD *)(a3 + 88) <= 5u) )
  {
    v22 = osif_cm_reset_id_and_src(a2);
    if ( (_DWORD)v22 )
    {
LABEL_27:
      result = qdf_status_to_os_return(v22);
      goto LABEL_28;
    }
    v23 = _qdf_mem_malloc(992, "osif_cm_connect", 793);
    if ( !v23 )
    {
      result = 4294967284LL;
      goto LABEL_28;
    }
    *(_BYTE *)v23 = v10;
    v24 = v23;
    *(_DWORD *)(v23 + 4) = 0;
    v25 = *(_QWORD *)(a3 + 16);
    if ( v25 )
    {
      v26 = v23 + 8;
    }
    else
    {
      if ( !v9 )
        goto LABEL_36;
      v25 = *(_QWORD *)(a3 + 24);
      v26 = v23 + 53;
    }
    qdf_mem_copy(v26, v25, 6u);
LABEL_36:
    v27 = *(_QWORD *)(a3 + 312);
    if ( v27 )
      qdf_mem_copy(v24 + 14, v27, 6u);
    v28 = (unsigned __int8)*(_QWORD *)(a3 + 40);
    *(_BYTE *)(v24 + 20) = *(_QWORD *)(a3 + 40);
    if ( (unsigned int)v28 >= 0x21 )
    {
      qdf_trace_msg(72, 2, "%s: Invalid ssid len %zu", "osif_cm_connect", *(_QWORD *)(a3 + 40));
      ucfg_cm_free_connect_req(v24);
      result = 4294967274LL;
      goto LABEL_28;
    }
    qdf_mem_copy(v24 + 21, *(_QWORD *)(a3 + 32), v28);
    if ( *(_QWORD *)a3 )
      *(_DWORD *)(v24 + 60) = *(_DWORD *)(*(_QWORD *)a3 + 4LL);
    v29 = *(_QWORD *)(a3 + 8);
    if ( v29 )
      *(_DWORD *)(v24 + 64) = *(_DWORD *)(v29 + 4);
    *(_DWORD *)(v24 + 72) = *(_DWORD *)(a3 + 80);
    v30 = osif_nl_to_crypto_auth_type(*(_DWORD *)(a3 + 48));
    if ( v30 == 4 && (v31 = *(_DWORD *)(a3 + 80)) != 0 )
    {
      if ( (v31 & 1) != 0 )
        v32 = 5;
      else
        v32 = 6;
    }
    else if ( *(_DWORD *)(a3 + 88) )
    {
      v32 = v30;
    }
    else
    {
      v32 = 1;
    }
    *(_DWORD *)(v24 + 76) |= 1 << v32;
    v33 = *(_DWORD *)(a3 + 84);
    if ( v33 )
      v34 = osif_nl_to_crypto_cipher_type(v33);
    else
      v34 = 17;
    *(_DWORD *)(v24 + 80) |= 1 << v34;
    if ( *(_DWORD *)(a3 + 88) )
    {
      *(_DWORD *)(v24 + 84) |= 1 << osif_nl_to_crypto_cipher_type(*(_DWORD *)(a3 + 92));
      if ( *(_DWORD *)(a3 + 88) < 2u
        || (*(_DWORD *)(v24 + 84) |= 1 << osif_nl_to_crypto_cipher_type(*(_DWORD *)(a3 + 96)), *(_DWORD *)(a3 + 88) < 3u)
        || (*(_DWORD *)(v24 + 84) |= 1 << osif_nl_to_crypto_cipher_type(*(_DWORD *)(a3 + 100)), *(_DWORD *)(a3 + 88) < 4u)
        || (*(_DWORD *)(v24 + 84) |= 1 << osif_nl_to_crypto_cipher_type(*(_DWORD *)(a3 + 104)), *(_DWORD *)(a3 + 88) < 5u) )
      {
LABEL_63:
        if ( *(_DWORD *)(a3 + 112) )
        {
          *(_DWORD *)(v24 + 88) |= 1 << osif_nl_to_crypto_akm_type(*(_DWORD *)(a3 + 116));
          if ( *(_DWORD *)(a3 + 112) < 2u
            || (*(_DWORD *)(v24 + 88) |= 1 << osif_nl_to_crypto_akm_type(*(_DWORD *)(a3 + 120)),
                *(_DWORD *)(a3 + 112) < 3u)
            || (*(_DWORD *)(v24 + 88) |= 1 << osif_nl_to_crypto_akm_type(*(_DWORD *)(a3 + 124)),
                *(_DWORD *)(a3 + 112) < 4u)
            || (*(_DWORD *)(v24 + 88) |= 1 << osif_nl_to_crypto_akm_type(*(_DWORD *)(a3 + 128)),
                *(_DWORD *)(a3 + 112) < 5u) )
          {
LABEL_71:
            v37 = *(unsigned __int8 *)(a3 + 208);
            if ( *(_BYTE *)(a3 + 208) )
            {
              *(_BYTE *)(v24 + 112) = v37;
              *(_BYTE *)(v24 + 114) = *(_BYTE *)(a3 + 209);
              v38 = _qdf_mem_malloc(v37, "osif_cm_set_wep_key_params", 83);
              *(_QWORD *)(v24 + 96) = v38;
              if ( !v38 )
              {
                v39 = 2;
                qdf_trace_msg(72, 2, "%s: set wep key params failed", "osif_cm_set_crypto_params");
                v40 = 0;
LABEL_76:
                v41 = *(_DWORD *)(a3 + 76);
                if ( v41 == 1 )
                  v42 = 64;
                else
                  v42 = (v41 == 2) << 7;
                *(_BYTE *)(v24 + 128) = v42;
                *(_DWORD *)(v24 + 144) = *(_DWORD *)(a3 + 92);
                *(_DWORD *)(v24 + 140) = *(_DWORD *)(a3 + 116);
                *(_DWORD *)(v24 + 132) = *(_DWORD *)(a3 + 48);
                *(_DWORD *)(v24 + 136) = *(_DWORD *)(a3 + 84);
                if ( v40 )
                {
                  *(_WORD *)(v24 + 194) = *(_WORD *)(a3 + 220);
                  *(_WORD *)(v24 + 196) = *(_WORD *)(a3 + 246);
                  *(_DWORD *)(v24 + 200) = *(_DWORD *)(a3 + 272);
                  *(_DWORD *)(v24 + 204) = *(_DWORD *)(a3 + 284);
                  v43 = *(_QWORD *)(a3 + 64);
                  if ( !v43 )
                  {
LABEL_83:
                    v39 = osif_cm_set_fils_info(a2);
                    if ( !v39 )
                    {
                      osif_cm_fill_connect_params(v24, a4);
                      v39 = mlo_connect(a2, v24);
                      if ( v39 )
                      {
                        qdf_trace_msg(72, 2, "%s: Connect failed with status %d", "osif_cm_connect", v39);
                        v45 = *(_QWORD *)(a2 + 216);
                        if ( v45 )
                          v46 = *(_QWORD *)(v45 + 80);
                        else
                          v46 = 0;
                        ucfg_cm_handle_legacy_conn_fail(v46, *(unsigned __int8 *)(a2 + 168));
                      }
                    }
                    goto LABEL_90;
                  }
                  *(_DWORD *)(v24 + 152) = v43;
                  v44 = _qdf_mem_malloc(*(_QWORD *)(a3 + 64), "osif_cm_connect", 836);
                  *(_QWORD *)(v24 + 160) = v44;
                  if ( v44 )
                  {
                    qdf_mem_copy(v44, *(_QWORD *)(a3 + 56), *(unsigned int *)(v24 + 152));
                    goto LABEL_83;
                  }
                  *(_DWORD *)(v24 + 152) = 0;
                  v39 = 2;
                }
LABEL_90:
                ucfg_cm_free_connect_req(v24);
                v22 = v39;
                goto LABEL_27;
              }
              qdf_mem_copy(v38, *(_QWORD *)(a3 + 200), *(unsigned __int8 *)(v24 + 112));
            }
            v39 = 0;
            v40 = 1;
            goto LABEL_76;
          }
          v36 = 1 << osif_nl_to_crypto_akm_type(*(_DWORD *)(a3 + 132));
        }
        else
        {
          v36 = 4;
        }
        *(_DWORD *)(v24 + 88) |= v36;
        goto LABEL_71;
      }
      v35 = 1 << osif_nl_to_crypto_cipher_type(*(_DWORD *)(a3 + 108));
    }
    else
    {
      v35 = 0x20000;
    }
    *(_DWORD *)(v24 + 84) |= v35;
    goto LABEL_63;
  }
  __break(0x5512u);
  return osif_cm_set_fils_info(v21);
}
