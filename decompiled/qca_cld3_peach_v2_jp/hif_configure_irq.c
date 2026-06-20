__int64 __fastcall hif_configure_irq(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x25
  unsigned int v11; // w20
  char v12; // w8
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int msi_irq; // w0
  __int64 v23; // x9
  __int64 v24; // x21
  char v25; // w0
  void *v26; // x9
  void *v27; // x10
  unsigned int v28; // w8
  __int64 v29; // x22
  unsigned __int64 v30; // x20
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned __int64 v48; // x21
  __int64 v49; // x0
  __int64 v50; // d0
  __int64 v51; // d6
  _DWORD *v52; // x10
  __int64 v53; // x13
  int v54; // w8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v64; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v65; // [xsp+10h] [xbp-10h] BYREF
  int v66; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v67; // [xsp+18h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x3Du, 5u, "%s: E", a2, a3, a4, a5, a6, a7, a8, a9, "hif_configure_irq");
  if ( (hif_is_polled_mode_enabled(a1) & 1) == 0 )
  {
    *(_QWORD *)(a1 + 31160) = reschedule_tasklet_work_handler;
    *(_QWORD *)(a1 + 31128) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 31168) = 0;
    *(_QWORD *)(a1 + 31136) = a1 + 31136;
    *(_QWORD *)(a1 + 31144) = a1 + 31136;
    *(_QWORD *)(a1 + 31152) = _qdf_defer_func;
    v12 = *(_BYTE *)(a1 + 3951);
    v13 = *(_QWORD *)(a1 + 27400);
    v66 = 0;
    v64 = 0;
    v65 = 0;
    if ( (v12 & 1) == 0 )
    {
      if ( (unsigned int)pld_get_user_msi_assignment(
                           *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL),
                           (__int64)"WAKE",
                           (__int64)&v65,
                           (__int64)&v66,
                           (__int64)&v64) )
        goto LABEL_9;
      msi_irq = pld_get_msi_irq(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), v64);
      v23 = *(_QWORD *)(a1 + 576);
      *(_DWORD *)(a1 + 2572) = msi_irq;
      *(_DWORD *)(a1 + 2576) = 1;
      if ( (unsigned int)pld_srng_request_irq(
                           *(_QWORD *)(v23 + 40),
                           msi_irq,
                           (__int64)hif_wake_interrupt_handler,
                           0x4000,
                           (__int64)"wlan_wake_irq",
                           a1) )
        goto LABEL_9;
    }
    if ( (unsigned int)pld_get_user_msi_assignment(
                         *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL),
                         (__int64)"CE",
                         (__int64)&v65,
                         (__int64)&v66,
                         (__int64)&v64) )
      goto LABEL_5;
    v25 = ce_srng_based(a1);
    v26 = &hif_ce_srng_msi_irq_disable;
    v27 = &hif_ce_legacy_msi_irq_enable;
    if ( (v25 & 1) != 0 )
      v27 = &hif_ce_srng_msi_irq_enable;
    else
      v26 = &hif_ce_legacy_msi_irq_disable;
    v28 = *(_DWORD *)(a1 + 656);
    *(_QWORD *)(a1 + 256) = v26;
    *(_QWORD *)(a1 + 264) = v27;
    *(_QWORD *)(a1 + 384) = hif_ce_msi_map_ce_to_irq;
    if ( !v28 )
      goto LABEL_36;
    v29 = 0;
    v30 = 0;
    while ( 1 )
    {
      if ( (*(_BYTE *)(v13 + (v29 >> 27)) & 0x48) == 0 )
      {
        if ( (unsigned int)hif_ce_msi_configure_irq_by_ceid(a1, (unsigned int)v30) )
        {
          if ( (int)v30 >= 1 )
          {
            v48 = v30 - 1;
            while ( v48 + 1 < *(unsigned int *)(a1 + 656) )
            {
              v49 = pld_get_msi_irq(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), v64 + (unsigned int)v48 % v65);
              if ( v30 >= 0xE )
              {
                __break(0x5512u);
                *(_QWORD *)(v9 + 392) = v51;
                *(_QWORD *)(v9 + 400) = v50;
                return hif_pci_close(v49);
              }
              pld_srng_free_irq(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), v49, a1 + 26448 + 56LL * (unsigned int)v48--);
              if ( v48 >= 0xFFFFFFFFFFFFFFFELL )
                break;
            }
          }
LABEL_5:
          if ( (*(_BYTE *)(a1 + 3951) & 1) == 0 )
          {
            pld_srng_free_irq(
              *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL),
              *(_DWORD *)(a1 + 2572),
              *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL));
            *(_QWORD *)(a1 + 2572) = 0;
          }
