__int64 __fastcall lpg_pattern_set(__int64 *a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x19
  unsigned int v8; // w23
  unsigned __int64 v9; // x20
  unsigned int *v10; // x0
  unsigned int v11; // w2
  unsigned int v12; // w8
  unsigned int i; // w10
  unsigned int *v14; // x11
  _DWORD *v15; // x13
  unsigned int v16; // w12
  unsigned __int64 v17; // x14
  int v18; // w9
  unsigned int v19; // w10
  __int64 v20; // x11
  unsigned int v21; // w14
  char v22; // w23
  unsigned int v23; // w25
  __int64 result; // x0
  __int64 v25; // x8
  __int64 v26; // x26
  unsigned int *v27; // x20
  __int64 v28; // x27
  unsigned int v29; // w0
  unsigned __int64 v30; // x11
  __int64 v31; // x10
  unsigned int v32; // w21
  int v33; // w9
  bool v34; // zf
  unsigned __int64 v35; // x8
  int v36; // w9
  int v37; // w10
  char v38; // w11
  __int64 v39; // x13
  __int64 v40; // x8
  unsigned __int64 StatusReg; // x25
  __int64 v42; // x26
  _QWORD v43[2]; // [xsp+0h] [xbp-10h] BYREF

  v43[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  if ( (a4 == 1 || a4 == -1) && (a3 & 1) == 0 )
  {
    v8 = a3;
    v9 = 8LL * (a3 >> 1);
    v10 = (unsigned int *)_kmalloc_noprof(v9, 3520);
    if ( !v10 )
    {
LABEL_53:
      result = 4294967284LL;
      goto LABEL_54;
    }
    while ( 2 )
    {
      v43[0] = 0;
      if ( v8 )
      {
        v12 = v8;
        for ( i = 0; i < v8; i += 2 )
        {
          v14 = (unsigned int *)(a2 + 8LL * i);
          v15 = (_DWORD *)(a2 + 8LL * (i + 1));
          v16 = v14[1];
          if ( v16 != v15[1] || *v15 )
            goto LABEL_38;
          if ( v9 < ((8LL * (i >> 1)) | 4uLL) )
            goto LABEL_52;
          v17 = 8LL * (i >> 1);
          v10[v17 / 4 + 1] = v16;
          if ( v9 <= v17 )
            goto LABEL_52;
          v10[v17 / 4] = *v14;
        }
        if ( v8 < 4 )
          break;
        v18 = *(_DWORD *)(v4 + 80);
        v19 = v8 >> 1;
        if ( v18 )
        {
          v20 = 0;
          v21 = v19 - 1;
          while ( v9 >= v20 * 4 + 4 && v9 >= ((8LL * v21) | 4uLL) )
          {
            if ( v10[v20 + 1] != v10[2 * v21 + 1] )
              goto LABEL_21;
            v20 += 2;
            --v21;
            if ( 2LL * (v8 >> 2) == v20 )
            {
              v22 = 1;
              v23 = (v19 + 1) >> 1;
              goto LABEL_22;
            }
          }
          goto LABEL_52;
        }
LABEL_21:
        v22 = 0;
        v23 = v12 >> 1;
LABEL_22:
        if ( v9 != 8 )
        {
          a2 = v10[2];
          if ( v12 != 4 )
          {
            if ( v19 <= 3 )
              v19 = 3;
            v30 = 16;
            v31 = 8LL * v19;
            while ( v9 > v30 )
            {
              if ( v10[v30 / 4] != (_DWORD)a2 && 8LL * (v23 - 1) != v30 )
                goto LABEL_38;
              v30 += 8LL;
              if ( v31 == v30 )
                goto LABEL_24;
            }
            goto LABEL_52;
          }
LABEL_24:
          if ( (unsigned int)a2 > 0x1FF )
            break;
          if ( v18 || *(_QWORD *)(v4 + 112) )
          {
            v25 = v23 - 1;
            if ( v9 <= 8 * (unsigned __int64)(unsigned int)v25 )
              goto LABEL_52;
            v26 = *v10;
            v27 = v10;
            v28 = v10[2 * v25];
LABEL_29:
            mutex_lock(v4 + 16);
            if ( *(_DWORD *)(v4 + 80) )
              v29 = lpg_lut_store(v4, v27, v23, (char *)v43 + 4, v43);
            else
              v29 = lpg_lut_store_sdam(v4, v27, v23, (char *)v43 + 4, v43);
            v33 = a4;
            v32 = v29;
            if ( (v29 & 0x80000000) == 0 && *((_DWORD *)a1 + 230) )
            {
              v34 = v33 == -1;
              v35 = 0;
              v37 = v43[0];
              v36 = HIDWORD(v43[0]);
              v38 = !v34;
              do
              {
                v39 = a1[v35++ + 116];
                *(_WORD *)(v39 + 76) = a2;
                *(_BYTE *)(v39 + 73) = v22;
                *(_BYTE *)(v39 + 74) = v38;
                *(_QWORD *)(v39 + 80) = v26;
                *(_QWORD *)(v39 + 88) = v28;
                *(_DWORD *)(v39 + 96) = v36;
                *(_DWORD *)(v39 + 100) = v37;
              }
              while ( v35 < *((unsigned int *)a1 + 230) );
            }
            mutex_unlock(v4 + 16);
            goto LABEL_39;
          }
          if ( (_DWORD)a2 != *v10 )
            break;
          v40 = v23 - 1;
          if ( v9 > 8 * (unsigned __int64)(unsigned int)v40 )
          {
            if ( (_DWORD)a2 != v10[2 * v40] )
              break;
            v27 = v10;
            v28 = 0;
            v26 = 0;
            goto LABEL_29;
          }
        }
LABEL_52:
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v42 = *(_QWORD *)(StatusReg + 80);
        v8 = v11;
        v9 = 8LL * (v11 >> 1);
        *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
        v10 = (unsigned int *)_kmalloc_noprof(v9, 3520);
        *(_QWORD *)(StatusReg + 80) = v42;
        if ( v10 )
          continue;
        goto LABEL_53;
      }
      break;
    }
LABEL_38:
    v32 = -22;
LABEL_39:
    kfree();
    result = v32;
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
