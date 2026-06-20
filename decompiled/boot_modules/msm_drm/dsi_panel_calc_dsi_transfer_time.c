void __fastcall dsi_panel_calc_dsi_transfer_time(__int64 a1, unsigned int *a2, unsigned int a3)
{
  __int64 v3; // x8
  unsigned int v6; // w22
  __int64 v7; // x11
  __int64 v8; // x13
  unsigned int v9; // w15
  int v10; // w13
  int v11; // w16
  unsigned __int64 v12; // x14
  __int64 v13; // x13
  __int64 v14; // x13
  __int64 v15; // x13
  __int64 v16; // x14
  int v17; // w12
  int v18; // w15
  __int64 v19; // x23
  unsigned int v20; // w9
  unsigned int v21; // w10
  unsigned int v22; // w8
  unsigned int v23; // w21
  unsigned __int64 v24; // x9
  __int64 v25; // x8
  unsigned int v26; // w9
  unsigned int v27; // w8

  v3 = a2[11];
  if ( (unsigned int)v3 <= 0x77 )
    v6 = a3;
  else
    v6 = 500;
  v7 = *((_QWORD *)a2 + 23);
  if ( *((_BYTE *)a2 + 72) == 1 )
  {
    v8 = *((_QWORD *)a2 + 10);
    v9 = *(unsigned __int16 *)(v8 + 4);
    v10 = *(unsigned __int16 *)(v8 + 16) >> 4;
    if ( (*(_BYTE *)(a1 + 52) & 1) != 0 )
      v11 = 120;
    else
      v11 = 56;
    v12 = (unsigned int)v3 * (unsigned __int64)((v11 + v10 * v9) * (*a2 / v9) / *(unsigned __int8 *)(a1 + 8)) * a2[6];
    LODWORD(v13) = a2[6];
  }
  else
  {
    if ( *((_BYTE *)a2 + 73) == 1 && (v14 = *((_QWORD *)a2 + 11)) != 0 )
      v15 = *(int *)(v14 + 500);
    else
      v15 = *a2;
    v16 = v15 * v3;
    v13 = a2[6];
    v12 = v16 * v13 * (unsigned __int64)a2[42] / *(unsigned __int8 *)(a1 + 8);
  }
  v17 = *(_DWORD *)(v7 + 2372);
  v18 = *(_DWORD *)(v7 + 2376);
  *((_QWORD *)a2 + 7) = v12;
  if ( *(_DWORD *)(a1 + 52) == 1 )
    *((_QWORD *)a2 + 7) = 7 * (v12 >> 4);
  v19 = 1000 * (0x3E8 % (unsigned int)v3) / (unsigned int)v3 + 1000 * (0x3E8 / (unsigned int)v3);
  if ( (*(_BYTE *)(v7 + 3452) & 1) != 0 )
    v20 = 40;
  else
    v20 = (unsigned int)v19 % (100 * v18) * v17 / (100 * v18) + (unsigned int)v19 / (100 * v18) * v17 + 40;
  v21 = a2[9] + a2[7] + a2[8];
  v22 = 40 * (int)v3 / 0x3Cu;
  if ( v21 > v22 )
    v22 = a2[9] + a2[7] + a2[8];
  v23 = v20
      + (unsigned int)v19 / (v21 + (unsigned int)v13) * v22
      + (unsigned int)v19 % (v21 + (unsigned int)v13) * v22 / (v21 + (unsigned int)v13);
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: min threshold time=%d\n", v23);
  if ( *((_QWORD *)a2 + 6) )
  {
    v24 = *((_QWORD *)a2 + 7) * v19 / (unsigned __int64)(unsigned int)*((_QWORD *)a2 + 6);
    v25 = *((_QWORD *)a2 + 23);
  }
  else
  {
    v25 = *((_QWORD *)a2 + 23);
    v26 = *(_DWORD *)(v25 + 2384);
    if ( v26 )
    {
      if ( v26 >= (unsigned int)v19 - v23 )
        v26 = v19 - v23;
      *(_DWORD *)(v25 + 2384) = v26;
      v25 = *((_QWORD *)a2 + 23);
      LODWORD(v24) = *(_DWORD *)(v25 + 2384);
    }
    else
    {
      if ( v23 > v6 || *(_BYTE *)(v25 + 3452) == 1 )
        v6 = v23;
      LODWORD(v24) = v19 - v6;
    }
  }
  a2[16] = v24;
  a2[17] = v24;
  v27 = *(_DWORD *)(v25 + 2384);
  if ( v27 && *((_QWORD *)a2 + 6) )
    a2[16] = v27;
  a2[38] = (unsigned int)(*((_QWORD *)a2 + 7)
                        * v19
                        / (unsigned __int64)(unsigned int)v24
                        * *(unsigned __int8 *)(a1 + 8)
                        / a2[42])
         / 0x3E8;
}
