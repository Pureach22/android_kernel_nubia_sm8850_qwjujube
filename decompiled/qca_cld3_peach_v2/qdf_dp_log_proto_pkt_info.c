__int64 __fastcall qdf_dp_log_proto_pkt_info(
        __int64 result,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        unsigned __int16 a6,
        unsigned __int8 a7)
{
  unsigned __int8 *v10; // x23
  unsigned __int8 v11; // w10
  __int64 v12; // x11
  __int64 v13; // x10
  char *v14; // x9
  const char *v15; // x19
  __int64 pkt_type_string; // x3
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  int v28; // w8
  int v29; // w9
  int v30; // w10
  int v31; // w11
  int v32; // w12
  int v33; // w12
  const char *v34; // x14
  const char *v35; // x2
  int v36; // [xsp+20h] [xbp-20h]
  int v37; // [xsp+28h] [xbp-18h]
  const char *v38; // [xsp+30h] [xbp-10h]

  v10 = (unsigned __int8 *)result;
  if ( (a3 & 0xF8) != 0 )
    v11 = 1;
  else
    v11 = 0x501010101053214uLL >> (8 * (unsigned __int8)a3);
  if ( a5 )
  {
    if ( a5 == 1 )
    {
      if ( (unsigned __int8)a4 <= 0x3Eu )
      {
        v12 = 0xFAu / v11;
        v13 = (unsigned __int8)a4;
        if ( qdf_dp_log_proto_pkt_info_last_ticks_rx[(unsigned __int8)a4] - jiffies + v12 >= 0 )
          return result;
        goto LABEL_14;
      }
    }
    else if ( (unsigned __int8)a4 <= 0x3Eu )
    {
      v13 = (unsigned __int8)a4;
LABEL_14:
      v14 = (char *)&qdf_dp_log_proto_pkt_info_last_ticks_rx[v13];
      v15 = (const char *)&unk_A39F4F;
      goto LABEL_15;
    }
LABEL_33:
    __break(0x5512u);
    return ((__int64 (*)(void))qdf_get_pkt_type_string)();
  }
  if ( (unsigned __int8)a4 >= 0x3Fu )
    goto LABEL_33;
  v14 = (char *)&qdf_dp_log_proto_pkt_info_last_ticks_tx + 8 * (unsigned __int8)a4;
  if ( (__int64)(*(_QWORD *)v14 - jiffies + 0xFAu / v11) >= 0 )
    return result;
  v15 = "TX";
LABEL_15:
  *(_QWORD *)v14 = jiffies;
  pkt_type_string = qdf_get_pkt_type_string(a3, a4);
  if ( a7 )
  {
    if ( v10 )
    {
      v25 = *v10;
      v26 = v10[1];
      v27 = v10[2];
      v28 = v10[5];
      if ( a2 )
      {
LABEL_18:
        v29 = *a2;
        v30 = a2[1];
        v31 = a2[2];
        v32 = a2[5];
LABEL_24:
        if ( a7 > 4u )
          v34 = "unknown";
        else
          v34 = off_AD0010[(char)a7 - 1];
        v35 = "%s %s: SA:%02x:%02x:%02x:**:**:%02x DA:%02x:%02x:%02x:**:**:%02x msdu_id:%d status: %s";
        v38 = v34;
        v37 = a6;
        v36 = v32;
        return qdf_trace_msg(
                 0x38u,
                 4u,
                 v35,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 pkt_type_string,
                 v15,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v36,
                 v37,
                 v38);
      }
    }
    else
    {
      v27 = 0;
      v25 = 0;
      v26 = 0;
      v28 = 0;
      if ( a2 )
        goto LABEL_18;
    }
    v31 = 0;
    v29 = 0;
    v30 = 0;
    v32 = 0;
    goto LABEL_24;
  }
  if ( !v10 )
  {
    v27 = 0;
    v25 = 0;
    v26 = 0;
    v28 = 0;
    if ( a2 )
      goto LABEL_21;
LABEL_29:
    v31 = 0;
    v29 = 0;
    v30 = 0;
    v33 = 0;
    goto LABEL_30;
  }
  v25 = *v10;
  v26 = v10[1];
  v27 = v10[2];
  v28 = v10[5];
  if ( !a2 )
    goto LABEL_29;
LABEL_21:
  v29 = *a2;
  v30 = a2[1];
  v31 = a2[2];
  v33 = a2[5];
LABEL_30:
  v36 = v33;
  v35 = "%s %s: SA:%02x:%02x:%02x:**:**:%02x DA:%02x:%02x:%02x:**:**:%02x";
  return qdf_trace_msg(
           0x38u,
           4u,
           v35,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           pkt_type_string,
           v15,
           v25,
           v26,
           v27,
           v28,
           v29,
           v30,
           v31,
           v36,
           v37,
           v38);
}
