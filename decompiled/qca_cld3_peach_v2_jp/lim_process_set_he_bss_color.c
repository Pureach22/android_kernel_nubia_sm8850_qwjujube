__int64 __fastcall lim_process_set_he_bss_color(
        __int64 a1,
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
  __int64 session_by_vdev_id; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  const char *v22; // x2
  const char *v23; // x2
  __int64 result; // x0
  char v25; // w8
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 cmpt_obj; // x0
  __int64 v36; // [xsp+8h] [xbp-28h] BYREF
  __int64 v37; // [xsp+10h] [xbp-20h]
  __int64 v38; // [xsp+18h] [xbp-18h]
  int v39; // [xsp+20h] [xbp-10h]
  __int64 v40; // [xsp+28h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v37 = 0;
  v38 = 0;
  v36 = 0;
  if ( a2 )
  {
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a2 + 4));
    if ( !session_by_vdev_id )
    {
      v22 = "%s: Session not found for given vdev_id %d";
      goto LABEL_16;
    }
    v21 = session_by_vdev_id;
    if ( *(_BYTE *)(session_by_vdev_id + 70) && *(_DWORD *)(session_by_vdev_id + 88) != 1 )
    {
      v22 = "%s: Invalid SystemRole %d";
      goto LABEL_16;
    }
    if ( *(_BYTE *)(a2 + 5) == (*(_BYTE *)(session_by_vdev_id + 8745) & 0x3F) )
    {
      v22 = "%s: No change in  BSS color, current BSS color %d";
LABEL_16:
      result = qdf_trace_msg(0x35u, 2u, v22, v13, v14, v15, v16, v17, v18, v19, v20, "lim_process_set_he_bss_color");
      goto LABEL_17;
    }
    qdf_mem_set(&v36, 0x1Cu, 0);
    HIWORD(v37) |= 0x800u;
    v25 = *(_BYTE *)(v21 + 8745);
    *(_BYTE *)(v21 + 8766) = 10;
    *(_BYTE *)(v21 + 8745) = v25 | 0x80;
    *(_BYTE *)(v21 + 8767) = *(_BYTE *)(v21 + 8767) & 0xC0 | *(_BYTE *)(a2 + 5) & 0x3F;
    LOBYTE(v39) = 1;
    HIDWORD(v38) = v25 & 0x3F;
    v26 = *(_QWORD *)(v21 + 16);
    *(_BYTE *)(v21 + 9776) = 1;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v26, v27, v28, v29, v30, v31, v32, v33, v34);
    if ( cmpt_obj && *(_BYTE *)(cmpt_obj + 186) == 1 )
      wlan_spatial_reuse_config_set(*(_QWORD *)(v21 + 16), 0, 0);
    if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64))sch_set_fixed_beacon_fields)(a1, v21) )
    {
      lim_send_beacon_params(a1, &v36, v21);
      result = lim_send_obss_color_collision_cfg(a1, v21, 0);
      goto LABEL_17;
    }
    v23 = "%s: Unable to set op mode IE in beacon";
  }
  else
  {
    v23 = "%s: Buffer is Pointing to NULL";
  }
  result = qdf_trace_msg(0x35u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_set_he_bss_color");
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
