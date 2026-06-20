__int64 __fastcall wlan_cm_ese_populate_additional_ies(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *mac_context; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x4
  unsigned __int8 *v32; // x23
  _QWORD *v33; // x22
  __int64 result; // x0
  __int64 v35; // [xsp+0h] [xbp-140h] BYREF
  __int64 v36; // [xsp+8h] [xbp-138h] BYREF
  __int64 v37; // [xsp+10h] [xbp-130h]
  __int64 v38; // [xsp+18h] [xbp-128h]
  __int64 v39; // [xsp+20h] [xbp-120h]
  __int64 v40; // [xsp+28h] [xbp-118h]
  __int64 v41; // [xsp+30h] [xbp-110h]
  __int64 v42; // [xsp+38h] [xbp-108h]
  __int64 v43; // [xsp+40h] [xbp-100h] BYREF
  __int64 v44; // [xsp+48h] [xbp-F8h]
  __int64 v45; // [xsp+50h] [xbp-F0h]
  __int64 v46; // [xsp+58h] [xbp-E8h]
  __int64 v47; // [xsp+60h] [xbp-E0h]
  __int64 v48; // [xsp+68h] [xbp-D8h]
  __int64 v49; // [xsp+70h] [xbp-D0h]
  __int64 v50; // [xsp+78h] [xbp-C8h]
  __int64 v51; // [xsp+80h] [xbp-C0h] BYREF
  __int64 v52; // [xsp+88h] [xbp-B8h]
  __int64 v53; // [xsp+90h] [xbp-B0h]
  __int64 v54; // [xsp+98h] [xbp-A8h]
  __int64 v55; // [xsp+A0h] [xbp-A0h]
  __int64 v56; // [xsp+A8h] [xbp-98h]
  __int64 v57; // [xsp+B0h] [xbp-90h]
  __int64 v58; // [xsp+B8h] [xbp-88h] BYREF
  __int64 v59; // [xsp+C0h] [xbp-80h]
  __int64 v60; // [xsp+C8h] [xbp-78h]
  __int64 v61; // [xsp+D0h] [xbp-70h]
  __int64 v62; // [xsp+D8h] [xbp-68h]
  __int64 v63; // [xsp+E0h] [xbp-60h]
  __int128 v64; // [xsp+E8h] [xbp-58h]
  __int64 v65; // [xsp+F8h] [xbp-48h] BYREF
  __int64 v66; // [xsp+100h] [xbp-40h]
  __int64 v67; // [xsp+108h] [xbp-38h]
  __int64 v68; // [xsp+110h] [xbp-30h]
  __int64 v69; // [xsp+118h] [xbp-28h]
  __int64 v70; // [xsp+120h] [xbp-20h]
  __int128 v71; // [xsp+128h] [xbp-18h]
  __int64 v72; // [xsp+138h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v35) = 258;
  *(_QWORD *)((char *)&v71 + 5) = 0;
  LODWORD(v35) = 49434624;
  v70 = 0;
  *(_QWORD *)&v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v65 = 0;
  *(_QWORD *)((char *)&v64 + 5) = 0;
  v63 = 0;
  *(_QWORD *)&v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v36 = 0;
  mac_context = sme_get_mac_context(a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !mac_context )
  {
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: mac_ctx is NULL",
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               "wlan_cm_ese_populate_additional_ies",
               v35,
               v36,
               v37,
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
               (_QWORD)v64,
               *((_QWORD *)&v64 + 1),
               v65,
               v66,
               v67,
               v68,
               v69,
               v70,
               (_QWORD)v71,
               *((_QWORD *)&v71 + 1),
               v72);
    goto LABEL_15;
  }
  v31 = a3;
  if ( a3 > 5u )
    goto LABEL_13;
  v32 = (unsigned __int8 *)(mac_context[2153] + 96LL * a3);
  if ( !v32 )
    goto LABEL_13;
  v33 = mac_context;
  result = csr_is_wmm_supported(
             mac_context,
             v17,
             v18,
             v19,
             v31,
             v20,
             v21,
             v22,
             v35,
             v36,
             v37,
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
             *((_QWORD *)&v64 + 1),
             v65);
  if ( (result & 1) != 0 && *(_BYTE *)(a2 + 1562) == 1 )
  {
    result = wlan_cm_get_ese_assoc(a1, *v32);
    if ( (result & 1) != 0 )
    {
      LOBYTE(v36) = sme_qos_ese_retrieve_tspec_info(v33, *v32, (char *)&v36 + 1);
      result = (__int64)qdf_mem_copy(&v65, &v35, 6u);
      if ( (_BYTE)v36 )
      {
        ese_populate_wmm_tspec((__int64)&v36 + 2, (__int64)&v65 + 6);
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64 *))wlan_cm_append_assoc_ies)(
                   a4,
                   221,
                   61,
                   &v65);
        if ( (unsigned __int8)v36 >= 2u )
        {
          ese_populate_wmm_tspec((__int64)&v43 + 5, (__int64)&v65 + 6);
          result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64 *))wlan_cm_append_assoc_ies)(
                     a4,
                     221,
                     61,
                     &v65);
          if ( (unsigned __int8)v36 >= 3u )
          {
            ese_populate_wmm_tspec((__int64)&v51, (__int64)&v65 + 6);
            result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64 *))wlan_cm_append_assoc_ies)(
                       a4,
                       221,
                       61,
                       &v65);
            if ( (unsigned __int8)v36 >= 4u )
            {
              ese_populate_wmm_tspec((__int64)&v58 + 3, (__int64)&v65 + 6);
              result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64 *))wlan_cm_append_assoc_ies)(
                         a4,
                         221,
                         61,
                         &v65);
              if ( (unsigned __int8)v36 > 4u )
              {
                __break(0x5512u);
LABEL_13:
                result = qdf_trace_msg(
                           0x34u,
                           2u,
                           "%s: session is null %d",
                           v23,
                           v24,
                           v25,
                           v26,
                           v27,
                           v28,
                           v29,
                           v30,
                           "wlan_cm_ese_populate_additional_ies",
                           v35);
              }
            }
          }
        }
      }
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
