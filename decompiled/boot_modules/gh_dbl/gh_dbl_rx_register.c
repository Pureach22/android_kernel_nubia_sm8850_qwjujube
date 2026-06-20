__int64 __fastcall gh_dbl_rx_register(int a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 *v5; // x22
  int v6; // w23
  unsigned int v7; // w21
  __int64 v8; // x21
  unsigned __int64 StatusReg; // x24
  __int64 v11; // x25
  __int64 v12; // x0

  if ( (unsigned int)(a1 - 266) <= 0xFFFFFFF5 )
  {
    printk(&unk_76E7, 256);
    return -22;
  }
  if ( gh_dbl_initialized == 1 )
  {
    v7 = a1 & 0xF;
    if ( v7 >= 0xB )
    {
      __break(0x5512u);
    }
    else
    {
      v5 = &gh_dbl_cap_table[12 * (a1 & 0xF)];
      v6 = a1;
      v3 = a3;
      v4 = a2;
      raw_spin_lock(v5 + 1);
      if ( v7 != 10 )
      {
        if ( *((_DWORD *)v5 + 11) )
        {
          v8 = -16;
LABEL_12:
          raw_spin_unlock(v5 + 1);
          return v8;
        }
        v8 = *v5;
        if ( *v5 )
        {
LABEL_11:
          v5[7] = v4;
          v5[8] = v3;
          *((_DWORD *)v5 + 11) = 1;
          goto LABEL_12;
        }
        v8 = _kmalloc_cache_noprof(_wake_up, 2336, 4);
        if ( v8 )
        {
LABEL_10:
          *(_DWORD *)v8 = v6;
          *v5 = v8;
          goto LABEL_11;
        }
LABEL_17:
        v8 = -12;
        goto LABEL_12;
      }
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = *(_QWORD *)(StatusReg + 80);
    v12 = _wake_up;
    *(_QWORD *)(StatusReg + 80) = &gh_dbl_rx_register__alloc_tag;
    v8 = _kmalloc_cache_noprof(v12, 2336, 4);
    *(_QWORD *)(StatusReg + 80) = v11;
    if ( v8 )
      goto LABEL_10;
    goto LABEL_17;
  }
  return -517;
}
