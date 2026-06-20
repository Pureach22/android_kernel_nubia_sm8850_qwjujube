__int64 __fastcall synx_handle_merge(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v4; // x1
  __int64 result; // x0
  unsigned __int64 v7; // x0
  __int64 v8; // x4
  __int64 v9; // x5
  unsigned __int64 v10; // x20
  size_t v11; // x21
  int v12; // w22
  unsigned int v13; // w22
  __int64 v14; // x19
  unsigned __int64 v15; // x21
  unsigned __int64 v16; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int64 v17; // [xsp+10h] [xbp-30h]
  char *v18; // [xsp+18h] [xbp-28h]
  __int64 v19; // [xsp+20h] [xbp-20h] BYREF
  __int64 v20; // [xsp+28h] [xbp-18h] BYREF
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 4);
  v17 = 0;
  v18 = nullptr;
  v16 = 0;
  if ( v2 != 24 )
    goto LABEL_5;
  v4 = *(_QWORD *)(a1 + 16);
  v20 = 0;
  v21 = 0;
  v19 = 0;
  if ( inline_copy_from_user((int)&v19, v4, 0x18u) )
  {
    result = 4294967282LL;
    goto LABEL_6;
  }
  if ( (unsigned int)v20 > 0xFFF )
  {
LABEL_5:
    result = 4294967274LL;
    goto LABEL_6;
  }
  v7 = _kmalloc_noprof(4LL * (unsigned int)v20, 3520);
  v10 = v7;
  if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (unsigned int)v20 >> 29 )
    {
      __break(0x800u);
    }
    else
    {
      v11 = 4LL * (unsigned int)v20;
      v12 = v19;
      _check_object_size(v7, v11, 0);
      if ( !inline_copy_from_user(v10, v12, v11) )
      {
        v16 = v10;
        v17 = __PAIR64__(v20, v21);
        v18 = (char *)&v20 + 4;
        v13 = synx_merge(a2, &v16);
        if ( v13 )
          goto LABEL_13;
        v14 = *(unsigned int *)(a1 + 4);
        if ( (unsigned int)v14 >= 0x19 )
        {
          _copy_overflow(24, *(unsigned int *)(a1 + 4));
          goto LABEL_11;
        }
        v15 = *(_QWORD *)(a1 + 16);
        _check_object_size(&v19, *(unsigned int *)(a1 + 4), 1);
        if ( !inline_copy_to_user(v15, (__int64)&v19, v14) )
        {
LABEL_13:
          kfree(v10);
          result = v13;
          goto LABEL_6;
        }
      }
    }
LABEL_11:
    kfree(v10);
    result = 4294967282LL;
    goto LABEL_6;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_25DFC, &unk_29207, "synx_handle_merge", 3179, v8, v9);
  result = 4294967284LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
