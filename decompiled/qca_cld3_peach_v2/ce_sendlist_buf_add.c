__int64 __fastcall ce_sendlist_buf_add(_DWORD *a1, __int64 a2, int a3, int a4, int a5)
{
  __int64 v5; // x9
  _DWORD *v8; // x10

  v5 = (unsigned int)*a1;
  if ( (unsigned int)v5 > 0xB )
    return 1;
  v8 = &a1[8 * v5];
  *a1 = v5 + 1;
  v8[2] = 0;
  *((_QWORD *)v8 + 2) = a2;
  v8[6] = a3;
  v8[7] = a4;
  v8[8] = a5;
  return 0;
}
