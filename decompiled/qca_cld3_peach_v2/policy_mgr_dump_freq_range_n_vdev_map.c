void __fastcall policy_mgr_dump_freq_range_n_vdev_map(int a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v5; // x20
  unsigned int v7; // w23
  __int64 v8; // x24
  int *v9; // x25
  int v10; // w3
  int v11; // w4
  int v12; // t1
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w0
  unsigned int v22; // w21
  _DWORD *v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w0
  _QWORD v33[12]; // [xsp+0h] [xbp-70h] BYREF
  int v34; // [xsp+60h] [xbp-10h]
  __int64 v35; // [xsp+68h] [xbp-8h]

  LODWORD(v5) = a1;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  memset(v33, 0, sizeof(v33));
  if ( a4 && a3 )
  {
    v7 = 0;
    v8 = a3;
    v9 = (int *)(a4 + 8);
    do
    {
      if ( v7 >= 0x65 )
LABEL_15:
        __break(0x5512u);
      v10 = *(v9 - 2);
      v11 = *(v9 - 1);
      v12 = *v9;
      v9 += 3;
      v13 = scnprintf((char *)v33 + v7, 100 - v7, "mac %d: %d => %d ", v10, v11, v12);
      --v8;
      v7 += v21;
    }
    while ( v8 );
    if ( a3 )
      qdf_trace_msg(0x4Fu, 8u, "Freq range:: %s", v13, v14, v15, v16, v17, v18, v19, v20, v33);
  }
  if ( (_DWORD)v5 && a2 )
  {
    v22 = 0;
    v5 = (unsigned int)v5;
    v23 = (_DWORD *)(a2 + 4);
    do
    {
      if ( v22 > 0x64 )
        goto LABEL_15;
      v24 = scnprintf((char *)v33 + v22, 100 - v22, "vdev %d -> mac %d ", *(v23 - 1), *v23);
      --v5;
      v22 += v32;
      v23 += 2;
    }
    while ( v5 );
    qdf_trace_msg(0x4Fu, 8u, "Vdev Map:: %s", v24, v25, v26, v27, v28, v29, v30, v31, v33);
  }
  _ReadStatusReg(SP_EL0);
}
