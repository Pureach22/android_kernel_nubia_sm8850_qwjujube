__int64 __fastcall action_oui_parse(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w19
  __int64 v13; // x23
  char *v14; // x0
  unsigned int v15; // w24
  char v16; // w22
  unsigned int v17; // w20
  int v18; // w25
  const char *v19; // x2
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  char *v29; // x0
  const char *v30; // x28
  int v31; // w0
  unsigned int v32; // w25
  char v33; // w25
  size_t v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w0
  char v44; // w25
  size_t v45; // x8
  const char *v46; // x6
  const char *v47; // x4
  int v48; // w8
  const char *v49; // x8
  const char *v50; // x2
  unsigned int v51; // w1
  __int64 v52; // x4
  const char *v53; // x2
  const char *v54; // x2
  const char *v55; // x2
  int v56; // w9
  const char *v57; // x4
  char *stringp; // [xsp+18h] [xbp-68h] BYREF
  char *v59; // [xsp+20h] [xbp-60h] BYREF
  __int128 v60; // [xsp+28h] [xbp-58h] BYREF
  __int64 v61; // [xsp+38h] [xbp-48h]
  __int64 v62; // [xsp+40h] [xbp-40h] BYREF
  _QWORD v63[2]; // [xsp+48h] [xbp-38h] BYREF
  __int64 v64; // [xsp+58h] [xbp-28h] BYREF
  __int64 v65; // [xsp+60h] [xbp-20h] BYREF
  int v66; // [xsp+68h] [xbp-18h]
  _QWORD v67[2]; // [xsp+70h] [xbp-10h] BYREF

  v11 = a3;
  v67[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = 0;
  v64 = 0;
  v65 = 0;
  v63[0] = 0;
  v63[1] = 0;
  v61 = 0;
  v62 = 0;
  v60 = 0u;
  stringp = nullptr;
  v59 = nullptr;
  if ( !a2 )
  {
    v19 = "%s: Invalid string for action oui: %u";
LABEL_159:
    qdf_trace_msg(0x63u, 2u, v19, a4, a5, a6, a7, a8, a9, a10, a11, "action_oui_parse", v11);
    result = 4;
    goto LABEL_163;
  }
  if ( (unsigned int)a3 >= 0x1C )
  {
    __break(0x5512u);
    return action_oui_parse_string(a1, a2, a3);
  }
  v13 = *(_QWORD *)(a1 + 8LL * (unsigned int)a3 + 23544);
  if ( !v13 )
  {
    qdf_trace_msg(0x63u, 2u, "%s: action oui priv not allocated", a4, a5, a6, a7, a8, a9, a10, a11, "action_oui_parse");
    result = 4;
    goto LABEL_163;
  }
  if ( !*(_BYTE *)(a1 + 8) )
  {
    qdf_trace_msg(0x63u, 8u, "%s: action_oui is not enable", a4, a5, a6, a7, a8, a9, a10, a11, "action_oui_parse");
    goto LABEL_162;
  }
  v14 = (char *)strim(a2);
  v59 = v14;
  if ( !v14 )
  {
LABEL_158:
    v19 = "%s: Not able to parse any extension in action oui: %u";
    goto LABEL_159;
  }
  if ( v11 >= 0x13 )
    v15 = 100;
  else
    v15 = 10;
  v16 = 0;
  v17 = 0;
  v18 = 1;
  while ( 1 )
  {
    stringp = (char *)skip_spaces(v14);
    if ( !*stringp )
    {
      if ( v18 > 15 )
      {
        if ( v18 > 63 )
        {
          if ( v18 == 64 )
            v46 = "ACTION_OUI_MAC_MASK_TOKEN";
          else
            v46 = "ACTION_OUI_CAPABILITY_TOKEN";
        }
        else if ( v18 == 16 )
        {
          v46 = "ACTION_OUI_INFO_MASK_TOKEN";
        }
        else
        {
          v46 = "ACTION_OUI_MAC_ADDR_TOKEN";
        }
      }
      else if ( v18 > 3 )
      {
        if ( v18 == 4 )
          v46 = "ACTION_OUI_DATA_TOKEN";
        else
          v46 = "ACTION_OUI_DATA_MASK_TOKEN";
      }
      else if ( v18 == 1 )
      {
        v46 = "ACTION_OUI_TOKEN";
      }
      else
      {
        v46 = "ACTION_OUI_DATA_LENGTH_TOKEN";
      }
      qdf_trace_msg(
        0x63u,
        2u,
        "%s: Invalid spaces in action oui: %u at extension: %u for token: %s",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "action_oui_parse",
        v11,
        v17 + 1,
        v46);
      goto LABEL_132;
    }
    v29 = strsep(&stringp, " ");
    if ( !v29 )
    {
      if ( v18 > 15 )
      {
        if ( v18 > 63 )
        {
          if ( v18 == 64 )
            v47 = "ACTION_OUI_MAC_MASK_TOKEN";
          else
            v47 = "ACTION_OUI_CAPABILITY_TOKEN";
        }
        else if ( v18 == 16 )
        {
          v47 = "ACTION_OUI_INFO_MASK_TOKEN";
        }
        else
        {
          v47 = "ACTION_OUI_MAC_ADDR_TOKEN";
        }
      }
      else if ( v18 > 3 )
      {
        if ( v18 == 4 )
          v47 = "ACTION_OUI_DATA_TOKEN";
        else
          v47 = "ACTION_OUI_DATA_MASK_TOKEN";
      }
      else if ( v18 == 1 )
      {
        v47 = "ACTION_OUI_TOKEN";
      }
      else
      {
        v47 = "ACTION_OUI_DATA_LENGTH_TOKEN";
      }
      goto LABEL_131;
    }
    v30 = v29;
    v59 = stringp;
    if ( v18 <= 15 )
    {
      if ( v18 > 3 )
      {
        if ( v18 == 4 )
        {
          LODWORD(v67[0]) = 2 * DWORD2(v60);
          if ( (action_oui_string_to_hex(v29, (char *)v63 + 1, 1, v67) & 1) == 0 )
          {
            v49 = "ACTION_OUI_DATA_TOKEN";
            v18 = 4;
            goto LABEL_130;
          }
          v18 = 8;
        }
        else
        {
          if ( (BYTE8(v60) & 7) != 0 )
            v32 = (DWORD2(v60) >> 3) + 1;
          else
            v32 = DWORD2(v60) >> 3;
          if ( v32 > 3
            || (LODWORD(v67[0]) = 2 * v32, (action_oui_string_to_hex(v29, (char *)&v64 + 5, 1, v67) & 1) == 0) )
          {
            v49 = "ACTION_OUI_DATA_MASK_TOKEN";
            v18 = 8;
            goto LABEL_130;
          }
          HIDWORD(v60) = v32;
          v18 = 16;
        }
        goto LABEL_15;
      }
      if ( v18 == 1 )
      {
        v67[0] = 0xA00000006LL;
        if ( (action_oui_string_to_hex(v29, (char *)&v62 + 4, 2, v67) & 1) == 0 )
        {
          v49 = "ACTION_OUI_TOKEN";
          v18 = 1;
          goto LABEL_130;
        }
        v18 = 2;
        DWORD1(v60) = strlen(v30) >> 1;
        goto LABEL_15;
      }
      v31 = strlen(v29);
      LOBYTE(v67[0]) = 0;
      if ( (unsigned int)(v31 - 3) <= 0xFFFFFFFD )
      {
        v53 = "%s: Invalid str token len for action OUI data len";
        goto LABEL_112;
      }
      if ( (unsigned int)kstrtou8(v30, 16, v67) )
      {
        v53 = "%s: Invalid char in action OUI data len str token";
LABEL_112:
        qdf_trace_msg(0x63u, 2u, v53, a4, a5, a6, a7, a8, a9, a10, a11, "validate_and_convert_data_length");
LABEL_120:
        v49 = "ACTION_OUI_DATA_LENGTH_TOKEN";
        v18 = 2;
        goto LABEL_130;
      }
      if ( LOBYTE(v67[0]) >= 0x15u )
      {
        qdf_trace_msg(
          0x63u,
          2u,
          "%s: action OUI data len %d is more than %u",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "validate_and_convert_data_length");
        goto LABEL_120;
      }
      if ( LOBYTE(v67[0]) )
        v18 = 4;
      else
        v18 = 16;
      DWORD2(v60) = LOBYTE(v67[0]);
      goto LABEL_15;
    }
    if ( v18 > 63 )
      break;
    if ( v18 != 16 )
    {
      LODWORD(v67[0]) = 12;
      if ( (action_oui_string_to_hex(v29, &v65, 1, v67) & 1) == 0 )
      {
        v49 = "ACTION_OUI_MAC_ADDR_TOKEN";
        v18 = 32;
        goto LABEL_130;
      }
      v18 = 64;
      LODWORD(v61) = 6;
      goto LABEL_15;
    }
    v43 = strlen(v29);
    LOBYTE(v67[0]) = 0;
    if ( v43 != 2 )
    {
      v54 = "%s: action OUI info mask str token len is not of 2 chars";
LABEL_129:
      qdf_trace_msg(0x63u, 2u, v54, a4, a5, a6, a7, a8, a9, a10, a11, "validate_and_convert_info_mask");
      v49 = "ACTION_OUI_INFO_MASK_TOKEN";
      v18 = 16;
      goto LABEL_130;
    }
    if ( (unsigned int)kstrtou8(v30, 16, v67) )
    {
      v54 = "%s: Invalid char in action OUI info mask str token";
      goto LABEL_129;
    }
    LODWORD(v60) = LOBYTE(v67[0]);
    if ( LOBYTE(v67[0]) <= 1u )
      goto LABEL_64;
    if ( LOBYTE(v67[0]) > 0x3Fu )
    {
      v54 = "%s: Invalid bits are set in action OUI info mask";
      goto LABEL_129;
    }
    if ( (v67[0] & 1) == 0 )
    {
      *(_QWORD *)((char *)&v60 + 4) = 0;
      HIDWORD(v60) = 0;
    }
    if ( (v67[0] & 2) != 0 )
      v18 = 32;
    else
      v18 = 128;
LABEL_15:
    v14 = v59;
    if ( !v59 )
    {
      v48 = 1;
      goto LABEL_133;
    }
  }
  if ( v18 != 64 )
  {
    v33 = v60;
    LODWORD(v67[0]) = 2;
    if ( (action_oui_string_to_hex(v29, (char *)&v65 + 7, 1, v67) & 1) == 0 )
      goto LABEL_127;
    v34 = strlen(v30) >> 1;
    if ( (unsigned int)v34 >= 2 )
    {
      qdf_trace_msg(
        0x63u,
        2u,
        "%s: action OUI capability str token len is more than %u chars",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "validate_and_convert_capability",
        2);
    }
    else
    {
      if ( (v33 & 4) != 0 && (v65 & 0xF00000000000000LL) == 0 )
      {
        v55 = "%s: Info presence for NSS is set but respective bits in capability are not set";
      }
      else
      {
        if ( (v33 & 0x20) == 0 || HIBYTE(v65) > 0x3Fu )
        {
          LODWORD(v62) = v34;
LABEL_64:
          LOBYTE(v66) = v16;
          if ( (unsigned int)action_oui_extension_store(a1, v13, (__int64)&v60) )
          {
            qdf_trace_msg(
              0x63u,
              2u,
              "%s: sme set of extension: %u for action oui: %u failed",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "action_oui_parse",
              v17 + 1,
              v11);
            goto LABEL_153;
          }
          if ( v11 >= 0x13 )
          {
            qdf_mutex_acquire(v13 + 32);
            ++*(_DWORD *)(a1 + 23536);
            qdf_mutex_release(v13 + 32);
          }
          if ( ++v17 == v15 )
          {
            if ( v59 )
            {
              v50 = "%s: Reached Maximum extensions: %u in action_oui: %u, ignoring the rest";
              v51 = 2;
              v52 = v15;
              goto LABEL_161;
            }
            goto LABEL_157;
          }
          if ( *(_BYTE *)(a1 + 23777 + v11) == 1 && stringp && *stringp )
          {
            v59 = (char *)skip_spaces(stringp);
            if ( (unsigned int)qdf_mem_cmp(v59, "&&", 2u) )
            {
              if ( !(unsigned int)qdf_mem_cmp(v59, "||", 2u) )
                strsep(&v59, " ");
              v16 = 0;
            }
            else
            {
              strsep(&v59, " ");
              ++v16;
            }
          }
          qdf_mem_set(&v60, 0x44u, 0);
          v18 = 1;
          goto LABEL_15;
        }
        v55 = "%s: Info presence for BAND is set but respective bits in capability are not set";
      }
      qdf_trace_msg(0x63u, 2u, v55, v35, v36, v37, v38, v39, v40, v41, v42, "validate_and_convert_capability");
    }
LABEL_127:
    v49 = "ACTION_OUI_CAPABILITY_TOKEN";
    v18 = 128;
    goto LABEL_130;
  }
  v44 = v60;
  LODWORD(v67[0]) = 2;
  if ( (action_oui_string_to_hex(v29, (char *)&v65 + 6, 1, v67) & 1) == 0 )
    goto LABEL_109;
  v45 = strlen(v30) >> 1;
  if ( (unsigned int)v45 < 2 )
  {
    HIDWORD(v61) = v45;
    if ( (v44 & 0x3C) != 0 )
    {
      v18 = 128;
      goto LABEL_15;
    }
    goto LABEL_64;
  }
  qdf_trace_msg(
    0x63u,
    2u,
    "%s: action OUI mac mask str token len is more than %u chars",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "validate_and_convert_mac_mask",
    2);
LABEL_109:
  v49 = "ACTION_OUI_MAC_MASK_TOKEN";
  v18 = 64;
LABEL_130:
  v47 = v49;
LABEL_131:
  qdf_trace_msg(
    0x63u,
    2u,
    "%s: Invalid string for token: %s at extension: %u in action oui: %u",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "action_oui_parse",
    v47,
    v17 + 1,
    v11);
LABEL_132:
  v48 = 0;
LABEL_133:
  if ( v18 != 1 )
  {
    v56 = v59 ? 0 : v48;
    if ( v56 == 1 )
    {
      if ( v18 > 63 )
      {
        if ( v18 == 64 )
          v57 = "ACTION_OUI_MAC_MASK_TOKEN";
        else
          v57 = "ACTION_OUI_CAPABILITY_TOKEN";
      }
      else if ( v18 <= 7 )
      {
        if ( v18 == 2 )
          v57 = "ACTION_OUI_DATA_LENGTH_TOKEN";
        else
          v57 = "ACTION_OUI_DATA_TOKEN";
      }
      else if ( v18 == 8 )
      {
        v57 = "ACTION_OUI_DATA_MASK_TOKEN";
      }
      else if ( v18 == 16 )
      {
        v57 = "ACTION_OUI_INFO_MASK_TOKEN";
      }
      else
      {
        v57 = "ACTION_OUI_MAC_ADDR_TOKEN";
      }
      qdf_trace_msg(
        0x63u,
        2u,
        "%s: No string for token: %s at extension: %u in action oui: %u",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "action_oui_parse",
        v57,
        v17 + 1,
        v11);
LABEL_153:
      v48 = 0;
    }
  }
  if ( !v17 )
    goto LABEL_158;
  if ( v48 )
  {
    v15 = v17;
LABEL_157:
    v50 = "%s: All extensions: %u parsed successfully in action oui: %u";
    v51 = 8;
    v52 = v15;
    goto LABEL_161;
  }
  v50 = "%s: First %u extensions parsed successfully in action oui: %u";
  v51 = 2;
  v52 = v17;
LABEL_161:
  qdf_trace_msg(0x63u, v51, v50, a4, a5, a6, a7, a8, a9, a10, a11, "action_oui_parse", v52, v11);
LABEL_162:
  result = 0;
LABEL_163:
  _ReadStatusReg(SP_EL0);
  return result;
}
