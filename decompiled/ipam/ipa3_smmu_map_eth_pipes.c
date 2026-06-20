__int64 __fastcall ipa3_smmu_map_eth_pipes(
        __int64 a1,
        int a2,
        char a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        float a8)
{
  unsigned int v9; // w4
  __int64 v10; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  int v15; // w9
  unsigned int v16; // w0
  __int64 v17; // x0
  __int64 result; // x0
  unsigned int v19; // w23
  unsigned int v20; // w22
  char *smmu_ctx; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  const char *v29; // x23
  unsigned int v30; // w21
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  const void *eth_smmu_domain; // x21
  __int64 v37; // x8
  __int64 v38; // x0
  const char *v39; // x4
  __int64 v40; // x0
  __int64 v41; // x5
  const char *v42; // x1
  __int64 v43; // x3
  const char *v44; // x4
  const char *v45; // x8
  unsigned int v46; // w22
  unsigned __int64 v47; // x27
  __int64 *v48; // x8
  __int64 v49; // x9
  __int64 v50; // x24
  __int64 v51; // x0
  __int64 v52; // x27
  __int64 v53; // x0
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  const char *v60; // x19
  unsigned int v61; // w20
  __int64 v62; // x8
  __int64 v63; // x0
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  const char *v70; // [xsp+8h] [xbp-18h]
  __int64 v71[2]; // [xsp+10h] [xbp-10h] BYREF

  v71[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_DWORD *)(a1 + 88);
  v71[0] = 0;
  if ( v9 > 0x1000 )
  {
    printk(&unk_3AF865, "ipa3_smmu_map_eth_pipes");
    v37 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_114;
    v38 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v38 )
    {
      if ( *(_DWORD *)(a1 + 16) )
        v39 = "RX";
      else
        v39 = "TX";
      ipc_log_string(
        v38,
        "ipa %s:%d %s: invalid data buff size %d\n",
        "ipa3_smmu_map_eth_pipes",
        492,
        v39,
        *(unsigned int *)(a1 + 88));
      v37 = ipa3_ctx;
    }
    v40 = *(_QWORD *)(v37 + 34160);
    if ( !v40 )
      goto LABEL_114;
    v41 = *(unsigned int *)(a1 + 88);
    v42 = "ipa %s:%d %s: invalid data buff size %d\n";
    v43 = 492;
    if ( *(_DWORD *)(a1 + 16) )
      v44 = "RX";
    else
      v44 = "TX";
    goto LABEL_113;
  }
  v10 = ipa3_ctx;
  if ( *(_BYTE *)(ipa3_ctx + 43310) != 1 )
  {
    v16 = ipa3_smmu_map_peer_buff(*(_QWORD *)(a1 + 32), *(_DWORD *)(a1 + 48), a3 & 1, *(_QWORD *)(a1 + 40), 0);
    v15 = 0;
    if ( !v16 )
      goto LABEL_10;
    if ( (a3 & 1) != 0 )
      v60 = "map";
    else
      v60 = "unmap";
    v61 = v16;
    printk(&unk_3EC430, "ipa3_smmu_map_eth_pipes");
    v62 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_114;
    v63 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v63 )
    {
      ipc_log_string(v63, "ipa %s:%d failed to %s ring %d\n", "ipa3_smmu_map_eth_pipes", 509, v60, v61);
      v62 = ipa3_ctx;
    }
    v40 = *(_QWORD *)(v62 + 34160);
    if ( !v40 )
    {
LABEL_114:
      result = 4294967274LL;
      goto LABEL_104;
    }
    v42 = "ipa %s:%d failed to %s ring %d\n";
    v43 = 509;
    v44 = v60;
    v41 = v61;
LABEL_113:
    ipc_log_string(v40, v42, "ipa3_smmu_map_eth_pipes", v43, v44, v41);
    goto LABEL_114;
  }
  if ( !ipa3_ctx )
  {
LABEL_8:
    v15 = -22;
LABEL_10:
    v10 = ipa3_ctx;
    goto LABEL_11;
  }
  v13 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v13 )
  {
    ipc_log_string(v13, "ipa %s:%d AP SMMU is set to s1 bypass\n", "ipa3_smmu_map_eth_pipes", 497);
    v10 = ipa3_ctx;
  }
  v14 = *(_QWORD *)(v10 + 34160);
  if ( v14 )
  {
    ipc_log_string(v14, "ipa %s:%d AP SMMU is set to s1 bypass\n", "ipa3_smmu_map_eth_pipes", 497);
    goto LABEL_8;
  }
  v15 = -22;
