__int64 __fastcall qrtr_peek_pkt_size(
        unsigned __int8 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v8; // w29
  __int64 v9; // x1
  __int64 v10; // x9
  int v11; // w8

  v9 = *a1;
  if ( (_DWORD)v9 == 1 )
  {
    v11 = 32;
    v10 = 20;
    return ((*(_DWORD *)&a1[v10] + 3) & 0xFFFFFFFC) + v11;
  }
  if ( (_DWORD)v9 == 3 )
  {
    v10 = 4;
    v11 = a1[3] + 16;
    return ((*(_DWORD *)&a1[v10] + 3) & 0xFFFFFFFC) + v11;
  }
  printk(&unk_DD6F, v9, a3, a4, a5, a6, a7, a8, v8);
  return 4294967274LL;
}
