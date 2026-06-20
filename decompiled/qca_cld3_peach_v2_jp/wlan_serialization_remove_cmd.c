__int64 __fastcall wlan_serialization_remove_cmd(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  unsigned int v19; // w8
  unsigned int v20; // w9
  __int64 v21; // x10
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // [xsp+8h] [xbp-38h] BYREF
  unsigned int v31; // [xsp+Ch] [xbp-34h]
  __int64 v32; // [xsp+10h] [xbp-30h]
  __int64 v33; // [xsp+18h] [xbp-28h]
  __int64 v34; // [xsp+20h] [xbp-20h]
  __int64 v35; // [xsp+28h] [xbp-18h]
  __int64 v36; // [xsp+30h] [xbp-10h]
  __int64 v37; // [xsp+38h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v32 = 0;
  if ( a1 )
  {
    if ( (unsigned int)wlan_serialization_validate_cmd(*a1, a1[1]) )
    {
      result = qdf_trace_msg(
                 0x4Cu,
                 2u,
                 "%s: cmd type %d is not valid",
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 "wlan_serialization_remove_cmd",
                 a1[1]);
    }
    else
    {
      v19 = a1[2];
      v20 = *a1;
      v21 = *((_QWORD *)a1 + 2);
      v30 = a1[1];
      v31 = v19;
      LODWORD(v33) = v20;
      v35 = v21;
      result = wlan_serialization_dequeue_cmd(&v30, 1, 1);
      if ( (result & 0xFFFFFFFD) != 1 )
        result = qdf_trace_msg(
                   0x4Cu,
                   8u,
                   "%s: Can't dequeue requested id %d type %d requestor %d",
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   "wlan_serialization_remove_cmd",
                   v31,
                   v30,
                   *a1);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x4Cu,
               2u,
               "%s: given request is empty",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "wlan_serialization_remove_cmd");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
