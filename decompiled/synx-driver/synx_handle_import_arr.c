__int64 __fastcall synx_handle_import_arr(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v4; // x1
  __int64 result; // x0
  unsigned __int64 v6; // x21
  unsigned __int64 v7; // x20
  size_t v8; // x22
  int v9; // w23
  unsigned int v10; // w23
  unsigned __int64 v11; // x23
  unsigned __int64 v12; // x22
  unsigned __int64 v13; // x26
  int v14; // w8
  unsigned __int64 v15; // x25
  _DWORD *v16; // x28
  unsigned __int64 fence; // x0
  __int64 v18; // x5
  int v19; // w0
  int v21; // w25
  int v27; // w9
  __int64 v28; // x19
  unsigned __int64 v29; // x21
  __int64 v30; // [xsp+8h] [xbp-48h] BYREF
  __int64 v31; // [xsp+10h] [xbp-40h]
  __int64 v32; // [xsp+18h] [xbp-38h]
  unsigned __int64 v33; // [xsp+20h] [xbp-30h]
  __int64 v34; // [xsp+28h] [xbp-28h]
  __int64 v35; // [xsp+30h] [xbp-20h]
  unsigned __int64 v36; // [xsp+38h] [xbp-18h] BYREF
  __int64 v37; // [xsp+40h] [xbp-10h]
  __int64 v38; // [xsp+48h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 4);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  if ( v2 != 16 )
  {
    result = 4294967274LL;
    goto LABEL_5;
  }
  v4 = *(_QWORD *)(a1 + 16);
  v36 = 0;
  v37 = 0;
  if ( inline_copy_from_user((int)&v36, v4, 0x10u) )
  {
    result = 4294967282LL;
    goto LABEL_5;
  }
  v6 = 32LL * (unsigned int)v37;
  v7 = _kmalloc_noprof(v6, 3520);
  result = 4294967284LL;
  if ( v7 && v7 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (unsigned int)v37 >> 26 )
    {
      __break(0x800u);
      goto LABEL_10;
    }
    v8 = 32LL * (unsigned int)v37;
    v9 = v36;
    _check_object_size(v7, v8, 0);
    if ( inline_copy_from_user(v7, v9, v8) )
    {
LABEL_10:
      v10 = -14;
      goto LABEL_11;
    }
    if ( !(_DWORD)v37 )
    {
      v10 = -22;
      goto LABEL_11;
    }
    v11 = 0;
    v12 = -24;
    while ( 1 )
    {
      v13 = v7 + v12;
      LODWORD(v30) = 1;
      v31 = v7 + v12 + 32;
      if ( v6 < v12 + 28 )
        goto LABEL_55;
      v14 = *(_DWORD *)(v13 + 28);
      v15 = v12 + 24;
      v16 = (_DWORD *)(v13 + 24);
      LODWORD(v32) = v14;
      if ( (v14 & 8) == 0 )
        goto LABEL_21;
      if ( v6 < v12 + 48 )
        goto LABEL_55;
      if ( *(_DWORD *)(v7 + v12 + 48) )
      {
        fence = sync_file_get_fence();
        v33 = fence;
        if ( !fence || fence >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (synx_debug & 1) != 0 )
          {
            if ( v6 >= v12 + 48 )
            {
              printk(&unk_26A26, &unk_29207, "synx_handle_import_arr", 3010, *(unsigned int *)(v7 + v12 + 48), v18);
              goto LABEL_46;
            }
LABEL_55:
            __break(1u);
          }
LABEL_46:
          v19 = -22;
LABEL_47:
          v10 = v19;
          if ( v12 != -24 )
          {
            while ( v6 >= v12 )
            {
              synx_release(a2, *(unsigned int *)(v7 + v12));
              v12 -= 32LL;
              if ( v12 == -24 )
                goto LABEL_11;
            }
            goto LABEL_55;
          }
LABEL_11:
          kfree(v7);
          result = v10;
          break;
        }
      }
      else
      {
LABEL_21:
        if ( (v14 & 4) != 0 )
        {
          if ( v6 <= v15 )
            goto LABEL_55;
          if ( *v16 )
            v33 = v13 + 24;
        }
      }
      v19 = synx_import(a2, &v30);
      if ( v6 < v12 + 28 )
        goto LABEL_55;
      if ( (*(_BYTE *)(v13 + 28) & 8) != 0 )
      {
        if ( v6 <= v15 )
          goto LABEL_55;
        if ( *v16 && v33 )
        {
          _X8 = (unsigned int *)(v33 + 56);
          __asm { PRFM            #0x11, [X8] }
          do
            v27 = __ldxr(_X8);
          while ( __stlxr(v27 - 1, _X8) );
          if ( v27 == 1 )
          {
            __dmb(9u);
            v21 = v19;
            dma_fence_release(_X8);
          }
          else
          {
            if ( v27 > 0 )
              goto LABEL_36;
            v21 = v19;
            refcount_warn_saturate(_X8, 3);
          }
          v19 = v21;
        }
      }
LABEL_36:
      if ( v19 )
        goto LABEL_47;
      ++v11;
      v12 += 32LL;
      if ( v11 >= (unsigned int)v37 )
      {
        if ( !((unsigned int)v37 >> 26) )
        {
          v28 = 32LL * (unsigned int)v37;
          v29 = v36;
          _check_object_size(v7, v28, 1);
          if ( inline_copy_to_user(v29, v7, v28) )
            v10 = -14;
          else
            v10 = 0;
          goto LABEL_11;
        }
        __break(0x800u);
        goto LABEL_10;
      }
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
