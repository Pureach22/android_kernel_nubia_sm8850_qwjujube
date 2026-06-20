__int64 kgsl_va_minidump_callback()
{
  _QWORD *v0; // x19
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 v3; // x22
  unsigned int v4; // w0
  __int64 v5; // x3
  __int64 result; // x0
  __int64 *v7; // x21
  unsigned int v8; // w0
  _QWORD *v9; // x25
  __int64 v10; // x21
  int v11; // w3
  __int64 *v12; // x25
  __int64 v13; // x8
  int v14; // w3
  __int64 v15; // x21
  int v16; // w3
  __int64 *v17; // x25
  __int64 v18; // x21
  int v19; // w3
  __int64 next; // x0
  __int64 v21; // x21
  const char *v22; // x2
  __int64 *v23; // x28
  const char *v24; // x25
  __int64 v25; // x23
  unsigned int v26; // w0
  __int64 v27; // x3
  _QWORD *v28; // x8
  _QWORD *v29; // x28
  _QWORD *v30; // t1
  _QWORD *v31; // x20
  __int64 *v32; // x27
  unsigned int v33; // w0
  _QWORD *i; // x26
  const char *v35; // x27
  __int64 v36; // x27
  __int64 *v37; // x28
  __int64 v38; // x23
  unsigned int v39; // w0
  unsigned int (__fastcall *v40)(_QWORD); // x8
  const char *v41; // x2
  int v42; // [xsp+Ch] [xbp-84h] BYREF
  char s[8]; // [xsp+10h] [xbp-80h] BYREF
  __int64 v44; // [xsp+18h] [xbp-78h]
  __int64 v45; // [xsp+20h] [xbp-70h]
  __int64 v46; // [xsp+28h] [xbp-68h]
  char v47[8]; // [xsp+30h] [xbp-60h] BYREF
  __int64 v48; // [xsp+38h] [xbp-58h]
  __int64 v49; // [xsp+40h] [xbp-50h]
  __int64 v50; // [xsp+48h] [xbp-48h]
  __int64 *v51; // [xsp+50h] [xbp-40h] BYREF
  __int64 v52; // [xsp+58h] [xbp-38h] BYREF
  __int64 v53; // [xsp+60h] [xbp-30h]
  __int64 v54; // [xsp+68h] [xbp-28h]
  __int64 v55; // [xsp+70h] [xbp-20h]
  __int64 v56; // [xsp+78h] [xbp-18h]
  __int64 v57; // [xsp+80h] [xbp-10h]
  __int64 v58; // [xsp+88h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = off_3A7F8;
  v45 = 0;
  v46 = 0;
  *(_QWORD *)s = 0;
  v44 = 0;
  v1 = *((_QWORD *)off_3A7F8 + 1783);
  v2 = *(_QWORD *)off_3A7F8;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v3 = *(_QWORD *)(v1 + 40);
  v56 = 0;
  v57 = 0;
  v51 = nullptr;
  scnprintf(&v52, 32, "kgsl_driver");
  v51 = (__int64 *)&kgsl_driver;
  LODWORD(v56) = 1376;
  v4 = qcom_va_md_add_region(&v51);
  v5 = v4;
  if ( (v4 & 0x80000000) != 0 )
  {
    v41 = "kgsl_driver";
    goto LABEL_51;
  }
  if ( v4 )
    goto LABEL_3;
  if ( (*(_BYTE *)(v0[1783] + 34LL) & 0x40) != 0 || *((_BYTE *)v0 + 11880) != 1 )
    goto LABEL_9;
  v2 = *v0;
  v7 = (__int64 *)v0[1441];
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v51 = nullptr;
  scnprintf(&v52, 32, "kgsl_adreno_tz_data");
  v51 = v7;
  LODWORD(v56) = 160;
  v8 = qcom_va_md_add_region(&v51);
  v5 = v8;
  if ( (v8 & 0x80000000) != 0 )
  {
    v41 = "kgsl_adreno_tz_data";
LABEL_51:
    dev_err(v2, "Failed to register %s with va_minidump: %d\n", v41, v5);
LABEL_3:
    result = 32770;
    goto LABEL_4;
  }
  if ( v8 )
    goto LABEL_3;
LABEL_9:
  v9 = v0 + 2600;
  do
  {
    v9 = (_QWORD *)*v9;
    if ( v9 == v0 + 2600 )
      break;
    snprintf(s, 0x20u, "kgsl_adreno_ctx_%d", *((_DWORD *)v9 - 403));
    v10 = *v0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v51 = nullptr;
    scnprintf(&v52, 32, s);
    v51 = v9 - 202;
    LODWORD(v56) = 2104;
    v11 = qcom_va_md_add_region(&v51);
    if ( v11 < 0 )
    {
      dev_err(v10, "Failed to register %s with va_minidump: %d\n", s, v11);
      break;
    }
  }
  while ( !v11 );
  v12 = &qword_3A800;
  do
  {
    v12 = (__int64 *)*v12;
    if ( v12 == &qword_3A800 )
      break;
    v13 = *(v12 - 8);
    if ( v13 )
      v14 = *(_DWORD *)(v13 + 112);
    else
      v14 = 0;
    snprintf(s, 0x20u, "kgsl_proc_priv_%d", v14);
    v15 = *v0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v51 = nullptr;
    scnprintf(&v52, 32, s);
    v51 = v12 - 9;
    LODWORD(v56) = 952;
    v16 = qcom_va_md_add_region(&v51);
    if ( v16 < 0 )
    {
      dev_err(v15, "Failed to register %s with va_minidump: %d\n", s, v16);
      break;
    }
  }
  while ( !v16 );
  v17 = &qword_3A828;
  do
  {
    v17 = (__int64 *)*v17;
    if ( v17 == &qword_3A828 )
      break;
    snprintf(s, 0x20u, "kgsl_pgtable_%d", *((_DWORD *)v17 + 4));
    v18 = *v0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v51 = nullptr;
    scnprintf(&v52, 32, s);
    v51 = v17 - 1;
    LODWORD(v56) = 192;
    v19 = qcom_va_md_add_region(&v51);
    if ( v19 < 0 )
    {
      dev_err(v18, "Failed to register %s with va_minidump: %d\n", s, v19);
      break;
    }
  }
  while ( !v19 );
  v42 = 0;
  next = idr_get_next(v0 + 1398, &v42);
  if ( next )
  {
    v21 = next;
    v22 = "kgsl_sync_timeline_ctxt:%d";
    do
    {
      v49 = 0;
      v50 = 0;
      v23 = *(__int64 **)(v21 + 56);
      *(_QWORD *)v47 = 0;
      v48 = 0;
      v24 = v22;
      snprintf(v47, 0x20u, v22, *(unsigned int *)(v21 + 4));
      v25 = *v0;
      v56 = 0;
      v57 = 0;
      v54 = 0;
      v55 = 0;
      v52 = 0;
      v53 = 0;
      v51 = nullptr;
      scnprintf(&v52, 32, v47);
      v51 = v23;
      LODWORD(v56) = 88;
      v26 = qcom_va_md_add_region(&v51);
      v27 = v26;
      if ( (v26 & 0x80000000) != 0 )
      {
LABEL_53:
        dev_err(v25, "Failed to register %s with va_minidump: %d\n", v47, v27);
        goto LABEL_3;
      }
      if ( v26 )
        goto LABEL_3;
      v30 = (_QWORD *)v23[6];
      v29 = v23 + 6;
      v28 = v30;
      while ( v28 != v29 )
      {
        v31 = (_QWORD *)*v28;
        v32 = v28 - 10;
        snprintf(v47, 0x20u, "kgsl_sync_fence_ctxt:%d", *(_DWORD *)(v21 + 4));
        v25 = *v0;
        v56 = 0;
        v57 = 0;
        v54 = 0;
        v55 = 0;
        v52 = 0;
        v53 = 0;
        v51 = nullptr;
        scnprintf(&v52, 32, v47);
        v51 = v32;
        LODWORD(v56) = 136;
        v33 = qcom_va_md_add_region(&v51);
        v27 = v33;
        if ( (v33 & 0x80000000) != 0 )
          goto LABEL_53;
        v28 = v31;
        if ( v33 )
          goto LABEL_3;
      }
      ++v42;
      v21 = idr_get_next(v0 + 1398, &v42);
      v22 = v24;
    }
    while ( v21 );
  }
  if ( (v0[3003] & 1) == 0 )
  {
    for ( i = (_QWORD *)v0[1639]; i != v0 + 1639; i = (_QWORD *)*i )
    {
      v35 = (const char *)*(i - 1);
      if ( !strcmp(v35, "ringbuffer")
        || !strcmp(v35, "memstore")
        || !strcmp(v35, "scratch")
        || !strcmp(v35, "profile")
        || !strcmp(v35, "profile_desc")
        || !strcmp(v35, "alwayson") )
      {
        snprintf(s, 0x20u, "kgsl_%s", v35);
        v36 = *v0;
        v37 = (__int64 *)*(i - 26);
        v38 = *(i - 22);
        v56 = 0;
        v57 = 0;
        v54 = 0;
        v55 = 0;
        v52 = 0;
        v53 = 0;
        v51 = nullptr;
        scnprintf(&v52, 32, s);
        v51 = v37;
        LODWORD(v56) = v38;
        v39 = qcom_va_md_add_region(&v51);
        if ( (v39 & 0x80000000) != 0 )
        {
          dev_err(v36, "Failed to register %s with va_minidump: %d\n", s, v39);
          goto LABEL_3;
        }
        if ( v39 )
          goto LABEL_3;
      }
    }
  }
  v40 = *(unsigned int (__fastcall **)(_QWORD))(v3 + 208);
  if ( *((_DWORD *)v40 - 1) != -83892780 )
    __break(0x8228u);
  if ( v40(v0) )
    result = 32770;
  else
    result = 1;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
