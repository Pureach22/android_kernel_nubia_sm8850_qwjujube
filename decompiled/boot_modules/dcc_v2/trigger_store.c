__int64 __fastcall trigger_store(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v5; // x19
  int v6; // w8
  __int64 result; // x0
  unsigned int v8; // w8
  int v9; // w9
  int v10; // w23
  unsigned int v11; // w8
  int v12; // w22
  int v13; // w11
  int v14; // w9
  unsigned int v15; // w10
  int v16; // w10
  int v17; // w14
  int v18; // w11
  unsigned int v19; // w13
  int v20; // w12
  unsigned int v21; // w12
  int v22; // w12
  unsigned int v23; // w10
  unsigned int v24; // w2
  int v25; // w21
  int v26; // w10
  unsigned int v27; // w10
  int v28; // w3
  int v29; // w10
  unsigned int v30; // w8
  bool v31; // zf
  unsigned int v32; // w10
  int v33; // w9
  int v34; // w12
  int v35; // w10
  int v36; // w10
  unsigned int v37; // w12
  int v38; // w11
  unsigned int v39; // w11
  int v40; // w11
  _QWORD v41[2]; // [xsp+0h] [xbp-10h] BYREF

  v41[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v41[0] = 0;
  v6 = kstrtoull(a3, 16, v41);
  result = -22;
  if ( v6 || v41[0] != 1 )
    goto LABEL_66;
  mutex_lock(v5 + 24);
  v8 = *(_DWORD *)(v5 + 328);
  if ( v8 )
  {
    v9 = 0;
    v10 = 68;
    do
    {
      v12 = v9;
      if ( *(_BYTE *)(*(_QWORD *)(v5 + 120) + v9) == 1 && *(_BYTE *)(*(_QWORD *)(v5 + 136) + v9) == 1 )
      {
        dev_info(*(_QWORD *)(v5 + 16), "DCC SW trigger link list %d\n", v9);
        v13 = *(_DWORD *)(v5 + 104);
        v14 = v12 << 7;
        v11 = (v12 << 7) | 0x38;
        if ( v13 == 1 )
        {
          v15 = v14 | 0x30;
        }
        else
        {
          v15 = (v12 << 7) | 0x38;
          if ( !v13 )
            v15 = v10 - 36;
        }
        v16 = *(_DWORD *)(*(_QWORD *)v5 + v15);
        v17 = *(_DWORD *)(v5 + 104);
        if ( v17 == 2 )
          v18 = -257;
        else
          v18 = -513;
        if ( v17 == 1 )
        {
          v19 = v14 | 0x30;
        }
        else
        {
          v19 = (v12 << 7) | 0x38;
          if ( !v17 )
            v19 = v10 - 36;
        }
        *(_DWORD *)(*(_QWORD *)v5 + v19) = v18 & v16;
        v20 = *(_DWORD *)(v5 + 104);
        if ( v20 == 1 )
        {
          v21 = v14 | 0x58;
        }
        else if ( v20 )
        {
          v21 = v14 | 0x60;
        }
        else
        {
          v21 = v10;
        }
        *(_DWORD *)(*(_QWORD *)v5 + v21) = 1;
        v22 = *(_DWORD *)(v5 + 104);
        if ( v22 == 1 )
        {
          v11 = v14 | 0x30;
        }
        else if ( !v22 )
        {
          v11 = v10 - 36;
        }
        *(_DWORD *)(*(_QWORD *)v5 + v11) = v16;
        v8 = *(_DWORD *)(v5 + 328);
      }
      v9 = v12 + 1;
      v10 += 128;
    }
    while ( v12 + 1 < v8 );
  }
  if ( (dcc_ready(v5) & 1) == 0 )
  {
    dev_err(*(_QWORD *)(v5 + 16), "DCC is busy after receiving sw tigger.\n");
    a4 = -16;
    goto LABEL_65;
  }
  v23 = *(_DWORD *)(v5 + 328);
  if ( !v23 )
    goto LABEL_65;
  v24 = 0;
  v25 = 100;
  while ( *(_BYTE *)(*(_QWORD *)(v5 + 120) + (int)v24) != 1 )
  {
LABEL_32:
    ++v24;
    v25 += 128;
    if ( v24 >= v23 )
      goto LABEL_65;
  }
  v26 = *(_DWORD *)(v5 + 104);
  if ( v26 == 1 )
  {
    v27 = (v24 << 7) | 0x5C;
  }
  else if ( v26 )
  {
    v27 = (v24 << 7) | 0x64;
  }
  else
  {
    v27 = v25 - 28;
  }
  v28 = *(_DWORD *)(*(_QWORD *)v5 + v27);
  if ( !v28 )
  {
    v23 = *(_DWORD *)(v5 + 328);
    goto LABEL_32;
  }
  dev_err(*(_QWORD *)(v5 + 16), "Read access error for list %d err: 0x%x.\n", v24, v28);
  v29 = *(_DWORD *)(v5 + 104);
  v30 = v25 - 44;
  if ( v29 )
  {
    v31 = v29 == 1;
    v32 = v25 - 44;
    if ( v31 )
      v32 = v25 - 52;
  }
  else
  {
    v32 = v25 - 68;
  }
  v33 = *(_DWORD *)(*(_QWORD *)v5 + v32);
  v34 = *(_DWORD *)(v5 + 104);
  if ( v34 == 2 )
    v35 = -257;
  else
    v35 = -513;
  v36 = v35 & v33;
  if ( v34 )
  {
    v31 = v34 == 1;
    v37 = v25 - 44;
    if ( v31 )
      v37 = v25 - 52;
  }
  else
  {
    v37 = v25 - 68;
  }
  *(_DWORD *)(*(_QWORD *)v5 + v37) = v36;
  v38 = *(_DWORD *)(v5 + 104);
  if ( v38 )
  {
    v31 = v38 == 1;
    v39 = v25;
    if ( v31 )
      v39 = v25 - 8;
  }
  else
  {
    v39 = v25 - 28;
  }
  *(_DWORD *)(*(_QWORD *)v5 + v39) = 3;
  v40 = *(_DWORD *)(v5 + 104);
  if ( v40 )
  {
    if ( v40 == 1 )
      v30 = v25 - 52;
  }
  else
  {
    v30 = v25 - 68;
  }
  *(_DWORD *)(*(_QWORD *)v5 + v30) = v33;
  a4 = -61;
LABEL_65:
  mutex_unlock(v5 + 24);
  result = a4;
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return result;
}
