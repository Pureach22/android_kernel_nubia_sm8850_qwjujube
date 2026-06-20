__int64 __fastcall process_raw_ctrs(__int64 result, __int64 a2, __int64 a3, int a4)
{
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x12
  __int64 v8; // x13
  int v9; // w15
  __int64 v10; // x14
  _QWORD *v11; // x15
  _DWORD *v12; // x16
  __int64 v13; // x16
  _DWORD *v14; // x16
  __int64 v15; // x16
  _DWORD *v16; // x16
  __int64 v17; // x16
  _DWORD *v18; // x16
  __int64 v19; // x16
  _DWORD *v20; // x16
  __int64 v21; // x15

  v4 = *(unsigned int *)(result + 552);
  if ( (_DWORD)v4 )
  {
    v5 = 0;
    v6 = memlat_data;
    v7 = result + 456;
    v8 = result + 184;
    do
    {
      if ( v5 == 8 )
      {
        __break(0x5512u);
        if ( !a4 )
          JUMPOUT(0xAC74);
        JUMPOUT(0xFFFFFFFFFFFC7AECLL);
      }
      v9 = *(_DWORD *)(v7 + 4 * v5);
      if ( !v9 )
        return result;
      v10 = *(_QWORD *)(v7 + 8 * v5 + 32);
      if ( v9 == *(_DWORD *)(v6 + 104) )
      {
        v11 = (_QWORD *)(result + 152);
        goto LABEL_53;
      }
      if ( v9 == *(_DWORD *)(v6 + 108) )
      {
        v11 = (_QWORD *)(result + 160);
        goto LABEL_53;
      }
      if ( v9 == *(_DWORD *)(v6 + 112) )
      {
        v11 = (_QWORD *)(result + 168);
        goto LABEL_53;
      }
      if ( v9 == *(_DWORD *)(v6 + 116) )
      {
        v11 = (_QWORD *)(result + 176);
        goto LABEL_53;
      }
      v12 = *(_DWORD **)(v6 + 248);
      if ( v12 )
      {
        if ( v9 == v12[18] )
        {
          v13 = 0;
        }
        else if ( v9 == v12[19] )
        {
          v13 = 1;
        }
        else
        {
          if ( v9 != v12[20] )
            goto LABEL_21;
          v13 = 2;
        }
        *(_QWORD *)(v8 + 8 * v13) = v10;
      }
LABEL_21:
      v14 = *(_DWORD **)(v6 + 256);
      if ( !v14 )
        goto LABEL_29;
      if ( v9 == v14[18] )
      {
        v15 = 0;
      }
      else if ( v9 == v14[19] )
      {
        v15 = 1;
      }
      else
      {
        if ( v9 != v14[20] )
          goto LABEL_29;
        v15 = 2;
      }
      *(_QWORD *)(v8 + 8 * v15 + 24) = v10;
LABEL_29:
      v16 = *(_DWORD **)(v6 + 264);
      if ( !v16 )
        goto LABEL_37;
      if ( v9 == v16[18] )
      {
        v17 = 0;
      }
      else if ( v9 == v16[19] )
      {
        v17 = 1;
      }
      else
      {
        if ( v9 != v16[20] )
          goto LABEL_37;
        v17 = 2;
      }
      *(_QWORD *)(v8 + 8 * v17 + 48) = v10;
LABEL_37:
      v18 = *(_DWORD **)(v6 + 272);
      if ( v18 )
      {
        if ( v9 == v18[18] )
        {
          v19 = 0;
LABEL_44:
          *(_QWORD *)(v8 + 8 * v19 + 72) = v10;
          goto LABEL_45;
        }
        if ( v9 == v18[19] )
        {
          v19 = 1;
          goto LABEL_44;
        }
        if ( v9 == v18[20] )
        {
          v19 = 2;
          goto LABEL_44;
        }
      }
LABEL_45:
      v20 = *(_DWORD **)(v6 + 280);
      if ( v20 )
      {
        if ( v9 == v20[18] )
        {
          v21 = 0;
          goto LABEL_52;
        }
        if ( v9 == v20[19] )
        {
          v21 = 1;
          goto LABEL_52;
        }
        if ( v9 == v20[20] )
        {
          v21 = 2;
LABEL_52:
          v11 = (_QWORD *)(v8 + 8 * v21 + 96);
LABEL_53:
          *v11 = v10;
        }
      }
      ++v5;
    }
    while ( v5 < v4 );
  }
  return result;
}
