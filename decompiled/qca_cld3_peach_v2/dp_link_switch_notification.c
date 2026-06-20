__int64 __fastcall dp_link_switch_notification(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 comp_private_obj; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  __int64 v32; // x6
  __int64 v33; // x7
  int v34; // w8
  int v35; // w9
  __int64 v36; // x23
  int v37; // w10
  int v38; // w11
  int v39; // w12
  int v40; // w13
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x4
  __int64 v50; // x7
  int v51; // w8
  int v52; // w9
  int v53; // w10
  int v54; // w11
  int v55; // w12
  int v56; // w13
  int v57; // w14
  int v58; // w15
  __int64 v60; // [xsp+0h] [xbp-70h]
  __int64 v61; // [xsp+8h] [xbp-68h]
  __int64 v62; // [xsp+10h] [xbp-60h]
  __int64 v63; // [xsp+18h] [xbp-58h]
  __int64 v64; // [xsp+28h] [xbp-48h]
  __int64 v65; // [xsp+30h] [xbp-40h]
  __int64 v66; // [xsp+38h] [xbp-38h]
  __int64 v67; // [xsp+40h] [xbp-30h]
  __int64 v68; // [xsp+50h] [xbp-20h]

  if ( a3 == 1 )
  {
    if ( a1 )
    {
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
    }
    else
    {
      qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a4, a5, a6, a7, a8, a9, a10, a11, "dp_get_vdev_priv_obj");
      comp_private_obj = 0;
    }
    if ( (is_dp_link_valid(comp_private_obj, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
    {
      v31 = *(_QWORD *)(comp_private_obj + 32);
      if ( comp_private_obj == -25 )
      {
        v34 = 0;
        v32 = 0;
        v33 = 0;
        v35 = 0;
        v36 = v31 + 20;
        if ( v31 != -20 )
          goto LABEL_9;
      }
      else
      {
        v32 = *(unsigned __int8 *)(comp_private_obj + 25);
        v33 = *(unsigned __int8 *)(comp_private_obj + 26);
        v34 = *(unsigned __int8 *)(comp_private_obj + 27);
        v35 = *(unsigned __int8 *)(comp_private_obj + 30);
        v36 = v31 + 20;
        if ( v31 != -20 )
        {
LABEL_9:
          v37 = *(unsigned __int8 *)(v31 + 20);
          v38 = *(unsigned __int8 *)(v31 + 21);
          v39 = *(unsigned __int8 *)(v31 + 22);
          v40 = *(unsigned __int8 *)(v31 + 25);
          goto LABEL_13;
        }
      }
      v39 = 0;
      v37 = 0;
      v38 = 0;
      v40 = 0;
LABEL_13:
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Link switch req for dp_link %pK id %d (%02x:%02x:%02x:**:**:%02x), dp_intf %pK (%02x:%02x:%02x:**:**:%02x) c"
        "ur_def_link %pK id %d device_mode %d num_links %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "dp_link_switch_notification",
        comp_private_obj,
        *(unsigned __int8 *)(comp_private_obj + 24),
        v32,
        v33,
        v34,
        v35,
        v31,
        v37,
        v38,
        v39,
        v40,
        *(_QWORD *)(v31 + 3664),
        *(unsigned __int8 *)(*(_QWORD *)(v31 + 3664) + 24LL),
        *(_DWORD *)(v31 + 28),
        *(unsigned __int8 *)(v31 + 3661));
      if ( *(_DWORD *)(v31 + 28) )
      {
        v49 = "Failed";
        v22 = 4;
        v50 = *(unsigned __int8 *)(comp_private_obj + 24);
        if ( comp_private_obj == -25 )
          goto LABEL_26;
      }
      else
      {
        if ( *(_BYTE *)(v31 + 3661) != 1 )
        {
          if ( comp_private_obj == *(_QWORD *)(v31 + 3664) )
          {
            v22 = dp_change_def_link(v31, comp_private_obj, a2);
            if ( v22 )
            {
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: Failed to change def_link for dp_intf %pK",
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                "dp_link_switch_notification",
                v31);
              v49 = "Failed";
              v50 = *(unsigned __int8 *)(comp_private_obj + 24);
              if ( comp_private_obj == -25 )
                goto LABEL_26;
              goto LABEL_22;
            }
          }
          else
          {
            v22 = 0;
          }
          v49 = "Successful";
          v50 = *(unsigned __int8 *)(comp_private_obj + 24);
          if ( comp_private_obj == -25 )
            goto LABEL_26;
          goto LABEL_22;
        }
        v49 = "Failed";
        v22 = 9;
        v50 = *(unsigned __int8 *)(comp_private_obj + 24);
        if ( comp_private_obj == -25 )
        {
LABEL_26:
          v53 = 0;
          v51 = 0;
          v52 = 0;
          v54 = 0;
          if ( !v36 )
            goto LABEL_27;
          goto LABEL_23;
        }
      }
LABEL_22:
      v51 = *(unsigned __int8 *)(comp_private_obj + 25);
      v52 = *(unsigned __int8 *)(comp_private_obj + 26);
      v53 = *(unsigned __int8 *)(comp_private_obj + 27);
      v54 = *(unsigned __int8 *)(comp_private_obj + 30);
      if ( !v36 )
      {
LABEL_27:
        v57 = 0;
        v55 = 0;
        v56 = 0;
        v58 = 0;
        goto LABEL_28;
      }
LABEL_23:
      v55 = *(unsigned __int8 *)(v31 + 20);
      v56 = *(unsigned __int8 *)(v31 + 21);
      v57 = *(unsigned __int8 *)(v31 + 22);
      v58 = *(unsigned __int8 *)(v31 + 25);
LABEL_28:
      LODWORD(v68) = *(unsigned __int8 *)(*(_QWORD *)(v31 + 3664) + 24LL);
      LODWORD(v67) = v58;
      LODWORD(v66) = v57;
      LODWORD(v65) = v56;
      LODWORD(v64) = v55;
      LODWORD(v63) = v54;
      LODWORD(v62) = v53;
      LODWORD(v61) = v52;
      LODWORD(v60) = v51;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Link switch req %s (ret %d) for dp_link %pK id %d (%02x:%02x:%02x:**:**:%02x), dp_intf %pK (%02x:%02x:%02x:*"
        "*:**:%02x) cur_def_link %pK id %d device_mode %d num_links %d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "dp_link_switch_notification",
        v49,
        v22,
        comp_private_obj,
        v50,
        v60,
        v61,
        v62,
        v63,
        v31,
        v64,
        v65,
        v66,
        v67,
        *(_QWORD *)(v31 + 3664),
        v68,
        *(_DWORD *)(v31 + 28),
        *(unsigned __int8 *)(v31 + 3661));
      return v22;
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: dp_link from vdev %pK is invalid",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "dp_link_switch_notification",
      a1);
    return 4;
  }
  else
  {
    return 0;
  }
}