LABEL_11:
  if ( *(_DWORD *)(v10 + 32240) <= 0x14u )
  {
    if ( (*(_BYTE *)(v10 + 43310) & 1) == 0 )
      goto LABEL_25;
LABEL_17:
    if ( v10 )
    {
      v17 = *(_QWORD *)(v10 + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d SMMU cb for buffer is set to s1 bypass\n", "ipa3_smmu_map_eth_pipes", 515);
        v10 = ipa3_ctx;
      }
      result = *(_QWORD *)(v10 + 34160);
      if ( !result )
        goto LABEL_104;
      ipc_log_string(result, "ipa %s:%d SMMU cb for buffer is set to s1 bypass\n", "ipa3_smmu_map_eth_pipes", 515);
    }
LABEL_103:
    result = 0;
    goto LABEL_104;
  }
  if ( (unsigned int)(a2 - 48) <= 0x3D && ((1LL << ((unsigned __int8)a2 - 48)) & 0x30C0000000000003LL) != 0 )
  {
    if ( (*(_BYTE *)(v10 + 43315) & 1) != 0 )
      goto LABEL_17;
  }
  else if ( (a2 & 0xFFFFFFFE) == 0x74 && *(_BYTE *)(v10 + 43316) == 1 )
  {
    goto LABEL_17;
  }
LABEL_25:
  v19 = a2 - 48;
  if ( (unsigned int)(a2 - 48) <= 0x3D && ((1LL << v19) & 0x30C0000000000003LL) != 0 )
  {
    v20 = 5;
  }
  else
  {
    if ( (a2 & 0xFFFFFFFE) != 0x74 )
    {
      v30 = v15;
      printk(&unk_3F7FEB, "ipa3_smmu_map_eth_pipes");
      v67 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v68 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v68 )
        {
          ipc_log_string(v68, "ipa %s:%d invalid CB type %d\n", "ipa3_smmu_map_eth_pipes", 521, 7);
          v67 = ipa3_ctx;
        }
        v69 = *(_QWORD *)(v67 + 34160);
        if ( v69 )
          ipc_log_string(v69, "ipa %s:%d invalid CB type %d\n", "ipa3_smmu_map_eth_pipes", 521, 7);
      }
      goto LABEL_123;
    }
    v20 = 6;
  }
  smmu_ctx = ipa3_get_smmu_ctx(v20, a4, a5, a6, a7, a8);
  v22 = ipa3_ctx;
  if ( smmu_ctx[52] != 1 )
  {
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(
          v24,
          "ipa %s:%d SMMU cb %d is not shared, continue to map buffers\n",
          "ipa3_smmu_map_eth_pipes",
          530,
          v20);
        v22 = ipa3_ctx;
      }
      v25 = *(_QWORD *)(v22 + 34160);
      if ( v25 )
        ipc_log_string(
          v25,
          "ipa %s:%d SMMU cb %d is not shared, continue to map buffers\n",
          "ipa3_smmu_map_eth_pipes",
          530,
          v20);
    }
    v26 = ipa3_ctx;
    if ( *(_BYTE *)(a1 + 52) == 1 )
    {
      if ( ipa3_ctx )
      {
        v27 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v27 )
        {
          ipc_log_string(v27, "ipa %s:%d buffer pool valid\n", "ipa3_smmu_map_eth_pipes", 534);
          v26 = ipa3_ctx;
        }
        v28 = *(_QWORD *)(v26 + 34160);
        if ( v28 )
          ipc_log_string(v28, "ipa %s:%d buffer pool valid\n", "ipa3_smmu_map_eth_pipes", 534);
      }
      result = ipa3_smmu_map_peer_buff(*(_QWORD *)(a1 + 56), *(_DWORD *)(a1 + 88), a3 & 1, *(_QWORD *)(a1 + 64), v20);
      if ( !(_DWORD)result )
        goto LABEL_104;
      if ( (a3 & 1) != 0 )
        v29 = "map";
      else
        v29 = "unmap";
      v30 = result;
      printk(&unk_3DB5D1, "ipa3_smmu_map_eth_pipes");
      v31 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v32 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v32 )
        {
          ipc_log_string(
            v32,
            "ipa %s:%d failed to %s buffer %d cb_type %d\n",
            "ipa3_smmu_map_eth_pipes",
            543,
            v29,
            v30,
            v20);
          v31 = ipa3_ctx;
        }
        v33 = *(_QWORD *)(v31 + 34160);
        if ( v33 )
          ipc_log_string(
            v33,
            "ipa %s:%d failed to %s buffer %d cb_type %d\n",
            "ipa3_smmu_map_eth_pipes",
            543,
            v29,
            v30,
            v20);
      }
