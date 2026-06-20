__int64 __fastcall page_list_merge(__int64 *a1, _QWORD *a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x9
  __int64 result; // x0
  __int64 v9; // x22
  __int64 v10; // x23
  char v11; // w8
  __int64 v12; // x25
  __int64 v13; // x9
  _QWORD *v14; // x9
  char v15; // w8
  char v16; // w9
  char v17; // w8
  char v18; // w8
  __int64 v19; // x9
  __int64 v20; // x9

  v6 = *a1;
  result = a3;
  v9 = *a2 - 8LL;
  v10 = v6 - 8;
  while ( 1 )
  {
    v14 = (_QWORD *)(v9 + 8);
    if ( (__int64 *)(v10 + 8) != a1 && v14 != a2 )
    {
      if ( (*(_QWORD *)v9 & 0x40) != 0 )
      {
        v15 = *(_BYTE *)(v9 + 64);
        if ( (*(_QWORD *)v10 & 0x40) != 0 )
          goto LABEL_9;
      }
      else
      {
        v15 = 0;
        if ( (*(_QWORD *)v10 & 0x40) != 0 )
        {
LABEL_9:
          v16 = *(_BYTE *)(v10 + 64);
LABEL_15:
          if ( 4096LL << v15 >= (unsigned __int64)(4096LL << v16) )
          {
            if ( (*(_QWORD *)v9 & 0x40) != 0 )
              v17 = *(_BYTE *)(v9 + 64);
            else
              v17 = 0;
            if ( (v9 & 3) != 0 )
              goto LABEL_38;
            goto LABEL_31;
          }
          if ( (*(_QWORD *)v10 & 0x40) != 0 )
            v18 = *(_BYTE *)(v10 + 64);
          else
            v18 = 0;
          if ( (v10 & 3) != 0 )
            goto LABEL_37;
          goto LABEL_35;
        }
      }
      v16 = 0;
      goto LABEL_15;
    }
    if ( v14 != a2 )
      break;
    if ( (__int64 *)(v10 + 8) != a1 )
    {
      if ( (*(_QWORD *)v10 & 0x40) != 0 )
        v18 = *(_BYTE *)(v10 + 64);
      else
        v18 = 0;
      if ( (v10 & 3) != 0 )
        goto LABEL_39;
LABEL_35:
      v20 = *(_QWORD *)result & 3LL;
      *(_DWORD *)(result + 8) = 0;
      *(_DWORD *)(result + 12) = 4096LL << v18;
      *(_QWORD *)result = v20 | v10;
      v10 = *(_QWORD *)(v10 + 8) - 8LL;
    }
LABEL_4:
    result = sg_next(result);
    if ( !result )
      return result;
  }
  if ( (*(_QWORD *)v9 & 0x40) != 0 )
    v17 = *(_BYTE *)(v9 + 64);
  else
    v17 = 0;
  if ( (v9 & 3) == 0 )
  {
LABEL_31:
    v19 = *(_QWORD *)result & 3LL;
    *(_DWORD *)(result + 8) = 0;
    *(_DWORD *)(result + 12) = 4096LL << v17;
    *(_QWORD *)result = v19 | v9;
    if ( (*(_QWORD *)v9 & 0x40) != 0 )
    {
      v11 = *(_BYTE *)(v9 + 64);
      v12 = result;
    }
    else
    {
      v12 = result;
      v11 = 0;
    }
    v13 = *(_QWORD *)a4 & 3LL;
    *(_DWORD *)(a4 + 8) = 0;
    *(_DWORD *)(a4 + 12) = 4096LL << v11;
    *(_QWORD *)a4 = v13 | v9;
    v9 = *(_QWORD *)(v9 + 8) - 8LL;
    a4 = sg_next(a4);
    result = v12;
    goto LABEL_4;
  }
  __break(0x800u);
LABEL_37:
  __break(0x800u);
LABEL_38:
  __break(0x800u);
LABEL_39:
  __break(0x800u);
  return get_secure_vmid(result);
}
