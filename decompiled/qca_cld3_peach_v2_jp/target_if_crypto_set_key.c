__int64 __fastcall target_if_crypto_set_key(__int64 a1, unsigned __int8 *a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x25
  __int64 v15; // x24
  __int64 **v16; // x23
  int v17; // w9
  __int64 *v18; // x8
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w27
  const char *v37; // x2
  __int64 result; // x0
  __int64 v39; // x8
  __int64 (__fastcall *v40)(__int64 **, __int64, unsigned __int8 *); // x8
  __int64 v41; // x1
  char v42; // w25
  __int64 peer_by_mac; // x0
  bool v44; // zf
  char v45; // w8
  char v46; // w25
  unsigned __int8 v47; // w0
  unsigned int v48; // w8
  unsigned int v49; // w0
  int v50; // w8
  unsigned int v51; // w24
  const void *v52; // x25
  const void *v53; // x1
  unsigned __int8 default_key_idx; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 *v63; // x8
  __int64 v64; // x1
  _DWORD *v65; // x8
  __int64 v66; // x8
  _DWORD *v67; // x8
  __int64 v68; // x1
  __int64 v69; // x8
  void (__fastcall *v70)(__int64 **, __int64, unsigned __int8 *, bool, unsigned __int8 *); // x8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int v79; // w19
  __int64 v80; // [xsp+8h] [xbp-98h]
  __int64 v81; // [xsp+10h] [xbp-90h] BYREF
  __int64 v82; // [xsp+18h] [xbp-88h]
  __int64 v83; // [xsp+20h] [xbp-80h] BYREF
  __int64 v84; // [xsp+28h] [xbp-78h] BYREF
  __int64 v85; // [xsp+30h] [xbp-70h]
  __int128 v86; // [xsp+38h] [xbp-68h]
  __int64 v87; // [xsp+48h] [xbp-58h]
  __int64 v88; // [xsp+50h] [xbp-50h] BYREF
  _QWORD v89[2]; // [xsp+58h] [xbp-48h] BYREF
  _QWORD v90[2]; // [xsp+68h] [xbp-38h] BYREF
  _QWORD v91[5]; // [xsp+78h] [xbp-28h] BYREF

  v91[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v91, 0, 32);
  v90[0] = 0;
  v90[1] = 0;
  v89[0] = 0;
  v89[1] = 0;
  v87 = 0;
  v88 = 0;
  v86 = 0u;
  v84 = 0;
  v85 = 0;
  v83 = 0;
  _cds_get_context(71, "target_if_crypto_set_key");
  v14 = *(_QWORD *)(a1 + 152);
  v81 = 0;
  v82 = 0;
  if ( !v14 )
  {
    v37 = "%s: Invalid PDEV";
    goto LABEL_12;
  }
  v15 = *(_QWORD *)(v14 + 80);
  if ( !v15 )
  {
    v37 = "%s: Invalid PSOC";
    goto LABEL_12;
  }
  v16 = *(__int64 ***)(v15 + 2808);
  if ( !v16 )
  {
    v37 = "%s: Invalid DP Handle";
    goto LABEL_12;
  }
  v17 = *((unsigned __int16 *)a2 + 2);
  LOBYTE(v83) = *(_BYTE *)(a1 + 104);
  HIDWORD(v83) = v17;
  qdf_mem_copy((char *)&v84 + 4, a2 + 16, 6u);
  v18 = *(__int64 **)(v14 + 1232);
  if ( !v18 || (v19 = *v18) == 0 )
  {
    v37 = "%s: Invalid PDEV WMI handle";
    goto LABEL_12;
  }
  HIDWORD(v85) = *((unsigned __int16 *)a2 + 1) | (a3 != 0);
  qdf_mem_copy(&v88, a2 + 104, 8u);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: key_type %d, mac: %02x:%02x:%02x:**:**:%02x",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "target_if_crypto_set_key",
    a3,
    a2[16],
    a2[17],
    a2[18],
    a2[21],
    v80,
    v81,
    v82);
  if ( *(_DWORD *)(a1 + 16) == 16 )
  {
    v36 = 0;
    goto LABEL_30;
  }
  if ( *v16 && (v39 = (*v16)[9]) != 0 )
  {
    v40 = *(__int64 (__fastcall **)(__int64 **, __int64, unsigned __int8 *))(v39 + 16);
    if ( v40 )
    {
      v41 = *(unsigned __int8 *)(v14 + 40);
      if ( *((_DWORD *)v40 - 1) != 454466150 )
        __break(0x8228u);
      v42 = v40(v16, v41, a2 + 16);
      goto LABEL_22;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v28, v29, v30, v31, v32, v33, v34, v35, "cdp_find_peer_exist");
  }
  v42 = 0;
