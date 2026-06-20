__int64 __fastcall qrtr_gunyah_fifo_init(__int64 result)
{
  _QWORD *v1; // x8
  _DWORD *v2; // x8
  __int64 v3; // x13
  _DWORD *v4; // x9
  _DWORD *v5; // x10
  _DWORD *v6; // x11
  __int64 v7; // x14
  _DWORD *v8; // x12
  __int64 v9; // x15
  __int64 v10; // x13

  if ( *(_BYTE *)(result + 176) == 1 )
  {
    v1 = *(_QWORD **)(result + 160);
    v1[3] = 0;
    v1[4] = 0;
    v1[1] = 0;
    v1[2] = 0;
    *v1 = 0;
  }
  v2 = *(_DWORD **)(result + 160);
  *v2 = 608784451;
  v3 = *(_QWORD *)(result + 160);
  if ( *(_BYTE *)(result + 176) == 1 )
  {
    v4 = v2 + 2;
    v5 = v2 + 5;
    *(_QWORD *)(result + 320) = v2 + 1;
    *(_QWORD *)(result + 328) = v2 + 2;
    v6 = v2 + 3;
    v7 = v3 + 4096;
    v8 = v2 + 4;
    v9 = v3 + 20480;
    v10 = 6;
  }
  else
  {
    v4 = v2 + 4;
    v5 = v2 + 6;
    *(_QWORD *)(result + 320) = v2 + 3;
    *(_QWORD *)(result + 328) = v2 + 4;
    v6 = v2 + 1;
    v7 = v3 + 20480;
    v8 = v2 + 2;
    v9 = v3 + 4096;
    v10 = 5;
  }
  *(_QWORD *)(result + 336) = v5;
  *(_QWORD *)(result + 344) = v7;
  *(_QWORD *)(result + 352) = 0x4000;
  *(_QWORD *)(result + 360) = v6;
  *(_QWORD *)(result + 384) = v9;
  *(_QWORD *)(result + 392) = 0x4000;
  *(_QWORD *)(result + 368) = v8;
  *(_QWORD *)(result + 376) = &v2[v10];
  *v4 = 0;
  **(_DWORD **)(result + 336) = 0;
  **(_DWORD **)(result + 360) = 0;
  return result;
}
