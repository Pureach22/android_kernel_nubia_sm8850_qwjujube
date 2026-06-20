__int64 __fastcall arm_smmu_device_cfg_probe(_QWORD *a1)
{
  int v2; // w20
  _DWORD **v3; // x8
  _DWORD *v4; // x8
  unsigned int v5; // w0
  unsigned int v6; // w21
  int v7; // w8
  int v8; // w20
  unsigned __int64 v9; // x22
  unsigned int v10; // w20
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x10
  int v17; // w9
  __int64 v18; // x11
  int v19; // w8
  _DWORD **v20; // x8
  _DWORD *v21; // x8
  int v22; // w0
  int v23; // w3
  int v24; // w9
  int v25; // w10
  int v26; // w20
  int v27; // w21
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 result; // x0
  const char *v32; // x2
  __int64 v33; // x0
  __int64 v34; // x0
  unsigned int v35; // w0
  unsigned int v36; // w20
  __int64 v37; // x8
  __int64 v38; // x8
  unsigned int v39; // w8
  unsigned int v40; // w8
  __int64 v41; // x8
  __int64 v42; // x8
  __int64 (__fastcall *v43)(_QWORD); // x8
  int v44; // w8
  __int64 v45; // x9
  int v46; // w8

  v2 = *((_DWORD *)a1 + 8);
  dev_notice(*a1, "probing hardware configuration...\n");
  dev_notice(*a1, "SMMUv%d with:\n");
  v3 = (_DWORD **)a1[6];
  if ( v3 && (v4 = *v3) != nullptr )
  {
    if ( *(v4 - 1) != 616069899 )
      __break(0x8228u);
    v5 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))v4)(a1, 0, 32);
  }
  else
  {
    v5 = readl_relaxed_0((unsigned int *)(a1[1] + 32LL));
  }
  if ( force_stage == 2 )
  {
    v6 = v5 & 0xAFFFFFFF;
    goto LABEL_8;
  }
  if ( force_stage == 1 )
    v5 &= 0xCFFFFFFF;
  v6 = v5;
  if ( (v5 & 0x40000000) == 0 )
  {
LABEL_8:
    if ( (v6 & 0x20000000) == 0 )
      goto LABEL_9;
LABEL_22:
    v12 = *a1;
    *((_DWORD *)a1 + 8) |= 8u;
    dev_notice(v12, "\tstage 2 translation\n");
    if ( (v6 & 0x10000000) == 0 )
      goto LABEL_10;
    goto LABEL_23;
  }
  v11 = *a1;
  *((_DWORD *)a1 + 8) |= 4u;
  dev_notice(v11, "\tstage 1 translation\n");
  if ( (v6 & 0x20000000) != 0 )
    goto LABEL_22;
LABEL_9:
  if ( (v6 & 0x10000000) == 0 )
    goto LABEL_10;
LABEL_23:
  v13 = *a1;
  *((_DWORD *)a1 + 8) |= 0x10u;
  dev_notice(v13, "\tnested translation\n");
LABEL_10:
  v7 = *((_DWORD *)a1 + 8);
  if ( (v7 & 0xC) == 0 )
  {
    dev_err(*a1, "\tno translation support!\n");
    return 4294967277LL;
  }
  v8 = v2 & 1;
  if ( (v6 & 0x40000000) != 0 && ((v6 & 0x4000000) == 0 || *((_DWORD *)a1 + 10) <= 1u) )
  {
    v33 = *a1;
    *((_DWORD *)a1 + 8) = v7 | 0x20;
    dev_notice(v33, "\taddress translation ops\n");
    v9 = v6 & 0x4000;
    if ( !v8 )
      goto LABEL_15;
LABEL_57:
    v32 = (const char *)&unk_17C28;
    goto LABEL_58;
  }
  v9 = v6 & 0x4000;
  if ( v8 )
    goto LABEL_57;
LABEL_15:
  if ( !v9 )
    goto LABEL_16;
  v32 = "non-";
LABEL_58:
  dev_notice(*a1, "\t%scoherent table walk\n", v32);
