__int64 __fastcall policy_mgr_get_mac_freq_list(
        __int64 result,
        unsigned __int8 a2,
        unsigned int *a3,
        _BYTE *a4,
        _BYTE *a5,
        unsigned int a6,
        char a7,
        unsigned int a8,
        char a9,
        unsigned int a10,
        char a11,
        unsigned int a12,
        char a13)
{
  unsigned int *v13; // x8
  unsigned int v14; // w8
  unsigned int v15; // w10
  unsigned int *v16; // x11
  unsigned int *v17; // x11
  unsigned int *v18; // x9

  if ( a6 && ((v13 = (unsigned int *)(result + 16LL * a2), *v13 <= a6) && v13[1] >= a6 || v13[2] <= a6 && v13[3] >= a6) )
  {
    v14 = 1;
    *a3 = a6;
    *a4 = a7;
    v15 = a12;
    if ( !a8 )
      goto LABEL_14;
  }
  else
  {
    v14 = 0;
    v15 = a12;
    if ( !a8 )
      goto LABEL_14;
  }
  v16 = (unsigned int *)(result + 16LL * a2);
  if ( *v16 <= a8 && v16[1] >= a8 || v16[2] <= a8 && v16[3] >= a8 )
  {
    a3[v14] = a8;
    a4[v14++] = a9;
  }
LABEL_14:
  if ( a10 )
  {
    if ( (v17 = (unsigned int *)(result + 16LL * a2), *v17 <= a10) && v17[1] >= a10 || v17[2] <= a10 && v17[3] >= a10 )
    {
      a3[v14] = a10;
      a4[v14++] = a11;
    }
  }
  if ( v15 )
  {
    if ( (v18 = (unsigned int *)(result + 16LL * a2), *v18 <= v15) && v18[1] >= v15 || v18[2] <= v15 && v18[3] >= v15 )
    {
      a3[v14] = v15;
      a4[v14] = a13;
      LOBYTE(v14) = v14 + 1;
    }
  }
  *a5 = v14;
  return result;
}
