__int64 __fastcall curr_list_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  unsigned int v6; // w8
  _BYTE *v7; // x9
  _BYTE *v8; // x8
  int v10; // w11
  unsigned int v11; // w10
  _BOOL4 v12; // w9
  int v13; // w12
  int v14; // w10
  unsigned int v15; // w10
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v16[0] = 0;
  if ( !(unsigned int)kstrtoull(a3, 16, v16) && v16[0] < (unsigned __int64)*(unsigned int *)(v5 + 328) )
  {
    mutex_lock(v5 + 24);
    v6 = *(_DWORD *)(v5 + 328);
    if ( v6 )
    {
      v7 = *(_BYTE **)(v5 + 120);
      if ( (*v7 & 1) != 0 )
      {
        v8 = (_BYTE *)(v5 + 332);
      }
      else
      {
        v10 = 1;
        do
        {
          v11 = v10;
          if ( v6 == v10 )
            break;
          ++v10;
        }
        while ( v7[v11] != 1 );
        v12 = v11 < v6;
        v8 = (_BYTE *)(v5 + 332);
        if ( !v12 )
          goto LABEL_14;
      }
      if ( *(unsigned __int8 *)(v5 + 332) != 255 )
      {
        dev_err(*(_QWORD *)(v5 + 16), "DCC is enabled, please disable it first.\n");
        goto LABEL_24;
      }
    }
    else
    {
      v8 = (_BYTE *)(v5 + 332);
    }
LABEL_14:
    v13 = *(_DWORD *)(v5 + 104);
    v14 = LODWORD(v16[0]) << 7;
    if ( v13 == 1 )
    {
      v15 = v14 | 0x2C;
    }
    else if ( v13 )
    {
      v15 = (LODWORD(v16[0]) << 7) | 0x34;
    }
    else
    {
      v15 = v14 | 0x1C;
    }
    if ( (*(_DWORD *)(*(_QWORD *)v5 + v15) & 1) == 0 )
    {
      *v8 = v16[0];
LABEL_21:
      mutex_unlock(v5 + 24);
      goto LABEL_7;
    }
    dev_err(*(_QWORD *)(v5 + 16), "DCC linked list is already configured\n");
LABEL_24:
    a4 = -22;
    goto LABEL_21;
  }
  a4 = -22;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return a4;
}
