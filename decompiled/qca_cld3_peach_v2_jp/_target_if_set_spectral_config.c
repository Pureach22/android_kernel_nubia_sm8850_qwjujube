__int64 __fastcall target_if_set_spectral_config(
        _QWORD *a1,
        _DWORD *a2,
        unsigned int a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x26
  _QWORD *v14; // x24
  __int64 v19; // x21
  char v20; // w8
  int v21; // w24
  __int64 v22; // x4
  int v23; // w8
  int v24; // w9
  int v25; // w24
  unsigned int v26; // w8
  unsigned int v27; // w8
  unsigned int v28; // w0
  __int64 v29; // x4
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  const char *v39; // x2
  _QWORD *vdev; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x25
  double ch_width; // d0
  unsigned int v51; // w0
  unsigned int v52; // w24
  unsigned int *v53; // x8
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 result; // x0
  unsigned int default_sscan_bw; // w0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x4
  unsigned int v72; // w0
  _DWORD *v73; // x8
  _DWORD *v74; // x8
  int v75; // w8
  const char *v76; // x2
  unsigned int v77; // w8
  __int64 v78; // x9
  __int64 v79; // x4
  int v80; // w8
  __int64 v81; // x2
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  unsigned int v90; // w24
  int v91; // w9
  int v92; // w8
  unsigned int v93; // w23
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  const char *v102; // x2
  __int64 v103; // x0
  __int64 v104; // x2
  _BYTE v109[4]; // [xsp+0h] [xbp-80h] BYREF
  _BYTE v110[4]; // [xsp+4h] [xbp-7Ch] BYREF
  __int64 v111; // [xsp+8h] [xbp-78h] BYREF
  _BYTE v112[4]; // [xsp+14h] [xbp-6Ch] BYREF
  _WORD v113[2]; // [xsp+18h] [xbp-68h] BYREF
  _BYTE v114[4]; // [xsp+1Ch] [xbp-64h] BYREF
  _QWORD v115[10]; // [xsp+20h] [xbp-60h] BYREF
  _QWORD v116[2]; // [xsp+70h] [xbp-10h] BYREF

  v13 = a3;
  v14 = a1 + 100;
  v116[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a4 = 0;
  v19 = (__int64)&a1[10 * a3 + 80];
  v116[0] = 0x800000008LL;
  v20 = *((_BYTE *)a1 + a3 + 800);
  memset(v115, 0, sizeof(v115));
  v114[0] = 0;
  v113[0] = 0;
  v112[0] = 0;
  v111 = 0;
  v110[0] = 0;
  if ( (v20 & 1) == 0 )
  {
    target_if_spectral_info_read((__int64)a1, a3, 2, (unsigned __int8 *)v19, 80, a5, a6, a7, a8, a9, a10, a11, a12);
    *((_BYTE *)v14 + v13) = 1;
  }
  switch ( *a2 )
  {
    case 0:
      *(_WORD *)v19 = a2[1];
      goto LABEL_56;
    case 1:
      v23 = a2[1];
      v24 = *(unsigned __int16 *)(v19 + 4);
      *(_WORD *)(v19 + 2) = v23;
      if ( v24 && (a3 == 1 || (v23 & 0xFFFCu) <= 0x33) )
      {
        *(_WORD *)(v19 + 4) = 0;
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: FFT recapture cannot be enabled due to scan period: %d us or spectral scan mode: %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "_target_if_set_spectral_config",
          (unsigned __int16)v23,
          a3);
      }
      goto LABEL_56;
    case 2:
      if ( !a2[1] )
        goto LABEL_55;
      v22 = *(unsigned __int16 *)(v19 + 2);
      if ( a3 || (unsigned int)v22 < 0x34 )
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: FFT recapture cannot be enabled due to scan period: %d us or spectral scan mode: %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "_target_if_set_spectral_config",
          v22,
          a3);
LABEL_55:
        *(_WORD *)(v19 + 4) = 0;
      }
      else
      {
        *(_WORD *)(v19 + 4) = 1;
      }
      goto LABEL_56;
    case 3:
      v26 = a2[1];
      if ( v26 > *((unsigned __int16 *)a1 + 732) )
        goto LABEL_85;
      *(_WORD *)(v19 + 6) = v26;
      goto LABEL_56;
    case 4:
      *(_WORD *)(v19 + 8) = a2[1] != 0;
      goto LABEL_56;
    case 5:
      *(_WORD *)(v19 + 12) = a2[1] != 0;
      goto LABEL_56;
    case 6:
      v25 = *((_DWORD *)a1 + 196);
      if ( *((_BYTE *)a1 + 1192) == 1 )
      {
        LODWORD(v116[0]) = *((unsigned __int16 *)a1 + 354);
      }
      else
      {
        default_sscan_bw = get_default_sscan_bw(a1, 0, v25 != 0);
        v71 = default_sscan_bw;
        LODWORD(v116[0]) = default_sscan_bw;
        if ( default_sscan_bw > 7 )
          goto LABEL_53;
        *((_WORD *)a1 + 354) = default_sscan_bw;
      }
      if ( (*((_BYTE *)a1 + 1193) & 1) != 0 )
      {
        HIDWORD(v116[0]) = *((unsigned __int16 *)a1 + 394);
        goto LABEL_74;
      }
      v72 = get_default_sscan_bw(a1, 1, v25 != 0);
      v71 = v72;
      HIDWORD(v116[0]) = v72;
      if ( v72 > 7 )
      {
LABEL_53:
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: Invalid sscan BW %u",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "target_if_spectral_populate_chwidth",
          v71);
        result = 16;
        goto LABEL_61;
      }
      *((_WORD *)a1 + 394) = v72;
