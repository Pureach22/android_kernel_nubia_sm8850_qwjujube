__int64 __fastcall dp_accumulate_delay_stats(__int64 result, __int64 *a2)
{
  __int64 v2; // x10
  __int64 v3; // x12
  __int64 v4; // x13
  __int64 v5; // x4
  __int64 v6; // x16
  __int64 v7; // x17
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x11
  __int64 v17; // x12
  __int64 v18; // x8
  __int64 v19; // x14
  __int64 v20; // x15
  __int64 v21; // x13
  __int64 v22; // x14
  __int64 v23; // x13
  __int64 v24; // x15
  __int64 v25; // x13
  __int64 v26; // x16
  __int64 v27; // x13
  __int64 v28; // x17
  __int64 v29; // x13
  __int64 v30; // x2
  __int64 v31; // x13
  __int64 v32; // x3
  __int64 v33; // x10
  __int64 v34; // x8
  unsigned int v35; // w11
  unsigned int v36; // w12
  __int64 v37; // x9
  unsigned int v38; // w10
  unsigned int v39; // w10
  unsigned int v40; // w11
  int v41; // w11
  unsigned int v42; // w10

  v2 = *(_QWORD *)(result + 8);
  v3 = *(_QWORD *)(result + 32);
  v4 = *(_QWORD *)(result + 40);
  v5 = *(_QWORD *)(result + 96);
  v6 = *(_QWORD *)(result + 64);
  v7 = *(_QWORD *)(result + 72);
  v8 = *(_QWORD *)(result + 80);
  v9 = *(_QWORD *)(result + 88);
  *(_QWORD *)result += *a2;
  v10 = *a2;
  v11 = v2 + a2[1];
  v12 = *(_QWORD *)(result + 16);
  v13 = *(_QWORD *)(result + 24);
  *(_QWORD *)(result + 8) = v11;
  v14 = a2[1];
  *(_QWORD *)(result + 16) = v12 + a2[2];
  v15 = a2[2];
  *(_QWORD *)(result + 24) = v13 + a2[3];
  v16 = a2[3];
  *(_QWORD *)(result + 32) = v3 + a2[4];
  v17 = a2[4];
  v18 = v16 + v15 + v14 + v10;
  v19 = *(_QWORD *)(result + 48);
  v20 = *(_QWORD *)(result + 56);
  *(_QWORD *)(result + 40) = v4 + a2[5];
  v21 = v19 + a2[6];
  v22 = a2[5];
  *(_QWORD *)(result + 48) = v21;
  v23 = v20 + a2[7];
  v24 = a2[6];
  *(_QWORD *)(result + 56) = v23;
  v25 = v6 + a2[8];
  v26 = a2[7];
  *(_QWORD *)(result + 64) = v25;
  v27 = v7 + a2[9];
  v28 = a2[8];
  *(_QWORD *)(result + 72) = v27;
  v29 = v8 + a2[10];
  v30 = a2[9];
  *(_QWORD *)(result + 80) = v29;
  v31 = v9 + a2[11];
  v32 = a2[10];
  *(_QWORD *)(result + 88) = v31;
  v33 = a2[11];
  *(_QWORD *)(result + 96) = v5 + a2[12];
  v34 = a2[12] + v33 + v32 + v30 + v28 + v26 + v24 + v22 + v17 + v18;
  if ( v34 )
  {
    v36 = *(_DWORD *)(result + 104);
    v35 = *(_DWORD *)(result + 108);
    v37 = *(_QWORD *)(result + 120) + v34;
    *(_QWORD *)(result + 120) = v37;
    v38 = *((_DWORD *)a2 + 27);
    if ( v35 > v38 )
      v38 = v35;
    *(_DWORD *)(result + 108) = v38;
    v39 = *((_DWORD *)a2 + 26);
    if ( v36 >= v39 )
      v40 = *((_DWORD *)a2 + 26);
    else
      v40 = v36;
    if ( v36 )
      v39 = v40;
    v41 = *(_DWORD *)(result + 112);
    *(_DWORD *)(result + 104) = v39;
    v42 = *((_DWORD *)a2 + 28);
    if ( v41 )
      v42 = ((unsigned __int8)(100 * v37 / (unsigned __int64)(v37 + v34)) * v41
           + (unsigned __int8)(100 * v34 / (unsigned __int64)(v37 + v34)) * v42)
          / 0x64;
    *(_DWORD *)(result + 112) = v42;
  }
  return result;
}