LABEL_22:
  peer_by_mac = wlan_objmgr_get_peer_by_mac(v15, a2 + 16, 19);
  if ( peer_by_mac )
  {
    v36 = *(_DWORD *)(peer_by_mac + 68);
    if ( a3 )
      v44 = 0;
    else
      v44 = v36 == 12;
    v45 = v44;
    v46 = v45 | v42;
    wlan_objmgr_peer_release_ref();
    if ( (a3 != 0) | v46 & 1 )
    {
LABEL_30:
      v47 = wlan_crypto_cipher_to_wmi_cipher(*((unsigned int *)a2 + 2));
      v48 = *((_DWORD *)a2 + 2);
      LODWORD(v86) = v47;
      v49 = wlan_crypto_cipher_to_cdp_sec_type(v48);
      v50 = *((_DWORD *)a2 + 2);
      v51 = v49;
      if ( v50 == 13 || v50 == 4 )
      {
        if ( (*(_DWORD *)(a1 + 16) | 2) == 3 )
        {
          v52 = &wlan_crypto_set_wapi_key_rx_iv;
          v53 = &wlan_crypto_set_wapi_key_tx_iv;
        }
        else
        {
          v52 = &wlan_crypto_set_wapi_key_tx_iv;
          v53 = &wlan_crypto_set_wapi_key_rx_iv;
        }
        qdf_mem_copy(v89, v53, 0x10u);
        qdf_mem_copy(v90, v52, 0x10u);
        v50 = *((_DWORD *)a2 + 2);
        *(_QWORD *)((char *)&v86 + 4) = 0x800000008LL;
      }
      if ( (unsigned int)(v50 - 15) >= 2 )
      {
        if ( v50 == 1 )
        {
          *(_QWORD *)((char *)&v86 + 4) = 0x800000008LL;
          goto LABEL_47;
        }
        if ( v50 )
          goto LABEL_47;
      }
      default_key_idx = wlan_crypto_get_default_key_idx(a1, 0);
      if ( !a3 && HIDWORD(v83) == default_key_idx || *(_DWORD *)(a1 + 16) == 1 && HIDWORD(v83) == default_key_idx )
        HIDWORD(v85) |= 2u;
LABEL_47:
      qdf_mem_copy(v91, a2 + 384, *a2);
      WORD1(v83) = *a2;
      qdf_mem_copy(&v81, &v88, 8u);
      if ( v36 != 12 )
      {
        v63 = *v16;
        if ( *v16 )
        {
          v64 = *(unsigned __int8 *)(a1 + 104);
          if ( !*v63 )
          {
LABEL_64:
            v69 = v63[1];
            if ( v69 )
            {
              v70 = *(void (__fastcall **)(__int64 **, __int64, unsigned __int8 *, bool, unsigned __int8 *))(v69 + 144);
              if ( v70 )
              {
                if ( *((_DWORD *)v70 - 1) != 784867940 )
                  __break(0x8228u);
                v70(v16, v64, a2 + 16, a3 == 0, a2 + 408);
              }
            }
            goto LABEL_70;
          }
          v65 = *(_DWORD **)(*v63 + 568);
          if ( v65 )
          {
            if ( *(v65 - 1) != -191045067 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64 **, __int64, unsigned __int8 *, _QWORD, __int64 *))v65)(
              v16,
              v64,
              a2 + 16,
              v51,
              &v81);
          }
        }
        else
        {
          qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v55, v56, v57, v58, v59, v60, v61, v62, "cdp_set_pn_check");
        }
        if ( *v16 )
        {
          v66 = **v16;
          if ( v66 )
          {
            v67 = *(_DWORD **)(v66 + 576);
            if ( v67 )
            {
              v68 = *(unsigned __int8 *)(a1 + 104);
              if ( *(v67 - 1) != -1727651379 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64 **, __int64, unsigned __int8 *, _QWORD, bool))v67)(
                v16,
                v68,
                a2 + 16,
                v51,
                a3 == 0);
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance:",
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            "cdp_set_key_sec_type");
        }
        v63 = *v16;
        if ( *v16 )
        {
          v64 = *(unsigned __int8 *)(a1 + 104);
          goto LABEL_64;
        }
        qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v55, v56, v57, v58, v59, v60, v61, v62, "cdp_set_key");
      }
LABEL_70:
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: vdev_id:%d, key: idx:%d,len:%d",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "target_if_crypto_set_key",
        (unsigned __int8)v83,
        HIDWORD(v83),
        WORD1(v83));
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: peer mac %02x:%02x:%02x:**:**:%02x",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "target_if_crypto_set_key",
        BYTE4(v84),
        BYTE5(v84),
        BYTE6(v84),
        BYTE1(v85));
      ((void (__fastcall *)(__int64, __int64, __int64 *, __int64))qdf_trace_hex_dump)(28, 8, &v88, 8);
      v79 = wmi_unified_setup_install_key_cmd(v19, &v83);
      qdf_mem_set(&v83, 0x78u, 0);
      result = v79;
      goto LABEL_13;
    }
  }
  else
  {
    v36 = 0;
    if ( (a3 != 0) | v42 & 1 )
      goto LABEL_30;
  }
  v37 = "%s: Invalid peer";
LABEL_12:
  qdf_trace_msg(0x49u, 2u, v37, v6, v7, v8, v9, v10, v11, v12, v13, "target_if_crypto_set_key");
  result = 16;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
