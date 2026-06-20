__int64 __fastcall hdd_map_req_id_to_pattern_id(_DWORD *a1, int a2, _BYTE *a3)
{
  _DWORD *v4; // x22
  int v7; // w8
  __int64 v8; // x8
  __int64 v9; // x8
  int v10; // w8
  int v11; // w8
  int v12; // w8
  int v13; // w8
  int v14; // w8
  _BYTE *v15; // x8
  _DWORD *v16; // x8
  unsigned int v17; // w21

  v4 = a1 + 314;
  mutex_lock(a1 + 326);
  v7 = a1[314];
  if ( v7 == -1 )
  {
    v9 = 0;
    goto LABEL_26;
  }
  if ( v7 != a2 )
  {
    v10 = a1[316];
    if ( v10 == -1 )
    {
      v9 = 1;
    }
    else
    {
      if ( v10 == a2 )
      {
        v8 = 1;
        goto LABEL_24;
      }
      v11 = a1[318];
      if ( v11 == -1 )
      {
        v9 = 2;
      }
      else
      {
        if ( v11 == a2 )
        {
          v8 = 2;
          goto LABEL_24;
        }
        v12 = a1[320];
        if ( v12 == -1 )
        {
          v9 = 3;
        }
        else
        {
          if ( v12 == a2 )
          {
            v8 = 3;
            goto LABEL_24;
          }
          v13 = a1[322];
          if ( v13 == -1 )
          {
            v9 = 4;
          }
          else
          {
            if ( v13 == a2 )
            {
              v8 = 4;
              goto LABEL_24;
            }
            v14 = a1[324];
            if ( v14 != -1 )
            {
              if ( v14 != a2 )
              {
                v17 = -105;
                goto LABEL_28;
              }
              v8 = 5;
              goto LABEL_24;
            }
            v9 = 5;
          }
        }
      }
    }
LABEL_26:
    v16 = &v4[2 * v9];
    *v16 = a2;
    v15 = v16 + 1;
    goto LABEL_27;
  }
  v8 = 0;
LABEL_24:
  v15 = &v4[2 * v8 + 1];
LABEL_27:
  v17 = 0;
  *a3 = *v15;
LABEL_28:
  mutex_unlock(a1 + 326);
  return v17;
}
