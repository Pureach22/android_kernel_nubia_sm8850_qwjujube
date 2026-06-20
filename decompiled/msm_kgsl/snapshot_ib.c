__int64 __fastcall snapshot_ib(_QWORD *a1, __int64 *a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v5; // x20
  __int64 *v7; // x25
  __int64 v8; // x8
  _QWORD *v9; // x21
  unsigned __int64 v11; // x24
  unsigned __int64 v12; // x8
  __int64 v13; // x8
  void (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x8
  unsigned __int64 v16; // x9
  const void *v17; // x21
  __int64 v18; // x9
  unsigned __int64 v19; // x13
  char v20; // w15
  bool v21; // cf
  unsigned __int64 v22; // x16
  __int64 v23; // x4
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x8
  __int64 v26; // x10
  unsigned __int64 v27; // x14
  bool v28; // w16
  unsigned __int64 v29; // x17
  __int64 v30; // x10
  unsigned __int64 v31; // x14
  bool v32; // w16
  unsigned __int64 v33; // x17
  __int64 v34; // x4
  unsigned __int64 v35; // x8
  __int64 v36; // x9
  __int64 v37; // x10
  unsigned __int64 v38; // x14
  bool v39; // w16
  unsigned __int64 v40; // x17
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 (*v43)(void); // x8
  __int64 result; // x0
  __int64 v45[2]; // [xsp+0h] [xbp-10h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45[0] = 0;
  if ( !a4 || (v5 = *a4) == 0 || (v7 = (__int64 *)a4[1]) == nullptr )
  {
    dev_err(*a1, "snapshot: bad metadata\n");
LABEL_98:
    result = 0;
    goto LABEL_99;
  }
  v8 = v7[1];
  v9 = (_QWORD *)v7[4];
  if ( !v8 )
  {
    v8 = v9[6] - *v7 + v9[4];
    v7[1] = v8;
  }
  if ( v8 + 24 > a3 )
  {
    dev_err(*a1, "snapshot: Not enough memory for the ib\n");
    goto LABEL_98;
  }
  v11 = *v7;
  v12 = v9[4];
  if ( v12 > *v7 || v9[6] + v12 <= v11 )
    goto LABEL_97;
  v13 = v9[9];
  if ( v13 )
  {
    v14 = *(void (__fastcall **)(_QWORD))(v13 + 24);
    if ( v14 )
    {
      if ( *((_DWORD *)v14 - 1) != -441828660 )
        __break(0x8228u);
      v14(v9 + 1);
    }
  }
  v15 = v9[2];
  if ( !v15 )
  {
    v11 = *v7;
    goto LABEL_97;
  }
  v16 = v11 - v9[4];
  v11 = *v7;
  v17 = (const void *)(v15 + v16);
  if ( !(v15 + v16) )
  {
LABEL_97:
    dev_err(*a1, "snapshot: Unable to map GPU memory object 0x%016llX into the kernel\n", v11);
    goto LABEL_98;
  }
  if ( a4[2] == v11 )
  {
    if ( objbufptr )
    {
      v18 = 0;
      v19 = 1;
      v20 = 1;
      while ( 1 )
      {
        if ( v18 == 448 )
          goto LABEL_101;
        v22 = objbuf[v18];
        if ( v22 <= v11 )
        {
          if ( (unsigned __int64)(v18 * 8 - 3576) < 0xFFFFFFFFFFFFF200LL )
            goto LABEL_100;
          if ( objbuf[v18 + 1] + v22 >= v7[1] + v11 )
          {
            if ( (unsigned __int64)(v18 * 8 - 3552) < 0xFFFFFFFFFFFFF200LL )
            {
LABEL_100:
              __break(1u);
              goto LABEL_101;
            }
            if ( *(_QWORD *)(objbuf[v18 + 4] + 256LL) == *(_QWORD *)(v7[4] + 256) )
              goto LABEL_32;
          }
        }
        v21 = v19 >= (unsigned int)objbufptr;
        v18 += 7;
        ++v19;
        v20 = !v21;
        if ( 7LL * (unsigned int)objbufptr == v18 )
          goto LABEL_32;
      }
    }
    v20 = 0;
LABEL_32:
    v23 = *(_QWORD *)(v5 + 8);
    *(_BYTE *)(v5 + 36) = v20 & 1;
    if ( (unsigned int)adreno_ib_create_object_list(
                         (__int64)a1,
                         *(_QWORD *)(v7[4] + 256),
                         *v7,
                         (unsigned __int64)v7[1] >> 2,
                         v23,
                         v45) == -7 )
      ib_max_objs = 1;
    if ( v45[0] )
    {
      snapshot_freeze_obj_list(v5, *(_QWORD *)(v7[4] + 256));
      adreno_ib_destroy_obj_list(v45[0]);
    }
  }
  v24 = a4[4];
  v25 = *v7;
  if ( v24 == *v7 )
  {
    if ( objbufptr )
    {
      v26 = 0;
      v27 = 1;
      v28 = 1;
      while ( v26 != 448 )
      {
        v29 = objbuf[v26];
        if ( v29 > v24 )
          goto LABEL_42;
        if ( (unsigned __int64)(v26 * 8 - 3576) < 0xFFFFFFFFFFFFF200LL )
          goto LABEL_100;
        if ( objbuf[v26 + 1] + v29 < v7[1] + v24 )
          goto LABEL_42;
        if ( (unsigned __int64)(v26 * 8 - 3552) < 0xFFFFFFFFFFFFF200LL )
          goto LABEL_100;
        if ( *(_QWORD *)(objbuf[v26 + 4] + 256LL) != *(_QWORD *)(v7[4] + 256) )
        {
LABEL_42:
          v21 = v27 >= (unsigned int)objbufptr;
          v26 += 7;
          ++v27;
          v28 = !v21;
          if ( 7LL * (unsigned int)objbufptr != v26 )
            continue;
        }
        goto LABEL_51;
      }
LABEL_101:
      __break(0x5512u);
    }
    v28 = 0;
LABEL_51:
    *(_BYTE *)(v5 + 37) = v28;
    v25 = *v7;
  }
  if ( a4[8] == v25 )
  {
    if ( objbufptr )
    {
      v30 = 0;
      v31 = 1;
      v32 = 1;
      while ( v30 != 448 )
      {
        v33 = objbuf[v30];
        if ( v33 > v25 )
          goto LABEL_58;
        if ( (unsigned __int64)(v30 * 8 - 3576) < 0xFFFFFFFFFFFFF200LL )
          goto LABEL_100;
        if ( objbuf[v30 + 1] + v33 < v7[1] + v25 )
          goto LABEL_58;
        if ( (unsigned __int64)(v30 * 8 - 3552) < 0xFFFFFFFFFFFFF200LL )
          goto LABEL_100;
        if ( *(_QWORD *)(objbuf[v30 + 4] + 256LL) != *(_QWORD *)(v7[4] + 256) )
        {
LABEL_58:
          v21 = v31 >= (unsigned int)objbufptr;
          v30 += 7;
          ++v31;
          v32 = !v21;
          if ( 7LL * (unsigned int)objbufptr != v30 )
            continue;
        }
        goto LABEL_67;
      }
      goto LABEL_101;
    }
    v32 = 0;
LABEL_67:
    v34 = *(_QWORD *)(v5 + 48);
    *(_BYTE *)(v5 + 64) = v32;
    if ( (unsigned int)adreno_ib_create_object_list(
                         (__int64)a1,
                         *(_QWORD *)(v7[4] + 256),
                         *v7,
                         (unsigned __int64)v7[1] >> 2,
                         v34,
                         v45) == -7 )
      ib_max_objs = 1;
    if ( v45[0] )
    {
      snapshot_freeze_obj_list(v5, *(_QWORD *)(v7[4] + 256));
      adreno_ib_destroy_obj_list(v45[0]);
    }
  }
  v35 = a4[10];
  v36 = *v7;
  if ( v35 == *v7 )
  {
    if ( objbufptr )
    {
      v37 = 0;
      v38 = 1;
      v39 = 1;
      while ( v37 != 448 )
      {
        v40 = objbuf[v37];
        if ( v40 > v35 )
          goto LABEL_77;
        if ( (unsigned __int64)(v37 * 8 - 3576) < 0xFFFFFFFFFFFFF200LL )
          goto LABEL_100;
        if ( objbuf[v37 + 1] + v40 < v7[1] + v35 )
          goto LABEL_77;
        if ( (unsigned __int64)(v37 * 8 - 3552) < 0xFFFFFFFFFFFFF200LL )
          goto LABEL_100;
        if ( *(_QWORD *)(objbuf[v37 + 4] + 256LL) != *(_QWORD *)(v7[4] + 256) )
        {
LABEL_77:
          v21 = v38 >= (unsigned int)objbufptr;
          v37 += 7;
          ++v38;
          v39 = !v21;
          if ( 7LL * (unsigned int)objbufptr != v37 )
            continue;
        }
        goto LABEL_86;
      }
      goto LABEL_101;
    }
    v39 = 0;
LABEL_86:
    *(_BYTE *)(v5 + 65) = v39;
    v36 = *v7;
  }
  *a2 = v36;
  v41 = *(_QWORD *)(*(_QWORD *)(v7[4] + 256) + 64LL);
  if ( v41 )
  {
    v42 = *(_QWORD *)(v41 + 96);
    if ( v42 && (v43 = *(__int64 (**)(void))(v42 + 48)) != nullptr )
    {
      if ( *((_DWORD *)v43 - 1) != 1831526433 )
        __break(0x8228u);
      v41 = v43();
    }
    else
    {
      v41 = 0;
    }
  }
  a2[1] = v41;
  a2[2] = (unsigned __int64)v7[1] >> 2;
  memcpy(a2 + 3, v17, v7[1]);
  result = v7[1] + 24;
LABEL_99:
  _ReadStatusReg(SP_EL0);
  return result;
}
