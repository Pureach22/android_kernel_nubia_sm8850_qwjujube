unsigned __int64 __fastcall kgsl_drawobj_sync_add_synclist(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5)
{
  unsigned int v5; // w19
  __int64 v7; // x21
  unsigned __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  size_t v13; // x24
  size_t v14; // x25
  __int64 v15; // [xsp+8h] [xbp-38h] BYREF
  __int64 v16; // [xsp+10h] [xbp-30h]
  __int64 v17; // [xsp+18h] [xbp-28h]
  __int64 v18; // [xsp+20h] [xbp-20h] BYREF
  __int64 v19; // [xsp+28h] [xbp-18h]
  __int64 v20; // [xsp+30h] [xbp-10h]
  __int64 v21; // [xsp+38h] [xbp-8h]

  v5 = a5;
  v7 = a3;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 || a5 | a4 )
  {
    result = 4294967274LL;
    if ( a3 && a4 && a5 )
    {
      v19 = 0;
      v20 = 0;
      v18 = 0;
      v11 = _kmalloc_noprof(120LL * a5, 3520);
      *(_QWORD *)(a2 + 56) = v11;
      if ( !v11 )
      {
        result = 4294967284LL;
        goto LABEL_4;
      }
      v12 = a4;
      v16 = 0;
      v17 = 0;
      if ( a4 >= 0x18uLL )
        v13 = 24;
      else
        v13 = a4;
      if ( a4 <= 0x18uLL )
        v12 = 24;
      v15 = 0;
      v14 = v12 - v13;
      while ( 1 )
      {
        if ( a4 > 0x17 )
        {
          if ( a4 >= 0x19 && (int)check_zeroed_user(v7 + v13, v14) < 1 )
          {
LABEL_23:
            result = 4294967282LL;
            break;
          }
        }
        else
        {
          memset((char *)&v18 + v13, 0, v14);
        }
        _check_object_size(&v18, v13, 0);
        if ( inline_copy_from_user_1((int)&v18, v7, v13) )
          goto LABEL_23;
        LODWORD(v15) = v20;
        v16 = v18;
        v17 = v19;
        result = kgsl_drawobj_sync_add_sync(a1, a2, (int *)&v15);
        if ( (_DWORD)result )
          break;
        --v5;
        v7 += 24;
        if ( !v5 )
        {
          result = 0;
          break;
        }
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
