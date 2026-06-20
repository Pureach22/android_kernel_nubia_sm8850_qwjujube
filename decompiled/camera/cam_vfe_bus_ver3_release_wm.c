__int64 __fastcall cam_vfe_bus_ver3_release_wm(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x9
  _QWORD *v3; // x9
  char v4; // w9

  v1 = *(_QWORD *)(result + 24);
  v2 = *(_QWORD *)(v1 + 56);
  *(_DWORD *)(v1 + 116) = 0;
  *(_WORD *)(v1 + 160) = 0;
  *(_BYTE *)(v1 + 164) = 0;
  *(_QWORD *)(v1 + 16) = 0;
  *(_QWORD *)(v1 + 24) = 0;
  *(_QWORD *)(v1 + 32) = 0;
  *(_QWORD *)(v1 + 40) = 0;
  *(_QWORD *)(v1 + 124) = 0;
  *(_QWORD *)(v1 + 132) = 0;
  *(_DWORD *)(v1 + 140) = 0;
  *(_QWORD *)(v1 + 72) = 0;
  *(_QWORD *)(v1 + 80) = 0;
  *(_QWORD *)(v1 + 88) = 0;
  *(_QWORD *)(v1 + 96) = 0;
  *(_QWORD *)(v1 + 104) = 0;
  if ( (*(_BYTE *)(v2 + 133) & 1) != 0 || *(_BYTE *)(v2 + 134) == 1 )
  {
    v3 = *(_QWORD **)(v1 + 64);
    v3[28] = 0;
    v3[29] = 0;
    v3[26] = 0;
    v3[27] = 0;
    v3[24] = 0;
    v3[25] = 0;
    v3[22] = 0;
    v3[23] = 0;
    v3[20] = 0;
    v3[21] = 0;
    v3[18] = 0;
    v3[19] = 0;
    v3[16] = 0;
    v3[17] = 0;
    v3[14] = 0;
    v3[15] = 0;
    v3[12] = 0;
    v3[13] = 0;
    v3[10] = 0;
    v3[11] = 0;
    v3[8] = 0;
    v3[9] = 0;
    v3[6] = 0;
    v3[7] = 0;
    v3[4] = 0;
    v3[5] = 0;
    v3[2] = 0;
    v3[3] = 0;
    *v3 = 0;
    v3[1] = 0;
  }
  *(_QWORD *)(result + 56) = 0;
  v4 = debug_mdl;
  *(_DWORD *)(result + 8) = 1;
  if ( (v4 & 8) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             v4 & 8,
             4,
             "cam_vfe_bus_ver3_release_wm",
             1410,
             "VFE:%u Release WM:%d %s",
             *(_DWORD *)(*(_QWORD *)v1 + 8LL),
             *(_DWORD *)(v1 + 120),
             (const char *)(result + 128));
  return result;
}
