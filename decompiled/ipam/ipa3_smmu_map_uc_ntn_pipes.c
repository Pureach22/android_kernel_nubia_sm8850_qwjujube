__int64 __fastcall ipa3_smmu_map_uc_ntn_pipes(__int64 a1, char a2)
{
  unsigned int v2; // w8
  __int64 v4; // x8
  unsigned int v6; // w21
  int v7; // w22
  __int64 v8; // x0
  const char *v9; // x4
  __int64 v10; // x0
  const char *v11; // x4
  unsigned int v12; // w0
  __int64 v13; // x7
  __int64 v14; // x8
  unsigned __int64 v15; // x5
  __int64 v16; // x9
  __int64 v17; // x0
  const char *v18; // x4
  __int64 v19; // x0
  __int64 v20; // x8
  const char *v21; // x4
  __int64 v22; // x8
  int v23; // w11
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  unsigned int v31; // w0
  unsigned int v32; // w0
  const char *v33; // x22
  unsigned int v34; // w21
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  unsigned int v40; // w0
  unsigned int v41; // w0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 smmu_domain; // x0
  const void *v46; // x21
  int v47; // w23
  const char *v48; // x24
  unsigned int v49; // w0
  __int64 *v50; // x9
  __int64 v51; // x10
  __int64 v52; // x22
  int v53; // w11
  __int64 v54; // x8
  __int64 v55; // x28
  __int64 v56; // x0
  __int64 v57; // x0
  unsigned int v58; // w0
  unsigned int v59; // w28
  __int64 v60; // x9
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  const char *v64; // x19
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x8
  __int64 v69; // x0
  __int64 v70; // x0
  const char *v71; // x22
  __int64 v72; // x8
  __int64 v73; // x0
  __int64 v74; // x0
  const char *v75; // x22
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x0
  const char *v79; // x22
  __int64 v80; // x8
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x8
  __int64 v84; // x0
  __int64 v85; // x0
  unsigned int v86; // w21
  __int64 v87; // x8
  __int64 v88; // x0
  __int64 v89; // x0
  unsigned int v90; // w1
  char v91; // w8
  __int64 v92; // x0
  __int64 v93; // x3
  unsigned int v94; // w1
  char v95; // w2
  unsigned __int64 v97; // [xsp+0h] [xbp-10h] BYREF
  __int64 v98; // [xsp+8h] [xbp-8h]

  v98 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 76);
  v97 = 0;
  if ( v2 > 0x1000 )
  {
    printk(&unk_3B8ACD, "ipa3_smmu_map_uc_ntn_pipes");
    v61 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v62 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v62 )
      {
        ipc_log_string(v62, "ipa %s:%d invalid data buff size\n", "ipa3_smmu_map_uc_ntn_pipes", 289);
        v61 = ipa3_ctx;
      }
      v63 = *(_QWORD *)(v61 + 34160);
      if ( v63 )
        ipc_log_string(v63, "ipa %s:%d invalid data buff size\n", "ipa3_smmu_map_uc_ntn_pipes", 289);
    }
    goto LABEL_136;
  }
  v4 = ipa3_ctx;
  v6 = *(_DWORD *)(ipa3_ctx + 43224);
  v7 = (a2 & 1) == 0;
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      if ( (a2 & 1) != 0 )
        v9 = "map";
      else
        v9 = "unmap";
      ipc_log_string(v8, "ipa %s:%d  %s uC regs, smmu_mapped %d\n", "ipa3_smmu_map_uc_ntn_pipes", 298, v9, v6);
      v4 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v4 + 34160);
    if ( v10 )
    {
      if ( (a2 & 1) != 0 )
        v11 = "map";
      else
        v11 = "unmap";
      ipc_log_string(
        v10,
        "ipa %s:%d  %s uC regs, smmu_mapped %d\n",
        "ipa3_smmu_map_uc_ntn_pipes",
        298,
        v11,
        *(unsigned int *)(v4 + 43224));
    }
  }
  if ( v6 == v7 )
  {
    v12 = ipa3_smmu_map_peer_reg(*(_QWORD *)(a1 + 80) & 0xFFFFFFFFFFFFF000LL, a2 & 1, 3u);
    if ( v12 )
    {
      if ( (a2 & 1) != 0 )
        v64 = "map";
      else
        v64 = "unmap";
      v34 = v12;
      printk(&unk_3A43F0, "ipa3_smmu_map_uc_ntn_pipes");
      v65 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v66 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v66 )
        {
          ipc_log_string(v66, "ipa %s:%d failed to %s uC regs %d\n", "ipa3_smmu_map_uc_ntn_pipes", 306, v64, v34);
          v65 = ipa3_ctx;
        }
        v67 = *(_QWORD *)(v65 + 34160);
        if ( v67 )
          ipc_log_string(v67, "ipa %s:%d failed to %s uC regs %d\n", "ipa3_smmu_map_uc_ntn_pipes", 306, v64, v34);
      }
      goto LABEL_150;
    }
    v14 = ipa3_ctx;
    v15 = *(_QWORD *)(a1 + 80) & 0xFFFFFFFFFFFFF000LL;
    v16 = ipa3_ctx + 43216;
    *(_QWORD *)(ipa3_ctx + 43216) = v15;
    if ( v14 )
    {
      v17 = *(_QWORD *)(v14 + 34152);
      if ( v17 )
      {
        if ( (a2 & 1) != 0 )
          v18 = "map";
        else
          v18 = "unmap";
        ipc_log_string(
          v17,
          "ipa %s:%d  %s ntn_reg_base_ptr_pa regs 0X%0llx smmu_mapped %d\n",
          "ipa3_smmu_map_uc_ntn_pipes",
          317,
          v18,
          v15,
          *(_DWORD *)(v16 + 8));
        v14 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v14 + 34160);
      if ( v19 )
      {
        v20 = v14 + 43216;
        if ( (a2 & 1) != 0 )
          v21 = "map";
        else
          v21 = "unmap";
        ipc_log_string(
          v19,
          "ipa %s:%d  %s ntn_reg_base_ptr_pa regs 0X%0llx smmu_mapped %d\n",
          "ipa3_smmu_map_uc_ntn_pipes",
          317,
          v21,
          *(_QWORD *)v20,
          *(unsigned int *)(v20 + 8),
          v13,
          v97,
          v98);
      }
    }
  }
  v22 = ipa3_ctx;
  v23 = *(_DWORD *)(ipa3_ctx + 43224);
  if ( (a2 & 1) != 0 )
  {
    *(_DWORD *)(ipa3_ctx + 43224) = v23 + 1;
    if ( v22 )
    {
      v24 = *(_QWORD *)(v22 + 34152);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d uc_ntn_ctx.smmu_mapped %d\n", "ipa3_smmu_map_uc_ntn_pipes", 323, v23 + 1);
        v22 = ipa3_ctx;
      }
      v25 = *(_QWORD *)(v22 + 34160);
      if ( v25 )
        ipc_log_string(
          v25,
          "ipa %s:%d uc_ntn_ctx.smmu_mapped %d\n",
          "ipa3_smmu_map_uc_ntn_pipes",
          323,
          *(unsigned int *)(v22 + 43224));
    }
  }
  else
  {
    if ( !v23 )
    {
      printk(&unk_3E43CD, "ipa3_smmu_map_uc_ntn_pipes");
      v68 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v69 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v69 )
        {
          ipc_log_string(
            v69,
            "ipa %s:%d Invalid smmu_mapped %d\n",
            "ipa3_smmu_map_uc_ntn_pipes",
            327,
            *(_DWORD *)(ipa3_ctx + 43224));
          v68 = ipa3_ctx;
        }
        v70 = *(_QWORD *)(v68 + 34160);
        if ( v70 )
        {
          ipc_log_string(
            v70,
            "ipa %s:%d Invalid smmu_mapped %d\n",
            "ipa3_smmu_map_uc_ntn_pipes",
            327,
            *(_DWORD *)(v68 + 43224));
          v34 = 0;
          goto LABEL_150;
        }
      }
      goto LABEL_106;
    }
    *(_DWORD *)(ipa3_ctx + 43224) = v23 - 1;
    if ( v22 )
    {
      v26 = *(_QWORD *)(v22 + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d uc_ntn_ctx.smmu_mapped %d\n", "ipa3_smmu_map_uc_ntn_pipes", 332, v23 - 1);
        v22 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v22 + 34160);
      if ( v27 )
        ipc_log_string(
          v27,
          "ipa %s:%d uc_ntn_ctx.smmu_mapped %d\n",
          "ipa3_smmu_map_uc_ntn_pipes",
          332,
          *(unsigned int *)(v22 + 43224));
    }
  }
  v28 = ipa3_ctx;
  if ( *(_BYTE *)(a1 + 4) == 1 )
  {
    if ( ipa3_ctx )
    {
      v29 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v29 )
      {
        ipc_log_string(v29, "ipa %s:%d smmu is enabled on EMAC\n", "ipa3_smmu_map_uc_ntn_pipes", 337);
        v28 = ipa3_ctx;
      }
      v30 = *(_QWORD *)(v28 + 34160);
      if ( v30 )
        ipc_log_string(v30, "ipa %s:%d smmu is enabled on EMAC\n", "ipa3_smmu_map_uc_ntn_pipes", 337);
    }
    v31 = ipa3_smmu_map_peer_buff(*(_QWORD *)(a1 + 16), *(_DWORD *)(a1 + 32), a2 & 1, *(_QWORD *)(a1 + 24), 3u);
    if ( v31 )
    {
      if ( (a2 & 1) != 0 )
        v71 = "map";
      else
        v71 = "unmap";
      v34 = v31;
      printk(&unk_3C7A5F, "ipa3_smmu_map_uc_ntn_pipes");
      v72 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v73 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v73 )
        {
          ipc_log_string(v73, "ipa %s:%d failed to %s ntn ring %d\n", "ipa3_smmu_map_uc_ntn_pipes", 343, v71, v34);
          v72 = ipa3_ctx;
        }
        v74 = *(_QWORD *)(v72 + 34160);
        if ( v74 )
          ipc_log_string(v74, "ipa %s:%d failed to %s ntn ring %d\n", "ipa3_smmu_map_uc_ntn_pipes", 343, v71, v34);
      }
      goto LABEL_149;
    }
    v32 = ipa3_smmu_map_peer_buff(*(_QWORD *)(a1 + 48), 4 * *(_DWORD *)(a1 + 72), a2 & 1, *(_QWORD *)(a1 + 56), 3u);
    if ( v32 )
    {
      if ( (a2 & 1) != 0 )
        v33 = "map";
      else
        v33 = "unmap";
      v34 = v32;
      printk(&unk_3FBDA6, "ipa3_smmu_map_uc_ntn_pipes");
      v35 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v36 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v36 )
        {
          ipc_log_string(v36, "ipa %s:%d failed to %s pool buffs %d\n", "ipa3_smmu_map_uc_ntn_pipes", 352, v33, v34);
          v35 = ipa3_ctx;
        }
        v37 = *(_QWORD *)(v35 + 34160);
        if ( v37 )
          ipc_log_string(v37, "ipa %s:%d failed to %s pool buffs %d\n", "ipa3_smmu_map_uc_ntn_pipes", 352, v33, v34);
      }
