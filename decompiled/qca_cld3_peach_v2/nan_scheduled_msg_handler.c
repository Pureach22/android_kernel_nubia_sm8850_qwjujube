__int64 __fastcall nan_scheduled_msg_handler(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x8
  int v10; // w9
  unsigned __int64 v11; // t2
  unsigned __int16 *v12; // x19
  unsigned int v13; // w4
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  bool v23; // cf
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v42)(); // [xsp+10h] [xbp-30h]
  __int64 v43; // [xsp+18h] [xbp-28h]
  __int64 v44; // [xsp+20h] [xbp-20h]
  __int64 v45; // [xsp+28h] [xbp-18h]
  __int64 *v46; // [xsp+30h] [xbp-10h]
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v45 = 0;
  v42 = nullptr;
  v43 = 0;
  v41 = 0;
  if ( a1 )
  {
    v9 = *((__int64 **)a1 + 1);
    if ( v9 )
    {
      HIDWORD(v11) = *a1 - 4;
      LODWORD(v11) = HIDWORD(v11);
      v10 = v11 >> 1;
      if ( v10 <= 1 )
      {
        if ( !v10 )
        {
          v12 = a1;
          v13 = 6;
          goto LABEL_15;
        }
        if ( v10 == 1 )
        {
          v12 = a1;
          v13 = 7;
          goto LABEL_15;
        }
      }
      else
      {
        switch ( v10 )
        {
          case 2:
            v12 = a1;
            v13 = 8;
            goto LABEL_15;
          case 6:
            v12 = a1;
            v13 = 9;
            goto LABEL_15;
          case 7:
            v12 = a1;
            v13 = 10;
LABEL_15:
            v41 = v13;
            v45 = *v9;
            v46 = v9;
            v42 = nan_serialized_cb;
            LODWORD(v43) = 15;
            LODWORD(v44) = 4000;
            qdf_trace_msg(0x53u, 8u, "%s: cmd_type: %d", a2, a3, a4, a5, a6, a7, a8, a9, "nan_scheduled_msg_handler");
            BYTE4(v43) = 2;
            v23 = (unsigned int)wlan_serialization_request((unsigned int *)&v41, v15, v16, v17, v18, v19, v20, v21, v22) >= 2;
            result = 0;
            if ( !v23 )
              goto LABEL_20;
            qdf_trace_msg(
              0x53u,
              2u,
              "%s: unable to serialize command",
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              "nan_scheduled_msg_handler");
            wlan_objmgr_vdev_release_ref(v45, 0x14u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
            _qdf_mem_free(*((_QWORD *)v12 + 1));
            *((_QWORD *)v12 + 1) = 0;
            goto LABEL_19;
        }
      }
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: wrong request type: %d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "nan_scheduled_msg_handler");
LABEL_19:
      result = 4;
      goto LABEL_20;
    }
  }
  qdf_trace_msg(0x53u, 1u, "%s: msg or bodyptr is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_scheduled_msg_handler");
  result = 29;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
