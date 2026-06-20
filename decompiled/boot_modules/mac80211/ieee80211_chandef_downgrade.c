__int64 __fastcall ieee80211_chandef_downgrade(__int64 *a1, __int64 a2)
{
  int v4; // w8
  unsigned int v5; // w21
  int v6; // w8
  __int64 v7; // x8
  int v8; // w0
  __int64 result; // x0

  do
  {
    v4 = *((_DWORD *)a1 + 2);
    if ( v4 > 7 )
    {
      if ( (unsigned int)(v4 - 8) >= 5 )
      {
        if ( v4 != 13 )
          goto LABEL_27;
        v5 = 5;
        if ( a2 )
        {
          v6 = 3;
          goto LABEL_22;
        }
LABEL_34:
        v8 = cfg80211_chandef_primary(a1, v5, (char *)a1 + 30);
        *((_DWORD *)a1 + 2) = v5;
        *((_DWORD *)a1 + 3) = v8;
        continue;
      }
      __break(0x800u);
      if ( a2 )
        *(_QWORD *)a2 = 0;
    }
    else
    {
      if ( v4 <= 3 )
      {
        switch ( v4 )
        {
          case 1:
            goto LABEL_28;
          case 2:
            v7 = *a1;
            *((_DWORD *)a1 + 2) = 1;
            *((_DWORD *)a1 + 3) = *(_DWORD *)(v7 + 4);
            if ( a2 )
            {
              if ( *(_DWORD *)a2 == 3 )
                *(_DWORD *)a2 = 2;
              *(_DWORD *)(a2 + 4) = 0;
            }
            goto LABEL_30;
          case 3:
            if ( !a2 )
            {
              v5 = 2;
              goto LABEL_34;
            }
            v5 = 2;
            if ( *(_DWORD *)a2 == 3 )
              *(_DWORD *)a2 = 2;
            v6 = 1;
            goto LABEL_22;
        }
LABEL_27:
        __break(0x800u);
LABEL_28:
        *((_DWORD *)a1 + 2) = 0;
        if ( a2 )
          *(_QWORD *)a2 = 1;
LABEL_30:
        *((_WORD *)a1 + 15) = 0;
        continue;
      }
      if ( (unsigned int)(v4 - 6) < 2 )
      {
        __break(0x800u);
        if ( a2 )
          *(_QWORD *)a2 = 1;
      }
      else
      {
        if ( v4 != 4 )
        {
          v5 = 3;
          if ( a2 )
          {
            v6 = 2;
LABEL_22:
            *(_DWORD *)(a2 + 4) = v6;
            goto LABEL_34;
          }
          goto LABEL_34;
        }
        *((_DWORD *)a1 + 4) = 0;
        *((_DWORD *)a1 + 2) = 3;
        if ( a2 )
          *(_DWORD *)(a2 + 4) = 2;
      }
    }
  }
  while ( (cfg80211_chandef_valid(a1) & 1) == 0 && *((_WORD *)a1 + 15) );
  result = cfg80211_chandef_valid(a1);
  if ( (result & 1) == 0 )
    __break(0x800u);
  return result;
}
