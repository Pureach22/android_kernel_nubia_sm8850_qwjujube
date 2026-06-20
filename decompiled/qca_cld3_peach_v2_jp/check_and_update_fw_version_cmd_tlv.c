__int64 __fastcall check_and_update_fw_version_cmd_tlv(unsigned int *a1, __int64 a2)
{
  _DWORD *v2; // x20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v13; // w9
  unsigned int v14; // [xsp+0h] [xbp-40h]
  unsigned int v15; // [xsp+8h] [xbp-38h]
  unsigned int v16; // [xsp+10h] [xbp-30h]
  int v17; // [xsp+18h] [xbp-28h]
  int v18; // [xsp+20h] [xbp-20h]
  int v19; // [xsp+28h] [xbp-18h]
  int v20; // [xsp+30h] [xbp-10h]
  int v21; // [xsp+38h] [xbp-8h]

  v2 = *(_DWORD **)a2;
  if ( wmi_versions_are_compatible(a1 + 74, (_DWORD *)(*(_QWORD *)a2 + 4LL)) )
  {
    qdf_mem_copy(a1 + 74, v2 + 1, 0x18u);
    qdf_mem_copy(a1 + 68, v2 + 1, 0x18u);
    return 0;
  }
  else
  {
    v13 = v2[1];
    v21 = v2[6];
    v20 = v2[5];
    v19 = v2[4];
    v18 = v2[3];
    v17 = v13 & 0xFFFFFF;
    v16 = HIBYTE(v13);
    v15 = a1[79];
    v14 = a1[78];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Error: Incompatible WMI version.Host: %d,%d,0x%x 0x%x 0x%x 0x%x, FW: %d,%d,0x%x 0x%x 0x%x 0x%x",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "check_and_update_fw_version_cmd_tlv",
      HIBYTE(a1[74]),
      a1[74] & 0xFFFFFF,
      a1[76],
      a1[77],
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21);
    return 16;
  }
}
