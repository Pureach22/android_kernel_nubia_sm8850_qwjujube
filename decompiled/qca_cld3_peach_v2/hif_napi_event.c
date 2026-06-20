__int64 __fastcall hif_napi_event(__int64 a1, int a2, unsigned __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w0
  int v27; // w8
  int v28; // w9
  __int64 i; // x21
  __int64 v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  const char *v39; // x2
  unsigned __int64 v40; // x8
  __int64 v41; // x8
  _DWORD *v42; // x21
  __int64 v43; // x8
  int v44; // w22
  unsigned int v45; // w21
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 j; // x21
  __int64 v56; // x8
  unsigned int v57; // w25
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  _QWORD *v66; // x20
  __int64 v67; // x8
  __int64 v68; // x8
  __int64 v69; // x8
  __int64 v70; // x8
  __int64 v71; // x8
  __int64 v72; // x8
  __int64 v73; // x8
  __int64 v74; // x8
  __int64 v75; // x8
  __int64 v76; // x8
  __int64 v77; // x8
  __int64 k; // x19
  __int64 v79; // x21
  __int64 v80; // x0

  if ( (ce_srng_based(a1) & 1) != 0 )
    return hif_exec_event(a1, a2, a3);
  if ( (*(_BYTE *)(a1 + 768) & 1) == 0 )
    return 4294967274LL;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 752);
  }
  else
  {
    raw_spin_lock_bh(a1 + 752);
    *(_QWORD *)(a1 + 760) |= 1uLL;
  }
  v17 = *(_DWORD *)(a1 + 768);
  if ( a2 <= 3 )
  {
    if ( (unsigned int)(a2 - 1) < 3 )
    {
      qdf_trace_msg(
        0x3Du,
        8u,
        "%s: recved evnt: STATE_CMD %d; v = %d (state=0x%0x)",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "hif_napi_event",
        (unsigned int)a2,
        a3 != 0,
        v17);
      if ( a3 )
      {
        if ( (v17 & 2) == 0 )
        {
          qdf_trace_msg(0x3Du, 8u, "%s: Setting state to ON", v18, v19, v20, v21, v22, v23, v24, v25, "hif_napi_event");
          v26 = 0;
          *(_DWORD *)(a1 + 768) |= 2u;
          goto LABEL_43;
        }
        v39 = "%s: Duplicate NAPI conf ON msg";
      }
      else
      {
        if ( (v17 & 2) != 0 )
        {
          qdf_trace_msg(0x3Du, 8u, "%s: Setting state to OFF", v18, v19, v20, v21, v22, v23, v24, v25, "hif_napi_event");
          v26 = 0;
          *(_DWORD *)(a1 + 768) &= ~2u;
          goto LABEL_43;
        }
        v39 = "%s: Duplicate NAPI conf OFF msg";
      }
      qdf_trace_msg(0x3Du, 8u, v39, v18, v19, v20, v21, v22, v23, v24, v25, "hif_napi_event");
      goto LABEL_42;
    }
    goto LABEL_39;
  }
  if ( a2 > 5 )
  {
    if ( a2 == 6 )
    {
      v26 = ((__int64 (__fastcall *)(__int64, __int64, __int64))hif_napi_cpu_migrate)(a1 + 744, 0xFFFFFFFFLL, 1);
      if ( a3 || v26 )
        goto LABEL_43;
      goto LABEL_48;
    }
    if ( a2 == 7 )
    {
      v27 = *(_DWORD *)(a1 + 780);
      v26 = 0;
      *(_DWORD *)(a1 + 2424) = 0;
      if ( v27 )
        goto LABEL_43;
LABEL_21:
      if ( (~*(unsigned __int8 *)(a1 + 2440) & 0xC) == 0 )
      {
        v28 = hif_napi_cpu_denylist_ref_count;
        if ( hif_napi_cpu_denylist_ref_count )
        {
          --hif_napi_cpu_denylist_ref_count;
          if ( v28 == 1 )
          {
            for ( i = 0; i != 12; ++i )
            {
              if ( ((*(_DWORD *)(a1 + 772) >> i) & 1) != 0 )
              {
                v30 = *(_QWORD *)(a1 + 784 + 8 * i);
                if ( v30 )
                {
                  irq_modify_status(*(unsigned int *)(v30 + 3132), 0x2000, 0);
                  qdf_trace_msg(
                    0x3Du,
                    8u,
                    "%s: dl_flag %d CE %d",
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    "hif_napi_dl_irq",
                    0,
                    (unsigned int)i);
                }
              }
              v26 = 0;
            }
            goto LABEL_43;
          }
        }
      }
LABEL_42:
      v26 = 0;
      goto LABEL_43;
    }
LABEL_39:
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: Unknown event: %d (data=0x%0lx)",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "hif_napi_event",
      (unsigned int)a2,
      a3);
    goto LABEL_42;
  }
  if ( a2 == 4 )
  {
    if ( (unsigned __int8)a3 == 1 && *(_DWORD *)(a1 + 2424) == 2 )
    {
      v40 = (int)(a3 >> 16);
      if ( v40 >= 0x20 )
      {
        __break(0x5512u);
        __asm { PRFM            #0x13, [X5,#0x4938] }
        JUMPOUT(0x71AEB0);
      }
      v41 = a1 + 48LL * (int)v40;
      if ( *(_DWORD *)(v41 + 916) )
      {
        v42 = (_DWORD *)(v41 + 916);
        v26 = ((__int64 (__fastcall *)(__int64))hif_napi_cpu_migrate)(a1 + 744);
        *v42 = 0;
        goto LABEL_43;
      }
    }
    goto LABEL_42;
  }
  if ( (_DWORD)a3 == 1 )
  {
    *(_DWORD *)(a1 + 2424) = 1;
    goto LABEL_21;
  }
  v26 = ((__int64 (__fastcall *)(__int64, __int64, __int64))hif_napi_cpu_migrate)(a1 + 744, 0xFFFFFFFFLL, 0xFFFFFFFFLL);
  *(_DWORD *)(a1 + 2424) = a3;
LABEL_48:
  if ( (~*(unsigned __int8 *)(a1 + 2440) & 0xC) == 0 && !hif_napi_cpu_denylist_ref_count++ )
  {
    for ( j = 0; j != 12; ++j )
    {
      if ( ((*(_DWORD *)(a1 + 772) >> j) & 1) != 0 )
      {
        v56 = *(_QWORD *)(a1 + 784 + 8 * j);
        if ( v56 )
        {
          v57 = v26;
          irq_modify_status(*(unsigned int *)(v56 + 3132), 0, 0x2000);
          qdf_trace_msg(
            0x3Du,
            8u,
            "%s: dl_flag %d CE %d",
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            "hif_napi_dl_irq",
            1,
            (unsigned int)j);
          v26 = v57;
        }
      }
    }
  }
LABEL_43:
  v43 = *(_QWORD *)(a1 + 760);
  v44 = *(_DWORD *)(a1 + 768);
  v45 = v26;
  if ( (v43 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 760) = v43 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 752);
    if ( v17 == v44 )
      goto LABEL_45;
  }
  else
  {
    raw_spin_unlock(a1 + 752);
    if ( v17 == v44 )
    {
LABEL_45:
      qdf_trace_msg(
        0x3Du,
        8u,
        "%s: no change in hif napi state (still %d)",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "hif_napi_event",
        v17);
      return v45;
    }
  }
  v66 = (_QWORD *)(a1 + 784);
  if ( *(_DWORD *)(a1 + 768) == 3 )
  {
    if ( *v66 )
      napi_enable(*v66 + 2696LL);
    v67 = *(_QWORD *)(a1 + 792);
    if ( v67 )
      napi_enable(v67 + 2696);
    v68 = *(_QWORD *)(a1 + 800);
    if ( v68 )
      napi_enable(v68 + 2696);
    v69 = *(_QWORD *)(a1 + 808);
    if ( v69 )
      napi_enable(v69 + 2696);
    v70 = *(_QWORD *)(a1 + 816);
    if ( v70 )
      napi_enable(v70 + 2696);
    v71 = *(_QWORD *)(a1 + 824);
    if ( v71 )
      napi_enable(v71 + 2696);
    v72 = *(_QWORD *)(a1 + 832);
    if ( v72 )
      napi_enable(v72 + 2696);
    v73 = *(_QWORD *)(a1 + 840);
    if ( v73 )
      napi_enable(v73 + 2696);
    v74 = *(_QWORD *)(a1 + 848);
    if ( v74 )
      napi_enable(v74 + 2696);
    v75 = *(_QWORD *)(a1 + 856);
    if ( v75 )
      napi_enable(v75 + 2696);
    v76 = *(_QWORD *)(a1 + 864);
    if ( v76 )
      napi_enable(v76 + 2696);
    v77 = *(_QWORD *)(a1 + 872);
    if ( v77 )
      napi_enable(v77 + 2696);
    return 1;
  }
  else
  {
    for ( k = 0; k != 12; ++k )
    {
      v79 = v66[k];
      if ( v79 )
      {
        napi_disable(v79 + 2696);
        v80 = _irq_apply_affinity_hint(*(unsigned int *)(v79 + 3132), 0, 1);
        qdf_status_from_os_return(v80);
      }
    }
    return 0;
  }
}
