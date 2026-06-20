__int64 __fastcall hdd_set_reset_apf_offload(__int64 a1, _QWORD *a2, __int64 a3)
{
  _DWORD *v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  __int64 v16; // x9
  unsigned int v17; // w21
  _WORD *v18; // x8
  int v19; // w23
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x8
  int v23; // w6
  __int64 v24; // x8
  int v25; // w8
  __int64 result; // x0
  const char *v27; // x2
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w20
  unsigned int v46; // w21
  __int64 v47; // [xsp+18h] [xbp-28h] BYREF
  __int64 v48; // [xsp+20h] [xbp-20h]
  __int64 v49; // [xsp+28h] [xbp-18h]
  __int64 v50; // [xsp+30h] [xbp-10h]
  __int64 v51; // [xsp+38h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD **)(a3 + 52832);
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  if ( !hdd_cm_is_vdev_associated(v6) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Not in Connected state!",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "hdd_set_reset_apf_offload");
    result = 4294966772LL;
    goto LABEL_25;
  }
  v15 = a2[4];
  if ( !v15 )
  {
    v27 = "%s: attr apf packet size failed";
LABEL_19:
    qdf_trace_msg(0x33u, 2u, v27, v7, v8, v9, v10, v11, v12, v13, v14, "hdd_set_reset_apf_offload");
    goto LABEL_20;
  }
  v16 = *(_QWORD *)(a3 + 52832);
  v17 = *(unsigned __int8 *)(v16 + 8);
  LOBYTE(v47) = *(_BYTE *)(v16 + 8);
  HIDWORD(v48) = *(_DWORD *)(v15 + 4);
  if ( !HIDWORD(v48) )
  {
    qdf_trace_msg(0x33u, 8u, "%s: APF reset packet", v7, v8, v9, v10, v11, v12, v13, v14, "hdd_set_reset_apf_offload");
    v25 = 0;
    v19 = 0;
    goto LABEL_12;
  }
  v18 = (_WORD *)a2[6];
  if ( !v18 )
  {
    v27 = "%s: attr apf program failed";
    goto LABEL_19;
  }
  LOWORD(v19) = *v18 - 4;
  v20 = _qdf_mem_malloc((unsigned __int16)v19, "hdd_set_reset_apf_offload", 258);
  v50 = v20;
  if ( !v20 )
  {
    v45 = 0;
    result = 4294967284LL;
    goto LABEL_21;
  }
  v19 = (unsigned __int16)v19;
  v21 = a2[6];
  HIDWORD(v49) = v19;
  nla_memcpy(v20, v21, (unsigned __int16)v19);
  v22 = a2[3];
  if ( !v22 )
  {
    v27 = "%s: attr filter id failed";
    goto LABEL_19;
  }
  v23 = *(_DWORD *)(v22 + 4);
  v24 = a2[5];
  LODWORD(v48) = v23;
  if ( !v24 )
  {
    v27 = "%s: attr current offset failed";
    goto LABEL_19;
  }
  v25 = *(_DWORD *)(v24 + 4);
  LODWORD(v49) = v25;
LABEL_12:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Posting, session_id: %d APF Version: %d filter ID: %d total_len: %d current_len: %d offset: %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "hdd_set_reset_apf_offload",
    v17,
    0,
    v19,
    v25);
  v36 = sme_set_apf_instructions(v28, v29, v30, v31, v32, v33, v34, v35, *(_QWORD *)(a1 + 16), (__int64)&v47);
  if ( v36 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: sme_set_apf_instructions failed(err=%d)",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "hdd_set_reset_apf_offload",
      v36);
LABEL_20:
    v45 = 0;
    result = 4294967274LL;
    goto LABEL_21;
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v37, v38, v39, v40, v41, v42, v43, v44, "hdd_set_reset_apf_offload");
  result = 0;
  v45 = 1;
LABEL_21:
  if ( HIDWORD(v49) )
  {
    v46 = result;
    _qdf_mem_free(v50);
    result = v46;
  }
  if ( v45 )
    *(_BYTE *)(a1 + 3612) = 1;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
