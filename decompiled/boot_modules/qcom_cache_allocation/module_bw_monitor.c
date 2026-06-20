__int64 __fastcall module_bw_monitor(__int64 result, __int64 a2, unsigned __int64 *a3, unsigned int a4)
{
  __int64 v4; // x11
  __int64 v5; // x8
  int v6; // w13
  unsigned int v7; // w12
  int v8; // w9
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x9
  __int64 v12; // x11
  __int64 *v13; // x10
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 *v16; // x10

  v4 = *(_QWORD *)(result + 240);
  v5 = 32LL * a4;
  v6 = *(_DWORD *)(a2 + 8);
  v7 = mpam_version;
  *(_QWORD *)(*(_QWORD *)(result + 248) + v5) = *(_QWORD *)(*(_QWORD *)(result + 248) + v5 + 16);
  v8 = 32;
  if ( v7 <= 0x10001 )
    v8 = 24;
  v9 = v4 + v8 * (__int64)v6;
  *(_QWORD *)(*(_QWORD *)(result + 248) + v5 + 8) = *(_QWORD *)(*(_QWORD *)(result + 248) + v5 + 24);
  v10 = 16;
  if ( v7 > 0x10001 )
    v10 = 24;
  *(_QWORD *)(*(_QWORD *)(result + 248) + v5 + 16) = *(_QWORD *)(v9 + v10);
  if ( v7 < 0x10002 )
    v11 = *(unsigned int *)(v9 + 12);
  else
    v11 = *(_QWORD *)(v9 + 16);
  *(_QWORD *)(*(_QWORD *)(result + 248) + 32LL * a4 + 24) = v11;
  v12 = *(_QWORD *)(result + 248);
  v13 = (__int64 *)(v12 + 32LL * a4);
  v14 = v13[2];
  v15 = *v13;
  if ( v14 == v15 )
  {
    *a3 = 0;
    v12 = *(_QWORD *)(result + 248);
    v16 = (__int64 *)(v12 + 32LL * a4);
    v14 = v16[2];
    v15 = *v16;
  }
  *a3 = 1831LL
      * (*(_QWORD *)(v12 + 32LL * a4 + 24) - *(_QWORD *)(v12 + 32LL * a4 + 8))
      / (unsigned __int64)(100 * (v14 - v15));
  return result;
}
