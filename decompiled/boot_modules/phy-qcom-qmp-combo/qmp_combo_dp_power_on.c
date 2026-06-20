__int64 __fastcall qmp_combo_dp_power_on(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v4; // x20
  __int64 v5; // x24
  __int64 v6; // x23
  __int64 v7; // x8
  int v8; // w25
  bool v9; // cc
  int v10; // w8
  __int64 v11; // x8
  int v12; // w24
  _BYTE *v13; // x25
  _BYTE *v14; // x26
  __int64 v15; // x8
  int v16; // w24
  _BYTE *v17; // x25
  __int64 v18; // x8
  int v19; // w24
  _BYTE *v20; // x25
  __int64 v21; // x8
  int v22; // w24
  _BYTE *v23; // x25
  __int64 v24; // x8
  int v25; // w23
  _BYTE *v26; // x24
  _BYTE *v27; // x22
  void (__fastcall *v28)(_QWORD); // x8
  void (__fastcall *v29)(_QWORD); // x8

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 104);
  v2 = *(_QWORD *)(v1 + 112);
  v4 = *(_QWORD *)(v1 + 8);
  mutex_lock(v1 + 208);
  v5 = *(_QWORD *)(v1 + 8);
  v6 = *(_QWORD *)(v1 + 96);
  v7 = *(_QWORD *)(v5 + 88);
  v8 = *(_DWORD *)(v5 + 96);
  if ( v7 )
    v9 = v8 < 1;
  else
    v9 = 1;
  if ( !v9 )
  {
    v14 = (_BYTE *)(v7 + 8);
    do
    {
      if ( *v14 )
        writel(*((_DWORD *)v14 - 1), (unsigned int *)(v6 + *((unsigned int *)v14 - 2)));
      --v8;
      v14 += 12;
    }
    while ( v8 );
  }
  v10 = *(_DWORD *)(v1 + 300);
  if ( v10 > 5399 )
  {
    if ( v10 == 5400 )
    {
      v21 = *(_QWORD *)(v5 + 152);
      if ( v21 )
      {
        v22 = *(_DWORD *)(v5 + 160);
        if ( v22 >= 1 )
        {
          v23 = (_BYTE *)(v21 + 8);
          do
          {
            if ( *v23 )
              writel(*((_DWORD *)v23 - 1), (unsigned int *)(v6 + *((unsigned int *)v23 - 2)));
            --v22;
            v23 += 12;
          }
          while ( v22 );
        }
      }
    }
    else if ( v10 == 8100 )
    {
      v15 = *(_QWORD *)(v5 + 168);
      if ( v15 )
      {
        v16 = *(_DWORD *)(v5 + 176);
        if ( v16 >= 1 )
        {
          v17 = (_BYTE *)(v15 + 8);
          do
          {
            if ( *v17 )
              writel(*((_DWORD *)v17 - 1), (unsigned int *)(v6 + *((unsigned int *)v17 - 2)));
            --v16;
            v17 += 12;
          }
          while ( v16 );
        }
      }
    }
  }
  else if ( v10 == 1620 )
  {
    v18 = *(_QWORD *)(v5 + 120);
    if ( v18 )
    {
      v19 = *(_DWORD *)(v5 + 128);
      if ( v19 >= 1 )
      {
        v20 = (_BYTE *)(v18 + 8);
        do
        {
          if ( *v20 )
            writel(*((_DWORD *)v20 - 1), (unsigned int *)(v6 + *((unsigned int *)v20 - 2)));
          --v19;
          v20 += 12;
        }
        while ( v19 );
      }
    }
  }
  else if ( v10 == 2700 )
  {
    v11 = *(_QWORD *)(v5 + 136);
    if ( v11 )
    {
      v12 = *(_DWORD *)(v5 + 144);
      if ( v12 >= 1 )
      {
        v13 = (_BYTE *)(v11 + 8);
        do
        {
          if ( *v13 )
            writel(*((_DWORD *)v13 - 1), (unsigned int *)(v6 + *((unsigned int *)v13 - 2)));
          --v12;
          v13 += 12;
        }
        while ( v12 );
      }
    }
  }
  v24 = *(_QWORD *)(v4 + 104);
  v25 = *(_DWORD *)(v4 + 112);
  if ( v24 && v25 >= 1 )
  {
    v26 = (_BYTE *)(v24 + 8);
    do
    {
      if ( (*v26 & 1) != 0 )
        writel(*((_DWORD *)v26 - 1), (unsigned int *)(v3 + *((unsigned int *)v26 - 2)));
      --v25;
      v26 += 12;
    }
    while ( v25 );
    v24 = *(_QWORD *)(v4 + 104);
    v25 = *(_DWORD *)(v4 + 112);
  }
  if ( v24 && v25 >= 1 )
  {
    v27 = (_BYTE *)(v24 + 8);
    do
    {
      if ( (*v27 & 2) != 0 )
        writel(*((_DWORD *)v27 - 1), (unsigned int *)(v2 + *((unsigned int *)v27 - 2)));
      --v25;
      v27 += 12;
    }
    while ( v25 );
  }
  v28 = *(void (__fastcall **)(_QWORD))(v4 + 224);
  if ( *((_DWORD *)v28 - 1) != -1494932575 )
    __break(0x8228u);
  v28(v1);
  v29 = *(void (__fastcall **)(_QWORD))(v4 + 216);
  if ( *((_DWORD *)v29 - 1) != 1426351319 )
    __break(0x8228u);
  v29(v1);
  mutex_unlock(v1 + 208);
  return 0;
}
