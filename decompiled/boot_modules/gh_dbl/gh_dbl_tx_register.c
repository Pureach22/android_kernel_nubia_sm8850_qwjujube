__int64 __fastcall gh_dbl_tx_register(int a1)
{
  __int64 *v1; // x20
  int v2; // w21
  unsigned int v3; // w19
  __int64 v4; // x19
  unsigned __int64 StatusReg; // x22
  __int64 v7; // x23
  __int64 v8; // x0

  if ( (unsigned int)(a1 - 266) <= 0xFFFFFFF5 )
  {
    printk(&unk_76E7, 256);
    return -22;
  }
  if ( gh_dbl_initialized == 1 )
  {
    v3 = a1 & 0xF;
    if ( v3 < 0xB )
    {
      v1 = &gh_dbl_cap_table[12 * (a1 & 0xF)];
      v2 = a1;
      raw_spin_lock(v1 + 1);
      if ( ((96LL * v3) | 0x18uLL) <= 0x3C0 )
      {
        if ( *((_DWORD *)v1 + 6) )
        {
          v4 = -16;
LABEL_13:
          raw_spin_unlock(v1 + 1);
          return v4;
        }
        if ( v3 != 10 )
        {
          v4 = *v1;
          if ( *v1 )
          {
LABEL_12:
            *((_DWORD *)v1 + 6) = 1;
            goto LABEL_13;
          }
          v4 = _kmalloc_cache_noprof(_wake_up, 2336, 4);
          if ( v4 )
          {
LABEL_11:
            *(_DWORD *)v4 = v2;
            *v1 = v4;
            goto LABEL_12;
          }
LABEL_18:
          v4 = -12;
          goto LABEL_13;
        }
      }
      __break(1u);
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v7 = *(_QWORD *)(StatusReg + 80);
    v8 = _wake_up;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v4 = _kmalloc_cache_noprof(v8, 2336, 4);
    *(_QWORD *)(StatusReg + 80) = v7;
    if ( v4 )
      goto LABEL_11;
    goto LABEL_18;
  }
  return -517;
}
