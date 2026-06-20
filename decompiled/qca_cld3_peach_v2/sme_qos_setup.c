__int64 __fastcall sme_qos_setup(
        __int64 a1,
        unsigned int a2,
        _BYTE *a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x4
  __int64 v13; // x9
  __int64 v15; // x24
  unsigned __int16 *v16; // x1
  unsigned int v19; // w19
  const char *v21; // x2
  unsigned int v22; // w19
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  char is_acm; // w8
  __int64 v35; // x4
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  int v45; // w26
  int v46; // w26
  char v47; // w8
  _BYTE v48[4]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v49[2]; // [xsp+10h] [xbp-10h] BYREF

  v12 = (unsigned __int8)a2;
  v49[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49[0] = 0;
  v48[0] = 0;
  if ( !a1
    || (unsigned __int8)a2 > 5u
    || (v13 = *(_QWORD *)(a1 + 17296)) == 0
    || (*(_BYTE *)(v13 + 96LL * (unsigned __int8)a2 + 1) & 1) == 0 )
  {
    v21 = "%s: Session Id %d is invalid";
    goto LABEL_10;
  }
  v15 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
  if ( (*(_BYTE *)(v15 + 1) & 1) == 0 )
  {
    v21 = "%s: Session %d is inactive";
    goto LABEL_10;
  }
  v16 = *(unsigned __int16 **)(v15 + 2920);
  if ( !v16 )
  {
    v21 = "%s: Session %d has an Invalid BSS Descriptor";
    goto LABEL_10;
  }
  v19 = v12;
  if ( (unsigned int)csr_get_parsed_bss_description_ies(a1, v16, v49) )
  {
    v21 = "%s: On session %d unable to parse BSS IEs";
    v12 = v19;
LABEL_10:
    v22 = 2;
    qdf_trace_msg(0x34u, 2u, v21, a5, a6, a7, a8, a9, a10, a11, a12, "sme_qos_setup", v12);
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return v22;
  }
  if ( !*(_BYTE *)(v49[0] + 3426) && !*(_BYTE *)(v49[0] + 3422) )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: On session %d AP doesn't support QoS",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "sme_qos_setup",
      v19);
    _qdf_mem_free(v49[0]);
    v22 = 4;
    goto LABEL_11;
  }
  v24 = qdf_trace_msg(
          0x34u,
          8u,
          "%s: UAPSD/PSB set %d: ",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "sme_qos_setup",
          (unsigned __int8)a3[12]);
  if ( a4 < 5 )
  {
    v33 = a1;
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 5692LL) & 1) != 0
      || (is_acm = sme_qos_is_acm(a1, *(unsigned __int16 **)(v15 + 2920), a4, 0, v25, v26, v27, v28, v29, v30, v31, v32),
          v33 = a1,
          (is_acm & 1) != 0) )
    {
      if ( a3[12] && (*(char *)(v49[0] + 3428) & 0x80000000) == 0 && (*(char *)(v49[0] + 3424) & 0x80000000) == 0 )
      {
        v35 = v19;
LABEL_32:
        v22 = 2;
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: On session %d AP doesn't support APSD",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "sme_qos_setup",
          v35);
        goto LABEL_35;
      }
      if ( (unsigned __int8)a3[20] == 255 )
        a3[20] = 7 - a3[8];
      if ( (unsigned int)qos_issue_command(v33, a2, 262145, a3, a4, 0) )
      {
        v44 = "%s: sme_qos_add_ts_req() failed";
LABEL_27:
        v22 = 2;
        qdf_trace_msg(0x34u, 2u, v44, v36, v37, v38, v39, v40, v41, v42, v43, "sme_qos_setup");
LABEL_35:
        _qdf_mem_free(v49[0]);
        goto LABEL_11;
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: On session %d AddTS on AC %d is pending",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "sme_qos_setup",
        v19,
        a4);
    }
    else
    {
      if ( a3[12] )
      {
        if ( (*(char *)(v49[0] + 3428) & 0x80000000) == 0 && (*(char *)(v49[0] + 3424) & 0x80000000) == 0 )
        {
          v35 = v19;
          goto LABEL_32;
        }
        v45 = 1 << (3 - a4);
        if ( ((unsigned __int8)v45 & *(_BYTE *)(v15 + 2916)) != 0 )
        {
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Request is looking for APSD and it is already set for the AC",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "sme_qos_setup");
          v22 = 1;
          goto LABEL_35;
        }
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: On session %d reassoc needed to enable APSD on AC %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "sme_qos_setup",
          v19);
        csr_get_modify_profile_fields(a1, v19, v48);
        v47 = *(_BYTE *)(v15 + 2916) | v45 | v48[0];
      }
      else
      {
        v46 = 1 << (3 - a4);
        if ( ((unsigned __int8)v46 & *(_BYTE *)(v15 + 2916)) == 0 )
        {
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Request is not looking for APSD & Admission Control isn't mandatory for the AC",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "sme_qos_setup");
          v22 = 7;
          goto LABEL_35;
        }
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: On session %d reassoc needed to disable APSD on AC %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "sme_qos_setup",
          v19);
        csr_get_modify_profile_fields(a1, v19, v48);
        v47 = (v48[0] | *(_BYTE *)(v15 + 2916)) & ~(_BYTE)v46;
      }
      v48[0] = v47;
      if ( (unsigned int)sme_qos_request_reassoc(a1, a2, v48) )
      {
        v44 = "%s: Unable to request reassociation";
        goto LABEL_27;
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: On session %d reassociation to enable APSD on AC %d is pending",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "sme_qos_setup",
        v19,
        a4);
      *(_BYTE *)(v15 + 728LL * a4 + 320) = 1;
    }
    v22 = 5;
    goto LABEL_35;
  }
  __break(0x5512u);
  return sme_qos_aggregate_params(v24);
}
