__int64 __fastcall drm_dp_dual_mode_write(__int64 a1, char a2, const void *a3, size_t a4)
{
  __int64 v8; // x23
  _BYTE *v9; // x0
  __int64 v10; // x1
  _BYTE *v11; // x22
  int v12; // w19
  __int64 result; // x0
  unsigned __int16 v14; // w8
  unsigned __int64 StatusReg; // x24
  __int64 v16; // x25
  int v17; // [xsp+8h] [xbp-18h] BYREF
  __int16 v18; // [xsp+Ch] [xbp-14h]
  __int16 v19; // [xsp+Eh] [xbp-12h]
  _BYTE *v20; // [xsp+10h] [xbp-10h]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 64;
  v18 = a4 + 1;
  v19 = 0;
  v8 = (unsigned __int16)(a4 + 1);
  v9 = (_BYTE *)_kmalloc_noprof(v8, 3264);
  if ( !v9 )
  {
LABEL_11:
    result = -12;
    goto LABEL_12;
  }
  while ( 1 )
  {
    v20 = v9;
    if ( !v8 )
    {
      _fortify_panic(17, 0, 1);
      goto LABEL_10;
    }
    v10 = v8 - 1;
    *v9 = a2;
    if ( v8 - 1 >= a4 )
      break;
LABEL_10:
    _fortify_panic(17, v10, a4);
    v8 = v14;
    StatusReg = _ReadStatusReg(SP_EL0);
    v16 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &drm_dp_dual_mode_write__alloc_tag;
    v9 = (_BYTE *)_kmalloc_noprof(v14, 3264);
    *(_QWORD *)(StatusReg + 80) = v16;
    if ( !v9 )
      goto LABEL_11;
  }
  v11 = v9;
  memcpy(v9 + 1, a3, a4);
  v12 = i2c_transfer(a1, &v17, 1);
  kfree(v11);
  if ( v12 < 0 )
  {
    result = v12;
  }
  else if ( v12 == 1 )
  {
    result = 0;
  }
  else
  {
    result = -71;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
