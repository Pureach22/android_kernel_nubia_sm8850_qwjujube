__int64 __fastcall qcom_reset_status(__int64 a1, __int64 a2)
{
  unsigned int *v3; // x22
  __int64 v4; // x21
  __int64 v5; // x20
  int v6; // w0
  __int64 result; // x0
  __int64 v8; // x8
  unsigned int v9; // w19
  int v10; // w0
  int v11; // w0
  unsigned int v12; // w8
  unsigned int v13; // w19
  unsigned int v20; // w10
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (unsigned int *)(*(_QWORD *)(a1 - 16) + 12 * a2);
  v21 = 0;
  LODWORD(v4) = v3[2];
  if ( !(_DWORD)v4 )
    v4 = 1LL << *((_BYTE *)v3 + 4);
  v5 = *(_QWORD *)(a1 + 96);
  if ( (*(_WORD *)(v5 + 488) & 7) == 0 && (v6 = _pm_runtime_resume(*(_QWORD *)(a1 + 96), 4), v6 < 0) )
  {
    v12 = *(_DWORD *)(v5 + 480);
    v13 = v6;
    do
    {
      if ( !v12 )
        break;
      _X12 = (unsigned int *)(v5 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v20 = __ldxr(_X12);
        if ( v20 != v12 )
          break;
        if ( !__stlxr(v12 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v20 == v12;
      v12 = v20;
    }
    while ( !_ZF );
    _warn_printk("ret=%d\n", v6);
    result = v13;
    __break(0x800u);
  }
  else
  {
    result = regmap_read(*(_QWORD *)(a1 - 8), *v3, &v21);
    v8 = *(_QWORD *)(a1 + 96);
    if ( (_DWORD)result )
    {
      if ( (*(_WORD *)(v8 + 488) & 7) == 0 )
      {
        v9 = result;
        v10 = _pm_runtime_idle(v8, 4);
        if ( v10 < 0 )
        {
          _warn_printk("ret=%d\n", v10);
          __break(0x800u);
        }
        result = v9;
      }
    }
    else
    {
      if ( (*(_WORD *)(v8 + 488) & 7) == 0 )
      {
        v11 = _pm_runtime_idle(*(_QWORD *)(a1 + 96), 4);
        if ( v11 < 0 )
        {
          _warn_printk("ret=%d\n", v11);
          __break(0x800u);
        }
      }
      result = v21 & (unsigned int)v4;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
