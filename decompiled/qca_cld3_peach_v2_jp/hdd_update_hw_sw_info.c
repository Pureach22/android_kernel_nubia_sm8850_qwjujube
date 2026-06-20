__int64 __fastcall hdd_update_hw_sw_info(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  size_t v11; // x2
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  char *s[2]; // [xsp+0h] [xbp-10h] BYREF

  s[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  s[0] = nullptr;
  result = (__int64)_cds_get_context(61, (__int64)"hdd_update_hw_sw_info", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    hif_get_hw_info(result, a1 + 141, a1 + 142, (const char **)s);
    qdf_mem_set(a1 + 143, 0x20u, 0);
    v11 = strlen(s[0]) + 1;
    if ( v11 > 0x20 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: target_hw_name_len is greater than MAX_TGT_HW_NAME_LEN",
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 "hdd_update_hw_sw_info");
    }
    else
    {
      qdf_mem_copy(a1 + 143, s[0], v11);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: target_hw_name = %s",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "hdd_update_hw_sw_info",
        a1 + 143);
      result = _qdf_mem_malloc(0x7FFu, "hdd_update_hw_sw_info", 4057);
      if ( result )
      {
        v28 = result;
        hdd_wlan_get_version(a1, 2047, result);
        qdf_trace_msg(0x33u, 8u, "%s", v29, v30, v31, v32, v33, v34, v35, v36, v28);
        result = _qdf_mem_free(v28);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