LABEL_74:
      v77 = a2[1];
      if ( v77 < *((unsigned __int16 *)a1 + 722) )
      {
LABEL_85:
        result = 16;
        *a4 = 3;
        goto LABEL_61;
      }
      if ( a3 > 1 )
        goto LABEL_109;
      v78 = *((unsigned int *)v116 + v13);
      if ( (unsigned int)v78 <= 8 )
      {
        if ( v77 <= *((unsigned __int16 *)a1 + v78 + 723) )
        {
          *(_WORD *)(v19 + 14) = v77;
LABEL_56:
          v73 = (_DWORD *)a1[12];
          if ( *(v73 - 1) != 2051770554 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, __int64, _QWORD))v73)(a1, v19, a3);
          v74 = (_DWORD *)a1[13];
          if ( *(v74 - 1) != 2051770554 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, _QWORD *, _QWORD))v74)(a1, v115, a3);
          result = 0;
          goto LABEL_61;
        }
        goto LABEL_85;
      }
LABEL_110:
      __break(0x5512u);
      __asm { STZ2G           X25, [X5,#-0xB0] }
      return target_if_get_spectral_config();
    case 7:
      *(_WORD *)(v19 + 16) = a2[1] != 0;
      goto LABEL_56;
    case 8:
      *(_WORD *)(v19 + 18) = a2[1] != 0;
      goto LABEL_56;
    case 9:
      *(_WORD *)(v19 + 20) = a2[1];
      goto LABEL_56;
    case 0xA:
      *(_WORD *)(v19 + 22) = a2[1];
      goto LABEL_56;
    case 0xB:
      *(_WORD *)(v19 + 24) = a2[1];
      goto LABEL_56;
    case 0xC:
      *(_WORD *)(v19 + 26) = a2[1];
      goto LABEL_56;
    case 0xD:
      *(_WORD *)(v19 + 28) = a2[1] != 0;
      goto LABEL_56;
    case 0xE:
      *(_WORD *)(v19 + 30) = a2[1] != 0;
      goto LABEL_56;
    case 0xF:
      *(_WORD *)(v19 + 32) = a2[1];
      goto LABEL_56;
    case 0x10:
      *(_WORD *)(v19 + 34) = a2[1] != 0;
      goto LABEL_56;
    case 0x11:
      v27 = a2[1];
      if ( v27 >= 4 )
        goto LABEL_85;
      *(_WORD *)(v19 + 36) = v27;
      goto LABEL_56;
    case 0x12:
      *(_WORD *)(v19 + 38) = a2[1];
      goto LABEL_56;
    case 0x13:
      *(_WORD *)(v19 + 40) = a2[1] != 0;
      goto LABEL_56;
    case 0x14:
      *(_WORD *)(v19 + 42) = a2[1];
      goto LABEL_56;
    case 0x18:
      v21 = a2[2];
      if ( *((_BYTE *)a1 + 1192) == 1 )
      {
        LODWORD(v116[0]) = *((unsigned __int16 *)a1 + 354);
        if ( (*((_BYTE *)a1 + 1193) & 1) != 0 )
        {
LABEL_8:
          HIDWORD(v116[0]) = *((unsigned __int16 *)a1 + 394);
          goto LABEL_63;
        }
      }
      else
      {
        v28 = get_default_sscan_bw(a1, 0, v21 != 0);
        v29 = v28;
        LODWORD(v116[0]) = v28;
        if ( v28 > 7 )
          goto LABEL_43;
        *((_WORD *)a1 + 354) = v28;
        if ( (*((_BYTE *)a1 + 1193) & 1) != 0 )
          goto LABEL_8;
      }
      v30 = get_default_sscan_bw(a1, 1, v21 != 0);
      v29 = v30;
      HIDWORD(v116[0]) = v30;
      if ( v30 <= 7 )
      {
        *((_WORD *)a1 + 394) = v30;
LABEL_63:
        if ( a3 > 1 )
        {
LABEL_109:
          __break(1u);
          goto LABEL_110;
        }
        v75 = a2[2];
        if ( *((_DWORD *)v116 + v13) == 4 )
        {
          if ( !v75 )
          {
            v76 = "%s: Non zero cfreq2 expected for 80p80";
LABEL_69:
            *a4 = 3;
            qdf_trace_msg(0x56u, 2u, v76, a5, a6, a7, a8, a9, a10, a11, a12, "_target_if_set_spectral_config");
            result = 4;
LABEL_61:
            _ReadStatusReg(SP_EL0);
            return result;
          }
        }
        else if ( v75 )
        {
          v76 = "%s: Non zero cfreq2 expected for 80p80 only";
          goto LABEL_69;
        }
        if ( (unsigned int)target_if_is_center_freq_of_any_chan(*a1, (unsigned int)a2[1], v112) )
        {
LABEL_71:
          result = 16;
          goto LABEL_61;
        }
        if ( v112[0] == 1 )
        {
          if ( (unsigned int)target_if_calculate_center_freq(a1, v116, (unsigned int)a2[1], v113) )
            goto LABEL_85;
          LOWORD(v80) = v113[0];
        }
        else
        {
          v81 = (unsigned int)a2[1];
          v109[0] = 0;
          if ( (unsigned int)target_if_validate_center_freq(a1, v116, v81, v109) )
            goto LABEL_71;
          if ( (v109[0] & 1) == 0 )
            goto LABEL_107;
          v80 = a2[1];
          v113[0] = v80;
        }
        v90 = (unsigned __int16)v80;
        v91 = *((_DWORD *)v116 + v13);
        LODWORD(v111) = (unsigned __int16)v80;
        if ( v91 != 4 )
        {
          v93 = 0;
          goto LABEL_95;
        }
        if ( (unsigned int)target_if_is_center_freq_of_any_chan(*a1, (unsigned int)a2[2], v112) )
          goto LABEL_71;
        if ( v112[0] == 1 )
        {
          if ( (unsigned int)target_if_calculate_center_freq(a1, v116, (unsigned int)a2[2], v113) )
            goto LABEL_85;
          LOWORD(v92) = v113[0];
          goto LABEL_106;
        }
        v104 = (unsigned int)a2[2];
        v109[0] = 0;
        if ( (unsigned int)target_if_validate_center_freq(a1, v116, v104, v109) )
          goto LABEL_71;
        if ( (v109[0] & 1) != 0 )
        {
          v92 = a2[2];
          v113[0] = v92;
LABEL_106:
          v93 = (unsigned __int16)v92;
          HIDWORD(v111) = (unsigned __int16)v92;
LABEL_95:
          if ( !(unsigned int)target_if_is_agile_span_overlap_with_operating_span(a1, v116, &v111, v114) )
          {
            if ( v114[0] == 1 )
            {
              v102 = "%s: Agile freq %u, %u overlaps with operating span";
            }
            else
            {
              if ( *((_DWORD *)v116 + v13) != 4 )
                goto LABEL_102;
              v103 = *a1;
              v109[0] = 0;
              result = target_if_spectral_is_valid_80p80_freq(v103, v90, v93, v109);
              if ( (_DWORD)result )
                goto LABEL_61;
              if ( (v109[0] & 1) != 0 )
              {
LABEL_102:
                *(_DWORD *)(v19 + 60) = v90;
                *(_DWORD *)(v19 + 64) = v93;
                goto LABEL_56;
              }
              v102 = "%s: Agile freq %u, %u is invalid 80+80 combination";
            }
            qdf_trace_msg(
              0x56u,
              2u,
              v102,
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              "_target_if_set_spectral_config",
              v90,
              v93);
            goto LABEL_85;
          }
          goto LABEL_71;
        }
LABEL_107:
        *a4 = 3;
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: Invalid agile center frequency",
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          "_target_if_set_spectral_config");
        goto LABEL_71;
      }
LABEL_43:
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Invalid sscan BW %u",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "target_if_spectral_populate_chwidth",
        v29);
      v39 = "%s: Failed to populate channel width";
      goto LABEL_47;
    case 0x1A:
      if ( a2[1] >= 8u )
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: invalid sscan width: %u",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "_target_if_set_spectral_config");
        goto LABEL_85;
      }
      vdev = target_if_spectral_get_vdev(a1, a3, a5, a6, a7, a8, a9, a10, a11, a12);
      if ( !vdev )
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: vdev is null",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "_target_if_set_spectral_config");
        result = 29;
        goto LABEL_61;
      }
      v49 = (__int64)vdev;
      ch_width = target_if_vdev_get_ch_width();
      v52 = v51;
      wlan_objmgr_vdev_release_ref(v49, 0x1Bu, v53, ch_width, v54, v55, v56, v57, v58, v59, v60);
      if ( (unsigned int)target_if_is_sscan_bw_supported(
                           a1,
                           a3,
                           (unsigned int)a2[1],
                           v52,
                           v110,
                           *((_DWORD *)a1 + 196) != 0) )
      {
        v39 = "%s: Unable to check if given sscan_bw is supported";
LABEL_47:
        qdf_trace_msg(0x56u, 2u, v39, v31, v32, v33, v34, v35, v36, v37, v38, "_target_if_set_spectral_config");
        result = 16;
        goto LABEL_61;
      }
      v79 = (unsigned int)a2[1];
      if ( (v110[0] & 1) != 0 )
      {
        *(_WORD *)(v19 + 68) = v79;
        *((_BYTE *)a1 + v13 + 1192) = 1;
        goto LABEL_56;
      }
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: sscan bw(%u) is not supported for the current operating width(%u) and sscan mode(%u)",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "_target_if_set_spectral_config",
        v79,
        v52,
        a3);
      goto LABEL_85;
    case 0x1B:
      *(_DWORD *)(v19 + 76) = a2[1];
      goto LABEL_56;
    default:
      goto LABEL_56;
  }
}
