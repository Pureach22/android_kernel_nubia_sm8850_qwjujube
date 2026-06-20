__int64 *__fastcall ieee80211_get_channel_khz(_QWORD *a1, int a2)
{
  __int64 **v2; // x8
  __int64 v3; // x9
  __int64 *i; // x8
  __int64 **v5; // x8
  __int64 v6; // x9
  __int64 **v7; // x8
  __int64 v8; // x9
  __int64 **v9; // x8
  __int64 v10; // x9
  __int64 **v11; // x8
  __int64 v12; // x9
  __int64 v13; // x9

  v2 = (__int64 **)a1[41];
  if ( v2 && (v3 = *((unsigned int *)v2 + 5), (int)v3 >= 1) )
  {
    i = *v2;
    while ( *((unsigned __int16 *)i + 4) + 1000 * *((_DWORD *)i + 1) != a2 )
    {
      --v3;
      i += 8;
      if ( !v3 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v5 = (__int64 **)a1[42];
    if ( v5 && (v6 = *((unsigned int *)v5 + 5), (int)v6 >= 1) )
    {
      i = *v5;
      while ( *((unsigned __int16 *)i + 4) + 1000 * *((_DWORD *)i + 1) != a2 )
      {
        --v6;
        i += 8;
        if ( !v6 )
          goto LABEL_11;
      }
    }
    else
    {
LABEL_11:
      v7 = (__int64 **)a1[43];
      if ( v7 && (v8 = *((unsigned int *)v7 + 5), (int)v8 >= 1) )
      {
        i = *v7;
        while ( *((unsigned __int16 *)i + 4) + 1000 * *((_DWORD *)i + 1) != a2 )
        {
          --v8;
          i += 8;
          if ( !v8 )
            goto LABEL_16;
        }
      }
      else
      {
LABEL_16:
        v9 = (__int64 **)a1[44];
        if ( v9 && (v10 = *((unsigned int *)v9 + 5), (int)v10 >= 1) )
        {
          i = *v9;
          while ( *((unsigned __int16 *)i + 4) + 1000 * *((_DWORD *)i + 1) != a2 )
          {
            --v10;
            i += 8;
            if ( !v10 )
              goto LABEL_21;
          }
        }
        else
        {
LABEL_21:
          v11 = (__int64 **)a1[45];
          if ( v11 && (v12 = *((unsigned int *)v11 + 5), (int)v12 >= 1) )
          {
            i = *v11;
            while ( *((unsigned __int16 *)i + 4) + 1000 * *((_DWORD *)i + 1) != a2 )
            {
              --v12;
              i += 8;
              if ( !v12 )
                goto LABEL_26;
            }
          }
          else
          {
LABEL_26:
            i = (__int64 *)a1[46];
            if ( i )
            {
              v13 = *((unsigned int *)i + 5);
              if ( (int)v13 < 1 )
              {
                return nullptr;
              }
              else
              {
                for ( i = (__int64 *)*i; *((unsigned __int16 *)i + 4) + 1000 * *((_DWORD *)i + 1) != a2; i += 8 )
                {
                  if ( !--v13 )
                    return nullptr;
                }
              }
            }
          }
        }
      }
    }
  }
  return i;
}
