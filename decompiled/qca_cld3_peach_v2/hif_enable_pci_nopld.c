__int64 __fastcall hif_enable_pci_nopld(__int64 a1, __int64 a2, __int64 a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w20
  unsigned int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x2
  unsigned int v43; // w0
  __int64 v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x21
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // w8
  __int64 v63; // x8
  unsigned __int16 v64; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v65; // [xsp+8h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64 = 0;
  pci_read_config_word(a2, 2, &v64);
  if ( *(_DWORD *)(a3 + 4) != v64 )
  {
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: dev id mismatch, config id = 0x%x, probing id = 0x%x",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hif_enable_pci_nopld");
LABEL_8:
    result = 4294967291LL;
    goto LABEL_9;
  }
  if ( (unsigned int)pci_assign_resource(a2, 0) )
  {
    v22 = "%s: pci_assign_resource error";
LABEL_7:
    qdf_trace_msg(0x3Du, 2u, v22, v14, v15, v16, v17, v18, v19, v20, v21, "hif_enable_pci_nopld");
    goto LABEL_8;
  }
  if ( (unsigned int)pci_enable_device(a2) )
  {
    v22 = "%s: pci_enable_device error";
    goto LABEL_7;
  }
  if ( (unsigned int)pci_request_region(a2, 0, "ath") )
  {
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: PCI MMIO reservation error",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "hif_enable_pci_nopld");
    v32 = -5;
LABEL_18:
    pci_disable_device(a2);
    result = v32;
    goto LABEL_9;
  }
  v33 = dma_set_mask(a2 + 200, 0xFFFFFFFFLL);
  if ( v33 )
  {
    v32 = v33;
    v42 = "%s: Cannot enable 32-bit pci DMA";
LABEL_16:
    qdf_trace_msg(0x3Du, 2u, v42, v34, v35, v36, v37, v38, v39, v40, v41, "hif_enable_pci_nopld");
LABEL_17:
    pci_release_region(a2, 0);
    goto LABEL_18;
  }
  v43 = dma_set_coherent_mask(a2 + 200, 0xFFFFFFFFLL);
  if ( v43 )
  {
    v32 = v43;
    v42 = "%s: Cannot enable 32-bit coherent DMA!";
    goto LABEL_16;
  }
  pci_set_master(a2);
  v44 = pci_iomap(a2, 0, 0);
  if ( !v44 )
  {
    qdf_trace_msg(0x3Du, 2u, "%s: PCI iomap error", v45, v46, v47, v48, v49, v50, v51, v52, "hif_enable_pci_nopld");
    pci_clear_master(a2);
    v32 = -5;
    goto LABEL_17;
  }
  v53 = v44;
  qdf_trace_msg(0x3Du, 5u, "%s: *****BAR is %pK", v45, v46, v47, v48, v49, v50, v51, v52, "hif_enable_pci_nopld", v44);
  v62 = v64;
  *(_QWORD *)(a1 + 30720) = v53;
  if ( (unsigned int)(v62 - 43968) < 4 || (unsigned int)(v62 - 43536) <= 1 )
  {
    v53 += 201326592;
    *(_QWORD *)(a1 + 30720) = v53;
    qdf_trace_msg(
      0x3Du,
      5u,
      "%s: Changing PCI mem base to %pK",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "hif_enable_pci_nopld",
      v53);
  }
  v63 = *(_QWORD *)(a2 + 1128);
  if ( v63 )
    v63 = v63 - *(_QWORD *)(a2 + 1120) + 1;
  *(_QWORD *)(a1 + 30752) = v63;
  result = 0;
  *(_QWORD *)(a1 + 40) = v53;
  *(_QWORD *)(a1 + 728) = *(_QWORD *)(a2 + 1120);
  *(_BYTE *)(a1 + 31088) = 1;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
