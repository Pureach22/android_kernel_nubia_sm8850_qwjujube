__int64 __fastcall osif_p2p_parse_wfd_params(__int64 a1, __int64 a2, unsigned int a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 result; // x0
  unsigned int v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  __int64 v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  if ( (unsigned int)_nla_parse(&v23, 1, a2, a3, &p2p_wfdr2_attr_policy, 31, 0) )
  {
    v12 = "%s: Invalid P2P vendor command attributes";
LABEL_3:
    qdf_trace_msg(0x48u, 8u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "osif_p2p_parse_wfd_params");
    goto LABEL_4;
  }
  if ( !v24 )
  {
    v12 = "%s: P2P USD OP type parse failed";
    goto LABEL_3;
  }
  v14 = *(unsigned __int8 *)(v24 + 4);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: p2p_mode %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "osif_p2p_parse_wfd_params",
    *(unsigned __int8 *)(v24 + 4));
  if ( v14 < 3 )
  {
    result = 0;
    *(_BYTE *)(a1 + 57448) = v14;
    goto LABEL_5;
  }
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: invalid p2p mode type %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "osif_p2p_mode_convert_qca_enum_to_p2p_enum",
    v14);
LABEL_4:
  result = 4294967274LL;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
