__int64 __fastcall rmnet_offload_engine_add_flow_pkt(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x11
  __int64 v6; // x10
  __int16 v7; // w8
  _QWORD *v8; // x8
  __int64 v9; // x2
  _QWORD *v10; // x9
  __int16 v11; // w9
  __int64 v12; // x10
  __int64 v13; // x11

  if ( *(_BYTE *)(a2 + 66) == 1 )
  {
    v3 = *(_QWORD *)(a2 + 16);
    v2 = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(result + 32) = *(_QWORD *)(a2 + 8);
    *(_QWORD *)(result + 40) = v3;
    *(_QWORD *)(result + 48) = v2;
    v5 = *(_QWORD *)(a2 + 40);
    v4 = *(_QWORD *)(a2 + 48);
    v6 = *(_QWORD *)(a2 + 32);
    *(_DWORD *)(result + 80) = *(_DWORD *)(a2 + 56);
    *(_QWORD *)(result + 64) = v5;
    *(_QWORD *)(result + 72) = v4;
    *(_QWORD *)(result + 56) = v6;
    *(_DWORD *)(result + 84) = *(_DWORD *)(a2 + 60);
    v7 = *(_WORD *)(*(_QWORD *)a2 + 70LL);
    if ( !v7 )
      v7 = *(_WORD *)(a2 + 64);
    *(_WORD *)(result + 96) = v7;
  }
  if ( *(_BYTE *)(a2 + 57) == 6 )
    *(_DWORD *)(result + 72) += *(unsigned __int16 *)(a2 + 64);
  v8 = *(_QWORD **)a2;
  v9 = result + 16;
  v10 = *(_QWORD **)(result + 24);
  if ( *(_QWORD *)a2 == result + 16 || v10 == v8 || *v10 != v9 )
  {
    _list_add_valid_or_report(v8, v10, v9);
    result = v12;
    a2 = v13;
  }
  else
  {
    *(_QWORD *)(result + 24) = v8;
    *v8 = v9;
    v8[1] = v10;
    *v10 = v8;
  }
  v11 = *(_WORD *)(result + 88);
  ++*(_BYTE *)(result + 98);
  *(_WORD *)(result + 88) = v11 + *(_WORD *)(a2 + 64);
  return result;
}