LABEL_145:
      v92 = *(_QWORD *)(a1 + 16);
      v93 = *(_QWORD *)(a1 + 24);
      v94 = *(_DWORD *)(a1 + 32);
      v95 = (a2 & 1) == 0;
      goto LABEL_148;
    }
  }
  else
  {
    if ( ipa3_ctx )
    {
      v38 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v38 )
      {
        ipc_log_string(v38, "ipa %s:%d smmu is disabled on EMAC\n", "ipa3_smmu_map_uc_ntn_pipes", 356);
        v28 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v28 + 34160);
      if ( v39 )
        ipc_log_string(v39, "ipa %s:%d smmu is disabled on EMAC\n", "ipa3_smmu_map_uc_ntn_pipes", 356);
    }
    v40 = ipa3_smmu_map_peer_buff(*(_QWORD *)(a1 + 8), *(_DWORD *)(a1 + 32), a2 & 1, 0, 3u);
    if ( v40 )
    {
      if ( (a2 & 1) != 0 )
        v75 = "map";
      else
        v75 = "unmap";
      v34 = v40;
      printk(&unk_3C7A5F, "ipa3_smmu_map_uc_ntn_pipes");
      v76 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v77 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v77 )
        {
          ipc_log_string(v77, "ipa %s:%d failed to %s ntn ring %d\n", "ipa3_smmu_map_uc_ntn_pipes", 361, v75, v34);
          v76 = ipa3_ctx;
        }
        v78 = *(_QWORD *)(v76 + 34160);
        if ( v78 )
          ipc_log_string(v78, "ipa %s:%d failed to %s ntn ring %d\n", "ipa3_smmu_map_uc_ntn_pipes", 361, v75, v34);
      }
      goto LABEL_149;
    }
    v41 = ipa3_smmu_map_peer_buff(*(_QWORD *)(a1 + 40), 4 * *(_DWORD *)(a1 + 72), a2 & 1, 0, 3u);
    if ( v41 )
    {
      if ( (a2 & 1) != 0 )
        v79 = "map";
      else
        v79 = "unmap";
      v34 = v41;
      printk(&unk_3FBDA6, "ipa3_smmu_map_uc_ntn_pipes");
      v80 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v81 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v81 )
        {
          ipc_log_string(v81, "ipa %s:%d failed to %s pool buffs %d\n", "ipa3_smmu_map_uc_ntn_pipes", 368, v79, v34);
          v80 = ipa3_ctx;
        }
        v82 = *(_QWORD *)(v80 + 34160);
        if ( v82 )
          ipc_log_string(v82, "ipa %s:%d failed to %s pool buffs %d\n", "ipa3_smmu_map_uc_ntn_pipes", 368, v79, v34);
      }
      goto LABEL_147;
    }
  }
  v42 = ipa3_ctx;
  if ( *(_BYTE *)(ipa3_ctx + 43310) == 1 )
  {
    if ( ipa3_ctx )
    {
      v43 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v43 )
      {
        ipc_log_string(v43, "ipa %s:%d AP SMMU is set to s1 bypass\n", "ipa3_smmu_map_uc_ntn_pipes", 374);
        v42 = ipa3_ctx;
      }
      v44 = *(_QWORD *)(v42 + 34160);
      if ( v44 )
      {
        ipc_log_string(v44, "ipa %s:%d AP SMMU is set to s1 bypass\n", "ipa3_smmu_map_uc_ntn_pipes", 374);
        v34 = 0;
        goto LABEL_150;
      }
    }
