__int64 __fastcall reg_send_scheduler_msg_nb(__int64 a1, __int64 a2)
{
  __int64 pdev_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int ref; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w19
  __int64 result; // x0
  const char *v24; // x2
  unsigned int v25; // w1
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w20
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x21
  unsigned int *v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w22
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned int *v71; // x8
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // [xsp+0h] [xbp-40h] BYREF
  __int64 v89; // [xsp+8h] [xbp-38h] BYREF
  __int64 v90; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v91)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v92)(); // [xsp+20h] [xbp-20h]
  __int64 v93; // [xsp+28h] [xbp-18h]
  __int64 v94; // [xsp+30h] [xbp-10h]
  __int64 v95; // [xsp+38h] [xbp-8h]

  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v93 = 0;
  v94 = 0;
  v91 = nullptr;
  v92 = nullptr;
  v89 = 0;
  v90 = 0;
  pdev_obj = reg_get_pdev_obj(a2);
  if ( !pdev_obj )
  {
    v24 = "%s: pdev reg component is NULL";
    v25 = 1;
LABEL_7:
    qdf_trace_msg(0x51u, v25, v24, v5, v6, v7, v8, v9, v10, v11, v12, "reg_send_scheduler_msg_nb");
    result = 16;
    goto LABEL_8;
  }
  if ( (*(_BYTE *)(pdev_obj + 58200) & 1) == 0 )
  {
    v24 = "%s: Empty channel list";
    v25 = 2;
    goto LABEL_7;
  }
  ref = wlan_objmgr_psoc_try_get_ref(a1, 0x16u, v5, v6, v7, v8, v9, v10, v11, v12);
  if ( ref )
  {
    v22 = ref;
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: error taking psoc ref cnt",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "reg_send_scheduler_msg_nb");
    result = v22;
  }
  else
  {
    v26 = wlan_objmgr_pdev_try_get_ref(a2, 0x16u, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( v26 )
    {
      v35 = v26;
      wlan_objmgr_psoc_release_ref(a1, 0x16u, v27, v28, v29, v30, v31, v32, v33, v34);
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: error taking pdev ref cnt",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "reg_send_scheduler_msg_nb");
      result = v35;
    }
    else
    {
      v88 = 0;
      reg_alloc_and_fill_payload(a1, a2, (__int64)&v88);
      v52 = v88;
      if ( v88 )
      {
        v90 = v88;
        v91 = reg_sched_chan_change_cbks_nb;
        v92 = reg_chan_change_flush_cbk_nb;
        result = scheduler_post_message_debug(
                   0x51u,
                   0x51u,
                   72,
                   (unsigned __int16 *)&v89,
                   0x150u,
                   (__int64)"reg_send_scheduler_msg_nb");
        if ( (_DWORD)result )
        {
          v62 = result;
          wlan_objmgr_pdev_release_ref(a2, 0x16u, v53, v54, v55, v56, v57, v58, v59, v60, v61);
          wlan_objmgr_psoc_release_ref(a1, 0x16u, v63, v64, v65, v66, v67, v68, v69, v70);
          _qdf_mem_free(v52);
          result = v62;
        }
      }
      else
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: malloc failed",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "reg_send_scheduler_msg_nb");
        wlan_objmgr_pdev_release_ref(a2, 0x16u, v71, v72, v73, v74, v75, v76, v77, v78, v79);
        wlan_objmgr_psoc_release_ref(a1, 0x16u, v80, v81, v82, v83, v84, v85, v86, v87);
        result = 2;
      }
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
