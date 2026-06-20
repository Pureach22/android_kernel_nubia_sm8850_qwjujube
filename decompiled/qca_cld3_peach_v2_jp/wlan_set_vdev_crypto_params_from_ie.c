__int64 __fastcall wlan_set_vdev_crypto_params_from_ie(__int64 a1, __int64 a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 comp_private_obj; // x0
  __int64 v15; // x19
  unsigned __int8 *rsn_data_from_ie_ptr; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  unsigned int v26; // w1
  const char *v27; // x2
  __int64 result; // x0
  unsigned int v29; // w22
  int v30; // w10
  int v31; // w10
  int v32; // w10
  __int16 v33; // w9
  __int64 vendor_ie_ptr_from_oui; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // w10
  int v52; // w10
  int v53; // w10
  __int16 v54; // w9
  __int64 ie_ptr_from_eid; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  const char *v64; // x2
  unsigned int v65; // w1
  int v66; // w10
  int v67; // w10
  int v68; // w10
  __int16 v69; // w9
  int v70; // [xsp+4h] [xbp-12Ch] BYREF
  _DWORD s[72]; // [xsp+8h] [xbp-128h] BYREF
  __int64 v72; // [xsp+128h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !a1 )
  {
    v27 = "%s: VDEV is NULL";
LABEL_10:
    qdf_trace_msg(0x1Cu, 2u, v27, v6, v7, v8, v9, v10, v11, v12, v13, "wlan_set_vdev_crypto_params_from_ie");
    result = 16;
    goto LABEL_11;
  }
  if ( !a2 )
  {
    v27 = "%s: IE ptr is NULL";
    goto LABEL_10;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !comp_private_obj )
  {
    v27 = "%s: crypto_priv NULL";
    goto LABEL_10;
  }
  v15 = comp_private_obj;
  *(_DWORD *)(comp_private_obj + 20) = 0;
  *(_WORD *)(comp_private_obj + 152) = 0;
  *(_QWORD *)comp_private_obj = 0;
  *(_QWORD *)(comp_private_obj + 8) = 0;
  qdf_mem_set(s, 0x120u, 0);
  rsn_data_from_ie_ptr = (unsigned __int8 *)wlan_get_rsn_data_from_ie_ptr(a2, (unsigned __int16)a3);
  if ( rsn_data_from_ie_ptr )
  {
    if ( !(unsigned int)wlan_crypto_rsnie_check(s, rsn_data_from_ie_ptr, nullptr) )
    {
      v30 = *(_DWORD *)(v15 + 4);
      v29 = 0;
      *(_DWORD *)v15 |= s[0];
      *(_DWORD *)(v15 + 4) = v30 | s[1];
      v31 = *(_DWORD *)(v15 + 12);
      *(_DWORD *)(v15 + 8) |= s[2];
      *(_DWORD *)(v15 + 12) = v31 | s[3];
      v32 = *(_DWORD *)(v15 + 20);
      v33 = *(_WORD *)(v15 + 152);
      *(_DWORD *)(v15 + 16) |= s[4];
      *(_DWORD *)(v15 + 20) = v32 | s[5];
      *(_WORD *)(v15 + 152) = v33 | LOWORD(s[38]);
      goto LABEL_15;
    }
    v25 = "%s: RSN IE check failed";
    v26 = 2;
  }
  else
  {
    v25 = "%s: RSN IE not present";
    v26 = 8;
  }
  qdf_trace_msg(0x1Cu, v26, v25, v17, v18, v19, v20, v21, v22, v23, v24, "wlan_get_crypto_params_from_rsn_ie");
  v29 = 16;
LABEL_15:
  qdf_mem_set(s, 0x120u, 0);
  v70 = 32657408;
  vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&v70, 4, a2, a3);
  if ( vendor_ie_ptr_from_oui )
  {
    if ( (unsigned int)wlan_crypto_wpaie_check((__int64)s, vendor_ie_ptr_from_oui, nullptr) )
    {
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: WPA IE check failed",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "wlan_get_crypto_params_from_wpa_ie");
    }
    else
    {
      v51 = *(_DWORD *)(v15 + 4);
      v29 = 0;
      *(_DWORD *)v15 |= s[0];
      *(_DWORD *)(v15 + 4) = v51 | s[1];
      v52 = *(_DWORD *)(v15 + 12);
      *(_DWORD *)(v15 + 8) |= s[2];
      *(_DWORD *)(v15 + 12) = v52 | s[3];
      v53 = *(_DWORD *)(v15 + 20);
      v54 = *(_WORD *)(v15 + 152);
      *(_DWORD *)(v15 + 16) |= s[4];
      *(_DWORD *)(v15 + 20) = v53 | s[5];
      *(_WORD *)(v15 + 152) = v54 | LOWORD(s[38]);
    }
  }
  else
  {
    qdf_trace_msg(
      0x1Cu,
      8u,
      "%s: WPA IE not present",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "wlan_get_crypto_params_from_wpa_ie");
  }
  qdf_mem_set(s, 0x120u, 0);
  ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(68, a2, (unsigned __int16)a3);
  if ( ie_ptr_from_eid )
  {
    result = wlan_crypto_wapiie_check(s, ie_ptr_from_eid);
    if ( !(_DWORD)result )
    {
      v66 = *(_DWORD *)(v15 + 4);
      *(_DWORD *)v15 |= s[0];
      *(_DWORD *)(v15 + 4) = v66 | s[1];
      v67 = *(_DWORD *)(v15 + 12);
      *(_DWORD *)(v15 + 8) |= s[2];
      *(_DWORD *)(v15 + 12) = v67 | s[3];
      v68 = *(_DWORD *)(v15 + 20);
      v69 = *(_WORD *)(v15 + 152);
      *(_DWORD *)(v15 + 16) |= s[4];
      *(_DWORD *)(v15 + 20) = v68 | s[5];
      *(_WORD *)(v15 + 152) = v69 | LOWORD(s[38]);
      goto LABEL_11;
    }
    v64 = "%s: WAPI IE check failed";
    v65 = 2;
  }
  else
  {
    v64 = "%s: WAPI ie not present";
    v65 = 8;
  }
  qdf_trace_msg(0x1Cu, v65, v64, v56, v57, v58, v59, v60, v61, v62, v63, "wlan_get_crypto_params_from_wapi_ie");
  result = v29;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
