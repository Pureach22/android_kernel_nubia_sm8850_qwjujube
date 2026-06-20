__int64 __fastcall osif_p2p_send_usd_params(__int64 a1, unsigned __int8 a2, __int64 a3, __int64 a4)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  __int64 result; // x0
  void *v15; // x0
  __int64 v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w22
  int v26; // w4
  size_t v27; // x0
  void *v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  const char *v38; // x2
  unsigned int v39; // w1
  size_t v40; // x0
  void *v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  _WORD *v62; // x8
  unsigned __int16 v63; // w8
  void *v64; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  size_t v73; // x0
  void *v74; // x0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // [xsp+8h] [xbp-78h] BYREF
  __int64 v84; // [xsp+10h] [xbp-70h]
  _WORD *v85; // [xsp+18h] [xbp-68h]
  __int64 v86; // [xsp+20h] [xbp-60h] BYREF
  __int64 v87; // [xsp+28h] [xbp-58h]
  __int64 v88; // [xsp+30h] [xbp-50h]
  __int64 v89; // [xsp+38h] [xbp-48h]
  _BYTE *v90; // [xsp+40h] [xbp-40h]
  __int64 v91; // [xsp+48h] [xbp-38h]
  _WORD *v92; // [xsp+50h] [xbp-30h]
  __int64 v93; // [xsp+58h] [xbp-28h]
  _WORD *v94; // [xsp+60h] [xbp-20h]
  __int64 v95; // [xsp+68h] [xbp-18h]
  __int64 v96; // [xsp+70h] [xbp-10h]
  __int64 v97; // [xsp+78h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v95 = 0;
  v96 = 0;
  v93 = 0;
  v94 = nullptr;
  v91 = 0;
  v92 = nullptr;
  v89 = 0;
  v90 = nullptr;
  v87 = 0;
  v88 = 0;
  v85 = nullptr;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  if ( (unsigned int)_nla_parse(&v86, 10, a3, a4, &p2p_usd_attr_policy, 31, 0) )
  {
    v13 = "%s: Invalid USD vendor command attributes";
LABEL_3:
    qdf_trace_msg(0x48u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12, "osif_p2p_send_usd_params");
    result = 4294967274LL;
    goto LABEL_4;
  }
  if ( !v88 )
  {
    v13 = "%s: P2P USD OP type parse failed";
    goto LABEL_3;
  }
  v15 = (void *)_qdf_mem_malloc(0x60u, "osif_p2p_send_usd_params", 738);
  if ( !v15 )
  {
    result = 4294967284LL;
    goto LABEL_4;
  }
  v16 = (__int64)v15;
  qdf_mem_set(v15, 0x60u, 0);
  v25 = *(unsigned __int8 *)(v88 + 4);
  if ( v25 > 2 )
  {
    switch ( v25 )
    {
      case 3u:
        v26 = 3;
        break;
      case 4u:
        v26 = 4;
        break;
      case 5u:
        v26 = 5;
        break;
      default:
        goto LABEL_20;
    }
LABEL_23:
    *(_DWORD *)(v16 + 4) = v26;
    if ( !v89 )
    {
      v38 = "%s: P2P instance ID parse failed";
      goto LABEL_33;
    }
    *(_BYTE *)(v16 + 14) = *(_BYTE *)(v89 + 4);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: op type %d instance id %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "osif_p2p_send_usd_params");
    if ( v92 )
    {
      v27 = (unsigned __int16)(*v92 - 4);
      *(_DWORD *)(v16 + 40) = (unsigned __int16)(*v92 - 4);
      v28 = (void *)_qdf_mem_malloc(v27, "osif_p2p_send_usd_params", 768);
      *(_QWORD *)(v16 + 32) = v28;
      if ( !v28 )
        goto LABEL_43;
      qdf_mem_copy(v28, v92 + 2, *(unsigned int *)(v16 + 40));
      qdf_trace_msg(0x48u, 8u, "%s: SSI dump:", v29, v30, v31, v32, v33, v34, v35, v36, "osif_p2p_send_usd_params");
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
        51,
        8,
        *(_QWORD *)(v16 + 32),
        *(unsigned int *)(v16 + 40));
    }
    if ( v25 - 3 < 0xFFFFFFFE )
    {
      v25 = 0;
      goto LABEL_29;
    }
    if ( !v87 )
    {
      v38 = "%s: P2P MAC address parse failed";
      goto LABEL_33;
    }
    qdf_mem_copy((void *)(v16 + 8), (const void *)(v87 + 4), 6u);
    if ( !v90 )
    {
      v38 = "%s: P2P service ID parse failed";
      goto LABEL_33;
    }
    v40 = (unsigned __int8)(*v90 - 4);
    *(_BYTE *)(v16 + 28) = *v90 - 4;
    v41 = (void *)_qdf_mem_malloc(v40, "osif_p2p_send_usd_params", 807);
    *(_QWORD *)(v16 + 16) = v41;
    if ( v41 )
    {
      qdf_mem_copy(v41, v90 + 4, *(unsigned __int8 *)(v16 + 28));
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: service id dump:",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "osif_p2p_send_usd_params");
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
        51,
        8,
        *(_QWORD *)(v16 + 16),
        *(unsigned __int8 *)(v16 + 28));
      if ( v91 )
      {
        v25 = osif_p2p_service_protocol_type_convert_qca_enum_to_p2p_enum(*(unsigned __int8 *)(v91 + 4), v16 + 24);
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: service protocol type %d",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "osif_p2p_send_usd_params",
          *(unsigned int *)(v16 + 24));
        if ( !v93 )
        {
          v37 = "%s: freq config parse failed";
          goto LABEL_31;
        }
        if ( (unsigned int)wlan_cfg80211_nla_parse_nested_0(&v83) )
        {
          v37 = "%s: Failed to parse channel config";
          goto LABEL_31;
        }
        if ( !v84 )
        {
          v37 = "%s: P2P freq config default freq parse fail";
          goto LABEL_31;
        }
        v62 = v85;
        *(_DWORD *)(v16 + 48) = *(_DWORD *)(v84 + 4);
        if ( v62 )
        {
          v63 = *v62 - 4;
          *(_DWORD *)(v16 + 64) = v63;
          v64 = (void *)_qdf_mem_malloc(v63, "osif_p2p_send_usd_params", 863);
          *(_QWORD *)(v16 + 56) = v64;
          if ( !v64 )
            goto LABEL_44;
          qdf_mem_copy(v64, v85 + 2, *(unsigned int *)(v16 + 64));
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: freq list dump:",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "osif_p2p_send_usd_params");
          ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
            51,
            8,
            *(_QWORD *)(v16 + 56),
            *(unsigned int *)(v16 + 64));
        }
        if ( !v94 )
        {
          v37 = "%s: fail to fetch P2P USD frame";
          goto LABEL_31;
        }
        v73 = (unsigned __int16)(*v94 - 4);
        *(_DWORD *)(v16 + 80) = (unsigned __int16)(*v94 - 4);
        v74 = (void *)_qdf_mem_malloc(v73, "osif_p2p_send_usd_params", 885);
        *(_QWORD *)(v16 + 72) = v74;
        if ( !v74 )
          goto LABEL_44;
        qdf_mem_copy(v74, v94 + 2, *(unsigned int *)(v16 + 80));
        qdf_trace_msg(0x48u, 8u, "%s: Frame dump:", v75, v76, v77, v78, v79, v80, v81, v82, "osif_p2p_send_usd_params");
        ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
          51,
          8,
          *(_QWORD *)(v16 + 72),
          *(unsigned int *)(v16 + 80));
        if ( !v95 )
        {
          v37 = "%s: fail to fetch P2P TTL";
          goto LABEL_31;
        }
        *(_WORD *)(v16 + 88) = *(_WORD *)(v95 + 4);
        goto LABEL_29;
      }
      v38 = "%s: P2P service protocol type parse failed";
