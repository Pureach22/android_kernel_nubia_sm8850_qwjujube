// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_105104@<X0>(__int64 a1@<X8>)
{
  unsigned __int64 v1; // x1
  __int64 v2; // x19
  __int64 v3; // x21
  size_t v4; // x0
  size_t v5; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v12; // x9
  int v14; // w8
  unsigned int v15; // [xsp-4Ch] [xbp-4Ch] BYREF
  _BYTE v16[72]; // [xsp-48h] [xbp-48h] BYREF

  v4 = _arch_copy_from_user(v16, a1 & 0xFF7FFFFFFFFFFFFFLL, v2);
  v5 = v4;
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v12 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v12 - 4096);
  _WriteStatusReg(TTBR1_EL1, v12);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
  if ( v4 )
  {
    if ( v2 - v4 <= 0xA )
      v1 = 10 - (v2 - v4);
    else
      v1 = 0;
    if ( v1 < v4 )
    {
      _fortify_panic(15, v1, v4);
      JUMPOUT(0x1051C8);
    }
    memset(&v16[v2 - v4], 0, v4);
    if ( v5 )
      goto LABEL_3;
  }
  v16[v2] = 0;
  if ( (unsigned int)kstrtouint(v16, 0, &v15) )
  {
LABEL_3:
    v2 = -14;
  }
  else
  {
    v14 = v15;
    if ( v15 <= 0xC35000 )
      v14 = 12800000;
    *(_DWORD *)(*(_QWORD *)(v3 + 16) + 21708LL) = v14;
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