LABEL_16:
  if ( v8 == (unsigned int)(v9 >> 14) )
  {
    if ( (v6 & 0x100) == 0 )
      goto LABEL_26;
  }
  else
  {
    dev_notice(*a1, "\t(IDR0.CTTW overridden by FW configuration)\n");
    if ( (v6 & 0x100) == 0 )
      goto LABEL_26;
  }
  if ( *((_DWORD *)a1 + 10) == 2 )
  {
    v10 = 0x10000;
    *((_DWORD *)a1 + 8) |= 0x1000u;
    goto LABEL_27;
  }
LABEL_26:
  v10 = 1 << ((v6 >> 9) & 0xF);
LABEL_27:
  *((_WORD *)a1 + 48) = v10 - 1;
  if ( (v6 & 0x8000000) != 0 )
  {
    v29 = *a1;
    v10 = (unsigned __int8)v6;
    *((_DWORD *)a1 + 8) |= 2u;
    if ( !(_BYTE)v6 )
    {
      dev_err(v29, "stream-matching supported, but no SMRs present!\n");
      return 4294967277LL;
    }
    v30 = devm_kmalloc(v29, 8 * (unsigned int)(unsigned __int8)v6, 3520);
    a1[13] = v30;
    if ( !v30 )
      return 4294967284LL;
    dev_notice(*a1, "\tstream matching with %u register groups", (unsigned __int8)v6);
  }
  v14 = devm_kmalloc(*a1, 24LL * v10, 3264);
  a1[14] = v14;
  if ( !v14 )
    return 4294967284LL;
  v15 = 0;
  v16 = v10;
  if ( disable_bypass )
    v17 = 2;
  else
    v17 = 1;
  do
  {
    --v16;
    v18 = a1[14] + v15;
    v15 += 24;
    *(_QWORD *)v18 = 0;
    *(_DWORD *)(v18 + 8) = 0;
    *(_DWORD *)(v18 + 12) = v17;
    *(_QWORD *)(v18 + 16) = 0;
  }
  while ( v16 );
  *((_DWORD *)a1 + 23) = v10;
  _mutex_init(a1 + 15, "&smmu->stream_map_mutex", &arm_smmu_device_cfg_probe___key);
  *((_DWORD *)a1 + 56) = 0;
  if ( (v6 & 0x2000000) == 0 || *((_DWORD *)a1 + 10) <= 1u )
  {
    v19 = *((_DWORD *)a1 + 8);
    *((_DWORD *)a1 + 8) = v19 | 0x400;
    if ( (v6 & 0x1000000) == 0 )
      *((_DWORD *)a1 + 8) = v19 | 0xC00;
  }
  v20 = (_DWORD **)a1[6];
  if ( v20 && (v21 = *v20) != nullptr )
  {
    if ( *(v21 - 1) != 616069899 )
      __break(0x8228u);
    v22 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))v21)(a1, 0, 36);
  }
  else
  {
    v22 = readl_relaxed_0((unsigned int *)(a1[1] + 36LL));
  }
  v23 = *((_DWORD *)a1 + 6);
  v24 = 4 << (((unsigned int)v22 >> 28) & 7);
  if ( v22 < 0 )
    v25 = 16;
  else
    v25 = 12;
  v26 = v22;
  *((_DWORD *)a1 + 7) = v25;
  v27 = 2 << (((unsigned int)v22 >> 28) & 7);
  if ( v23 != v24 << v25 )
    dev_warn(*a1, "SMMU address space size (0x%x) differs from mapped region size (0x%x)!\n", v24 << v25, v23);
  if ( (*((_BYTE *)a1 + 36) & 0x80) != 0 )
    v27 = *((_DWORD *)a1 + 6) >> 1 >> *((_DWORD *)a1 + 7);
  v28 = *a1;
  *((_DWORD *)a1 + 6) = v27;
  *((_DWORD *)a1 + 14) = (unsigned __int8)v26;
  *((_DWORD *)a1 + 15) = BYTE2(v26);
  if ( BYTE2(v26) > (unsigned int)(unsigned __int8)v26 )
  {
    dev_err(v28, "impossible number of S2 context banks!\n");
    return 4294967277LL;
  }
  dev_notice(v28, "\t%u context banks (%u stage-2 only)\n", (unsigned __int8)v26, BYTE2(v26));
  v34 = devm_kmalloc(*a1, 48LL * *((unsigned int *)a1 + 14), 3520);
  a1[10] = v34;
  if ( !v34 )
    return 4294967284LL;
  v35 = arm_smmu_readl((__int64)a1, 0, 40);
  v36 = v35;
  if ( (v35 & 0xF) > 4 )
    v37 = 48;
  else
    v37 = qword_19C38[v35 & 0xF];
  a1[22] = v37;
  if ( (unsigned __int8)((unsigned __int8)v35 >> 4) > 4u )
    v38 = 48;
  else
    v38 = qword_19C38[(unsigned __int8)v35 >> 4];
  a1[23] = v38;
  if ( (v35 & 0x8000) != 0 )
    *((_DWORD *)a1 + 8) |= 0x40u;
  if ( (unsigned int)dma_set_mask_and_coherent(*a1, ~(-1LL << v38)) )
    dev_warn(*a1, "failed to set DMA mask for table walker\n");
  v39 = *((_DWORD *)a1 + 10);
  if ( v39 <= 1 )
  {
    a1[21] = a1[22];
    if ( v39 != 1 )
      goto LABEL_81;
LABEL_80:
    *((_DWORD *)a1 + 8) |= 0x200u;
    goto LABEL_81;
  }
  v40 = (v36 >> 8) & 0xF;
  if ( v40 > 4 )
    v41 = 48;
  else
    v41 = qword_19C38[v40];
  a1[21] = v41;
  if ( (v36 & 0x1000) != 0 )
  {
    *((_DWORD *)a1 + 8) |= 0x80u;
    if ( (v36 & 0x2000) == 0 )
    {
LABEL_79:
      if ( (v36 & 0x4000) == 0 )
        goto LABEL_81;
      goto LABEL_80;
    }
  }
  else if ( (v36 & 0x2000) == 0 )
  {
    goto LABEL_79;
  }
  *((_DWORD *)a1 + 8) |= 0x100u;
  if ( (v36 & 0x4000) != 0 )
    goto LABEL_80;