LABEL_106:
    v34 = 0;
    goto LABEL_150;
  }
  smmu_domain = ipa3_get_smmu_domain();
  if ( !smmu_domain )
  {
    printk(&unk_3DDF55, "ipa3_smmu_map_uc_ntn_pipes");
    v83 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v84 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v84 )
      {
        ipc_log_string(v84, "ipa %s:%d invalid smmu domain\n", "ipa3_smmu_map_uc_ntn_pipes", 380);
        v83 = ipa3_ctx;
      }
      v85 = *(_QWORD *)(v83 + 34160);
      if ( v85 )
        ipc_log_string(v85, "ipa %s:%d invalid smmu domain\n", "ipa3_smmu_map_uc_ntn_pipes", 380);
    }
LABEL_136:
    v34 = -22;
    goto LABEL_150;
  }
  if ( !*(_DWORD *)(a1 + 72) )
    goto LABEL_106;
  v46 = (const void *)smmu_domain;
  v47 = 0;
  if ( (a2 & 1) != 0 )
    v48 = "mapping";
  else
    v48 = "unmapping";
  while ( 1 )
  {
    v50 = (__int64 *)(*(_QWORD *)(a1 + 64) + 16LL * v47);
    v52 = *v50;
    v51 = v50[1];
    v53 = (v51 & 0xFFF) + *(_DWORD *)(a1 + 76);
    v97 = v51 & 0xFFFFFFFFFFFFF000LL;
    v54 = ipa3_ctx;
    v55 = (v53 + 4095) & 0xFFFFF000;
    if ( ipa3_ctx )
    {
      v56 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v56 )
      {
        ipc_log_string(
          v56,
          "ipa %s:%d %s 0x%llx to 0x%pa size %d\n",
          "ipa3_smmu_map_uc_ntn_pipes",
          390,
          v48,
          v52 & 0xFFFFFFFFFFFFF000LL,
          &v97,
          v55);
        v54 = ipa3_ctx;
      }
      v57 = *(_QWORD *)(v54 + 34160);
      if ( v57 )
        ipc_log_string(
          v57,
          "ipa %s:%d %s 0x%llx to 0x%pa size %d\n",
          "ipa3_smmu_map_uc_ntn_pipes",
          390,
          v48,
          v52 & 0xFFFFFFFFFFFFF000LL,
          &v97,
          v55);
    }
    if ( (a2 & 1) != 0 )
      break;
    v58 = iommu_unmap(v46, v52 & 0xFFFFFFFFFFFFF000LL, v55);
    if ( *(_DWORD *)(a1 + 76) != v58 )
    {
      v59 = v58;
      printk(&unk_3D52EA, "ipa3_smmu_map_uc_ntn_pipes");
      v58 = v59;
      v60 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        if ( *(_QWORD *)(ipa3_ctx + 34152) )
        {
          ipc_log_string(
            *(_QWORD *)(ipa3_ctx + 34152),
            "ipa %s:%d Fail to unmap 0x%llx\n",
            "ipa3_smmu_map_uc_ntn_pipes",
            399,
            v52);
          v58 = v59;
          v60 = ipa3_ctx;
        }
        if ( *(_QWORD *)(v60 + 34160) )
        {
          ipc_log_string(
            *(_QWORD *)(v60 + 34160),
            "ipa %s:%d Fail to unmap 0x%llx\n",
            "ipa3_smmu_map_uc_ntn_pipes",
            399,
            v52);
          v58 = v59;
        }
      }
    }
    if ( v58 )
      goto LABEL_143;
