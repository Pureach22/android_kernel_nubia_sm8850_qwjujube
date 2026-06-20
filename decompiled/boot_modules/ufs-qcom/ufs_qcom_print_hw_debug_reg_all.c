_QWORD *__fastcall ufs_qcom_print_hw_debug_reg_all(_QWORD *result, __int64 a2, _DWORD *a3)
{
  _QWORD *v4; // x21
  __int64 v5; // x24
  int v7; // w0
  unsigned int v8; // w8
  unsigned int i; // w22
  unsigned int j; // w22
  unsigned int k; // w22
  unsigned int m; // w22
  int v13; // w0
  __int64 v14; // x1
  __int64 v15; // x1
  __int64 v16; // x1
  __int64 v17; // x1
  __int64 v18; // x1
  __int64 v19; // x1
  __int64 v20; // x1
  unsigned int v21; // w8
  _QWORD *v22; // x0
  __int64 v23; // x2
  __int64 v24; // x1
  __int64 v25; // x1
  __int64 v26; // x1
  int v27; // w0
  __int64 v28; // x1
  __int64 v29; // x1
  __int64 v30; // x1
  __int64 v31; // x1
  __int64 v32; // x1
  __int64 v33; // x1
  __int64 v34; // x1
  __int64 v35; // x1

  if ( !result )
    return (_QWORD *)printk(&unk_1AB41, "ufs_qcom_print_hw_debug_reg_all");
  v4 = result;
  if ( !a3 )
    return (_QWORD *)dev_err(result[8], "%s: print_fn is NULL\n", "ufs_qcom_print_hw_debug_reg_all");
  v5 = result[23];
  if ( (*(_BYTE *)(v5 + 184) & 1) != 0 )
  {
    v7 = readl((unsigned int *)(*result + 220LL));
    writel(v7 | 0x20000u, *v4 + 220LL);
    v8 = *(unsigned __int8 *)(v5 + 174);
    if ( v8 < 6 )
    {
      if ( v8 >= 3 )
        v24 = 7424;
      else
        v24 = 6400;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v24,
        32,
        "UFS_UFS_DBG_RD_EDTL_RAM ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v25 = 6400;
      else
        v25 = 5376;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v25,
        128,
        "UFS_UFS_DBG_RD_DESC_RAM ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v26 = 6912;
      else
        v26 = 5888;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v26,
        64,
        "UFS_UFS_DBG_RD_PRDT_RAM ",
        a2);
      v27 = readl((unsigned int *)(*v4 + 220LL));
      writel(v27 & 0xFFFDFFFF, *v4 + 220LL);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v28 = 3072;
      else
        v28 = 2048;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v28,
        44,
        "UFS_UFS_DBG_RD_REG_OCSC ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v29 = 1280;
      else
        v29 = 256;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v29,
        4,
        "UFS_DBG_RD_REG_UAWM ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v30 = 1536;
      else
        v30 = 512;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v30,
        4,
        "UFS_DBG_RD_REG_UARM ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v31 = 1792;
      else
        v31 = 768;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v31,
        48,
        "UFS_DBG_RD_REG_TXUC ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v32 = 2048;
      else
        v32 = 1024;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v32,
        27,
        "UFS_DBG_RD_REG_RXUC ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v33 = 2304;
      else
        v33 = 1280;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v33,
        19,
        "UFS_DBG_RD_REG_DFC ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v34 = 2560;
      else
        v34 = 1536;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v34,
        34,
        "UFS_DBG_RD_REG_TRLUT ",
        a2);
      v21 = *(unsigned __int8 *)(v5 + 174);
      v22 = v4;
      v23 = 9;
    }
    else
    {
      for ( i = 3; i != 32771; i += 256 )
      {
        writel(i, *v4 + 4096LL);
        if ( *(a3 - 1) != -1686493801 )
          __break(0x8233u);
        ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
          v4,
          4132,
          8,
          "UFS_UFS_DBG_RD_DESC_RAM ",
          a2);
      }
      for ( j = 4; j != 16388; j += 256 )
      {
        writel(j, *v4 + 4096LL);
        if ( *(a3 - 1) != -1686493801 )
          __break(0x8233u);
        ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
          v4,
          4132,
          8,
          "UFS_UFS_DBG_RD_PRDT_RAM ",
          a2);
      }
      for ( k = 5; k != 16389; k += 256 )
      {
        writel(k, *v4 + 4096LL);
        if ( *(a3 - 1) != -1686493801 )
          __break(0x8233u);
        ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
          v4,
          4132,
          8,
          " UFS_UFS_DBG_RD_RESP_RAM ",
          a2);
      }
      for ( m = 6; m != 16390; m += 256 )
      {
        writel(m, *v4 + 4096LL);
        if ( *(a3 - 1) != -1686493801 )
          __break(0x8233u);
        ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
          v4,
          4132,
          8,
          "UFS_UFS_DBG_RD_EDTL_RAM ",
          a2);
      }
      v13 = readl((unsigned int *)(*v4 + 220LL));
      writel(v13 & 0xFFFDFFFF, *v4 + 220LL);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v14 = 3072;
      else
        v14 = 2048;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v14,
        64,
        "UFS_UFS_DBG_RD_REG_OCSC ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v15 = 1280;
      else
        v15 = 256;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v15,
        64,
        "UFS_DBG_RD_REG_UAWM ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v16 = 1536;
      else
        v16 = 512;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v16,
        64,
        "UFS_DBG_RD_REG_UARM ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v17 = 1792;
      else
        v17 = 768;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v17,
        64,
        "UFS_DBG_RD_REG_TXUC ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v18 = 2048;
      else
        v18 = 1024;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v18,
        64,
        "UFS_DBG_RD_REG_RXUC ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v19 = 2304;
      else
        v19 = 1280;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v19,
        64,
        "UFS_DBG_RD_REG_DFC ",
        a2);
      if ( *(unsigned __int8 *)(v5 + 174) >= 3u )
        v20 = 2560;
      else
        v20 = 1536;
      if ( *(a3 - 1) != -1686493801 )
        __break(0x8233u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
        v4,
        v20,
        64,
        "UFS_DBG_RD_REG_TRLUT ",
        a2);
      v21 = *(unsigned __int8 *)(v5 + 174);
      v22 = v4;
      v23 = 64;
    }
    if ( v21 >= 3 )
      v35 = 2816;
    else
      v35 = 1792;
    if ( *(a3 - 1) != -1686493801 )
      __break(0x8233u);
    return (_QWORD *)((__int64 (__fastcall *)(_QWORD *, __int64, __int64, const char *, __int64))a3)(
                       v22,
                       v35,
                       v23,
                       "UFS_DBG_RD_REG_TMRLUT ",
                       a2);
  }
  return result;
}
