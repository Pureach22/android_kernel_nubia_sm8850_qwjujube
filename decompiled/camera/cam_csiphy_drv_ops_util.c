__int64 __fastcall cam_csiphy_drv_ops_util(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v5; // x20
  unsigned __int64 v6; // x19
  __int64 v7; // x6
  int v8; // w8
  const char *v9; // x5
  __int64 v10; // x4
  const char *v11; // x9
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x20
  char v15; // [xsp+24h] [xbp-Ch]
  __int64 v16; // [xsp+28h] [xbp-8h]

  if ( *(_BYTE *)(a2 + 4112) == 1 && *(_BYTE *)(a3 + 88) == 1 && *(_BYTE *)(a3 + 89) == 1 )
  {
    v4 = *(unsigned int *)(a3 + 84);
    if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
    {
      v11 = "HALT";
      if ( *(_DWORD *)(a4 + 8) != 1 )
        v11 = "RESUME";
      v16 = a2;
      v15 = result;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        (unsigned __int16)debug_mdl & 0x8000,
        4,
        "cam_csiphy_drv_ops_util",
        168,
        "PHY: %d, CSID: %d DRV info : use hw client %d, enable drv config %d, op=%s",
        *(_DWORD *)(a2 + 932),
        v4,
        1,
        1,
        v11);
      a2 = v16;
      if ( (v15 & 1) != 0 )
      {
LABEL_7:
        if ( (unsigned int)v4 < 3 )
        {
          v5 = a2;
          v6 = *(_QWORD *)(a2 + 16 * v4 + 3720);
          result = cam_soc_util_set_src_clk_rate(a2 + 912, 0xFFFFFFFF, v6, 0);
          if ( !(_DWORD)result )
            return result;
          v7 = *(unsigned int *)(v5 + 932);
          v8 = result;
          v9 = "PHY[%d] CSID HALT: csiphy set_rate %ld failed rc: %d";
          v10 = 177;
          return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, int))cam_print_log)(
                   3,
                   0x8000,
                   1,
                   "cam_csiphy_drv_ops_util",
                   v10,
                   v9,
                   v7,
                   v6,
                   v8);
        }
        goto LABEL_19;
      }
    }
    else if ( (result & 1) != 0 )
    {
      goto LABEL_7;
    }
    v12 = *(unsigned int *)(a2 + 3784);
    if ( (unsigned int)v12 <= 9 )
    {
      v13 = *(unsigned int *)(a2 + 3708);
      if ( (unsigned int)v13 <= 0x1F )
      {
        v14 = a2;
        v6 = *(int *)(a2 + (v12 << 7) + 4 * v13 + 2296);
        result = cam_soc_util_set_src_clk_rate(a2 + 912, 0xFFFFFFFF, v6, 0);
        if ( !(_DWORD)result )
          return result;
        v7 = *(unsigned int *)(v14 + 932);
        v8 = result;
        v9 = "PHY[%d] CSID RESUME: csiphy _set_rate %ld failed rc: %d";
        v10 = 188;
        return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, int))cam_print_log)(
                 3,
                 0x8000,
                 1,
                 "cam_csiphy_drv_ops_util",
                 v10,
                 v9,
                 v7,
                 v6,
                 v8);
      }
    }
LABEL_19:
    __break(0x5512u);
    JUMPOUT(0x279EB8);
  }
  return result;
}