LABEL_81:
  v42 = a1[6];
  if ( !v42 )
    goto LABEL_86;
  v43 = *(__int64 (__fastcall **)(_QWORD))(v42 + 32);
  if ( !v43 )
    goto LABEL_86;
  if ( *((_DWORD *)v43 - 1) != -1110832593 )
    __break(0x8228u);
  result = v43(a1);
  if ( !(_DWORD)result )
  {
LABEL_86:
    v44 = *((_DWORD *)a1 + 8);
    if ( (v44 & 0x800) != 0 )
      a1[24] |= 0x1111000uLL;
    if ( (v44 & 0x480) != 0 )
    {
      a1[24] |= 0x40201000uLL;
      if ( (v44 & 0x100) == 0 )
      {
LABEL_90:
        if ( (v44 & 0x200) == 0 )
          goto LABEL_92;
        goto LABEL_91;
      }
    }
    else if ( (v44 & 0x100) == 0 )
    {
      goto LABEL_90;
    }
    a1[24] |= 0x2004000uLL;
    if ( (v44 & 0x200) == 0 )
    {
LABEL_92:
      v45 = qword_E08;
      if ( qword_E08 == -1 )
        v45 = 0;
      qword_E08 = a1[24] | v45;
      dev_notice(*a1, "\tSupported page sizes: 0x%08lx\n", a1[24]);
      v46 = *((_DWORD *)a1 + 8);
      if ( (v46 & 4) != 0 )
      {
        dev_notice(*a1, "\tStage-1: %lu-bit VA -> %lu-bit IPA\n", a1[21], a1[22]);
        if ( (a1[4] & 8) == 0 )
          return 0;
      }
      else if ( (v46 & 8) == 0 )
      {
        return 0;
      }
      dev_notice(*a1, "\tStage-2: %lu-bit IPA -> %lu-bit PA\n", a1[22], a1[23]);
      return 0;
    }
LABEL_91:
    a1[24] |= 0x20010000uLL;
    goto LABEL_92;
  }
  return result;
}
