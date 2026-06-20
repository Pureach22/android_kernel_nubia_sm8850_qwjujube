__int64 __fastcall lim_obss_send_detection_cfg(
        int a1,
        unsigned __int8 *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int detection_config; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w19
  __int64 result; // x0
  __int64 v24; // x4
  const char *v25; // x2
  __int64 v26; // x0
  _DWORD *v27; // x19
  int v28; // w9
  int v29; // w10
  int v30; // w11
  int v31; // w8
  int v32; // w9
  int v33; // w8
  unsigned int v34; // w20
  __int64 v35; // [xsp+0h] [xbp-40h] BYREF
  _DWORD *v36; // [xsp+8h] [xbp-38h]
  __int64 v37; // [xsp+10h] [xbp-30h]
  __int64 v38; // [xsp+18h] [xbp-28h]
  __int64 v39; // [xsp+20h] [xbp-20h]
  __int64 v40; // [xsp+28h] [xbp-18h]
  unsigned __int8 v41[8]; // [xsp+30h] [xbp-10h] BYREF
  __int64 v42; // [xsp+38h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)&v41[3] = 0;
  *(_DWORD *)v41 = 0;
  if ( !a2 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: Invalid session", a4, a5, a6, a7, a8, a9, a10, a11, "lim_obss_send_detection_cfg");
    result = 4;
    goto LABEL_10;
  }
  if ( (a2[10006] & 1) == 0 )
  {
    v24 = a2[10];
    v25 = "%s: obss offload protectiond disabled, session %d";
LABEL_9:
    qdf_trace_msg(0x35u, 8u, v25, a4, a5, a6, a7, a8, a9, a10, a11, "lim_obss_send_detection_cfg", v24);
    result = 0;
    goto LABEL_10;
  }
  if ( !a2[428] )
  {
    v24 = a2[10];
    v25 = "%s: protectiond disabled, force from policy, session %d";
    goto LABEL_9;
  }
  detection_config = lim_obss_generate_detection_config(a1, (int)a2, (int)v41);
  if ( detection_config )
  {
    v22 = detection_config;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to generate obss detection cfg, session %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "lim_obss_send_detection_cfg",
      a2[10]);
    result = v22;
    goto LABEL_10;
  }
  if ( !(unsigned int)qdf_mem_cmp(a2 + 9992, v41, 7u) && (a3 & 1) == 0 )
  {
    v25 = "%s: Skipping WMA_OBSS_DETECTION_REQ, force = %d";
    v24 = 0;
    goto LABEL_9;
  }
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = nullptr;
  v26 = _qdf_mem_malloc(0x24u, "lim_obss_send_detection_cfg", 1466);
  if ( v26 )
  {
    v27 = (_DWORD *)v26;
    qdf_mem_copy(a2 + 9992, v41, 7u);
    *v27 = a2[10];
    v27[1] = 4000;
    v28 = v41[1];
    v29 = v41[2];
    v30 = v41[6];
    v27[2] = v41[0];
    v27[3] = v28;
    v31 = v41[3];
    v32 = v41[5];
    v36 = v27;
    v27[4] = v29;
    v27[5] = v31;
    v33 = v41[4];
    v27[7] = v32;
    v27[8] = v30;
    v27[6] = v33;
    LODWORD(v35) = 4521;
    result = scheduler_post_message_debug(
               0x35u,
               0x36u,
               54,
               (unsigned __int16 *)&v35,
               0x5D5u,
               (__int64)"lim_obss_send_detection_cfg");
    if ( (_DWORD)result )
    {
      v34 = result;
      _qdf_mem_free((__int64)v27);
      result = v34;
    }
  }
  else
  {
    result = 2;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
