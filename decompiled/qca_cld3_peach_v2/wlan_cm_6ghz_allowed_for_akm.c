__int64 __fastcall wlan_cm_6ghz_allowed_for_akm(__int64 a1, unsigned int a2, char a3, __int64 a4, __int64 a5, char a6)
{
  __int64 v6; // x29
  __int64 v7; // x30
  __int64 cmpt_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x4
  const char *v23; // x2
  __int64 v24; // x5
  __int64 v25; // [xsp+8h] [xbp-28h]

  if ( (a6 & 1) != 0 )
    return 1;
  v25 = v7;
  cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj )
  {
    if ( (*(_BYTE *)(cmpt_obj + 2048) & 8) != 0 )
    {
      if ( (a2 & 0x19FFFEBD) != 0 )
      {
        if ( a3 < 0 )
        {
          if ( (a2 & 0x18000C00) != 0 && (util_is_rsnxe_h2e_capable(a4) & 1) == 0 )
            LOBYTE(cmpt_obj) = wlan_wfa_get_test_feature_flags(a1, 1);
          else
            LOBYTE(cmpt_obj) = 1;
          return cmpt_obj & 1;
        }
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: PMF not enabled for 6GHz AP",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_cm_6ghz_allowed_for_akm",
          v6,
          v25);
        goto LABEL_13;
      }
      v23 = "%s: AKM 0x%x didn't match with allowed 6ghz AKM 0x%x";
      v22 = a2;
      v24 = 436207293;
    }
    else
    {
      v22 = *(unsigned int *)(cmpt_obj + 2052);
      LOBYTE(cmpt_obj) = 1;
      if ( !(_DWORD)v22 || ((unsigned int)v22 & a2) != 0 )
        return cmpt_obj & 1;
      v23 = "%s: user configured mask %x didn't match AKM %x";
      v24 = a2;
    }
    qdf_trace_msg(
      0x68u,
      8u,
      v23,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_cm_6ghz_allowed_for_akm",
      v22,
      v24,
      v6,
      v25);
LABEL_13:
    LOBYTE(cmpt_obj) = 0;
  }
  return cmpt_obj & 1;
}
