__int64 __fastcall hdd_wmm_sme_callback(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        int a12,
        unsigned int a13)
{
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w19
  __int64 v26; // x24
  __int64 v27; // x1
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
  __int64 v44; // x8
  __int64 v45; // x8
  __int64 v46; // x10
  __int64 v47; // x11
  __int64 v48; // x9
  __int64 v49; // x11
  __int64 v50; // x10
  __int64 v51; // x4
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x8
  __int64 v61; // x8
  __int64 v62; // x10
  __int64 v63; // x11
  __int64 v64; // x9
  __int64 v65; // x11
  __int64 v66; // x10

  qdf_trace_msg(0x33u, 8u, "%s: Entered, context %pK", a1, a2, a3, a4, a5, a6, a7, a8, "hdd_wmm_sme_callback", a10);
  if ( !a10 || *(_DWORD *)(a10 + 72) != 1464683864 )
    JUMPOUT(0x36F9D8);
  v25 = *(_DWORD *)(a10 + 32);
  if ( v25 >= 5 )
    JUMPOUT(0x36F9FC);
  v26 = *(_QWORD *)(a10 + 24) + 280LL * v25 + 1880;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: status %d flowid %d info %pK",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "hdd_wmm_sme_callback",
    (unsigned int)a12,
    a13,
    a11);
  if ( a12 > 299 )
  {
    if ( a12 != 300 )
    {
      if ( a12 == 400 )
        JUMPOUT(0x36F760);
      if ( a12 == 401 )
LABEL_44:
        JUMPOUT(0x36F644);
LABEL_16:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: unexpected SME Status=%d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_wmm_sme_callback",
        (unsigned int)a12);
    }
LABEL_41:
    JUMPOUT(0x36F930);
  }
  switch ( a12 )
  {
    case 0:
      qdf_trace_msg(0x33u, 8u, "%s: Setup is complete", v28, v29, v30, v31, v32, v33, v34, v35, "hdd_wmm_sme_callback");
      if ( a11 )
      {
        *(_BYTE *)(v26 + 6) = 1;
        v44 = *(_QWORD *)(a11 + 8);
        *(_QWORD *)(v26 + 8) = *(_QWORD *)a11;
        *(_QWORD *)(v26 + 16) = v44;
        v45 = *(_QWORD *)(a11 + 40);
        v46 = *(_QWORD *)(a11 + 16);
        v47 = *(_QWORD *)(a11 + 24);
        *(_QWORD *)(v26 + 40) = *(_QWORD *)(a11 + 32);
        *(_QWORD *)(v26 + 48) = v45;
        *(_QWORD *)(v26 + 24) = v46;
        *(_QWORD *)(v26 + 32) = v47;
        v49 = *(_QWORD *)(a11 + 56);
        v48 = *(_QWORD *)(a11 + 64);
        v50 = *(_QWORD *)(a11 + 48);
        *(_DWORD *)(v26 + 80) = *(_DWORD *)(a11 + 72);
        *(_QWORD *)(v26 + 64) = v49;
        *(_QWORD *)(v26 + 72) = v48;
        *(_QWORD *)(v26 + 56) = v50;
      }
      *(_DWORD *)(v26 + 2) = 16842752;
      if ( *(_DWORD *)(a10 + 16) != -1 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Explicit Qos, notifying user space",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "hdd_wmm_sme_callback");
        *(_DWORD *)(a10 + 36) = 0;
        hdd_wmm_notify_app(a10);
      }
      if ( a11 )
      {
        v51 = *(unsigned int *)(a11 + 36);
        if ( (_DWORD)v51 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Inactivity timer value = %d for AC=%d",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "hdd_wmm_sme_callback",
            v51,
            v25);
          hdd_wmm_enable_inactivity_timer(a10, *(unsigned int *)(a11 + 36));
        }
      }
      goto LABEL_44;
    case 1:
      JUMPOUT(0x36F548);
    case 2:
      JUMPOUT(0x36F48C);
    case 3:
      JUMPOUT(0x36F43C);
    case 4:
      JUMPOUT(0x36F4F0);
    case 5:
      JUMPOUT(0x36F53C);
    case 6:
      JUMPOUT(0x36F5B4);
    case 7:
      JUMPOUT(0x36F40C);
    case 8:
    case 206:
      goto LABEL_41;
    case 9:
      JUMPOUT(0x36F3AC);
    case 100:
      JUMPOUT(0x36F650);
    case 101:
      qdf_trace_msg(0x33u, 8u, "%s: Release failure", v28, v29, v30, v31, v32, v33, v34, v35, "hdd_wmm_sme_callback");
      if ( *(_DWORD *)(a10 + 16) != -1 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Explicit Qos, notifying user space",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "hdd_wmm_sme_callback");
        JUMPOUT(0x36F70C);
      }
      goto LABEL_41;
    case 102:
      JUMPOUT(0x36F334);
    case 103:
      JUMPOUT(0x36F4E4);
    case 104:
      return sub_36F318(51, v27, "%s: Release Invalid Params", "hdd_wmm_sme_callback");
    case 200:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Modification is complete, notify TL",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_wmm_sme_callback");
      if ( a11 )
      {
        *(_BYTE *)(v26 + 6) = 1;
        v60 = *(_QWORD *)(a11 + 8);
        *(_QWORD *)(v26 + 8) = *(_QWORD *)a11;
        *(_QWORD *)(v26 + 16) = v60;
        v61 = *(_QWORD *)(a11 + 40);
        v62 = *(_QWORD *)(a11 + 16);
        v63 = *(_QWORD *)(a11 + 24);
        *(_QWORD *)(v26 + 40) = *(_QWORD *)(a11 + 32);
        *(_QWORD *)(v26 + 48) = v61;
        *(_QWORD *)(v26 + 24) = v62;
        *(_QWORD *)(v26 + 32) = v63;
        v65 = *(_QWORD *)(a11 + 56);
        v64 = *(_QWORD *)(a11 + 64);
        v66 = *(_QWORD *)(a11 + 48);
        *(_DWORD *)(v26 + 80) = *(_DWORD *)(a11 + 72);
        *(_QWORD *)(v26 + 64) = v65;
        *(_QWORD *)(v26 + 72) = v64;
        *(_QWORD *)(v26 + 56) = v66;
      }
      if ( *(_DWORD *)(a10 + 16) != -1 )
        JUMPOUT(0x36F638);
      goto LABEL_44;
    case 201:
      JUMPOUT(0x36F6C8);
    case 202:
      JUMPOUT(0x36F6FC);
    case 203:
      JUMPOUT(0x36F6DC);
    case 204:
      JUMPOUT(0x36F3F8);
    case 205:
      JUMPOUT(0x36F5A0);
    case 207:
      JUMPOUT(0x36F71C);
    default:
      goto LABEL_16;
  }
}
