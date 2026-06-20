__int64 __fastcall synx_util_init_group_coredata(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 result; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  unsigned __int64 v18; // x20
  _DWORD *v19; // x27
  __int64 v20; // x26
  __int64 first_zero_bit; // x0
  __int64 v22; // x8
  unsigned __int64 v29; // x9
  int inited; // w0
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x5
  __int64 v34; // x4
  unsigned int v35; // w19
  unsigned __int64 v36; // x0
  __int64 v37; // x4
  __int64 v38; // x5
  int v39; // w9
  __int64 v40; // x1
  __int64 v41; // x2
  __int64 v42; // x3
  __int64 v43; // x4
  __int64 v44; // x5
  int object_status; // w0
  __int64 v46; // x8
  int *v47; // x1
  int v48; // w8
  int v49; // w9
  __int64 v50; // x1
  __int64 v51; // x2
  __int64 v52; // x3
  __int64 v53; // x4
  __int64 v54; // x5
  int v55; // w8
  __int64 v56; // x9
  __int64 v57; // x8
  unsigned __int64 v60; // x9
  unsigned __int64 v63; // x10
  unsigned int v64; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v65; // [xsp+8h] [xbp-8h]

  result = 4294967274LL;
  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( a1 <= 0xFFFFFFFFFFFFF000LL )
    {
      v18 = _kmalloc_cache_noprof(raw_spin_unlock_bh, 3520, 32);
      result = 4294967284LL;
      if ( v18 )
      {
        if ( v18 <= 0xFFFFFFFFFFFFF000LL )
        {
          v19 = *(_DWORD **)(a3 + 16);
          if ( (*(_BYTE *)(a3 + 8) & 2) != 0 )
          {
            v64 = 0;
            inited = synx_global_alloc_index(&v64, v13, v14, v15, v16, v17);
            if ( !inited )
            {
              if ( v64 <= 0xFFF )
                v34 = v64 + 0x100000;
              else
                v34 = 0;
              *v19 = v34;
              if ( (synx_debug & 8) != 0 )
                goto LABEL_38;
              goto LABEL_21;
            }
            *(_DWORD *)(a1 + 344) = **(unsigned __int16 **)(a3 + 16);
            goto LABEL_22;
          }
          v20 = *(_QWORD *)(synx_dev + 152) + 22568LL;
          do
          {
            first_zero_bit = find_first_zero_bit(v20, 4096);
            if ( first_zero_bit > 4095 )
              break;
            v22 = 1LL << first_zero_bit;
            _X10 = (unsigned __int64 *)(v20 + 8LL * ((unsigned int)first_zero_bit >> 6));
            __asm { PRFM            #0x11, [X10] }
            do
              v29 = __ldxr(_X10);
            while ( __stlxr(v29 | v22, _X10) );
            __dmb(0xBu);
          }
          while ( (v29 & v22) != 0 );
          if ( (unsigned int)first_zero_bit > 0xFFF )
          {
            inited = -12;
LABEL_22:
            v35 = inited;
            kfree(v18);
            result = v35;
            goto LABEL_23;
          }
          *v19 = first_zero_bit;
          if ( (synx_debug & 8) != 0 )
            printk(&unk_2A400, &unk_2A972, "synx_alloc_local_handle", 581, first_zero_bit, (unsigned int)first_zero_bit);
          while ( 1 )
          {
            v36 = dma_fence_array_create(a4, a2, a5);
            if ( !v36 || v36 >= 0xFFFFFFFFFFFFF001LL )
              break;
            *(_QWORD *)(a1 + 64) = v36;
            *(_DWORD *)(a1 + 348) = 1;
            v39 = *(_DWORD *)(a3 + 8);
            *(_DWORD *)(a1 + 132) = 0;
            *(_QWORD *)(a1 + 360) = a6;
            *(_DWORD *)(a1 + 124) = v39 | 0x20;
            *(_DWORD *)(a1 + 120) = 1;
            _mutex_init(a1 + 72, "&synx_obj->obj_lock", &synx_util_init_group_coredata___key);
            *(_QWORD *)(a1 + 328) = a1 + 328;
            *(_QWORD *)(a1 + 336) = a1 + 328;
            _X8 = (unsigned __int64 *)(*(_QWORD *)(a1 + 64) + 48LL);
            __asm { PRFM            #0x11, [X8] }
            do
              v60 = __ldxr(_X8);
            while ( __stxr(v60 | 0x20000000, _X8) );
            object_status = synx_util_get_object_status(a1, v40, v41, v42, v43, v44);
            v46 = *(_QWORD *)(a1 + 64);
            *(_DWORD *)(a1 + 128) = object_status;
            v47 = *(int **)(a3 + 16);
            *(_QWORD *)(v18 + 8) = v46;
            v48 = *(_DWORD *)(a3 + 8);
            v49 = *v47;
            if ( (v48 & 2) != 0 )
              *(_DWORD *)v18 = v49;
            else
              *(_DWORD *)(v18 + 4) = v49;
            result = synx_util_insert_fence_entry(v18, v47, v48 & 2);
            if ( !(_DWORD)result )
              goto LABEL_23;
            __break(0x800u);
LABEL_38:
            printk(&unk_2B708, &unk_2A972, "synx_alloc_global_handle", 564, v34, (unsigned int)v34);
            v34 = (unsigned int)*v19;
LABEL_21:
            inited = synx_global_init_coredata(v34, a6, v31, v32, v34, v33);
            *(_DWORD *)(a1 + 344) = **(unsigned __int16 **)(a3 + 16);
            if ( inited )
              goto LABEL_22;
          }
          if ( (synx_debug & 1) != 0 )
            printk(&unk_28A00, &unk_29207, "synx_util_init_group_coredata", 275, v37, v38);
          kfree(v18);
          v55 = **(_DWORD **)(a3 + 16);
          if ( (*(_BYTE *)(a3 + 8) & 2) != 0 )
          {
            synx_global_put_ref((unsigned __int16)**(_DWORD **)(a3 + 16), v50, v51, v52, v53, v54);
          }
          else
          {
            v56 = (unsigned __int16)v55 >> 6;
            v57 = 1LL << v55;
            _X9 = (unsigned __int64 *)(*(_QWORD *)(synx_dev + 152) + 22568LL + 8 * v56);
            __asm { PRFM            #0x11, [X9] }
            do
              v63 = __ldxr(_X9);
            while ( __stxr(v63 & ~v57, _X9) );
          }
          result = 4294967274LL;
        }
      }
    }
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
