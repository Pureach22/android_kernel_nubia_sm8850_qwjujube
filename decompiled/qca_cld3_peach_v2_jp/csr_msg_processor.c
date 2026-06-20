__int64 __fastcall csr_msg_processor(_QWORD *a1, unsigned __int16 *a2)
{
  unsigned int v2; // w19
  int v5; // w21
  unsigned __int16 v6; // w22
  const char *sme_msg_string; // x0
  unsigned int v8; // w24
  const char *v9; // x25
  const char *v10; // x26
  const char *v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w0
  __int64 v29; // x0
  const char *v30; // x0
  unsigned int v31; // w20
  const char *v32; // x23
  const char *v33; // x21
  const char *v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v44; // [xsp+0h] [xbp-10h]

  v2 = *((unsigned __int8 *)a2 + 4);
  v5 = ((__int64 (__fastcall *)(_QWORD *, _QWORD))sme_get_current_roam_state)(a1, *((unsigned __int8 *)a2 + 4));
  v6 = ((__int64 (__fastcall *)(_QWORD *, _QWORD))sme_get_current_roam_sub_state)(a1, v2);
  sme_msg_string = mac_trace_get_sme_msg_string(*a2);
  v8 = *a2;
  v9 = sme_msg_string;
  v10 = mac_trace_getcsr_roam_state(v5);
  v11 = mac_trace_getcsr_roam_sub_state(v6);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: msg %s[0x%04X] in %s[%s] vdev %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "csr_msg_processor",
    v9,
    v8,
    v10,
    v11,
    v2);
  if ( v5 == 2 )
  {
    csr_roaming_state_msg_processor((__int64)a1, a2, v20, v21, v22, v23, v24, v25, v26, v27);
  }
  else if ( v5 == 3 )
  {
    csr_roam_joined_state_msg_processor(a1, a2, v20, v21, v22, v23, v24, v25, v26, v27);
  }
  else
  {
    v28 = *a2;
    if ( v28 == 5125 || v28 == 5135 )
    {
      csr_roam_check_for_link_status_change((__int64)a1, a2, v20, v21, v22, v23, v24, v25, v26, v27);
    }
    else if ( v28 == 5158 )
    {
      v29 = *((_QWORD *)a2 + 335);
      if ( v29 )
        _qdf_mem_free(v29);
    }
    else
    {
      v30 = mac_trace_get_sme_msg_string(v28);
      v31 = *a2;
      v32 = v30;
      v33 = mac_trace_getcsr_roam_state(v5);
      v34 = mac_trace_getcsr_roam_sub_state(v6);
      LODWORD(v44) = v2;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: msg %s[0x%04X] not handled in %s[%s] for vdev %d",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "csr_msg_processor",
        v32,
        v31,
        v33,
        v34,
        v44);
    }
  }
  return 0;
}
