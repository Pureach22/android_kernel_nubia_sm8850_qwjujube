__int64 __fastcall get_dma_info(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x21
  __int64 v5; // x8
  __int64 v6; // x9
  int *v7; // x20
  int v8; // w10
  unsigned int v9; // w8
  int *v10; // x9
  int v11; // w12
  int v12; // w11
  int v13; // w13
  int v14; // w15
  int v15; // t1
  int v16; // w10
  int v17; // w12
  int v18; // w11
  int v19; // w10
  int v20; // w13
  int v21; // w12
  int v22; // w10
  int v23; // w12
  int v24; // w11
  int v25; // w10
  int v26; // w11
  int v27; // w13
  int v28; // w10
  int v29; // w13
  int v30; // w8
  unsigned __int64 v31; // t2
  int v32; // w9
  int v33; // w10
  int v34; // w8
  int v35; // w9
  __int64 v36; // x8
  int v38; // w0
  __int64 v39; // x9
  __int64 v40; // x8
  __int64 *v41; // x10
  __int64 v42; // x1
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x9
  void *v47; // x10
  __int64 v48; // x8
  __int64 v49; // x9

  if ( (qcom_is_dma_buf_file(a2) & 1) == 0 )
    return 0;
  v4 = *(_QWORD **)a1;
  if ( !*(_DWORD *)(a1 + 16) )
  {
    v5 = v4[2]
       + (int)scnprintf(
                *v4 + v4[2],
                v4[1] - v4[2],
                "\n%s (PID %d)\nDMA Buffers:\n",
                (const char *)(*(_QWORD *)(a1 + 8) + 2320LL),
                *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1804LL));
    v6 = v4[1] - 1LL;
    v4[2] = v5;
    if ( v5 == v6 )
      return 4294967274LL;
  }
  v7 = *(int **)(a2 + 32);
  v8 = 1979019907;
  v9 = 264;
  v10 = v7;
  v11 = 1979019907;
  v12 = 1979019907;
  do
  {
    v14 = v10[1];
    v13 = v10[2];
    v15 = *v10;
    v10 += 3;
    v9 -= 12;
    v16 = v13 + v8;
    v17 = v14 + v11;
    v18 = (v15 + v12 - v16) ^ __ROR4__(v16, 28);
    v19 = v16 + v17;
    v20 = (v17 - v18) ^ __ROR4__(v18, 26);
    v21 = v19 - v20;
    v22 = v18 + v19;
    v23 = v21 ^ __ROR4__(v20, 24);
    v24 = v22 - v23;
    v25 = v20 + v22;
    v26 = v24 ^ __ROR4__(v23, 16);
    v27 = v25 - v26;
    v28 = v23 + v25;
    v29 = v27 ^ __ROR4__(v26, 13);
    v12 = v26 + v28;
    v8 = (v28 - v29) ^ __ROR4__(v29, 28);
    v11 = v29 + v12;
  }
  while ( v9 > 0xC );
  v30 = v11
      + (*((unsigned __int8 *)v7 + 259) << 24)
      + (*((unsigned __int8 *)v7 + 258) << 16)
      + (*((unsigned __int8 *)v7 + 257) << 8)
      + *((unsigned __int8 *)v7 + 256);
  HIDWORD(v31) = v30;
  LODWORD(v31) = v30;
  v32 = (v30
       ^ (v8
        + (*((unsigned __int8 *)v7 + 263) << 24)
        + (*((unsigned __int8 *)v7 + 262) << 16)
        + (*((unsigned __int8 *)v7 + 261) << 8)
        + *((unsigned __int8 *)v7 + 260)))
      - (v31 >> 18);
  HIDWORD(v31) = v32;
  LODWORD(v31) = v32;
  v33 = (v32
       ^ (v12
        + (*((unsigned __int8 *)v7 + 255) << 24)
        + (*((unsigned __int8 *)v7 + 254) << 16)
        + (*((unsigned __int8 *)v7 + 253) << 8)
        + *((unsigned __int8 *)v7 + 252)))
      - (v31 >> 21);
  HIDWORD(v31) = v33;
  LODWORD(v31) = v33;
  v34 = (v33 ^ v30) - (v31 >> 7);
  HIDWORD(v31) = v34;
  LODWORD(v31) = v34;
  v35 = (v34 ^ v32) - (v31 >> 16);
  HIDWORD(v31) = v35;
  LODWORD(v31) = v35;
  HIDWORD(v31) = (v35 ^ v33) - (v31 >> 28);
  LODWORD(v31) = HIDWORD(v31);
  v36 = ((((HIDWORD(v31) ^ v34) - (unsigned int)(v31 >> 18)) ^ v35)
       - (((HIDWORD(v31) ^ v34) - (unsigned int)(v31 >> 18)) >> 8))
      & 0xFFFFF;
  if ( (dma_buf_hash[v36] & 1) != 0 )
    return 0;
  dma_buf_hash[v36] = 1;
  ++*(_DWORD *)(a1 + 16);
  v38 = scnprintf(
          *v4 + v4[2],
          v4[1] - v4[2],
          "%-8s\t%-8s\t%-8s\t%-8s\texp_name\t%-8s\n",
          "size",
          "flags",
          "mode",
          "count",
          "ino");
  v39 = v4[1];
  v40 = v4[2] + v38;
  v4[2] = v40;
  if ( v40 == v39 - 1 )
    return 4294967274LL;
  v41 = *((__int64 **)v7 + 1);
  v42 = v39 - v40;
  v43 = *((unsigned int *)v41 + 12);
  v44 = *((unsigned int *)v41 + 3);
  v45 = *v41;
  v46 = *(_QWORD *)(v41[5] + 64);
  v47 = &unk_112C48;
  if ( *((_QWORD *)v7 + 9) )
    v47 = *((void **)v7 + 9);
  v48 = v4[2]
      + (int)scnprintf(
               *v4 + v40,
               v42,
               "%08zu\t%08x\t%08x\t%08ld\t%s\t%08lu\t%s\n",
               *(_QWORD *)v7,
               v43,
               v44,
               v45,
               *((_QWORD *)v7 + 8),
               v46,
               v47);
  v49 = v4[1] - 1LL;
  v4[2] = v48;
  if ( v48 == v49 )
    return 4294967274LL;
  *(_QWORD *)(a1 + 24) += *(_QWORD *)v7;
  return 0;
}
