__int64 __fastcall dlm_add_userspace_deny_list(__int64 a1, int *a2, char a3)
{
  __int64 v3; // x21
  __int64 v6; // x22
  __int64 psoc_obj; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x28
  __int64 pdev_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x23
  const char *v27; // x2
  __int64 result; // x0
  unsigned __int8 *i; // x1
  __int64 v30; // x4
  __int64 v31; // x5
  __int64 v32; // x6
  __int64 v33; // x7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x27
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7
  unsigned int v47; // w9
  unsigned int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w19
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  int v66; // w8
  __int16 v67; // w9
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned __int8 *v76; // [xsp+8h] [xbp-48h] BYREF
  unsigned __int8 *v77; // [xsp+10h] [xbp-40h] BYREF
  _QWORD v78[4]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v79; // [xsp+38h] [xbp-18h]
  __int64 v80; // [xsp+40h] [xbp-10h]
  __int64 v81; // [xsp+48h] [xbp-8h]

  LOBYTE(v3) = a3;
  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v79 = 0;
  v80 = 0;
  memset(v78, 0, sizeof(v78));
  v6 = ((__int64 (*)(void))dlm_get_pdev_obj)();
  psoc_obj = dlm_get_psoc_obj(*(_QWORD *)(a1 + 80));
  if ( !v6 || !psoc_obj )
  {
    qdf_trace_msg(
      0x6Du,
      2u,
      "%s: dlm_ctx or dlm_psoc_obj is NULL",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "dlm_add_userspace_deny_list");
    result = 4;
    goto LABEL_34;
  }
  v16 = psoc_obj;
  v76 = nullptr;
  v77 = nullptr;
  pdev_obj = dlm_get_pdev_obj(a1);
  if ( !pdev_obj )
  {
    v27 = "%s: dlm_ctx is NULL";
    goto LABEL_8;
  }
  v26 = pdev_obj;
  if ( (unsigned int)qdf_mutex_acquire(pdev_obj) )
  {
    v27 = "%s: failed to acquire reject_ap_list_lock";
LABEL_8:
    qdf_trace_msg(0x6Du, 2u, v27, v18, v19, v20, v21, v22, v23, v24, v25, "dlm_clear_userspace_denylist_info");
    goto LABEL_23;
  }
  qdf_list_peek_front((_QWORD *)(v26 + 64), &v77);
  for ( i = v77; i; v77 = i )
  {
    qdf_list_peek_next((_QWORD *)(v26 + 64), i, &v76);
    v42 = (__int64)v77;
    if ( (v77[104] & 0x3F) == 1 )
    {
      if ( v77 == (unsigned __int8 *)-16LL )
      {
        v32 = 0;
        v30 = 0;
        v31 = 0;
        v33 = 0;
      }
      else
      {
        v30 = v77[16];
        v31 = v77[17];
        v32 = v77[18];
        v33 = v77[21];
      }
      qdf_trace_msg(
        0x6Du,
        8u,
        "%s: removing bssid: %02x:%02x:%02x:**:**:%02x",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "dlm_clear_userspace_denylist_info",
        v30,
        v31,
        v32,
        v33);
      qdf_list_remove_node(v26 + 64, (_QWORD *)v42);
      _qdf_mem_free(v42);
    }
    else if ( (v77[104] & 1) != 0 )
    {
      if ( v77 == (unsigned __int8 *)-16LL )
      {
        v45 = 0;
        v43 = 0;
        v44 = 0;
        v46 = 0;
      }
      else
      {
        v43 = v77[16];
        v44 = v77[17];
        v45 = v77[18];
        v46 = v77[21];
      }
      qdf_trace_msg(
        0x6Du,
        8u,
        "%s: Clearing userspace denylist bit for %02x:%02x:%02x:**:**:%02x",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "dlm_clear_userspace_denylist_info",
        v43,
        v44,
        v45,
        v46);
      v47 = *(_DWORD *)(v42 + 108) & 0xFFFFFFDF;
      *(_BYTE *)(v42 + 104) &= ~1u;
      *(_DWORD *)(v42 + 108) = v47;
    }
    i = v76;
    v76 = nullptr;
  }
  qdf_mutex_release(v26);
LABEL_23:
  v48 = qdf_mutex_acquire(v6);
  if ( v48 )
  {
    v57 = v48;
    qdf_trace_msg(
      0x6Du,
      2u,
      "%s: failed to acquire reject_ap_list_lock",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "dlm_add_userspace_deny_list");
    result = v57;
  }
  else
  {
    dlm_send_reject_ap_list_to_fw(a1, v6 + 64, v16 + 8);
    qdf_mutex_release(v6);
    if ( a2 && (_BYTE)v3 )
    {
      v3 = (unsigned __int8)v3;
      while ( 1 )
      {
        qdf_mem_set(v78, 0x30u, 0);
        v66 = *a2;
        v67 = *((_WORD *)a2 + 2);
        v79 = 0x600000001LL;
        LODWORD(v78[0]) = v66;
        WORD2(v78[0]) = v67;
        LODWORD(v80) = 1;
        if ( (unsigned int)dlm_add_bssid_to_reject_list(a1, (__int64)v78) )
          break;
        --v3;
        a2 = (int *)((char *)a2 + 6);
        if ( !v3 )
          goto LABEL_32;
      }
      qdf_trace_msg(
        0x6Du,
        2u,
        "%s: Failed to add bssid to userspace denylist",
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        "dlm_add_userspace_deny_list");
      result = 16;
    }
    else
    {
      qdf_trace_msg(
        0x6Du,
        8u,
        "%s: Userspace denylist/num of denylist NULL",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "dlm_add_userspace_deny_list");
LABEL_32:
      result = 0;
    }
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
