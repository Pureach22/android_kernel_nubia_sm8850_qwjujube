__int64 __fastcall msm_cvp_set_sysprop_pwr_hw(__int64 a1, int *a2)
{
  int v2; // w9
  unsigned int v3; // w8
  unsigned int v4; // w9
  __int64 v5; // x10

  v2 = *a2;
  v3 = -14;
  if ( *a2 > 21 )
  {
    if ( v2 > 39 )
    {
      switch ( v2 )
      {
        case '(':
          v4 = a2[1];
          v5 = 14880;
          goto LABEL_28;
        case '+':
          v4 = a2[1];
          v5 = 14884;
          goto LABEL_28;
        case '.':
          v4 = a2[1];
          v5 = 14888;
          goto LABEL_28;
      }
    }
    else
    {
      switch ( v2 )
      {
        case 22:
          v4 = a2[1];
          v5 = 14944;
          goto LABEL_28;
        case 34:
          v4 = a2[1];
          v5 = 14872;
          goto LABEL_28;
        case 37:
          v4 = a2[1];
          v5 = 14876;
          goto LABEL_28;
      }
    }
  }
  else if ( v2 > 18 )
  {
    switch ( v2 )
    {
      case 19:
        v4 = a2[1];
        v5 = 14860;
        goto LABEL_28;
      case 20:
        v5 = 14892;
        v4 = 2 * a2[1] / 3u;
        goto LABEL_28;
      case 21:
        v4 = a2[1];
        v5 = 14936;
        goto LABEL_28;
    }
  }
  else
  {
    switch ( v2 )
    {
      case 16:
        v4 = a2[1];
        v5 = 14856;
        goto LABEL_28;
      case 17:
        v5 = 14868;
        v4 = 2 * a2[1] / 3u;
        goto LABEL_28;
      case 18:
        v4 = a2[1];
        v5 = 14864;
LABEL_28:
        v3 = 0;
        *(_DWORD *)(a1 + v5) = v4;
        break;
    }
  }
  return v3;
}
