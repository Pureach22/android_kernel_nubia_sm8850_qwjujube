__int64 __fastcall dp_mon_buffers_replenish(
        __int64 *a1,
        _QWORD *a2,
        __int64 a3,
        unsigned int a4,
        _QWORD *a5,
        _QWORD **a6,
        _DWORD *a7,
        int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  __int64 v20; // x22
  __int64 v22; // x27
  unsigned int v23; // w25
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w3
  unsigned int v33; // w8
  unsigned int v34; // w9
  unsigned int v35; // w8
  unsigned int v36; // w9
  __int64 v37; // x0
  unsigned int v38; // w26
  unsigned int v39; // w9
  unsigned int v40; // w10
  unsigned int v41; // w9
  unsigned int v42; // w8
  unsigned int v43; // w9
  bool v44; // cf
  unsigned int v45; // w8
  unsigned int *v46; // x2
  __int64 v47; // x8
  unsigned int v48; // w19
  unsigned __int64 StatusReg; // x8
  _QWORD *v50; // x8
  _QWORD *v51; // x8
  __int64 v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w28
  unsigned int v62; // w25
  __int64 v63; // x1
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x8
  unsigned int v81; // w9
  __int64 v82; // x19
  _DWORD *v83; // x23
  __int64 *v84; // x8
  int v85; // w9
  __int64 v86; // x8
  __int64 *v87; // x9
  unsigned __int64 v88; // x11
  __int64 v89; // x0
  _DWORD *v90; // x19
  __int64 v91; // x8
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x8
  _QWORD **v102; // [xsp+8h] [xbp-38h]
  __int64 v104; // [xsp+18h] [xbp-28h]
  __int64 v105[4]; // [xsp+20h] [xbp-20h] BYREF

  v105[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v105, 0, 24);
  if ( !a4 )
  {
    v37 = qdf_trace_msg(
            0x92u,
            8u,
            "%s: %pK: Received request for 0 buffers replenish",
            a9,
            a10,
            a11,
            a12,
            a13,
            a14,
            a15,
            a16,
            "dp_mon_buffers_replenish",
            a1);
    v38 = 4;
    if ( *a5 )
      goto LABEL_82;
    goto LABEL_83;
  }
  v20 = *a2;
  v22 = a1[2507];
  v23 = a4;
  hal_srng_access_start_4(a1[141], *a2);
  v32 = *(_DWORD *)(v20 + 120);
  v33 = *(_DWORD *)(v20 + 136);
  if ( *(_DWORD *)(v20 + 116) )
  {
    v34 = v33 - v32;
    if ( v33 < v32 )
      v34 += *(_DWORD *)(v20 + 36);
    v35 = *(_DWORD *)(v20 + 44);
    v36 = v34 / v35;
  }
  else
  {
    v39 = v33 - v32;
    if ( v33 <= v32 )
      v39 += *(_DWORD *)(v20 + 36);
    v35 = *(_DWORD *)(v20 + 44);
    v36 = v39 / v35 - 1;
  }
  if ( v36 > *(_DWORD *)(v20 + 240) )
  {
    *(_DWORD *)(v20 + 240) = v36;
    *(_QWORD *)(v20 + 248) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
  }
  if ( v36 >= *(_DWORD *)(v20 + 276) )
  {
    ++*(_DWORD *)(v20 + 300);
  }
  else if ( v36 >= *(_DWORD *)(v20 + 272) )
  {
    ++*(_DWORD *)(v20 + 296);
  }
  else if ( v36 >= *(_DWORD *)(v20 + 268) )
  {
    ++*(_DWORD *)(v20 + 292);
  }
  else if ( v36 >= *(_DWORD *)(v20 + 264) )
  {
    ++*(_DWORD *)(v20 + 288);
  }
  else if ( v36 >= *(_DWORD *)(v20 + 260) )
  {
    ++*(_DWORD *)(v20 + 284);
  }
  else
  {
    ++*(_DWORD *)(v20 + 280);
  }
  v40 = **(_DWORD **)(v20 + 128);
  v41 = v40 - v32;
  *(_DWORD *)(v20 + 136) = v40;
  if ( v40 <= v32 )
    v41 += *(_DWORD *)(v20 + 36);
  v42 = v41 / v35 - 1;
  if ( !v42 )
    goto LABEL_39;
  if ( a8 == 24 )
  {
    v43 = *(unsigned __int16 *)(v22 + 842);
    v44 = v42 >= v43;
    v45 = v42 - v43;
    if ( v44 )
      v23 = v45;
    else
      v23 = 0;
    if ( v45 != 0 && v44 )
      goto LABEL_37;
LABEL_39:
    if ( v20 )
    {
      v46 = *(unsigned int **)(v20 + 144);
      if ( (*(_DWORD *)(v20 + 76) & 0x80000000) != 0 )
      {
        *v46 = v32;
        v47 = *(_QWORD *)(v20 + 88);
        if ( (v47 & 1) == 0 )
          goto LABEL_42;
      }
      else
      {
        hal_delayed_reg_write(a1[141], (unsigned __int8 *)v20, (__int64)v46, v32);
        v47 = *(_QWORD *)(v20 + 88);
        if ( (v47 & 1) == 0 )
        {
LABEL_42:
          v37 = raw_spin_unlock(v20 + 80);
          goto LABEL_43;
        }
      }
      *(_QWORD *)(v20 + 88) = v47 & 0xFFFFFFFFFFFFFFFELL;
      v37 = raw_spin_unlock_bh(v20 + 80);
    }
    else
    {
      v37 = qdf_trace_msg(
              0x38u,
              2u,
              "%s: Error: Invalid hal_ring\n",
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              "hal_srng_access_end");
    }
LABEL_43:
    v38 = 0;
    if ( *a5 )
      goto LABEL_82;
    goto LABEL_83;
  }
  if ( a8 == 16 && v42 < v23 )
    v23 = v42;
LABEL_37:
  if ( !*a5 )
  {
    v48 = (unsigned __int16)v23;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a3 + 24);
    }
    else
    {
      raw_spin_lock_bh(a3 + 24);
      *(_QWORD *)(a3 + 32) |= 1uLL;
    }
    v50 = *(_QWORD **)(a3 + 16);
    *a6 = v50;
    *a5 = v50;
    if ( (_WORD)v23 )
    {
      v51 = *(_QWORD **)(a3 + 16);
      v23 = 0;
      while ( v51 )
      {
        *a6 = v51;
        ++v23;
        v51 = **(_QWORD ***)(a3 + 16);
        *(_QWORD *)(a3 + 16) = v51;
        if ( v23 >= v48 )
          goto LABEL_53;
      }
      qdf_spin_unlock_bh_17(a3 + 24);
      if ( !v23 )
      {
LABEL_88:
        qdf_trace_msg(
          0x92u,
          8u,
          "%s: %pK: no free rx_descs in freelist",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "dp_mon_buffers_replenish",
          a1);
        if ( v20 )
        {
          if ( (*(_DWORD *)(v20 + 76) & 0x80000000) != 0 )
            **(_DWORD **)(v20 + 144) = *(_DWORD *)(v20 + 120);
          else
            hal_delayed_reg_write(a1[141], (unsigned __int8 *)v20, *(_QWORD *)(v20 + 144), *(_DWORD *)(v20 + 120));
          v101 = *(_QWORD *)(v20 + 88);
          if ( (v101 & 1) != 0 )
          {
            *(_QWORD *)(v20 + 88) = v101 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v20 + 80);
          }
          else
          {
            raw_spin_unlock(v20 + 80);
          }
          v38 = 2;
        }
        else
        {
          v38 = 2;
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Error: Invalid hal_ring\n",
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            v100,
            "hal_srng_access_end");
        }
        goto LABEL_83;
      }
    }
    else
    {
LABEL_53:
      **a6 = 0;
      v52 = *(_QWORD *)(a3 + 32);
      if ( (v52 & 1) != 0 )
      {
        *(_QWORD *)(a3 + 32) = v52 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a3 + 24);
        v23 = v48;
        if ( !v48 )
          goto LABEL_88;
      }
      else
      {
        raw_spin_unlock(a3 + 24);
        v23 = v48;
        if ( !v48 )
          goto LABEL_88;
      }
    }
    v102 = a6;
    qdf_trace_msg(
      0x92u,
      5u,
      "%s: %pK: %d rx desc allocated",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "dp_mon_buffers_replenish",
      a1,
      v23);
    goto LABEL_56;
  }
  v102 = a6;
