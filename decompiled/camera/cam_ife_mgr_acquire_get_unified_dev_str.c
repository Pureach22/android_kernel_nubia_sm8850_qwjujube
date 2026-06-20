_DWORD *__fastcall cam_ife_mgr_acquire_get_unified_dev_str(_DWORD *result, __int64 a2)
{
  int v2; // w9
  int v3; // w8
  unsigned int v4; // w8
  _DWORD *v5; // x11
  __int64 v6; // x12

  *(_DWORD *)(a2 + 8) = *result;
  *(_DWORD *)(a2 + 12) = result[1];
  *(_DWORD *)(a2 + 16) = result[2];
  *(_DWORD *)(a2 + 20) = result[3];
  *(_DWORD *)(a2 + 24) = result[4];
  v2 = result[5];
  *(_DWORD *)(a2 + 56) = 1;
  *(_DWORD *)(a2 + 40) = v2;
  *(_DWORD *)(a2 + 60) = result[6];
  *(_DWORD *)(a2 + 76) = result[7];
  *(_DWORD *)(a2 + 80) = result[8];
  *(_DWORD *)(a2 + 84) = result[9];
  *(_DWORD *)(a2 + 88) = result[10];
  *(_DWORD *)(a2 + 92) = result[11];
  *(_DWORD *)(a2 + 96) = result[12];
  *(_DWORD *)(a2 + 100) = result[13];
  *(_DWORD *)(a2 + 104) = result[14];
  *(_DWORD *)(a2 + 108) = result[15];
  *(_DWORD *)(a2 + 112) = result[16];
  *(_DWORD *)(a2 + 116) = result[17];
  *(_DWORD *)(a2 + 120) = result[18];
  *(_DWORD *)(a2 + 124) = result[19];
  *(_DWORD *)(a2 + 128) = result[20];
  *(_DWORD *)(a2 + 132) = result[21];
  *(_DWORD *)(a2 + 136) = result[6];
  *(_DWORD *)(a2 + 140) = 0;
  v3 = result[23];
  *(_DWORD *)(a2 + 144) = v3;
  if ( v3 )
  {
    v4 = 0;
    do
    {
      v5 = &result[8 * v4 + 24];
      *(_DWORD *)(*(_QWORD *)(a2 + 224) + 44LL * (int)v4) = *v5;
      *(_DWORD *)(*(_QWORD *)(a2 + 224) + 44LL * (int)v4 + 4) = v5[1];
      *(_DWORD *)(*(_QWORD *)(a2 + 224) + 44LL * (int)v4 + 8) = v5[2];
      *(_DWORD *)(*(_QWORD *)(a2 + 224) + 44LL * (int)v4 + 12) = v5[3];
      *(_DWORD *)(*(_QWORD *)(a2 + 224) + 44LL * (int)v4 + 16) = v5[4];
      *(_DWORD *)(*(_QWORD *)(a2 + 224) + 44LL * (int)v4 + 20) = v5[5];
      v6 = *(_QWORD *)(a2 + 224) + 44LL * (int)v4++;
      *(_DWORD *)(v6 + 24) = v5[6];
    }
    while ( v4 < result[23] );
  }
  return result;
}
