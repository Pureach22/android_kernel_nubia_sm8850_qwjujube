__int64 __fastcall target_if_nan_datapath_req(
        _DWORD *a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w8
  unsigned __int64 v11; // t2
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x21
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x19
  __int64 v31; // x8
  int v32; // w10
  void (__fastcall *v33)(_QWORD); // x8
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x9
  __int64 v37; // x21
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x19
  __int64 v49; // x8
  int v50; // w10
  __int64 v51; // x9
  __int64 v52; // x9
  __int64 v53; // x9
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v56; // x8
  __int64 v57; // x9
  __int64 v58; // x21
  __int64 comp_private_obj; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x19
  int v70; // w9
  int v71; // w10
  const char *v72; // x2
  const char *v73; // x3
  __int64 v75; // [xsp+8h] [xbp-58h] BYREF
  __int64 *v76; // [xsp+10h] [xbp-50h]
  __int64 v77; // [xsp+18h] [xbp-48h]
  __int64 v78; // [xsp+20h] [xbp-40h]
  __int64 v79; // [xsp+28h] [xbp-38h]
  __int64 v80; // [xsp+30h] [xbp-30h]
  __int64 v81; // [xsp+38h] [xbp-28h] BYREF
  int v82; // [xsp+40h] [xbp-20h]
  _BYTE v83[12]; // [xsp+44h] [xbp-1Ch]
  __int64 v84; // [xsp+50h] [xbp-10h]
  __int64 v85; // [xsp+58h] [xbp-8h]

  HIDWORD(v11) = a2 - 4;
  LODWORD(v11) = a2 - 4;
  v10 = v11 >> 1;
  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( v10 <= 1 )
  {
    if ( !v10 )
    {
      v79 = 0;
      v80 = 0;
      v77 = 0;
      v78 = 0;
      v75 = 0;
      v76 = nullptr;
      *(_QWORD *)&v83[4] = 9003;
      if ( a1 )
      {
        v55 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
        if ( v55 && (v56 = *(_QWORD *)(v55 + 80)) != 0 )
        {
          v57 = *(_QWORD *)(v56 + 2800);
          if ( v57 && (v58 = *(_QWORD *)(v57 + 16)) != 0 )
          {
            comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v56, 0xFu);
            if ( comp_private_obj )
            {
              v69 = comp_private_obj;
              if ( !(unsigned int)wmi_unified_ndp_initiator_req_cmd_send(v58) )
                goto LABEL_72;
              v70 = a1[2];
              v71 = a1[5];
              v81 = *(_QWORD *)a1;
              v33 = *(void (__fastcall **)(_QWORD))(v69 + 264);
              v82 = v70;
              *(_DWORD *)v83 = v71;
              LOWORD(v75) = 5;
              v76 = &v81;
              if ( !v33 )
                goto LABEL_72;
              goto LABEL_46;
            }
            qdf_trace_msg(
              0x53u,
              2u,
              "%s: psoc private object is null",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "nan_psoc_get_rx_ops");
            v72 = "%s: nan_rx_ops is null.";
          }
          else
          {
            v72 = "%s: wmi_handle is null.";
          }
        }
        else
        {
          v72 = "%s: psoc is null.";
        }
      }
      else
      {
        v72 = "%s: ndp_req is null.";
      }
      v73 = "target_if_nan_ndp_initiator_req";
      goto LABEL_71;
    }
    if ( v10 != 1 )
      goto LABEL_49;
    v79 = 0;
    v80 = 0;
    v77 = 0;
    v78 = 0;
    v75 = 0;
    v76 = nullptr;
    *(_QWORD *)&v83[4] = 0;
    v84 = 0;
    if ( a1 )
    {
      v16 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
      if ( v16 && (v17 = *(_QWORD *)(v16 + 80)) != 0 )
      {
        v18 = *(_QWORD *)(v17 + 2800);
        if ( v18 && (v19 = *(_QWORD *)(v18 + 16)) != 0 )
        {
          v21 = wlan_objmgr_psoc_get_comp_private_obj(v17, 0xFu);
          if ( v21 )
          {
            v30 = v21;
            if ( !(unsigned int)wmi_unified_ndp_responder_req_cmd_send(v19) )
              goto LABEL_72;
            v31 = *(_QWORD *)a1;
            v32 = a1[2];
            *(_QWORD *)v83 = 0x232C00000001LL;
            v81 = v31;
            v33 = *(void (__fastcall **)(_QWORD))(v30 + 264);
            v76 = &v81;
            v82 = v32;
            LOWORD(v75) = 7;
            if ( !v33 )
              goto LABEL_72;
            goto LABEL_46;
          }
          qdf_trace_msg(
            0x53u,
            2u,
            "%s: psoc private object is null",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "nan_psoc_get_rx_ops");
          v72 = "%s: nan_rx_ops is null.";
        }
        else
        {
          v72 = "%s: wmi_handle is null.";
        }
      }
      else
      {
        v72 = "%s: psoc is null.";
      }
    }
    else
    {
      v72 = "%s: Invalid req.";
    }
    v73 = "target_if_nan_ndp_responder_req";
    goto LABEL_71;
  }
  if ( v10 != 2 )
  {
    if ( v10 == 6 )
    {
      if ( *(_QWORD *)a1 )
      {
        v51 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
        if ( v51 && (v52 = *(_QWORD *)(v51 + 80)) != 0 )
        {
          v53 = *(_QWORD *)(v52 + 2800);
          if ( v53 )
          {
            v54 = *(_QWORD *)(v53 + 16);
            if ( v54 )
            {
              wmi_unified_terminate_all_ndps_req_cmd(v54);
              goto LABEL_72;
            }
          }
          v72 = "%s: wmi_handle is null.";
        }
        else
        {
          v72 = "%s: psoc is null.";
        }
      }
      else
      {
        v72 = "%s: vdev object is NULL!";
      }
      v73 = "target_if_nan_end_all_ndps_req";
      goto LABEL_71;
    }
    if ( v10 == 7 )
    {
      if ( a1 )
      {
        if ( *(_QWORD *)a1 )
        {
          v12 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
          if ( v12 && (v13 = *(_QWORD *)(v12 + 80)) != 0 )
          {
            v14 = *(_QWORD *)(v13 + 2800);
            if ( v14 )
            {
              v15 = *(_QWORD *)(v14 + 16);
              if ( v15 )
              {
                wmi_unified_ndp_update_config_cmd_send(v15);
                goto LABEL_72;
              }
            }
            v72 = "%s: wmi_handle is null.";
          }
          else
          {
            v72 = "%s: psoc is null.";
          }
        }
        else
        {
          v72 = "%s: vdev object is NULL!";
        }
      }
      else
      {
        v72 = "%s: Invalid config.";
      }
      v73 = "target_if_nan_ndp_update_config";
LABEL_71:
      qdf_trace_msg(0x49u, 2u, v72, a3, a4, a5, a6, a7, a8, a9, a10, v73);
      goto LABEL_72;
    }
LABEL_49:
    v72 = "%s: invalid req type";
    v73 = "target_if_nan_datapath_req";
    goto LABEL_71;
  }
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = nullptr;
  *(_QWORD *)&v83[4] = 9012;
  if ( !a1 )
  {
    v72 = "%s: req is null";
    goto LABEL_62;
  }
  v34 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
  if ( !v34 || (v35 = *(_QWORD *)(v34 + 80)) == 0 )
  {
    v72 = "%s: psoc is null.";
LABEL_62:
    v73 = "target_if_nan_ndp_end_req";
    goto LABEL_71;
  }
  v36 = *(_QWORD *)(v35 + 2800);
  if ( !v36 || (v37 = *(_QWORD *)(v36 + 16)) == 0 )
  {
    v72 = "%s: wmi_handle is null.";
    goto LABEL_62;
  }
  v39 = wlan_objmgr_psoc_get_comp_private_obj(v35, 0xFu);
  if ( !v39 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: psoc private object is null",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "nan_psoc_get_rx_ops");
    v72 = "%s: nan_rx_ops is null.";
    goto LABEL_62;
  }
  v48 = v39;
  if ( !(unsigned int)wmi_unified_ndp_end_req_cmd_send(v37) )
    goto LABEL_72;
  v49 = *(_QWORD *)a1;
  v50 = a1[2];
  LOWORD(v75) = 9;
  v81 = v49;
  v33 = *(void (__fastcall **)(_QWORD))(v48 + 264);
  v82 = v50;
  *(_DWORD *)v83 = 1;
  v76 = &v81;
  if ( !v33 )
    goto LABEL_72;
LABEL_46:
  if ( *((_DWORD *)v33 - 1) != 1685785071 )
    __break(0x8228u);
  v33(&v75);
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return 0;
}