LABEL_56:
  v61 = 0;
  v62 = v23 - 1;
  while ( 1 )
  {
    while ( 1 )
    {
      v63 = _page_frag_alloc_align(a3 + 48, (*(unsigned __int16 *)(a3 + 42) + 63) & 0x1FFC0, 2080, 0xFFFFFFFFLL);
      v104 = v63;
      if ( !v63 )
      {
        v38 = 2;
        qdf_trace_msg(
          0x92u,
          2u,
          "%s: Frag alloc failed",
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          "dp_mon_frag_alloc_and_map");
LABEL_76:
        if ( v20 )
          goto LABEL_77;
LABEL_71:
        v37 = qdf_trace_msg(
                0x38u,
                2u,
                "%s: Error: Invalid hal_ring\n",
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                "hal_srng_access_end");
        v90 = a7;
        if ( !a7 )
          goto LABEL_81;
        goto LABEL_80;
      }
      if ( !(unsigned int)_qdf_mem_map_page(a1[3], v63, 2u, *(unsigned __int16 *)(a3 + 42), v105) )
        break;
      if ( v104 )
        page_frag_free(v104);
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: Frag map failed",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        "dp_mon_frag_alloc_and_map");
    }
    v80 = *(unsigned int *)(v20 + 120);
    ++v61;
    v81 = (unsigned int)(*(_DWORD *)(v20 + 44) + v80) % *(_DWORD *)(v20 + 36);
    if ( v81 == *(_DWORD *)(v20 + 136) )
      break;
    v82 = *(_QWORD *)*a5;
    v83 = (_DWORD *)(*(_QWORD *)(v20 + 16) + 4 * v80);
    *(_DWORD *)(v20 + 120) = v81;
    *(_DWORD *)(v20 + 124) = v81;
    if ( !v83 )
      break;
    v84 = (__int64 *)*a5;
    v85 = *(_DWORD *)(*a5 + 16LL);
    if ( (v85 & 1) != 0 )
    {
      v89 = printk(
              &unk_9BB309,
              "(*desc_list)->mon_desc.in_use == 0",
              "dp_mon_buffers_replenish",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_mon_2.0.c");
      dump_stack(v89);
      v84 = (__int64 *)*a5;
      v85 = *(_DWORD *)(*a5 + 16LL);
    }
    v38 = 0;
    *((_DWORD *)v84 + 4) = v85 | 1;
    *(_DWORD *)(*a5 + 16LL) &= ~2u;
    *(_QWORD *)*a5 = v104;
    v86 = v105[0];
    *(_QWORD *)(*a5 + 8LL) = v105[0];
    *(_DWORD *)(*a5 + 28LL) = -559043635;
    *(_DWORD *)(*a5 + 16LL) = *(_DWORD *)(*a5 + 16LL) & 0xFC000003
                            | (4 * (((unsigned int)(*(_DWORD *)(*a5 + 16LL) + 4) >> 2) & 0xFFFFFF));
    ++*(_DWORD *)(v22 + 440);
    v87 = (__int64 *)*a5;
    v88 = *a5 & 0xFF00000000LL | ((unsigned __int64)(*(_DWORD *)(*a5 + 16LL) >> 2) << 40);
    *v83 = v86;
    v83[1] = BYTE4(v86);
    v83[2] = (_DWORD)v87;
    v83[3] = HIDWORD(v88);
    *a5 = v82;
    if ( !v82 || v61 > v62 )
      goto LABEL_76;
  }
  if ( v104 )
  {
    page_frag_free(v104);
    v38 = 0;
    if ( !v20 )
      goto LABEL_71;
  }
  else
  {
    v38 = 0;
    if ( !v20 )
      goto LABEL_71;
  }
LABEL_77:
  v90 = a7;
  if ( (*(_DWORD *)(v20 + 76) & 0x80000000) != 0 )
  {
    **(_DWORD **)(v20 + 144) = *(_DWORD *)(v20 + 120);
    v91 = *(_QWORD *)(v20 + 88);
    if ( (v91 & 1) == 0 )
      goto LABEL_79;
  }
  else
  {
    hal_delayed_reg_write(a1[141], (unsigned __int8 *)v20, *(_QWORD *)(v20 + 144), *(_DWORD *)(v20 + 120));
    v91 = *(_QWORD *)(v20 + 88);
    if ( (v91 & 1) == 0 )
    {
LABEL_79:
      v37 = raw_spin_unlock(v20 + 80);
      if ( !a7 )
        goto LABEL_81;
      goto LABEL_80;
    }
  }
  *(_QWORD *)(v20 + 88) = v91 & 0xFFFFFFFFFFFFFFFELL;
  v37 = raw_spin_unlock_bh(v20 + 80);
  if ( a7 )
LABEL_80:
    *v90 += v61;
LABEL_81:
  a6 = v102;
  if ( *a5 )
LABEL_82:
    dp_mon_add_desc_list_to_free_list(v37, a5, a6, a3);
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return v38;
}
