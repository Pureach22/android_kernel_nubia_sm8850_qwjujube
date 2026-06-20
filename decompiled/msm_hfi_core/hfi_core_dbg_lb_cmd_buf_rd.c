__int64 __fastcall hfi_core_dbg_lb_cmd_buf_rd(__int64 a1, unsigned __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // x30
  __int64 v6; // x8
  _QWORD *v7; // x28
  __int64 v8; // x22
  __int64 v9; // x3
  __int64 v10; // x20
  _QWORD *v11; // x19
  _QWORD *v12; // t1
  unsigned int v13; // w27
  unsigned int v14; // w5
  int v15; // w0
  int v16; // w8
  int v17; // w21
  size_t v18; // x24
  __int64 v19; // x0
  const char *v20; // x25
  __int64 v21; // x26
  unsigned int v22; // w0
  size_t v23; // x0
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v25; // x10
  __int64 v26; // x0
  _QWORD *v28; // x10
  unsigned __int64 v29; // x10
  unsigned __int64 v34; // x9
  unsigned __int64 v35; // x8
  unsigned __int64 v37; // x9
  void *v38; // x0
  __int64 v39; // x2
  unsigned __int64 v40; // x19
  __int64 v41; // x21
  __int64 v42; // [xsp+8h] [xbp-18h]

  if ( !*a4 )
  {
    if ( a2 )
    {
      if ( !a1 || (v6 = *(_QWORD *)(a1 + 32)) == 0 )
      {
        printk(&unk_1F30A, "hfi_core_dbg_lb_cmd_buf_rd", 1767, v4);
        return -22;
      }
      v7 = *(_QWORD **)(v6 + 792);
      if ( v7 )
      {
        v8 = v4;
        v10 = _kmalloc_cache_noprof(alloc_pages_exact_noprof, 3520, 4096);
        if ( !v10 )
          return -12;
        while ( 1 )
        {
          v12 = (_QWORD *)v7[15];
          v7 += 15;
          v11 = v12;
          if ( v12 == v7 )
          {
            if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
              printk(&unk_1D511, "hfi_core_dbg_lb_cmd_buf_rd", 1783, v9);
            return 0;
          }
          v13 = 0;
          _ReadStatusReg(SP_EL0);
          v42 = v8;
          while ( 1 )
          {
            v14 = *((_DWORD *)v11 - 2);
            if ( v14 > 0x1000 )
            {
              v4 = v42;
              v38 = &unk_1CB46;
              v39 = 1789;
              goto LABEL_37;
            }
            v15 = scnprintf(
                    v10 + v13,
                    4096 - v13,
                    "hfi_cmd: 0x%x flags: 0x%x payload_size: 0x%x\npayload:",
                    *((_DWORD *)v11 - 6),
                    *((_DWORD *)v11 - 1),
                    v14);
            v16 = *((_DWORD *)v11 - 2);
            v13 += v15;
            if ( v16 )
              break;
LABEL_11:
            v11 = (_QWORD *)*v11;
            if ( v11 == v7 )
            {
              if ( v13 > 0x1000 )
              {
                _copy_overflow(4096, v13);
              }
              else
              {
                _check_object_size(v10, v13, 1);
                StatusReg = _ReadStatusReg(SP_EL0);
                if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v25 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
                  v25 = a2 & ((__int64)(a2 << 8) >> 8);
                v26 = v13;
                _CF = 0x8000000000LL - (unsigned __int64)v13 >= v25;
                v28 = a4;
                if ( _CF )
                {
                  v29 = _ReadStatusReg(DAIF);
                  __asm { MSR             DAIFSet, #3 }
                  v34 = *(_QWORD *)(StatusReg + 8);
                  _WriteStatusReg(TTBR1_EL1, v34 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                  _WriteStatusReg(TTBR0_EL1, v34);
                  __isb(0xFu);
                  _WriteStatusReg(DAIF, v29);
                  v26 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v10, v13);
                  v28 = a4;
                  v35 = _ReadStatusReg(DAIF);
                  __asm { MSR             DAIFSet, #3 }
                  v37 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                  _WriteStatusReg(TTBR0_EL1, v37 - 4096);
                  _WriteStatusReg(TTBR1_EL1, v37);
                  __isb(0xFu);
                  _WriteStatusReg(DAIF, v35);
                }
                if ( !v26 )
                {
                  *v28 += v13;
LABEL_33:
                  kfree(v10);
                  return v13;
                }
              }
              printk(&unk_19BF9, "hfi_core_dbg_lb_cmd_buf_rd", 1827, v42);
              v13 = -14;
              goto LABEL_33;
            }
          }
          v17 = (10 * v16) | 1;
          v18 = v17;
          v19 = _kmalloc_noprof(v17, 3520);
          v20 = (const char *)v19;
          if ( !v19 )
            return -12;
          if ( *((_DWORD *)v11 - 2) )
          {
            LODWORD(v8) = 0;
            v21 = v19;
            do
            {
              v22 = scnprintf(v21, v17, "0x%x ", *(_DWORD *)(*(v11 - 2) + 4LL * (int)v8));
              v8 = (unsigned int)(v8 + 1);
              v21 += v22;
              v17 -= v22;
            }
            while ( (unsigned int)v8 < *((_DWORD *)v11 - 2) );
          }
          v23 = strnlen(v20, v18);
          if ( v23 > v18 )
            goto LABEL_43;
          if ( v23 < v18 )
            break;
          v23 = _fortify_panic(4, v18, v23 + 1);
LABEL_43:
          _fortify_panic(2, v18, v23 + 1);
          v40 = _ReadStatusReg(SP_EL0);
          v41 = *(_QWORD *)(v40 + 80);
          *(_QWORD *)(v40 + 80) = &hfi_core_dbg_lb_cmd_buf_rd__alloc_tag;
          v10 = _kmalloc_cache_noprof(alloc_pages_exact_noprof, 3520, 4096);
          *(_QWORD *)(v40 + 80) = v41;
          if ( !v10 )
            return -12;
        }
        if ( !(_DWORD)v23 )
        {
          printk(&unk_1F72B, "hfi_core_dbg_lb_cmd_buf_rd", 1816, v42);
          goto LABEL_33;
        }
        v13 += scnprintf(v10 + v13, 4096 - v13, "%s\n", v20);
        kfree(v20);
        goto LABEL_11;
      }
      v38 = &unk_1A52F;
      v39 = 1774;
    }
    else
    {
      v38 = &unk_197DB;
      v39 = 1762;
    }
LABEL_37:
    printk(v38, "hfi_core_dbg_lb_cmd_buf_rd", v39, v4);
    return -22;
  }
  return 0;
}
