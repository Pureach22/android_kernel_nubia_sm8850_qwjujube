__int64 __fastcall find_timeout_syncobj(__int64 a1, unsigned int a2, int a3)
{
  __int64 v6; // x24
  unsigned int *v7; // x0
  unsigned int v8; // w8
  unsigned int v10; // w25
  unsigned int v16; // w9
  __int64 result; // x0
  unsigned int *v18; // x27
  unsigned int v19; // w23
  unsigned int *v20; // x25
  unsigned int v21; // w8
  unsigned __int64 v22; // x26
  __int64 v23; // x10
  __int64 v24; // x24
  unsigned int v25; // w25
  unsigned __int64 v26; // x26
  unsigned int v27; // w0
  char v28; // w9
  unsigned int v29; // w28
  int v30; // w8
  int v31; // w0
  int v32; // w0
  char *v33; // x0
  __int64 v34; // x1
  int v35; // w0
  char *v36; // x0
  __int64 v37; // x1
  int v38; // w0
  char *v39; // x0
  __int64 v40; // x1
  int v42; // w8
  __int64 v43; // [xsp+8h] [xbp-C8h]
  __int64 s; // [xsp+10h] [xbp-C0h] BYREF
  __int64 v45; // [xsp+18h] [xbp-B8h]
  unsigned int v46; // [xsp+20h] [xbp-B0h]
  __int64 v47; // [xsp+28h] [xbp-A8h] BYREF
  __int64 v48; // [xsp+30h] [xbp-A0h]
  __int64 v49; // [xsp+38h] [xbp-98h]
  _QWORD v50[18]; // [xsp+40h] [xbp-90h] BYREF

  v50[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = to_gen7_gmu(a1);
  v46 = 0;
  s = 0;
  v45 = 0;
  raw_read_lock(a1 + 11208);
  v7 = (unsigned int *)idr_find(a1 + 11184, a2);
  if ( !v7 )
  {
    result = raw_read_unlock(a1 + 11208);
    goto LABEL_58;
  }
  v8 = *v7;
  _X19 = v7;
  if ( *v7 )
  {
    do
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v16 = __ldxr(v7);
      while ( v16 == v8 && __stxr(v8 + 1, v7) );
      v10 = v8;
      if ( v16 == v8 )
        break;
      v10 = 0;
      v8 = v16;
    }
    while ( v16 );
  }
  else
  {
    v10 = 0;
  }
  if ( (((v10 + 1) | v10) & 0x80000000) != 0 )
    refcount_warn_saturate(v7, 0);
  result = raw_read_unlock(a1 + 11208);
  if ( v10 )
  {
    v18 = *((unsigned int **)_X19 + 206);
    v19 = v18[5];
    if ( v19 == v18[6] )
    {
LABEL_16:
      if ( v19 == v18[6] )
        result = dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Couldn't find unsignaled syncobj ctx:%d ts:%d\n", a2, a3);
      __asm { PRFM            #0x11, [X19] }
      do
        v42 = __ldxr(_X19);
      while ( __stlxr(v42 - 1, _X19) );
      if ( v42 == 1 )
      {
        __dmb(9u);
        result = kgsl_context_destroy(_X19);
      }
      else if ( v42 <= 0 )
      {
        result = refcount_warn_saturate(_X19, 3);
      }
      goto LABEL_58;
    }
    v20 = v18 + 12;
    while ( 1 )
    {
      v21 = v20[v19];
      if ( (unsigned __int8)v21 == 152 )
      {
        result = adreno_gmu_context_queue_read((int)_X19, &s);
        if ( (_DWORD)result )
          goto LABEL_16;
        if ( HIDWORD(v45) == a3 )
        {
          v22 = v18[2];
          result = gen7_gmu_to_adreno(v6);
          if ( !v46 )
            goto LABEL_16;
          v23 = *((_QWORD *)_X19 + 206);
          v24 = result;
          v25 = 0;
          v48 = 0;
          v49 = 0;
          v47 = 0;
          memset(v50, 0, 128);
          v43 = v23;
          v26 = ((unsigned __int64)v19 + 5) % v22;
          while ( 2 )
          {
            result = adreno_gmu_context_queue_read((int)_X19, &v47);
            if ( (_DWORD)result )
              goto LABEL_16;
            v27 = scnprintf(v50, 128, "syncobj[%d] ctxt_id:%llu seqno:%llu flags:", v25, v47, v48);
            v28 = v49;
            v29 = v27;
            if ( (v49 & 1) != 0 )
            {
              v31 = scnprintf((char *)v50 + v27, 128 - v27, "%s", "KGSL");
              v28 = v49;
              v29 += v31;
              if ( (v49 & 2) != 0 )
              {
                v32 = scnprintf((char *)v50 + v29, 128 - v29, "|%s", "SIGNALED");
                goto LABEL_36;
              }
              v30 = 0;
            }
            else
            {
              if ( (v49 & 2) == 0 )
              {
                v30 = 1;
                goto LABEL_37;
              }
              v32 = scnprintf((char *)v50 + v27, 128 - v27, "%s", "SIGNALED");
LABEL_36:
              v28 = v49;
              v30 = 0;
              v29 += v32;
            }
LABEL_37:
            if ( (v28 & 4) != 0 )
            {
              v33 = (char *)v50 + v29;
              v34 = 128 - v29;
              if ( v30 )
                v35 = scnprintf(v33, v34, "%s", "QUERIED");
              else
                v35 = scnprintf(v33, v34, "|%s", "QUERIED");
              v28 = v49;
              v30 = 0;
              v29 += v35;
              if ( (v49 & 8) != 0 )
                goto LABEL_45;
LABEL_39:
              if ( (v28 & 0x10) != 0 )
              {
LABEL_49:
                v39 = (char *)v50 + v29;
                v40 = 128 - v29;
                if ( v30 )
                  scnprintf(v39, v40, "%s", "SW_PENDING");
                else
                  scnprintf(v39, v40, "|%s", "SW_PENDING");
              }
            }
            else
            {
              if ( (v28 & 8) == 0 )
                goto LABEL_39;
LABEL_45:
              v36 = (char *)v50 + v29;
              v37 = 128 - v29;
              if ( v30 )
                v38 = scnprintf(v36, v37, "%s", "SW_SIGNALED");
              else
                v38 = scnprintf(v36, v37, "|%s", "SW_SIGNALED");
              v30 = 0;
              v29 += v38;
              if ( (v49 & 0x10) != 0 )
                goto LABEL_49;
            }
            result = dev_err(*(_QWORD *)(v24 + 1544) + 16LL, "%s\n", (const char *)v50);
            ++v25;
            v26 = ((unsigned __int64)(unsigned int)v26 + 6) % *(unsigned int *)(v43 + 8);
            if ( v25 >= v46 )
              goto LABEL_16;
            continue;
          }
        }
        v21 = v20[v19];
      }
      v19 = (v19 + BYTE1(v21)) % v18[2];
      if ( v19 == v18[6] )
        goto LABEL_16;
    }
  }
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return result;
}
