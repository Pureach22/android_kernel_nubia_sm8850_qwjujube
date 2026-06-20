__int64 __fastcall perf_remove(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x22
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x4
  __int64 (__fastcall *v8)(__int64, __int64, __int64, __int64, __int64); // x8
  unsigned int v9; // w0
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x23
  __int64 (__fastcall *v13)(__int64, __int64, __int64, __int64, __int64); // x8
  __int64 v14; // x1
  unsigned __int8 v15; // w24
  __int64 v16; // x0
  __int64 v17; // x22
  __int64 (__fastcall *v18)(__int64, __int64, __int64, __int64, __int64); // x8
  unsigned int v19; // w0
  __int64 v20; // x9
  void *v21; // x0
  __int64 result; // x0

  if ( *(_BYTE *)(a2 + 133) )
  {
    v4 = *(unsigned __int8 *)(a2 + 134);
    if ( v4 >= 0x65 )
    {
      v10 = *(_QWORD *)(a2 + 32);
      while ( 1 )
      {
        v11 = *(_QWORD *)(a2 + 88);
        if ( (unsigned __int8)v4 >= 0x64u )
          v12 = 100;
        else
          v12 = (unsigned __int8)v4;
        v13 = **(__int64 (__fastcall ***)(__int64, __int64, __int64, __int64, __int64))(a2 + 96);
        if ( *((_DWORD *)v13 - 1) != 1737159351 )
          __break(0x8228u);
        v9 = v13(v11, v10, 0x534C432D50455246LL, 4, v12);
        if ( v9 )
          goto LABEL_6;
        LOBYTE(v4) = v4 - v12;
        v10 = *(_QWORD *)(a2 + 32) + v12;
        *(_QWORD *)(a2 + 32) = v10;
        if ( !(_BYTE)v4 )
          goto LABEL_15;
      }
    }
    v5 = *(_QWORD *)(a2 + 88);
    v6 = *(_QWORD *)(a2 + 24);
    v7 = *(unsigned __int8 *)(a2 + 134);
    v8 = **(__int64 (__fastcall ***)(__int64, __int64, __int64, __int64, __int64))(a2 + 96);
    if ( *((_DWORD *)v8 - 1) != 1737159351 )
      __break(0x8228u);
    v9 = v8(v5, v6, 0x534C432D50455246LL, 4, v7);
    if ( v9 )
    {
LABEL_6:
      dev_err(a1, "Send SCMI: attr %d err: %d, %s\n", 4, v9, "remove and try again.");
      return 4294967274LL;
    }
  }
LABEL_15:
  if ( *(_BYTE *)(a2 + 128) == 1 )
  {
    v14 = *(_QWORD *)(a2 + 8);
    v15 = *(_BYTE *)(a2 + 130);
    *(_QWORD *)(a2 + 16) = v14;
    while ( 1 )
    {
      v16 = *(_QWORD *)(a2 + 88);
      v17 = v15 >= 0x64u ? 100LL : v15;
      v18 = **(__int64 (__fastcall ***)(__int64, __int64, __int64, __int64, __int64))(a2 + 96);
      if ( *((_DWORD *)v18 - 1) != 1737159351 )
        __break(0x8228u);
      v19 = v18(v16, v14, 0x534C432D50455246LL, 5, v17);
      if ( v19 )
        break;
      v15 -= v17;
      v14 = *(_QWORD *)(a2 + 16) + v17;
      *(_QWORD *)(a2 + 16) = v14;
      if ( !v15 )
        goto LABEL_24;
    }
    dev_err(a1, "Send SCMI: attr %d err: %d, %s\n", 5, v19, "remove and try again.");
    return 4294967274LL;
  }
LABEL_24:
  cntr_payload_cleanup(a2);
  memset(*(void **)(a2 + 8), 0, *(unsigned int *)(a2 + 44));
  v20 = *(_QWORD *)(a2 + 112);
  v21 = *(void **)(a2 + 64);
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(a2 + 8);
  memset(v21, 0, 2LL * *(unsigned __int8 *)(v20 + 4));
  result = 0;
  *(_WORD *)(a2 + 128) = 0;
  *(_BYTE *)(a2 + 130) = 0;
  return result;
}
