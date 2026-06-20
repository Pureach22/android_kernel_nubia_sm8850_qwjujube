unsigned __int64 __fastcall qpace_queue_compress(signed int a1, __int64 a2, __int64 a3)
{
  char v3; // w20
  __int64 *v6; // x22
  __int64 v7; // x8
  int v8; // w9
  __int64 v9; // x10
  __int64 v10; // x8
  unsigned __int64 result; // x0
  __int64 v12; // x8

  v3 = a1;
  v6 = (__int64 *)(tr_rings + 32LL * a1);
  get_ring(a1);
  v7 = v6[2];
  v8 = *(_DWORD *)(v7 + 28);
  v9 = *(_QWORD *)(v7 + 16);
  *(_QWORD *)v7 = a3;
  *(_QWORD *)(v7 + 8) = a2;
  *(_QWORD *)(v7 + 16) = v9 & 0xFFFFFFFFFFF00000LL | 0xFFF;
  *(_DWORD *)(v7 + 28) = v8 & 0xFC1FFF8F | ((v3 & 0xF) << 22) | 0x200010;
  v10 = v6[2];
  result = (unsigned __int64)(v10 - *v6) >> 5;
  if ( v10 == *v6 + 4064 )
    v12 = *v6;
  else
    v12 = v10 + 32;
  v6[2] = v12;
  return result;
}
