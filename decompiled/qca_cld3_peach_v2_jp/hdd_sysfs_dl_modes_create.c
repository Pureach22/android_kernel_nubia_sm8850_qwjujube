__int64 __fastcall hdd_sysfs_dl_modes_create(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
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
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 result; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7

  if ( (unsigned int)device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_loglevel) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create dl_loglevel sysfs file",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "hdd_sysfs_dl_loglevel_create");
  if ( (unsigned int)device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_mod_loglevel) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create dl_mod_loglevel sysfs file",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "hdd_sysfs_dl_mod_loglevel_create");
  if ( (unsigned int)device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_modoff) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create dl_modoff sysfs file",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hdd_sysfs_dl_modoff_create");
  if ( (unsigned int)device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_modon) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create dl_modon sysfs file",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hdd_sysfs_dl_modon_create");
  if ( (unsigned int)device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_report) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create dl_report sysfs file",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "hdd_sysfs_dl_report_create");
  if ( (unsigned int)device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_type) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create dl_type sysfs file",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "hdd_sysfs_dl_type_create");
  if ( (unsigned int)device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_vapoff) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not create dl_vapoff sysfs file",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "hdd_sysfs_dl_vapoff_create");
  result = device_create_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_vapon);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: could not create dl_vapon sysfs file",
             v59,
             v60,
             v61,
             v62,
             v63,
             v64,
             v65,
             v66,
             "hdd_sysfs_dl_vapon_create");
  return result;
}
