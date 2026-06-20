__int64 __fastcall dp_ipa_setup(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        char a11,
        __int64 a12,
        char a13,
        int a14,
        unsigned int a15)
{
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x20
  __int64 v21; // x25
  __int64 v22; // x28
  int v23; // w8
  __int64 result; // x0
  int v25; // w8
  __int64 v26; // x8
  __int64 v27; // x8
  __int16 v28; // w8
  __int64 (__fastcall *v29)(_QWORD); // x8
  unsigned __int8 v30; // w23
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int16 v39; // w8
  __int64 (__fastcall *v40)(_QWORD); // x8
  unsigned __int8 v41; // w23
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w28
  __int64 v51; // x24
  __int64 v52; // x25
  int v53; // w8
  int v54; // w8
  int v55; // w8
  __int64 v56; // x8
  __int64 v57; // x8
  __int64 v58; // x8
  __int64 v59; // x8
  unsigned int v60; // w0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w21
  int v70; // w4
  int v71; // w5
  int v72; // w6
  int v73; // w7
  __int64 v74; // x8
  char v75; // w10
  char v76; // [xsp+0h] [xbp-40h]
  int v77[2]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v78; // [xsp+20h] [xbp-20h]
  __int64 v79; // [xsp+28h] [xbp-18h]
  __int64 v80; // [xsp+30h] [xbp-10h]
  __int64 v81; // [xsp+38h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(_QWORD *)(a1 + 40);
  v79 = 0;
  v80 = 0;
  *(_QWORD *)v77 = 0;
  v78 = 0;
  if ( (wlan_cfg_is_ipa_enabled(v18) & 1) == 0 )
  {
    result = 0;
    goto LABEL_63;
  }
  v19 = _qdf_mem_malloc(0x808u, "dp_ipa_setup", 3136);
  if ( !v19 )
  {
    result = 2;
    goto LABEL_63;
  }
  v20 = v19;
  qdf_mem_set(v77, 0x20u, 0);
  *(_WORD *)(v20 + 16) = a11 & 1;
  *(_DWORD *)(v20 + 804) = 14;
  if ( (a11 & 1) != 0 )
    v21 = 0;
  else
    v21 = v20 + 792;
  if ( (a11 & 1) != 0 )
    v22 = v20 + 792;
  else
    v22 = 0;
  *(_DWORD *)(v20 + 792) = 0;
  *(_DWORD *)(v20 + 824) = 0;
  *(_QWORD *)(v20 + 816) = 0;
  *(_DWORD *)(v20 + 880) = 0;
  *(_BYTE *)(v20 + 857) = 1;
  if ( (a11 & 1) != 0 )
  {
    if ( (a13 & 1) != 0 )
    {
      if ( a15 > 2 )
        goto LABEL_30;
      v23 = dword_A2B3E0[a15];
    }
    else
    {
      v23 = 11;
    }
    *(_DWORD *)(v22 + 192) = v23;
LABEL_30:
    qdf_mem_copy((void *)(v22 + 200), (const void *)(a1 + 18264), 0x10u);
    *(_DWORD *)(v22 + 216) = *(_QWORD *)(a1 + 18240);
    *(_QWORD *)(v22 + 224) = *(_QWORD *)(a1 + 18048);
    *(_BYTE *)(v22 + 232) = (unsigned int)pld_get_pci_slot(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL)) == 0;
    qdf_mem_copy((void *)(v22 + 240), (const void *)(a1 + 18192), 0x10u);
    *(_DWORD *)(v22 + 256) = *(_QWORD *)(a1 + 18168);
    *(_QWORD *)(v22 + 264) = *(_QWORD *)(a1 + 18008);
    *(_BYTE *)(v22 + 272) = (unsigned int)pld_get_pci_slot(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL)) == 0;
    v39 = *(_DWORD *)(a1 + 18216);
    *(_WORD *)(v22 + 276) = 0;
    *(_WORD *)(v22 + 274) = v39;
    v40 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1648);
    if ( v40 )
    {
      if ( *((_DWORD *)v40 - 1) != -305200552 )
        __break(0x8228u);
      v41 = v40(a1);
      qdf_trace_msg(0x45u, 5u, "%s: bank_id %u", v42, v43, v44, v45, v46, v47, v48, v49, "dp_ipa_get_tx_bank_id", v41);
      *(_BYTE *)(v22 + 408) = v41;
    }
    goto LABEL_34;
  }
  if ( (a13 & 1) != 0 )
    v25 = 13;
  else
    v25 = 11;
  *(_DWORD *)(v21 + 192) = v25;
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 24) + 608LL) )
    v26 = 8;
  else
    v26 = 0;
  *(_QWORD *)(v21 + 200) = *(_QWORD *)(a1 + v26 + 18224);
  *(_DWORD *)(v21 + 208) = *(_QWORD *)(a1 + 18240);
  *(_QWORD *)(v21 + 216) = *(_QWORD *)(a1 + 18048);
  *(_BYTE *)(v21 + 224) = (unsigned int)pld_get_pci_slot(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL)) == 0;
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 24) + 608LL) )
    v27 = 8;
  else
    v27 = 0;
  *(_QWORD *)(v21 + 232) = *(_QWORD *)(a1 + 18152 + v27);
  *(_DWORD *)(v21 + 240) = *(_QWORD *)(a1 + 18168);
  *(_QWORD *)(v21 + 248) = *(_QWORD *)(a1 + 18008);
  *(_BYTE *)(v21 + 256) = (unsigned int)pld_get_pci_slot(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL)) == 0;
  v28 = *(_DWORD *)(a1 + 18216);
  *(_WORD *)(v21 + 260) = 0;
  *(_WORD *)(v21 + 258) = v28;
  v29 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1648);
  if ( v29 )
  {
    if ( *((_DWORD *)v29 - 1) != -305200552 )
      __break(0x8228u);
    v30 = v29(a1);
    qdf_trace_msg(0x45u, 5u, "%s: bank_id %u", v31, v32, v33, v34, v35, v36, v37, v38, "dp_ipa_get_tx_bank_id", v30);
    *(_BYTE *)(v21 + 392) = v30;
  }
