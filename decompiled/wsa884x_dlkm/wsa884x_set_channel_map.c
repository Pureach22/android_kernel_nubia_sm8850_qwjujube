__int64 __fastcall wsa884x_set_channel_map(
        __int64 a1,
        _BYTE *a2,
        unsigned __int8 a3,
        unsigned int *a4,
        _DWORD *a5,
        _BYTE *a6)
{
  __int64 v11; // x24
  __int64 result; // x0

  if ( a3 <= 6u && a2 && a4 && a5 )
  {
    if ( !a3 )
      return 0;
    v11 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
    *(_BYTE *)(v11 + 40) = *a2;
    *(_BYTE *)(v11 + 41) = *a4;
    *(_DWORD *)(v11 + 44) = *a5;
    *(_BYTE *)(v11 + 48) = _sw_hweight8(*a4);
    if ( a6 )
      *(_BYTE *)(v11 + 49) = *a6;
    if ( a3 == 1 )
      return 0;
    *(_BYTE *)(v11 + 52) = a2[1];
    *(_BYTE *)(v11 + 53) = a4[1];
    *(_DWORD *)(v11 + 56) = a5[1];
    *(_BYTE *)(v11 + 60) = _sw_hweight8(a4[1]);
    if ( a6 )
      *(_BYTE *)(v11 + 61) = a6[1];
    if ( a3 == 2 )
      return 0;
    *(_BYTE *)(v11 + 64) = a2[2];
    *(_BYTE *)(v11 + 65) = a4[2];
    *(_DWORD *)(v11 + 68) = a5[2];
    *(_BYTE *)(v11 + 72) = _sw_hweight8(a4[2]);
    if ( a6 )
      *(_BYTE *)(v11 + 73) = a6[2];
    if ( a3 == 3 )
      return 0;
    *(_BYTE *)(v11 + 76) = a2[3];
    *(_BYTE *)(v11 + 77) = a4[3];
    *(_DWORD *)(v11 + 80) = a5[3];
    *(_BYTE *)(v11 + 84) = _sw_hweight8(a4[3]);
    if ( a6 )
      *(_BYTE *)(v11 + 85) = a6[3];
    if ( a3 == 4 )
      return 0;
    *(_BYTE *)(v11 + 88) = a2[4];
    *(_BYTE *)(v11 + 89) = a4[4];
    *(_DWORD *)(v11 + 92) = a5[4];
    *(_BYTE *)(v11 + 96) = _sw_hweight8(a4[4]);
    if ( a6 )
      *(_BYTE *)(v11 + 97) = a6[4];
    if ( a3 == 5 )
    {
      return 0;
    }
    else
    {
      *(_BYTE *)(v11 + 100) = a2[5];
      *(_BYTE *)(v11 + 101) = a4[5];
      *(_DWORD *)(v11 + 104) = a5[5];
      *(_BYTE *)(v11 + 108) = _sw_hweight8(a4[5]);
      result = 0;
      if ( a6 )
        *(_BYTE *)(v11 + 109) = a6[5];
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&wsa884x_set_channel_map__rs, "wsa884x_set_channel_map") )
      dev_err(
        *(_QWORD *)(a1 + 24),
        "%s: Invalid port=%pK, ch_mask=%pK, ch_rate=%pK\n",
        "wsa884x_set_channel_map",
        a2,
        a4,
        a5);
    return 4294967274LL;
  }
  return result;
}
