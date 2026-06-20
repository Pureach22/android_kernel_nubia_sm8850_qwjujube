__int64 __fastcall synx_handle_import_arr_v2(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v4; // x1
  __int64 result; // x0
  unsigned __int64 v6; // x21
  unsigned __int64 v7; // x20
  int v8; // w23
  size_t v9; // x22
  unsigned int v10; // w23
  unsigned __int64 v11; // x23
  unsigned __int64 v12; // x22
  unsigned __int64 v13; // x28
  unsigned __int64 v14; // x27
  int v15; // w8
  unsigned __int64 v16; // x24
  _DWORD *v17; // x26
  unsigned __int64 fence; // x0
  __int64 v19; // x5
  int v20; // w0
  int v22; // w24
  int v28; // w9
  unsigned __int64 v29; // x21
  __int64 v30; // x19
  __int64 v31; // [xsp+8h] [xbp-48h] BYREF
  __int64 v32; // [xsp+10h] [xbp-40h]
  __int64 v33; // [xsp+18h] [xbp-38h]
  unsigned __int64 v34; // [xsp+20h] [xbp-30h]
  __int64 v35; // [xsp+28h] [xbp-28h]
  __int64 v36; // [xsp+30h] [xbp-20h]
  unsigned __int64 v37; // [xsp+38h] [xbp-18h] BYREF
  __int64 v38; // [xsp+40h] [xbp-10h]
  __int64 v39; // [xsp+48h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 4);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  if ( v2 != 16 )
  {
    result = 4294967274LL;
    goto LABEL_5;
  }
  v4 = *(_QWORD *)(a1 + 16);
  v37 = 0;
  v38 = 0;
  if ( inline_copy_from_user((int)&v37, v4, 0x10u) )
  {
    result = 4294967282LL;
    goto LABEL_5;
  }
  v6 = 48LL * (unsigned int)v38;
  v7 = _kmalloc_noprof(v6, 3520);
  result = 4294967284LL;
  if ( v7 && v7 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (unsigned int)v38 > 0x2AAAAAA )
    {
      __break(0x800u);
      goto LABEL_10;
    }
    v8 = v37;
    v9 = 48LL * (unsigned int)v38;
    _check_object_size(v7, v9, 0);
    if ( inline_copy_from_user(v7, v8, v9) )
    {
LABEL_10:
      v10 = -14;
      goto LABEL_11;
    }
    if ( !(_DWORD)v38 )
    {
      v10 = -22;
      goto LABEL_11;
    }
    v11 = 0;
    v12 = -40;
    while ( 1 )
    {
      v13 = v7 + v12;
      v14 = v12 + 44;
      LODWORD(v31) = 3;
      v32 = v7 + v12 + 48;
      if ( v6 < v12 + 44 )
        goto LABEL_58;
      LODWORD(v33) = *(_DWORD *)(v13 + 44);
      if ( v6 < v12 + 80 )
        goto LABEL_58;
      LODWORD(v36) = *(_DWORD *)(v7 + v12 + 80);
      if ( v6 < v12 + 84 )
        goto LABEL_58;
      HIDWORD(v36) = *(_DWORD *)(v7 + v12 + 84);
      if ( v6 < v14 )
        goto LABEL_58;
      v15 = *(_DWORD *)(v13 + 44);
      v16 = v12 + 40;
      v17 = (_DWORD *)(v13 + 40);
      if ( (v15 & 8) == 0 )
        goto LABEL_24;
      if ( v6 < v12 + 64 )
        goto LABEL_58;
      if ( *(_DWORD *)(v7 + v12 + 64) )
      {
        fence = sync_file_get_fence();
        v34 = fence;
        if ( !fence || fence >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (synx_debug & 1) != 0 )
          {
            if ( v6 >= v12 + 64 )
            {
              printk(&unk_26A26, &unk_29207, "synx_handle_import_arr_v2", 3094, *(unsigned int *)(v7 + v12 + 64), v19);
              goto LABEL_49;
            }
LABEL_58:
            __break(1u);
          }
LABEL_49:
          v20 = -22;
LABEL_50:
          v10 = v20;
          if ( v12 != -40 )
          {
            while ( v6 >= v12 )
            {
              synx_release(a2, *(unsigned int *)(v7 + v12));
              v12 -= 48LL;
              if ( v12 == -40 )
                goto LABEL_11;
            }
            goto LABEL_58;
          }
LABEL_11:
          kfree(v7);
          result = v10;
          break;
        }
      }
      else
      {
LABEL_24:
        if ( (v15 & 4) != 0 )
        {
          if ( v6 <= v16 )
            goto LABEL_58;
          if ( *v17 )
            v34 = v13 + 40;
        }
      }
      v20 = synx_import(a2, &v31);
      if ( v6 < v14 )
        goto LABEL_58;
      if ( (*(_BYTE *)(v13 + 44) & 8) != 0 )
      {
        if ( v6 <= v16 )
          goto LABEL_58;
        if ( *v17 && v34 )
        {
          _X8 = (unsigned int *)(v34 + 56);
          __asm { PRFM            #0x11, [X8] }
          do
            v28 = __ldxr(_X8);
          while ( __stlxr(v28 - 1, _X8) );
          if ( v28 == 1 )
          {
            __dmb(9u);
            v22 = v20;
            dma_fence_release(_X8);
          }
          else
          {
            if ( v28 > 0 )
              goto LABEL_39;
            v22 = v20;
            refcount_warn_saturate(_X8, 3);
          }
          v20 = v22;
        }
      }
LABEL_39:
      if ( v20 )
        goto LABEL_50;
      ++v11;
      v12 += 48LL;
      if ( v11 >= (unsigned int)v38 )
      {
        if ( (unsigned int)v38 <= 0x2AAAAAA )
        {
          v29 = v37;
          v30 = 48LL * (unsigned int)v38;
          _check_object_size(v7, v30, 1);
          if ( inline_copy_to_user(v29, v7, v30) )
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
