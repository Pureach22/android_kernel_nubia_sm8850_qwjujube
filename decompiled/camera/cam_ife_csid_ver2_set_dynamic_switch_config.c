__int64 __fastcall cam_ife_csid_ver2_set_dynamic_switch_config(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  char v3; // w8
  __int64 v4; // x8
  int v5; // w9
  __int64 v6; // x8
  int v7; // w9
  __int64 v8; // x8
  int v9; // w9
  __int64 result; // x0
  unsigned int v11; // w8
  __int64 v12; // x8
  unsigned int v13; // w9
  int v14; // w7
  __int64 v15; // x9
  int v16; // w10
  int *v17; // x9
  int v18; // w19
  __int64 v19; // x22
  __int64 v20; // x21
  __int64 v21; // x23
  __int64 (__fastcall *v22)(_QWORD); // x8
  int v23; // w0
  __int64 v24; // x8
  unsigned int v25; // w7
  int v26; // w21
  const char *v27; // x5
  __int64 v28; // x6
  __int64 v29; // x4
  _DWORD *v30; // x9
  __int64 v31; // x0
  int v32; // w11
  int v33; // w10
  int v34; // w14
  _DWORD *v35; // t2
  int v36; // w10
  _DWORD *v37; // x11
  __int64 v38; // x19
  __int64 v39; // x19
  __int64 v40; // x21
  __int64 v41; // x19
  __int64 v42; // x21
  __int64 v43; // x19
  __int64 v44; // x21
  __int64 v45; // x23
  __int64 v46; // x19
  __int64 v47; // x21
  unsigned int v50; // w10
  unsigned int v53; // w10
  unsigned int v60; // w10
  _DWORD v61[4]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v62; // [xsp+18h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_50;
  v2 = **(_QWORD **)(a1 + 31136);
  if ( *(_BYTE *)(a2 + 4) == 1 )
  {
    v3 = debug_mdl;
    *(_DWORD *)(a1 + 2092) = *(_DWORD *)a2;
    if ( (v3 & 8) != 0 && !debug_priority )
    {
      v39 = a2;
      v40 = a1;
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        v3 & 8,
        4,
        "cam_ife_csid_ver2_set_dynamic_switch_config",
        8225,
        "CSID[%u] MUP %u",
        *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL));
      a1 = v40;
      a2 = v39;
    }
  }
  if ( *(_BYTE *)(a2 + 12) != 1 )
    goto LABEL_30;
  v4 = *(_QWORD *)(a1 + 24);
  if ( !v4 )
    goto LABEL_14;
  if ( (*(_DWORD *)(a1 + 8) & 0xFFFFFFFE) != 2 )
    goto LABEL_14;
  if ( *(_DWORD *)(a2 + 8) )
    goto LABEL_14;
  v5 = *(unsigned __int8 *)(v4 + 248);
  *(_BYTE *)(v4 + 249) = 1;
  if ( v5 != 1 )
    goto LABEL_14;
  *(_BYTE *)(v4 + 248) = 0;
  *(_DWORD *)(v4 + 228) = 0;
  _X8 = (unsigned int *)(a1 + 32248);
  __asm { PRFM            #0x11, [X8] }
  do
    v60 = __ldxr(_X8);
  while ( __stxr(v60 - 1, _X8) );
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v46 = a2;
    v47 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_set_dynamic_switch_config",
      8256,
      "CSID[%u] Reset discard config for %s",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      (const char *)(a1 + 128));
    a1 = v47;
    a2 = v46;
    v6 = *(_QWORD *)(v47 + 176);
    if ( !v6 )
      goto LABEL_22;
  }
  else
  {
LABEL_14:
    v6 = *(_QWORD *)(a1 + 176);
    if ( !v6 )
      goto LABEL_22;
  }
  if ( (*(_DWORD *)(a1 + 160) & 0xFFFFFFFE) != 2 )
    goto LABEL_22;
  if ( *(_DWORD *)(a2 + 8) > 1u )
    goto LABEL_22;
  v7 = *(unsigned __int8 *)(v6 + 248);
  *(_BYTE *)(v6 + 249) = 1;
  if ( v7 != 1 )
    goto LABEL_22;
  *(_BYTE *)(v6 + 248) = 0;
  *(_DWORD *)(v6 + 228) = 0;
  while ( 1 )
  {
    _X8 = (unsigned int *)(a1 + 32248);
    __asm { PRFM            #0x11, [X8] }
    do
      v50 = __ldxr(_X8);
    while ( __stxr(v50 - 1, _X8) );
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v41 = a2;
      v42 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_set_dynamic_switch_config",
        8256,
        "CSID[%u] Reset discard config for %s",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        (const char *)(a1 + 280));
      a1 = v42;
      a2 = v41;
    }
