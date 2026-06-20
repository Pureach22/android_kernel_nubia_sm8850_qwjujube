_BYTE *__fastcall sme_send_mscs_action_frame(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x21
  _BYTE *result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  __int64 v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  char v30; // w20
  __int64 v31; // x4
  char v32; // w9
  const char *v33; // x2
  __int64 v34; // [xsp+8h] [xbp-38h] BYREF
  __int64 v35; // [xsp+10h] [xbp-30h]
  __int64 v36; // [xsp+18h] [xbp-28h]
  __int64 v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  __int64 v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = qword_91F2D8 + 3040LL * a1;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  if ( v10 )
  {
    result = (_BYTE *)_qdf_mem_malloc(0x38u, "sme_send_mscs_action_frame", 3615);
    if ( result )
    {
      *result = a1;
      v20 = (__int64)result;
      v21 = *(_QWORD *)(v10 + 2920);
      if ( !v21 )
      {
        v33 = "%s: BSS descriptor is NULL so we won't send request to PE";
        goto LABEL_11;
      }
      qdf_mem_copy(result + 1, (const void *)(v21 + 2), 6u);
      v30 = byte_91F344;
      v31 = (unsigned __int8)byte_91F344;
      if ( (((unsigned __int8)byte_91F344 + 1) & 0x100) != 0 )
        v32 = 1;
      else
        v32 = byte_91F344 + 1;
      byte_91F344 = v32;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: token %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "sme_qos_assign_dialog_token",
        v31);
      *(_WORD *)(v20 + 10) = 1984;
      *(_QWORD *)(v20 + 16) = 60000;
      *(_WORD *)(v20 + 24) = 24324;
      *(_BYTE *)(v20 + 7) = v30;
      *(_BYTE *)(v20 + 8) = 0;
      LODWORD(v34) = 5153;
      v35 = v20;
      result = (_BYTE *)scheduler_post_message_debug(
                          0x34u,
                          0x35u,
                          53,
                          (unsigned __int16 *)&v34,
                          0xE38u,
                          (__int64)"sme_send_mscs_action_frame");
      if ( (_DWORD)result )
      {
        v33 = "%s: Fail to send mscs request to PE";
LABEL_11:
        qdf_trace_msg(0x34u, 2u, v33, v12, v13, v14, v15, v16, v17, v18, v19, "sme_send_mscs_action_frame");
        result = (_BYTE *)_qdf_mem_free(v20);
      }
    }
  }
  else
  {
    result = (_BYTE *)qdf_trace_msg(
                        0x34u,
                        8u,
                        "%s: qos_session is NULL",
                        a2,
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        "sme_send_mscs_action_frame");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
