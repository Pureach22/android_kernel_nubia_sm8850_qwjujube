__int64 __fastcall cam_hw_cdm_submit_gen_irq(__int64 a1, int *a2, unsigned int a3)
{
  __int64 v3; // x27
  __int64 v4; // x25
  unsigned int v5; // w26
  __int64 v7; // x20
  __int64 v8; // x23
  __int64 result; // x0
  __int64 (*v11)(void); // x8
  int v12; // w24
  int v13; // w0
  __int64 v14; // x28
  __int64 v15; // x0
  __int64 v16; // x8
  bool v17; // zf
  int v18; // w20
  __int64 v19; // x21
  __int64 v20; // x2
  int v21; // w8
  _QWORD *v22; // x22
  __int64 v23; // x8
  __int64 v24; // x8
  int v25; // w20
  _QWORD *v26; // x1
  _DWORD *v27; // x9
  __int64 v28; // x0
  __int64 v29; // x0
  const char *v30; // x5
  __int64 v31; // x4
  __int64 v32; // x6
  unsigned int v33; // w0
  unsigned int v34; // w20
  unsigned int v35; // w19
  _QWORD *v36; // x8
  __int64 v37; // x9
  const char *v38; // x9
  unsigned int *v39; // x8
  __int64 v41; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v42[2]; // [xsp+30h] [xbp-10h] BYREF

  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 3680);
  v42[0] = 0;
  v4 = *((_QWORD *)a2 + 1);
  v5 = **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL);
  v41 = 0;
  if ( a3 >= 4 )
    __break(0x5512u);
  v7 = v3 + 640LL * a3;
  v8 = *(unsigned __int8 *)(v7 + 2400);
  if ( *(_DWORD *)(v7 + 2404) - 1 < (unsigned int)v8 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_submit_gen_irq",
      864,
      "Invalid BL Tag: %u, BL Depth: %d, Fifo_idx: %d",
      *(unsigned __int8 *)(v7 + 2400));
    result = 4294967274LL;
    goto LABEL_49;
  }
  v11 = *(__int64 (**)(void))(*(_QWORD *)(v3 + 240) + 40LL);
  if ( *((_DWORD *)v11 - 1) != -605791253 )
    __break(0x8228u);
  v12 = v11();
  v13 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD *, __int64 *, _QWORD, _QWORD))cam_mem_get_io_buf)(
          **(unsigned int **)(v4 + 24),
          *(unsigned int *)(v3 + 224),
          v42,
          &v41,
          0,
          0);
  if ( v13 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_submit_gen_irq",
      873,
      "Getting a hwva from mem_hdl failed. rc: %d",
      v13);
    result = 4294967274LL;
    goto LABEL_49;
  }
  v14 = v7 + 2296;
  v15 = raw_spin_lock_irqsave(v7 + 2928);
  v16 = *(_QWORD *)(v4 + 40);
  v17 = (unsigned int)v8 >= 0x40 || v16 == 0;
  v18 = !v17;
  if ( !v17 )
    *(_QWORD *)(v14 + 8 * v8 + 120) = v16;
  raw_spin_unlock_irqrestore(v14 + 632, v15);
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    v38 = "N";
    if ( v18 )
      v38 = "Y";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_submit_gen_irq",
      891,
      "Last Tag: %u, Total BLs: %d, Cookie: %d, Fast callback enabled: %s",
      v8,
      *(_DWORD *)(v4 + 20),
      *(_QWORD *)(v4 + 32),
      v38);
  }
  if ( mem_trace_en != 1 )
  {
    v19 = _kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
    if ( v19 )
      goto LABEL_20;
LABEL_29:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_submit_gen_irq",
      895,
      "Failed while getting memory for the Node");
    result = 4294967284LL;
    goto LABEL_49;
  }
  v19 = cam_mem_trace_alloc(56, 0xCC0u, 0, "cam_hw_cdm_submit_gen_irq", 0x37Du);
  if ( !v19 )
    goto LABEL_29;