LABEL_34:
  v50 = *(unsigned __int8 *)(v20 + 16);
  v51 = v20 + 1208;
  *(_DWORD *)(v20 + 1208) = 0;
  if ( v50 )
    v52 = v20 + 1208;
  else
    v52 = 0;
  if ( (ucfg_ipa_is_wds_enabled() & 1) != 0 )
    v53 = 26;
  else
    v53 = 14;
  *(_DWORD *)(v20 + 1240) = 0;
  *(_DWORD *)(v20 + 1224) = 0;
  *(_QWORD *)(v20 + 1232) = 0x100000000LL;
  *(_DWORD *)(v20 + 1220) = v53;
  *(_DWORD *)(v20 + 1252) = 1;
  *(_DWORD *)(v20 + 1296) = 0;
  *(_BYTE *)(v20 + 1273) = 1;
  if ( (a11 & 1) == 0 )
  {
    if ( v50 )
      v51 = 0;
    if ( (a13 & 1) != 0 )
      v55 = 12;
    else
      v55 = 10;
    *(_DWORD *)(v51 + 192) = v55;
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 24) + 608LL) )
      v56 = 8;
    else
      v56 = 0;
    *(_QWORD *)(v51 + 200) = *(_QWORD *)(a1 + v56 + 18288);
    *(_DWORD *)(v51 + 208) = *(_QWORD *)(a1 + 18304);
    *(_QWORD *)(v51 + 216) = *(_QWORD *)(a1 + 18104);
    *(_BYTE *)(v51 + 224) = (unsigned int)pld_get_pci_slot(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL)) == 0;
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 24) + 608LL) )
      v57 = 8;
    else
      v57 = 0;
    *(_QWORD *)(v51 + 232) = *(_QWORD *)(a1 + v57 + 18352);
    *(_DWORD *)(v51 + 240) = *(_QWORD *)(a1 + 18368);
    v58 = *(_QWORD *)(a1 + 18136);
    *(_BYTE *)(v51 + 256) = 0;
    *(_QWORD *)(v51 + 248) = v58;
    *(_WORD *)(v51 + 260) = *(_WORD *)(a1 + 1138) + 2;
    goto LABEL_59;
  }
  if ( (a13 & 1) == 0 )
  {
    v54 = 10;
    goto LABEL_57;
  }
  if ( a15 <= 2 )
  {
    v54 = dword_A2B3EC[a15];
LABEL_57:
    *(_DWORD *)(v52 + 192) = v54;
  }
  qdf_mem_copy((void *)(v52 + 200), (const void *)(a1 + 18328), 0x10u);
  *(_DWORD *)(v52 + 216) = *(_QWORD *)(a1 + 18304);
  *(_QWORD *)(v52 + 224) = *(_QWORD *)(a1 + 18104);
  *(_BYTE *)(v52 + 232) = (unsigned int)pld_get_pci_slot(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL)) == 0;
  qdf_mem_copy((void *)(v52 + 240), (const void *)(a1 + 18392), 0x10u);
  *(_DWORD *)(v52 + 256) = *(_QWORD *)(a1 + 18368);
  v59 = *(_QWORD *)(a1 + 18136);
  *(_BYTE *)(v52 + 272) = 0;
  *(_QWORD *)(v52 + 264) = v59;
  *(_WORD *)(v52 + 276) = *(_WORD *)(a1 + 1138) + 2;
LABEL_59:
  *(_QWORD *)v20 = a4;
  *(_QWORD *)(v20 + 8) = a7;
  *(_DWORD *)(v20 + 2048) = a14;
  v60 = ipa_wdi_conn_pipes_per_inst(v20, v77);
  if ( v60 )
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: ipa_wdi_conn_pipes: IPA pipe setup failed: ret=%d",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "dp_ipa_setup",
      v60);
    v69 = 16;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Tx DB PA=0x%x, Rx DB PA=0x%x",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "dp_ipa_setup",
      (unsigned int)v77[0],
      (unsigned int)v78);
    wlan_ipa_log_message((int)"dp_ipa_setup", (int)"Tx DB PA=0x%x, Rx DB PA=0x%x", v77[0], v78, v70, v71, v72, v73, v76);
    v74 = *(_QWORD *)v77;
    v69 = 0;
    v75 = v80;
    *(_QWORD *)(a1 + 18432) = v78;
    *(_QWORD *)(a1 + 18416) = v74;
    *(_BYTE *)(a1 + 18440) = v75;
    *(_BYTE *)(a1 + 18148) = 1;
  }
  _qdf_mem_free(v20);
  result = v69;
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return result;
}
