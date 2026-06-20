__int64 __fastcall dwc3_msm_notify_event(__int64 *a1, int a2, unsigned int a3)
{
  __int64 *v3; // x20
  __int64 result; // x0
  __int64 v5; // x19
  unsigned __int64 v6; // x20
  int v7; // w24
  unsigned __int16 v8; // w23
  __int64 v9; // x0
  unsigned int v10; // w21
  __int64 v11; // x22
  __int64 v12; // x0
  __int64 v13; // x0
  const char **v14; // x21
  char v15; // w0
  _QWORD *v16; // x21
  __int64 v17; // x19
  __int64 v18; // x8
  __int64 v19; // x22
  _QWORD *v20; // x26
  __int64 v21; // x8
  char v22; // w20
  int v23; // w0
  __int64 v24; // x8
  __int64 v25; // x0
  void (*v26)(void); // x8
  __int64 v27; // x21
  int v28; // w0
  __int64 v29; // x21
  __int64 v30; // x0
  int v31; // w3
  int v32; // w4
  int v33; // w3
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  unsigned int v36; // w20
  int v37; // w21
  unsigned int v38; // w22
  __int64 v39; // x23
  unsigned int v40; // w8
  unsigned int i; // w21
  __int64 v42; // x9
  unsigned int v43; // w20
  unsigned int v44; // w21
  __int64 v45; // x8
  _DWORD *v46; // x8
  __int64 v47; // x20
  __int64 v48; // x22
  int v49; // w0
  _DWORD *v50; // x8
  __int64 v51; // x19
  __int64 v52; // x20
  int v53; // w0
  unsigned __int8 *j; // x8
  unsigned __int64 v55; // x2
  __int64 v56; // x1
  const char *v57; // x4
  const char *v58; // x5
  int v59; // w0
  __int64 v60; // x2
  __int64 v61; // x1
  void *v62; // x0
  char v63; // w23
  const char *v64; // x0
  const char *v65; // x2
  unsigned __int64 v72; // x9
  int v73; // [xsp+Ch] [xbp-94h] BYREF
  _QWORD v74[18]; // [xsp+10h] [xbp-90h] BYREF

  v3 = a1;
  v74[17] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = a1[46];
  v5 = *(_QWORD *)(*(_QWORD *)(result + 96) + 152LL);
  if ( a2 > 10 )
  {
    if ( a2 > 13 )
    {
      switch ( a2 )
      {
        case 14:
          if ( *(_QWORD *)(v5 + 864) )
          {
            v40 = *(_DWORD *)(v5 + 856);
            if ( v40 )
            {
              for ( i = 0; i < v40; ++i )
              {
                v42 = *(_QWORD *)(*(_QWORD *)(v5 + 864) + 8LL * (int)i);
                if ( v42 )
                {
                  result = dma_free_attrs(v3[47], *(unsigned int *)(v42 + 16), *(_QWORD *)v42, *(_QWORD *)(v42 + 32), 0);
                  v40 = *(_DWORD *)(v5 + 856);
                }
              }
            }
LABEL_96:
            v56 = *(_QWORD *)(v5 + 1208);
            if ( v56 )
            {
              result = dma_unmap_page_attrs(v3[47], v56, 8, 2, 0);
              *(_QWORD *)(v5 + 1208) = 0;
            }
          }
          break;
        case 15:
          v46 = *(_DWORD **)(v5 + 1136);
          if ( v46 )
          {
            v47 = *(_QWORD *)(v5 + 8);
            v48 = (unsigned int)(*v46 + 1017856);
            v49 = readl(v47 + v48);
            writel(v49 | 2u, v47 + v48);
            readl(v47 + v48);
            v50 = *(_DWORD **)(v5 + 1136);
            v51 = *(_QWORD *)(v5 + 8);
            v52 = (unsigned int)(*v50 + 1017856);
            v53 = readl(v51 + v52);
            writel(v53 & 0xFFFFFFFE, v51 + v52);
            result = readl(v51 + v52);
          }
          break;
        case 16:
          v17 = diag_dload;
          memset(v74, 0, 128);
          if ( diag_dload && (v18 = v3[106]) != 0 )
          {
            v19 = **(_QWORD **)(v18 + 48);
            if ( *(_WORD *)(v19 + 330) == 1478 )
            {
              v20 = (_QWORD *)(v19 + 344);
              while ( 1 )
              {
                v20 = (_QWORD *)*v20;
                if ( v20 == (_QWORD *)(v19 + 344) )
                  break;
                result = strcmp(**(const char ***)(v20[5] + 208LL), "ffs.diag");
                if ( !(_DWORD)result )
                {
                  v3 = *(__int64 **)(v19 + 360);
                  v73 = *(unsigned __int16 *)(v19 + 332);
                  v74[16] = 0x6194537471432909LL;
                  if ( v3 == (__int64 *)(v19 + 360) )
                  {
LABEL_112:
                    result = _memcpy_toio(v17, &v73, 140);
                    goto LABEL_107;
                  }
                  while ( v3 != (__int64 *)-16LL )
                  {
                    for ( j = *(unsigned __int8 **)(v3[2] + 8); j; j += 16 )
                    {
                      v5 = *((_QWORD *)j + 1);
                      if ( !v5 )
                        break;
                      if ( *j == *(unsigned __int8 *)(v19 + 338) )
                      {
                        result = strnlen(*((const char **)j + 1), 0x80u);
                        if ( result == -1 )
                          goto LABEL_124;
                        if ( result == 128 )
                          v55 = 128;
                        else
                          v55 = result + 1;
                        if ( v55 < 0x81 )
                        {
                          sized_strscpy(v74, v5);
                          break;
                        }
                        result = _fortify_panic(7, 128, v55);
                        goto LABEL_96;
                      }
                    }
                    v3 = (__int64 *)*v3;
                    if ( v3 == (__int64 *)(v19 + 360) )
                    {
                      v17 = diag_dload;
                      goto LABEL_112;
                    }
                  }
                  v62 = &unk_17D71;
                  goto LABEL_114;
                }
              }
            }
          }
          else
          {
            v62 = &unk_1622C;
LABEL_114:
            result = printk(v62);
          }
          break;
      }
    }
    else if ( a2 == 11 )
    {
      if ( *(_QWORD *)(v5 + 864) && *(_DWORD *)(v5 + 856) )
      {
        v36 = 0;
        v37 = 0x10000;
        v38 = 50204;
        do
        {
          v39 = *(_QWORD *)(*(_QWORD *)(v5 + 864) + 8LL * (int)v36);
          if ( !v39 )
            break;
          memset(*(void **)v39, 0, *(unsigned int *)(v39 + 16));
          *(_DWORD *)(v39 + 20) = 0;
          ++v36;
          writel(*(unsigned int *)(v39 + 32), *(_QWORD *)(v5 + 8) + v38 - 12);
          writel((v37 + *(unsigned __int16 *)(v39 + 36)) | 0xC00000u, *(_QWORD *)(v5 + 8) + v38 - 8);
          writel(*(unsigned __int16 *)(v39 + 16) | 0x80000000, *(_QWORD *)(v5 + 8) + v38 - 4);
          result = writel(0, *(_QWORD *)(v5 + 8) + v38);
          v37 += 0x10000;
          v38 += 16;
        }
        while ( v36 < *(_DWORD *)(v5 + 856) );
      }
    }
    else if ( a2 == 12 )
    {
      if ( *(_QWORD *)(v5 + 864) && *(_DWORD *)(v5 + 856) )
      {
        v43 = 0;
        v44 = 50204;
        do
        {
          v45 = *(_QWORD *)(*(_QWORD *)(v5 + 864) + 8LL * (int)v43++);
          *(_DWORD *)(v45 + 20) = 0;
          writel(0, *(_QWORD *)(v5 + 8) + v44 - 12);
          writel(0, *(_QWORD *)(v5 + 8) + v44 - 8);
          writel((unsigned __int16)v43 | 0x80000000, *(_QWORD *)(v5 + 8) + v44 - 4);
          result = writel(0, *(_QWORD *)(v5 + 8) + v44);
          v44 += 16;
        }
        while ( v43 < *(_DWORD *)(v5 + 856) );
      }
    }
    else if ( *(_DWORD *)(v5 + 856) )
    {
      v6 = 0;
      v7 = 50204;
      do
      {
        ++v6;
        v8 = readl(*(_QWORD *)(v5 + 8) + (v7 & 0xFFFFFFFC));
        writel(v8 & 0xFFFC, *(_QWORD *)(v5 + 8) + (v7 & 0xFFFFFFFC));
        result = ipc_log_string(
                   *(_QWORD *)(v5 + 1256),
                   "%s: remaining EVNTCOUNT(%d)=%d",
                   "handle_gsi_buffer_clear_event",
                   v6,
                   v8 & 0xFFFC);
        v7 += 16;
      }
      while ( v6 < *(unsigned int *)(v5 + 856) );
    }
    goto LABEL_107;
  }
  if ( a2 <= 7 )
  {
    if ( a2 == 5 )
    {
      v24 = *(_QWORD *)(v5 + 448);
      if ( v24 && (*(_BYTE *)(v24 + 16) & 1) != 0 )
        __break(0x800u);
      if ( *(_BYTE *)(v5 + 2561) == 1 && *(_DWORD *)(v3[106] + 72) >= 5u )
      {
        v25 = *(_QWORD *)(v5 + 448);
        if ( v25 )
        {
          v26 = *(void (**)(void))(v25 + 312);
          if ( v26 )
          {
            if ( *((_DWORD *)v26 - 1) != -1429527844 )
              __break(0x8228u);
            v26();
          }
        }
        if ( *(_DWORD *)(v5 + 2796) == 1 )
        {
          _const_udelay(85900);
          mdwc3_usb2_phy_soft_reset(v5);
        }
      }
      if ( (*(_BYTE *)(v5 + 508) & 1) == 0 && *(_BYTE *)(v5 + 756) == 1 )
      {
        v27 = *(_QWORD *)(v5 + 8);
        v28 = readl(v27 + 1017948);
        writel(v28 | 0x2000u, v27 + 1017948);
        readl(v27 + 1017948);
      }
      *(_DWORD *)(v5 + 832) = 0;
      v29 = *(_QWORD *)(*(_QWORD *)(v3[46] + 96) + 152LL);
      if ( (mdwc3_update_u1u2_value_read_u1u2 & 1) == 0 )
      {
        v30 = *(_QWORD *)(v29 + 1256);
        v31 = (*((_DWORD *)v3 + 344) >> 29) & 1;
        *(_BYTE *)(v29 + 2563) = (v3[172] & 0x20000000) != 0;
        v32 = (*((_DWORD *)v3 + 344) >> 30) & 1;
        mdwc3_update_u1u2_value_read_u1u2 = 1;
        *(_BYTE *)(v29 + 2564) = v32;
        ipc_log_string(v30, "%s: cached_dt_param: u1_disable:%d u2_disable:%d\n", "mdwc3_update_u1u2_value", v31, v32);
      }
      v33 = *((unsigned __int8 *)v3 + 1278);
      if ( v33 == 4 )
      {
        v34 = v3[172] & 0xFFFFFFFFDFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(v29 + 2563) & 1) << 29);
        v3[172] = v34;
        v35 = v34 & 0xFFFFFFFFBFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(v29 + 2564) & 1) << 30);
      }
      else
      {
        v35 = v3[172] | 0x60000000;
      }
      v3[172] = v35;
      if ( (v35 & 0x20000000) != 0 )
        v57 = "disabled";
      else
        v57 = "enabled";
      if ( (v35 & 0x40000000) != 0 )
        v58 = "disabled";
      else
        v58 = "enabled";
      ipc_log_string(*(_QWORD *)(v29 + 1256), "%s: speed:%d u1:%s u2:%s\n", "mdwc3_update_u1u2_value", v33, v57, v58);
    }
    else
    {
      if ( a2 != 7 )
      {
        if ( a2 )
          goto LABEL_107;
        dev_info(*(_QWORD *)v5, "DWC3_CONTROLLER_ERROR_EVENT received\n");
        writel(0, *(_QWORD *)(v5 + 8) + 50952LL);
        v59 = readl(*(_QWORD *)(v5 + 8) + 49424LL);
        result = writel(v59 | 0x800u, *(_QWORD *)(v5 + 8) + 49424LL);
        if ( *(int *)(v5 + 1248) > 2 )
          goto LABEL_107;
        v60 = v5 + 600;
        v61 = system_wq;
LABEL_106:
        result = queue_work_on(32, v61, v60);
        goto LABEL_107;
      }
      if ( (a3 & 0xE0) == 0 )
      {
        v21 = v5 + 40LL * (a3 & 0x1F);
        if ( *(_DWORD *)(v21 + 1280) == 1 )
        {
          v22 = *(_BYTE *)(v21 + 1296);
          v23 = readl(*(_QWORD *)(v5 + 8) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v5 + 496) + 96LL) + 1015808));
          result = writel(
                     v23 | (unsigned int)(1 << v22),
                     *(_QWORD *)(v5 + 8) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v5 + 496) + 96LL) + 1015808));
        }
        goto LABEL_107;
      }
      __break(0x5512u);
