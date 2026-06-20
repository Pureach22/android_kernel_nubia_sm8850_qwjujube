__int64 __fastcall dsi_convert_to_drm_mode(int *a1, __int64 a2)
{
  int v2; // w8
  int v4; // w21
  __int16 v5; // w9
  __int16 v6; // w9
  unsigned __int16 v7; // w9
  int v8; // w22
  __int16 v9; // w10
  __int16 v10; // w10
  unsigned __int16 v11; // w10
  int v12; // w9
  int v13; // w8
  const char *v14; // x9
  const char *v15; // x20
  int v16; // w0

  v2 = a1[40];
  *(_QWORD *)(a2 + 104) = 0;
  *(_QWORD *)(a2 + 112) = 0;
  *(_QWORD *)(a2 + 88) = 0;
  *(_QWORD *)(a2 + 96) = 0;
  *(_QWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 56) = 0;
  *(_QWORD *)(a2 + 64) = 0;
  *(_QWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 48) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)a2 = 0;
  v4 = *a1;
  *(_WORD *)(a2 + 4) = *a1;
  v5 = a1[3] + v4;
  *(_WORD *)(a2 + 6) = v5;
  v6 = a1[2] + v5;
  *(_WORD *)(a2 + 8) = v6;
  v7 = a1[1] + v6;
  *(_WORD *)(a2 + 10) = v7;
  *(_WORD *)(a2 + 12) = a1[4];
  v8 = a1[6];
  *(_WORD *)(a2 + 14) = v8;
  v9 = a1[9] + v8;
  *(_WORD *)(a2 + 16) = v9;
  v10 = a1[8] + v9;
  *(_WORD *)(a2 + 18) = v10;
  v11 = a1[7] + v10;
  *(_WORD *)(a2 + 20) = v11;
  *(_DWORD *)a2 = v11 * (unsigned int)v7 * a1[11] / 0x3E8;
  if ( *((_BYTE *)a1 + 20) == 1 )
  {
    *(_DWORD *)(a2 + 24) = 1;
    v12 = 5;
  }
  else
  {
    v12 = 4;
  }
  if ( *((_BYTE *)a1 + 40) == 1 )
    *(_DWORD *)(a2 + 24) = v12;
  v13 = v2 & 3;
  v14 = "vid";
  if ( v13 == 2 )
    v14 = "cmd";
  if ( v13 == 3 )
    v15 = "vid_cmd";
  else
    v15 = v14;
  v16 = drm_mode_vrefresh(a2);
  return snprintf((char *)(a2 + 80), 0x20u, "%dx%dx%d%s", (unsigned __int16)v4, (unsigned __int16)v8, v16, v15);
}
