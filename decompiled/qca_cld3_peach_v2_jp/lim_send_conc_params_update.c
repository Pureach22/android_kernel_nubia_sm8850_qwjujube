__int64 __fastcall lim_send_conc_params_update(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // x0
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int connection_count; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned __int8 v27; // w9
  __int64 v28; // x21
  __int64 v29; // x20
  __int64 v30; // x11
  int v31; // w12
  __int64 v32; // x4
  const char *v33; // x2
  const char *v34; // x3
  int v35; // w8
  int v36; // w9
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x0
  char v46; // w10
  int v47; // w10
  int v48; // w10
  int v49; // w11
  int v50; // w11
  int v51; // w13
  int v52; // w15
  int v53; // w9
  int v54; // w9
  int v55; // w10
  int v56; // w10
  int v57; // w10
  int v58; // w24
  unsigned int v59; // w22
  __int64 values; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  char v69; // w8
  int v70; // w9
  __int16 v71; // w2
  int v72; // w10
  int v73; // w10
  char v74; // w8
  __int16 v75; // w2
  __int64 v76; // x0
  int v77; // w10
  int v78; // w11
  char v79; // w9
  int *v80; // x1
  int v81; // w9
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  char v90; // w8
  int v91; // w9
  int v92; // w10
  int v93; // w10
  __int16 v94; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v95; // [xsp+8h] [xbp-8h]

  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(53, (__int64)"lim_send_conc_params_update", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !result )
    goto LABEL_5;
  v9 = result;
  if ( *(_BYTE *)(*(_QWORD *)(result + 8) + 976LL) != 1
    || (unsigned int)policy_mgr_get_connection_count(*(_QWORD *)(result + 21552)) > 2 )
  {
    connection_count = policy_mgr_get_connection_count(*(_QWORD *)(v9 + 21552));
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: A-EDCA not enabled or max number of connections: %d",
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               "lim_send_conc_params_update",
               connection_count);
    goto LABEL_5;
  }
  if ( !*(_WORD *)(v9 + 3992) )
  {
    v29 = 0;
    v28 = 0;
LABEL_19:
    if ( !(v29 | v28) )
    {
      v33 = "%s: No sta or sap or P2P go session";
      v34 = "lim_send_conc_params_update";
      goto LABEL_24;
    }
    if ( v29 )
    {
      v32 = *(unsigned __int8 *)(v29 + 70);
      if ( v28 )
        goto LABEL_26;
    }
    else
    {
      if ( v28 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Valid STA session: %d Valid SAP session: %d",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "lim_send_conc_params_update",
          0,
          *(unsigned __int8 *)(v28 + 70));
        v29 = 0;
        v58 = 0;
        v94 = 0;
        goto LABEL_33;
      }
      v32 = 0;
    }
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Valid STA session: %d Valid SAP session: %d",
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               "lim_send_conc_params_update",
               v32,
               0);
    v94 = 0;
    if ( !v29 )
      goto LABEL_5;
    check_and_send_vendor_oui(v9, v29);
    if ( !(unsigned int)qdf_mem_cmp((const void *)(v29 + 7136), (const void *)(v29 + 7096), 5u)
      && !(unsigned int)qdf_mem_cmp((const void *)(v29 + 7141), (const void *)(v29 + 7101), 5u)
      && !(unsigned int)qdf_mem_cmp((const void *)(v29 + 7146), (const void *)(v29 + 7106), 5u) )
    {
      result = qdf_mem_cmp((const void *)(v29 + 7151), (const void *)(v29 + 7111), 5u);
      if ( !(_DWORD)result )
        goto LABEL_5;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: local sta EDCA params are not equal to Active EDCA params, hence update required",
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      "lim_check_conc_and_send_edca");
    v90 = *(_BYTE *)(v29 + 7105);
    v91 = *(_DWORD *)(v29 + 7096);
    v75 = *(unsigned __int8 *)(v29 + 10);
    v76 = v9;
    v80 = (int *)(v29 + 7136);
    *(_DWORD *)(v29 + 7141) = *(_DWORD *)(v29 + 7101);
    *(_BYTE *)(v29 + 7145) = v90;
    v92 = *(_DWORD *)(v29 + 7106);
    *(_DWORD *)(v29 + 7136) = v91;
    LOBYTE(v91) = *(_BYTE *)(v29 + 7110);
    *(_DWORD *)(v29 + 7146) = v92;
    LOBYTE(v92) = *(_BYTE *)(v29 + 7100);
    *(_BYTE *)(v29 + 7150) = v91;
    LOBYTE(v91) = *(_BYTE *)(v29 + 7115);
    *(_BYTE *)(v29 + 7140) = v92;
    v93 = *(_DWORD *)(v29 + 7111);
    *(_BYTE *)(v29 + 7155) = v91;
    *(_DWORD *)(v29 + 7151) = v93;
    goto LABEL_50;
  }
  v27 = 0;
  v28 = 0;
  v29 = 0;
  while ( !v29 || !v28 )
  {
    v30 = *(_QWORD *)(v9 + 12264) + 10792LL * v27;
    if ( *(_BYTE *)(v30 + 70) )
    {
      v31 = *(_DWORD *)(v30 + 88);
      if ( v31 != 4 )
      {
        if ( v31 == 2 )
        {
          v29 = *(_QWORD *)(v9 + 12264) + 10792LL * v27;
          goto LABEL_9;
        }
        if ( v31 != 1 )
          goto LABEL_9;
      }
      v28 = *(_QWORD *)(v9 + 12264) + 10792LL * v27;
    }
LABEL_9:
    if ( *(unsigned __int16 *)(v9 + 3992) <= (unsigned int)++v27 )
      goto LABEL_19;
  }
  v32 = *(unsigned __int8 *)(v29 + 70);
