__int64 __fastcall wlan_sm_create(
        __int64 a1,
        __int64 a2,
        char a3,
        __int64 a4,
        unsigned __int8 a5,
        __int64 a6,
        int a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  const char *v16; // x2
  int v17; // w12
  unsigned int v18; // w9
  unsigned int v19; // w10
  unsigned int v20; // w9
  __int64 result; // x0
  __int64 v28; // x20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x6
  __int64 v41; // [xsp+0h] [xbp-D0h]
  __int64 v42; // [xsp+8h] [xbp-C8h]
  __int64 v43; // [xsp+10h] [xbp-C0h]
  __int64 v44; // [xsp+18h] [xbp-B8h]
  __int64 v45; // [xsp+20h] [xbp-B0h]
  __int64 v46; // [xsp+28h] [xbp-A8h]
  __int64 v47; // [xsp+30h] [xbp-A0h]
  __int64 v48; // [xsp+38h] [xbp-98h]
  __int64 v49; // [xsp+40h] [xbp-90h]
  __int64 v50; // [xsp+48h] [xbp-88h]
  __int64 v51; // [xsp+50h] [xbp-80h]
  __int64 v52; // [xsp+58h] [xbp-78h]
  __int64 v53; // [xsp+60h] [xbp-70h]
  __int64 v54; // [xsp+68h] [xbp-68h]
  __int64 v55; // [xsp+70h] [xbp-60h]
  __int64 v56; // [xsp+78h] [xbp-58h]
  __int64 v57; // [xsp+80h] [xbp-50h]
  __int64 v58; // [xsp+88h] [xbp-48h]
  __int64 v59; // [xsp+90h] [xbp-40h]
  __int64 v60; // [xsp+98h] [xbp-38h]
  __int64 v61; // [xsp+A0h] [xbp-30h]
  __int64 v62; // [xsp+A8h] [xbp-28h]
  __int64 v63; // [xsp+B0h] [xbp-20h]
  __int64 v64; // [xsp+B8h] [xbp-18h]
  __int64 v65; // [xsp+C0h] [xbp-10h]
  __int64 v66; // [xsp+C8h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a5 > 0xC8u )
  {
    v16 = "%s: %s: Num states exceeded";
LABEL_18:
    qdf_trace_msg(0x67u, 2u, v16, a8, a9, a10, a11, a12, a13, a14, a15, "wlan_sm_create", a1);
    result = 0;
    goto LABEL_19;
  }
  if ( a5 )
  {
    v17 = 0;
    while ( 2 )
    {
      v64 = 0;
      v65 = 0;
      v62 = 0;
      v63 = 0;
      v60 = 0;
      v61 = 0;
      v58 = 0;
      v59 = 0;
      v18 = *(unsigned __int8 *)(a4 + 40LL * (unsigned __int8)v17);
      v56 = 0;
      v57 = 0;
      v54 = 0;
      v55 = 0;
      v52 = 0;
      v53 = 0;
      v50 = 0;
      v51 = 0;
      v48 = 0;
      v49 = 0;
      v46 = 0;
      v47 = 0;
      v44 = 0;
      v45 = 0;
      v42 = 0;
      v43 = 0;
      v41 = 0;
      if ( v18 > 0xC7 || (v19 = (unsigned __int8)v17, v18 != (unsigned __int8)v17) )
      {
        v37 = "%s: %s: entry %d has invalid state %d";
        v38 = a1;
        v39 = (unsigned __int8)v17;
        v40 = v18;
LABEL_16:
        qdf_trace_msg(
          0x67u,
          2u,
          v37,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          a15,
          "wlan_sm_validate_state_info",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66);
LABEL_17:
        v16 = "%s: %s: states validation failed";
        goto LABEL_18;
      }
      while ( 1 )
      {
        if ( v19 >= 0xC8 )
          __break(0x5512u);
        v20 = v19;
        if ( *((_BYTE *)&v41 + v19) == 1 )
        {
          qdf_trace_msg(
            0x67u,
            2u,
            "%s: %s: detected a loop with entry %d",
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            a14,
            a15,
            "wlan_sm_validate_state_info",
            a1,
            (unsigned __int8)v17,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66);
          goto LABEL_17;
        }
        *((_BYTE *)&v41 + v19) = 1;
        v19 = *(unsigned __int8 *)(a4 + 40LL * v19 + 1);
        if ( v19 == 255 )
          break;
        if ( !*(_BYTE *)(a4 + 40LL * v19 + 3) )
        {
          v37 = "%s: %s: state %d is marked as parent of %d but is not a super state";
          v38 = a1;
          v39 = v19;
          v40 = v20;
          goto LABEL_16;
        }
      }
      if ( ++v17 != a5 )
        continue;
      break;
    }
  }
  result = _qdf_mem_malloc(0x70u, "wlan_sm_create", 272);
  if ( result )
  {
    *(_BYTE *)(result + 64) = a3;
    *(_BYTE *)(result + 65) = a5;
    *(_QWORD *)(result + 72) = a4;
    *(_QWORD *)(result + 80) = a2;
    *(_BYTE *)(result + 66) = -1;
    *(_DWORD *)(result + 88) = 0;
    *(_QWORD *)(result + 96) = a6;
    *(_DWORD *)(result + 104) = a7;
    v28 = result;
    sized_strscpy(result, a1, 64);
    qdf_trace_msg(
      0x67u,
      8u,
      "%s: %s: sm creation successful",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_sm_create",
      a1);
    result = v28;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
