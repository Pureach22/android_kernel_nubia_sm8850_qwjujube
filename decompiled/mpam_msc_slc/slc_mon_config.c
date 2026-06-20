__int64 __fastcall slc_mon_config(__int64 a1, __int64 a2, int *a3)
{
  __int64 v3; // x16
  __int64 v4; // x10
  __int64 result; // x0
  unsigned int v6; // w9
  unsigned int v7; // w8
  __int64 v8; // x12
  __int64 v9; // x13
  int v10; // w15
  __int64 v11; // x16
  int v12; // w14
  int v13; // w13
  _DWORD *v14; // x17
  _DWORD *v15; // x16
  int v16; // w3
  _DWORD *v17; // x4
  _DWORD *v18; // x5
  int v19; // w9
  int v20; // w8
  __int64 *v24; // x1
  unsigned int device_capability; // w0
  int v26; // w9
  int v27; // w8
  int v28; // w0
  __int64 v29; // x8
  __int64 v30; // x10
  __int64 v31; // x0
  __int64 (__fastcall *v32)(__int64, __int64 *, __int64, __int64, __int64); // x8
  int v33; // w0
  int *v34; // x9
  int v35; // w10
  int v36; // w11
  __int64 v37; // x19
  __int64 v38; // x16
  __int64 v39; // x10
  unsigned int v40; // w2
  __int64 v41; // x12
  __int64 v42; // x13
  unsigned int v43; // w8
  int v44; // w15
  __int64 v45; // x16
  int v46; // w14
  int v47; // w13
  _DWORD *v48; // x17
  _DWORD *v49; // x16
  int v50; // w0
  _DWORD *v51; // x1
  _DWORD *v52; // x3
  int v53; // w8
  int v54; // w8
  int v55; // w8
  const char *v56; // x1
  unsigned int v57; // w19
  int v58; // w8
  int v59; // w8
  int v60; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v61; // [xsp+8h] [xbp-28h] BYREF
  __int64 v62; // [xsp+10h] [xbp-20h]
  __int64 v63; // [xsp+18h] [xbp-18h] BYREF
  __int64 v64; // [xsp+20h] [xbp-10h]
  __int64 v65; // [xsp+28h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  if ( !v3 )
    goto LABEL_4;
  v4 = *(_QWORD *)(v3 + 16);
  if ( !v4 || (*(_BYTE *)(v3 + 88) & 2) == 0 )
    goto LABEL_4;
  v60 = 0;
  v6 = *(unsigned __int16 *)(a2 + 6);
  v7 = *(unsigned __int16 *)(a2 + 4);
  if ( *(_DWORD *)v4 <= v6 )
  {
    v56 = "Invalid Client ID %d\n";
    goto LABEL_111;
  }
  v8 = *(_QWORD *)(v4 + 4);
  v9 = v8 + 21LL * *(unsigned __int16 *)(a2 + 6);
  if ( !*(_BYTE *)(v9 + 12) )
  {
    v56 = "Client not enabled for configuration %d\n";
    goto LABEL_111;
  }
  if ( v7 >= *(unsigned __int16 *)(v9 + 2) )
  {
    v56 = "Invalid PART id %d\n";
    goto LABEL_111;
  }
  v10 = *(_DWORD *)(v4 + 32);
  v11 = *(_QWORD *)(v3 + 64);
  v12 = 0;
  v13 = 0;
  v14 = (_DWORD *)(v11 + 24);
  v15 = (_DWORD *)(v11 + 8);
  if ( v10 )
    v15 = nullptr;
  else
    v14 = nullptr;
  while ( 1 )
  {
    v16 = *(unsigned __int16 *)(v8 + 2);
    if ( *(_WORD *)(v8 + 2) )
      break;
LABEL_12:
    ++v12;
    v8 += 21;
    if ( v12 == *(_DWORD *)v4 )
      goto LABEL_95;
  }
  v17 = (_DWORD *)(*(_QWORD *)(v8 + 4) + 12LL);
  while ( 1 )
  {
    if ( v10 )
    {
      if ( !*v17 )
        goto LABEL_16;
      v18 = v14;
      v14 += 22;
    }
    else
    {
      v18 = v15;
      v15 += 8;
    }
    if ( *v18 == v6 && v18[1] == v7 )
      break;
    ++v13;
LABEL_16:
    --v16;
    v17 += 4;
    if ( !v16 )
      goto LABEL_12;
  }
  if ( v13 < 0 )
  {
LABEL_95:
    printk(&unk_8869);
    result = 4294967274LL;
    goto LABEL_5;
  }
  v19 = *a3;
  if ( (unsigned int)(*a3 - 2) < 2 )
  {
    if ( !*(_WORD *)(a2 + 4) )
      goto LABEL_32;
    v56 = "Invalid Part ID %d\n";
LABEL_111:
    dev_err(a1, v56);
    result = 4294967274LL;
    goto LABEL_5;
  }
  if ( v19 == 1 )
  {
    v27 = a3[1];
    if ( v27 != 1 )
    {
      if ( !v27 && !*(_DWORD *)(v4 + 20) )
        goto LABEL_4;
      goto LABEL_32;
    }
    if ( *(_DWORD *)(v4 + 20) < *(_DWORD *)(v4 + 12) )
      goto LABEL_32;
LABEL_4:
    result = 4294967274LL;
    goto LABEL_5;
  }
  if ( v19 )
    goto LABEL_32;
  v20 = a3[1];
  if ( v20 == 1 )
  {
    if ( *(_DWORD *)(v4 + 24) < *(_DWORD *)(v4 + 16) )
      goto LABEL_32;
    goto LABEL_4;
  }
  if ( !v20 && !*(_DWORD *)(v4 + 24) )
    goto LABEL_4;
LABEL_32:
  msc_system_get_mpam_version(2, &v60);
  v24 = (__int64 *)a2;
  if ( !v60 )
    goto LABEL_56;
  device_capability = msc_system_get_device_capability(2, a2, &v63);
  if ( device_capability )
  {
    v57 = device_capability;
LABEL_109:
    printk(&unk_833E);
    result = v57;
    goto LABEL_5;
  }
  v26 = *a3;
  if ( *a3 > 1 )
  {
    v24 = (__int64 *)a2;
    if ( v26 == 2 )
    {
      if ( !v60 || (v64 & 0x400000000LL) == 0 )
        goto LABEL_55;
    }
    else
    {
      if ( v26 != 3 )
        goto LABEL_56;
      if ( !v60 || (v64 & 0x800000000LL) == 0 )
        goto LABEL_55;
    }
    if ( a3[1] )
    {
      if ( !perf_clk_enable )
      {
        v28 = llcc_perf_clk_enable(1, a2);
        v24 = (__int64 *)a2;
        if ( v28 )
          goto LABEL_55;
      }
    }
  }
  else
  {
    v24 = (__int64 *)a2;
    if ( v26 )
    {
      if ( v26 == 1 && (v64 & 0x200000000LL) == 0 )
        goto LABEL_55;
    }
    else if ( (v64 & 0x100000000LL) == 0 )
    {
LABEL_55:
      result = 0xFFFFFFFFLL;
      goto LABEL_5;
    }
  }
LABEL_56:
  v29 = *(_QWORD *)a3;
  v30 = *(_QWORD *)(a1 + 152);
  v61 = *v24;
  v62 = v29;
  if ( !v30 )
  {
    v34 = a3;
    v33 = -22;
LABEL_103:
    v57 = v33;
    if ( (v29 & 0xFFFFFFFE) == 2 && v34[1] && !perf_clk_enable )
      llcc_perf_clk_enable(0, v24);
    goto LABEL_109;
  }
  v31 = *(_QWORD *)(v30 + 48);
  v32 = **(__int64 (__fastcall ***)(__int64, __int64 *, __int64, __int64, __int64))(v30 + 40);
  if ( *((_DWORD *)v32 - 1) != 1737159351 )
    __break(0x8228u);
  v33 = v32(v31, &v61, 0x534C434D50414DLL, 3, 16);
  LODWORD(v29) = *a3;
  v34 = a3;
  if ( v33 )
    goto LABEL_103;
  if ( (v29 & 0xFFFFFFFE) == 2 )
  {
    v35 = a3[1];
    v36 = v35 ? perf_clk_enable + 1 : perf_clk_enable - 1;
    perf_clk_enable = v36;
    if ( !(v35 | v36) )
    {
      v37 = llcc_perfmon_clock;
      if ( llcc_perfmon_clock )
      {
        clk_disable(llcc_perfmon_clock);
        clk_unprepare(v37);
        v34 = a3;
      }
    }
  }
  v38 = *(_QWORD *)(a1 + 152);
  if ( !v38 )
    goto LABEL_131;
  v39 = *(_QWORD *)(v38 + 16);
  if ( !v39 || (*(_BYTE *)(v38 + 88) & 2) == 0 )
    goto LABEL_131;
  v40 = *(unsigned __int16 *)(a2 + 6);
  if ( *(_DWORD *)v39 <= v40 )
  {
    dev_err(a1, "Invalid Client ID %d\n", v40);
    goto LABEL_131;
  }
  v41 = *(_QWORD *)(v39 + 4);
  v42 = v41 + 21LL * *(unsigned __int16 *)(a2 + 6);
  if ( !*(_BYTE *)(v42 + 12) )
  {
    dev_err(a1, "Client not enabled for configuration %d\n", v40);
    goto LABEL_131;
  }
  v43 = *(unsigned __int16 *)(a2 + 4);
  if ( v43 >= *(unsigned __int16 *)(v42 + 2) )
  {
    dev_err(a1, "Invalid PART id %d\n", *(unsigned __int16 *)(a2 + 4));
    goto LABEL_131;
  }
  v44 = *(_DWORD *)(v39 + 32);
  v45 = *(_QWORD *)(v38 + 64);
  v46 = 0;
  v47 = 0;
  v48 = (_DWORD *)(v45 + 24);
  v49 = (_DWORD *)(v45 + 8);
  if ( v44 )
    v49 = nullptr;
  else
    v48 = nullptr;
  while ( 1 )
  {
    v50 = *(unsigned __int16 *)(v41 + 2);
    if ( *(_WORD *)(v41 + 2) )
      break;
LABEL_76:
    ++v46;
    result = 0;
    v41 += 21;
    if ( v46 == *(_DWORD *)v39 )
      goto LABEL_5;
  }
  v51 = (_DWORD *)(*(_QWORD *)(v41 + 4) + 12LL);
  while ( 2 )
  {
    if ( !v44 )
    {
      v52 = v49;
      v49 += 8;
      goto LABEL_85;
    }
    if ( !*v51 )
    {
LABEL_80:
      --v50;
      v51 += 4;
      if ( !v50 )
        goto LABEL_76;
      continue;
    }
    break;
  }
  v52 = v48;
  v48 += 22;
LABEL_85:
  if ( *v52 != v40 || v52[1] != v43 )
  {
    ++v47;
    goto LABEL_80;
  }
  if ( v47 < 0 )
    goto LABEL_131;
  v53 = *v34;
  if ( (unsigned int)(*v34 - 2) < 2 )
  {
    v55 = v34[1];
    if ( v55 )
    {
      if ( v55 != 1 )
        goto LABEL_126;
      goto LABEL_125;
    }
    goto LABEL_118;
  }
  if ( v53 == 1 )
  {
    v58 = v34[1];
    if ( v58 == 1 )
    {
      ++*(_DWORD *)(v39 + 20);
      goto LABEL_124;
    }
    if ( v58 )
      goto LABEL_126;
    --*(_DWORD *)(v39 + 20);
LABEL_118:
    v55 = -1;
LABEL_125:
    *(_DWORD *)(v39 + 28) += v55;
    goto LABEL_126;
  }
  if ( v53 )
    goto LABEL_126;
  v54 = v34[1];
  if ( v54 == 1 )
  {
    ++*(_DWORD *)(v39 + 24);
LABEL_124:
    v55 = 1;
    goto LABEL_125;
  }
  if ( !v54 )
  {
    --*(_DWORD *)(v39 + 24);
    v55 = -1;
    goto LABEL_125;
  }
LABEL_126:
  v59 = *(_DWORD *)(v39 + 28);
  if ( v34[1] )
  {
    if ( v59 == 1 )
      _module_get(&_this_module);
  }
  else if ( !v59 )
  {
    module_put(&_this_module);
  }
LABEL_131:
  result = 0;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
