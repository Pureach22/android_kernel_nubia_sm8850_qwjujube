__int64 __fastcall _qdf_nbuf_alloc_no_recycler(int a1, int a2, int a3)
{
  int v3; // w8
  __int64 result; // x0
  __int64 v7; // x8
  int v8; // w9
  unsigned __int64 v9; // x8
  int v10; // w9
  unsigned __int64 v11; // x10
  int v12; // w10

  v3 = a3 - 1;
  if ( !a3 )
    v3 = 0;
  result = _alloc_skb((unsigned int)(v3 + a1), 2080, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v7 = *(_QWORD *)(result + 224);
    v8 = *(_DWORD *)(result + 208);
    *(_QWORD *)(result + 72) = 0;
    *(_QWORD *)(result + 80) = 0;
    *(_QWORD *)(result + 56) = 0;
    *(_QWORD *)(result + 64) = 0;
    v9 = v7 + a2;
    v10 = v8 + a2;
    *(_QWORD *)(result + 40) = 0;
    *(_QWORD *)(result + 48) = 0;
    *(_DWORD *)(result + 208) = v10;
    *(_QWORD *)(result + 224) = v9;
    if ( a3 )
    {
      v11 = v9 % a3;
      if ( v11 )
      {
        v12 = a3 - v11;
        *(_DWORD *)(result + 208) = v12 + v10;
        *(_QWORD *)(result + 224) = v9 + v12;
      }
    }
  }
  return result;
}
