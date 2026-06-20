__int64 __fastcall nan_pasn_scheduled_handler(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x19
  _QWORD *comp_private_obj; // x0
  int v12; // w4
  __int64 (__fastcall *v13)(__int64, __int64 *, __int64, __int64); // x8
  __int64 v14; // x0
  __int64 v15; // x2
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  unsigned int v26; // w19
  const char *v27; // x2
  _DWORD *v29; // x8
  __int64 v30; // x0
  __int64 v31; // x1
  __int64 v32; // x0
  _QWORD *v33; // x20
  __int64 v34; // x0
  double (*v35)(void); // x8
  __int64 v36; // x19
  double v37; // d0
  unsigned int v38; // w0
  unsigned int v39; // w20
  unsigned int *v40; // x8
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  if ( !a1 || (v9 = *((__int64 **)a1 + 1)) == nullptr )
  {
    v27 = "%s: msg or bodyptr is null";
    goto LABEL_16;
  }
  if ( !*v9 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
    goto LABEL_15;
  }
  comp_private_obj = (_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(*v9, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_15:
    v27 = "%s: psoc_nan_obj is null";
    goto LABEL_16;
  }
  v12 = *a1;
  if ( v12 == 2 )
  {
    if ( comp_private_obj[23] )
    {
      v33 = comp_private_obj;
      v34 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              *v9,
              *((unsigned __int8 *)v9 + 14),
              20);
      if ( !v34 )
      {
        v27 = "%s: vdev is null";
        goto LABEL_16;
      }
      v35 = (double (*)(void))v33[23];
      v36 = v34;
      if ( *((_DWORD *)v35 - 1) != 1263140689 )
        __break(0x8228u);
      v37 = v35();
      v39 = v38;
      wlan_objmgr_vdev_release_ref(v36, 0x14u, v40, v37, v41, v42, v43, v44, v45, v46, v47);
      v16 = v39;
      v25 = *((_QWORD *)a1 + 1);
      if ( !v25 )
        goto LABEL_12;
LABEL_21:
      v26 = v16;
      if ( *a1 >= 3u )
      {
        qdf_trace_msg(
          0x53u,
          2u,
          "%s: Unsupported request type: %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "nan_pasn_flush_callback");
        v32 = *((_QWORD *)a1 + 1);
      }
      else
      {
        v32 = v25;
      }
      _qdf_mem_free(v32);
      return v26;
    }
    v27 = "%s: NAN PASN peer delete all ops is NULL";
LABEL_16:
    qdf_trace_msg(0x53u, 2u, v27, a2, a3, a4, a5, a6, a7, a8, a9, "nan_pasn_scheduled_handler");
    return 29;
  }
  if ( v12 == 1 )
  {
    v29 = (_DWORD *)comp_private_obj[22];
    if ( v29 )
    {
      v30 = *v9;
      v31 = *((unsigned __int8 *)v9 + 14);
      if ( *(v29 - 1) != -232243948 )
        __break(0x8228u);
      v16 = ((__int64 (__fastcall *)(__int64, __int64, __int64 *, __int64, _QWORD))v29)(v30, v31, v9 + 1, 13, 0);
      v25 = *((_QWORD *)a1 + 1);
      if ( !v25 )
        goto LABEL_12;
      goto LABEL_21;
    }
    v27 = "%s: NAN PASN peer delete ops is NULL";
    goto LABEL_16;
  }
  if ( *a1 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Unsupported request type: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "nan_pasn_scheduled_handler");
    _qdf_mem_free(*((_QWORD *)a1 + 1));
    return 16;
  }
  v13 = (__int64 (__fastcall *)(__int64, __int64 *, __int64, __int64))comp_private_obj[21];
  if ( !v13 )
  {
    v27 = "%s: NAN PASN peer create ops is NULL";
    goto LABEL_16;
  }
  v14 = *v9;
  v15 = *((unsigned __int8 *)v9 + 14);
  if ( *((_DWORD *)v13 - 1) != 933372279 )
    __break(0x8228u);
  v16 = v13(v14, v9 + 1, v15, 12);
  v25 = *((_QWORD *)a1 + 1);
  if ( v25 )
    goto LABEL_21;
LABEL_12:
  v26 = v16;
  qdf_trace_msg(
    0x53u,
    2u,
    "%s: Null pointer for NAN Discovery message",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "nan_pasn_flush_callback");
  return v26;
}
