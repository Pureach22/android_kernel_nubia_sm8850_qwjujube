__int64 __fastcall dsi_pll_parse_dfps_data(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x0
  unsigned __int64 v5; // x22
  int v6; // w3
  __int64 v7; // x3
  __int64 v8; // x3
  __int64 v9; // x3
  __int64 v10; // x3
  int v11; // w3
  unsigned __int64 v12; // x0
  __int64 v13; // x0
  unsigned __int64 v14; // x0
  unsigned __int64 *address; // x0
  unsigned __int64 v16; // x22
  unsigned __int64 v17; // x21
  unsigned __int64 v18; // x0
  __int64 v19; // x3
  __int64 v20; // x3
  unsigned int v21; // w23
  __int64 v22; // x3
  __int64 v23; // x3
  unsigned __int64 v24; // x0
  unsigned __int64 v25; // x2
  unsigned __int64 v26; // x0
  unsigned __int64 v27; // x0
  _DWORD *v28; // x8
  unsigned int v29; // w14
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x9
  unsigned __int64 v32; // x10
  unsigned __int64 v33; // x11
  __int64 v34; // x14
  _DWORD *v35; // x14
  __int64 v36; // x1
  __int64 v37; // x3
  unsigned __int64 StatusReg; // x23
  __int64 v39; // x24
  __int64 (__fastcall *v40)(_QWORD); // x0
  int v41; // w3
  __int64 v42; // x8
  __int64 v43; // x9
  __int64 v44; // x20
  unsigned __int64 v45; // x19
  unsigned __int64 v46; // x21
  int v47; // w3
  __int64 v48; // x3
  int v49; // [xsp+4h] [xbp-6Ch] BYREF
  __int64 v50; // [xsp+8h] [xbp-68h] BYREF
  __int16 v51; // [xsp+10h] [xbp-60h]
  unsigned __int64 v52; // [xsp+18h] [xbp-58h] BYREF
  __int64 v53; // [xsp+20h] [xbp-50h]
  __int64 v54; // [xsp+28h] [xbp-48h]
  __int64 v55; // [xsp+30h] [xbp-40h]
  __int64 v56; // [xsp+38h] [xbp-38h]
  __int64 v57; // [xsp+40h] [xbp-30h]
  __int64 v58; // [xsp+48h] [xbp-28h]
  __int64 v59; // [xsp+50h] [xbp-20h]
  __int64 v60; // [xsp+58h] [xbp-18h]
  __int64 v61; // [xsp+60h] [xbp-10h]
  __int64 v62; // [xsp+68h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a2 + 180) & 1) != 0 )
    goto LABEL_51;
  v2 = result;
  v3 = *(_QWORD *)(result + 760);
  v49 = 0;
  v51 = 0;
  v50 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v3, "pll_codes_region", 0, 0, 0, &v52) )
    v5 = 0;
  else
    v5 = v52;
  if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( a2 )
      v7 = *(unsigned int *)(a2 + 100);
    else
      v7 = 0xFFFFFFFFLL;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: of_parse_phandle failed\n", v7);
    goto LABEL_32;
  }
  of_get_property(v5, "reg", &v49);
  if ( v49 <= 0 )
  {
    if ( a2 )
      v8 = *(unsigned int *)(a2 + 100);
    else
      v8 = 0xFFFFFFFFLL;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: invalid property length\n", v8);
    goto LABEL_32;
  }
  if ( (of_property_read_variable_u32_array(v5, "reg", &v50, 2, 0) & 0x80000000) != 0 )
  {
    if ( a2 )
      v9 = *(unsigned int *)(a2 + 100);
    else
      v9 = 0xFFFFFFFFLL;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: fail to get pll_codes data header\n", v9);
    goto LABEL_32;
  }
  if ( (unsigned __int16)v50 != 22083 )
  {
    if ( a2 )
      v10 = *(unsigned int *)(a2 + 100);
    else
      v10 = 0xFFFFFFFFLL;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: pll codes magic id not match\n", v10);
    goto LABEL_32;
  }
  if ( !BYTE2(v50) )
  {
    if ( a2 )
      v11 = *(_DWORD *)(a2 + 100);
    else
      v11 = -1;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: DSI_PLL_%d: unsupported pll trim codes version:%d\n",
      v11,
      0);
    goto LABEL_32;
  }
  if ( WORD2(v50) <= 9u )
  {
    if ( a2 )
      v6 = *(_DWORD *)(a2 + 100);
    else
      v6 = -1;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: invalid header size:%d\n", v6, WORD2(v50));
LABEL_32:
    v12 = 0;
    goto LABEL_33;
  }
  if ( WORD2(v50) == 10 )
  {
    if ( a2 )
      v36 = *(unsigned int *)(a2 + 100);
    else
      v36 = 0xFFFFFFFFLL;
    printk(&unk_22C01A, v36);
    goto LABEL_32;
  }
  if ( 14LL * BYTE3(v50) + 10 != WORD2(v50) )
  {
    if ( a2 )
      v23 = *(unsigned int *)(a2 + 100);
    else
      v23 = 0xFFFFFFFFLL;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: num_entries not match with size\n", v23);
    goto LABEL_32;
  }
  v21 = WORD2(v50) + 3;
  v17 = v21 & 0x1FFFC;
  if ( (unsigned int)v17 > v49 )
  {
    if ( a2 )
      v22 = *(unsigned int *)(a2 + 100);
    else
      v22 = 0xFFFFFFFFLL;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: pll code bigger than node space\n", v22);
    goto LABEL_32;
  }
  v24 = _kmalloc_noprof(v21 & 0x1FFFC, 3520);
  if ( !v24 || v24 >= 0xFFFFFFFFFFFFF001LL )
  {
    v46 = v24;
    if ( a2 )
      v47 = *(_DWORD *)(a2 + 100);
    else
      v47 = -1;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: fail to alloc memory for pll codes\n", v47);
    v12 = v46;
LABEL_33:
    kfree(v12);
    v13 = *(_QWORD *)(v2 + 760);
    v50 = 0;
    v60 = 0;
    v61 = 0;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    if ( (unsigned int)_of_parse_phandle_with_args(v13, "memory-region", 0, 0, 0, &v52) )
      v14 = 0;
    else
      v14 = v52;
    if ( v14 && v14 < 0xFFFFFFFFFFFFF001LL )
    {
      address = (unsigned __int64 *)_of_get_address();
      if ( address )
      {
        LODWORD(v16) = v50;
        LODWORD(v17) = bswap64(*address);
        result = memremap((unsigned int)v17, (unsigned int)v50, 1);
        if ( !result )
          goto LABEL_102;
        v2 = result;
        v18 = _kmalloc_cache_noprof(msleep, 3520, 324);
        *(_QWORD *)(a2 + 152) = v18;
        if ( !v18 )
          goto LABEL_97;
LABEL_41:
        if ( v18 < 0xFFFFFFFFFFFFF001LL )
        {
          _memcpy_fromio();
LABEL_101:
          result = memunmap(v2);
LABEL_102:
          v42 = (unsigned int)v17 >> 12;
          v43 = (unsigned int)(v16 + v17) >> 12;
          if ( (unsigned int)v42 < (unsigned int)v43 )
          {
            v44 = v43 - v42;
            v45 = (v42 << 6) | 0xFFFFFFFEC0000000LL;
            do
            {
              result = free_reserved_page(v45 - ((__int64)memstart_addr >> 12 << 6));
              --v44;
              v45 += 64LL;
            }
            while ( v44 );
          }
          goto LABEL_51;
        }
LABEL_97:
        if ( a2 )
          v41 = *(_DWORD *)(a2 + 100);
        else
          v41 = -1;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: pll_res->dfps allocate failed\n", v41);
        goto LABEL_101;
      }
      if ( a2 )
        v20 = *(unsigned int *)(a2 + 100);
      else
        v20 = 0xFFFFFFFFLL;
      result = drm_dev_printk(
                 0,
                 &unk_248D72,
                 "*ERROR* [msm-dsi-error]: DSI_PLL_%d: failed to parse the dfps memory address\n",
                 v20);
    }
    else
    {
      if ( a2 )
        v19 = *(unsigned int *)(a2 + 100);
      else
        v19 = 0xFFFFFFFFLL;
      result = drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: DSI_PLL_%d: of_parse_phandle failed\n", v19);
    }
    goto LABEL_51;
  }
  v25 = v24;
  v26 = v5;
  v16 = v25;
  if ( (of_property_read_variable_u32_array(v26, "reg", v25, v21 >> 2, 0) & 0x80000000) != 0 )
  {
    if ( a2 )
      v37 = *(unsigned int *)(a2 + 100);
    else
      v37 = 0xFFFFFFFFLL;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: fail to get pll_codes data\n", v37);
    goto LABEL_114;
  }
  v27 = _kmalloc_cache_noprof(msleep, 3520, 324);
  v28 = (_DWORD *)v27;
  *(_QWORD *)(a2 + 152) = v27;
  if ( !v27 || v27 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( a2 )
      v48 = *(unsigned int *)(a2 + 100);
    else
      v48 = 0xFFFFFFFFLL;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: pll_res->dfps allocate failed\n", v48);
LABEL_114:
    v12 = v16;
    goto LABEL_33;
  }
  v29 = BYTE3(v50);
  if ( BYTE3(v50) )
  {
    v30 = 0;
    v31 = 0;
    v32 = v17 - 11;
    v33 = 18;
    while ( v17 > v33 - 8 )
    {
      if ( *(_DWORD *)(a2 + 100) == *(unsigned __int8 *)(v16 + v33 - 8) )
      {
        v34 = *(_QWORD *)(a2 + 152) + 20 * v31;
        *(_DWORD *)(v34 + 4) = 1;
        v35 = (_DWORD *)(v34 + 4);
        if ( v32 < 4 )
          break;
        if ( v17 < v33 - 7 )
          break;
        v35[1] = *(_DWORD *)(v16 + v33 - 7);
        if ( v17 <= v33 - 2 )
          break;
        v35[2] = *(unsigned __int8 *)(v16 + v33 - 2);
        if ( v17 <= v33 - 1 )
          break;
        v35[3] = *(unsigned __int8 *)(v16 + v33 - 1);
        if ( v17 <= v33 )
          break;
        v35[4] = *(unsigned __int8 *)(v16 + v33);
        if ( v31 > 0xE )
        {
          LODWORD(v31) = 16;
LABEL_94:
          v28 = *(_DWORD **)(a2 + 152);
          goto LABEL_95;
        }
        v29 = BYTE3(v50);
        ++v31;
      }
      ++v30;
      v33 += 14LL;
      v32 -= 14LL;
      if ( v30 >= v29 )
        goto LABEL_94;
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v39 = *(_QWORD *)(StatusReg + 80);
    v40 = msleep;
    *(_QWORD *)(StatusReg + 80) = &dsi_pll_parse_dfps__alloc_tag;
    v18 = _kmalloc_cache_noprof(v40, 3520, 324);
    *(_QWORD *)(StatusReg + 80) = v39;
    *(_QWORD *)(a2 + 152) = v18;
    if ( !v18 )
      goto LABEL_97;
    goto LABEL_41;
  }
  LODWORD(v31) = 0;
LABEL_95:
  *v28 = v31;
  result = kfree(v16);
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
