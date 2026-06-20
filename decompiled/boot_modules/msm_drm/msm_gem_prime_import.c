unsigned __int64 __fastcall msm_gem_prime_import(_QWORD *a1, _QWORD *a2)
{
  __int64 v2; // x8
  unsigned __int64 result; // x0
  __int64 *v5; // x21
  int v7; // w0
  int v8; // w20
  unsigned __int64 v9; // x19
  __int64 v10; // x1
  __int64 v11; // x0
  unsigned __int8 v12; // w24
  __int64 v13; // x25
  __int64 v14; // x22
  __int64 (__fastcall *v15)(_QWORD); // x8
  int v16; // w8
  int v17; // w22
  int v18; // w23
  int v19; // w26
  __int64 (__fastcall *v20)(__int64 *, __int64); // x8
  __int64 v21; // x1
  unsigned __int64 v22; // x21
  __int64 v23; // x1
  char v24; // w26
  __int64 v25; // x8
  __int64 *v26; // x0
  _DWORD *v27; // x8
  _QWORD *v28; // x0
  unsigned __int64 v29; // x0
  __int64 v30; // x8
  long double v31; // q0
  unsigned __int64 v32; // x22
  _DWORD *v33; // x8
  unsigned __int64 v39; // x9
  unsigned int v42; // w8
  int v43; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v45[2]; // [xsp+10h] [xbp-10h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = a1[7];
    if ( v2 )
    {
      result = a2[14];
      v5 = *(__int64 **)(v2 + 8);
      if ( result && !*(_QWORD *)(a2[4] + 64LL) && *(_QWORD **)(result + 8) == a1 )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v42 = __ldxr((unsigned int *)result);
        while ( __stxr(v42 + 1, (unsigned int *)result) );
        if ( v42 )
        {
          if ( (((v42 + 1) | v42) & 0x80000000) == 0 )
            goto LABEL_71;
          v9 = result;
          v10 = 1;
        }
        else
        {
          v9 = result;
          v10 = 2;
        }
        refcount_warn_saturate(v9, v10);
        result = v9;
        goto LABEL_71;
      }
      if ( !*(_QWORD *)(a1[6] + 96LL) )
      {
        _drm_err("NULL gem_prime_import_sg_table\n");
        result = -22;
        goto LABEL_71;
      }
      _X8 = (unsigned __int64 *)a2[1];
      __asm { PRFM            #0x11, [X8] }
      do
        v39 = __ldxr(_X8);
      while ( __stxr(v39 + 1, _X8) );
      if ( !v39 && (get_file___already_done_0 & 1) == 0 )
      {
        get_file___already_done_0 = 1;
        _warn_printk("struct file::f_count incremented from zero; use-after-free condition present!\n");
        __break(0x800u);
      }
      if ( !v5 || !*(_QWORD *)(*v5 + 240) )
      {
        _drm_err("invalid kms ops\n");
        v8 = -22;
        goto LABEL_16;
      }
      v44 = 0;
      v45[0] = 0;
      v43 = 0;
      v7 = mem_buf_dma_buf_copy_vmperm(a2, v45, &v44, &v43);
      if ( v7 )
      {
        v8 = v7;
        _drm_err("get vmid list failure, ret:%d", v7);
LABEL_16:
        dma_buf_put(a2);
        result = v8;
        goto LABEL_71;
      }
      v11 = v45[0];
      if ( v43 < 1 )
      {
        v17 = 0;
        v18 = 0;
        v19 = 0;
        v12 = 0;
        v13 = 0;
      }
      else
      {
        v12 = 0;
        v13 = 0;
        v14 = 0;
        while ( 1 )
        {
          if ( *(_DWORD *)(v11 + 4 * v14) == 45 )
          {
            v15 = *(__int64 (__fastcall **)(_QWORD))(*v5 + 304);
            if ( !v15 )
              goto LABEL_28;
            if ( *((_DWORD *)v15 - 1) != -1471928254 )
              __break(0x8228u);
            if ( (v15(v5) & 1) == 0 )
            {
LABEL_28:
              v12 = 1;
              v13 = 0x40000;
            }
          }
          v11 = v45[0];
          v16 = *(_DWORD *)(v45[0] + 4 * v14);
          if ( v16 == 10 )
          {
            v17 = 0;
            v18 = 0;
            v12 = 0;
            v13 = 0;
            v19 = 1;
            goto LABEL_38;
          }
          if ( v16 == 17 )
            break;
          if ( v16 == 29 )
          {
            v18 = 0;
            v19 = 0;
            v17 = 1;
            goto LABEL_38;
          }
          if ( ++v14 >= v43 )
          {
            v17 = 0;
            v18 = 0;
            v19 = 0;
            goto LABEL_38;
          }
        }
        v17 = 0;
        v19 = 0;
        v18 = 1;
      }
LABEL_38:
      kfree(v11);
      kfree(v44);
      if ( v19 )
      {
        v20 = *(__int64 (__fastcall **)(__int64 *, __int64))(*v5 + 240);
        if ( *((_DWORD *)v20 - 1) != 1394849382 )
          __break(0x8228u);
        v21 = v20(v5, 2);
        if ( v21 )
        {
          v22 = dma_buf_attach(a2, v21);
          if ( v22 < 0xFFFFFFFFFFFFF001LL )
            goto LABEL_58;
          goto LABEL_56;
        }
        v25 = *v5;
        v26 = v5;
      }
      else
      {
        if ( (mdss_iommu_present() & 1) == 0 || (v12 & 1) != 0 || (v17 & 1) != 0 || v18 )
        {
          v23 = a1[1];
          v24 = 0;
          goto LABEL_53;
        }
        v25 = *v5;
        v26 = v5;
      }
      v27 = *(_DWORD **)(v25 + 240);
      if ( *(v27 - 1) != 1394849382 )
        __break(0x8228u);
      v23 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v27)(v26, 0);
      v24 = 1;
LABEL_53:
      v28 = a2;
      if ( !v23 )
      {
        _drm_dev_dbg(0, 0, 0, "attaching dma buf with default drm device\n");
        v23 = a1[1];
        v28 = a2;
      }
      v29 = dma_buf_attach(v28, v23);
      v22 = v29;
      if ( v29 <= 0xFFFFFFFFFFFFF000LL )
      {
        if ( (v24 & 1) == 0 )
        {
          v30 = *(_QWORD *)(v29 + 72);
          goto LABEL_60;
        }
LABEL_58:
        v30 = *(_QWORD *)(v22 + 72) | 0x20000LL;
        *(_QWORD *)(v22 + 72) = v30;
LABEL_60:
        *(_QWORD *)(v22 + 72) = v30 | v13;
        if ( (v12 & 1) != 0 || (v17 & 1) != 0 || (v18 & 1) != 0 )
        {
          *(double *)&v31 = _drm_dev_dbg(
                              0,
                              0,
                              0,
                              "deferring dma_buf_map_attachment; tvm:%d, sec_cam:%d, sec_disp:%d\n",
                              v12,
                              v17,
                              v18);
          v32 = 0;
        }
        else
        {
          v32 = dma_buf_map_attachment_unlocked(v22);
          if ( v32 >= 0xFFFFFFFFFFFFF001LL )
          {
            _drm_err("dma_buf_map_attachment failure, err=%d\n", v32);
            v8 = v32;
LABEL_69:
            dma_buf_detach(a2, v22);
            goto LABEL_16;
          }
        }
        v33 = *(_DWORD **)(a1[6] + 96LL);
        if ( *(v33 - 1) != 2108542046 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(_QWORD *, unsigned __int64, unsigned __int64, long double))v33)(
                   a1,
                   v22,
                   v32,
                   v31);
        if ( result < 0xFFFFFFFFFFFFF001LL )
        {
          *(_QWORD *)(result + 240) = v22;
          goto LABEL_71;
        }
        v8 = result;
        _drm_err("gem_prime_import_sg_table failure, err=%d\n", result);
        if ( v32 )
          dma_buf_unmap_attachment_unlocked(v22, v32, 0);
        goto LABEL_69;
      }
LABEL_56:
      _drm_err("dma_buf_attach failure, err=%ld\n", v22);
      result = v22;
      goto LABEL_71;
    }
  }
  result = -22;
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
