__int64 __fastcall drm_dp_dual_mode_read(__int64 a1, unsigned __int8 a2, void *a3, size_t a4)
{
  size_t v4; // x23
  size_t v5; // x21
  __int64 v9; // x22
  int v10; // w0
  size_t v11; // x8
  int v12; // w21
  __int64 result; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v15; // x26
  char v16; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v17[2]; // [xsp+8h] [xbp-28h] BYREF
  int v18; // [xsp+18h] [xbp-18h]
  __int16 v19; // [xsp+1Ch] [xbp-14h]
  __int16 v20; // [xsp+1Eh] [xbp-12h]
  __int64 v21; // [xsp+20h] [xbp-10h]
  __int64 v22; // [xsp+28h] [xbp-8h]

  v4 = a2;
  v5 = a2 + a4;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17[0] = 0x100000040LL;
  v17[1] = &v16;
  v19 = a2 + (_WORD)a4;
  v18 = 65600;
  v20 = 0;
  v21 = (__int64)a3;
  if ( a2 )
  {
    v9 = _kmalloc_noprof(a2 + a4, 3264);
    if ( !v9 )
    {
LABEL_15:
      result = -12;
      goto LABEL_16;
    }
    while ( 1 )
    {
      v21 = v9;
      v10 = i2c_transfer(a1, v17, 2);
      v11 = v5 >= v4 ? a4 : 0LL;
      if ( v11 >= a4 )
        break;
      _fortify_panic(16, -1, a4);
      StatusReg = _ReadStatusReg(SP_EL0);
      v15 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v9 = _kmalloc_noprof(v5, 3264);
      *(_QWORD *)(StatusReg + 80) = v15;
      if ( !v9 )
        goto LABEL_15;
    }
    v12 = v10;
    memcpy(a3, (const void *)(v9 + v4), a4);
  }
  else
  {
    v12 = i2c_transfer(a1, v17, 2);
    v9 = 0;
  }
  kfree(v9);
  if ( v12 < 0 )
  {
    result = v12;
  }
  else if ( v12 == 2 )
  {
    result = 0;
  }
  else
  {
    result = -71;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
