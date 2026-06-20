__int64 __fastcall hfi_core_dbg_dump_events_rd(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x22
  const char *v6; // x19
  char *v7; // x27
  _QWORD *v9; // x21
  __int64 v11; // x19
  __int64 v12; // x25
  __int64 v13; // x3
  unsigned __int64 v14; // x8
  __int64 v15; // x20
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x9
  unsigned __int64 v23; // x8
  __int64 v24; // x0
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x9
  __int64 v28; // x28
  __int64 v29; // x20
  unsigned int v30; // w26
  const char *v31; // x3
  const char *v32; // x2
  int v33; // w0
  __int64 v34; // x25
  unsigned int *v35; // x26
  unsigned int v36; // t1
  char v37; // w8
  int v38; // w22
  unsigned __int64 StatusReg; // x20
  __int64 v40; // x21
  unsigned __int64 v42; // [xsp+0h] [xbp-B0h]
  _QWORD *v43; // [xsp+8h] [xbp-A8h]
  __int64 v44; // [xsp+18h] [xbp-98h]
  __int64 v45; // [xsp+28h] [xbp-88h]
  _QWORD v46[13]; // [xsp+30h] [xbp-80h] BYREF
  int v47; // [xsp+98h] [xbp-18h]
  __int64 v48; // [xsp+A0h] [xbp-10h]

  v5 = v4;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v6 = *(const char **)(a1 + 32)) != nullptr )
  {
    if ( *((_QWORD *)v6 + 101) )
    {
      v7 = (char *)&unk_1F000;
      v9 = (_QWORD *)a3;
      if ( hfi_core_dbg_dump_events_rd_wraparound != 1 || hfi_core_dbg_dump_events_rd_index < 0 )
      {
        if ( a3 <= 0x3F )
        {
          printk(&unk_1EA15, "hfi_core_dbg_dump_events_rd", 2780, v4);
          v11 = -22;
          goto LABEL_59;
        }
        v12 = _kmalloc_cache_noprof(alloc_pages_exact_noprof, 3520, 4096);
        if ( !v12 )
          goto LABEL_58;
LABEL_11:
        v45 = *(_QWORD *)(*((_QWORD *)v6 + 101) + 8LL);
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          printk(&unk_1A1EF, "hfi_core_dbg_dump_events_rd", 2789, v45);
        v43 = (_QWORD *)a4;
        v13 = (unsigned int)hfi_core_dbg_dump_events_rd_index;
        v42 = a2;
        v44 = v5;
        if ( v7[2856] != 1 || hfi_core_dbg_dump_events_rd_index < 0 )
        {
          a2 = 0;
          a4 = 108;
          v6 = "0x%lx ";
          while ( 1 )
          {
            v28 = (int)v13;
            v29 = v45 + ((__int64)(int)v13 << 6);
            v30 = *(_DWORD *)(v29 + 8);
            if ( v30 )
            {
              v47 = 0;
              memset(v46, 0, sizeof(v46));
              if ( v30 >= 0xD )
              {
                printk(&unk_1943D, "_dump_event", 2711, v44);
                v30 = 12;
              }
              v31 = (const char *)*(unsigned int *)(v29 + 12);
              v7 = (char *)v12;
              if ( (_DWORD)v31 == 48879 )
              {
                v32 = "%s: ";
                v31 = "init trace dumps. [max trace events][trace mem ptr]";
              }
              else
              {
                v32 = "0x%lx ";
              }
              v5 = (unsigned int)scnprintf(v46, 108, v32, v31);
              if ( v30 != 1 )
              {
                v34 = v30 - 1LL;
                v35 = (unsigned int *)(v45 + 16 + (v28 << 6));
                while ( (unsigned int)v5 <= 0x6C )
                {
                  v36 = *v35++;
                  --v34;
                  v5 = (unsigned int)scnprintf((char *)v46 + (unsigned int)v5, (unsigned int)(108 - v5), "0x%lx ", v36)
                     + (unsigned int)v5;
                  if ( !v34 )
                    goto LABEL_40;
                }
                __break(0x5512u);
                StatusReg = _ReadStatusReg(SP_EL0);
                v40 = *(_QWORD *)(StatusReg + 80);
                *(_QWORD *)(StatusReg + 80) = &hfi_core_dbg_dump_events_rd__alloc_tag;
                v12 = _kmalloc_cache_noprof(alloc_pages_exact_noprof, 3520, 4096);
                *(_QWORD *)(StatusReg + 80) = v40;
                v9 = v46;
                if ( !v12 )
                {
LABEL_58:
                  v11 = -12;
                  goto LABEL_59;
                }
                goto LABEL_11;
              }
LABEL_40:
              v12 = (__int64)v7;
              v33 = scnprintf(
                      &v7[(unsigned int)a2],
                      (unsigned int)(4096 - a2),
                      "[%d][t:%llu][evt:0x%llx] data[%d]:%s\n",
                      v28,
                      *(_QWORD *)v29,
                      v29,
                      *(_DWORD *)(v29 + 8),
                      (const char *)v46);
              if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
              {
                v38 = v33;
                printk(&unk_1F347, "_dump_event", 2737, (unsigned int)v28);
                v33 = v38;
              }
              v7 = (char *)&unk_1F000;
            }
            else
            {
              v33 = 0;
            }
            v13 = (unsigned int)++hfi_core_dbg_dump_events_rd_index;
            if ( hfi_core_dbg_dump_events_rd_index <= 3999 )
            {
              v37 = v7[2856];
            }
            else
            {
              v13 = 0;
              v37 = 1;
              hfi_core_dbg_dump_events_rd_index = 0;
              v7[2856] = 1;
            }
            a2 = (unsigned int)(v33 + a2);
            if ( (int)v13 < 0 )
              v37 = 0;
            if ( (v37 & 1) != 0 || (unsigned int)a2 >= 0xFC0 )
              goto LABEL_16;
          }
        }
        LODWORD(a2) = 0;
LABEL_16:
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          printk(&unk_1B9D8, "hfi_core_dbg_dump_events_rd", 2800, v13);
        if ( (int)a2 < 1 || (v11 = (unsigned int)a2, (unsigned int)a2 > (unsigned __int64)v9) )
        {
          printk(&unk_1AA1D, "hfi_core_dbg_dump_events_rd", 2804, v44);
          v11 = 0;
        }
        else
        {
          if ( (unsigned int)a2 > 0x1000 )
          {
            _copy_overflow(4096, (unsigned int)a2);
            v15 = v44;
          }
          else
          {
            _check_object_size(v12, (unsigned int)a2, 1);
            v14 = _ReadStatusReg(SP_EL0);
            v15 = v44;
            if ( (*(_BYTE *)(v14 + 70) & 0x20) != 0 || (v16 = v42, (*(_QWORD *)v14 & 0x4000000) != 0) )
              v16 = v42 & ((__int64)(v42 << 8) >> 8);
            if ( 0x8000000000LL - (unsigned __int64)(unsigned int)a2 >= v16 )
            {
              v17 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v23 = *(_QWORD *)(v14 + 8);
              _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v23);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v17);
              v24 = _arch_copy_to_user(v42 & 0xFF7FFFFFFFFFFFFFLL, v12, (unsigned int)a2);
              v25 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v27 - 4096);
              _WriteStatusReg(TTBR1_EL1, v27);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v25);
              if ( !v24 )
              {
                *v43 += (unsigned int)a2;
                goto LABEL_27;
              }
            }
          }
          printk(&unk_1BA09, "hfi_core_dbg_dump_events_rd", 2810, v15);
          v11 = -14;
        }
LABEL_27:
        kfree(v12);
      }
      else
      {
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          printk(&unk_1DED8, "hfi_core_dbg_dump_events_rd", 2771, (unsigned int)hfi_core_dbg_dump_events_rd_index);
        v11 = 0;
        hfi_core_dbg_dump_events_rd_index = 0;
        hfi_core_dbg_dump_events_rd_wraparound = 0;
      }
    }
    else
    {
      printk(&unk_1979E, "hfi_core_dbg_dump_events_rd", 2765, v4);
      v11 = -22;
    }
  }
  else
  {
    printk(&unk_1F30A, "hfi_core_dbg_dump_events_rd", 2755, v4);
    v11 = -22;
  }
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return v11;
}
