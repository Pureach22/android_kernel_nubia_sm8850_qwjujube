__int64 __fastcall sme_qos_process_ft_reassoc_rsp_ev(
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
  unsigned int v10; // w21
  __int64 v11; // x20
  unsigned int v12; // w22
  __int64 v14; // x19
  unsigned int v15; // w27
  __int64 v16; // x26
  _BYTE *v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x24
  __int64 v36; // x19
  int v37; // w20
  _BYTE *v38; // x22
  unsigned int v39; // w23
  _DWORD *v40; // x21
  int v41; // w25
  int v42; // w19
  _BYTE *v43; // x22
  unsigned int v44; // w20
  _DWORD *v45; // x21
  int v46; // w25
  __int64 v47; // x24
  unsigned int v48; // w23
  _BYTE *i; // x28
  _BYTE *v50; // x22
  unsigned int v51; // w6
  __int64 v52; // [xsp+8h] [xbp-28h]
  __int64 v53; // [xsp+10h] [xbp-20h]
  __int64 v54; // [xsp+10h] [xbp-20h]
  __int64 v55; // [xsp+18h] [xbp-18h]
  unsigned int v56; // [xsp+20h] [xbp-10h]
  _BYTE *v57; // [xsp+28h] [xbp-8h]

  v10 = (unsigned __int8)a2;
  if ( (unsigned __int8)a2 > 5u
    || (v11 = a2, v12 = (unsigned __int8)a2, (v14 = *(_QWORD *)(a1 + 17224) + 96LL * (unsigned __int8)a2) == 0) )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: The Session pointer is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_qos_process_ft_reassoc_rsp_ev");
    return 16;
  }
  v15 = *(_DWORD *)(v14 + 20);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: invoked on session %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "sme_qos_process_ft_reassoc_rsp_ev",
    (unsigned __int8)a2);
  v16 = qword_856120;
  v17 = (_BYTE *)(*(_QWORD *)(v14 + 32)
                + (unsigned int)(*(_DWORD *)(v14 + 12) + *(_DWORD *)(v14 + 8) + *(_DWORD *)(v14 + 16)));
  v52 = v11;
  if ( !wlan_cm_is_roam_sync_in_progress(*(_QWORD *)(a1 + 21552), (unsigned int)v11) )
  {
    v54 = a1;
    v47 = 0;
    v48 = v15;
    for ( i = (_BYTE *)(v16 + 3040LL * v12 + 325); ; i += 728 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: invoked on session %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "sme_qos_find_matching_tspec",
        v10);
      if ( !*(i - 1) )
        goto LABEL_36;
      if ( !v48 )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: RIC Response not received for AC %d on TSPEC Index %d, RIC Req Identifier = %d",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "sme_qos_find_matching_tspec",
          (unsigned int)v47,
          0);
        if ( !*i )
          goto LABEL_28;
        goto LABEL_27;
      }
      if ( *v17 && v17[2] )
      {
        if ( v17[3] == *(i - 1) )
        {
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Processing RIC Response for AC %d, TSPEC Flow index %d with RIC ID %d",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            "sme_qos_find_matching_tspec",
            (unsigned int)v47,
            0,
            (unsigned __int8)v17[3]);
          ((void (__fastcall *)(__int64, _QWORD, _BYTE *, _QWORD, _QWORD))sme_qos_process_ftric_response)(
            v54,
            (unsigned int)v11,
            v17,
            (unsigned int)v47,
            0);
        }
        else
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: RIC response order not same as request sent. Request ID = %d, Response ID = %d",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            "sme_qos_find_matching_tspec",
            (unsigned __int8)*(i - 1),
            (unsigned __int8)v17[3]);
        }
        v50 = v17 + 636;
        v48 -= 636;
        v51 = (unsigned __int8)*i;
        if ( !*i )
          goto LABEL_29;
      }
      else
      {
LABEL_36:
        v50 = v17;
        v51 = (unsigned __int8)*i;
        if ( !*i )
          goto LABEL_29;
      }
      if ( v48 )
      {
        if ( *v50 && v50[2] )
        {
          if ( (unsigned __int8)v50[3] == v51 )
          {
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: Processing RIC Response for AC %d, TSPEC Flow index %d with RIC ID %d",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "sme_qos_find_matching_tspec",
              (unsigned int)v47,
              1,
              (unsigned __int8)v50[3]);
            ((void (__fastcall *)(__int64, _QWORD, _BYTE *, _QWORD, __int64))sme_qos_process_ftric_response)(
              v54,
              (unsigned int)v11,
              v50,
              (unsigned int)v47,
              1);
          }
          else
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: RIC response order not same as request sent. Request ID = %d, Response ID = %d",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "sme_qos_find_matching_tspec",
              v51,
              (unsigned __int8)v50[3]);
          }
          v48 -= 636;
        }
        goto LABEL_29;
      }
