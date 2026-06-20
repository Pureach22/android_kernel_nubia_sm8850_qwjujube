__int64 __fastcall ieee80211_chandef_to_operating_class(_DWORD *a1, char *a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w9
  __int64 result; // x0
  int v5; // w9
  char v6; // w9

  v2 = a1[3];
  if ( v2 - 2412 <= 0x3C )
  {
    v3 = a1[2];
    if ( v3 > 2 )
      return 0;
    if ( v3 == 2 )
    {
      if ( v2 > *(_DWORD *)(*(_QWORD *)a1 + 4LL) )
        v6 = 83;
      else
        v6 = 84;
    }
    else
    {
      v6 = 81;
    }
    goto LABEL_56;
  }
  v5 = a1[2];
  if ( v2 == 2484 )
  {
    if ( v5 )
      return 0;
    v6 = 82;
    goto LABEL_56;
  }
  if ( v5 > 5 )
  {
    if ( (unsigned int)(v5 - 6) < 2 )
      return 0;
  }
  else
  {
    switch ( v5 )
    {
      case 3:
        v6 = 0x80;
        goto LABEL_22;
      case 4:
        v6 = -126;
        goto LABEL_22;
      case 5:
        v6 = -127;
LABEL_22:
        if ( v2 - 5180 >= 0x3D && v2 - 5260 >= 0x3D && v2 - 5500 >= 0xDD && v2 - 5745 >= 0x65 )
          return 0;
        goto LABEL_56;
    }
  }
  if ( v2 - 5180 <= 0x3C )
  {
    if ( v5 == 2 )
    {
      if ( v2 > *(_DWORD *)(*(_QWORD *)a1 + 4LL) )
        v6 = 116;
      else
        v6 = 117;
    }
    else
    {
      v6 = 115;
    }
    goto LABEL_56;
  }
  if ( v2 - 5260 <= 0x3C )
  {
    if ( v5 == 2 )
    {
      if ( v2 > *(_DWORD *)(*(_QWORD *)a1 + 4LL) )
        v6 = 119;
      else
        v6 = 120;
    }
    else
    {
      v6 = 118;
    }
    goto LABEL_56;
  }
  if ( v2 - 5500 <= 0xDC )
  {
    if ( v5 == 2 )
    {
      if ( v2 > *(_DWORD *)(*(_QWORD *)a1 + 4LL) )
        v6 = 122;
      else
        v6 = 123;
    }
    else
    {
      v6 = 121;
    }
    goto LABEL_56;
  }
  if ( v2 - 5745 <= 0x64 )
  {
    if ( v5 == 2 )
    {
      if ( v2 > *(_DWORD *)(*(_QWORD *)a1 + 4LL) )
        v6 = 126;
      else
        v6 = 127;
    }
    else if ( v2 >> 1 < 0xB57 )
    {
      v6 = 124;
    }
    else
    {
      v6 = 125;
    }
    goto LABEL_56;
  }
  result = 0;
  if ( v2 - 69121 >= 0xFFFFD5CF && (unsigned int)v5 <= 1 )
  {
    v6 = -76;
LABEL_56:
    *a2 = v6;
    return 1;
  }
  return result;
}
