__int64 __fastcall nc_override_set(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  _DWORD *v4; // x23
  __int64 result; // x0
  unsigned __int64 v8; // x22
  const char *v9; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x9
  size_t v12; // x2
  size_t v13; // x1
  __int64 v14; // x20
  unsigned __int64 v15; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9
  unsigned int v25; // w9
  _DWORD *v26; // x11
  int v27; // w8
  int v28; // w0
  int v29; // w8
  unsigned __int64 v30; // x25
  __int64 v31; // x26
  __int64 v32; // [xsp+0h] [xbp-10h] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v4 = *(_DWORD **)(v3 + 24552);
  if ( !v4 )
  {
    result = 0;
    goto LABEL_33;
  }
  if ( (unsigned __int64)(a3 - 4096) >= 0xFFFFFFFFFFFFF001LL )
  {
    v32 = 0;
    v8 = a3 + 1;
    v9 = (const char *)_kmalloc_noprof(a3 + 1, 3520);
    if ( !v9 )
    {
LABEL_32:
      result = -12;
      goto LABEL_33;
    }
    while ( 1 )
    {
      _check_object_size(v9, a3, 0);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v11 = a2 & ((__int64)(a2 << 8) >> 8);
      v12 = a3;
      if ( 0x8000000000LL - a3 >= v11 )
      {
        v15 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v21 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v21);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v15);
        v12 = _arch_copy_from_user(v9, a2 & 0xFF7FFFFFFFFFFFFFLL, a3);
        v22 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v24 - 4096);
        _WriteStatusReg(TTBR1_EL1, v24);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v22);
        if ( !v12 )
          break;
      }
      if ( v8 >= a3 - v12 )
        v13 = v8 - (a3 - v12);
      else
        v13 = 0;
      if ( v13 >= v12 )
      {
        memset((void *)&v9[a3 - v12], 0, v12);
        v14 = -14;
        goto LABEL_30;
      }
      _fortify_panic(15, v13, v12);
      v8 = a3 + 1;
      v30 = _ReadStatusReg(SP_EL0);
      v31 = *(_QWORD *)(v30 + 80);
      *(_QWORD *)(v30 + 80) = &nc_override_set__alloc_tag;
      v9 = (const char *)_kmalloc_noprof(a3 + 1, 3520);
      *(_QWORD *)(v30 + 80) = v31;
      if ( !v9 )
        goto LABEL_32;
    }
    v9[a3] = 0;
    if ( !sscanf(v9, "0x%x:0x%x", (char *)&v32 + 4, &v32) )
      goto LABEL_29;
    mutex_lock(v3 + 24560);
    if ( *v4 )
    {
      if ( *v4 == HIDWORD(v32) )
      {
LABEL_23:
        v27 = v32;
        *((_BYTE *)v4 + 12) = 1;
        v4[2] = v27;
        mutex_unlock(v3 + 24560);
        if ( a3 >= 1 )
        {
          v28 = adreno_power_cycle(v3, (void (__fastcall *)(__int64, __int64))nc_override_cb, 0);
          if ( v28 )
            v29 = v28;
          else
            v29 = a3;
          v14 = v29;
          goto LABEL_30;
        }
LABEL_29:
        v14 = -22;
LABEL_30:
        kfree(v9);
        result = v14;
        goto LABEL_33;
      }
      v25 = 1;
      while ( 1 )
      {
        v26 = &v4[5 * v25];
        if ( !*v26 )
          break;
        ++v25;
        if ( *v26 == HIDWORD(v32) )
        {
          v4 = v26;
          goto LABEL_23;
        }
      }
    }
    mutex_unlock(v3 + 24560);
    goto LABEL_29;
  }
  result = -22;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
