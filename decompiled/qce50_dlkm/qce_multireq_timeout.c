__int64 __fastcall qce_multireq_timeout(_DWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w8
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0
  unsigned int v14; // w8
  unsigned int v17; // w10
  _DWORD *v18; // x20
  int v19; // w8
  _DWORD *v20; // x19
  _DWORD *v21; // x20
  unsigned int v24; // w11

  v4 = a1[173];
  if ( !v4 || v4 != a1[174] )
  {
    a1[174] = v4;
    return mod_timer(a1, jiffies + 5LL);
  }
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  _X10 = a1 - 3;
  __asm { PRFM            #0x11, [X10] }
  while ( 1 )
  {
    v14 = __ldxr(_X10);
    if ( v14 )
      break;
    if ( !__stlxr(2u, _X10) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v14 )
  {
    _WriteStatusReg(DAIF, StatusReg);
    return mod_timer(a1, jiffies + 5LL);
  }
  _X8 = a1 - 1862;
  __asm { PRFM            #0x11, [X8] }
  do
    v17 = __ldxr(_X8);
  while ( __stlxr(1u, _X8) );
  __dmb(0xBu);
  if ( v17 || (v18 = a1, v19 = qce_process_sha_req((__int64)(a1 - 17382), 0, a3, a4), a1 = v18, ++v18[170], v19) )
  {
    v21 = a1;
    printk(&unk_15E1D, "qce_multireq_timeout", (unsigned int)a1[168]);
    a1 = v21;
  }
  _X9 = a1 - 3;
  __asm { PRFM            #0x11, [X9] }
  while ( 1 )
  {
    v24 = __ldxr(_X9);
    if ( v24 != 2 )
      break;
    if ( !__stlxr(0, _X9) )
    {
      __dmb(0xBu);
      break;
    }
  }
  a1[166] = 0;
  _WriteStatusReg(DAIF, StatusReg);
  v20 = a1;
  result = timer_delete(a1);
  ++v20[169];
  return result;
}
