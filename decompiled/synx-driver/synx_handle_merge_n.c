__int64 __fastcall synx_handle_merge_n(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v4; // x1
  __int64 result; // x0
  unsigned int v7; // w19
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x0
  __int64 v10; // x4
  __int64 v11; // x5
  size_t v12; // x21
  int v13; // w22
  unsigned __int64 v14; // x23
  unsigned __int64 v15; // x20
  unsigned int v16; // w0
  __int64 v17; // x19
  unsigned __int64 v18; // x21
  __int64 v19; // [xsp+8h] [xbp-68h] BYREF
  unsigned __int64 v20; // [xsp+10h] [xbp-60h]
  unsigned __int64 v21; // [xsp+18h] [xbp-58h]
  char *v22; // [xsp+20h] [xbp-50h]
  __int64 v23; // [xsp+28h] [xbp-48h]
  __int64 v24; // [xsp+30h] [xbp-40h]
  __int64 v25; // [xsp+38h] [xbp-38h] BYREF
  __int64 v26; // [xsp+40h] [xbp-30h]
  __int64 v27; // [xsp+48h] [xbp-28h] BYREF
  __int64 v28; // [xsp+50h] [xbp-20h]
  __int64 v29; // [xsp+58h] [xbp-18h]
  __int64 v30; // [xsp+60h] [xbp-10h]
  __int64 v31; // [xsp+68h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 4);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = nullptr;
  v19 = 0;
  v20 = 0;
  if ( v2 != 48 )
    goto LABEL_6;
  v4 = *(_QWORD *)(a1 + 16);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  if ( inline_copy_from_user((int)&v25, v4, 0x30u) )
  {
    result = 4294967282LL;
    goto LABEL_7;
  }
  if ( (_DWORD)v25 != 1 )
  {
    v7 = 0;
    v8 = 0;
    goto LABEL_9;
  }
  if ( (unsigned int)v27 > 0xFFF )
  {
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  v9 = _kmalloc_noprof(4LL * (unsigned int)v27, 3520);
  if ( v9 && v9 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (unsigned int)v27 >> 29 )
    {
      v15 = v9;
      __break(0x800u);
      goto LABEL_14;
    }
    v12 = 4LL * (unsigned int)v27;
    v13 = v26;
    v14 = v9;
    _check_object_size(v9, v12, 0);
    v15 = v14;
    if ( inline_copy_from_user(v14, v13, v12) )
    {
LABEL_14:
      kfree(v15);
      result = 4294967282LL;
      goto LABEL_7;
    }
    LODWORD(v19) = 1;
    v21 = __PAIR64__(v27, v28);
    v22 = (char *)&v27 + 4;
    v20 = v14;
    v24 = v30;
    v16 = synx_merge_n(a2, &v19);
    if ( v16 )
    {
      v7 = v16;
    }
    else
    {
      v17 = *(unsigned int *)(a1 + 4);
      if ( (unsigned int)v17 >= 0x31 )
      {
        _copy_overflow(48, *(unsigned int *)(a1 + 4));
        goto LABEL_14;
      }
      v18 = *(_QWORD *)(a1 + 16);
      _check_object_size(&v25, *(unsigned int *)(a1 + 4), 1);
      if ( inline_copy_to_user(v18, (__int64)&v25, v17) )
        goto LABEL_14;
      v7 = 0;
    }
    v8 = v14;
LABEL_9:
    kfree(v8);
    result = v7;
    goto LABEL_7;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_25DFC, &unk_29207, "synx_handle_merge_n", 3232, v10, v11);
  result = 4294967284LL;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
