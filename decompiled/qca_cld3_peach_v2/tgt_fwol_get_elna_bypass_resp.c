__int64 __fastcall tgt_fwol_get_elna_bypass_resp(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  unsigned int ref; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 *v32; // x0
  __int64 result; // x0
  __int64 v34; // x9
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // [xsp+8h] [xbp-38h] BYREF
  __int64 *v44; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v45)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v46)(); // [xsp+20h] [xbp-20h]
  __int64 v47; // [xsp+28h] [xbp-18h]
  __int64 v48; // [xsp+30h] [xbp-10h]
  __int64 v49; // [xsp+38h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = 0;
  v45 = nullptr;
  v46 = nullptr;
  v43 = 0;
  v44 = nullptr;
  v4 = _qdf_mem_malloc(0x80u, "tgt_fwol_get_elna_bypass_resp", 128);
  if ( v4 )
  {
    v13 = v4;
    ref = wlan_objmgr_psoc_try_get_ref(a1, 0x47u, v5, v6, v7, v8, v9, v10, v11, v12);
    if ( ref )
    {
      v23 = ref;
      qdf_trace_msg(
        0x66u,
        2u,
        "%s: Failed to get psoc ref",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "tgt_fwol_get_elna_bypass_resp");
      v32 = (__int64 *)v13;
LABEL_7:
      fwol_release_rx_event(v32, v24, v25, v26, v27, v28, v29, v30, v31);
      result = v23;
      goto LABEL_8;
    }
    *(_QWORD *)v13 = a1;
    *(_DWORD *)(v13 + 8) = 1;
    v34 = *a2;
    LOWORD(v43) = 1;
    *(_QWORD *)(v13 + 12) = v34;
    v44 = (__int64 *)v13;
    v45 = fwol_process_event;
    v46 = fwol_flush_callback;
    result = scheduler_post_message_debug(
               0x66u,
               0x66u,
               73,
               (unsigned __int16 *)&v43,
               0x94u,
               (__int64)"tgt_fwol_get_elna_bypass_resp");
    if ( (_DWORD)result )
    {
      v23 = result;
      qdf_trace_msg(
        0x66u,
        2u,
        "%s: failed to send WLAN_FWOL_GET_ELNA_BYPASS_RESPONSE msg",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "tgt_fwol_get_elna_bypass_resp");
      v32 = v44;
      v44 = nullptr;
      goto LABEL_7;
    }
  }
  else
  {
    result = 2;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
