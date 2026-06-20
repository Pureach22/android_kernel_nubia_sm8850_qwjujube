__int64 __fastcall hdd_dbs_scan_selection_init(__int64 *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w22
  unsigned __int64 v21; // x23
  _DWORD *v22; // x25
  int v23; // w19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  _BYTE v40[4]; // [xsp+8h] [xbp-88h] BYREF
  _BYTE v41[4]; // [xsp+Ch] [xbp-84h] BYREF
  _QWORD v42[3]; // [xsp+10h] [xbp-80h] BYREF
  int v43; // [xsp+2Ch] [xbp-64h] BYREF
  __int64 v44; // [xsp+30h] [xbp-60h]
  __int64 v45; // [xsp+38h] [xbp-58h]
  __int64 v46; // [xsp+40h] [xbp-50h]
  __int64 v47; // [xsp+48h] [xbp-48h]
  _QWORD v48[8]; // [xsp+50h] [xbp-40h] BYREF

  v48[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v47 = 0;
  memset(v48, 0, 56);
  v45 = 0;
  v46 = 0;
  v44 = 0;
  v41[0] = 0;
  v40[0] = 0;
  memset(v42, 0, 21);
  if ( (unsigned int)ucfg_policy_mgr_get_dual_mac_feature(v2, v40) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: can't get dual mac feature flag",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "hdd_dbs_scan_selection_init");
    result = 4294967274LL;
  }
  else
  {
    if ( (v40[0] & 0xFB) != 1 )
    {
      hdd_string_to_u8_array((char *)(a1[13] + 81), (__int64)v42, v41, 0x15u);
      if ( v41[0] )
      {
        v20 = 0;
        v43 = 0;
        if ( v41[0] >= 3u )
        {
          v21 = 0;
          v22 = v48;
          while ( 1 )
          {
            if ( v21 == 21 )
              goto LABEL_18;
            *(v22 - 7) = *((unsigned __int8 *)v42 + v21);
            if ( v21 > 0x13 )
              break;
            *v22 = *((unsigned __int8 *)v42 + v21 + 1);
            if ( v21 == 19 )
              break;
            v22[7] = *((unsigned __int8 *)v42 + v21 + 2);
            v20 = ++v43;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: module:%d NDS:%d NNDS:%d",
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              "hdd_dbs_scan_selection_init");
            v21 += 3LL;
            ++v22;
            if ( v41[0] - 2 <= (int)v21 )
              goto LABEL_12;
          }
          __break(1u);
LABEL_18:
          __break(0x5512u);
        }
LABEL_12:
        LODWORD(v44) = 0;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: clients:%d pdev:%d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "hdd_dbs_scan_selection_init",
          v20,
          0);
        v23 = ((__int64 (__fastcall *)(__int64, int *))sme_set_dbs_scan_selection_config)(a1[2], &v43);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Sending DBS Scan Selection Configuration to fw",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "hdd_dbs_scan_selection_init");
        if ( v23 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to send DBS Scan selection configuration!",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "hdd_dbs_scan_selection_init");
          result = 4294967285LL;
          goto LABEL_16;
        }
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Do not send scan_selection_config",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "hdd_dbs_scan_selection_init");
      }
      result = 0;
      goto LABEL_16;
    }
    result = 4294967274LL;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