LABEL_20:
  v20 = v14 + 40;
  *(_DWORD *)(v19 + 4) = 1;
  v21 = *a2;
  v22 = (_QWORD *)(v19 + 32);
  *(_DWORD *)(v19 + 8) = v21;
  v23 = *(_QWORD *)(v4 + 32);
  *(_BYTE *)v19 = v8;
  *(_DWORD *)(v19 + 24) = v23;
  v24 = *(_QWORD *)(v4 + 8);
  *(_BYTE *)(v19 + 48) = v18;
  v25 = 4 * v12;
  *(_QWORD *)(v19 + 16) = v24;
  v26 = *(_QWORD **)(v14 + 48);
  if ( v19 + 32 == v14 + 40 || v26 == v22 || *v26 != v20 )
  {
    _list_add_valid_or_report(v19 + 32);
  }
  else
  {
    *(_QWORD *)(v14 + 48) = v22;
    *(_QWORD *)(v19 + 32) = v20;
    *(_QWORD *)(v19 + 40) = v26;
    *v26 = v22;
  }
  v27 = *(_DWORD **)(*(_QWORD *)(v3 + 240) + 136LL);
  v28 = *(_QWORD *)(*(_QWORD *)(v4 + 24) + 8LL) + (*(_DWORD *)(*(_QWORD *)(v4 + 24) + 24LL) & 0xFFFFFFFC);
  if ( *(v27 - 1) != 1079251131 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, _QWORD, bool, _QWORD))v27)(v28, (unsigned int)v8, v5 > 1, a3);
  v29 = cam_hw_cdm_bl_write(
          a1,
          *(_DWORD *)(*(_QWORD *)(v4 + 24) + 16LL) + LODWORD(v42[0]),
          v25 - 1,
          v8,
          *(_BYTE *)(v4 + 1),
          a3);
  if ( (v29 & 1) != 0 )
  {
    v30 = "CDM hw bl write failed for gen irq bl_tag = %u";
    v31 = 913;
    v32 = (unsigned int)v8;
  }
  else
  {
    if ( (debug_mdl & 1) != 0 && !debug_priority )
    {
      v39 = (unsigned int *)(*(_QWORD *)(*(_QWORD *)(v4 + 24) + 8LL)
                           + (*(_DWORD *)(*(_QWORD *)(v4 + 24) + 24LL) & 0xFFFFFFFC));
      v29 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              1,
              4,
              "cam_hw_cdm_submit_gen_irq",
              920,
              "GenIRQ BL: First Word: 0x%llx Second Word: 0x%llx",
              *v39,
              v39[1]);
    }
    *(_DWORD *)(*(_QWORD *)(v4 + 24) + 24LL) += v25;
    *(_DWORD *)(*(_QWORD *)(v4 + 24) + 16LL) += v25;
    if ( (cam_presil_mode_enabled(v29) & 1) != 0 )
    {
      if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x8000000,
          4,
          "cam_hw_cdm_submit_gen_irq",
          928,
          "Sending CDM gen irq cmd buffer:%d with iommu_hdl:%d",
          **(_DWORD **)(v4 + 24),
          *(_DWORD *)(v3 + 224));
      v33 = cam_mem_mgr_send_buffer_to_presil();
      if ( v33 )
      {
        v34 = v33;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000000,
          1,
          "cam_hw_cdm_submit_gen_irq",
          935,
          "Failed to send CDM gen irq cmd buffer fifo_idx:%d mem_handle:%d rc:%d",
          a3,
          **(_DWORD **)(v4 + 24),
          v33);
        v35 = v34;
        goto LABEL_42;
      }
    }
    if ( !cam_cdm_write_hw_reg(
            a1,
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 3680) + 232LL) + 8LL * a3 + 8) + 8LL),
            1u) )
    {
      result = 0;
      goto LABEL_49;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_commit_bl_write",
      840,
      "Failed to write CDM commit BL");
    v32 = *(unsigned __int8 *)(v14 + 104);
    v30 = "Cannot commit the genirq BL with Tag: %u";
    v31 = 943;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    1,
    1,
    "cam_hw_cdm_submit_gen_irq",
    v31,
    v30,
    v32);
  v35 = -5;
LABEL_42:
  v36 = *(_QWORD **)(v19 + 40);
  if ( (_QWORD *)*v36 == v22 && (v37 = *v22, *(_QWORD **)(*v22 + 8LL) == v22) )
  {
    *(_QWORD *)(v37 + 8) = v36;
    *v36 = v37;
  }
  else
  {
    _list_del_entry_valid_or_report(v19 + 32);
  }
  *(_QWORD *)(v19 + 32) = v19 + 32;
  *(_QWORD *)(v19 + 40) = v22;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v19, 0);
  else
    kvfree(v19);
  result = v35;
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
