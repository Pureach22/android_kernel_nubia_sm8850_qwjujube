__int64 __fastcall hif_pci_enable_bus(
        __int64 a1,
        __int64 a2,
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
  __int64 v16; // x24
  unsigned int conparam; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x0
  __int64 target_info_handle; // x0
  int v28; // w25
  __int64 v29; // x20
  __int64 (__fastcall *v30)(); // x8
  __int64 (__fastcall *v31)(); // x9
  __int64 (__fastcall *v32)(); // x10
  __int64 (__fastcall *v33)(__int64, __int64, __int64); // x8
  unsigned int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int16 v43; // w8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  const char *v61; // x2
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  int v70; // w22
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x4
  __int64 result; // x0
  unsigned int v81; // w19
  const char *v82; // x2
  int v83; // w21
  const char *v84; // x20
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  int v93; // w20
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  void (__fastcall *v102)(_QWORD); // x8
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  unsigned int v111; // w23
  int v112; // w24
  int v113; // w0
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x0
  unsigned __int16 v123; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v124; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v125; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v126; // [xsp+18h] [xbp-8h]

  v126 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v125 = 0;
  v124 = 0;
  v123 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0x3Du, 2u, "%s: hif_ctx is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "hif_pci_enable_bus");
    result = 2;
    goto LABEL_61;
  }
  v16 = a1 + 28672;
  conparam = hif_get_conparam(a1);
  v26 = qdf_trace_msg(
          0x3Du,
          5u,
          "%s: con_mode = 0x%x, WLAN_SOC_device_id = 0x%x",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "hif_pci_enable_bus",
          conparam,
          *(unsigned int *)(a4 + 4));
  *(_QWORD *)(a1 + 30768) = a3;
  *(_QWORD *)(a1 + 30760) = a3 + 200;
  *(_WORD *)(v16 + 2236) = *(_DWORD *)(a4 + 4);
  *(_DWORD *)(v16 + 2232) = cache_line_size(v26);
  target_info_handle = hif_get_target_info_handle(a1);
  v28 = *(_DWORD *)(a4 + 4);
  v29 = target_info_handle;
  if ( (pld_have_platform_driver_support(*(_QWORD *)(a1 + 30760)) & 1) == 0
    || ((v30 = (__int64 (__fastcall *)())hif_pci_get_soc_info_pld,
         v31 = hif_pci_deinit_pld,
         v32 = hif_enable_pci_pld,
         (unsigned int)(v28 - 4352) > 0x12)
     || ((1 << v28) & 0x6469F) == 0)
    && v28 != 62
    && v28 != 43981 )
  {
    v30 = hif_pci_get_soc_info_nopld;
    v31 = hif_pci_deinit_nopld;
    v32 = hif_enable_pci_nopld;
  }
  *(_QWORD *)(a1 + 31184) = v32;
  *(_QWORD *)(a1 + 31192) = v31;
  *(_QWORD *)(a1 + 31200) = v30;
  if ( *((_DWORD *)v30 - 1) != -1243203193 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64))v30)(a1, a2);
  v33 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 31184);
  if ( *((_DWORD *)v33 - 1) != -1620945365 )
    __break(0x8228u);
  v34 = v33(a1, a3, a4);
  if ( (v34 & 0x80000000) != 0 )
  {
    v81 = v34;
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: hif_enable_pci error = %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "hif_pci_enable_bus",
      v34);
    result = qdf_status_from_os_return(v81);
    goto LABEL_61;
  }
  qdf_trace_msg(0x3Du, 5u, "%s: hif_enable_pci done", v35, v36, v37, v38, v39, v40, v41, v42, "hif_pci_enable_bus");
  pld_pci_read_config_dword(*(_QWORD *)(a1 + 30768), 0x80u, v16 + 2504);
  pld_pci_write_config_dword(*(_QWORD *)(a1 + 30768), 0x80u, *(_DWORD *)(v16 + 2504) & 0xFFFFFF00);
  v43 = *(_WORD *)(a3 + 468);
  if ( (v43 & 8) == 0 )
    *(_WORD *)(a3 + 468) = v43 & 0xFFF5;
  pld_pci_read_config_word(a3, 8u, (__int64)&v123);
  if ( (hif_get_device_type(*(_DWORD *)(a4 + 4), v123, (int *)&v125, (int *)&v124) & 0x80000000) == 0 )
  {
    qdf_trace_msg(
      0x3Du,
      5u,
      "%s: hif_type = 0x%x, target_type = 0x%x",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "hif_pci_enable_bus",
      v125,
      v124);
    hif_register_tbl_attach(a1, v125);
    hif_target_register_tbl_attach(a1, v124);
    v52 = v124;
    if ( v124 <= 0x2B && ((1LL << v124) & 0xC2488C00000LL) != 0 )
    {
      *(_BYTE *)(v16 + 2417) = 1;
      *(_QWORD *)(a1 + 31104) = 0;
      *(_QWORD *)(v16 + 2420) = 0;
    }
    else
    {
      *(_BYTE *)(v16 + 2417) = 0;
    }
    *(_DWORD *)(v29 + 4) = v52;
    if ( v52 == 32 || v52 == 26 )
      *(_DWORD *)(a1 + 3984) = 1;
    if ( (ce_srng_based(a1) & 1) != 0 )
    {
      v61 = "%s: Skip tgt_wake up for srng devices";
LABEL_24:
      qdf_trace_msg(0x3Du, 5u, v61, v53, v54, v55, v56, v57, v58, v59, v60, "hif_pci_enable_bus");
      if ( *(_QWORD *)(a1 + 728) )
      {
        if ( (ce_srng_based(a1) & 1) != 0 )
        {
LABEL_60:
          result = 0;
          goto LABEL_61;
        }
        hif_write32_mb_reg_window(
          a1,
          *(_QWORD *)(a1 + 40)
        + (*(_DWORD *)(*(_QWORD *)(a1 + 616) + 296LL) | *(_DWORD *)(*(_QWORD *)(a1 + 616) + 272LL)),
          *(_DWORD *)(*(_QWORD *)(a1 + 616) + 308LL) | *(_DWORD *)(*(_QWORD *)(a1 + 616) + 304LL));
        hif_read32_mb_reg_window(
          a1,
          *(_QWORD *)(a1 + 40)
        + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 616) + 296LL) | *(_DWORD *)(*(_QWORD *)(a1 + 616) + 272LL)));
        hif_write32_mb_reg_window(
          a1,
          *(_QWORD *)(a1 + 40) + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 160LL) + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 168LL),
          *(_DWORD *)(*(_QWORD *)(a1 + 632) + 172LL));
        do
        {
          while ( (*(_BYTE *)(a1 + 648) & 1) != 0 )
            ;
        }
        while ( (*(_DWORD *)(*(_QWORD *)(a1 + 632) + 196LL)
               & ~((*(_DWORD *)(*(_QWORD *)(a1 + 632) + 176LL)
                  & (unsigned int)hif_read32_mb_reg_window(
                                    a1,
                                    *(_QWORD *)(a1 + 40)
                                  + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 160LL)
                                  + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 152LL))) >> *(_DWORD *)(*(_QWORD *)(a1 + 632) + 180LL))) != 0 );
        v70 = *(_DWORD *)(a1 + 20);
        qdf_trace_msg(
          0x3Du,
          5u,
          "%s: Loop checking FW signal",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "hif_target_sync");
        if ( (*(_DWORD *)(*(_QWORD *)(a1 + 632) + 188LL)
            & (unsigned int)hif_read32_mb_reg_window(
                              a1,
                              *(_QWORD *)(a1 + 40) + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 260LL))) != 0 )
        {
          v79 = 0;
LABEL_58:
          qdf_trace_msg(
            0x3Du,
            5u,
            "%s: Got FW signal, retries = %x",
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            "hif_target_sync",
            v79);
          goto LABEL_59;
        }
        v111 = 0;
        while ( 2 )
        {
          v112 = 500;
          do
          {
            if ( v112 < 0 )
              goto LABEL_53;
            --v112;
            hif_write32_mb_reg_window(
              a1,
              *(_QWORD *)(a1 + 40)
            + (*(_DWORD *)(*(_QWORD *)(a1 + 616) + 296LL) | *(_DWORD *)(*(_QWORD *)(a1 + 616) + 272LL)),
              *(_DWORD *)(*(_QWORD *)(a1 + 616) + 308LL) | *(_DWORD *)(*(_QWORD *)(a1 + 616) + 304LL));
            hif_read32_mb_reg_window(
              a1,
              *(_QWORD *)(a1 + 40)
            + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 616) + 296LL) | *(_DWORD *)(*(_QWORD *)(a1 + 616) + 272LL)));
            _const_udelay(4295000);
            _const_udelay(4295000);
            _const_udelay(4295000);
            _const_udelay(4295000);
            _const_udelay(4295000);
            _const_udelay(4295000);
            _const_udelay(4295000);
            _const_udelay(4295000);
            _const_udelay(4295000);
            _const_udelay(4295000);
          }
          while ( (*(_DWORD *)(*(_QWORD *)(a1 + 632) + 188LL)
                 & (unsigned int)hif_read32_mb_reg_window(
                                   a1,
                                   *(_QWORD *)(a1 + 40) + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 260LL))) == 0 );
          if ( v112 == -1 )
          {
LABEL_53:
            if ( v70 != 7 || v111 > 1 )
            {
              qdf_trace_msg(
                0x3Du,
                5u,
                "%s: FW signal timed out",
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                "hif_target_sync");
              v122 = printk(
                       &unk_AAA255,
                       "0",
                       "hif_target_sync",
                       "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/hif/src/pcie/if_pci.c");
              dump_stack(v122);
LABEL_59:
              hif_write32_mb_reg_window(
                a1,
                *(_QWORD *)(a1 + 40)
              + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 160LL)
              + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 168LL),
                *(_DWORD *)(*(_QWORD *)(a1 + 632) + 164LL));
              goto LABEL_60;
            }
            ++v111;
            v113 = hif_read32_mb_reg_window(
                     a1,
                     *(_QWORD *)(a1 + 40)
                   + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 616) + 748LL) + **(_DWORD **)(a1 + 616)));
            hif_write32_mb_reg_window(
              a1,
              *(_QWORD *)(a1 + 40) + *(_DWORD *)(*(_QWORD *)(a1 + 616) + 748LL) + **(_DWORD **)(a1 + 616),
              v113 | 1);
            qdf_trace_msg(
              0x3Du,
              5u,
              "%s: Loop checking FW signal",
              v114,
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              v121,
              "hif_target_sync");
            if ( (*(_DWORD *)(*(_QWORD *)(a1 + 632) + 188LL)
                & (unsigned int)hif_read32_mb_reg_window(
                                  a1,
                                  *(_QWORD *)(a1 + 40) + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 260LL))) == 0 )
              continue;
            v112 = 500;
          }
          break;
        }
        v79 = (unsigned int)(500 - v112);
        goto LABEL_58;
      }
      v82 = "%s: BAR0 uninitialized";
      goto LABEL_40;
    }
    hif_write32_mb_reg_window(
      a1,
      *(_QWORD *)(a1 + 30720) + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 160LL) + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 168LL),
      *(_DWORD *)(*(_QWORD *)(a1 + 632) + 172LL));
    v83 = -500;
    v84 = "%s: target awake timeout";
    if ( (*(_BYTE *)(a1 + 648) & 1) != 0 )
      goto LABEL_36;
