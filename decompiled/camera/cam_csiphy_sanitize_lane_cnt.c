__int64 __fastcall cam_csiphy_sanitize_lane_cnt(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  bool v3; // zf
  int v4; // w8
  unsigned int v5; // w6
  unsigned int v6; // w7

  if ( *(_BYTE *)(a1 + 97) )
  {
    if ( a2 < 3 )
    {
      v3 = *(_DWORD *)(a1 + 104LL * a2 + 624) == 0;
      v4 = 1;
      goto LABEL_4;
    }
  }
  else if ( *(_BYTE *)(a1 + 98) )
  {
    if ( a2 < 3 )
    {
      v5 = 2;
      v6 = a3;
      if ( !a3 )
      {
LABEL_14:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_sanitize_lane_cnt",
          951,
          "wrong lane_cnt configuration: expected max lane_cnt: %u received lane_cnt: %u",
          v5,
          v6);
        return 4294967274LL;
      }
LABEL_12:
      if ( v5 >= v6 )
        return 0;
      goto LABEL_14;
    }
  }
  else if ( a2 <= 2 )
  {
    v3 = *(_DWORD *)(a1 + 104LL * a2 + 624) == 0;
    v4 = 3;
LABEL_4:
    if ( v3 )
      v5 = v4 + 1;
    else
      v5 = v4;
    v6 = a3;
    if ( !a3 )
      goto LABEL_14;
    goto LABEL_12;
  }
  __break(0x5512u);
  return cam_csiphy_update_secure_info();
}
