unsigned __int64 __fastcall kgsl_drawobj_sync_add_syncpoints(_QWORD *a1, __int64 a2, int a3, int a4)
{
  int v4; // w20
  __int64 v8; // x0
  unsigned __int64 result; // x0
  __int64 v10; // [xsp+0h] [xbp-30h] BYREF
  __int64 v11; // [xsp+8h] [xbp-28h]
  __int64 v12; // [xsp+10h] [xbp-20h]
  __int64 v13; // [xsp+18h] [xbp-18h] BYREF
  unsigned int v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a4 )
  {
LABEL_16:
    result = 0;
    goto LABEL_17;
  }
  v4 = a4;
  if ( !is_mul_ok(a4, 0x78u) )
  {
    *(_QWORD *)(a2 + 56) = 0;
    result = 4294967284LL;
    goto LABEL_17;
  }
  v8 = _kmalloc_noprof(120LL * a4, 3520);
  *(_QWORD *)(a2 + 56) = v8;
  if ( v8 )
  {
    if ( (*(_QWORD *)_ReadStatusReg(SP_EL0) & 0x400000) != 0 )
    {
      if ( v4 >= 1 )
      {
        v10 = 0;
        while ( 1 )
        {
          v14 = 0;
          v13 = 0;
          if ( inline_copy_from_user_1((int)&v13, a3, 0xCu) )
            goto LABEL_18;
          LODWORD(v10) = v13;
          v11 = HIDWORD(v13);
          v12 = v14;
          result = kgsl_drawobj_sync_add_sync(a1, a2, (int *)&v10);
          if ( (_DWORD)result )
            goto LABEL_17;
          --v4;
          a3 += 12;
          if ( !v4 )
            goto LABEL_16;
        }
      }
    }
    else if ( v4 >= 1 )
    {
      while ( 1 )
      {
        v11 = 0;
        v12 = 0;
        v10 = 0;
        if ( inline_copy_from_user_1((int)&v10, a3, 0x18u) )
          break;
        result = kgsl_drawobj_sync_add_sync(a1, a2, (int *)&v10);
        if ( (_DWORD)result )
          goto LABEL_17;
        --v4;
        a3 += 24;
        if ( !v4 )
          goto LABEL_16;
      }
LABEL_18:
      result = 4294967282LL;
      goto LABEL_17;
    }
    goto LABEL_16;
  }
  result = 4294967284LL;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
