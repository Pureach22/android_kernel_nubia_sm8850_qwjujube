__int64 __fastcall cam_ife_csid_ver2_rdi_lcr_cfg(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x8
  int v6; // w8
  const char *v7; // x5
  __int64 v8; // x7
  __int64 v9; // x6
  __int64 v10; // x4
  unsigned int v11; // w8
  __int64 v13; // x21
  __int64 v14; // x22
  char v15; // w9
  int v16; // [xsp+0h] [xbp-10h]
  int v17; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_rdi_lcr_cfg",
      8638,
      "Invalid params");
    return (unsigned int)-22;
  }
  v2 = *(unsigned int *)(a2 + 4);
  if ( (unsigned int)v2 < 0xC )
  {
    v3 = *(_QWORD *)(a2 + 24);
    if ( v3
      && (v4 = **(_QWORD **)(a1 + 31136), (v5 = *(_QWORD *)(v4 + 8 * v2 + 136)) != 0)
      && (v6 = *(_DWORD *)(v5 + 584), (v6 & 1) != 0) )
    {
      if ( !(_DWORD)v2 || (*(_BYTE *)(v3 + 250) & 1) != 0 )
      {
        if ( !*(_DWORD *)(v3 + 52) )
        {
          if ( (*(_BYTE *)(v3 + 252) & 1) == 0 )
          {
            v13 = a1;
            v14 = a2;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              2,
              "cam_ife_csid_ver2_rdi_lcr_cfg",
              8679,
              "CSID[%u] [%s] Input data to LCR is in LSB, in_format %d out_format %d",
              *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
              (const char *)(a2 + 128),
              *(_DWORD *)(v3 + 124),
              *(_DWORD *)(v3 + 140));
            a1 = v13;
            a2 = v14;
          }
          if ( *(_BYTE *)(a1 + 2160) == 1 )
            *(_DWORD *)(a1 + 2060) |= 1LL << *(_DWORD *)(a2 + 4) << *(_DWORD *)(*(_QWORD *)(v4 + 232) + 88LL);
          v11 = 0;
          v15 = debug_mdl;
          *(_BYTE *)(a1 + 2159) = 1;
          *(_BYTE *)(v3 + 251) = 1;
          if ( (v15 & 8) != 0 && !debug_priority )
          {
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v15 & 8,
              4,
              "cam_ife_csid_ver2_rdi_lcr_cfg",
              8689,
              "CSID[%u] %s top_cfg %u",
              *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
              (const char *)(a2 + 128),
              *(_DWORD *)(a1 + 2060));
            return 0;
          }
          return v11;
        }
        v7 = "CSID[%u] [%s] LCR not supported in_format %d out_format %d";
        v9 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
        v6 = *(_DWORD *)(v3 + 124);
        v17 = *(_DWORD *)(v3 + 140);
        v8 = a2 + 128;
        v10 = 8669;
      }
      else
      {
        v7 = "CSID[%u] Invalid res: %s, capabilities 0x%x sfe_shdr: %u";
        v8 = a2 + 128;
        v9 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
        v10 = 8657;
        v17 = 0;
      }
      v16 = v6;
    }
    else
    {
      v7 = "CSID[%u] Invalid res %s";
      v8 = a2 + 128;
      v9 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
      v10 = 8650;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, int))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_rdi_lcr_cfg",
      v10,
      v7,
      v9,
      v8,
      v16,
      v17);
    return (unsigned int)-22;
  }
  __break(0x5512u);
  return cam_ife_csid_init_config_update(a1, a2);
}
