__int64 __fastcall wma_get_roam_scan_ch(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  unsigned int v21; // w20
  __int64 v22; // x0
  __int16 v23; // w8
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // [xsp+8h] [xbp-38h] BYREF
  __int64 v34; // [xsp+10h] [xbp-30h]
  __int64 v35; // [xsp+18h] [xbp-28h]
  __int64 v36; // [xsp+20h] [xbp-20h]
  __int64 v37; // [xsp+28h] [xbp-18h]
  __int64 v38; // [xsp+30h] [xbp-10h]
  __int64 v39; // [xsp+38h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  if ( (wma_is_vdev_valid((unsigned __int8)a2, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev_id: %d is not active",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_get_roam_scan_ch",
      (unsigned __int8)a2);
LABEL_7:
    result = 4;
    goto LABEL_8;
  }
  result = wmi_unified_get_roam_scan_ch_list(a1, a2);
  if ( (_DWORD)result )
  {
    v21 = result;
    v22 = _qdf_mem_malloc(0x10u, "wma_get_roam_scan_ch", 4167);
    if ( v22 )
    {
      *(_WORD *)(v22 + 2) = 0;
      *(_DWORD *)(v22 + 4) = 1;
      v23 = (unsigned __int8)a2;
      *(_QWORD *)(v22 + 8) = 0;
      v24 = v22;
      *(_WORD *)v22 = v23;
      v34 = v22;
      LOWORD(v33) = 5280;
      if ( !(unsigned int)scheduler_post_message_debug(
                            0x36u,
                            0x34u,
                            52,
                            (unsigned __int16 *)&v33,
                            0x1054u,
                            (__int64)"wma_get_roam_scan_ch") )
      {
        result = v21;
        goto LABEL_8;
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to post msg to SME",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wma_get_roam_scan_ch");
      _qdf_mem_free(v24);
    }
    goto LABEL_7;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
