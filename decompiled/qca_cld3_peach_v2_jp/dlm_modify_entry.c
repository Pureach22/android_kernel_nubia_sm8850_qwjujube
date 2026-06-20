__int64 __fastcall dlm_modify_entry(
        __int64 a1,
        __int64 a2,
        int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w4
  char v15; // w10
  int v16; // w9
  __int64 system_time; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w8
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  const char *v30; // x2
  __int64 v31; // x7
  const char *v32; // x3
  __int64 result; // x0
  int v34; // w8
  char v35; // w8
  int v36; // w9
  __int64 v37; // x9
  char v38; // w8
  const char *v39; // x21
  __int16 v40; // w9
  int v41; // w10
  int v42; // w11
  unsigned int v43; // w9
  int v44; // w4
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w8
  __int64 v54; // x9
  __int64 v55; // x10
  int v56; // w4
  unsigned int v57; // w9
  unsigned int v58; // w8
  __int64 v59; // x22
  char v60; // w10
  int v61; // w11
  char v62; // w12
  __int16 v63; // w9
  int v64; // w13
  int v65; // w11
  char v66; // w10
  int v67; // [xsp+0h] [xbp-40h]

  v11 = a3[8];
  if ( v11 > 1 )
  {
    if ( v11 != 4 )
    {
      if ( v11 != 2 )
        return qdf_trace_msg(
                 0x6Du,
                 8u,
                 "%s: Invalid input of ap type %d",
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 "dlm_modify_entry");
LABEL_7:
      result = qdf_mc_timer_get_system_time();
      v34 = a3[8];
      if ( v34 != 2 )
      {
        if ( v34 )
          return result;
        v35 = *(_BYTE *)(a1 + 104) | 4;
        v36 = *(_DWORD *)(a1 + 108) | 0x40;
        *(_BYTE *)(a1 + 104) = v35;
        *(_DWORD *)(a1 + 108) = v36;
        v37 = 56;
LABEL_66:
        *(_QWORD *)(a1 + v37) = result;
        v60 = v35 & 0xDF;
        v61 = a3[10];
        v62 = *(_BYTE *)(a1 + 48);
        *(_DWORD *)(a1 + 112) = v61;
        v63 = *((_WORD *)a3 + 2);
        v64 = *a3;
        *(_BYTE *)(a1 + 104) = v35 & 0xDF;
        *(_WORD *)(a1 + 20) = v63;
        *(_DWORD *)(a1 + 16) = v64;
        *(_BYTE *)(a1 + 48) = v62 + 1;
        if ( *(unsigned __int8 *)(a2 + 32) > (unsigned int)(unsigned __int8)(v62 + 1) )
        {
          qdf_trace_msg(
            0x6Du,
            8u,
            "%s: Added %02x:%02x:%02x:**:**:%02x to avoid list type %d, counter %d reason %d updated reject reason %d source %d",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            "dlm_handle_avoid_list",
            *(unsigned __int8 *)(a1 + 16),
            *(unsigned __int8 *)(a1 + 17),
            *(unsigned __int8 *)(a1 + 18),
            *(unsigned __int8 *)(a1 + 21),
            a3[8],
            (unsigned __int8)(v62 + 1),
            a3[9],
            *(_DWORD *)(a1 + 108),
            v61);
          result = qdf_mc_timer_get_system_time();
          *(_QWORD *)(a1 + 120) = result;
          return result;
        }
        v65 = a3[8];
        if ( v65 == 2 )
        {
          v66 = -41;
        }
        else
        {
          if ( v65 )
          {
LABEL_73:
            v27 = *(unsigned __int8 *)(a1 + 16);
            v28 = *(unsigned __int8 *)(a1 + 17);
            v29 = *(unsigned __int8 *)(a1 + 18);
            v31 = *(unsigned __int8 *)(a1 + 21);
            v30 = "%s: %02x:%02x:%02x:**:**:%02x moved to deny list with counter %d";
            *(_BYTE *)(a1 + 104) = v60 | 2;
            *(_QWORD *)(a1 + 80) = result;
            v32 = "dlm_handle_avoid_list";
            v67 = (unsigned __int8)(v62 + 1);
            return qdf_trace_msg(0x6Du, 8u, v30, v18, v19, v20, v21, v22, v23, v24, v25, v32, v27, v28, v29, v31, v67);
          }
          v66 = -37;
        }
        v60 = v35 & v66;
        goto LABEL_73;
      }
      v42 = *(_DWORD *)(a1 + 108);
      v35 = *(_BYTE *)(a1 + 104) | 8;
      *(_BYTE *)(a1 + 104) = v35;
      v43 = v42 & 0xFFFD07F8;
      v44 = a3[9];
      *(_DWORD *)(a1 + 108) = v42 & 0xFFFD07F8;
      if ( v44 > 13 )
      {
        if ( v44 <= 15 )
        {
          if ( v44 == 14 )
            *(_DWORD *)(a1 + 108) = v43 | 0x20000;
          else
            *(_DWORD *)(a1 + 108) = v43 | 0x8000;
          goto LABEL_65;
        }
        switch ( v44 )
        {
          case 16:
            *(_DWORD *)(a1 + 108) = v43 | 0x2000;
            goto LABEL_65;
          case 17:
            *(_DWORD *)(a1 + 108) = v43 | 0x4000;
            goto LABEL_65;
          case 19:
            *(_DWORD *)(a1 + 108) = v42 & 0xFFFC07F8 | 0x10000;
            goto LABEL_65;
        }
      }
      else if ( v44 <= 2 )
      {
        if ( v44 == 1 )
        {
          *(_DWORD *)(a1 + 108) = v43 | 1;
          goto LABEL_65;
        }
        if ( v44 == 2 )
        {
          *(_DWORD *)(a1 + 108) = v43 | 2;
          goto LABEL_65;
        }
      }
      else
      {
        switch ( v44 )
        {
          case 3:
            *(_DWORD *)(a1 + 108) = v43 | 4;
            goto LABEL_65;
          case 12:
            *(_DWORD *)(a1 + 108) = v43 | 0x800;
            goto LABEL_65;
          case 13:
            *(_DWORD *)(a1 + 108) = v43 | 0x1000;
LABEL_65:
            v37 = 64;
            goto LABEL_66;
        }
      }
      v59 = result;
      qdf_trace_msg(
        0x6Du,
        2u,
        "%s: Invalid reason passed %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "dlm_update_avoidlist_reject_reason");
      v35 = *(_BYTE *)(a1 + 104);
      result = v59;
      goto LABEL_65;
    }
    v38 = *(_BYTE *)(a1 + 104);
    if ( (v38 & 0x10) != 0 )
    {
      v39 = "UPDATED";
    }
    else
    {
      v39 = "ADDED";
      *(_DWORD *)(a1 + 44) = a3[10];
      v40 = *((_WORD *)a3 + 2);
      v41 = *a3;
      *(_BYTE *)(a1 + 104) = v38 | 0x10;
      *(_WORD *)(a1 + 20) = v40;
      *(_DWORD *)(a1 + 16) = v41;
    }
    *(_QWORD *)(a1 + 88) = qdf_mc_timer_get_system_time();
    v53 = *(_DWORD *)(a1 + 108);
    v55 = *((_QWORD *)a3 + 2);
    v54 = *((_QWORD *)a3 + 3);
    *(_QWORD *)(a1 + 24) = *((_QWORD *)a3 + 1);
    *(_QWORD *)(a1 + 32) = v55;
    *(_QWORD *)(a1 + 40) = v54;
    v56 = a3[9];
    v57 = v53 & 0xFFFFF067;
    *(_DWORD *)(a1 + 108) = v53 & 0xFFFFF067;
    if ( v56 > 11 )
    {
      if ( v56 <= 14 )
      {
        if ( v56 == 12 )
        {
          v58 = v57 | 0x800;
          *(_DWORD *)(a1 + 108) = v57 | 0x800;
        }
        else
        {
          if ( v56 == 13 )
            v58 = v53 & 0xFFFFE067 | 0x1000;
          else
            v58 = v53 & 0xFFFDF067 | 0x20000;
          *(_DWORD *)(a1 + 108) = v58;
        }
        return qdf_trace_msg(
                 0x6Du,
                 4u,
                 "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origina"
                 "l timeout %u received time %lu reject reason %d updated reason %d",
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 v50,
                 v51,
                 v52,
                 "dlm_handle_rssi_reject_list",
                 *(unsigned __int8 *)(a1 + 16),
                 *(unsigned __int8 *)(a1 + 17),
                 *(unsigned __int8 *)(a1 + 18),
                 *(unsigned __int8 *)(a1 + 21),
                 v39,
                 *(char *)(a1 + 28),
                 *(_DWORD *)(a1 + 24),
                 *(_DWORD *)(a1 + 44),
                 *(_DWORD *)(a1 + 40),
                 *(_QWORD *)(a1 + 32),
                 a3[9],
                 v58);
      }
      switch ( v56 )
      {
        case 15:
          v58 = v53 & 0xFFFF7067 | 0x8000;
          *(_DWORD *)(a1 + 108) = v58;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v45,
                   v46,
                   v47,
                   v48,
                   v49,
                   v50,
                   v51,
                   v52,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v39,
                   *(char *)(a1 + 28),
                   *(_DWORD *)(a1 + 24),
                   *(_DWORD *)(a1 + 44),
                   *(_DWORD *)(a1 + 40),
                   *(_QWORD *)(a1 + 32),
                   a3[9],
                   v58);
        case 16:
          v58 = v53 & 0xFFFFD067 | 0x2000;
          *(_DWORD *)(a1 + 108) = v58;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v45,
                   v46,
                   v47,
                   v48,
                   v49,
                   v50,
                   v51,
                   v52,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v39,
                   *(char *)(a1 + 28),
                   *(_DWORD *)(a1 + 24),
                   *(_DWORD *)(a1 + 44),
                   *(_DWORD *)(a1 + 40),
                   *(_QWORD *)(a1 + 32),
                   a3[9],
                   v58);
        case 17:
          v58 = v53 & 0xFFFFB067 | 0x4000;
          *(_DWORD *)(a1 + 108) = v58;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v45,
                   v46,
                   v47,
                   v48,
                   v49,
                   v50,
                   v51,
                   v52,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v39,
                   *(char *)(a1 + 28),
                   *(_DWORD *)(a1 + 24),
                   *(_DWORD *)(a1 + 44),
                   *(_DWORD *)(a1 + 40),
                   *(_QWORD *)(a1 + 32),
                   a3[9],
                   v58);
      }
    }
    else
    {
      if ( v56 > 8 )
      {
        if ( v56 == 9 )
        {
          v58 = v57 | 0x100;
          *(_DWORD *)(a1 + 108) = v57 | 0x100;
        }
        else if ( v56 == 10 )
        {
          v58 = v57 | 0x200;
          *(_DWORD *)(a1 + 108) = v57 | 0x200;
        }
        else
        {
          v58 = v57 | 0x400;
          *(_DWORD *)(a1 + 108) = v57 | 0x400;
        }
        return qdf_trace_msg(
                 0x6Du,
                 4u,
                 "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origina"
                 "l timeout %u received time %lu reject reason %d updated reason %d",
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 v50,
                 v51,
                 v52,
                 "dlm_handle_rssi_reject_list",
                 *(unsigned __int8 *)(a1 + 16),
                 *(unsigned __int8 *)(a1 + 17),
                 *(unsigned __int8 *)(a1 + 18),
                 *(unsigned __int8 *)(a1 + 21),
                 v39,
                 *(char *)(a1 + 28),
                 *(_DWORD *)(a1 + 24),
                 *(_DWORD *)(a1 + 44),
                 *(_DWORD *)(a1 + 40),
                 *(_QWORD *)(a1 + 32),
                 a3[9],
                 v58);
      }
      switch ( v56 )
      {
        case 4:
          v58 = v57 | 8;
          *(_DWORD *)(a1 + 108) = v57 | 8;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v45,
                   v46,
                   v47,
                   v48,
                   v49,
                   v50,
                   v51,
                   v52,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v39,
                   *(char *)(a1 + 28),
                   *(_DWORD *)(a1 + 24),
                   *(_DWORD *)(a1 + 44),
                   *(_DWORD *)(a1 + 40),
                   *(_QWORD *)(a1 + 32),
                   a3[9],
                   v58);
        case 5:
          v58 = v57 | 0x10;
          *(_DWORD *)(a1 + 108) = v57 | 0x10;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v45,
                   v46,
                   v47,
                   v48,
                   v49,
                   v50,
                   v51,
                   v52,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v39,
                   *(char *)(a1 + 28),
                   *(_DWORD *)(a1 + 24),
                   *(_DWORD *)(a1 + 44),
                   *(_DWORD *)(a1 + 40),
                   *(_QWORD *)(a1 + 32),
                   a3[9],
                   v58);
        case 8:
          v58 = v57 | 0x80;
          *(_DWORD *)(a1 + 108) = v57 | 0x80;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v45,
                   v46,
                   v47,
                   v48,
                   v49,
                   v50,
                   v51,
                   v52,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v39,
                   *(char *)(a1 + 28),
                   *(_DWORD *)(a1 + 24),
                   *(_DWORD *)(a1 + 44),
                   *(_DWORD *)(a1 + 40),
                   *(_QWORD *)(a1 + 32),
                   a3[9],
                   v58);
      }
    }
    qdf_trace_msg(
      0x6Du,
      2u,
      "%s: Invalid reason passed %d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "dlm_update_rssi_reject_reason");
    v58 = *(_DWORD *)(a1 + 108);
    return qdf_trace_msg(
             0x6Du,
             4u,
             "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d original ti"
             "meout %u received time %lu reject reason %d updated reason %d",
             v45,
             v46,
             v47,
             v48,
             v49,
             v50,
             v51,
             v52,
             "dlm_handle_rssi_reject_list",
             *(unsigned __int8 *)(a1 + 16),
             *(unsigned __int8 *)(a1 + 17),
             *(unsigned __int8 *)(a1 + 18),
             *(unsigned __int8 *)(a1 + 21),
             v39,
             *(char *)(a1 + 28),
             *(_DWORD *)(a1 + 24),
             *(_DWORD *)(a1 + 44),
             *(_DWORD *)(a1 + 40),
             *(_QWORD *)(a1 + 32),
             a3[9],
             v58);
  }
  if ( !v11 )
    goto LABEL_7;
  if ( v11 != 1 )
    return qdf_trace_msg(
             0x6Du,
             8u,
             "%s: Invalid input of ap type %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "dlm_modify_entry");
  v15 = *(_BYTE *)(a1 + 104);
  v16 = *a3;
  *(_WORD *)(a1 + 20) = *((_WORD *)a3 + 2);
  *(_DWORD *)(a1 + 16) = v16;
  *(_BYTE *)(a1 + 104) = v15 | 1;
  system_time = qdf_mc_timer_get_system_time();
  v26 = *(_DWORD *)(a1 + 108);
  v27 = *(unsigned __int8 *)(a1 + 16);
  v28 = *(unsigned __int8 *)(a1 + 17);
  v29 = *(unsigned __int8 *)(a1 + 18);
  v30 = "%s: %02x:%02x:%02x:**:**:%02x added to userspace denylist";
  v31 = *(unsigned __int8 *)(a1 + 21);
  *(_QWORD *)(a1 + 72) = system_time;
  v32 = "dlm_handle_denylist";
  *(_DWORD *)(a1 + 108) = v26 | 0x20;
  *(_DWORD *)(a1 + 112) = 1;
  return qdf_trace_msg(0x6Du, 8u, v30, v18, v19, v20, v21, v22, v23, v24, v25, v32, v27, v28, v29, v31, v67);
}
