__int64 __fastcall hdd_driver_command(
        __int64 *a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x24
  int v11; // w19
  __int64 v13; // x21
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  __int64 result; // x0
  __int64 v25; // x4
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w19
  __int64 v35; // x0
  size_t v36; // x22
  char *v37; // x21
  __int64 v38; // x23
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7

  v10 = *a1;
  v11 = (int)a1;
  v13 = *(_QWORD *)(*a1 + 24);
  v14 = qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_driver_command");
  if ( (unsigned int)hdd_get_conparam(v14) == 5 )
  {
    v23 = "%s: Command not allowed in FTM mode";
LABEL_3:
    qdf_trace_msg(0x33u, 2u, v23, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_driver_command");
    return 4294967274LL;
  }
  result = _wlan_hdd_validate_context(v13, "hdd_driver_command");
  if ( !(_DWORD)result )
  {
    if ( *(_DWORD *)(v13 + 1464) == 2 )
    {
      v23 = "%s: Driver module is closed; command can not be processed";
      goto LABEL_3;
    }
    v25 = *((unsigned int *)a2 + 3);
    if ( (unsigned int)(v25 - 8193) > 0xFFFFDFFF )
    {
      v35 = _qdf_mem_malloc(v25 + 1, "hdd_driver_command", 7652);
      if ( v35 )
      {
        v36 = *((unsigned int *)a2 + 3);
        v37 = (char *)v35;
        if ( (v36 & 0x80000000) != 0 )
        {
          __break(0x800u);
          v34 = -14;
        }
        else
        {
          v38 = *a2;
          _check_object_size(v35, *((unsigned int *)a2 + 3), 0);
          if ( inline_copy_from_user_1((int)v37, v38, v36) )
          {
            v34 = -14;
          }
          else
          {
            v37[*((int *)a2 + 3)] = 0;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: %s: %s",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "hdd_driver_command",
              *(_QWORD *)(v10 + 32) + 296LL,
              v37);
            v34 = hdd_drv_cmd_process(v11, v37);
          }
        }
        _qdf_mem_free((__int64)v37);
      }
      else
      {
        v34 = -12;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: Invalid priv_data.total_len: %d!!!",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "hdd_driver_command");
      v34 = -22;
    }
    qdf_trace_msg(0x33u, 8u, "%s: exit", v26, v27, v28, v29, v30, v31, v32, v33, "hdd_driver_command");
    return v34;
  }
  return result;
}