LABEL_73:
    if ( (unsigned int)++v47 >= *(_DWORD *)(a1 + 72) )
      goto LABEL_106;
  }
  v49 = ipa3_iommu_map(v46, v52 & 0xFFFFFFFFFFFFF000LL, v97, v55, 3u);
  if ( !v49 )
    goto LABEL_73;
  v86 = v49;
  printk(&unk_3C683A, "ipa3_smmu_map_uc_ntn_pipes");
  v87 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v88 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v88 )
    {
      ipc_log_string(v88, "ipa %s:%d Fail to map 0x%llx\n", "ipa3_smmu_map_uc_ntn_pipes", 395, v52);
      v87 = ipa3_ctx;
    }
    v89 = *(_QWORD *)(v87 + 34160);
    if ( v89 )
      ipc_log_string(v89, "ipa %s:%d Fail to map 0x%llx\n", "ipa3_smmu_map_uc_ntn_pipes", 395, v52);
  }
  v58 = v86;
LABEL_143:
  v34 = v58;
  v90 = 4 * *(_DWORD *)(a1 + 72);
  v91 = a2 ^ 1;
  if ( (*(_BYTE *)(a1 + 4) & 1) != 0 )
  {
    ipa3_smmu_map_peer_buff(*(_QWORD *)(a1 + 48), v90, v91 & 1, 0, 3u);
    goto LABEL_145;
  }
  ipa3_smmu_map_peer_buff(*(_QWORD *)(a1 + 40), v90, v91 & 1, 0, 3u);
LABEL_147:
  v92 = *(_QWORD *)(a1 + 8);
  v94 = *(_DWORD *)(a1 + 32);
  v95 = (a2 & 1) == 0;
  v93 = 0;
LABEL_148:
  ipa3_smmu_map_peer_buff(v92, v94, v95, v93, 3u);
LABEL_149:
  ipa3_smmu_map_peer_reg(*(_QWORD *)(a1 + 80) & 0xFFFFFFFFFFFFF000LL, (a2 & 1) == 0, 3u);
LABEL_150:
  _ReadStatusReg(SP_EL0);
  return v34;
}
