__int64 __fastcall policy_mgr_next_actions(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int current_hw_mode; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w19
  __int64 result; // x0
  __int64 v37; // x20
  __int64 v38; // x0
  __int64 v39; // x1
  __int64 v40; // x3
  __int64 v41; // x0
  unsigned int v42; // w1
  unsigned int v43; // w2
  char v44; // w8
  unsigned int v45; // w3
  unsigned int v46; // w4
  unsigned int v47; // w5
  unsigned int v48; // w6
  __int64 v49; // x0
  __int64 v50; // x2
  char v51; // w8
  char is_hw_sbs_capable; // w0
  int v53; // w8
  int v54; // [xsp+8h] [xbp-58h]
  unsigned int v55; // [xsp+10h] [xbp-50h]
  char v56; // [xsp+18h] [xbp-48h]
  char v57; // [xsp+18h] [xbp-48h]
  unsigned int v58; // [xsp+20h] [xbp-40h]
  unsigned int v59; // [xsp+20h] [xbp-40h]
  int v60; // [xsp+28h] [xbp-38h]
  int v61; // [xsp+28h] [xbp-38h]
  _QWORD v62[2]; // [xsp+30h] [xbp-30h] BYREF
  __int64 v63; // [xsp+40h] [xbp-20h] BYREF
  __int64 v64; // [xsp+48h] [xbp-18h] BYREF
  int v65; // [xsp+50h] [xbp-10h]
  __int64 v66; // [xsp+58h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v65 = 0;
  v63 = 0;
  v64 = 0;
  v62[0] = 0;
  v62[1] = 0;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
  {
    if ( (a3 & 0xFFFFFFFE) == 6 && (policy_mgr_is_hw_sbs_capable(a1) & 1) == 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        4u,
        "%s: firmware is not sbs capable",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "policy_mgr_validate_unsupported_action");
      result = 11;
    }
    else
    {
      current_hw_mode = policy_mgr_get_current_hw_mode(a1, v62);
      if ( current_hw_mode )
      {
        v35 = current_hw_mode;
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: policy_mgr_get_current_hw_mode failed",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "policy_mgr_next_actions");
        result = v35;
      }
      else
      {
        switch ( a3 )
        {
          case 1u:
            policy_mgr_get_hw_dbs_nss(a1, &v64);
            policy_mgr_get_hw_dbs_max_bw(a1, &v63);
            is_hw_sbs_capable = policy_mgr_is_hw_sbs_capable(a1);
            v43 = v64;
            v46 = HIDWORD(v64);
            v45 = v63;
            v47 = HIDWORD(v63);
            v53 = is_hw_sbs_capable & 1;
            v48 = 0;
            v60 = a5;
            v41 = a1;
            v42 = a2;
            v58 = 1;
            v56 = 0;
            v55 = a4;
            v54 = v53;
            goto LABEL_34;
          case 2u:
            v49 = a1;
            v50 = 1;
            goto LABEL_39;
          case 3u:
            v48 = 0;
            v41 = a1;
            v42 = a2;
            v43 = 2;
            v45 = 5;
            v46 = 2;
            v60 = a5;
            v58 = 3;
            v56 = 9;
            v55 = a4;
            v54 = 0;
            goto LABEL_33;
          case 4u:
            v61 = a5;
            v59 = 4;
            v57 = 0;
            goto LABEL_28;
          case 5u:
            v59 = 5;
            v61 = a5;
            v57 = 9;
LABEL_28:
            result = policy_mgr_pdev_set_hw_mode(a1, a2, 2u, 5u, 0, 0, 0, 0, 0, 0, a4, v57, v59, v61);
            break;
          case 6u:
            v48 = 0;
            v60 = a5;
            v58 = 6;
            v41 = a1;
            v56 = 0;
            v42 = a2;
            v43 = 1;
            v55 = a4;
            v45 = 5;
            v46 = 1;
            v54 = 1;
LABEL_33:
            v47 = 5;
            goto LABEL_34;
          case 7u:
            v49 = a1;
            v50 = 6;
            goto LABEL_39;
          case 8u:
            v38 = a1;
            v39 = 0;
            goto LABEL_42;
          case 9u:
            v38 = a1;
            v39 = 1;
LABEL_42:
            v40 = 2;
            goto LABEL_43;
          case 0xAu:
            if ( (policy_mgr_dbs1_dbs2_need_action(a1, 10, v62) & 1) == 0 )
              goto LABEL_40;
            v60 = a5;
            v41 = a1;
            v58 = 10;
            v42 = a2;
            v43 = 2;
            v55 = a4;
            if ( HIBYTE(v62[0]) )
              v51 = 14;
            else
              v51 = 0;
            v54 = 0;
            v45 = 5;
            v56 = v51;
            v46 = 1;
            v47 = 4;
            v48 = 2;
            goto LABEL_34;
          case 0xBu:
            if ( (policy_mgr_dbs1_dbs2_need_action(a1, 11, v62) & 1) == 0 )
              goto LABEL_40;
            v49 = a1;
            v50 = 10;
            goto LABEL_39;
          case 0xCu:
            if ( (policy_mgr_dbs1_dbs2_need_action(a1, 12, v62) & 1) == 0 )
              goto LABEL_40;
            v60 = a5;
            v41 = a1;
            v58 = 12;
            v42 = a2;
            v43 = 2;
            v55 = a4;
            if ( HIBYTE(v62[0]) )
              v44 = 15;
            else
              v44 = 0;
            v54 = 0;
            v45 = 4;
            v56 = v44;
            v46 = 1;
            v47 = 4;
            v48 = 1;
LABEL_34:
            result = policy_mgr_pdev_set_hw_mode(v41, v42, v43, v45, v46, v47, v48, 1u, 0, v54, v55, v56, v58, v60);
            break;
          case 0xDu:
            if ( (policy_mgr_dbs1_dbs2_need_action(a1, 13, v62) & 1) != 0 )
            {
              v49 = a1;
              v50 = 12;
LABEL_39:
              result = policy_mgr_complete_action(v49, 0, v50, a4, a2, a5);
            }
            else
            {
LABEL_40:
              result = 6;
            }
            break;
          case 0xEu:
            v38 = a1;
            v39 = 1;
            v40 = 1;
            goto LABEL_43;
          case 0xFu:
            v38 = a1;
            v39 = 1;
            v40 = 0;
LABEL_43:
            result = policy_mgr_nss_update(v38, v39, 0, v40, a4, a2, a5);
            break;
          case 0x10u:
          case 0x11u:
            policy_mgr_sap_ch_width_update(a1, a3, a4, a2, a5);
            result = 0;
            break;
          default:
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: unexpected action value %d",
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              "policy_mgr_next_actions",
              a3);
            result = 16;
            break;
        }
      }
    }
  }
  else
  {
    v37 = jiffies;
    if ( policy_mgr_next_actions___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: driver isn't dbs capable, no further action needed",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "policy_mgr_next_actions");
      policy_mgr_next_actions___last_ticks = v37;
    }
    result = 11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
