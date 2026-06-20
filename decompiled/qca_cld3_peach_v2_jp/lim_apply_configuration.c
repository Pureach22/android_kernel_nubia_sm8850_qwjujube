_QWORD *__fastcall lim_apply_configuration(
        _QWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int *v10; // x9
  int v11; // w8
  unsigned int v14; // w21
  __int64 v15; // x22
  char v16; // w10
  int v17; // w11
  char v18; // w9
  bool v19; // zf
  char v20; // w8
  double short_slot_from_phy_mode; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _QWORD *result; // x0

  *(_BYTE *)(a2 + 179) = 0;
  v10 = (unsigned int *)(a2 + 7232);
  v11 = *(_DWORD *)(a2 + 88);
  if ( !a2 )
    v10 = (unsigned int *)(a1 + 605);
  v14 = *v10;
  v15 = a2 + 4096;
  *(_BYTE *)(a2 + 7160) = *(_BYTE *)(a1[1] + 1278LL);
  if ( v11 == 1 )
  {
    v16 = *(_BYTE *)(a2 + 7024) & 0xFD | (2 * *(_BYTE *)(a1[1] + 5453LL));
    *(_BYTE *)(a2 + 7024) = v16;
  }
  else
  {
    v16 = *(_BYTE *)(a2 + 7024);
  }
  v17 = *(unsigned __int8 *)(a1[1] + 5455LL);
  v18 = v16 & 0xFB | (4 * (v17 & 1));
  *(_BYTE *)(a2 + 7024) = v18;
  if ( (v16 & 2) == 0 && v17 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: Can't enable WSM without WME", a3, a4, a5, a6, a7, a8, a9, a10, "lim_update_config");
    v18 = *(_BYTE *)(v15 + 2928) & 0xFB;
    v11 = *(_DWORD *)(a2 + 88);
    *(_BYTE *)(v15 + 2928) = v18;
  }
  if ( v11 == 1 )
  {
    v18 = *(_BYTE *)(a1[1] + 5452LL) | v18 & 0xFE;
    *(_BYTE *)(v15 + 2928) = v18;
  }
  v19 = (v18 & 4) != 0 && v11 == 1;
  v20 = v18 | 8;
  if ( !v19 )
    v20 = v18 & 0xF7 | (8 * *(_BYTE *)(a1[1] + 5385LL));
  *(_BYTE *)(v15 + 2928) = v20;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Updated Lim shadow state based on CFG",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_update_config");
  short_slot_from_phy_mode = lim_get_short_slot_from_phy_mode(a1, a2, v14, a2 + 250);
  result = lim_set_cfg_protection(a1, a2, short_slot_from_phy_mode, v22, v23, v24, v25, v26, v27, v28);
  if ( *(_DWORD *)(a2 + 88) == 1 && !*(_WORD *)(a2 + 248) )
  {
    sch_set_beacon_interval(a1, a2);
    return (_QWORD *)((__int64 (__fastcall *)(_QWORD *, __int64))sch_set_fixed_beacon_fields)(a1, a2);
  }
  return result;
}
