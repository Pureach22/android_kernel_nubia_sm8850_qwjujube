__int64 __fastcall hdd_config_total_beacon_miss_count(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 *v11; // x22
  __int64 result; // x0
  unsigned int v14; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int8 v23; // w21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w19
  const char *v42; // x2
  char v43[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v43[0] = 0;
  v11 = *(__int64 **)(v10 + 24);
  if ( !*(_DWORD *)(v10 + 40) )
  {
    v14 = *(unsigned __int8 *)(a2 + 4);
    ucfg_mlme_get_roam_bmiss_first_bcnt(*v11, v43);
    v23 = v14 - v43[0];
    if ( v14 <= (unsigned __int8)v43[0] )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Total %u needs to exceed first %u",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "hdd_config_total_beacon_miss_count",
        v14);
    }
    else if ( ucfg_mlme_validate_roam_bmiss_final_bcnt(
                (unsigned __int8)(v14 - v43[0]),
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: First count %u, final count %u",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "hdd_config_total_beacon_miss_count",
        (unsigned __int8)v43[0],
        v23);
      v32 = sme_set_roam_bmiss_final_bcnt(v11[2], *((unsigned __int8 *)a1 + 8), v23);
      if ( v32 )
      {
        v41 = v32;
        v42 = "%s: Failed to set final count, status %u";
      }
      else
      {
        v41 = sme_set_bmiss_bcnt(*((unsigned __int8 *)a1 + 8), (unsigned __int8)v43[0], v23);
        if ( !v41 )
        {
LABEL_12:
          result = qdf_status_to_os_return(v41);
          goto LABEL_13;
        }
        v42 = "%s: Failed to set count, status %u";
      }
      qdf_trace_msg(0x33u, 2u, v42, v33, v34, v35, v36, v37, v38, v39, v40, "hdd_config_total_beacon_miss_count", v41);
      goto LABEL_12;
    }
    result = 4294967274LL;
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Only supported in sta mode",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_config_total_beacon_miss_count");
  result = 4294967274LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
