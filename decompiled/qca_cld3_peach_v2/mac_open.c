__int64 __fastcall mac_open(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int ref; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  __int64 result; // x0
  __int64 ext_hdl; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double inited; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w20

  if ( !a2 )
    return 16;
  qword_91BFB8 = a3;
  ref = wlan_objmgr_psoc_try_get_ref(a1, 7u, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( ref )
  {
    v24 = ref;
    qdf_trace_msg(0x35u, 2u, "%s: PSOC get ref failure", v16, v17, v18, v19, v20, v21, v22, v23, "mac_open");
    return v24;
  }
  qword_91E210 = a1;
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(a1);
  if ( !ext_hdl )
  {
    qdf_trace_msg(0x35u, 2u, "%s: Failed to get MLME Obj", v27, v28, v29, v30, v31, v32, v33, v34, "mac_open");
    LODWORD(result) = 16;
LABEL_11:
    v51 = result;
    wlan_objmgr_psoc_release_ref(a1, 7u, v43, v44, v45, v46, v47, v48, v49, v50);
    return v51;
  }
  qword_918DA0 = ext_hdl;
  *a2 = &global_mac_context;
  if ( *(_DWORD *)(a4 + 8) )
    global_mac_context = 1;
  inited = sys_init_globals(&global_mac_context);
  word_91E1FC = 2047;
  dword_91E260 = 3847;
  byte_91E258 = 1;
  result = pe_open((__int64)&global_mac_context, (unsigned __int16 *)a4, inited, v36, v37, v38, v39, v40, v41, v42);
  if ( (_DWORD)result )
    goto LABEL_11;
  return result;
}
