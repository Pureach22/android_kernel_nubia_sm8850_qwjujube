__int64 __fastcall qcom_mdt_get_size(__int64 a1)
{
  __int64 v1; // x9
  __int64 v2; // x10
  unsigned __int64 v3; // x8
  _DWORD *v4; // x11
  unsigned __int64 v5; // x9
  int v6; // w13
  unsigned __int64 v7; // x14
  unsigned __int64 v8; // x13
  bool v9; // cc
  unsigned __int64 v10; // x8

  v1 = *(_QWORD *)(a1 + 8);
  v2 = *(unsigned __int16 *)(v1 + 44);
  if ( *(_WORD *)(v1 + 44) )
  {
    v3 = 0;
    v4 = (_DWORD *)(v1 + 76);
    v5 = -1;
    do
    {
      if ( *(v4 - 6) == 1 && (*v4 & 0x7000000) != 0x2000000 )
      {
        v6 = *(v4 - 1);
        if ( v6 )
        {
          v7 = (unsigned int)*(v4 - 3);
          v8 = (unsigned int)(v6 + v7);
          if ( v5 >= v7 )
            v5 = (unsigned int)*(v4 - 3);
          if ( v3 < v8 )
            v3 = ((_DWORD)v8 + 4095) & 0xFFFFF000;
        }
      }
      --v2;
      v4 += 8;
    }
    while ( v2 );
  }
  else
  {
    v3 = 0;
    v5 = -1;
  }
  v9 = v3 > v5;
  v10 = v3 - v5;
  if ( v9 )
    return v10;
  else
    return -22;
}
