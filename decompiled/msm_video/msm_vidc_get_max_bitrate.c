__int64 __fastcall msm_vidc_get_max_bitrate(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w10
  unsigned int v4; // w9
  int v5; // w9
  __int64 v6; // x9
  unsigned int v7; // w9
  unsigned int v8; // w8

  result = 0x7FFFFFFF;
  if ( *(_QWORD *)(a1 + 15608) )
  {
    v3 = *(_DWORD *)(a1 + 35584);
    if ( v3 >= 0x7FFFFFFF )
      result = 0x7FFFFFFF;
    else
      result = v3;
  }
  if ( *(_QWORD *)(a1 + 16112) )
  {
    v4 = *(_DWORD *)(a1 + 35416);
    if ( (unsigned int)result >= v4 )
      result = v4;
    else
      result = (unsigned int)result;
  }
  v5 = *(_DWORD *)(a1 + 312);
  switch ( v5 )
  {
    case 64:
      v6 = 15424;
      break;
    case 2:
      v6 = 35080;
      break;
    case 1:
      v6 = 35080;
      if ( !*(_QWORD *)(a1 + 11240) )
        v6 = 35248;
      break;
    default:
      goto LABEL_20;
  }
  v7 = *(_DWORD *)(a1 + v6);
  if ( (unsigned int)result >= v7 )
    result = v7;
  else
    result = (unsigned int)result;
LABEL_20:
  if ( (_DWORD)result == 0x7FFFFFFF || !(_DWORD)result )
  {
    v8 = *(_DWORD *)(a1 + 15424);
    if ( (unsigned int)result >= v8 )
      return v8;
    else
      return (unsigned int)result;
  }
  return result;
}
