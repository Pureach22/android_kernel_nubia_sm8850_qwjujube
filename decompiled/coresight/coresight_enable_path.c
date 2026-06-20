__int64 __fastcall coresight_enable_path(_QWORD *a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x8
  __int64 v7; // x26
  _QWORD *v8; // x25
  __int64 (__fastcall *v9)(__int64 *, unsigned __int64); // x8
  unsigned __int64 v10; // x24
  __int64 *v11; // x23
  __int64 v12; // x8
  int v13; // w27
  __int64 i; // x28
  __int64 v15; // x0
  __int64 (*v16)(void); // x9
  int v17; // w0
  __int64 v18; // x9
  _DWORD *v19; // x8
  int v20; // w0
  _QWORD *v21; // x9
  __int64 v22; // x27
  __int64 v23; // x10
  unsigned __int64 *v24; // x11
  const char *v25; // x2
  const char *v26; // x3
  __int64 v27; // x9
  unsigned __int64 *v28; // x8
  unsigned __int64 v29; // x2
  const char *v30; // x2
  const char *v31; // x3
  int v32; // w8

  if ( a1 && (v6 = *(_QWORD *)(*a1 - 8LL)) != 0 )
  {
    if ( *(_DWORD *)(v6 + 8) == 3 )
      v7 = *(_QWORD *)(*a1 - 8LL);
    else
      v7 = 0;
  }
  else
  {
    v7 = 0;
  }
  v8 = (_QWORD *)a1[1];
  if ( v8 == a1 )
  {
LABEL_68:
    LODWORD(v10) = 0;
    return (unsigned int)v10;
  }
  while ( 1 )
  {
    v11 = (__int64 *)*(v8 - 1);
    v12 = *v11;
    v13 = *((_DWORD *)v11 + 2);
    if ( *(int *)(*v11 + 4) >= 1 )
    {
      for ( i = 0; i < *(int *)(v12 + 4); ++i )
      {
        v15 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 8) + 8 * i) + 16LL);
        if ( v15 )
        {
          if ( *(_DWORD *)(v15 + 8) == 4 )
          {
            v16 = **(__int64 (***)(void))(*(_QWORD *)(v15 + 24) + 24LL);
            if ( v16 )
            {
              if ( *((_DWORD *)v16 - 1) != -1807167071 )
                __break(0x8229u);
              v17 = v16();
              if ( v17 )
              {
                LODWORD(v10) = v17;
                goto LABEL_70;
              }
              v12 = *v11;
            }
          }
        }
      }
    }
    if ( v13 == 2 )
    {
      if ( !a1 || (v18 = *(_QWORD *)(a1[1] - 8LL), (*(_DWORD *)(v18 + 8) | 2) != 2) )
        v18 = 0;
      v13 = v11 != (__int64 *)v18;
    }
    if ( v13 == 3 )
      goto LABEL_13;
    if ( v13 == 1 )
    {
      LODWORD(v10) = -22;
      v21 = *(_QWORD **)(v8[1] - 8LL);
      if ( !v21 )
        goto LABEL_70;
      v22 = *(_QWORD *)(*v8 - 8LL);
      if ( !v22 )
        goto LABEL_70;
      v23 = *(unsigned int *)(*v21 + 4LL);
      if ( (int)v23 < 1 )
      {
LABEL_45:
        v25 = (const char *)v21[21];
        if ( !v25 )
          v25 = (const char *)v21[7];
        v26 = (const char *)v11[21];
        if ( !v26 )
          v26 = (const char *)v11[7];
        dev_err(v21 + 7, "couldn't find output connection, csdev: %s, out_dev: %s\n", v25, v26);
        v12 = *v11;
        v10 = -19;
      }
      else
      {
        v24 = *(unsigned __int64 **)(*v21 + 8LL);
        while ( 1 )
        {
          v10 = *v24;
          if ( (!*(_QWORD *)(*v24 + 40) || *(_QWORD *)(v10 + 48) == v7) && *(__int64 **)(v10 + 16) == v11 )
            break;
          --v23;
          ++v24;
          if ( !v23 )
            goto LABEL_45;
        }
      }
      v27 = *(unsigned int *)(v12 + 4);
      if ( (int)v27 < 1 )
      {
LABEL_57:
        v30 = (const char *)v11[21];
        if ( !v30 )
          v30 = (const char *)v11[7];
        v31 = *(const char **)(v22 + 168);
        if ( !v31 )
          v31 = *(const char **)(v22 + 56);
        dev_err(v11 + 7, "couldn't find output connection, csdev: %s, out_dev: %s\n", v30, v31);
        v29 = -19;
      }
      else
      {
        v28 = *(unsigned __int64 **)(v12 + 8);
        while ( 1 )
        {
          v29 = *v28;
          if ( (!*(_QWORD *)(*v28 + 40) || *(_QWORD *)(v29 + 48) == v7) && *(_QWORD *)(v29 + 16) == v22 )
            break;
          --v27;
          ++v28;
          if ( !v27 )
            goto LABEL_57;
        }
      }
      v32 = *((_DWORD *)v11 + 4);
      if ( v32 == 1 )
      {
        if ( v29 >= 0xFFFFFFFFFFFFF001LL )
        {
          LODWORD(v10) = v29;
          goto LABEL_12;
        }
      }
      else if ( !v32 && v10 >= 0xFFFFFFFFFFFFF001LL )
      {
        goto LABEL_12;
      }
      v9 = **(__int64 (__fastcall ***)(__int64 *, unsigned __int64))(v11[3] + 8);
      if ( *((_DWORD *)v9 - 1) != 8774143 )
        __break(0x8228u);
      LODWORD(v10) = v9(v11, v10);
LABEL_12:
      if ( (_DWORD)v10 )
        goto LABEL_70;
      goto LABEL_13;
    }
    if ( v13 )
      break;
    v19 = **(_DWORD ***)v11[3];
    if ( *(v19 - 1) != -1807167071 )
      __break(0x8228u);
    v20 = ((__int64 (__fastcall *)(__int64 *, _QWORD, __int64))v19)(v11, a2, a3);
    if ( v20 )
    {
      LODWORD(v10) = v20;
      return (unsigned int)v10;
    }
LABEL_13:
    v8 = (_QWORD *)v8[1];
    if ( v8 == a1 )
      goto LABEL_68;
  }
  LODWORD(v10) = 0;
LABEL_70:
  coresight_disable_path_from((__int64)a1, (__int64)(v8 - 1));
  return (unsigned int)v10;
}
