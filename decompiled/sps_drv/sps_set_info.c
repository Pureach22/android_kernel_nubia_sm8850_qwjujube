__int64 __fastcall sps_set_info(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  _DWORD *v3; // x23
  _BYTE *v4; // x24
  __int64 v5; // x25
  __int64 v6; // x19
  _BYTE *v8; // x20
  unsigned __int64 StatusReg; // x22
  unsigned __int64 v10; // x8
  _BYTE *v11; // x21
  unsigned __int64 v12; // x1
  __int64 v13; // x2
  unsigned __int64 v14; // x8
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  __int64 v24; // x8
  unsigned int v25; // w20
  int v26; // w11
  __int64 v27; // x1
  __int64 v28; // x2
  unsigned int v29; // w26
  __int64 v30; // x1
  __int64 v31; // x2
  void *v32; // x0
  __int64 v33; // x0
  __int64 v34; // x26
  __int64 v35; // x0
  _QWORD v37[11]; // [xsp+8h] [xbp-58h] BYREF

  v6 = a3;
  v37[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 0x50 )
    v8 = (_BYTE *)&unk_50;
  else
    v8 = (_BYTE *)a3;
  memset(v37, 0, 80);
  _check_object_size(v37, v8, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v10 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v10 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( 0x8000000000LL - (__int64)v8 >= v10 )
  {
    v14 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v14);
    v11 = (_BYTE *)_arch_copy_from_user(v37, a2 & 0xFF7FFFFFFFFFFFFFLL, v8);
    v21 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v23 - 4096);
    _WriteStatusReg(TTBR1_EL1, v23);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v21);
    if ( !v11 )
      goto LABEL_16;
  }
  else
  {
    v11 = v8;
  }
  if ( (unsigned __int64)(v8 - v11) <= 0x50 )
    v12 = 80 - (v8 - v11);
  else
    v12 = 0;
  if ( v12 < (unsigned __int64)v11 )
  {
    _fortify_panic(15);
    v33 = *((unsigned int *)v11 + 102);
    v34 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &sps_set_info__alloc_tag;
    v35 = _kmalloc_noprof(v33, 3520);
    *(_QWORD *)(StatusReg + 80) = v34;
    *(_QWORD *)(v5 + 416) = v35;
    if ( v35 )
      goto LABEL_26;
    goto LABEL_34;
  }
  memset((char *)v37 + v8 - v11, 0, (size_t)v11);
  if ( !v11 )
  {
LABEL_16:
    v24 = 0;
    v25 = 0;
    do
    {
      v26 = *((unsigned __int8 *)v37 + v24);
      if ( (unsigned int)(v26 - 48) > 9 )
        break;
      ++v24;
      v25 = v26 + 10 * v25 - 48;
    }
    while ( v24 != 80 );
    printk(&unk_26272, v25, v13);
    if ( (logging_option & 0xFD) != 0 )
    {
      if ( v25 )
      {
        if ( v25 < 0x200000 )
        {
          v29 = v25 << 10;
          mutex_lock(&sps_debugfs_lock);
          v8 = &loc_2C000;
          v11 = &loc_2C000;
          v3 = &loc_2C000;
          v4 = &loc_2C000;
          if ( debugfs_record_enabled )
          {
            if ( debugfs_buf_size == v29 )
            {
              printk(&unk_2AE04, v30, v31);
              goto LABEL_27;
            }
            debugfs_record_enabled = 0;
            debugfs_buf_used = 0;
            wraparound = 0;
            kfree(debugfs_buf);
            debugfs_buf = 0;
          }
          debugfs_buf_size = v29;
          debugfs_buf = _kmalloc_noprof(v29, 3520);
          if ( debugfs_buf )
          {
LABEL_26:
            v3[101] = 0;
            v4[412] = 0;
            v8[400] = 1;
LABEL_27:
            mutex_unlock(&sps_debugfs_lock);
            goto LABEL_35;
          }
LABEL_34:
          *((_DWORD *)v11 + 102) = 0;
          mutex_unlock(&sps_debugfs_lock);
          v6 = -12;
          goto LABEL_35;
        }
        v32 = &unk_254D1;
      }
      else
      {
        v32 = &unk_2629C;
      }
    }
    else
    {
      v32 = &unk_29E70;
    }
    printk(v32, v27, v28);
    v6 = -14;
    goto LABEL_35;
  }
  v6 = -14;
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return v6;
}