LABEL_27:
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: RIC Response not received for AC %d on TSPEC Index %d, RIC Req Identifier = %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "sme_qos_find_matching_tspec",
        (unsigned int)v47,
        1);
LABEL_28:
      v48 = 0;
LABEL_29:
      if ( ++v47 == 4 )
      {
        if ( v48 )
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: RIC Resp still follows . Rem len = %d",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            "sme_qos_process_ft_reassoc_rsp_ev",
            v48);
        return sme_qos_ft_aggr_qos_req(v52);
      }
    }
  }
  v57 = v17;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: LFR3-11r Compare RIC in Reassoc Resp to find matching tspec in host",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "sme_qos_process_ft_reassoc_rsp_ev");
  if ( v15 && *v17 && v17[448] )
  {
    v34 = 0;
    v56 = v10;
    v53 = a1;
    v55 = v16 + 3040LL * v12 + 4;
    do
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: invoked on session %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "sme_qos_find_matching_tspec_lfr3",
        v10);
      v36 = v55 + 728 * v34;
      if ( (*(_BYTE *)(v36 + 317) & 1) != 0 )
      {
        v37 = *(_DWORD *)(v36 + 180);
        v38 = v57;
        v39 = v15;
        while ( 1 )
        {
          v40 = v38 + 450;
          v41 = sme_qos_up_to_ac_map[((unsigned __int64)*(unsigned int *)(v38 + 450) >> 11) & 7];
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: up = %d ac = %d returned",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "sme_qos_up_to_ac");
          if ( (unsigned __int8)v41 == 4 )
            break;
          if ( v34 == (unsigned __int8)v41 && ((*v40 >> 5) & 3) == v37 )
          {
            ((void (__fastcall *)(__int64, __int64, _BYTE *, _QWORD, _QWORD))sme_qos_process_ftric_response)(
              v53,
              v52,
              v38,
              (unsigned int)v34,
              0);
            goto LABEL_19;
          }
          v39 -= 636;
          v38 += 636;
          if ( !v39 )
            goto LABEL_19;
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Invalid AC %d UP %d",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "sme_qos_find_matching_tspec_lfr3",
          4,
          (*v40 >> 11) & 7);
      }
LABEL_19:
      if ( (*(_BYTE *)(v36 + 317) & 2) != 0 )
      {
        v42 = *(_DWORD *)(v36 + 256);
        v43 = v57;
        v44 = v15;
        while ( 1 )
        {
          v45 = v43 + 450;
          v46 = sme_qos_up_to_ac_map[((unsigned __int64)*(unsigned int *)(v43 + 450) >> 11) & 7];
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: up = %d ac = %d returned",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "sme_qos_up_to_ac");
          if ( (unsigned __int8)v46 == 4 )
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Invalid AC %d UP %d",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "sme_qos_find_matching_tspec_lfr3",
              4,
              (*v45 >> 11) & 7);
            goto LABEL_10;
          }
          if ( v34 == (unsigned __int8)v46 && ((*v45 >> 5) & 3) == v42 )
            break;
          v44 -= 636;
          v43 += 636;
          if ( !v44 )
            goto LABEL_10;
        }
        ((void (__fastcall *)(__int64, __int64, _BYTE *, _QWORD, __int64))sme_qos_process_ftric_response)(
          v53,
          v52,
          v43,
          (unsigned int)v34,
          1);
      }
LABEL_10:
      ++v34;
      v10 = v56;
    }
    while ( v34 != 4 );
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: LFR3-11r ric_rsplen is zero or ric_data_desc is not present or wmmtspec is not present",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "sme_qos_process_ft_reassoc_rsp_ev");
  }
  return sme_qos_ft_aggr_qos_req(v52);
}
