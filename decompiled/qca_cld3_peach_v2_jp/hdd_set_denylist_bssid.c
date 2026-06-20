__int64 __fastcall hdd_set_denylist_bssid(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  unsigned int v13; // w23
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  _WORD *v27; // x8
  int v28; // w28
  unsigned int v29; // w24
  unsigned int v30; // w25
  unsigned __int16 *v31; // x26
  void *v32; // x27
  __int64 result; // x0
  __int64 v34; // x0
  __int64 v35; // x8
  unsigned int v36; // w9
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  void *v45; // x20
  unsigned __int8 *v46; // x27
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x4
  __int64 v56; // x5
  __int64 v57; // x6
  __int64 v58; // x7
  const char *v59; // x2
  _QWORD v61[4]; // [xsp+8h] [xbp-F8h] BYREF
  __int64 v62; // [xsp+28h] [xbp-D8h]
  __int64 v63; // [xsp+30h] [xbp-D0h]
  _QWORD v64[20]; // [xsp+38h] [xbp-C8h] BYREF
  __int64 v65; // [xsp+D8h] [xbp-28h]
  __int64 v66; // [xsp+E0h] [xbp-20h]
  __int64 v67; // [xsp+E8h] [xbp-18h]
  __int64 v68; // [xsp+F0h] [xbp-10h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a3 + 152);
  v66 = 0;
  v67 = 0;
  v65 = 0;
  memset(v64, 0, sizeof(v64));
  if ( !v12 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: attr num of denylist bssid failed",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "hdd_set_denylist_bssid");
    goto LABEL_30;
  }
  v13 = *(_DWORD *)(v12 + 4);
  if ( v13 >= 0x11 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Denylist BSSID count %u exceeds max %u",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "hdd_set_denylist_bssid",
      v13,
      16);
LABEL_30:
    result = 4294967274LL;
    goto LABEL_31;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Num of denylist BSSID (%d)",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "hdd_set_denylist_bssid",
    v13);
  v17 = _qdf_mem_malloc(0x60u, "hdd_set_denylist_bssid", 5989);
  if ( !v17 )
    goto LABEL_30;
  v26 = v17;
  if ( v13 )
  {
    v27 = *(_WORD **)(a3 + 144);
    if ( v27 )
    {
      v28 = (unsigned __int16)(*v27 - 4);
      if ( (unsigned int)v28 >= 4 )
      {
        v29 = 0;
        v30 = 0;
        v31 = v27 + 2;
        v32 = &wlan_hdd_set_roam_param_policy;
        while ( 1 )
        {
          v36 = *v31;
          if ( v36 < 4 || v28 < v36 )
            goto LABEL_11;
          if ( v13 == v30 )
          {
            qdf_trace_msg(
              0x33u,
              3u,
              "%s: Ignoring excess Denylist BSSID",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "hdd_set_denylist_bssid");
            goto LABEL_13;
          }
          if ( (unsigned int)_nla_parse(v64, 22, v31 + 2, (unsigned __int16)(v36 - 4), v32, 31, 0) )
            break;
          if ( !v65 )
          {
            v59 = "%s: attr denylist addr failed";
            goto LABEL_29;
          }
          if ( v66 )
          {
            v62 = 0;
            v63 = 0;
            memset(v61, 0, sizeof(v61));
            qdf_mem_set(v61, 0x30u, 0);
            nla_memcpy(v61, v65, 6);
            v34 = *(_QWORD *)(a1 + 8);
            v62 = 0x700000000LL;
            LODWORD(v63) = 1;
            ucfg_dlm_add_bssid_to_reject_list(v34, v61);
          }
          else
          {
            v45 = v32;
            v46 = (unsigned __int8 *)(v26 + 6LL * (unsigned __int8)v29);
            nla_memcpy(v46, v65, 6);
            if ( v46 )
            {
              v55 = *v46;
              v56 = v46[1];
              v57 = v46[2];
              v58 = v46[5];
            }
            else
            {
              v57 = 0;
              v55 = 0;
              v56 = 0;
              v58 = 0;
            }
            v32 = v45;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: %02x:%02x:%02x:**:**:%02x",
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              "hdd_set_denylist_bssid",
              v55,
              v56,
              v57,
              v58);
            ++v29;
          }
          ++v30;
          v35 = (*v31 + 3) & 0x1FFFC;
          v28 -= v35;
          v31 = (unsigned __int16 *)((char *)v31 + v35);
          if ( v28 <= 3 )
            goto LABEL_11;
        }
        v59 = "%s: nla_parse failed";
LABEL_29:
        qdf_trace_msg(0x33u, 2u, v59, v37, v38, v39, v40, v41, v42, v43, v44, "hdd_set_denylist_bssid");
        _qdf_mem_free(v26);
        goto LABEL_30;
      }
    }
  }
  v30 = 0;
  v29 = 0;
LABEL_11:
  if ( v30 < v13 )
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Num Denylist BSSID %u less than expected %u",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hdd_set_denylist_bssid",
      v30,
      v13);
LABEL_13:
  ucfg_dlm_add_userspace_deny_list(*(_QWORD *)(a1 + 8), v26, v29);
  _qdf_mem_free(v26);
  sme_update_roam_params(*(_QWORD *)(a1 + 16), a4, a2, 0, 29);
  result = 0;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
