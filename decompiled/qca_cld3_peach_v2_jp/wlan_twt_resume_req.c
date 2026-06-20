__int64 __fastcall wlan_twt_resume_req(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w1
  unsigned int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w19
  __int64 result; // x0
  char v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w21
  unsigned int v45; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD *)(a2 + 12);
  v45 = 0;
  v7 = wlan_twt_check_all_twt_support(a1, v6);
  if ( v7 )
  {
    v16 = v7;
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: All TWT sessions not supported by target",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlan_twt_resume_req");
    result = v16;
  }
  else
  {
    v18 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))wlan_twt_is_setup_done)(
            a1,
            a2 + 4,
            *(unsigned int *)(a2 + 12));
    v27 = *(_DWORD *)(a2 + 12);
    if ( (v18 & 1) != 0 )
    {
      if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, unsigned int *))wlan_twt_is_command_in_progress)(
              a1,
              a2 + 4,
              v27,
              255,
              &v45)
          & 1) != 0 )
      {
        qdf_trace_msg(
          0x96u,
          8u,
          "%s: Already TWT command:%d is in progress",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "wlan_twt_resume_req",
          v45);
        result = 24;
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))wlan_twt_set_command_in_progress)(
          a1,
          a2 + 4,
          *(unsigned int *)(a2 + 12),
          8);
        ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))wlan_twt_set_ack_context)(
          a1,
          a2 + 4,
          *(unsigned int *)(a2 + 12),
          a3);
        result = tgt_twt_resume_req_send(a1, a2);
        if ( (_DWORD)result )
        {
          v44 = result;
          qdf_trace_msg(
            0x96u,
            2u,
            "%s: tgt_twt_resume_req_send failed (status=%d)",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "wlan_twt_resume_req",
            (unsigned int)result);
          ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))wlan_twt_set_command_in_progress)(
            a1,
            a2 + 4,
            *(unsigned int *)(a2 + 12),
            0);
          result = v44;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x96u,
        2u,
        "%s: TWT setup is not complete for dialog_id:%d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "wlan_twt_resume_req",
        v27);
      result = 3;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
