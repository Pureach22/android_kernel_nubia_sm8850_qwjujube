__int64 __fastcall cam_icp_mgr_is_valid_outconfig(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x9
  int v3; // w13
  int v4; // w11
  int v5; // w12
  signed int v6; // w10
  int v7; // w14
  __int64 v8; // x15
  unsigned int v9; // w14
  int v10; // w19
  __int64 v11; // x11
  unsigned int v12; // w20
  __int64 v13; // x20

  v1 = *(_DWORD *)(a1 + 36);
  if ( !v1 )
  {
    v12 = 1;
    v10 = 0;
    goto LABEL_20;
  }
  v2 = a1 + (*(_DWORD *)(a1 + 32) & 0xFFFFFFFC) + 56;
  if ( v1 == 1 || v1 - 1 < 0 )
  {
    v10 = 0;
    v6 = 0;
  }
  else
  {
    v3 = 0;
    v4 = 0;
    v5 = 0;
    v6 = v1 & 0xFFFFFFFE;
    do
    {
      v7 = v3 + 1;
      v8 = v3;
      v3 += 2;
      v9 = *(_DWORD *)(v2 + ((__int64)v7 << 8) + 224) & 0xFFFFFFFE;
      if ( (*(_DWORD *)(v2 + (v8 << 8) + 224) & 0xFFFFFFFE) == 2 )
        ++v4;
      if ( v9 == 2 )
        ++v5;
    }
    while ( v6 != v3 );
    v10 = v5 + v4;
    if ( v1 == v6 )
      goto LABEL_16;
  }
  do
  {
    v11 = v6++;
    if ( (*(_DWORD *)(v2 + (v11 << 8) + 224) & 0xFFFFFFFE) == 2 )
      ++v10;
  }
  while ( v1 != v6 );
LABEL_16:
  if ( v10 >= 15 )
  {
    v13 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_is_valid_outconfig",
      6394,
      "Out config entries(%u) more than allowed(%u)",
      v10,
      14);
    a1 = v13;
    v12 = 0;
  }
  else
  {
    v12 = 1;
  }
LABEL_20:
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_is_valid_outconfig",
      6400,
      "number of io config: %u out config: %u max out res: %u",
      *(_DWORD *)(a1 + 36),
      v10,
      14);
  return v12;
}
