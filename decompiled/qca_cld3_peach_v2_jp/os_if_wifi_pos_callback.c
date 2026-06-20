__int64 __fastcall os_if_wifi_pos_callback(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 psoc; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w21
  __int64 v43; // x3
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  const char *v52; // x2
  _WORD *v53; // x22
  unsigned __int64 v54; // x21
  const char *v55; // x2
  unsigned int v56; // w8
  int v57; // w8
  int v58; // w4
  int v59; // w8
  __int64 v60; // x4
  unsigned int v61; // w8
  __int64 v62; // x3
  const char *v63; // x2
  unsigned int app_pid; // w0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // w0
  __int16 v74; // t1
  char v75[4]; // [xsp+Ch] [xbp-C4h] BYREF
  __int64 v76; // [xsp+10h] [xbp-C0h] BYREF
  _WORD *v77; // [xsp+18h] [xbp-B8h]
  __int64 v78; // [xsp+20h] [xbp-B0h]
  __int64 v79; // [xsp+28h] [xbp-A8h]
  __int64 v80; // [xsp+30h] [xbp-A0h]
  __int64 v81; // [xsp+38h] [xbp-98h]
  __int64 v82; // [xsp+40h] [xbp-90h]
  __int64 v83; // [xsp+48h] [xbp-88h]
  _QWORD v84[2]; // [xsp+50h] [xbp-80h] BYREF
  __int64 v85; // [xsp+60h] [xbp-70h]
  __int64 v86; // [xsp+68h] [xbp-68h]
  __int64 v87; // [xsp+70h] [xbp-60h]
  __int64 v88; // [xsp+78h] [xbp-58h]
  __int64 v89; // [xsp+80h] [xbp-50h] BYREF
  __int64 v90; // [xsp+88h] [xbp-48h]
  _WORD *v91; // [xsp+90h] [xbp-40h]
  __int64 v92; // [xsp+98h] [xbp-38h]
  __int64 v93; // [xsp+A0h] [xbp-30h]
  _WORD *v94; // [xsp+A8h] [xbp-28h]
  __int64 v95; // [xsp+B0h] [xbp-20h] BYREF
  __int16 *v96; // [xsp+B8h] [xbp-18h]
  __int64 v97; // [xsp+C0h] [xbp-10h]
  __int64 v98; // [xsp+C8h] [xbp-8h]

  v98 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _qdf_op_protect();
  if ( !(_DWORD)result )
  {
    v75[0] = 0;
    v82 = 0;
    v83 = 0;
    v80 = 0;
    v81 = 0;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = nullptr;
    psoc = wifi_pos_get_psoc(result);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: enter: pid %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "__os_if_wifi_pos_callback",
      a4,
      0);
    if ( !psoc )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: global psoc object not registered yet.",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "__os_if_wifi_pos_callback");
LABEL_48:
      result = _qdf_op_unprotect();
      goto LABEL_49;
    }
    wlan_objmgr_psoc_get_ref(psoc, 0x28u, v17, v18, v19, v20, v21, v22, v23, v24);
    v87 = 0;
    v88 = 0;
    v85 = 0;
    v86 = 0;
    v84[0] = 0;
    v84[1] = 0;
    if ( (unsigned int)_nla_parse(v84, 5, a1, a2, 0, 31, 0) )
    {
      v33 = "%s: invalid data in request";
LABEL_5:
      qdf_trace_msg(0x48u, 2u, v33, v25, v26, v27, v28, v29, v30, v31, v32, "wifi_pos_parse_req");
      v75[0] = 5;
      goto LABEL_46;
    }
    if ( v85 )
    {
      v93 = 0;
      v94 = nullptr;
      v91 = nullptr;
      v92 = 0;
      v89 = 0;
      v90 = 0;
      if ( (unsigned int)_nla_parse(&v89, 5, a1, a2, 0, 31, 0) )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: invalid data in request",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "wifi_pos_parse_ani_req");
        v42 = 5;
        goto LABEL_45;
      }
      v53 = v91;
      v54 = (unsigned __int16)(*v91 - 4);
      if ( (unsigned int)v54 <= 3 )
      {
        v55 = "%s: Insufficient length for msg_hdr: %u";
LABEL_24:
        v60 = (unsigned int)v54;
LABEL_25:
        qdf_trace_msg(0x48u, 2u, v55, v34, v35, v36, v37, v38, v39, v40, v41, "wifi_pos_parse_ani_req", v60);
        v42 = 6;
        goto LABEL_45;
      }
      v56 = (unsigned __int16)v91[2] - 1;
      if ( v56 < 0xB && ((0x515u >> v56) & 1) != 0 )
      {
        v57 = dword_A2BFC0[(unsigned __int16)(v91[2] - 1)];
      }
      else
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: ani req is invalid :%d",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "map_ani_msg_req_to_wifi_pos_cmd");
        v57 = 0;
      }
      LODWORD(v76) = v57;
      HIDWORD(v80) = 1;
      if ( (unsigned __int64)(unsigned __int16)v53[3] + 4 > v54 )
      {
        v55 = "%s: Insufficient length for msg_hdr buffer: %u";
        goto LABEL_24;
      }
      LODWORD(v78) = (unsigned __int16)v53[3];
      v77 = v53 + 4;
      HIDWORD(v76) = a4;
      if ( v92 )
      {
        v60 = (unsigned __int16)(*(_WORD *)v92 - 4);
        if ( (unsigned int)v60 <= 0xF )
        {
          v55 = "%s: Insufficient length for field_info_buf: %u";
          goto LABEL_25;
        }
        v61 = *(_DWORD *)(v92 + 4);
        if ( v61 )
        {
          if ( v61 - 1 <= 0x15555553 )
          {
            if ( 12 * (v61 - 1) + 16 > (unsigned int)v60 )
            {
              v55 = "%s: Insufficient len for total no.of %u fields";
              v60 = v61;
              goto LABEL_25;
            }
            v42 = 0;
            v79 = v92 + 4;
            LODWORD(v80) = v60;
          }
          else
          {
            v42 = 6;
          }
        }
        else
        {
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: field_info->count is zero, ignoring META_DATA",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "wifi_pos_parse_ani_req");
          v42 = 0;
        }
      }
      else
      {
        v42 = 0;
      }