LABEL_35:
    if ( (*(_DWORD *)(*(_QWORD *)(a1 + 632) + 196LL)
        & ~((*(_DWORD *)(*(_QWORD *)(a1 + 632) + 176LL)
           & (unsigned int)hif_read32_mb_reg_window(
                             a1,
                             *(_QWORD *)(a1 + 30720)
                           + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 160LL)
                           + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 152LL))) >> *(_DWORD *)(*(_QWORD *)(a1 + 632)
                                                                                             + 180LL))) != 0 )
    {
LABEL_36:
      while ( v83 )
      {
        _const_udelay(4295000);
        ++v83;
        if ( (*(_BYTE *)(a1 + 648) & 1) == 0 )
          goto LABEL_35;
      }
    }
    else
    {
      v93 = hif_read32_mb_reg_window(a1, *(_QWORD *)(a1 + 30720) + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 260LL));
      hif_write32_mb_reg_window(
        a1,
        *(_QWORD *)(a1 + 30720)
      + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 160LL)
      + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 168LL),
        *(_DWORD *)(*(_QWORD *)(a1 + 632) + 164LL));
      if ( (*(_DWORD *)(*(_QWORD *)(a1 + 632) + 188LL) & v93) == 0 )
      {
        v61 = "%s: hif_pci_probe_tgt_wakeup done";
        goto LABEL_24;
      }
      v84 = "%s: Target is in an unknown state. EAGAIN";
    }
    qdf_trace_msg(0x3Du, 2u, v84, v53, v54, v55, v56, v57, v58, v59, v60, "hif_pci_probe_tgt_wakeup");
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: hif_pci_prob_wakeup error = %d",
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      "hif_pci_enable_bus",
      4294967285LL);
    goto LABEL_44;
  }
  v82 = "%s: Invalid device id/revision_id";
LABEL_40:
  qdf_trace_msg(0x3Du, 2u, v82, v44, v45, v46, v47, v48, v49, v50, v51, "hif_pci_enable_bus");
LABEL_44:
  hif_pci_device_reset(a1, v85, v86, v87, v88, v89, v90, v91, v92);
  v102 = *(void (__fastcall **)(_QWORD))(a1 + 31192);
  if ( *((_DWORD *)v102 - 1) != -37903589 )
    __break(0x8228u);
  v102(a1);
  *(_QWORD *)(a1 + 30720) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  *(_BYTE *)(v16 + 2416) = 0;
  qdf_trace_msg(
    0x3Du,
    2u,
    "%s: hif_disable_pci done",
    v103,
    v104,
    v105,
    v106,
    v107,
    v108,
    v109,
    v110,
    "hif_pci_enable_bus");
  result = 10;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
