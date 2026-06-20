__int64 __fastcall policy_mgr_is_mcc_with_this_vdev_id(__int64 a1, unsigned __int8 a2, _BYTE *a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  char v25; // w22
  int v26; // w23
  unsigned int v27; // w21
  int v28; // w24
  char v29; // w8
  int v30; // w24
  char v31; // w8
  int v32; // w24
  char v33; // w8
  int v34; // w24
  char v35; // w8
  int v36; // w23
  char v37; // w8
  unsigned int v38; // [xsp+Ch] [xbp-C4h] BYREF
  _QWORD v39[3]; // [xsp+10h] [xbp-C0h] BYREF
  __int64 v40; // [xsp+28h] [xbp-A8h]
  __int64 v41; // [xsp+30h] [xbp-A0h]
  __int64 v42; // [xsp+38h] [xbp-98h]
  __int64 v43; // [xsp+40h] [xbp-90h]
  __int64 v44; // [xsp+48h] [xbp-88h]
  __int64 v45; // [xsp+50h] [xbp-80h]
  __int64 v46; // [xsp+58h] [xbp-78h]
  __int64 v47; // [xsp+60h] [xbp-70h]
  __int64 v48; // [xsp+68h] [xbp-68h]
  __int64 v49; // [xsp+70h] [xbp-60h]
  __int64 v50; // [xsp+78h] [xbp-58h]
  __int64 v51; // [xsp+80h] [xbp-50h]
  __int64 v52; // [xsp+88h] [xbp-48h]
  __int64 v53; // [xsp+90h] [xbp-40h]
  __int64 v54; // [xsp+98h] [xbp-38h]
  __int64 v55; // [xsp+A0h] [xbp-30h]
  __int64 v56; // [xsp+A8h] [xbp-28h]
  __int64 v57; // [xsp+B0h] [xbp-20h]
  __int64 v58; // [xsp+B8h] [xbp-18h]
  int v59; // [xsp+C0h] [xbp-10h]
  __int64 v60; // [xsp+C8h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v40 = 0;
  memset(v39, 0, sizeof(v39));
  if ( a3 )
    *a3 = -1;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_is_mcc_with_this_vdev_id");
    goto LABEL_7;
  }
  v15 = context;
  v38 = 0;
  if ( (unsigned int)policy_mgr_get_chan_by_session_id(a1, a2, &v38) )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to get channel for vdev:%d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "policy_mgr_is_mcc_with_this_vdev_id",
      a2);
LABEL_7:
    result = 0;
    goto LABEL_8;
  }
  result = policy_mgr_get_sta_p2p_conn_info(v15, v39);
  if ( !(_DWORD)result )
    goto LABEL_8;
  v25 = v40;
  v26 = a2;
  v27 = v38;
  if ( (_DWORD)v40 == v26
    || HIDWORD(v39[0]) == v38
    || (v28 = result,
        v29 = policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(v39[0]), v38),
        LODWORD(result) = v28,
        (v29 & 1) == 0) )
  {
    if ( (_DWORD)result == 1 )
      goto LABEL_7;
    v25 = BYTE4(v44);
    if ( HIDWORD(v44) == v26
      || (_DWORD)v42 == v27
      || (v30 = result, v31 = policy_mgr_are_2_freq_on_same_mac(a1, v42, v27), LODWORD(result) = v30, (v31 & 1) == 0) )
    {
      if ( (_DWORD)result == 2 )
        goto LABEL_7;
      v25 = v49;
      if ( (_DWORD)v49 == v26
        || HIDWORD(v46) == v27
        || (v32 = result,
            v33 = policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(v46), v27),
            LODWORD(result) = v32,
            (v33 & 1) == 0) )
      {
        if ( (_DWORD)result == 3 )
          goto LABEL_7;
        v25 = BYTE4(v53);
        if ( HIDWORD(v53) == v26
          || (_DWORD)v51 == v27
          || (v34 = result, v35 = policy_mgr_are_2_freq_on_same_mac(a1, v51, v27), LODWORD(result) = v34, (v35 & 1) == 0) )
        {
          if ( (_DWORD)result == 4 )
            goto LABEL_7;
          v25 = v58;
          if ( (_DWORD)v58 == v26
            || HIDWORD(v55) == v27
            || (v36 = result,
                v37 = policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(v55), v27),
                LODWORD(result) = v36,
                (v37 & 1) == 0) )
          {
            if ( (_DWORD)result != 5 )
              __break(0x5512u);
            goto LABEL_7;
          }
        }
      }
    }
  }
  if ( a3 )
    *a3 = v25;
  result = 1;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