LABEL_45:
      v75[0] = v42;
      if ( !v42 )
      {
        v73 = ucfg_wifi_pos_process_req(psoc, &v76, os_if_wifi_pos_send_rsp);
        if ( v73 )
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: ucfg_wifi_pos_process_req failed. status: %d",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "__os_if_wifi_pos_callback",
            v73);
        goto LABEL_47;
      }
LABEL_46:
      app_pid = wifi_pos_get_app_pid(psoc);
      v65 = os_if_wifi_pos_send_rsp(psoc, app_pid, 6, 1, v75);
LABEL_47:
      wlan_objmgr_psoc_release_ref(psoc, 0x28u, v65, v66, v67, v68, v69, v70, v71, v72);
      goto LABEL_48;
    }
    if ( !v87 )
    {
      v33 = "%s: Valid CLD80211 ATTR not present";
      goto LABEL_5;
    }
    v43 = a2;
    v93 = 0;
    v94 = nullptr;
    v42 = 5;
    v91 = nullptr;
    v92 = 0;
    v89 = 0;
    v90 = 0;
    if ( (unsigned int)_nla_parse(&v89, 5, a1, v43, 0, 31, 0) )
    {
      v52 = "%s: invalid data in request";
LABEL_44:
      qdf_trace_msg(0x48u, 2u, v52, v44, v45, v46, v47, v48, v49, v50, v51, "wifi_pos_parse_nla_req");
      goto LABEL_45;
    }
    HIDWORD(v76) = a4;
    v58 = *(_DWORD *)(v93 + 4);
    if ( (unsigned int)(v58 - 1) >= 4 )
    {
      if ( v58 == 5 )
      {
        v59 = 1;
      }
      else
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: cld vendor subcmd is invalid :%d",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "map_cld_vendor_sub_cmd_to_wifi_pos_cmd");
        v59 = 0;
        v58 = 0;
      }
    }
    else
    {
      v59 = 0;
    }
    LODWORD(v76) = v58;
    HIDWORD(v80) = 2;
    if ( v94 )
    {
      v62 = (unsigned __int16)(*v94 - 4);
      if ( v59 )
      {
        v96 = nullptr;
        v97 = 0;
        v95 = 0;
        if ( (unsigned int)_nla_parse(&v95, 2, v94 + 2, v62, 0, 31, 0) )
        {
          v63 = "%s: invalid data in request";
LABEL_40:
          qdf_trace_msg(0x48u, 2u, v63, v44, v45, v46, v47, v48, v49, v50, v51, "wifi_pos_parse_nla_oemdata_req");
          v42 = 6;
          v52 = "%s: parsing oemdata req failed";
          goto LABEL_44;
        }
        if ( !v96 )
        {
          v63 = "%s: CLD80211_SUB_ATTR_MSG_OEM_DATA_FW not present";
          goto LABEL_40;
        }
        v74 = *v96;
        v77 = v96 + 2;
        LODWORD(v78) = (unsigned __int16)(v74 - 4);
      }
      else
      {
        LODWORD(v78) = (unsigned __int16)(*v94 - 4);
        v77 = v94 + 2;
      }
    }
    v42 = 0;
    if ( !v92 )
      goto LABEL_45;
    v52 = "%s: meta data dropped. Apps can use CLD80211_ATTR_CMD_TAG_DATA sub attrs";
    goto LABEL_44;
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
