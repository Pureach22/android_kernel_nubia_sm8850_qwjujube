__int64 __fastcall kgsl_get_ctxt_properties(__int64 *a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  size_t v4; // x21
  __int64 v5; // x20
  __int64 result; // x0
  __int64 owner; // x0
  unsigned int *v9; // x20
  int v10; // w8
  __int64 v11; // x19
  unsigned __int64 v12; // x21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x9
  unsigned __int64 v21; // x8
  __int64 v22; // x0
  unsigned __int64 v23; // x8
  unsigned __int64 v25; // x9
  __int64 v26; // x19
  int v28; // w9
  unsigned __int64 v29; // [xsp+8h] [xbp-28h] BYREF
  __int64 v30; // [xsp+10h] [xbp-20h]
  __int64 v31; // [xsp+18h] [xbp-18h]
  _DWORD v32[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 v33; // [xsp+28h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 16);
  if ( v2 )
  {
    if ( v2 >= 0x18 )
      v4 = 24;
    else
      v4 = *(_QWORD *)(a2 + 16);
    v5 = *(_QWORD *)(a2 + 8);
    v30 = 0;
    v31 = 0;
    v29 = 0;
    _check_object_size(&v29, v4, 0);
    if ( inline_copy_from_user_0((int)&v29, v5, v4) )
    {
      result = -14;
    }
    else if ( HIDWORD(v30) && (owner = kgsl_context_get_owner(a1, v31)) != 0 )
    {
      _X8 = (unsigned int *)owner;
      if ( HIDWORD(v30) == 1 )
      {
        if ( (_DWORD)v30 )
        {
          v9 = (unsigned int *)owner;
          v10 = *(_DWORD *)(owner + 284);
          if ( (unsigned int)v30 >= 8 )
            v11 = 8;
          else
            v11 = (unsigned int)v30;
          v12 = v29;
          v32[0] = *(_DWORD *)(owner + 280);
          v32[1] = v10;
          _check_object_size(v32, v11, 1);
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = v12, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v14 = v12 & ((__int64)(v12 << 8) >> 8);
          if ( 0x8000000000LL - v11 >= v14 )
          {
            v15 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v21 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v21);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v15);
            v22 = _arch_copy_to_user(v12 & 0xFF7FFFFFFFFFFFFFLL, v32, v11);
            v23 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v25 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v25 - 4096);
            _WriteStatusReg(TTBR1_EL1, v25);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v23);
            if ( v22 )
              result = -14;
            else
              result = 0;
          }
          else
          {
            result = -14;
          }
          _X8 = v9;
        }
        else
        {
          result = 0;
          LODWORD(v30) = 8;
        }
      }
      else
      {
        result = -95;
      }
      __asm { PRFM            #0x11, [X8] }
      do
        v28 = __ldxr(_X8);
      while ( __stlxr(v28 - 1, _X8) );
      if ( v28 == 1 )
      {
        __dmb(9u);
        v26 = result;
        kgsl_context_destroy((__int64)_X8);
      }
      else
      {
        if ( v28 > 0 )
          goto LABEL_33;
        v26 = result;
        refcount_warn_saturate(_X8, 3);
      }
      result = v26;
    }
    else
    {
      result = -22;
    }
  }
  else
  {
    result = 0;
    *(_QWORD *)(a2 + 16) = 24;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
