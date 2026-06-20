__int64 __fastcall msm_cvp_set_sysprop_pwr_op(__int64 a1, int *a2)
{
  int v2; // w9
  unsigned int v3; // w8
  unsigned int v4; // w9
  __int64 v5; // x10

  v2 = *a2;
  v3 = -14;
  if ( *a2 > 28 )
  {
    if ( v2 > 40 )
    {
      switch ( v2 )
      {
        case ')':
          v4 = a2[1];
          v5 = 14920;
          goto LABEL_28;
        case ',':
          v4 = a2[1];
          v5 = 14924;
          goto LABEL_28;
        case '/':
          v4 = a2[1];
          v5 = 14928;
          goto LABEL_28;
      }
    }
    else
    {
      switch ( v2 )
      {
        case 29:
          v4 = a2[1];
          v5 = 14948;
          goto LABEL_28;
        case 35:
          v4 = a2[1];
          v5 = 14912;
          goto LABEL_28;
        case 38:
          v4 = a2[1];
          v5 = 14916;
          goto LABEL_28;
      }
    }
  }
  else if ( v2 > 25 )
  {
    switch ( v2 )
    {
      case 26:
        v4 = a2[1];
        v5 = 14900;
        goto LABEL_28;
      case 27:
        v5 = 14932;
        v4 = 2 * a2[1] / 3u;
        goto LABEL_28;
      case 28:
        v4 = a2[1];
        v5 = 14940;
        goto LABEL_28;
    }
  }
  else
  {
    switch ( v2 )
    {
      case 23:
        v4 = a2[1];
        v5 = 14896;
        goto LABEL_28;
      case 24:
        v5 = 14908;
        v4 = 2 * a2[1] / 3u;
        goto LABEL_28;
      case 25:
        v4 = a2[1];
        v5 = 14904;
LABEL_28:
        v3 = 0;
        *(_DWORD *)(a1 + v5) = v4;
        break;
    }
  }
  return v3;
}
