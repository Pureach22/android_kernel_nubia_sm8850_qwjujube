__int64 __fastcall fastrpc_map_create(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int64 a5,
        unsigned int a6,
        unsigned int a7,
        __int64 *a8,
        unsigned __int8 a9)
{
  unsigned int v15; // w27
  __int64 result; // x0
  __int64 v18; // x0
  __int64 v19; // x19
  unsigned __int64 v21; // x0
  __int64 v22; // x20
  unsigned __int64 v28; // x9
  __int64 v29; // x8
  __int64 v30; // x27
  __int64 v31; // x8
  __int64 v32; // x26
  int vmperm; // w0
  int v34; // w20
  int v35; // w8
  __int64 *v36; // x20
  __int64 v37; // x27
  unsigned int v38; // w26
  unsigned int v39; // w28
  __int64 v40; // x8
  __int64 v41; // x0
  unsigned int v42; // w9
  unsigned __int64 v43; // x22
  int v44; // w24
  unsigned __int64 v45; // x8
  _QWORD *v46; // x9
  unsigned __int64 v47; // x28
  __int64 v48; // x26
  unsigned __int64 v49; // x0
  unsigned __int64 v50; // x0
  _DWORD *v51; // x8
  __int64 v52; // x9
  __int64 v53; // x9
  int v54; // w22
  __int64 v55; // x0
  unsigned int v56; // w20
  __int64 v57; // x0
  unsigned int v58; // w20
  unsigned __int64 v59; // x8
  __int64 v60; // x9
  __int64 v61; // x4
  __int64 v62; // x0
  __int64 v63; // x1
  int v64; // w8
  __int64 v65; // x0
  unsigned int v66; // [xsp+4h] [xbp-3Ch]
  __int64 v67; // [xsp+10h] [xbp-30h]
  unsigned int v68; // [xsp+18h] [xbp-28h]
  int v69; // [xsp+1Ch] [xbp-24h] BYREF
  __int64 v70; // [xsp+20h] [xbp-20h] BYREF
  __int64 v71; // [xsp+28h] [xbp-18h] BYREF
  int v72; // [xsp+30h] [xbp-10h]
  int v73; // [xsp+34h] [xbp-Ch]
  __int64 v74; // [xsp+38h] [xbp-8h]

  v15 = a2;
  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = fastrpc_map_lookup(a1, a2, a4, a7, a8, a9);
  if ( (_DWORD)result )
  {
    v18 = _kmalloc_cache_noprof(_kmalloc_noprof, 3520, 128);
    v19 = v18;
    if ( v18 )
    {
      *(_QWORD *)v18 = v18;
      *(_QWORD *)(v18 + 8) = v18;
      *(_DWORD *)(v18 + 112) = 1;
      *(_QWORD *)(v18 + 16) = a1;
      *(_DWORD *)(v18 + 24) = v15;
      *(_DWORD *)(v18 + 108) = a7;
      *(_QWORD *)(v18 + 88) = a5;
      if ( a7 == 6 )
      {
        if ( a4 )
        {
          _X8 = *(unsigned __int64 **)(a4 + 8);
          *(_QWORD *)(v18 + 32) = a4;
          __asm { PRFM            #0x11, [X8] }
          do
            v28 = __ldxr(_X8);
          while ( __stxr(v28 + 1, _X8) );
          if ( !v28 && (get_file___already_done & 1) == 0 )
          {
            get_file___already_done = 1;
            _warn_printk("struct file::f_count incremented from zero; use-after-free condition present!\n");
            __break(0x800u);
          }
          goto LABEL_14;
        }
        v22 = 4294967282LL;
      }
      else
      {
        v21 = dma_buf_get(v15);
        *(_QWORD *)(v19 + 32) = v21;
        if ( v21 < 0xFFFFFFFFFFFFF001LL )
        {
LABEL_14:
          v29 = *(_QWORD *)(v19 + 16);
          v30 = *(_QWORD *)(v19 + 32);
          v71 = 0;
          v70 = 0;
          v31 = *(_QWORD *)(v29 + 128);
          v69 = 0;
          v32 = *(_QWORD *)(v31 + 168);
          if ( (is_mem_buf_dma_buf(v30) & 1) == 0 )
            goto LABEL_18;
          vmperm = mem_buf_dma_buf_get_vmperm(v30, &v71, &v70, &v69);
          if ( vmperm )
          {
            dev_err(v32, "failed to obtain buffer attributes for fd %d ret %d\n", *(_DWORD *)(v19 + 24), vmperm);
            v22 = 4294967219LL;
            goto LABEL_69;
          }
          if ( v69 == 1 && (v34 = *(_DWORD *)v71, v34 == (unsigned int)mem_buf_current_vmid()) )
LABEL_18:
            v35 = 0;
          else
            v35 = 1;
          v67 = a3;
          v36 = (__int64 *)(a1 + 136);
          v37 = *(_QWORD *)(a1 + 136);
          v38 = *(_DWORD *)(a1 + 268);
          if ( byte_27530 )
            v35 = 0;
          *(_DWORD *)(v19 + 116) = v35;
          if ( !v35 || (a6 & 0x10) != 0 || a7 == 16 )
          {
            if ( a7 - 17 > 1 )
            {
              v39 = 0;
              if ( v37 )
                goto LABEL_35;
              goto LABEL_33;
            }
            if ( a5 < 0x200000 || (a5 & 0xFFFFF) != 0 )
            {
              v22 = 4294967201LL;
              dev_err(
                *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL),
                "Error 0x%x: %s: Invalid size 0x%llx. Size should be a multiple of 0x%llx and greater than 0x%llx for map flag %d",
                -95,
                "fastrpc_map_create",
                a5,
                0x100000,
                0x200000,
                a7);
              goto LABEL_69;
            }
            v39 = 0;
            v38 = 10;
            v40 = 152;
          }
          else
          {
            v39 = 1;
            v40 = 144;
          }
          v36 = (__int64 *)(a1 + v40);
          v37 = *(_QWORD *)(a1 + v40);
          if ( v37 )
            goto LABEL_35;
LABEL_33:
          v41 = fastrpc_session_alloc(a1, v39, v38);
          if ( v41 )
          {
            v37 = v41;
            *v36 = v41;
LABEL_35:
            v42 = a7;
            v43 = 0;
            v68 = a6;
            if ( v42 == 16 )
              v44 = 1;
            else
              v44 = (a6 >> 4) & 1;
            v66 = v42;
            while ( 1 )
            {
              v45 = *(unsigned int *)(v37 + 1016);
              if ( v45 > v43 )
              {
                v46 = (_QWORD *)(v37 + 120 + 144 * v43);
                while ( 1 )
                {
                  if ( v43 == 8 )
                    goto LABEL_92;
                  if ( !*v46 || *(v46 - 1) <= a5 && *(v46 - 2) - *(v46 - 3) > a5 )
                    break;
                  ++v43;
                  v46 += 18;
                  if ( v45 == v43 )
                    goto LABEL_68;
                }
                v43 = (unsigned int)v43;
              }
              if ( v43 >= v45 )
              {
LABEL_68:
                dev_err(
                  *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL),
                  "%s: No valid smmu context bank found for len 0x%llx\n",
                  "fastrpc_map_create",
                  a5);
                v22 = 4294967233LL;
                goto LABEL_69;
              }
              if ( v43 >= 8 )
LABEL_92:
                __break(0x5512u);
              v47 = v37 + 144 * v43;
              if ( v44 )
              {
                v48 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL);
              }
              else
              {
                v48 = *(_QWORD *)v47;
                *(_QWORD *)(v19 + 56) = v47;
              }
              mutex_lock(v47 + 16);
              if ( !*(_QWORD *)v47 )
              {
                mutex_unlock(v47 + 16);
                v22 = 4294967277LL;
                goto LABEL_69;
              }
              v49 = dma_buf_attach(*(_QWORD *)(v19 + 32), v48);
              *(_QWORD *)(v19 + 48) = v49;
              if ( v49 >= 0xFFFFFFFFFFFFF001LL )
                break;
              v50 = dma_buf_map_attachment_unlocked(v49, 0);
              if ( v50 <= 0xFFFFFFFFFFFFF000LL )
              {
                *(_QWORD *)(v19 + 40) = v50;
                v51 = *(_DWORD **)(v19 + 40);
                v52 = *(_QWORD *)v51;
                if ( (v68 & 1) != 0 )
                {
                  v54 = v66;
                  *(_QWORD *)(v19 + 64) = *(unsigned int *)(v52 + 8)
                                        + (((*(_QWORD *)v52 & 0x3FFFFFFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6)
                                        + 0x5000000000LL;
                  if ( v51[2] )
                  {
                    v55 = *(_QWORD *)v51;
                    v56 = 0;
                    do
                    {
                      ++v56;
                      *(_QWORD *)(v19 + 72) += *(unsigned int *)(v55 + 24);
                      v55 = sg_next();
                    }
                    while ( v56 < *(_DWORD *)(*(_QWORD *)(v19 + 40) + 8LL) );
                  }
                }
                else
                {
                  v53 = *(_QWORD *)(v52 + 16);
                  v54 = v66;
                  *(_QWORD *)(v19 + 64) = v53;
                  if ( v44 )
                  {
                    *(_QWORD *)(v19 + 72) = *(unsigned int *)(*(_QWORD *)v51 + 24LL);
                    *(_QWORD *)(v19 + 80) = v67;
                    goto LABEL_80;
                  }
                  *(_QWORD *)(v19 + 64) = ((__int64)*(int *)(v47 + 8) << *(_DWORD *)(v47 + 140)) + v53;
                  if ( v51[2] )
                  {
                    v57 = *(_QWORD *)v51;
                    v58 = 0;
                    do
                    {
                      ++v58;
                      *(_QWORD *)(v19 + 72) += *(unsigned int *)(v57 + 24);
                      v57 = sg_next();
                    }
                    while ( v58 < *(_DWORD *)(*(_QWORD *)(v19 + 40) + 8LL) );
                  }
                }
                v59 = *(_QWORD *)(v19 + 72);
                v60 = 4095;
                if ( v59 > 0x200000 )
                  v60 = 0x1FFFFF;
                *(_QWORD *)(v19 + 80) = v67;
                if ( v59 > 0x40000000 )
                  v60 = 0x3FFFFFFF;
                *(_QWORD *)(v47 + 96) += (v60 + v59) & ~v60;
LABEL_80:
                trace_fastrpc_dma_map(
                  **(unsigned int **)(*(_QWORD *)(v19 + 16) + 128LL),
                  *(unsigned int *)(v19 + 24),
                  *(_QWORD *)(v19 + 64),
                  *(_QWORD *)(v19 + 72),
                  *(_QWORD *)(v19 + 88),
                  *(unsigned int *)(*(_QWORD *)(v19 + 48) + 72LL),
                  *(unsigned int *)(v19 + 108));
                mutex_unlock(v47 + 16);
                if ( (unsigned int)(v54 - 17) <= 1 && (v61 = *(_QWORD *)(v19 + 64), (v61 & 0x1FFFFF) != 0) )
                {
                  v22 = 4294967201LL;
                  dev_err(
                    v48,
                    "Error %d: %s: iova 0x%llx not aligned to 0x%llx for map flag %d",
                    -95,
                    "fastrpc_map_create",
                    v61,
                    0x200000,
                    v54);
                }
                else
                {
                  if ( (v68 & 1) == 0 )
                    goto LABEL_84;
                  v62 = *(_QWORD *)(v19 + 64);
                  v63 = *(_QWORD *)(v19 + 72);
                  v64 = *(_DWORD *)(*(_QWORD *)(a1 + 128) + 32LL);
                  v70 = 8;
                  v71 = 0x600000003LL;
                  v72 = v64;
                  v73 = 7;
                  v65 = qcom_scm_assign_mem(v62, v63, &v70, &v71, 2);
                  if ( !(_DWORD)v65 )
                  {
LABEL_84:
                    *(_DWORD *)(v19 + 104) = v68;
                    raw_spin_lock(a1 + 320);
                    _list_add(v19, *(_QWORD *)(a1 + 24), a1 + 16);
                    raw_spin_unlock(a1 + 320);
                    result = 0;
                    *a8 = v19;
                    goto LABEL_71;
                  }
                  v22 = v65;
                  dev_err(
                    *(_QWORD *)v47,
                    "Failed to assign memory with phys 0x%llx size 0x%llx err %d",
                    *(_QWORD *)(v19 + 64),
                    *(_QWORD *)(v19 + 72),
                    v65);
                }
                dma_buf_unmap_attachment_wrap(v19);
                goto LABEL_59;
              }
              if ( (_DWORD)v50 != -22 && (_DWORD)v50 != -12 )
              {
                v22 = v50;
                mutex_unlock(v47 + 16);
LABEL_59:
                dma_buf_detach(*(_QWORD *)(v19 + 32), *(_QWORD *)(v19 + 48));
                goto LABEL_69;
              }
              mutex_unlock(v47 + 16);
              dma_buf_detach(*(_QWORD *)(v19 + 32), *(_QWORD *)(v19 + 48));
              ++v43;
            }
            dev_err(v48, "Failed to attach dmabuf\n");
            v22 = *(unsigned int *)(v19 + 48);
            mutex_unlock(v47 + 16);
            goto LABEL_69;
          }
          dev_err(
            *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL),
            "%s: no session available, pd type %d, secure %d\n",
            "fastrpc_map_create",
            v38,
            v39);
          v22 = 4294967280LL;
LABEL_69:
          dma_buf_put(*(_QWORD *)(v19 + 32));
          goto LABEL_70;
        }
        v22 = (unsigned int)v21;
      }
LABEL_70:
      kfree(v19);
      result = v22;
      goto LABEL_71;
    }
    result = 4294967284LL;
  }
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
