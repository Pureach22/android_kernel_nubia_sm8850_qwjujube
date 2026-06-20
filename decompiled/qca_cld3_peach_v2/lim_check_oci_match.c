__int64 __fastcall lim_check_oci_match(__int64 a1, __int64 a2, unsigned __int8 *a3, __int64 a4, unsigned int a5)
{
  unsigned __int8 *ext_ie_ptr_from_ext_id; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w4
  int v20; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned __int16 chanwidth_from_opclass_auto; // w22
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w9
  bool v48; // zf
  unsigned __int16 v49; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v50; // [xsp+28h] [xbp-18h] BYREF
  char v51[4]; // [xsp+30h] [xbp-10h] BYREF
  __int16 v52; // [xsp+34h] [xbp-Ch] BYREF
  char v53; // [xsp+36h] [xbp-Ah]
  __int64 v54; // [xsp+38h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51[0] = 54;
  v50 = 0;
  v49 = 0;
  v53 = 0;
  v52 = 0;
  if ( (lim_is_self_and_peer_ocv_capable(a1, a4, a2) & 1) == 0 )
  {
LABEL_16:
    result = 1;
    goto LABEL_19;
  }
  if ( a5 < 6 )
  {
LABEL_18:
    result = 0;
    goto LABEL_19;
  }
  ext_ie_ptr_from_ext_id = wlan_get_ext_ie_ptr_from_ext_id(v51, 1u, a3, a5);
  if ( !ext_ie_ptr_from_ext_id )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: OCV not found OCI in SA Query frame!",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "lim_check_oci_match");
    goto LABEL_18;
  }
  v19 = ext_ie_ptr_from_ext_id[1];
  if ( v19 <= 3 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: OCI len %d is incorrect",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "lim_check_oci_match");
    goto LABEL_18;
  }
  v20 = dot11f_unpack_ie_oci(a1, ext_ie_ptr_from_ext_id + 3, v19 - 1, &v50, 0);
  result = 0;
  if ( !v20 && (_BYTE)v50 )
  {
    wlan_reg_read_current_country(*(_QWORD *)(a1 + 21624), &v52, v21, v22, v23, v24, v25, v26, v27, v28);
    chanwidth_from_opclass_auto = wlan_reg_dmn_get_chanwidth_from_opclass_auto(
                                    (unsigned __int8 *)&v52,
                                    BYTE2(v50),
                                    BYTE1(v50),
                                    v30,
                                    v31,
                                    v32,
                                    v33,
                                    v34,
                                    v35,
                                    v36,
                                    v37);
    lim_fill_oci_params(a1, a2, (char *)&v50 + 4, a4, &v49);
    v47 = BYTE2(v50);
    v48 = v49 <= (unsigned int)chanwidth_from_opclass_auto || BYTE5(v50) == BYTE1(v50);
    if ( !v48 || BYTE6(v50) != BYTE2(v50) || (v47 = BYTE6(v50), HIBYTE(v50) != BYTE3(v50)) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: OCI mismatch,self %d %d %d %d, peer %d %d %d %d",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "lim_check_oci_match",
        BYTE1(v50),
        v47,
        BYTE3(v50),
        chanwidth_from_opclass_auto);
      goto LABEL_18;
    }
    goto LABEL_16;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