LABEL_124:
      _fortify_panic(2, -1, result + 1);
    }
    _X8 = (unsigned __int64 *)(v5 + 688);
    __asm { PRFM            #0x11, [X8] }
    do
      v72 = __ldxr(_X8);
    while ( __stxr(v72 | 0x10, _X8) );
    v61 = *(_QWORD *)(v5 + 648);
    v60 = v5 + 656;
    goto LABEL_106;
  }
  if ( a2 == 8 )
  {
    if ( *(_BYTE *)(v5 + 746) == 1 )
      result = usb_redriver_gadget_pullup_enter(*(_QWORD *)(v5 + 464), a3);
    goto LABEL_107;
  }
  if ( a2 == 9 )
  {
    if ( *(_BYTE *)(v5 + 746) == 1 )
      result = usb_redriver_gadget_pullup_exit(*(_QWORD *)(v5 + 464), a3);
    goto LABEL_107;
  }
  if ( !*(_DWORD *)(v5 + 856) )
    goto LABEL_107;
  v9 = ((__int64 (*)(void))devm_kmalloc)();
  *(_QWORD *)(v5 + 864) = v9;
  if ( !v9 )
  {
    result = dev_err(v3[46], "can't allocate gsi_ev_buff\n");
    goto LABEL_107;
  }
  if ( !*(_DWORD *)(v5 + 856) )
  {
LABEL_19:
    v14 = (const char **)v3[47];
    v15 = is_vmalloc_addr(v5 + 1200);
    if ( (v15 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
    {
      v63 = v15;
      dma_map_single_attrs___already_done = 1;
      v64 = (const char *)dev_driver_string(v14);
      v65 = v14[14];
      if ( !v65 )
        v65 = *v14;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v64, v65);
      __break(0x800u);
      if ( (v63 & 1) == 0 )
        goto LABEL_22;
    }
    else if ( (v15 & 1) == 0 )
    {
LABEL_22:
      result = dma_map_page_attrs(
                 v14,
                 ((unsigned __int64)(((v5 + 1200) << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                 (v5 + 1200) & 0xFFF,
                 8,
                 2,
                 0);
      *(_QWORD *)(v5 + 1208) = result;
      if ( result != -1 )
        goto LABEL_107;
      v16 = (_QWORD *)(v5 + 1208);
LABEL_122:
      result = dev_err(v3[46], "failed to map dummy doorbell buffer\n");
      *v16 = 0;
      goto LABEL_107;
    }
    v16 = (_QWORD *)(v5 + 1208);
    *(_QWORD *)(v5 + 1208) = -1;
    goto LABEL_122;
  }
  v10 = 0;
  while ( 1 )
  {
    result = devm_kmalloc(v3[46], 56, 3520);
    if ( !result )
      break;
    v11 = result;
    *(_QWORD *)(result + 40) = v3;
    v12 = v3[47];
    *(_DWORD *)(v11 + 16) = 4096;
    v13 = dma_alloc_attrs(v12, 4096, v11 + 32, 3264, 0);
    *(_QWORD *)v11 = v13;
    if ( !v13 )
    {
      result = dev_err(v3[46], "can't allocate gsi_evt_buf(%d)\n", v10);
      break;
    }
    *(_QWORD *)(*(_QWORD *)(v5 + 864) + 8LL * (int)v10++) = v11;
    if ( v10 >= *(_DWORD *)(v5 + 856) )
      goto LABEL_19;
  }
LABEL_107:
  _ReadStatusReg(SP_EL0);
  return result;
}
