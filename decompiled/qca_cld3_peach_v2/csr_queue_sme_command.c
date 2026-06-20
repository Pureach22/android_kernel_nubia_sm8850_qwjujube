__int64 __fastcall csr_queue_sme_command(
        __int64 a1,
        _DWORD *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v13; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  __int64 v33; // x21
  unsigned int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int *v43; // x8
  _QWORD v44[4]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v45; // [xsp+28h] [xbp-18h]
  __int64 v46; // [xsp+30h] [xbp-10h]
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_DWORD *)(a1 + 12840);
  v45 = 0;
  v46 = 0;
  memset(v44, 0, sizeof(v44));
  if ( !v13 )
  {
    v23 = "%s: Sme in stop state";
    goto LABEL_5;
  }
  qdf_mem_set(v44, 0x30u, 0);
  if ( (unsigned int)csr_set_serialization_params_to_cmd(
                       a1,
                       a2,
                       (int *)v44,
                       a3 & 1,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22) )
  {
    v23 = "%s: failed to set ser params";
LABEL_5:
    qdf_trace_msg(0x34u, 2u, v23, a4, a5, a6, a7, a8, a9, a10, a11, "csr_queue_sme_command");
    goto LABEL_6;
  }
  v33 = v45;
  v34 = wlan_serialization_request((unsigned int *)v44, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( v34 < 2 )
  {
    result = 0;
    goto LABEL_7;
  }
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: Failed to queue command %d with status:%d",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "csr_queue_sme_command",
    (unsigned int)a2[4],
    v34);
  if ( v33 )
    wlan_objmgr_vdev_release_ref(v33, 0xBu, v43, v24, v25, v26, v27, v28, v29, v30, v31);
LABEL_6:
  csr_release_command_buffer(a1, (__int64)a2, v24, v25, v26, v27, v28, v29, v30, v31);
  result = 16;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