LABEL_22:
    v8 = *(_QWORD *)(a1 + 328);
    if ( v8 )
    {
      if ( (*(_DWORD *)(a1 + 312) & 0xFFFFFFFE) == 2 && *(_DWORD *)(a2 + 8) <= 2u )
      {
        v9 = *(unsigned __int8 *)(v8 + 248);
        *(_BYTE *)(v8 + 249) = 1;
        if ( v9 == 1 )
        {
          *(_BYTE *)(v8 + 248) = 0;
          *(_DWORD *)(v8 + 228) = 0;
          _X8 = (unsigned int *)(a1 + 32248);
          __asm { PRFM            #0x11, [X8] }
          do
            v53 = __ldxr(_X8);
          while ( __stxr(v53 - 1, _X8) );
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            v43 = a2;
            v44 = a1;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_csid_ver2_set_dynamic_switch_config",
              8256,
              "CSID[%u] Reset discard config for %s",
              *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
              (const char *)(a1 + 432));
            a1 = v44;
            a2 = v43;
          }
        }
      }
    }
LABEL_30:
    if ( *(_DWORD *)(*(_QWORD *)(v2 + 120) + 592LL) < 3u || (*(_BYTE *)(a2 + 44) & 1) != 0 )
    {
      result = 0;
      goto LABEL_51;
    }
    v11 = *(_DWORD *)(a2 + 36);
    if ( v11 <= 0xC )
    {
      v12 = a1 + 152LL * v11;
      if ( *(_DWORD *)(v12 + 8) == 1 )
        goto LABEL_50;
      v13 = *(_DWORD *)(*(_QWORD *)(v12 + 24) + 120LL);
      if ( v13 <= 4 )
        break;
    }
    __break(0x5512u);
  }
  v14 = *(_DWORD *)(a2 + 40);
  v15 = a1 + 56LL * v13;
  v16 = *(unsigned __int8 *)(v15 + 1832);
  v17 = (int *)(v15 + 1824);
  if ( (v16 != 1 || (v18 = *v17, v14 != (*v17 & 1))) && (*((_BYTE *)v17 + 20) != 1 || (v18 = v17[3], v14 != (v18 & 1)))
    || v18 < 0 )
  {
    v27 = "CSID[%u] no vc found for the given mup: %u";
    v28 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v29 = 8295;
    goto LABEL_49;
  }
  v19 = a1;
  v20 = a2;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v45 = v12;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_set_dynamic_switch_config",
      8301,
      "CSID[%u] Configuring vc: %u dt: %u for pkt capture",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      v18,
      *(_DWORD *)(a2 + 32));
    v12 = v45;
  }
  v21 = *(_QWORD *)(v12 + 48);
  v22 = *(__int64 (__fastcall **)(_QWORD))(v21 + 24);
  if ( *((_DWORD *)v22 - 1) != 2010610996 )
    __break(0x8228u);
  v23 = v22(2);
  v24 = v20;
  v25 = *(_DWORD *)(v20 + 24);
  v26 = 4 * v23;
  if ( 4 * v23 > v25 )
  {
    v27 = "CSID[%u] buf size:%d is not sufficient, expected: %d";
    v28 = *(unsigned int *)(*(_QWORD *)(v19 + 31120) + 4LL);
    v29 = 8308;
LABEL_49:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_set_dynamic_switch_config",
      v29,
      v27,
      v28);
LABEL_50:
    result = 4294967274LL;
    goto LABEL_51;
  }
  v30 = *(_DWORD **)(v2 + 128);
  v31 = *(_QWORD *)(v24 + 16);
  v32 = 1 << v30[42];
  v33 = *(_DWORD *)(v24 + 32) << v30[45];
  v34 = v18 << v30[46];
  v35 = v30 + 10;
  LODWORD(v30) = v30[10];
  v36 = v33 | v32;
  v37 = *(_DWORD **)(v21 + 120);
  v38 = v24;
  v61[0] = v35[1];
  v61[1] = 1;
  v61[2] = (_DWORD)v30;
  v61[3] = v36 | v34;
  if ( *(v37 - 1) != -1401492769 )
    __break(0x822Bu);
  ((void (__fastcall *)(__int64, __int64, _DWORD *))v37)(v31, 2, v61);
  result = 0;
  *(_DWORD *)(v38 + 28) = v26;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
