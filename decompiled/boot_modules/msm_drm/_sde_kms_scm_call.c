__int64 __fastcall sde_kms_scm_call(__int64 a1, unsigned int a2)
{
  void *v4; // x0
  const char *v5; // x26
  char is_enabled; // w0
  __int64 v7; // x22
  char v8; // w19
  __int64 v9; // x23
  __int64 v10; // x21
  __int64 v11; // x24
  __int64 v12; // x8
  unsigned __int64 v13; // x12
  __int64 v14; // x9
  __int64 v15; // x8
  __int64 v16; // x25
  const char *v17; // x28
  int v18; // w5
  unsigned int v19; // w0
  char v20; // w0
  __int64 v21; // x0
  __int64 v22; // x26
  unsigned int v23; // w24
  __int64 result; // x0
  char v25; // w25
  __int64 v26; // x1
  __int64 v27; // x2
  unsigned __int64 StatusReg; // x23
  __int64 v29; // x24
  __int64 v30; // [xsp+28h] [xbp-3B8h] BYREF
  __int64 v31; // [xsp+30h] [xbp-3B0h]
  __int64 v32; // [xsp+38h] [xbp-3A8h]
  _QWORD s[116]; // [xsp+40h] [xbp-3A0h] BYREF

  s[114] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = memset(s, 0, 0x390u);
  v5 = *(const char **)(a1 + 152);
  v31 = 0;
  v32 = 0;
  v30 = 0;
  is_enabled = qtee_shmbridge_is_enabled(v4);
  v7 = *((unsigned int *)v5 + 5370);
  if ( (_DWORD)v7 )
  {
    v8 = is_enabled;
    if ( (is_enabled & 1) != 0 )
    {
      v9 = 4 * v7;
      if ( !(unsigned int)qtee_shmbridge_allocate_shm(4 * v7, &v30) )
      {
        v11 = v30;
        v10 = v31;
        goto LABEL_9;
      }
    }
    else
    {
      v10 = _kmalloc_noprof(4 * v7, 3520);
      if ( v10 )
      {
        while ( 2 )
        {
          v12 = v10 << 8 >> 8;
          v9 = 4 * v7;
          v13 = (unsigned __int64)(v12 + 0x8000000000LL) >> 38;
          v14 = memstart_addr + v12 + 0x8000000000LL;
          v15 = v12 - kimage_voffset;
          if ( v13 )
            v11 = v15;
          else
            v11 = v14;
LABEL_9:
          v16 = 0;
          v17 = v5 + 21484;
          v5 = "sid_mask[%d]: %d\n";
          while ( v16 != 12 )
          {
            v18 = *(_DWORD *)&v17[4 * v16];
            *(_DWORD *)(v10 + 4 * v16) = v18;
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "sid_mask[%d]: %d\n", v16, v18);
            if ( v7 == ++v16 )
            {
              s[80] = &s[81];
              v19 = dma_set_mask(s, -1);
              if ( v19 )
              {
                v23 = v19;
                printk(&unk_2502D6, "_sde_kms_scm_call");
              }
              else
              {
                dma_set_coherent_mask(s, -1);
                s[79] = 0;
                v20 = is_vmalloc_addr(v10);
                if ( (v20 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
                {
                  v25 = v20;
                  dma_map_single_attrs___already_done = 1;
                  v26 = dev_driver_string(s);
                  if ( s[14] )
                    v27 = s[14];
                  else
                    v27 = s[0];
                  _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v26, v27);
                  __break(0x800u);
                  if ( (v25 & 1) != 0 )
                    goto LABEL_34;
LABEL_18:
                  v21 = dma_map_page_attrs(
                          s,
                          ((unsigned __int64)((v10 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                          v10 & 0xFFF,
                          4 * v7,
                          1,
                          0);
                  if ( v21 == -1 )
                    goto LABEL_34;
                  v22 = v21;
                  if ( (_drm_debug & 4) != 0 )
                    _drm_dev_dbg(0, 0, 0, "calling scm_call for vmid 0x%x, num_sids %d, qtee_en %d", a2, v7, v8 & 1);
                  v23 = qcom_scm_mem_protect_sd_ctrl(26, v11, v9, a2);
                  if ( v23 )
                    printk(&unk_216310, "_sde_kms_scm_call");
                  sde_evtlog_log(sde_dbg_base_evtlog, "_sde_kms_scm_call", 410, -1, 24, 26, v9, a2, v8 & 1);
                  dma_unmap_page_attrs(s, v22, 4 * v7, 1, 0);
                }
                else
                {
                  if ( (v20 & 1) == 0 )
                    goto LABEL_18;
LABEL_34:
                  printk(&unk_2574B9, "_sde_kms_scm_call");
                  v23 = 0;
                }
              }
              if ( (v8 & 1) != 0 )
                qtee_shmbridge_free_shm(&v30);
              else
                kfree(v10);
              result = v23;
              goto LABEL_37;
            }
          }
          __break(0x5512u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v29 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &sde_kms_scm_call__alloc_tag;
          v10 = _kmalloc_noprof(4 * v7, 3520);
          *(_QWORD *)(StatusReg + 80) = v29;
          if ( v10 )
            continue;
          break;
        }
      }
    }
    result = 4294967284LL;
    goto LABEL_37;
  }
  printk(&unk_250291, "_sde_kms_scm_call");
  result = 4294967274LL;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