LABEL_9:
          v24 = *(unsigned int *)(a1 + 20);
          if ( (unsigned int)v24 > 0x29 )
            goto LABEL_23;
          if ( ((1LL << v24) & 0x21A23100000LL) != 0 )
          {
            v11 = -22;
            goto LABEL_12;
          }
          if ( v24 != 32 )
          {
LABEL_23:
            qdf_trace_msg(0x3Du, 5u, "%s: E", v14, v15, v16, v17, v18, v19, v20, v21, "hif_pci_configure_legacy_irq");
            tasklet_init(a1 + 30784, wlan_tasklet, a1);
            v31 = request_threaded_irq(
                    *(unsigned int *)(*(_QWORD *)(a1 + 30768) + 1116LL),
                    hif_pci_legacy_ce_interrupt_handler,
                    0,
                    2097280,
                    "wlan_pci",
                    a1);
            if ( v31 )
            {
              v11 = v31;
              qdf_trace_msg(
                0x3Du,
                2u,
                "%s: request_irq failed, ret: %d",
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                "hif_pci_configure_legacy_irq",
                v31);
              qdf_trace_msg(
                0x3Du,
                2u,
                "%s: X, ret = %d",
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                "hif_pci_configure_legacy_irq",
                v11);
              if ( (v11 & 0x80000000) != 0 )
              {
LABEL_12:
                qdf_trace_msg(
                  0x3Du,
                  2u,
                  "%s: error = %d",
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  "hif_configure_irq",
                  v11);
                goto LABEL_37;
              }
            }
            else
            {
              v52 = *(_DWORD **)(a1 + 616);
              v53 = *(_QWORD *)(a1 + 30720);
              v54 = *(_DWORD *)(*(_QWORD *)(a1 + 30768) + 1116LL);
              *(_DWORD *)(a1 + 30896) = v54;
              *(_DWORD *)(a1 + 2572) = v54;
              hif_write32_mb_reg_window(a1, v53 + (v52[74] | v52[68]), v52[77] | v52[76] | v52[221]);
              hif_read32_mb_reg_window(
                a1,
                *(_QWORD *)(a1 + 30720)
              + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 616) + 296LL) | *(_DWORD *)(*(_QWORD *)(a1 + 616) + 272LL)));
              hif_write32_mb_reg_window(
                a1,
                *(_QWORD *)(a1 + 30720)
              + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 160LL)
              + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 168LL),
                *(_DWORD *)(*(_QWORD *)(a1 + 632) + 164LL));
              if ( (unsigned int)v24 <= 0x11 && ((1 << v24) & 0x2BA80) != 0 )
                hif_write32_mb_reg_window(
                  a1,
                  *(_QWORD *)(a1 + 40)
                + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 160LL)
                + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 168LL),
                  *(_DWORD *)(*(_QWORD *)(a1 + 632) + 172LL));
              qdf_trace_msg(
                0x3Du,
                2u,
                "%s: X, ret = %d",
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                v62,
                "hif_pci_configure_legacy_irq",
                0);
            }
          }
LABEL_36:
          v11 = 0;
          *(_BYTE *)(a1 + 585) = 1;
          goto LABEL_37;
        }
        v28 = *(_DWORD *)(a1 + 656);
      }
      ++v30;
      v29 += 0x100000000LL;
      if ( v28 <= (unsigned int)v30 )
        goto LABEL_36;
    }
  }
  v11 = 0;
  *(_BYTE *)(a1 + 585) = 0;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return v11;
}
