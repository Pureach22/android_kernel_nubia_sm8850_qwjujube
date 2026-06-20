__int64 __fastcall policy_mgr_get_hw_mode_from_idx(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned __int64 v14; // x8
  int v15; // w10
  int v16; // w9
  unsigned __int64 v17; // x9
  bool v18; // zf
  unsigned __int64 v19; // x13
  unsigned int v20; // w8
  __int64 result; // x0
  const char *v22; // x2
  unsigned int v23; // w9
  unsigned int v24; // w10
  int v25; // w8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    v22 = "%s: Invalid Context";
LABEL_15:
    qdf_trace_msg(0x4Fu, 2u, v22, v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_get_hw_mode_from_idx");
    return 16;
  }
  if ( !*(_DWORD *)(comp_private_obj + 1184) )
  {
    v22 = "%s: No dbs hw modes available";
    goto LABEL_15;
  }
  v14 = 0;
  do
  {
    v15 = *(_DWORD *)(*(_QWORD *)(comp_private_obj + 1192) + 8 * v14 + 4) & 1;
    v16 = *(_DWORD *)(*(_QWORD *)(comp_private_obj + 1192) + 8 * v14) & 7;
    *(_BYTE *)(a3 + 10) = *(_BYTE *)(*(_QWORD *)(comp_private_obj + 1192) + 8 * v14 + 4) & 1;
    v18 = v16 == a2;
    v17 = *(unsigned int *)(comp_private_obj + 1184);
    v18 = !v18 && v15 == 0;
    if ( !v18 )
      break;
    ++v14;
  }
  while ( v14 < v17 );
  if ( (unsigned int)v17 <= (unsigned int)v14 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: hw mode id %d not found",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_get_hw_mode_from_idx",
      a2);
    return 16;
  }
  else
  {
    v19 = *(_QWORD *)(*(_QWORD *)(comp_private_obj + 1192) + 8 * v14);
    *(_BYTE *)(a3 + 4) = (unsigned __int16)v19 >> 12;
    *(_BYTE *)(a3 + 5) = BYTE1(v19) & 0xF;
    *(_BYTE *)(a3 + 7) = (v19 & 0x80) != 0;
    v20 = ((unsigned int)v19 >> 3) & 3;
    *(_BYTE *)(a3 + 8) = (v19 & 0x40) != 0;
    *(_BYTE *)a3 = v19 >> 28;
    *(_BYTE *)(a3 + 1) = BYTE3(v19) & 0xF;
    *(_BYTE *)(a3 + 2) = ((unsigned int)v19 >> 20) & 0xF;
    *(_BYTE *)(a3 + 3) = BYTE2(v19) & 0xF;
    *(_BYTE *)(a3 + 6) = ((unsigned int)v19 >> 3) & 3;
    *(_BYTE *)(a3 + 9) = (v19 & 0x20) != 0;
    if ( (v19 & 0x80) != 0 )
    {
      v23 = (unsigned __int8)(v19 >> 28);
      if ( (BYTE3(v19) & 0xF) < v23 )
        v23 = BYTE3(v19) & 0xF;
      if ( (((unsigned int)v19 >> 20) & 0xF) >= (WORD1(v19) & 0xF) )
        v24 = WORD1(v19) & 0xF;
      else
        v24 = ((unsigned int)v19 >> 20) & 0xF;
      if ( v23 > v24 && v24 && v20 == 2 && v23 )
      {
        result = 0;
        v25 = 10;
      }
      else if ( v23 > v24 && v24 && v20 == 1 && v23 )
      {
        result = 0;
        v25 = 12;
      }
      else
      {
        result = 0;
        v25 = 1;
      }
      *(_DWORD *)(a3 + 12) = v25;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
