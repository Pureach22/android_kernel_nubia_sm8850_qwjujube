__int64 __fastcall wlan_hdd_reset_prob_rspies(
        __int64 *a1,
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
  int v10; // w4
  int *v11; // x9
  int v12; // w10
  __int16 v13; // w9
  __int16 v14; // w11
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  __int64 v27; // [xsp+8h] [xbp-18h]
  __int64 v28; // [xsp+10h] [xbp-10h]
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v27 = 0;
  v10 = *(_DWORD *)(v9 + 40);
  if ( v10 <= 1 )
  {
    if ( v10 )
    {
      if ( v10 != 1 )
        goto LABEL_15;
      goto LABEL_8;
    }
LABEL_7:
    v11 = (int *)a1 + 77;
    goto LABEL_9;
  }
  if ( v10 != 3 )
  {
    if ( v10 != 2 )
    {
LABEL_15:
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: Unexpected request for the current device type %d",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "wlan_hdd_reset_prob_rspies");
      goto LABEL_16;
    }
    goto LABEL_7;
  }
LABEL_8:
  v11 = (int *)(v9 + 1617);
LABEL_9:
  v12 = *v11;
  v13 = *((_WORD *)v11 + 2);
  v14 = *((unsigned __int8 *)a1 + 8);
  v28 = 0;
  WORD2(v26) = v13;
  LODWORD(v26) = v12;
  HIWORD(v26) = v14;
  LOBYTE(v27) = 1;
  if ( v9 && (v15 = *(_QWORD *)(v9 + 24)) != 0 )
    v16 = *(_QWORD *)(v15 + 16);
  else
    v16 = 0;
  result = sme_update_add_ie(v16, &v26, 2);
  if ( (_DWORD)result == 16 )
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: Could not pass on PROBE_RSP_BCN data to PE",
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               "wlan_hdd_reset_prob_rspies",
               v26,
               v27,
               v28,
               v29);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
