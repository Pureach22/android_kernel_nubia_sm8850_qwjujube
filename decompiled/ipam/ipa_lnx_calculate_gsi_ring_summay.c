__int64 __fastcall ipa_lnx_calculate_gsi_ring_summay(__int64 result, _DWORD *a2, unsigned int a3)
{
  unsigned int *v3; // x8
  unsigned int v4; // w13
  unsigned int v5; // w11
  unsigned int v6; // w12
  unsigned int v7; // w9
  unsigned int v8; // w10
  unsigned int v9; // w14
  unsigned int v10; // w17
  unsigned int v11; // w15
  unsigned int v12; // w16
  int v13; // w14
  unsigned int v14; // w11
  int v15; // w14
  unsigned int v16; // w15
  unsigned int v17; // w9
  int v18; // w14
  unsigned int v19; // w10
  unsigned int v20; // w14
  int v21; // w15
  unsigned int *v22; // x8
  unsigned int v23; // w14
  unsigned int v24; // w9
  unsigned int v25; // w10
  unsigned int v26; // w12
  unsigned int v27; // w13
  unsigned int v28; // w11
  unsigned int v29; // w15
  unsigned int v30; // w17
  int v31; // w11
  int v32; // w15
  unsigned int v33; // w9
  unsigned int v34; // w11
  unsigned int v35; // w10
  int v36; // w15
  unsigned int v37; // w12
  unsigned int v38; // w13
  int v39; // w11

  if ( (int)a3 > 133 )
  {
    if ( !a2 )
      return result;
    goto LABEL_41;
  }
  if ( result && (a3 & 1) != 0 )
  {
    if ( a3 < 0x86 )
    {
      v3 = (unsigned int *)((char *)&poll_pack_and_cred_info + 20 * a3);
      v4 = *(_DWORD *)(result + 20);
      v5 = *(_DWORD *)(result + 4);
      v6 = *(_DWORD *)(result + 8);
      v7 = *(_DWORD *)(result + 12);
      v8 = *(_DWORD *)(result + 16);
      v9 = *v3;
      v10 = v3[1];
      v11 = v3[2];
      v12 = v3[3];
      *v3 = v5;
      if ( v5 < v9 )
        v13 = ~v9;
      else
        v13 = -v9;
      v14 = v13 + v5;
      if ( v7 < v11 )
        v15 = ~v11;
      else
        v15 = -v11;
      v16 = v3[4];
      v17 = v15 + v7;
      v18 = -v12;
      if ( v8 < v12 )
        v18 = ~v12;
      v19 = v18 + v8;
      if ( v6 >= v10 )
        v20 = v10;
      else
        v20 = v10 + 1;
      if ( v4 < v16 )
        v21 = ~v16;
      else
        v21 = -v16;
      v3[1] = *(_DWORD *)(result + 8);
      v3[2] = *(_DWORD *)(result + 12);
      v3[3] = *(_DWORD *)(result + 16);
      v3[4] = *(_DWORD *)(result + 20);
      *(_DWORD *)(result + 48) = (100 * v14 + 75 * v17 + 25 * v19 + 50 * (v20 - (v17 + v14 + v6 + v19) + v21 + v4))
                               / (v21 + v4);
      return result;
    }
    goto LABEL_41;
  }
  if ( !a2 || (a3 & 1) != 0 )
    return result;
  if ( a3 > 0x85 )
  {
LABEL_41:
    __break(0x5512u);
    goto LABEL_42;
  }
  if ( ((20LL * a3) | 4uLL) > 0xA78 )
  {
LABEL_42:
    __break(1u);
    return ipa_get_gsi_pipe_info(result, a2);
  }
  v22 = (unsigned int *)((char *)&poll_pack_and_cred_info + 20 * a3);
  v23 = a2[5];
  v25 = a2[3];
  v24 = a2[4];
  v26 = a2[1];
  v27 = a2[2];
  v29 = v22[2];
  v28 = v22[3];
  v30 = *v22;
  result = v22[1];
  *v22 = v26;
  if ( v24 < v28 )
    v31 = ~v28;
  else
    v31 = -v28;
  if ( v25 < v29 )
    v32 = ~v29;
  else
    v32 = -v29;
  v33 = v31 + v24;
  v34 = v22[4];
  if ( v26 < v30 )
    ++v30;
  v35 = v32 + v25;
  if ( v27 < (unsigned int)result )
    v36 = ~(_DWORD)result;
  else
    v36 = -(int)result;
  v37 = v26 + v35;
  v38 = v36 + v27;
  if ( v23 < v34 )
    v39 = ~v34;
  else
    v39 = -v34;
  v22[1] = a2[2];
  v22[2] = a2[3];
  v22[3] = a2[4];
  v22[4] = a2[5];
  a2[11] = (25 * v35 + 75 * v33 + 100 * v38 + 50 * (v30 - (v37 + v33 + v38) + v39 + v23)) / (v39 + v23);
  return result;
}
