unsigned __int64 __fastcall qpace_queue_copy(int a1, __int64 a2, __int64 a3, int a4)
{
  char v4; // w21
  __int64 *v8; // x23
  __int64 v9; // x8
  int v10; // w9
  __int64 v11; // x10
  __int64 v12; // x8
  unsigned __int64 result; // x0
  __int64 v14; // x8

  v4 = a1;
  v8 = (__int64 *)(tr_rings + 32LL * a1);
  get_ring();
  v9 = v8[2];
  v10 = *(_DWORD *)(v9 + 28);
  v11 = *(_QWORD *)(v9 + 16);
  *(_QWORD *)v9 = a3;
  *(_QWORD *)(v9 + 8) = a2;
  *(_QWORD *)(v9 + 16) = v11 & 0xFFFFFFFFFFF00000LL | *(_QWORD *)&a4 & 0xFFFFFLL;
  *(_DWORD *)(v9 + 28) = v10 & 0xFC2FFF8F | ((v4 & 0xF) << 22) | 0x100000;
  v12 = v8[2];
  result = (unsigned __int64)(v12 - *v8) >> 5;
  if ( v12 == *v8 + 4064 )
    v14 = *v8;
  else
    v14 = v12 + 32;
  v8[2] = v14;
  return result;
}
