__int64 __fastcall wcd938x_set_port_params(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        _BYTE *a4,
        _BYTE *a5,
        _DWORD *a6,
        _BYTE *a7,
        char a8)
{
  int v8; // w19
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x10
  _DWORD *v12; // x8
  unsigned int v13; // w10
  unsigned int v14; // w9
  int v15; // w9
  _DWORD *v17; // x8

  v8 = (unsigned __int8)a2;
  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  v10 = 364;
  if ( a8 == 1 )
    v10 = 1644;
  v11 = 360;
  v12 = (_DWORD *)(v9 + v10);
  if ( a8 == 1 )
    v11 = 361;
  if ( *v12 == (unsigned __int8)a2 )
  {
    v13 = 0;
    v14 = 0;
LABEL_27:
    *a3 = v13;
    v17 = &v12[40 * v13 + 5 * v14];
    *a4 = v17[3];
    *a5 = v17[2];
    *a6 = v17[4];
    *a7 = v17[1];
    return 0;
  }
  if ( v12[5] == (unsigned __int8)a2 )
  {
    v13 = 0;
    v14 = 1;
    goto LABEL_27;
  }
  if ( v12[10] == (unsigned __int8)a2 )
  {
    v13 = 0;
    v14 = 2;
    goto LABEL_27;
  }
  if ( v12[15] == (unsigned __int8)a2 )
  {
    v13 = 0;
    v14 = 3;
    goto LABEL_27;
  }
  if ( v12[20] == (unsigned __int8)a2 )
  {
    v13 = 0;
    v14 = 4;
    goto LABEL_27;
  }
  if ( v12[25] == (unsigned __int8)a2 )
  {
    v13 = 0;
    v14 = 5;
    goto LABEL_27;
  }
  if ( v12[30] == (unsigned __int8)a2 )
  {
    v13 = 0;
    v14 = 6;
    goto LABEL_27;
  }
  if ( v12[35] == (unsigned __int8)a2 )
  {
    v13 = 0;
    v14 = 7;
    goto LABEL_27;
  }
  v15 = *(unsigned __int8 *)(v9 + v11);
  if ( !v15 )
    goto LABEL_149;
  if ( v12[40] == (unsigned __int8)a2 )
  {
    v14 = 0;
LABEL_24:
    v13 = 1;
    goto LABEL_27;
  }
  if ( v12[45] == (unsigned __int8)a2 )
  {
    v13 = 1;
    v14 = 1;
    goto LABEL_27;
  }
  if ( v12[50] == (unsigned __int8)a2 )
  {
    v14 = 2;
    goto LABEL_24;
  }
  if ( v12[55] == (unsigned __int8)a2 )
  {
    v14 = 3;
    goto LABEL_24;
  }
  if ( v12[60] == (unsigned __int8)a2 )
  {
    v14 = 4;
    goto LABEL_24;
  }
  if ( v12[65] == (unsigned __int8)a2 )
  {
    v14 = 5;
    goto LABEL_24;
  }
  if ( v12[70] == (unsigned __int8)a2 )
  {
    v14 = 6;
    goto LABEL_24;
  }
  if ( v12[75] == (unsigned __int8)a2 )
  {
    v14 = 7;
    goto LABEL_24;
  }
  if ( v15 == 1 )
    goto LABEL_149;
  if ( v12[80] == (unsigned __int8)a2 )
  {
    v14 = 0;
    v13 = 2;
    goto LABEL_27;
  }
  if ( v12[85] == (unsigned __int8)a2 )
  {
    v14 = 1;
    v13 = 2;
    goto LABEL_27;
  }
  if ( v12[90] == (unsigned __int8)a2 )
  {
    v13 = 2;
    v14 = 2;
    goto LABEL_27;
  }
  if ( v12[95] == (unsigned __int8)a2 )
  {
    v14 = 3;
    v13 = 2;
    goto LABEL_27;
  }
  if ( v12[100] == (unsigned __int8)a2 )
  {
    v14 = 4;
    v13 = 2;
    goto LABEL_27;
  }
  if ( v12[105] == (unsigned __int8)a2 )
  {
    v14 = 5;
    v13 = 2;
    goto LABEL_27;
  }
  if ( v12[110] == (unsigned __int8)a2 )
  {
    v14 = 6;
    v13 = 2;
    goto LABEL_27;
  }
  if ( v12[115] == (unsigned __int8)a2 )
  {
    v14 = 7;
    v13 = 2;
    goto LABEL_27;
  }
  if ( v15 == 2 )
    goto LABEL_149;
  if ( v12[120] == (unsigned __int8)a2 )
  {
    v14 = 0;
    v13 = 3;
    goto LABEL_27;
  }
  if ( v12[125] == (unsigned __int8)a2 )
  {
    v14 = 1;
    v13 = 3;
    goto LABEL_27;
  }
  if ( v12[130] == (unsigned __int8)a2 )
  {
    v14 = 2;
    v13 = 3;
    goto LABEL_27;
  }
  if ( v12[135] == (unsigned __int8)a2 )
  {
    v13 = 3;
    v14 = 3;
    goto LABEL_27;
  }
  if ( v12[140] == (unsigned __int8)a2 )
  {
    v14 = 4;
    v13 = 3;
    goto LABEL_27;
  }
  if ( v12[145] == (unsigned __int8)a2 )
  {
    v14 = 5;
    v13 = 3;
    goto LABEL_27;
  }
  if ( v12[150] == (unsigned __int8)a2 )
  {
    v14 = 6;
    v13 = 3;
    goto LABEL_27;
  }
  if ( v12[155] == (unsigned __int8)a2 )
  {
    v14 = 7;
    v13 = 3;
    goto LABEL_27;
  }
  if ( v15 == 3 )
    goto LABEL_149;
  if ( v12[160] == (unsigned __int8)a2 )
  {
    v14 = 0;
    v13 = 4;
    goto LABEL_27;
  }
  if ( v12[165] == (unsigned __int8)a2 )
  {
    v14 = 1;
    v13 = 4;
    goto LABEL_27;
  }
  if ( v12[170] == (unsigned __int8)a2 )
  {
    v14 = 2;
    v13 = 4;
    goto LABEL_27;
  }
  if ( v12[175] == (unsigned __int8)a2 )
  {
    v14 = 3;
    v13 = 4;
    goto LABEL_27;
  }
  if ( v12[180] == (unsigned __int8)a2 )
  {
    v13 = 4;
    v14 = 4;
    goto LABEL_27;
  }
  if ( v12[185] == (unsigned __int8)a2 )
  {
    v14 = 5;
    v13 = 4;
    goto LABEL_27;
  }
  if ( v12[190] == (unsigned __int8)a2 )
  {
    v14 = 6;
    v13 = 4;
    goto LABEL_27;
  }
  if ( v12[195] == (unsigned __int8)a2 )
  {
    v14 = 7;
    v13 = 4;
    goto LABEL_27;
  }
  if ( v15 == 4 )
    goto LABEL_149;
  if ( v12[200] == (unsigned __int8)a2 )
  {
    v14 = 0;
    v13 = 5;
    goto LABEL_27;
  }
  if ( v12[205] == (unsigned __int8)a2 )
  {
    v14 = 1;
    v13 = 5;
    goto LABEL_27;
  }
  if ( v12[210] == (unsigned __int8)a2 )
  {
    v14 = 2;
    v13 = 5;
    goto LABEL_27;
  }
  if ( v12[215] == (unsigned __int8)a2 )
  {
    v14 = 3;
    v13 = 5;
    goto LABEL_27;
  }
  if ( v12[220] == (unsigned __int8)a2 )
  {
    v14 = 4;
    v13 = 5;
    goto LABEL_27;
  }
  if ( v12[225] == (unsigned __int8)a2 )
  {
    v13 = 5;
    v14 = 5;
    goto LABEL_27;
  }
  if ( v12[230] == (unsigned __int8)a2 )
  {
    v14 = 6;
    v13 = 5;
    goto LABEL_27;
  }
  if ( v12[235] == (unsigned __int8)a2 )
  {
    v14 = 7;
    v13 = 5;
    goto LABEL_27;
  }
  if ( v15 == 5 )
    goto LABEL_149;
  if ( v12[240] == (unsigned __int8)a2 )
  {
    v14 = 0;
    v13 = 6;
    goto LABEL_27;
  }
  if ( v12[245] == (unsigned __int8)a2 )
  {
    v14 = 1;
    v13 = 6;
    goto LABEL_27;
  }
  if ( v12[250] == (unsigned __int8)a2 )
  {
    v14 = 2;
    v13 = 6;
    goto LABEL_27;
  }
  if ( v12[255] == (unsigned __int8)a2 )
  {
    v14 = 3;
    v13 = 6;
    goto LABEL_27;
  }
  if ( v12[260] == (unsigned __int8)a2 )
  {
    v14 = 4;
    v13 = 6;
    goto LABEL_27;
  }
  if ( v12[265] == (unsigned __int8)a2 )
  {
    v14 = 5;
    v13 = 6;
    goto LABEL_27;
  }
  if ( v12[270] == (unsigned __int8)a2 )
  {
    v13 = 6;
    v14 = 6;
    goto LABEL_27;
  }
  if ( v12[275] == (unsigned __int8)a2 )
  {
    v14 = 7;
    v13 = 6;
    goto LABEL_27;
  }
  if ( v15 == 6 )
    goto LABEL_149;
  if ( v12[280] == (unsigned __int8)a2 )
  {
    v14 = 0;
    v13 = 7;
    goto LABEL_27;
  }
  if ( v12[285] == (unsigned __int8)a2 )
  {
    v14 = 1;
    v13 = 7;
    goto LABEL_27;
  }
  if ( v12[290] == (unsigned __int8)a2 )
  {
    v14 = 2;
    v13 = 7;
    goto LABEL_27;
  }
  if ( v12[295] == (unsigned __int8)a2 )
  {
    v14 = 3;
    v13 = 7;
    goto LABEL_27;
  }
  if ( v12[300] == (unsigned __int8)a2 )
  {
    v14 = 4;
    v13 = 7;
    goto LABEL_27;
  }
  if ( v12[305] == (unsigned __int8)a2 )
  {
    v14 = 5;
    v13 = 7;
    goto LABEL_27;
  }
  if ( v12[310] == (unsigned __int8)a2 )
  {
    v14 = 6;
    v13 = 7;
    goto LABEL_27;
  }
  if ( v12[315] == (unsigned __int8)a2 )
  {
    v13 = 7;
    v14 = 7;
    goto LABEL_27;
  }
  if ( v15 == 7 )
  {
LABEL_149:
    if ( (unsigned int)__ratelimit(&wcd938x_set_port_params__rs_253, "wcd938x_set_port_params") )
      dev_err(*(_QWORD *)(a1 + 24), "%s Failed to find slave port for type %u\n", "wcd938x_set_port_params", v8);
    return 4294967274LL;
  }
  else
  {
    __break(0x5512u);
    return _wcd938x_codec_enable_micbias(a1, a2);
  }
}