LABEL_33:
      v39 = 2;
LABEL_42:
      qdf_trace_msg(0x48u, v39, v38, v17, v18, v19, v20, v21, v22, v23, v24, "osif_p2p_send_usd_params");
    }
LABEL_43:
    v25 = 0;
    goto LABEL_44;
  }
  if ( !*(_BYTE *)(v88 + 4) )
  {
    *(_DWORD *)(v16 + 4) = 0;
LABEL_29:
    *(_DWORD *)v16 = a2;
    if ( (unsigned int)ucfg_p2p_send_usd_params() )
    {
      v37 = "%s: fail to send P2P USD params";
LABEL_31:
      qdf_trace_msg(0x48u, 2u, v37, v17, v18, v19, v20, v21, v22, v23, v24, "osif_p2p_send_usd_params");
      goto LABEL_44;
    }
    v38 = "%s: P2P USD request success";
    v39 = 8;
    goto LABEL_42;
  }
  if ( v25 == 1 )
  {
    v26 = 1;
    goto LABEL_23;
  }
  if ( v25 == 2 )
  {
    v26 = 2;
    goto LABEL_23;
  }
LABEL_20:
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: invalid OP type %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "osif_p2p_op_type_convert_qca_enum_to_p2p_enum",
    *(unsigned __int8 *)(v88 + 4));
  v25 = -22;
LABEL_44:
  v58 = *(_QWORD *)(v16 + 32);
  if ( v58 )
    _qdf_mem_free(v58);
  v59 = *(_QWORD *)(v16 + 16);
  if ( v59 )
    _qdf_mem_free(v59);
  v60 = *(_QWORD *)(v16 + 56);
  if ( v60 )
    _qdf_mem_free(v60);
  v61 = *(_QWORD *)(v16 + 72);
  if ( v61 )
    _qdf_mem_free(v61);
  _qdf_mem_free(v16);
  result = v25;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