LABEL_26:
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Valid STA session: %d Valid SAP session: %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "lim_send_conc_params_update",
    v32,
    *(unsigned __int8 *)(v28 + 70));
  v35 = *(_DWORD *)(v29 + 284);
  v36 = *(_DWORD *)(v28 + 284);
  v94 = 0;
  if ( v35 != v36 )
  {
    v58 = 1;
LABEL_33:
    v59 = *(unsigned __int8 *)(v28 + 10);
    values = cfg_psoc_get_values(*(_QWORD *)(v9 + 21552));
    wma_cli_set_command(v59, 44, *(unsigned int *)(values + 1192), 1);
    if ( v58 )
      check_and_send_vendor_oui(v9, v29);
    if ( !(unsigned int)qdf_mem_cmp((const void *)(v28 + 7136), (const void *)(v28 + 7096), 5u)
      && !(unsigned int)qdf_mem_cmp((const void *)(v28 + 7141), (const void *)(v28 + 7101), 5u)
      && !(unsigned int)qdf_mem_cmp((const void *)(v28 + 7146), (const void *)(v28 + 7106), 5u) )
    {
      result = qdf_mem_cmp((const void *)(v28 + 7151), (const void *)(v28 + 7111), 5u);
      if ( !(_DWORD)result )
        goto LABEL_5;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: local sap EDCA params are not equal to Active EDCA params, hence update required",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "lim_check_conc_and_send_edca");
    v69 = *(_BYTE *)(v28 + 7105);
    v70 = *(_DWORD *)(v28 + 7096);
    v71 = *(unsigned __int8 *)(v28 + 10);
    *(_DWORD *)(v28 + 7141) = *(_DWORD *)(v28 + 7101);
    *(_BYTE *)(v28 + 7145) = v69;
    v72 = *(_DWORD *)(v28 + 7106);
    *(_DWORD *)(v28 + 7136) = v70;
    LOBYTE(v70) = *(_BYTE *)(v28 + 7110);
    *(_DWORD *)(v28 + 7146) = v72;
    LOBYTE(v72) = *(_BYTE *)(v28 + 7100);
    *(_BYTE *)(v28 + 7150) = v70;
    LOBYTE(v70) = *(_BYTE *)(v28 + 7115);
    *(_BYTE *)(v28 + 7140) = v72;
    v73 = *(_DWORD *)(v28 + 7111);
    *(_BYTE *)(v28 + 7155) = v70;
    *(_DWORD *)(v28 + 7151) = v73;
    lim_send_edca_params(v9, (int *)(v28 + 7136), v71, 0);
    result = sch_qos_update_broadcast(v9, v28, 0);
    if ( !v58 )
      goto LABEL_5;
    v74 = *(_BYTE *)(v29 + 7105);
    v75 = *(unsigned __int8 *)(v29 + 10);
    v76 = v9;
    *(_DWORD *)(v29 + 7141) = *(_DWORD *)(v29 + 7101);
    v77 = *(_DWORD *)(v29 + 7096);
    *(_BYTE *)(v29 + 7145) = v74;
    v78 = *(_DWORD *)(v29 + 7106);
    *(_DWORD *)(v29 + 7136) = v77;
    v79 = *(_BYTE *)(v29 + 7100);
    *(_DWORD *)(v29 + 7146) = v78;
    v80 = (int *)(v29 + 7136);
    *(_BYTE *)(v29 + 7150) = *(_BYTE *)(v29 + 7110);
    LOBYTE(v78) = *(_BYTE *)(v29 + 7115);
    *(_BYTE *)(v29 + 7140) = v79;
    v81 = *(_DWORD *)(v29 + 7111);
    *(_BYTE *)(v29 + 7155) = v78;
    *(_DWORD *)(v29 + 7151) = v81;
LABEL_50:
    result = lim_send_edca_params(v76, v80, v75, 0);
    goto LABEL_5;
  }
  wma_cli_set_command(*(unsigned __int8 *)(v28 + 10), 44, 17, 1);
  wma_cli_set_command(*(unsigned __int8 *)(v29 + 10), 44, 17, 1);
  v45 = dph_lookup_hash_entry(
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v9,
          (unsigned __int8 *)(v29 + 24),
          &v94,
          v29 + 360);
  if ( !v45 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: No STA DS entry found for %02x:%02x:%02x:**:**:%02x",
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               "lim_check_conc_and_send_edca",
               *(unsigned __int8 *)(v29 + 24),
               *(unsigned __int8 *)(v29 + 25),
               *(unsigned __int8 *)(v29 + 26),
               *(unsigned __int8 *)(v29 + 29));
    goto LABEL_5;
  }
  if ( *(_BYTE *)(v45 + 240) )
  {
    v46 = *(_BYTE *)(v45 + 247);
    *(_DWORD *)(v28 + 7116) = *(_DWORD *)(v45 + 243);
    *(_BYTE *)(v28 + 7120) = v46;
    v47 = *(_DWORD *)(v45 + 248);
    *(_BYTE *)(v28 + 7125) = *(_BYTE *)(v45 + 252);
    *(_DWORD *)(v28 + 7121) = v47;
    v48 = *(_DWORD *)(v45 + 253);
    *(_BYTE *)(v28 + 7130) = *(_BYTE *)(v45 + 257);
    *(_DWORD *)(v28 + 7126) = v48;
    v49 = *(_DWORD *)(v45 + 258);
    *(_BYTE *)(v28 + 7135) = *(_BYTE *)(v45 + 262);
    *(_DWORD *)(v28 + 7131) = v49;
    v50 = *(_DWORD *)(v45 + 243);
    *(_BYTE *)(v28 + 7140) = *(_BYTE *)(v45 + 247);
    *(_DWORD *)(v28 + 7136) = v50;
    v51 = *(_DWORD *)(v45 + 248);
    *(_BYTE *)(v28 + 7145) = *(_BYTE *)(v45 + 252);
    *(_DWORD *)(v28 + 7141) = v51;
    v52 = *(_DWORD *)(v45 + 253);
    *(_BYTE *)(v28 + 7150) = *(_BYTE *)(v45 + 257);
    *(_DWORD *)(v28 + 7146) = v52;
    v53 = *(_DWORD *)(v45 + 258);
    *(_BYTE *)(v28 + 7155) = *(_BYTE *)(v45 + 262);
    LOBYTE(v52) = *(_BYTE *)(v28 + 7140);
    *(_DWORD *)(v28 + 7151) = v53;
    v54 = *(_DWORD *)(v28 + 7136);
    *(_BYTE *)(v29 + 7140) = v52;
    *(_DWORD *)(v29 + 7136) = v54;
    v55 = *(_DWORD *)(v28 + 7141);
    *(_BYTE *)(v29 + 7145) = *(_BYTE *)(v28 + 7145);
    *(_DWORD *)(v29 + 7141) = v55;
    v56 = *(_DWORD *)(v28 + 7146);
    *(_BYTE *)(v29 + 7150) = *(_BYTE *)(v28 + 7150);
    *(_DWORD *)(v29 + 7146) = v56;
    v57 = *(_DWORD *)(v28 + 7151);
    *(_BYTE *)(v29 + 7155) = *(_BYTE *)(v28 + 7155);
    *(_DWORD *)(v29 + 7151) = v57;
    lim_send_edca_params(v9, (int *)(v28 + 7136), *(unsigned __int8 *)(v28 + 10), 0);
    ++*(_BYTE *)(v28 + 7156);
    result = csr_update_beacon(v9);
    goto LABEL_5;
  }
  v33 = "%s: No sta_ds edca_params present";
  v34 = "lim_check_conc_and_send_edca";
LABEL_24:
  result = qdf_trace_msg(0x35u, 8u, v33, v10, v11, v12, v13, v14, v15, v16, v17, v34);
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
