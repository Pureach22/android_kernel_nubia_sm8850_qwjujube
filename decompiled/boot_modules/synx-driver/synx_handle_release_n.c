__int64 __fastcall synx_handle_release_n(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v4; // x5
  __int64 result; // x0
  unsigned __int64 v6; // x20
  unsigned __int64 v7; // x19
  int v8; // w23
  size_t v9; // x22
  __int64 v10; // x5
  unsigned int v11; // w19
  unsigned __int64 v12; // x0
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x10
  int v16; // w13
  __int64 v17; // x12
  unsigned int v18; // w0
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x26
  unsigned __int64 v22; // x27
  unsigned __int64 v23; // x28
  char v24; // w9
  unsigned __int64 v25; // x22
  __int64 v26; // x20
  __int64 v27; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v29; // x23
  __int64 v30; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int64 v31; // [xsp+10h] [xbp-30h]
  __int64 v32; // [xsp+18h] [xbp-28h]
  __int64 v33; // [xsp+20h] [xbp-20h] BYREF
  unsigned __int64 v34; // [xsp+28h] [xbp-18h]
  __int64 v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 4);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  if ( v2 != 24 )
  {
LABEL_18:
    result = 4294967274LL;
    goto LABEL_19;
  }
  if ( inline_copy_from_user((int)&v33, *(_QWORD *)(a1 + 16), 0x18u) )
  {
    result = 4294967282LL;
    goto LABEL_19;
  }
  if ( (_DWORD)v33 == 1 )
  {
    LODWORD(v30) = 1;
    v31 = (unsigned int)v34 | 0xFFFFFFEA00000000LL;
    result = synx_release_n(a2, &v30);
    if ( (_DWORD)result )
    {
      if ( (synx_debug & 1) != 0 )
      {
        v11 = result;
        printk(&unk_2635D, &unk_29207, "synx_handle_release_n", 3455, (unsigned int)result, (unsigned int)v31);
        result = v11;
      }
    }
    else
    {
      if ( (synx_debug & 0x10) != 0 )
        printk(&unk_2B193, "verb", "synx_handle_release_n", 3459, (unsigned int)v31, v10);
      result = 0;
    }
    goto LABEL_19;
  }
  if ( (_DWORD)v33 != 2 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2639E, &unk_29207, "synx_handle_release_n", 3462, (unsigned int)v33, v4);
    goto LABEL_18;
  }
  result = 4294967274LL;
  if ( (unsigned int)(v35 - 4096) >= 0xFFFFF001 )
  {
    if ( v34 )
    {
      v6 = 12LL * (unsigned int)v35;
      v7 = _kmalloc_noprof(v6, 3520);
      result = 4294967284LL;
      if ( v7 )
      {
        while ( 1 )
        {
          if ( v7 > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_19;
          if ( (unsigned int)v35 > 0xAAAAAAA )
          {
            __break(0x800u);
LABEL_12:
            kfree(v7);
            result = 4294967282LL;
            goto LABEL_19;
          }
          v8 = v34;
          v9 = 12LL * (unsigned int)v35;
          _check_object_size(v7, v9, 0);
          if ( inline_copy_from_user(v7, v8, v9) )
            goto LABEL_12;
          LODWORD(v30) = 2;
          LODWORD(v32) = v35;
          v12 = _kmalloc_noprof(8LL * (unsigned int)v35, 3520);
          v31 = v12;
          if ( !v12 || v12 > 0xFFFFFFFFFFFFF000LL )
            break;
          if ( (_DWORD)v32 )
          {
            v13 = 0;
            v14 = 0;
            v15 = 0;
            while ( v6 > v14 )
            {
              v16 = *(_DWORD *)(v7 + v14);
              ++v15;
              v14 += 12LL;
              *(_DWORD *)(v31 + v13) = v16;
              v17 = v31 + v13;
              v13 += 8;
              *(_DWORD *)(v17 + 4) = -22;
              if ( v15 >= (unsigned int)v32 )
                goto LABEL_29;
            }
          }
          else
          {
LABEL_29:
            v18 = synx_release_n(a2, &v30);
            a2 = v18;
            if ( v18 && (synx_debug & 1) != 0 )
            {
              printk(&unk_28F40, &unk_29207, "synx_handle_release_n", 3429, v18, v20);
              if ( !(_DWORD)v32 )
              {
LABEL_38:
                if ( (unsigned int)v35 > 0xAAAAAAA )
                {
                  __break(0x800u);
LABEL_40:
                  if ( (synx_debug & 1) != 0 )
                    printk(&unk_28BFE, &unk_29207, "synx_handle_release_n", 3441, v19, v20);
                  LODWORD(a2) = -14;
                }
                else
                {
                  v25 = v34;
                  v26 = 12LL * (unsigned int)v35;
                  _check_object_size(v7, v26, 1);
                  if ( inline_copy_to_user(v25, v7, v26) )
                    goto LABEL_40;
                }
                kfree(v7);
                kfree(v31);
                result = (unsigned int)a2;
                goto LABEL_19;
              }
            }
            else if ( !(_DWORD)v32 )
            {
              goto LABEL_38;
            }
            v21 = 0;
            v22 = 0;
            v23 = 4;
            while ( v6 > v23 )
            {
              v24 = synx_debug;
              *(_DWORD *)(v7 + v23) = *(_DWORD *)(v31 + v21 + 4);
              if ( (v24 & 8) != 0 )
                printk(
                  &unk_25DC8,
                  &unk_2A972,
                  "synx_handle_release_n",
                  3434,
                  *(unsigned int *)(v31 + v21),
                  *(unsigned int *)(v31 + v21 + 4));
              ++v22;
              v23 += 12LL;
              v21 += 8;
              if ( v22 >= (unsigned int)v32 )
                goto LABEL_38;
            }
          }
          __break(1u);
          v27 = (unsigned int)v35;
          StatusReg = _ReadStatusReg(SP_EL0);
          v29 = *(_QWORD *)(StatusReg + 80);
          v6 = 12 * v27;
          *(_QWORD *)(StatusReg + 80) = &synx_handle_release_n__alloc_tag;
          v7 = _kmalloc_noprof(12 * v27, 3520);
          *(_QWORD *)(StatusReg + 80) = v29;
          result = 4294967284LL;
          if ( !v7 )
            goto LABEL_19;
        }
        kfree(v7);
        result = 4294967284LL;
      }
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
