__int64 __fastcall _osif_twt_work_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x19
  unsigned int v11; // w20
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  const char *v85; // x2
  const char *v86; // x3
  unsigned int v87; // w1
  int v88; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v89; // [xsp+8h] [xbp-38h] BYREF
  __int64 v90; // [xsp+10h] [xbp-30h]
  unsigned __int64 v91; // [xsp+18h] [xbp-28h] BYREF
  __int64 v92; // [xsp+20h] [xbp-20h]
  _QWORD v93[3]; // [xsp+28h] [xbp-18h] BYREF

  v93[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 152);
  LODWORD(v92) = 0;
  v89 = 0;
  v90 = 0;
  v88 = 0;
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v85 = "%s: psoc is null";
    v86 = "__osif_twt_work_handler";
    v87 = 2;
LABEL_19:
    result = qdf_trace_msg(0x48u, v87, v85, a2, a3, a4, a5, a6, a7, a8, a9, v86);
    goto LABEL_20;
  }
  v11 = *(unsigned __int8 *)(a1 + 104);
  ucfg_twt_get_work_params(a1, (__int64)&v89, &v88);
  if ( v88 != 1 )
  {
    v85 = "%s: Do not send STA teardown req as TWT renegotiation or power save work is not scheduled";
    v86 = "__osif_twt_work_handler";
    goto LABEL_18;
  }
  LOWORD(v92) = WORD2(v89);
  HIDWORD(v92) = v90;
  v91 = __PAIR64__(v89, v11);
  result = osif_send_sta_twt_teardown_req(v10, (__int64)&v91);
  if ( (_DWORD)result == -16 && BYTE4(v90) == 1 )
  {
    v93[0] = v91;
    v93[1] = v92;
    qdf_sleep();
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Implicitly TWT teardown req retry count:%d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "osif_twt_teardown_req_retry",
      1);
    result = osif_send_sta_twt_teardown_req(v10, (__int64)v93);
    if ( (_DWORD)result == -16 )
    {
      qdf_sleep();
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: Implicitly TWT teardown req retry count:%d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "osif_twt_teardown_req_retry",
        2);
      result = osif_send_sta_twt_teardown_req(v10, (__int64)v93);
      if ( (_DWORD)result == -16 )
      {
        qdf_sleep();
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: Implicitly TWT teardown req retry count:%d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "osif_twt_teardown_req_retry",
          3);
        result = osif_send_sta_twt_teardown_req(v10, (__int64)v93);
        if ( (_DWORD)result == -16 )
        {
          qdf_sleep();
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: Implicitly TWT teardown req retry count:%d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "osif_twt_teardown_req_retry",
            4);
          result = osif_send_sta_twt_teardown_req(v10, (__int64)v93);
          if ( (_DWORD)result == -16 )
          {
            qdf_sleep();
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: Implicitly TWT teardown req retry count:%d",
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              "osif_twt_teardown_req_retry",
              5);
            result = osif_send_sta_twt_teardown_req(v10, (__int64)v93);
            if ( (_DWORD)result == -16 )
            {
              qdf_sleep();
              qdf_trace_msg(
                0x48u,
                8u,
                "%s: Implicitly TWT teardown req retry count:%d",
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                "osif_twt_teardown_req_retry",
                6);
              result = osif_send_sta_twt_teardown_req(v10, (__int64)v93);
              if ( (_DWORD)result == -16 )
              {
                qdf_sleep();
                qdf_trace_msg(
                  0x48u,
                  8u,
                  "%s: Implicitly TWT teardown req retry count:%d",
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  v67,
                  v68,
                  "osif_twt_teardown_req_retry",
                  7);
                result = osif_send_sta_twt_teardown_req(v10, (__int64)v93);
                if ( (_DWORD)result == -16 )
                {
                  qdf_sleep();
                  qdf_trace_msg(
                    0x48u,
                    8u,
                    "%s: Implicitly TWT teardown req retry count:%d",
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    "osif_twt_teardown_req_retry",
                    8);
                  result = osif_send_sta_twt_teardown_req(v10, (__int64)v93);
                  if ( (_DWORD)result == -16 )
                  {
                    qdf_sleep();
                    qdf_trace_msg(
                      0x48u,
                      8u,
                      "%s: Implicitly TWT teardown req retry count:%d",
                      v77,
                      v78,
                      v79,
                      v80,
                      v81,
                      v82,
                      v83,
                      v84,
                      "osif_twt_teardown_req_retry",
                      9);
                    result = osif_send_sta_twt_teardown_req(v10, (__int64)v93);
                    if ( (_DWORD)result == -16 )
                    {
                      v85 = "%s: TWT Del Dialog req max retries reached";
                      v86 = "osif_twt_teardown_req_retry";
LABEL_18:
                      v87 = 8;
                      goto LABEL_19;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
