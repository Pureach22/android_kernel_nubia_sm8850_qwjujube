__int64 __fastcall populate_vm_list(int a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  int v4; // w10
  unsigned __int64 v5; // x14
  __int64 result; // x0
  int v7; // w16
  char v8; // w14
  __int64 v9; // x15
  __int64 v10; // x15
  bool v11; // zf
  int v12; // w15

  v3 = a1 & 0x7FFF8000;
  if ( (a1 & 0x7FFF8000) == 0 )
    return 4294967274LL;
  v4 = a3 - 1;
  v5 = a1 & 0x7FFF8000;
  result = 4294967274LL;
  while ( 1 )
  {
    v7 = 1;
    v8 = __clz(__rbit64(v5));
    v9 = 1LL << v8;
    if ( ((1LL << v8) & 0x10000) == 0 )
    {
      if ( (v9 & 0x20000) != 0 )
      {
        v7 = 8;
      }
      else if ( (v9 & 0x40000) != 0 )
      {
        v7 = 9;
      }
      else if ( (v9 & 0x80000) != 0 )
      {
        v7 = 10;
      }
      else if ( (v9 & 0x100000) != 0 )
      {
        v7 = 11;
      }
      else if ( (v9 & 0x200000) != 0 )
      {
        v7 = 13;
      }
      else if ( (v9 & 0x2000000) != 0 )
      {
        v7 = 17;
      }
      else if ( (v9 & 0x4000000) != 0 )
      {
        v7 = 18;
      }
      else if ( (v9 & 0x8000000) != 0 )
      {
        v7 = 29;
      }
      else if ( (v9 & 0x800000) != 0 )
      {
        v7 = 26;
      }
      else if ( (v9 & 0x1000000) != 0 )
      {
        v7 = 34;
      }
      else if ( (v9 & 0x40000000) != 0 )
      {
        v7 = 36;
      }
      else if ( (v9 & 0x20000000) != 0 )
      {
        v7 = 42;
      }
      else if ( (v9 & 0x10000000) != 0 )
      {
        v7 = 15;
      }
      else
      {
        v7 = -22;
      }
    }
    v10 = v9 & 0x400000;
    v11 = v7 > -1 || v10 == 0;
    v12 = v11 ? v7 : 3;
    if ( v4 == -1 || v12 < 0 )
      break;
    *(_DWORD *)(a2 + 4LL * v4--) = v12;
    v5 = (-2LL << v8) & v3;
    if ( !v5 )
      return 0;
  }
  return result;
}
