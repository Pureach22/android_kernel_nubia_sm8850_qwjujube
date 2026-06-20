__int64 __fastcall ufs_qcom_dump_dbg_regs(_QWORD *a1)
{
  _QWORD *v1; // x20
  __int64 v2; // x21
  __int64 v3; // x24
  __int64 v4; // x26
  __int64 v5; // x28
  __int64 v6; // x21
  int v7; // w0
  __int64 v8; // x21
  int v9; // w0
  __int64 v10; // x21
  int v11; // w0
  __int64 v12; // x21
  int v13; // w0
  __int64 v14; // x21
  int v15; // w0
  __int64 result; // x0
  __int64 v17; // x24
  int v18; // w0
  unsigned int v19; // w8
  unsigned int i; // w21
  unsigned int j; // w21
  unsigned int k; // w21
  unsigned int m; // w21
  int v24; // w0
  __int64 v25; // x1
  __int64 v26; // x1
  __int64 v27; // x1
  __int64 v28; // x1
  __int64 v29; // x1
  __int64 v30; // x1
  __int64 v31; // x1
  _QWORD *v32; // x0
  __int64 v33; // x2
  __int64 v34; // x1
  __int64 v35; // x1
  __int64 v36; // x1
  __int64 v37; // x1
  int v38; // w0
  __int64 v39; // x1
  __int64 v40; // x1
  __int64 v41; // x1
  __int64 v42; // x1
  __int64 v43; // x1
  __int64 v44; // x1
  __int64 v45; // x1
  __int64 v46; // x22
  char *v47; // x23
  unsigned __int64 n; // x26
  __int64 v49; // x19
  __int64 v50; // x25
  int v51; // w8
  __int64 v52; // x19
  __int64 v53; // [xsp+0h] [xbp-10h]
  __int64 vars10; // [xsp+20h] [xbp+10h]
  __int64 vars20; // [xsp+30h] [xbp+20h]
  __int64 vars30; // [xsp+40h] [xbp+30h]
  __int64 _58; // [xsp+58h] [xbp+48h]
  _QWORD *vars50; // [xsp+60h] [xbp+50h]

  if ( !a1 )
  {
    __break(0x800u);
    goto LABEL_88;
  }
  v5 = a1[23];
  v1 = a1;
  *(_BYTE *)(v5 + 496) = 1;
  v4 = *(_QWORD *)(v5 + 8);
  v6 = a1[8];
  v7 = readl((unsigned int *)(*a1 + 9984LL));
  dev_err(v6, "HW_H8_ENTER_CNT=%d\n", v7);
  v8 = v1[8];
  v9 = readl((unsigned int *)(*v1 + 9996LL));
  dev_err(v8, "HW_H8_EXIT_CNT=%d\n", v9);
  v10 = v1[8];
  v11 = readl((unsigned int *)(*v1 + 9988LL));
  dev_err(v10, "SW_H8_ENTER_CNT=%d\n", v11);
  v12 = v1[8];
  v13 = readl((unsigned int *)(*v1 + 10000LL));
  dev_err(v12, "SW_H8_EXIT_CNT=%d\n", v13);
  v14 = v1[8];
  v15 = readl((unsigned int *)(*v1 + 9992LL));
  dev_err(v14, "SW_AFTER_HW_H8_ENTER_CNT=%d\n", v15);
  ufshcd_dump_regs(v1, 192, 64, "HCI Vendor Specific Registers ");
  result = ufshcd_dump_regs(v1, 9728, 116, "HCI Shared ICE Registers ");
  if ( *((_BYTE *)v1 + 4893) == 1 )
    result = ufshcd_dump_regs(v1, 3328, 256, "HCI MCQ Debug Registers ");
  v17 = v1[23];
  if ( (*(_BYTE *)(v17 + 184) & 1) != 0 )
  {
    v18 = readl((unsigned int *)(*v1 + 220LL));
    writel(v18 | 0x20000, (unsigned int *)(*v1 + 220LL));
    v19 = *(unsigned __int8 *)(v17 + 174);
    if ( v19 < 6 )
    {
      if ( v19 >= 3 )
        v35 = 7424;
      else
        v35 = 6400;
      ufshcd_dump_regs(v1, v35, 128, "UFS_UFS_DBG_RD_EDTL_RAM ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v36 = 6400;
      else
        v36 = 5376;
      ufshcd_dump_regs(v1, v36, 512, "UFS_UFS_DBG_RD_DESC_RAM ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v37 = 6912;
      else
        v37 = 5888;
      ufshcd_dump_regs(v1, v37, 256, "UFS_UFS_DBG_RD_PRDT_RAM ");
      v38 = readl((unsigned int *)(*v1 + 220LL));
      writel(v38 & 0xFFFDFFFF, (unsigned int *)(*v1 + 220LL));
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v39 = 3072;
      else
        v39 = 2048;
      ufshcd_dump_regs(v1, v39, 176, "UFS_UFS_DBG_RD_REG_OCSC ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v40 = 1280;
      else
        v40 = 256;
      ufshcd_dump_regs(v1, v40, 16, "UFS_DBG_RD_REG_UAWM ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v41 = 1536;
      else
        v41 = 512;
      ufshcd_dump_regs(v1, v41, 16, "UFS_DBG_RD_REG_UARM ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v42 = 1792;
      else
        v42 = 768;
      ufshcd_dump_regs(v1, v42, 192, "UFS_DBG_RD_REG_TXUC ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v43 = 2048;
      else
        v43 = 1024;
      ufshcd_dump_regs(v1, v43, 108, "UFS_DBG_RD_REG_RXUC ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v44 = 2304;
      else
        v44 = 1280;
      ufshcd_dump_regs(v1, v44, 76, "UFS_DBG_RD_REG_DFC ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v45 = 2560;
      else
        v45 = 1536;
      ufshcd_dump_regs(v1, v45, 136, "UFS_DBG_RD_REG_TRLUT ");
      v32 = v1;
      v33 = 36;
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v34 = 2816;
      else
        v34 = 1792;
    }
    else
    {
      for ( i = 3; i != 32771; i += 256 )
      {
        writel(i, (unsigned int *)(*v1 + 4096LL));
        ufshcd_dump_regs(v1, 4132, 32, "UFS_UFS_DBG_RD_DESC_RAM ");
      }
      for ( j = 4; j != 16388; j += 256 )
      {
        writel(j, (unsigned int *)(*v1 + 4096LL));
        ufshcd_dump_regs(v1, 4132, 32, "UFS_UFS_DBG_RD_PRDT_RAM ");
      }
      for ( k = 5; k != 16389; k += 256 )
      {
        writel(k, (unsigned int *)(*v1 + 4096LL));
        ufshcd_dump_regs(v1, 4132, 32, " UFS_UFS_DBG_RD_RESP_RAM ");
      }
      for ( m = 6; m != 16390; m += 256 )
      {
        writel(m, (unsigned int *)(*v1 + 4096LL));
        ufshcd_dump_regs(v1, 4132, 32, "UFS_UFS_DBG_RD_EDTL_RAM ");
      }
      v24 = readl((unsigned int *)(*v1 + 220LL));
      writel(v24 & 0xFFFDFFFF, (unsigned int *)(*v1 + 220LL));
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v25 = 3072;
      else
        v25 = 2048;
      ufshcd_dump_regs(v1, v25, 256, "UFS_UFS_DBG_RD_REG_OCSC ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v26 = 1280;
      else
        v26 = 256;
      ufshcd_dump_regs(v1, v26, 256, "UFS_DBG_RD_REG_UAWM ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v27 = 1536;
      else
        v27 = 512;
      ufshcd_dump_regs(v1, v27, 256, "UFS_DBG_RD_REG_UARM ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v28 = 1792;
      else
        v28 = 768;
      ufshcd_dump_regs(v1, v28, 256, "UFS_DBG_RD_REG_TXUC ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v29 = 2048;
      else
        v29 = 1024;
      ufshcd_dump_regs(v1, v29, 256, "UFS_DBG_RD_REG_RXUC ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v30 = 2304;
      else
        v30 = 1280;
      ufshcd_dump_regs(v1, v30, 256, "UFS_DBG_RD_REG_DFC ");
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v31 = 2560;
      else
        v31 = 1536;
      ufshcd_dump_regs(v1, v31, 256, "UFS_DBG_RD_REG_TRLUT ");
      v32 = v1;
      v33 = 256;
      if ( *(unsigned __int8 *)(v17 + 174) >= 3u )
        v34 = 2816;
      else
        v34 = 1792;
    }
    result = ufshcd_dump_regs(v32, v34, v33, "UFS_DBG_RD_REG_TMRLUT ");
  }
  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFF0100) != 0 )
    goto LABEL_85;
  usleep_range_state(1000, 1100, 2);
  if ( *((_BYTE *)v1 + 4893) == 1 )
  {
    ufsqcom_dump_regs((__int64)v1, 0, 0x400u, (__int64)"MCQ HCI 1da0000-1da03f0 ", 1);
    usleep_range_state(1000, 1100, 2);
    ufsqcom_dump_regs((__int64)v1, 1024, 0x400u, (__int64)"MCQ HCI 1da0400-1da07f0 ", 1);
    usleep_range_state(1000, 1100, 2);
    ufsqcom_dump_regs((__int64)v1, 0, 0x14u, (__int64)"MCQ VS 1da4000-1da4010 ", 6);
    usleep_range_state(1000, 1100, 2);
    ufsqcom_dump_regs((__int64)v1, 0, 0x400u, (__int64)"MCQ SQD 1da5000-1da53f0 ", 2);
    usleep_range_state(1000, 1100, 2);
    ufsqcom_dump_regs((__int64)v1, 1024, 0x400u, (__int64)"MCQ SQD 1da5400-1da57f0 ", 2);
    usleep_range_state(1000, 1100, 2);
    ufsqcom_dump_regs((__int64)v1, 2048, 0x400u, (__int64)"MCQ SQD 1da5800-1da5bf0 ", 2);
    usleep_range_state(1000, 1100, 2);
    ufsqcom_dump_regs((__int64)v1, 3072, 0x400u, (__int64)"MCQ SQD 1da5c00-1da5ff0 ", 2);
    usleep_range_state(1000, 1100, 2);
    ufsqcom_dump_regs((__int64)v1, 4096, 0x400u, (__int64)"MCQ SQD 1da6000-1da63f0 ", 2);
    usleep_range_state(1000, 1100, 2);
    ufsqcom_dump_regs((__int64)v1, 5120, 0x400u, (__int64)"MCQ SQD 1da6400-1da67f0 ", 2);
    usleep_range_state(1000, 1100, 2);
    ufsqcom_dump_regs((__int64)v1, 6144, 0x400u, (__int64)"MCQ SQD 1da6800-1da6bf0 ", 2);
    usleep_range_state(1000, 1100, 2);
    ufsqcom_dump_regs((__int64)v1, 7168, 0x400u, (__int64)"MCQ SQD 1da6c00-1da6ff0 ", 2);
    usleep_range_state(1000, 1100, 2);
  }
  ufshcd_dump_regs(v1, 232, 4, "UFS_TEST_BUS ");
  usleep_range_state(1000, 1100, 2);
  v2 = v1[23];
  v46 = _kmalloc_cache_noprof(devm_ioremap_resource, 3264, 1024);
  if ( v46 )
  {
LABEL_76:
    v53 = v4;
    v47 = nullptr;
    for ( n = 0; n != 12; ++n )
    {
      if ( n > 0xB )
      {
        v49 = 32;
      }
      else
      {
        v49 = dword_18610[n];
        v47 = off_18640[n];
      }
      v50 = 0;
      *(_BYTE *)(v2 + 188) = n;
      do
      {
        *(_BYTE *)(v2 + 189) = v50;
        ufs_qcom_testbus_config(v2);
        *(_DWORD *)(v46 + 4 * v50++) = readl((unsigned int *)(*v1 + 232LL));
      }
      while ( v49 != v50 );
      print_hex_dump(&unk_19A10, v47, 2, 16, 4, v46, 4 * v49, 0);
    }
    kfree(v46);
    v4 = v53;
  }
  while ( 1 )
  {
    usleep_range_state(1000, 1100, 2);
    result = ufs_qcom_phy_dbg_register_dump(v4);
LABEL_85:
    v51 = *(unsigned __int8 *)(v5 + 497);
    v1 = vars50;
    v2 = _58;
    v3 = vars30;
    v4 = vars20;
    v5 = vars10;
    if ( v51 != 1 )
      return result;
LABEL_88:
    __break(0x800u);
    v52 = *(_QWORD *)(v3 + 80);
    *(_QWORD *)(v3 + 80) = &ufs_qcom_print_all_testbus__alloc_tag;
    v46 = _kmalloc_cache_noprof(devm_ioremap_resource, 3264, 1024);
    *(_QWORD *)(v3 + 80) = v52;
    if ( v46 )
      goto LABEL_76;
  }
}
