__int64 __fastcall lim_send_ext_cap_ie(__int64 a1, unsigned int a2, __int64 a3, char a4)
{
  __int64 v8; // x8
  bool v9; // cf
  unsigned int v10; // w8
  int v11; // w9
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x23
  __int64 ext_hdl; // x0
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int *v41; // x8
  char v42; // w8
  unsigned int v43; // w23
  __int64 session_by_vdev_id; // x0
  _DWORD *v45; // x0
  __int64 v46; // x20
  void *v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // [xsp+0h] [xbp-50h] BYREF
  __int64 v57; // [xsp+8h] [xbp-48h]
  __int64 v58; // [xsp+10h] [xbp-40h]
  __int64 v59; // [xsp+18h] [xbp-38h]
  __int64 v60; // [xsp+20h] [xbp-30h]
  __int64 v61; // [xsp+28h] [xbp-28h]
  __int64 v62; // [xsp+30h] [xbp-20h] BYREF
  __int64 v63; // [xsp+38h] [xbp-18h]
  char v64; // [xsp+40h] [xbp-10h]
  __int64 v65; // [xsp+48h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 8);
  v64 = 0;
  v62 = 0;
  v63 = 0;
  LODWORD(v8) = *(_DWORD *)(v8 + 5964);
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v9 = (unsigned int)v8 >= 0xE;
  v10 = 0x3F01u >> v8;
  v56 = 0;
  v57 = 0;
  v11 = !v9;
  if ( (unsigned int)populate_dot11f_ext_cap(a1, v11 & v10, &v62, 0) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to populate ext cap IE",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "lim_send_ext_cap_ie",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62);
LABEL_6:
    result = 16;
    goto LABEL_7;
  }
  v21 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 21624),
          a2,
          7);
  if ( v21 )
  {
    v30 = v21;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v21, v22, v23, v24, v25, v26, v27, v28, v29);
    if ( ext_hdl )
    {
      v41 = (unsigned int *)(WORD1(v63) & 0x9FFF
                           | (((*(unsigned __int8 *)(ext_hdl + 23897) >> 1) & 1) << 13)
                           | (((*(unsigned __int8 *)(ext_hdl + 23897) >> 2) & 1u) << 14));
      WORD1(v63) = WORD1(v63) & 0x9FFF
                 | (((*(_BYTE *)(ext_hdl + 23897) & 2) != 0) << 13)
                 | (((*(_BYTE *)(ext_hdl + 23897) & 4) != 0) << 14);
      wlan_objmgr_vdev_release_ref(v30, 7u, v41, v33, v34, v35, v36, v37, v38, v39, v40);
      if ( v64 )
      {
        v42 = 15;
      }
      else if ( HIBYTE(v63) )
      {
        v42 = 14;
      }
      else if ( BYTE6(v63) )
      {
        v42 = 13;
      }
      else if ( BYTE5(v63) )
      {
        v42 = 12;
      }
      else if ( BYTE4(v63) )
      {
        v42 = 11;
      }
      else if ( BYTE3(v63) )
      {
        v42 = 10;
      }
      else if ( BYTE2(v63) )
      {
        v42 = 9;
      }
      else if ( BYTE1(v63) )
      {
        v42 = 8;
      }
      else if ( (_BYTE)v63 )
      {
        v42 = 7;
      }
      else if ( HIBYTE(v62) )
      {
        v42 = 6;
      }
      else if ( BYTE6(v62) )
      {
        v42 = 5;
      }
      else if ( BYTE5(v62) )
      {
        v42 = 4;
      }
      else if ( BYTE4(v62) )
      {
        v42 = 3;
      }
      else if ( BYTE3(v62) )
      {
        v42 = 2;
      }
      else
      {
        v42 = BYTE2(v62) != 0;
      }
      BYTE1(v62) = v42;
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v30, 7u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
    }
  }
  v43 = BYTE1(v62);
  if ( a3 && (a4 & 1) != 0 && *(_BYTE *)(a3 + 1) )
  {
    if ( *(unsigned __int8 *)(a3 + 1) > (unsigned int)BYTE1(v62) )
      v43 = *(unsigned __int8 *)(a3 + 1);
    lim_merge_extcap_struct(&v62, a3, 1);
  }
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2, v22, v23, v24, v25, v26, v27, v28, v29);
  if ( session_by_vdev_id )
    populate_dot11f_btm_extended_caps(a1, session_by_vdev_id, &v62);
  v45 = (_DWORD *)_qdf_mem_malloc(v43 + 24LL, "lim_send_ext_cap_ie", 6380);
  if ( !v45 )
  {
    result = 2;
    goto LABEL_7;
  }
  v46 = (__int64)v45;
  v45[2] = v43;
  v45[3] = 0;
  *v45 = a2;
  v45[1] = 127;
  v47 = v45 + 6;
  *(_QWORD *)(v46 + 16) = v47;
  qdf_mem_copy(v47, (char *)&v62 + 2, v43);
  LODWORD(v56) = 4462;
  v57 = v46;
  result = scheduler_post_message_debug(
             0x35u,
             0x36u,
             54,
             (unsigned __int16 *)&v56,
             0x18FFu,
             (__int64)"lim_send_ext_cap_ie");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Not able to post WMA_SET_IE_INFO to WDA",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "lim_send_ext_cap_ie");
    _qdf_mem_free(v46);
    goto LABEL_6;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
