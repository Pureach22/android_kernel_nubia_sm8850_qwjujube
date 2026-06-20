_DWORD *__fastcall req_done(_DWORD *result)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x2
  int v4; // w3
  _DWORD *v6; // x20
  unsigned __int8 v12; // w10
  _QWORD *v13; // x1
  unsigned __int64 StatusReg; // x8
  int v15; // w9
  int v16; // w8
  __int64 v17; // x22
  int v18; // w23
  unsigned int v21; // w10

  v1 = *((_QWORD *)result + 1);
  v2 = *((_QWORD *)result + 2);
  v3 = *((_QWORD *)result + 3);
  v4 = result[8];
  _X9 = (unsigned __int8 *)(result + 1);
  v6 = *(_DWORD **)(v1 + 32);
  *((_QWORD *)result + 2) = 0;
  *((_QWORD *)result + 3) = 0;
  __asm { PRFM            #0x11, [X9] }
  do
    v12 = __ldxr(_X9);
  while ( __stlxr(0, _X9) );
  __dmb(0xBu);
  if ( v12 )
  {
    _X8 = (unsigned int *)(v1 + 248);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 - 1, _X8) );
  }
  else
  {
    v17 = v3;
    v18 = v4;
    result = (_DWORD *)printk(&unk_11D20, result);
    v4 = v18;
    v3 = v17;
  }
  if ( v2 )
    v13 = (_QWORD *)(*(_QWORD *)(v2 + 32) + 32LL);
  else
    v13 = nullptr;
  StatusReg = _ReadStatusReg(SP_EL0);
  v15 = *(unsigned __int8 *)(v1 + 253);
  v16 = *(_DWORD *)(StatusReg + 40);
  *(_DWORD *)(v1 + 256) = v16;
  if ( v15 == 1 && v16 != v6[72] )
    v6[72] = v16;
  if ( v2 )
    result = (_DWORD *)qcrypto_tfm_complete(v1, v13, v3, v4);
  if ( v6[71] == 1 )
    return start_qcrypto_process(v6, v1);
  return result;
}
