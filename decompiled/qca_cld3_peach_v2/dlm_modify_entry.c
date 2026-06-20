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
  char v14; // w10
  int v15; // w9
  __int64 system_time; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  const char *v29; // x2
  __int64 v30; // x7
  const char *v31; // x3
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w8
  __int64 v43; // x21
  int v44; // w9
  __int64 v45; // x8
  char v46; // w8
  const char *v47; // x21
  __int16 v48; // w9
  int v49; // w10
  int v50; // w10
  int v51; // w4
  unsigned int v52; // w8
  int v53; // w8
  int v54; // w10
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w8
  __int64 v64; // x9
  __int64 v65; // x10
  int v66; // w4
  unsigned int v67; // w9
  unsigned int v68; // w8
  int v69; // w8
  int v70; // w10
  int v71; // w9
  char v72; // w11
  char v73; // w12
  char v74; // w10
  __int16 v75; // w8
  int v76; // w13
  int v77; // w9
  char v78; // w9
  int v79; // [xsp+0h] [xbp-40h]

  v11 = a3[22];
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
      v42 = a3[22];
      v43 = result;
      if ( v42 != 2 )
      {
        if ( v42 )
          return result;
        v44 = *(_DWORD *)(a1 + 140) | 0x40;
        *(_BYTE *)(a1 + 136) |= 4u;
        v45 = 88;
        *(_DWORD *)(a1 + 140) = v44;
LABEL_66:
        *(_QWORD *)(a1 + v45) = v43;
        v69 = *((unsigned __int8 *)a3 + 56);
        *(_BYTE *)(a1 + 48) = v69;
        *(_BYTE *)(a1 + 49) = *((_BYTE *)a3 + 57);
        v70 = a3[2];
        *(_WORD *)(a1 + 26) = *((_WORD *)a3 + 6);
        *(_DWORD *)(a1 + 22) = v70;
        qdf_mem_copy((void *)(a1 + 28), a3 + 4, (unsigned int)(2 * v69));
        v71 = a3[24];
        v72 = *(_BYTE *)(a1 + 136);
        v73 = *(_BYTE *)(a1 + 80);
        *(_DWORD *)(a1 + 144) = v71;
        v74 = v72 & 0xDF;
        v75 = *((_WORD *)a3 + 2);
        v76 = *a3;
        *(_BYTE *)(a1 + 136) = v72 & 0xDF;
        *(_WORD *)(a1 + 20) = v75;
        *(_DWORD *)(a1 + 16) = v76;
        *(_BYTE *)(a1 + 80) = v73 + 1;
        if ( *(unsigned __int8 *)(a2 + 32) > (unsigned int)(unsigned __int8)(v73 + 1) )
        {
          qdf_trace_msg(
            0x6Du,
            8u,
            "%s: Added %02x:%02x:%02x:**:**:%02x to avoid list type %d, counter %d reason %d updated reject reason %d source %d",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "dlm_handle_avoid_list",
            *(unsigned __int8 *)(a1 + 16),
            *(unsigned __int8 *)(a1 + 17),
            *(unsigned __int8 *)(a1 + 18),
            *(unsigned __int8 *)(a1 + 21),
            a3[22],
            (unsigned __int8)(v73 + 1),
            a3[23],
            *(_DWORD *)(a1 + 140),
            v71);
          result = qdf_mc_timer_get_system_time();
          *(_QWORD *)(a1 + 152) = result;
          return result;
        }
        v77 = a3[22];
        if ( v77 == 2 )
        {
          v78 = -41;
        }
        else
        {
          if ( v77 )
          {
LABEL_73:
            v26 = *(unsigned __int8 *)(a1 + 16);
            v27 = *(unsigned __int8 *)(a1 + 17);
            v28 = *(unsigned __int8 *)(a1 + 18);
            v30 = *(unsigned __int8 *)(a1 + 21);
            v29 = "%s: %02x:%02x:%02x:**:**:%02x moved to deny list with counter %d";
            v31 = "dlm_handle_avoid_list";
            *(_BYTE *)(a1 + 136) = v74 | 2;
            *(_QWORD *)(a1 + 112) = v43;
            v79 = (unsigned __int8)(v73 + 1);
            return qdf_trace_msg(0x6Du, 8u, v29, v17, v18, v19, v20, v21, v22, v23, v24, v31, v26, v27, v28, v30, v79);
          }
          v78 = -37;
        }
        v74 = v72 & v78;
        goto LABEL_73;
      }
      v50 = *(_DWORD *)(a1 + 140);
      *(_BYTE *)(a1 + 136) |= 8u;
      v51 = a3[23];
      v52 = v50 & 0xFFFD07F8;
      *(_DWORD *)(a1 + 140) = v50 & 0xFFFD07F8;
      if ( v51 > 13 )
      {
        if ( v51 <= 15 )
        {
          if ( v51 == 14 )
            *(_DWORD *)(a1 + 140) = v52 | 0x20000;
          else
            *(_DWORD *)(a1 + 140) = v52 | 0x8000;
          goto LABEL_65;
        }
        switch ( v51 )
        {
          case 16:
            *(_DWORD *)(a1 + 140) = v52 | 0x2000;
            goto LABEL_65;
          case 17:
            *(_DWORD *)(a1 + 140) = v52 | 0x4000;
            goto LABEL_65;
          case 19:
            *(_DWORD *)(a1 + 140) = v50 & 0xFFFC07F8 | 0x10000;
            goto LABEL_65;
        }
      }
      else if ( v51 <= 2 )
      {
        if ( v51 == 1 )
        {
          *(_DWORD *)(a1 + 140) = v52 | 1;
          goto LABEL_65;
        }
        if ( v51 == 2 )
        {
          *(_DWORD *)(a1 + 140) = v52 | 2;
          goto LABEL_65;
        }
      }
      else
      {
        switch ( v51 )
        {
          case 3:
            *(_DWORD *)(a1 + 140) = v52 | 4;
            goto LABEL_65;
          case 12:
            *(_DWORD *)(a1 + 140) = v52 | 0x800;
            goto LABEL_65;
          case 13:
            *(_DWORD *)(a1 + 140) = v52 | 0x1000;
LABEL_65:
            v45 = 96;
            goto LABEL_66;
        }
      }
      qdf_trace_msg(
        0x6Du,
        2u,
        "%s: Invalid reason passed %d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "dlm_update_avoidlist_reject_reason");
      goto LABEL_65;
    }
    v46 = *(_BYTE *)(a1 + 136);
    if ( (v46 & 0x10) != 0 )
    {
      v47 = "UPDATED";
    }
    else
    {
      v47 = "ADDED";
      *(_DWORD *)(a1 + 76) = a3[24];
      v48 = *((_WORD *)a3 + 2);
      v49 = *a3;
      *(_BYTE *)(a1 + 136) = v46 | 0x10;
      *(_WORD *)(a1 + 20) = v48;
      *(_DWORD *)(a1 + 16) = v49;
    }
    v53 = *((unsigned __int8 *)a3 + 56);
    *(_BYTE *)(a1 + 48) = v53;
    *(_BYTE *)(a1 + 49) = *((_BYTE *)a3 + 57);
    v54 = a3[2];
    *(_WORD *)(a1 + 26) = *((_WORD *)a3 + 6);
    *(_DWORD *)(a1 + 22) = v54;
    qdf_mem_copy((void *)(a1 + 28), a3 + 4, (unsigned int)(2 * v53));
    *(_QWORD *)(a1 + 120) = qdf_mc_timer_get_system_time();
    v63 = *(_DWORD *)(a1 + 140);
    v65 = *((_QWORD *)a3 + 9);
    v64 = *((_QWORD *)a3 + 10);
    *(_QWORD *)(a1 + 56) = *((_QWORD *)a3 + 8);
    *(_QWORD *)(a1 + 64) = v65;
    *(_QWORD *)(a1 + 72) = v64;
    v66 = a3[23];
    v67 = v63 & 0xFFFFF067;
    *(_DWORD *)(a1 + 140) = v63 & 0xFFFFF067;
    if ( v66 > 11 )
    {
      if ( v66 <= 14 )
      {
        if ( v66 == 12 )
        {
          v68 = v67 | 0x800;
          *(_DWORD *)(a1 + 140) = v67 | 0x800;
        }
        else
        {
          if ( v66 == 13 )
            v68 = v63 & 0xFFFFE067 | 0x1000;
          else
            v68 = v63 & 0xFFFDF067 | 0x20000;
          *(_DWORD *)(a1 + 140) = v68;
        }
        return qdf_trace_msg(
                 0x6Du,
                 4u,
                 "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origina"
                 "l timeout %u received time %lu reject reason %d updated reason %d",
                 v55,
                 v56,
                 v57,
                 v58,
                 v59,
                 v60,
                 v61,
                 v62,
                 "dlm_handle_rssi_reject_list",
                 *(unsigned __int8 *)(a1 + 16),
                 *(unsigned __int8 *)(a1 + 17),
                 *(unsigned __int8 *)(a1 + 18),
                 *(unsigned __int8 *)(a1 + 21),
                 v47,
                 *(char *)(a1 + 60),
                 *(_DWORD *)(a1 + 56),
                 *(_DWORD *)(a1 + 76),
                 *(_DWORD *)(a1 + 72),
                 *(_QWORD *)(a1 + 64),
                 a3[23],
                 v68);
      }
      switch ( v66 )
      {
        case 15:
          v68 = v63 & 0xFFFF7067 | 0x8000;
          *(_DWORD *)(a1 + 140) = v68;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v55,
                   v56,
                   v57,
                   v58,
                   v59,
                   v60,
                   v61,
                   v62,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v47,
                   *(char *)(a1 + 60),
                   *(_DWORD *)(a1 + 56),
                   *(_DWORD *)(a1 + 76),
                   *(_DWORD *)(a1 + 72),
                   *(_QWORD *)(a1 + 64),
                   a3[23],
                   v68);
        case 16:
          v68 = v63 & 0xFFFFD067 | 0x2000;
          *(_DWORD *)(a1 + 140) = v68;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v55,
                   v56,
                   v57,
                   v58,
                   v59,
                   v60,
                   v61,
                   v62,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v47,
                   *(char *)(a1 + 60),
                   *(_DWORD *)(a1 + 56),
                   *(_DWORD *)(a1 + 76),
                   *(_DWORD *)(a1 + 72),
                   *(_QWORD *)(a1 + 64),
                   a3[23],
                   v68);
        case 17:
          v68 = v63 & 0xFFFFB067 | 0x4000;
          *(_DWORD *)(a1 + 140) = v68;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v55,
                   v56,
                   v57,
                   v58,
                   v59,
                   v60,
                   v61,
                   v62,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v47,
                   *(char *)(a1 + 60),
                   *(_DWORD *)(a1 + 56),
                   *(_DWORD *)(a1 + 76),
                   *(_DWORD *)(a1 + 72),
                   *(_QWORD *)(a1 + 64),
                   a3[23],
                   v68);
      }
    }
    else
    {
      if ( v66 > 8 )
      {
        if ( v66 == 9 )
        {
          v68 = v67 | 0x100;
          *(_DWORD *)(a1 + 140) = v67 | 0x100;
        }
        else if ( v66 == 10 )
        {
          v68 = v67 | 0x200;
          *(_DWORD *)(a1 + 140) = v67 | 0x200;
        }
        else
        {
          v68 = v67 | 0x400;
          *(_DWORD *)(a1 + 140) = v67 | 0x400;
        }
        return qdf_trace_msg(
                 0x6Du,
                 4u,
                 "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origina"
                 "l timeout %u received time %lu reject reason %d updated reason %d",
                 v55,
                 v56,
                 v57,
                 v58,
                 v59,
                 v60,
                 v61,
                 v62,
                 "dlm_handle_rssi_reject_list",
                 *(unsigned __int8 *)(a1 + 16),
                 *(unsigned __int8 *)(a1 + 17),
                 *(unsigned __int8 *)(a1 + 18),
                 *(unsigned __int8 *)(a1 + 21),
                 v47,
                 *(char *)(a1 + 60),
                 *(_DWORD *)(a1 + 56),
                 *(_DWORD *)(a1 + 76),
                 *(_DWORD *)(a1 + 72),
                 *(_QWORD *)(a1 + 64),
                 a3[23],
                 v68);
      }
      switch ( v66 )
      {
        case 4:
          v68 = v67 | 8;
          *(_DWORD *)(a1 + 140) = v67 | 8;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v55,
                   v56,
                   v57,
                   v58,
                   v59,
                   v60,
                   v61,
                   v62,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v47,
                   *(char *)(a1 + 60),
                   *(_DWORD *)(a1 + 56),
                   *(_DWORD *)(a1 + 76),
                   *(_DWORD *)(a1 + 72),
                   *(_QWORD *)(a1 + 64),
                   a3[23],
                   v68);
        case 5:
          v68 = v67 | 0x10;
          *(_DWORD *)(a1 + 140) = v67 | 0x10;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v55,
                   v56,
                   v57,
                   v58,
                   v59,
                   v60,
                   v61,
                   v62,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v47,
                   *(char *)(a1 + 60),
                   *(_DWORD *)(a1 + 56),
                   *(_DWORD *)(a1 + 76),
                   *(_DWORD *)(a1 + 72),
                   *(_QWORD *)(a1 + 64),
                   a3[23],
                   v68);
        case 8:
          v68 = v67 | 0x80;
          *(_DWORD *)(a1 + 140) = v67 | 0x80;
          return qdf_trace_msg(
                   0x6Du,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d origi"
                   "nal timeout %u received time %lu reject reason %d updated reason %d",
                   v55,
                   v56,
                   v57,
                   v58,
                   v59,
                   v60,
                   v61,
                   v62,
                   "dlm_handle_rssi_reject_list",
                   *(unsigned __int8 *)(a1 + 16),
                   *(unsigned __int8 *)(a1 + 17),
                   *(unsigned __int8 *)(a1 + 18),
                   *(unsigned __int8 *)(a1 + 21),
                   v47,
                   *(char *)(a1 + 60),
                   *(_DWORD *)(a1 + 56),
                   *(_DWORD *)(a1 + 76),
                   *(_DWORD *)(a1 + 72),
                   *(_QWORD *)(a1 + 64),
                   a3[23],
                   v68);
      }
    }
    qdf_trace_msg(
      0x6Du,
      2u,
      "%s: Invalid reason passed %d",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "dlm_update_rssi_reject_reason");
    v68 = *(_DWORD *)(a1 + 140);
    return qdf_trace_msg(
             0x6Du,
             4u,
             "%s: %02x:%02x:%02x:**:**:%02x %s to rssi reject list, expected RSSI %d retry delay %u source %d original ti"
             "meout %u received time %lu reject reason %d updated reason %d",
             v55,
             v56,
             v57,
             v58,
             v59,
             v60,
             v61,
             v62,
             "dlm_handle_rssi_reject_list",
             *(unsigned __int8 *)(a1 + 16),
             *(unsigned __int8 *)(a1 + 17),
             *(unsigned __int8 *)(a1 + 18),
             *(unsigned __int8 *)(a1 + 21),
             v47,
             *(char *)(a1 + 60),
             *(_DWORD *)(a1 + 56),
             *(_DWORD *)(a1 + 76),
             *(_DWORD *)(a1 + 72),
             *(_QWORD *)(a1 + 64),
             a3[23],
             v68);
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
  v14 = *(_BYTE *)(a1 + 136);
  v15 = *a3;
  *(_WORD *)(a1 + 20) = *((_WORD *)a3 + 2);
  *(_DWORD *)(a1 + 16) = v15;
  *(_BYTE *)(a1 + 136) = v14 | 1;
  system_time = qdf_mc_timer_get_system_time();
  v25 = *(_DWORD *)(a1 + 140);
  v26 = *(unsigned __int8 *)(a1 + 16);
  v27 = *(unsigned __int8 *)(a1 + 17);
  v28 = *(unsigned __int8 *)(a1 + 18);
  v29 = "%s: %02x:%02x:%02x:**:**:%02x added to userspace denylist";
  v30 = *(unsigned __int8 *)(a1 + 21);
  *(_QWORD *)(a1 + 104) = system_time;
  v31 = "dlm_handle_denylist";
  *(_DWORD *)(a1 + 140) = v25 | 0x20;
  *(_DWORD *)(a1 + 144) = 1;
  return qdf_trace_msg(0x6Du, 8u, v29, v17, v18, v19, v20, v21, v22, v23, v24, v31, v26, v27, v28, v30, v79);
}
