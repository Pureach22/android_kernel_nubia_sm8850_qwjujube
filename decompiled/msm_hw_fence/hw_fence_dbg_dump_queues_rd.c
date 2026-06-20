__int64 __fastcall hw_fence_dbg_dump_queues_rd(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x25
  unsigned int v5; // w26
  __int64 v6; // x30
  __int64 v7; // x23
  __int64 v8; // x22
  __int64 v12; // x27
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x4
  __int64 v16; // x0
  unsigned int v17; // w27
  __int64 v18; // x25
  unsigned int v19; // w20
  __int64 v20; // x4
  const char *v21; // x11
  unsigned int v22; // w20
  bool v23; // w8
  unsigned __int64 v24; // x24
  __int64 v25; // x0
  __int64 v26; // x22
  const char *v27; // x0
  __int64 v28; // x4
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v30; // x9
  unsigned __int64 v31; // x9
  unsigned __int64 v37; // x8
  __int64 v38; // x0
  unsigned __int64 v39; // x8
  unsigned __int64 v41; // x9
  __int64 queue_type; // x4
  unsigned __int64 v43; // x19
  unsigned __int64 v44; // x21
  __int64 v45; // x20
  _QWORD *v47; // [xsp+38h] [xbp-48h]
  __int64 v48; // [xsp+48h] [xbp-38h]
  unsigned __int64 v49; // [xsp+50h] [xbp-30h]
  __int64 v50; // [xsp+58h] [xbp-28h]
  _DWORD *v51; // [xsp+60h] [xbp-20h] BYREF
  unsigned int *v52; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v53[2]; // [xsp+70h] [xbp-10h] BYREF

  v7 = v6;
  v53[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = nullptr;
  v53[0] = 0;
  v51 = nullptr;
  if ( a1 )
  {
    v8 = *(_QWORD *)(a1 + 32);
    if ( v8 )
    {
      mutex_lock(v8 + 680);
      v12 = *(unsigned int *)(v8 + 512);
      if ( (_DWORD)v12 )
      {
        v13 = *(_QWORD *)(*(_QWORD *)(v8 + 728) + 8 * v12);
        if ( !v13 )
        {
          printk(&unk_208AB, "hw_fence_dbg_dump_queues_rd", 929, v7, (unsigned int)v12);
          v18 = -22;
          goto LABEL_65;
        }
        v14 = (unsigned int)hw_fence_dbg_dump_queues_rd_queue_type;
        if ( (unsigned int)hw_fence_dbg_dump_queues_rd_queue_type <= 2 )
        {
          v15 = *(unsigned int *)(v13 + 136);
          v4 = v13 + 48LL * (unsigned int)hw_fence_dbg_dump_queues_rd_queue_type + 40;
          goto LABEL_9;
        }
      }
      else
      {
        v14 = (unsigned int)hw_fence_dbg_dump_queues_rd_queue_type;
        if ( (unsigned int)hw_fence_dbg_dump_queues_rd_queue_type < 3 )
        {
          v15 = 2;
          v4 = v8 + 48LL * (unsigned int)hw_fence_dbg_dump_queues_rd_queue_type + 216;
LABEL_9:
          v5 = *(_DWORD *)(v4 + 8) >> 6;
          if ( (unsigned int)v14 >= (unsigned int)v15 )
          {
            if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
              printk(&unk_28AFB, "hw_fence_dbg_dump_queues_rd", 941, (unsigned int)v12, v15);
            v18 = 0;
            hw_fence_dbg_dump_queues_rd_queue_type = 0;
            hw_fence_dbg_dump_queues_rd_index = 0;
            goto LABEL_65;
          }
          if ( !v4 || !*(_QWORD *)(v4 + 16) || !*(_QWORD *)v4 )
          {
            get_queue_type(v14);
            printk(&unk_23E85, "hw_fence_dbg_dump_queues_rd", 951, v7, (unsigned int)v12);
            v18 = -22;
            goto LABEL_65;
          }
          if ( a3 <= 0x4D )
          {
            printk(&unk_208E3, "hw_fence_dbg_dump_queues_rd", 958, v7, a3);
            v18 = -22;
            goto LABEL_65;
          }
          v16 = _kvmalloc_node_noprof(4096, 0, 3520, 0xFFFFFFFFLL);
          if ( v16 )
          {
LABEL_15:
            v49 = a3;
            v50 = v16;
            v48 = v8;
            v47 = a4;
            if ( (hw_fence_dbg_dump_queues_rd_qhdr_dumped & 1) != 0 )
            {
              v17 = 0;
            }
            else
            {
              __dsb(0xFu);
              v19 = hw_fence_dbg_dump_queues_rd_queue_type;
              hw_fence_get_queue_idx_ptrs(v8, *(_QWORD *)(v4 + 16), v53, &v52, &v51);
              if ( (~msm_hw_fence_debug_level & 0x10004) == 0 )
              {
                queue_type = get_queue_type(v19);
                printk(&unk_2903F, "_dump_queue_header", 802, (unsigned int)v12, queue_type);
              }
              v20 = get_queue_type((unsigned int)hw_fence_dbg_dump_queues_rd_queue_type);
              v21 = "false";
              if ( *(_BYTE *)(v4 + 40) )
                v21 = "true";
              v17 = scnprintf(
                      v50,
                      4096,
                      "Client:%d %s q_sz_bytes:%u rd_idx:%u wr_idx:%u tx_wm:%u skips:%s start:%u factor:%u\n",
                      (unsigned int)v12,
                      v20,
                      *(unsigned int *)(v4 + 8),
                      *(unsigned int *)v53[0],
                      *v52,
                      *v51,
                      v21,
                      *(_DWORD *)(v4 + 32),
                      *(_DWORD *)(v4 + 36));
              hw_fence_dbg_dump_queues_rd_qhdr_dumped = 1;
            }
            v22 = hw_fence_dbg_dump_queues_rd_index;
            v23 = hw_fence_dbg_dump_queues_rd_index < v5;
            if ( hw_fence_dbg_dump_queues_rd_index < v5 && v17 <= 0xFB1 )
            {
              do
              {
                v24 = *(_QWORD *)v4 + ((unsigned __int64)v22 << 6);
                if ( (~msm_hw_fence_debug_level & 0x10004) != 0 )
                {
                  if ( !*(_QWORD *)(v24 + 24) )
                    goto LABEL_30;
                }
                else
                {
                  v25 = get_queue_type((unsigned int)hw_fence_dbg_dump_queues_rd_queue_type);
                  printk(&unk_20E93, "_dump_queue_payload", 820, v25, v22);
                  if ( !*(_QWORD *)(v24 + 24) )
                  {
LABEL_30:
                    if ( !*(_QWORD *)(v24 + 8)
                      && !*(_QWORD *)(v24 + 16)
                      && !*(_QWORD *)(v24 + 32)
                      && !*(_QWORD *)(v24 + 40)
                      && !*(_DWORD *)(v24 + 48)
                      && !*(_DWORD *)(v24 + 52)
                      && !*(_DWORD *)(v24 + 56)
                      && !*(_WORD *)(v24 + 4) )
                    {
                      goto LABEL_41;
                    }
                  }
                }
                v26 = *(_QWORD *)(v24 + 52);
                v27 = (const char *)get_queue_type((unsigned int)hw_fence_dbg_dump_queues_rd_queue_type);
                v17 += scnprintf(
                         v50 + v17,
                         4096 - v17,
                         "%s[%d]: hash:%llu ctx:%llu seqno:%llu f:%llu d:%llu err:%u time:%llu type:%u\n",
                         v27,
                         hw_fence_dbg_dump_queues_rd_index,
                         *(_QWORD *)(v24 + 24),
                         *(_QWORD *)(v24 + 8),
                         *(_QWORD *)(v24 + 16),
                         *(_QWORD *)(v24 + 32),
                         *(_QWORD *)(v24 + 40),
                         *(_DWORD *)(v24 + 48),
                         v26,
                         *(unsigned __int16 *)(v24 + 4));
LABEL_41:
                v22 = ++hw_fence_dbg_dump_queues_rd_index;
                v23 = hw_fence_dbg_dump_queues_rd_index < v5;
                if ( hw_fence_dbg_dump_queues_rd_index >= v5 )
                  goto LABEL_44;
              }
              while ( v17 < 0xFB2 );
            }
            if ( !v23 )
            {
LABEL_44:
              hw_fence_dbg_dump_queues_rd_index = 0;
              ++hw_fence_dbg_dump_queues_rd_queue_type;
              hw_fence_dbg_dump_queues_rd_qhdr_dumped = 0;
            }
            if ( (int)v17 >= 1 )
            {
              v18 = v17;
              if ( v17 <= v49 )
              {
                v8 = v48;
                if ( v17 > 0x1000 )
                {
                  _copy_overflow(4096, v17);
                }
                else
                {
                  _check_object_size(v50, v17, 1);
                  StatusReg = _ReadStatusReg(SP_EL0);
                  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v30 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
                    v30 = a2 & ((__int64)(a2 << 8) >> 8);
                  if ( 0x8000000000LL - (unsigned __int64)v17 >= v30 )
                  {
                    v31 = _ReadStatusReg(DAIF);
                    __asm { MSR             DAIFSet, #3 }
                    v37 = *(_QWORD *)(StatusReg + 8);
                    _WriteStatusReg(
                      TTBR1_EL1,
                      v37 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                    _WriteStatusReg(TTBR0_EL1, v37);
                    __isb(0xFu);
                    _WriteStatusReg(DAIF, v31);
                    v38 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v50, v17);
                    v39 = _ReadStatusReg(DAIF);
                    __asm { MSR             DAIFSet, #3 }
                    v41 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                    _WriteStatusReg(TTBR0_EL1, v41 - 4096);
                    _WriteStatusReg(TTBR1_EL1, v41);
                    __isb(0xFu);
                    _WriteStatusReg(DAIF, v39);
                    if ( !v38 )
                    {
                      *v47 += v17;
LABEL_54:
                      kvfree(v50);
LABEL_65:
                      mutex_unlock(v8 + 680);
                      goto LABEL_66;
                    }
                  }
                }
                printk(&unk_24E1F, "hw_fence_dbg_dump_queues_rd", 1009, v7, v28);
                v18 = -14;
                goto LABEL_54;
              }
            }
            printk(&unk_277B7, "hw_fence_dbg_dump_queues_rd", 1003, v7, v17);
            v8 = v48;
            v18 = 0;
            goto LABEL_54;
          }
LABEL_64:
          v18 = -12;
          goto LABEL_65;
        }
      }
      __break(0x5512u);
      v43 = _ReadStatusReg(SP_EL0);
      v44 = a3;
      v45 = *(_QWORD *)(v43 + 80);
      *(_QWORD *)(v43 + 80) = &hw_fence_dbg_dump_queues_rd__alloc_tag;
      v16 = _kvmalloc_node_noprof(4096, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v43 + 80) = v45;
      a3 = v44;
      if ( v16 )
        goto LABEL_15;
      goto LABEL_64;
    }
  }
  printk(&unk_2A0F5, "hw_fence_dbg_dump_queues_rd", 918, v6, a1);
  v18 = -22;
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return v18;
}
