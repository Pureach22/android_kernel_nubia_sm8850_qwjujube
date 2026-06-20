__int64 __fastcall seq_response(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x22
  __int64 v3; // x25
  unsigned __int64 StatusReg; // x28
  _QWORD *v11; // x8
  _QWORD *v12; // x23
  _QWORD *v13; // x9
  _QWORD *v14; // x8
  __int64 v15; // x0
  __int64 (*v16)(void); // x9
  __int64 v17; // x0
  unsigned int v20; // w9
  int v21; // w23
  __int64 v22; // x0
  __int64 **v23; // x9
  __int64 v24; // x1
  __int64 *v25; // x9
  int v26; // w10
  __int64 *v27; // x24
  unsigned int v31; // w8
  unsigned int v34; // w8
  __int64 v35; // x23
  unsigned int v38; // w8
  __int64 v39; // [xsp+8h] [xbp-8h]

  v1 = result;
  v2 = result - 196;
  v3 = result - 136;
  _X26 = (unsigned __int64 *)(result - 24);
  v39 = result - 248;
  StatusReg = _ReadStatusReg(SP_EL0);
LABEL_2:
  __asm { PRFM            #0x11, [X26] }
  do
    v11 = (_QWORD *)__ldxr(_X26);
  while ( __stlxr(0, _X26) );
  __dmb(0xBu);
  if ( !v11 )
    goto LABEL_36;
  v12 = nullptr;
  do
  {
    v13 = v12;
    v12 = v11;
    v11 = (_QWORD *)*v11;
    *v12 = v13;
  }
  while ( v11 );
  do
  {
    v14 = v12;
    v12 = (_QWORD *)*v12;
    v15 = v14[1];
    *(_DWORD *)(StatusReg + 16) += 512;
    v16 = *(__int64 (**)(void))(v15 + 16);
    if ( *((_DWORD *)v16 - 1) != 1607364836 )
      __break(0x8229u);
    v17 = v16();
    result = local_bh_enable(v17);
    _X8 = (unsigned int *)(v1 - 16);
    __asm { PRFM            #0x11, [X8] }
    do
      v20 = __ldxr(_X8);
    while ( __stxr(v20 - 1, _X8) );
  }
  while ( v12 );
  if ( *(int *)(v1 - 16) > 199 )
    goto LABEL_36;
  _X10 = (unsigned int *)(v1 + 36);
  __asm { PRFM            #0x11, [X10] }
  while ( 1 )
  {
    v38 = __ldxr(_X10);
    if ( v38 )
      break;
    if ( !__stlxr(1u, _X10) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v38 )
    goto LABEL_36;
  v21 = *(_DWORD *)(v1 - 120);
  ++*(_DWORD *)(v1 + 72);
  if ( v21 < 1 )
    goto LABEL_36;
  while ( 1 )
  {
    v22 = raw_spin_lock_irqsave(v2);
    v23 = *(__int64 ***)(v1 + 56);
    v24 = v22;
    if ( *(_QWORD *)(v1 - 136) == v3 )
      break;
    if ( !v23 || (v25 = *v23, v25 == (__int64 *)v3) )
      v25 = *(__int64 **)(v1 - 136);
    v26 = *(_DWORD *)(v1 - 120) + 1;
    v27 = v25;
    while ( 1 )
    {
      if ( --v26 < 1 )
      {
LABEL_32:
        *(_QWORD *)(v1 + 56) = 0;
        goto LABEL_33;
      }
      if ( (*((_BYTE *)v27 + 252) & 1) == 0 && *((_DWORD *)v27 + 62) < *((_DWORD *)v27 + 59) )
        break;
      if ( !v27 || (v27 = (__int64 *)*v27, v27 == (__int64 *)v3) )
        v27 = *(__int64 **)(v1 - 136);
      if ( v25 == v27 )
        goto LABEL_32;
    }
    *(_QWORD *)(v1 + 56) = v27;
    result = raw_spin_unlock_irqrestore(v2, v22);
    if ( v27 )
    {
      result = start_qcrypto_process(v39, v27);
      if ( v21-- > 1 )
        continue;
    }
    goto LABEL_36;
  }
  v35 = v22;
  printk(&unk_12ACF, "_avail_eng");
  v24 = v35;
LABEL_33:
  result = raw_spin_unlock_irqrestore(v2, v24);
  do
  {
LABEL_36:
    _X9 = (unsigned int *)(v1 + 32);
    __asm { PRFM            #0x11, [X9] }
    while ( 1 )
    {
      v31 = __ldxr(_X9);
      if ( v31 != 2 )
        break;
      if ( !__stlxr(1u, _X9) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( v31 == 2 )
      goto LABEL_2;
    _X10 = (unsigned int *)(v1 + 32);
    __asm { PRFM            #0x11, [X10] }
    while ( 1 )
    {
      v34 = __ldxr(_X10);
      if ( v34 != 1 )
        break;
      if ( !__stlxr(0, _X10) )
      {
        __dmb(0xBu);
        break;
      }
    }
  }
  while ( v34 == 2 );
  return result;
}
