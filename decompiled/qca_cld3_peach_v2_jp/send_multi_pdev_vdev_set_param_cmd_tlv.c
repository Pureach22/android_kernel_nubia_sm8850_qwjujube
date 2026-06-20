__int64 __fastcall send_multi_pdev_vdev_set_param_cmd_tlv(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x22
  int *v12; // x8
  __int64 v13; // x9
  int v14; // t1
  int *v15; // x8
  __int64 v16; // x9
  int v17; // t1
  int v18; // w23
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _DWORD *v28; // x24
  __int64 v29; // x20
  int v30; // w8
  int v31; // w3
  __int64 result; // x0
  __int64 v33; // x8
  __int64 (*v34)(void); // x8
  const char *v35; // x2
  __int64 v36; // x26
  _DWORD *v37; // x27
  __int64 v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w19

  v10 = *((unsigned __int8 *)a2 + 6);
  if ( *a2 )
  {
    if ( *a2 != 1 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: invalid param type",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "convert_host_pdev_vdev_param_id_to_target");
      return 4;
    }
    if ( *((_BYTE *)a2 + 6) )
    {
      v12 = *((int **)a2 + 1);
      v13 = *((unsigned __int8 *)a2 + 6);
      while ( 1 )
      {
        v14 = *v12;
        v12 += 2;
        if ( !v14 )
          break;
        if ( !--v13 )
          goto LABEL_12;
      }
      v35 = "%s: vdev param %d not available";
LABEL_21:
      qdf_trace_msg(0x31u, 2u, v35, a3, a4, a5, a6, a7, a8, a9, a10, "convert_host_pdev_vdev_param_id_to_target", 0);
      return 4;
    }
  }
  else if ( *((_BYTE *)a2 + 6) )
  {
    v15 = *((int **)a2 + 1);
    v16 = *((unsigned __int8 *)a2 + 6);
    while ( 1 )
    {
      v17 = *v15;
      v15 += 2;
      if ( !v17 )
        break;
      if ( !--v16 )
        goto LABEL_12;
    }
    v35 = "%s: pdev param %d not available";
    goto LABEL_21;
  }
LABEL_12:
  v18 = 12 * v10;
  v19 = wmi_buf_alloc_fl(a1, 12 * (int)v10 + 16, "send_multi_pdev_vdev_set_param_cmd_tlv", 0xB42u);
  if ( !v19 )
    return 2;
  v28 = *(_DWORD **)(v19 + 224);
  v29 = v19;
  *v28 = 70189064;
  v30 = *a2;
  v28[1] = *a2;
  if ( v30 )
  {
    LOBYTE(v31) = *((_BYTE *)a2 + 5);
  }
  else
  {
    v33 = *(_QWORD *)(a1 + 728);
    if ( *((_BYTE *)a2 + 4) )
      v34 = *(__int64 (**)(void))(v33 + 3704);
    else
      v34 = *(__int64 (**)(void))(v33 + 3664);
    if ( *((_DWORD *)v34 - 1) != -2112860426 )
      __break(0x8228u);
    v19 = v34();
    LOBYTE(v31) = v19;
    *((_BYTE *)a2 + 5) = v19;
  }
  v28[2] = (unsigned __int8)v31;
  v28[3] = v18 | 0x120000;
  if ( (_DWORD)v10 )
  {
    v36 = 0;
    v37 = v28 + 4;
    while ( 1 )
    {
      *v37 = 70254600;
      v37[1] = *(_DWORD *)(*((_QWORD *)a2 + 1) + v36);
      v37[2] = *(_DWORD *)(*((_QWORD *)a2 + 1) + v36 + 4);
      v38 = (unsigned int)v28[1];
      if ( (unsigned int)v38 >= 2 )
        break;
      v36 += 8;
      v19 = qdf_trace_msg(
              0x31u,
              8u,
              "Set %s %d param 0x%x to %u",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              off_9E7008[v38],
              *((unsigned __int8 *)a2 + 5));
      v37 += 3;
      if ( 8 * v10 == v36 )
      {
        v31 = v28[2];
        goto LABEL_31;
      }
    }
    __break(0x5512u);
    return wmi_reg_status_to_reg_status(v19);
  }
  else
  {
LABEL_31:
    qdf_mtrace(49, 100, 0xE9Fu, v31, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v29,
               v18 + 16,
               0x1D01Fu,
               "send_multi_pdev_vdev_set_param_cmd_tlv",
               0xB69u,
               v39,
               v40,
               v41,
               v42,
               v43,
               v44,
               v45,
               v46);
    if ( (_DWORD)result )
    {
      v47 = result;
      wmi_buf_free();
      return v47;
    }
  }
  return result;
}
