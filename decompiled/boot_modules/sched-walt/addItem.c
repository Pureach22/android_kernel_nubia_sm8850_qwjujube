__int64 __fastcall addItem(__int64 result, _QWORD *a2)
{
  int v2; // w9
  int v3; // w8
  __int64 v4; // x12
  __int64 v5; // x13
  _QWORD *v6; // x9
  __int64 v7; // x10
  __int64 v8; // x10
  __int64 v9; // x12
  __int64 v10; // x13
  __int64 v11; // x10
  __int64 v12; // x11

  if ( !result )
    return printk(&unk_61D9B);
  v2 = *(_DWORD *)(result + 24);
  v3 = (*(_DWORD *)(result + 32) + 1) % v2;
  if ( v3 == *(_DWORD *)(result + 28) )
    *(_DWORD *)(result + 28) = (v3 + 1) % v2;
  v5 = a2[3];
  v4 = a2[4];
  v6 = (_QWORD *)(*(_QWORD *)(result + 8) + 88LL * *(int *)(result + 32));
  v7 = a2[6];
  v6[5] = a2[5];
  v6[6] = v7;
  v6[3] = v5;
  v6[4] = v4;
  v8 = a2[10];
  v10 = a2[7];
  v9 = a2[8];
  v6[9] = a2[9];
  v6[10] = v8;
  v6[7] = v10;
  v6[8] = v9;
  v12 = a2[1];
  v11 = a2[2];
  *v6 = *a2;
  v6[1] = v12;
  v6[2] = v11;
  *(_DWORD *)(result + 32) = v3;
  return result;
}
