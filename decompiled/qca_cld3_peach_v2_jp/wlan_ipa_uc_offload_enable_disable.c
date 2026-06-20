__int64 __fastcall wlan_ipa_uc_offload_enable_disable(
        _QWORD *a1,
        unsigned int a2,
        unsigned __int8 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w19
  __int64 result; // x0
  __int64 v14; // x22
  unsigned int v15; // w21
  char *v16; // x23
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  unsigned int v27; // w1
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _DWORD v38[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v39; // [xsp+18h] [xbp-8h]

  v12 = a3;
  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 < 5u )
  {
    v14 = a3;
    v15 = a4 & 1;
    v16 = (char *)a1 + 7293;
    if ( *((unsigned __int8 *)a1 + a3 + 7293) == v15 )
    {
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: IPA offload status is already set",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wlan_ipa_uc_offload_enable_disable");
      v26 = "%s: offload_type=%d, vdev_id=%d, enable=%d";
      v27 = 4;
    }
    else
    {
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: offload_type=%d, session_id=%d, enable=%d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wlan_ipa_uc_offload_enable_disable",
        a2,
        a3,
        a4 & 1);
      v29 = *a1;
      v38[0] = a2;
      v38[1] = v12;
      v38[2] = v15;
      result = ipa_send_uc_offload_enable_disable(v29, v38);
      if ( !(_DWORD)result )
      {
        v16[v14] = v15;
        goto LABEL_8;
      }
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: Fail to enable IPA offload",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wlan_ipa_uc_offload_enable_disable");
      v26 = "%s: offload type=%d, vdev_id=%d, enable=%d";
      v27 = 2;
    }
    result = qdf_trace_msg(
               0x61u,
               v27,
               v26,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               "wlan_ipa_uc_offload_enable_disable",
               a2,
               v12,
               v15);
  }
  else
  {
    result = qdf_trace_msg(
               0x61u,
               2u,
               "%s: invalid session id: %d",
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "wlan_ipa_uc_offload_enable_disable",
               a3);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
