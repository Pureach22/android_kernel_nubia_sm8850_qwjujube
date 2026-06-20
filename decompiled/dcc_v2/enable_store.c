__int64 __fastcall enable_store(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v5; // x20
  int v6; // w8
  __int64 result; // x0
  int v8; // w0
  unsigned int v9; // w12
  unsigned int v10; // w11
  int v11; // w8
  unsigned int v12; // w12
  int v13; // w15
  int v14; // w12
  unsigned int v15; // w13
  unsigned int v16; // w14
  int v17; // w14
  unsigned int v18; // w14
  int v19; // w15
  int v20; // w14
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v21[0] = 0;
  v6 = kstrtoull(a3, 16, v21);
  result = -22;
  if ( !v6 && v21[0] <= 1u )
  {
    if ( v21[0] )
    {
      v8 = dcc_enable(v5);
      if ( v8 )
        a4 = v8;
      goto LABEL_32;
    }
    mutex_lock(v5 + 24);
    if ( (dcc_ready((_QWORD *)v5) & 1) != 0 )
    {
      v9 = *(_DWORD *)(v5 + 328);
      if ( v9 )
        goto LABEL_8;
    }
    else
    {
      dev_err(*(_QWORD *)(v5 + 16), "DCC is not ready Disabling DCC...\n");
      v9 = *(_DWORD *)(v5 + 328);
      if ( v9 )
      {
LABEL_8:
        v10 = 0;
        v11 = 40;
        do
        {
          if ( *(_BYTE *)(*(_QWORD *)(v5 + 120) + (int)v10) == 1 )
          {
            v13 = *(_DWORD *)(v5 + 104);
            v14 = v10 << 7;
            v15 = (v10 << 7) | 0x38;
            if ( v13 == 1 )
            {
              v16 = v14 | 0x30;
            }
            else
            {
              v16 = (v10 << 7) | 0x38;
              if ( !v13 )
                v16 = v11 - 8;
            }
            *(_DWORD *)(*(_QWORD *)v5 + v16) = 0;
            v17 = *(_DWORD *)(v5 + 104);
            if ( v17 == 1 )
            {
              v18 = v14 | 0x34;
            }
            else if ( v17 )
            {
              v18 = v14 | 0x3C;
            }
            else
            {
              v18 = v11 - 4;
            }
            *(_DWORD *)(*(_QWORD *)v5 + v18) = 0;
            v19 = *(_DWORD *)(v5 + 104);
            if ( v19 != 1 )
            {
              if ( v19 )
                v15 = v14 | 0x40;
              else
                v15 = v11;
            }
            *(_DWORD *)(*(_QWORD *)v5 + v15) = 0;
            v20 = *(_DWORD *)(v5 + 104);
            if ( v20 == 1 )
            {
              v12 = v14 | 0x2C;
            }
            else if ( v20 )
            {
              v12 = v14 | 0x34;
            }
            else
            {
              v12 = v11 - 12;
            }
            *(_DWORD *)(*(_QWORD *)v5 + v12) = 0;
            *(_BYTE *)(*(_QWORD *)(v5 + 120) + (int)v10) = 0;
            v9 = *(_DWORD *)(v5 + 328);
          }
          ++v10;
          v11 += 128;
        }
        while ( v10 < v9 );
      }
    }
    _memset_io(*(_QWORD *)(v5 + 72), 0, *(unsigned int *)(v5 + 80));
    *(_QWORD *)(v5 + 108) = 0;
    *(_DWORD *)(v5 + 348) = 0;
    mutex_unlock(v5 + 24);
LABEL_32:
    result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
