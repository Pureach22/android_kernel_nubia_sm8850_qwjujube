__int64 __fastcall mem_buf_acl_to_vmid_perms_list(unsigned int a1, __int64 a2, __int64 *a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 v9; // x25
  __int64 v10; // x19
  unsigned __int64 v11; // x26
  __int64 v12; // x24
  int v13; // w9
  unsigned __int64 StatusReg; // x27
  __int64 v15; // x8
  unsigned __int64 v16; // x10
  __int64 v17; // x20
  unsigned __int64 v18; // x9
  unsigned __int64 v24; // x10
  size_t v25; // x2
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x9
  int v29; // w0
  unsigned int v30; // w9
  unsigned int v31; // w10
  unsigned int v32; // w9
  unsigned int v33; // w21
  unsigned __int64 v34; // x20
  __int64 v35; // x24
  _QWORD *v36; // [xsp+8h] [xbp-18h]
  _QWORD v37[2]; // [xsp+10h] [xbp-10h] BYREF

  result = 4294967274LL;
  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v37[0] = 0;
    v9 = 4LL * a1;
    v10 = _kmalloc_noprof(v9, 3264);
    if ( !v10 )
      goto LABEL_34;
    while ( 1 )
    {
      v11 = 4LL * a1;
      v12 = _kmalloc_noprof(v11, 3264);
      if ( !v12 )
      {
        kfree(v10);
        goto LABEL_34;
      }
      v36 = (_QWORD *)a4;
      v13 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      a4 = 0x7FFFFFFFF8LL;
      while ( 1 )
      {
        v15 = a2 + 8LL * v13;
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v16 = a2 + 8LL * v13, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v16 = v15 & (v15 << 8 >> 8);
        if ( v16 > 0x7FFFFFFFF8LL )
        {
          v25 = 8;
LABEL_22:
          if ( v25 >= 9 )
            goto LABEL_31;
          memset((char *)&v37[1] - v25, 0, v25);
          v33 = -14;
LABEL_28:
          kfree(v12);
          kfree(v10);
          result = v33;
          goto LABEL_35;
        }
        v17 = v13;
        v18 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v24 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v24 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v24);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v18);
        v25 = _arch_copy_from_user(v37, v15 & 0xFF7FFFFFFFFFFFFFLL, 8);
        v26 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v28 - 4096);
        _WriteStatusReg(TTBR1_EL1, v28);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v26);
        if ( v25 )
          goto LABEL_22;
        v29 = mem_buf_fd_to_vmid(LODWORD(v37[0]));
        if ( v9 <= 4 * v17 )
          goto LABEL_30;
        v30 = HIDWORD(v37[0]);
        *(_DWORD *)(v10 + 4 * v17) = v29;
        if ( v30 >= 8 )
          break;
        if ( v11 <= 4 * v17 )
          goto LABEL_30;
        v31 = __rbit32(v30 & 3) >> 29;
        v32 = v30 <= 3 ? v31 : v31 + 1;
        *(_DWORD *)(v12 + 4 * v17) = v32;
        if ( v9 <= 4 * v17 )
          goto LABEL_30;
        if ( (*(_DWORD *)(v10 + 4 * v17) & 0x80000000) != 0 )
        {
          v33 = -22;
          goto LABEL_28;
        }
        v13 = v17 + 1;
        if ( a1 == (_DWORD)v17 + 1 )
        {
          result = 0;
          *a3 = v10;
          *v36 = v12;
          goto LABEL_35;
        }
      }
      if ( (unsigned int)__ratelimit(&is_valid_mem_buf_perms__rs, "is_valid_mem_buf_perms") )
      {
        printk(&unk_9CCC, "is_valid_mem_buf_perms");
        if ( v11 <= 4 * v17 )
          goto LABEL_30;
LABEL_26:
        v33 = -22;
        *(_DWORD *)(v12 + 4 * v17) = -22;
        goto LABEL_28;
      }
      if ( v11 > 4 * v17 )
        goto LABEL_26;
LABEL_30:
      __break(1u);
LABEL_31:
      _fortify_panic(15, 0);
      v9 = 4LL * a1;
      v34 = _ReadStatusReg(SP_EL0);
      v35 = *(_QWORD *)(v34 + 80);
      *(_QWORD *)(v34 + 80) = &_start_alloc_tags;
      v10 = _kmalloc_noprof(v9, 3264);
      *(_QWORD *)(v34 + 80) = v35;
      if ( !v10 )
      {
LABEL_34:
        result = 4294967284LL;
        break;
      }
    }
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
