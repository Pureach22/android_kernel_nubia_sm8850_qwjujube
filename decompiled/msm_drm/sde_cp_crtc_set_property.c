__int64 __fastcall sde_cp_crtc_set_property(char *a1, unsigned int *a2, _DWORD *a3, unsigned __int64 a4)
{
  unsigned int *v8; // x23
  int v9; // w7
  __int64 v10; // x1
  unsigned int v11; // w3
  __int64 v12; // x8
  unsigned int *v13; // x9
  unsigned int *v14; // x10
  unsigned int v15; // w10
  unsigned int v16; // w10
  __int64 result; // x0
  __int64 v18; // x9
  unsigned int *v19; // x9
  __int64 v20; // x20
  size_t v21; // x21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v23; // x9
  size_t v24; // x22
  unsigned __int64 v25; // x9
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x8
  unsigned __int64 v34; // x9
  unsigned __int64 v35; // x21
  __int64 v36; // x22
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a2 || !a1 || !a3 )
  {
    _drm_err("invalid crtc %pK property %pK state %pK\n", a1, a3, a2);
    return 4294967274LL;
  }
  mutex_lock(a1 + 4664);
  v8 = (unsigned int *)(a1 + 4520);
  do
  {
    v8 = *(unsigned int **)v8;
    if ( v8 == (unsigned int *)(a1 + 4520) )
    {
      mutex_unlock(a1 + 4664);
      return 4294967294LL;
    }
  }
  while ( a3[4] != *(v8 - 10) );
  mutex_unlock(a1 + 4664);
  v10 = a2[1152];
  v11 = *(v8 - 8);
  if ( (unsigned int)v10 > 0x33 || v11 >= 0x34 )
  {
    _drm_err("invalid cnt %d exp %ld feature %d\n", v10, 52, v11);
    return 4294967274LL;
  }
  v12 = 24;
  v13 = a2 + 1154;
  v14 = &a2[6 * v11 + 1154];
  if ( !*(_QWORD *)v14 )
  {
    *(_QWORD *)v14 = a3;
    v15 = *(v8 - 8);
    if ( v15 > 0x33 )
      goto LABEL_32;
    *(_QWORD *)&v13[6 * v15 + 4] = v8 - 10;
    v16 = *(v8 - 8);
    a2[1152] = v10 + 1;
    a2[v10 + 1466] = v16;
    v11 = *(v8 - 8);
    if ( v11 > 0x33 )
      goto LABEL_32;
  }
  *(_QWORD *)&v13[6 * v11 + 2] = a4;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_cp_crtc_set_property", 2622, -1, *(v8 - 8), a4, -1059143953, v9, vars0);
  v12 = *((_QWORD *)v8 - 3);
  if ( !v12 )
    return 0;
  result = 0;
  if ( a4 && (a3[12] & 2) != 0 )
  {
    v18 = *(v8 - 8);
    if ( (unsigned int)v18 < 0x34 )
    {
      v19 = &a2[4 * v18];
      v20 = *((_QWORD *)v19 + 759);
      v8 = v19 + 1518;
      if ( v20
        || (v19[1520] = *(_QWORD *)(v12 + 72),
            v20 = _kmalloc_noprof(*(_QWORD *)(v12 + 72), 3264),
            (*(_QWORD *)v8 = v20) != 0) )
      {
LABEL_18:
        v21 = v8[2];
        if ( (v21 & 0x80000000) != 0 )
        {
          LODWORD(v24) = v8[2];
          __break(0x800u);
LABEL_24:
          _drm_err("failed to get the property info ret %d", v24);
          kfree(*(_QWORD *)v8);
          v8[2] = 0;
          *(_QWORD *)v8 = 0;
          return 4294967282LL;
        }
        _check_object_size(v20, v8[2], 0);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v23 = a4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v23 = a4 & ((__int64)(a4 << 8) >> 8);
        v24 = v21;
        if ( 0x8000000000LL - v21 < v23 )
          goto LABEL_36;
        v25 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v31 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v31 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v31);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v25);
        v24 = _arch_copy_from_user(v20, a4 & 0xFF7FFFFFFFFFFFFFLL, v21);
        v32 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v34 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v34 - 4096);
        _WriteStatusReg(TTBR1_EL1, v34);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v32);
        if ( v24 )
        {
LABEL_36:
          memset((void *)(v20 + v21 - v24), 0, v24);
          if ( (_DWORD)v24 )
            goto LABEL_24;
        }
        return 0;
      }
      return 4294967284LL;
    }
LABEL_32:
    __break(0x5512u);
    v35 = _ReadStatusReg(SP_EL0);
    v36 = *(_QWORD *)(v35 + 80);
    *(_QWORD *)(v35 + 80) = &sde_cp_crtc_set_range_prop__alloc_tag;
    v20 = _kmalloc_noprof(*(_QWORD *)(v12 + 72), 3264);
    *(_QWORD *)(v35 + 80) = v36;
    *(_QWORD *)v8 = v20;
    if ( v20 )
      goto LABEL_18;
    return 4294967284LL;
  }
  return result;
}