LABEL_123:
      ipa3_smmu_map_peer_buff(*(_QWORD *)(a1 + 32), *(_DWORD *)(a1 + 48), (a3 & 1) == 0, *(_QWORD *)(a1 + 40), 0);
      result = v30;
      goto LABEL_104;
    }
    if ( ipa3_ctx )
    {
      v34 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v34 )
      {
        ipc_log_string(v34, "ipa %s:%d buffer pool not valid\n", "ipa3_smmu_map_eth_pipes", 547);
        v26 = ipa3_ctx;
      }
      v35 = *(_QWORD *)(v26 + 34160);
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d buffer pool not valid\n", "ipa3_smmu_map_eth_pipes", 547);
        v26 = ipa3_ctx;
      }
    }
    if ( *(_DWORD *)(v26 + 32240) > 0x14u )
    {
      if ( v19 <= 0x3D && ((1LL << v19) & 0x30C0000000000003LL) != 0 )
      {
        eth_smmu_domain = (const void *)ipa3_get_eth_smmu_domain();
        if ( !eth_smmu_domain )
        {
LABEL_117:
          printk(&unk_3DDF55, "ipa3_smmu_map_eth_pipes");
          v64 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v65 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v65 )
            {
              ipc_log_string(v65, "ipa %s:%d invalid smmu domain\n", "ipa3_smmu_map_eth_pipes", 550);
              v64 = ipa3_ctx;
            }
            v66 = *(_QWORD *)(v64 + 34160);
            if ( v66 )
              ipc_log_string(v66, "ipa %s:%d invalid smmu domain\n", "ipa3_smmu_map_eth_pipes", 550);
          }
          v30 = -22;
          goto LABEL_123;
        }
      }
      else
      {
        if ( (a2 & 0xFFFFFFFE) != 0x74 )
          goto LABEL_117;
        eth_smmu_domain = (const void *)ipa3_get_eth1_smmu_domain();
        if ( !eth_smmu_domain )
          goto LABEL_117;
      }
    }
    else
    {
      eth_smmu_domain = (const void *)ipa3_get_smmu_domain();
      if ( !eth_smmu_domain )
        goto LABEL_117;
    }
    if ( *(_DWORD *)(a1 + 72) )
    {
      v45 = "unmapping";
      v46 = 0;
      v47 = 0;
      if ( (a3 & 1) != 0 )
        v45 = "mapping";
      v70 = v45;
      do
      {
        v48 = (__int64 *)(*(_QWORD *)(a1 + 80) + 16LL * (int)v46);
        v50 = *v48;
        v49 = v48[1];
        v71[0] = v49 & 0xFFFFFFFFFFFFF000LL;
        if ( v47 == (v50 & 0xFFFFFFFFFFFFF000LL) )
        {
          if ( ipa3_ctx )
          {
            v51 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v51 )
              ipc_log_string(
                v51,
                "ipa %s:%d current buffer and previous are on the same page, skip page mapping\n",
                "ipa3_smmu_map_eth_pipes",
                565);
          }
        }
        else
        {
          v52 = ((v49 & 0xFFF) + *(_DWORD *)(a1 + 88) + 4095) & 0xFFFFF000;
          if ( ipa3_ctx )
          {
            v53 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v53 )
              ipc_log_string(
                v53,
                "ipa %s:%d %s 0x%llx to 0x%pa size %d\n",
                "ipa3_smmu_map_eth_pipes",
                570,
                v70,
                v50 & 0xFFFFFFFFFFFFF000LL,
                v71,
                v52);
          }
          if ( (a3 & 1) != 0 )
          {
            if ( (unsigned int)ipa3_iommu_map(eth_smmu_domain, v50 & 0xFFFFFFFFFFFFF000LL, v71[0], v52, 3u) )
            {
              printk(&unk_3C683A, "ipa3_smmu_map_eth_pipes");
              v57 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v58 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v58 )
                {
                  ipc_log_string(v58, "ipa %s:%d Fail to map 0x%llx\n", "ipa3_smmu_map_eth_pipes", 575, v50);
                  v57 = ipa3_ctx;
                }
                v59 = *(_QWORD *)(v57 + 34160);
                if ( v59 )
                  ipc_log_string(v59, "ipa %s:%d Fail to map 0x%llx\n", "ipa3_smmu_map_eth_pipes", 575, v50);
              }
            }
          }
          else if ( (_DWORD)v52 != (unsigned int)iommu_unmap(eth_smmu_domain, v50 & 0xFFFFFFFFFFFFF000LL, v52) )
          {
            printk(&unk_3D52EA, "ipa3_smmu_map_eth_pipes");
            v54 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v55 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v55 )
              {
                ipc_log_string(v55, "ipa %s:%d Fail to unmap 0x%llx\n", "ipa3_smmu_map_eth_pipes", 579, v50);
                v54 = ipa3_ctx;
              }
              v56 = *(_QWORD *)(v54 + 34160);
              if ( v56 )
                ipc_log_string(v56, "ipa %s:%d Fail to unmap 0x%llx\n", "ipa3_smmu_map_eth_pipes", 579, v50);
            }
          }
          v47 = v50 & 0xFFFFFFFFFFFFF000LL;
        }
        ++v46;
      }
      while ( v46 < *(_DWORD *)(a1 + 72) );
    }
    goto LABEL_103;
  }
  if ( !ipa3_ctx )
    goto LABEL_103;
  v23 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v23 )
  {
    ipc_log_string(v23, "ipa %s:%d SMMU cb %d is shared, no need to map buffers\n", "ipa3_smmu_map_eth_pipes", 526, v20);
    v22 = ipa3_ctx;
  }
  result = *(_QWORD *)(v22 + 34160);
  if ( result )
  {
    ipc_log_string(
      result,
      "ipa %s:%d SMMU cb %d is shared, no need to map buffers\n",
      "ipa3_smmu_map_eth_pipes",
      526,
      v20);
    goto LABEL_103;
  }
LABEL_104:
  _ReadStatusReg(SP_EL0);
  return result;
}
