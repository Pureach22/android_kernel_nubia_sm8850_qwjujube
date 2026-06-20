__int64 __fastcall dp_accumulate_hist_stats(__int64 result, __int64 a2)
{
  __int64 v2; // x10
  __int64 v3; // x12
  __int64 v4; // x13
  __int64 v5; // x16
  __int64 v6; // x17
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x12
  __int64 v17; // x14
  __int64 v18; // x15
  __int64 v19; // x13
  __int64 v20; // x14
  __int64 v21; // x15
  __int64 v22; // x16
  __int64 v23; // x17
  __int64 v24; // x2
  __int64 v25; // x4
  __int64 v26; // x3
  int v27; // w10
  int v28; // w8
  int v29; // w9
  int v30; // w8

  v2 = *(_QWORD *)(a2 + 16);
  v3 = *(_QWORD *)(a2 + 40);
  v4 = *(_QWORD *)(a2 + 48);
  v5 = *(_QWORD *)(a2 + 72);
  v6 = *(_QWORD *)(a2 + 80);
  v7 = *(_QWORD *)(a2 + 88);
  v8 = *(_QWORD *)(a2 + 96);
  *(_QWORD *)(a2 + 8) += *(_QWORD *)(result + 8);
  v9 = *(_QWORD *)(result + 8);
  v10 = v2 + *(_QWORD *)(result + 16);
  v11 = *(_QWORD *)(a2 + 24);
  v12 = *(_QWORD *)(a2 + 32);
  *(_QWORD *)(a2 + 16) = v10;
  v13 = *(_QWORD *)(result + 16);
  *(_QWORD *)(a2 + 24) = v11 + *(_QWORD *)(result + 24);
  v14 = *(_QWORD *)(result + 24);
  *(_QWORD *)(a2 + 32) = v12 + *(_QWORD *)(result + 32);
  v15 = *(_QWORD *)(result + 32);
  *(_QWORD *)(a2 + 40) = v3 + *(_QWORD *)(result + 40);
  v16 = *(_QWORD *)(result + 40);
  v17 = *(_QWORD *)(a2 + 56);
  v18 = *(_QWORD *)(a2 + 64);
  *(_QWORD *)(a2 + 48) = v4 + *(_QWORD *)(result + 48);
  v19 = *(_QWORD *)(result + 48);
  *(_QWORD *)(a2 + 56) = v17 + *(_QWORD *)(result + 56);
  v20 = *(_QWORD *)(result + 56);
  *(_QWORD *)(a2 + 64) = v18 + *(_QWORD *)(result + 64);
  v21 = *(_QWORD *)(result + 64);
  *(_QWORD *)(a2 + 72) = v5 + *(_QWORD *)(result + 72);
  v22 = *(_QWORD *)(result + 72);
  *(_QWORD *)(a2 + 80) = v6 + *(_QWORD *)(result + 80);
  v23 = *(_QWORD *)(result + 80);
  *(_QWORD *)(a2 + 88) = v7 + *(_QWORD *)(result + 88);
  v24 = *(_QWORD *)(result + 88);
  v25 = *(_QWORD *)(a2 + 104);
  *(_QWORD *)(a2 + 96) = v8 + *(_QWORD *)(result + 96);
  v26 = *(_QWORD *)(result + 96);
  *(_QWORD *)(a2 + 104) = v25 + *(_QWORD *)(result + 104);
  if ( *(_QWORD *)(result + 104) || v26 || v24 || v23 || v22 || v21 || v20 || v19 || v16 || v15 || v14 || v13 || v9 )
  {
    v27 = *(_DWORD *)(a2 + 112);
    v28 = *(_DWORD *)(result + 116);
    if ( v28 >= *(_DWORD *)(a2 + 116) )
      v28 = *(_DWORD *)(a2 + 116);
    v29 = *(_DWORD *)(a2 + 120);
    *(_DWORD *)(a2 + 116) = v28;
    v30 = *(_DWORD *)(result + 112);
    if ( v30 <= v27 )
      v30 = v27;
    *(_DWORD *)(a2 + 112) = v30;
    *(_DWORD *)(a2 + 120) = (v29 + *(_DWORD *)(result + 120)) >> 1;
  }
  return result;
}
