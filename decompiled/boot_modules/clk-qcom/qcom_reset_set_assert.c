__int64 __fastcall qcom_reset_set_assert(__int64 a1, __int64 a2, char a3)
{
  unsigned int *v5; // x25
  __int64 v6; // x20
  __int64 v7; // x24
  int v8; // w0
  __int64 v9; // x3
  __int64 result; // x0
  __int64 v11; // x0
  unsigned int v12; // w8
  unsigned int v13; // w19
  unsigned int v20; // w10
  __int64 v21; // x8
  unsigned int v22; // w19
  int v23; // w0
  int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = (unsigned int *)(*(_QWORD *)(a1 - 16) + 12 * a2);
  v24 = 0;
  LODWORD(v6) = v5[2];
  if ( !(_DWORD)v6 )
    v6 = 1LL << *((_BYTE *)v5 + 4);
  v7 = *(_QWORD *)(a1 + 96);
  if ( (*(_WORD *)(v7 + 488) & 7) == 0 && (v8 = _pm_runtime_resume(*(_QWORD *)(a1 + 96), 4), v8 < 0) )
  {
    v12 = *(_DWORD *)(v7 + 480);
    v13 = v8;
    do
    {
      if ( !v12 )
        break;
      _X12 = (unsigned int *)(v7 + 480);
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
    _warn_printk("ret=%d\n", v8);
    result = v13;
    __break(0x800u);
  }
  else
  {
    if ( (a3 & 1) != 0 )
      v9 = (unsigned int)v6;
    else
      v9 = 0;
    result = regmap_update_bits_base(*(_QWORD *)(a1 - 8), *v5, (unsigned int)v6, v9, 0, 0, 0);
    if ( !(_DWORD)result )
    {
      result = regmap_read(*(_QWORD *)(a1 - 8), *v5, &v24);
      if ( !(_DWORD)result )
      {
        if ( *((_WORD *)v5 + 3) )
          v11 = *((unsigned __int16 *)v5 + 3);
        else
          v11 = 4;
        if ( (unsigned int)v11 > 0xA )
        {
          if ( (unsigned int)v11 > 0x4E20 )
            msleep((4294968 * (unsigned __int64)(unsigned int)(v11 + 999)) >> 32);
          else
            usleep_range_state(v11, 2 * v11, 2);
        }
        else
        {
          _udelay();
        }
        result = 0;
      }
    }
    v21 = *(_QWORD *)(a1 + 96);
    if ( (*(_WORD *)(v21 + 488) & 7) == 0 )
    {
      v22 = result;
      v23 = _pm_runtime_idle(v21, 4);
      if ( v23 < 0 )
      {
        _warn_printk("ret=%d\n", v23);
        __break(0x800u);
      }
      result = v22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
