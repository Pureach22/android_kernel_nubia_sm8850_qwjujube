__int64 __fastcall coresight_timeout(__int64 a1, unsigned int a2, char a3, int a4)
{
  __int64 v6; // x22
  __int64 v8; // x23
  int v9; // w24
  _DWORD *v10; // x8
  int v11; // w0

  v6 = 1LL << a3;
  v8 = a2;
  v9 = 101;
  while ( 1 )
  {
    v10 = *(_DWORD **)(a1 + 8);
    if ( *(_BYTE *)a1 == 1 )
    {
      v11 = readl((char *)v10 + v8);
    }
    else
    {
      if ( *(v10 - 1) != -340433967 )
        __break(0x8228u);
      v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))v10)(a2, 0, 0);
    }
    if ( !a4 )
      break;
    if ( ((unsigned int)v6 & v11) != 0 )
      return 0;
LABEL_8:
    if ( v9 != 2 )
    {
      _const_udelay(4295);
      if ( --v9 )
        continue;
    }
    return 4294967285LL;
  }
  if ( ((unsigned int)v6 & v11) != 0 )
    goto LABEL_8;
  return 0;
}
