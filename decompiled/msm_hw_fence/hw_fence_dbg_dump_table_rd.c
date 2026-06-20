__int64 __fastcall hw_fence_dbg_dump_table_rd(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x30
  __int64 v5; // x27
  __int64 v6; // x23
  __int64 v8; // x4
  __int64 v10; // x0
  __int64 v11; // x4
  __int64 v12; // x19
  __int64 v13; // x24
  __int64 v14; // x25
  unsigned int *v15; // x0
  int v16; // w24
  unsigned int *v17; // x26
  unsigned int v18; // w24
  int v19; // w8
  __int64 v20; // x23
  _DWORD *v21; // x14
  int v22; // w8
  __int64 v23; // x9
  int v24; // w11
  __int64 v25; // x12
  __int64 v26; // x11
  __int64 v27; // x25
  __int64 v28; // x27
  unsigned int v29; // w28
  int v30; // w26
  _DWORD *v31; // x21
  __int64 v32; // x14
  unsigned int v33; // w5
  int v34; // w6
  __int64 v35; // x10
  __int64 v36; // x7
  __int64 v37; // x9
  int v38; // w16
  int v39; // w17
  int v40; // w8
  __int64 v41; // x11
  int v42; // w12
  __int64 v43; // x15
  int v44; // w0
  __int64 v45; // x4
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v47; // x10
  unsigned __int64 v48; // x10
  unsigned __int64 v54; // x9
  __int64 v55; // x0
  unsigned __int64 v56; // x8
  unsigned __int64 v58; // x9
  __int64 v60; // [xsp+30h] [xbp-90h]
  _QWORD *v61; // [xsp+60h] [xbp-60h]
  __int64 v62; // [xsp+68h] [xbp-58h]
  __int64 v64; // [xsp+78h] [xbp-48h] BYREF
  __int64 v65; // [xsp+80h] [xbp-40h] BYREF
  __int64 v66; // [xsp+88h] [xbp-38h]
  __int64 v67; // [xsp+90h] [xbp-30h]
  __int64 v68; // [xsp+98h] [xbp-28h]
  __int64 v69; // [xsp+A0h] [xbp-20h]
  __int16 v70; // [xsp+A8h] [xbp-18h]
  __int64 v71; // [xsp+B0h] [xbp-10h]

  v5 = v4;
  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v6 = *(_QWORD *)(a1 + 32)) != 0 )
  {
    if ( *(_QWORD *)(v6 + 64) )
    {
      v8 = *(unsigned int *)(v6 + 80);
      if ( hw_fence_dbg_dump_table_rd_index >= (unsigned int)v8 )
      {
        if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
          printk(&unk_284D3, "hw_fence_dbg_dump_table_rd", 1056, (unsigned int)hw_fence_dbg_dump_table_rd_index, v8);
        v20 = 0;
        hw_fence_dbg_dump_table_rd_index = 0;
        hw_fence_dbg_dump_table_rd_cnt = 0;
      }
      else
      {
        if ( a3 > 0x85 )
        {
          v10 = _kmalloc_cache_noprof(kvfree, 3520, 4096);
          v12 = v10;
          if ( !v10 )
          {
            v20 = -12;
            goto LABEL_43;
          }
          if ( (*(_BYTE *)(v6 + 488) & 1) != 0 )
          {
            v13 = *(_QWORD *)(v6 + 496);
            v14 = *(_QWORD *)(v6 + 504);
            v64 = 0;
            v15 = (unsigned int *)msm_hw_fence_find(v6, 0, v13, v13, v14, &v64);
            if ( v15 )
            {
              v16 = v64;
              v17 = v15;
              v70 = 0;
              v68 = 0;
              v69 = 0;
              v66 = 0;
              v67 = 0;
              v65 = 0;
              dump_fence_helper(4, v15, (__int64)&v65, v64, 0);
              v18 = scnprintf(
                      v12,
                      4096,
                      "[%d]hfence[%u] v:%d err:%u ctx:%llu seq:%llu wait:0x%llx alloc:%d f:0x%llx child_cnt:%d%s ct:%llu "
                      "tt:%llu wt:%llu ref:0x%x h_synx:%u\n",
                      0,
                      v16,
                      *v17,
                      v17[1],
                      *((_QWORD *)v17 + 1),
                      *((_QWORD *)v17 + 2),
                      *((_QWORD *)v17 + 3),
                      v17[8],
                      *((_QWORD *)v17 + 6),
                      v17[21],
                      (const char *)&v65,
                      *((_QWORD *)v17 + 11),
                      *((_QWORD *)v17 + 12),
                      *((_QWORD *)v17 + 13),
                      v17[28],
                      v17[29]);
              hw_fence_destroy_with_hash(v6, 0, v64);
            }
            else
            {
              printk(&unk_22544, "dump_single_entry", 583, v5, v13);
              v18 = scnprintf(v12, 4096, "no valid hfence found for context:%llu seqno:%llu hash:%llu\n", v13, v14, v64);
            }
            v19 = *(_DWORD *)(v6 + 80);
          }
          else
          {
            v62 = v10;
            v18 = 0;
            v21 = &unk_2B000;
LABEL_15:
            v22 = hw_fence_dbg_dump_table_rd_index;
            v23 = 0;
            while ( 1 )
            {
              v24 = hw_fence_dbg_dump_table_rd_index + v23;
              if ( (unsigned __int64)(unsigned int)hw_fence_dbg_dump_table_rd_index + v23 >= *(unsigned int *)(v6 + 80)
                || (int)v18 > 3961 )
              {
                break;
              }
              v25 = *(_QWORD *)(v6 + 64);
              ++v23;
              v26 = (unsigned int)(v24 + 1);
              if ( *(_DWORD *)(v25 + (v26 << 7)) )
              {
                v27 = v5;
                v28 = v25 + (v26 << 7);
                v29 = v21[464];
                v70 = 0;
                hw_fence_dbg_dump_table_rd_index += v23;
                v30 = hw_fence_dbg_dump_table_rd_index;
                v68 = 0;
                v69 = 0;
                v66 = 0;
                v67 = 0;
                v65 = 0;
                v61 = a4;
                v31 = v21;
                dump_fence_helper(4, (unsigned int *)v28, (__int64)&v65, v22 + v23, v29);
                v32 = *(_QWORD *)(v28 + 96);
                v33 = *(_DWORD *)v28;
                v34 = *(_DWORD *)(v28 + 4);
                v35 = *(_QWORD *)(v28 + 24);
                v36 = *(_QWORD *)(v28 + 8);
                v37 = *(_QWORD *)(v28 + 16);
                v38 = *(_DWORD *)(v28 + 112);
                v39 = *(_DWORD *)(v28 + 116);
                v40 = *(_DWORD *)(v28 + 32);
                v41 = *(_QWORD *)(v28 + 48);
                v42 = *(_DWORD *)(v28 + 84);
                v43 = *(_QWORD *)(v28 + 104);
                v60 = *(_QWORD *)(v28 + 88);
                v5 = v27;
                v44 = scnprintf(
                        v62 + (int)v18,
                        (int)(4096 - v18),
                        "[%d]hfence[%u] v:%d err:%u ctx:%llu seq:%llu wait:0x%llx alloc:%d f:0x%llx child_cnt:%d%s ct:%ll"
                        "u tt:%llu wt:%llu ref:0x%x h_synx:%u\n",
                        v29,
                        v30,
                        v33,
                        v34,
                        v36,
                        v37,
                        v35,
                        v40,
                        v41,
                        v42,
                        (const char *)&v65,
                        v60,
                        v32,
                        v43,
                        v38,
                        v39);
                v21 = v31;
                a4 = v61;
                v18 += v44;
                ++v21[464];
                goto LABEL_15;
              }
            }
            v12 = v62;
            v19 = hw_fence_dbg_dump_table_rd_index + v23 + 1;
          }
          hw_fence_dbg_dump_table_rd_index = v19;
          v20 = v18;
          if ( (v18 & 0x80000000) != 0 || v18 > a3 )
          {
            printk(&unk_277B7, "hw_fence_dbg_dump_table_rd", 1076, v5, v18);
          }
          else if ( v18 )
          {
            if ( v18 > 0x1000 )
            {
              _copy_overflow(4096, v18);
            }
            else
            {
              _check_object_size(v12, v18, 1);
              StatusReg = _ReadStatusReg(SP_EL0);
              if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v47 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
                v47 = a2 & ((__int64)(a2 << 8) >> 8);
              if ( 0x8000000000LL - (unsigned __int64)v18 >= v47 )
              {
                v48 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v54 = *(_QWORD *)(StatusReg + 8);
                _WriteStatusReg(TTBR1_EL1, v54 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                _WriteStatusReg(TTBR0_EL1, v54);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v48);
                v55 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v12, v18);
                v56 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v58 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v58 - 4096);
                _WriteStatusReg(TTBR1_EL1, v58);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v56);
                if ( !v55 )
                {
                  *a4 += v18;
LABEL_38:
                  kfree(v12);
                  goto LABEL_43;
                }
              }
            }
            printk(&unk_24E1F, "hw_fence_dbg_dump_table_rd", 1087, v5, v45);
            v20 = -14;
            goto LABEL_38;
          }
          if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
            printk(&unk_2B238, "hw_fence_dbg_dump_table_rd", 1082, a3, v11);
          v20 = 0;
          goto LABEL_38;
        }
        printk(&unk_2776D, "hw_fence_dbg_dump_table_rd", 1063, v4, a3);
        v20 = -22;
      }
    }
    else
    {
      printk(&unk_224FF, "hw_fence_dbg_dump_table_rd", 1051, v4, a1);
      v20 = -22;
    }
  }
  else
  {
    printk(&unk_2A0F5, "hw_fence_dbg_dump_table_rd", 1045, v4, a1);
    v20 = -22;
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return v20;
}
