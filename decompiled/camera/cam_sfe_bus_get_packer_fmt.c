__int64 __fastcall cam_sfe_bus_get_packer_fmt(__int64 a1, int a2, int a3)
{
  unsigned int v3; // w9
  int v4; // w10
  bool v5; // w8
  int *v6; // x13
  int v7; // w13
  __int64 result; // x0

  v3 = *(_DWORD *)(a1 + 27548);
  if ( v3 )
  {
    v4 = 0;
    v5 = 1;
    do
    {
      v6 = (int *)(*(_QWORD *)(a1 + 27608) + 56LL * v4);
      if ( v6[10] == a3 )
      {
        v7 = *v6;
        if ( v7 == 5 || v7 == 16 )
          break;
      }
      v5 = ++v4 < v3;
    }
    while ( v3 != v4 );
  }
  else
  {
    v5 = 0;
  }
  result = 0;
  switch ( a2 )
  {
    case 1:
    case 2:
    case 6:
    case 13:
    case 20:
    case 35:
      return result;
    case 3:
      if ( v5 )
        result = 12;
      else
        result = 0;
      break;
    case 4:
      if ( v5 )
        result = 13;
      else
        result = 0;
      break;
    case 5:
      if ( v5 )
        result = 14;
      else
        result = 0;
      break;
    case 7:
      if ( v5 )
        result = 15;
      else
        result = 0;
      break;
    case 12:
      result = 1;
      break;
    case 14:
      result = 5;
      break;
    case 15:
      result = 6;
      break;
    case 16:
      result = 7;
      break;
    case 17:
      result = 8;
      break;
    case 19:
    case 36:
    case 48:
      result = 10;
      break;
    case 21:
    case 47:
      result = 9;
      break;
    case 32:
    case 37:
    case 38:
    case 45:
      result = 3;
      break;
    case 33:
    case 39:
      result = 11;
      break;
    default:
      result = 17;
      break;
  }
  return result;
}
