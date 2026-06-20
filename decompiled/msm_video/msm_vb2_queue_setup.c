__int64 __fastcall msm_vb2_queue_setup(__int64 a1, unsigned int *a2, unsigned int *a3, unsigned int *a4)
{
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v10; // x19
  __int64 v11; // x4
  void *v12; // x0
  __int64 result; // x0
  unsigned int v14; // w0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x4
  unsigned int v19; // w22
  int v20; // w8
  __int64 v21; // x4
  unsigned int v22; // w20
  __int64 v23; // x4
  __int64 v24; // x9
  unsigned int v25; // w0
  unsigned int v26; // w23
  unsigned int v27; // w20
  const char *v28; // x4
  void *v29; // x0
  __int64 buffers; // x0
  __int64 v31; // x8
  _DWORD *v32; // x24
  unsigned int *v33; // x9
  _DWORD *v34; // x10
  __int64 v35; // x12
  _DWORD *v36; // x11
  _DWORD *v37; // x12
  int v38; // w0
  unsigned int v39; // w8
  unsigned int v40; // w12
  __int64 v41; // x8
  _DWORD *v42; // x8
  int v43; // w0
  __int64 v44; // x8
  __int64 v45; // x8
  _DWORD *v46; // x8
  unsigned int v47; // w1
  unsigned __int64 context_bank_for_region; // x0
  char v49; // w8
  const char *v50; // x0

  if ( !a1 || !a2 || !a3 || !a4 || (v4 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_82632, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_queue_setup");
    return 4294967274LL;
  }
  v5 = *(_QWORD *)(v4 + 320);
  if ( !v5 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83566, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_queue_setup");
    return 4294967274LL;
  }
  v10 = v4 + 340;
  if ( is_state(*(_QWORD *)(a1 + 72), 3) )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v11 = *(unsigned int *)(v4 + 160);
    v12 = &unk_8F3DF;
LABEL_10:
    printk(v12, "err ", v4 + 340, "msm_vb2_queue_setup", v11);
    return 4294967274LL;
  }
  v14 = v4l2_type_to_driver_port(v4, *(_DWORD *)a1, (__int64)"msm_vb2_queue_setup");
  if ( (v14 & 0x80000000) != 0 )
    return 4294967274LL;
  v19 = v14;
  if ( (*(_BYTE *)(v4 + 4107) & 1) == 0 )
  {
    result = msm_vidc_prepare_dependency_list(v4, v15, v16, v17, v18);
    if ( (_DWORD)result )
      return result;
    *(_BYTE *)(v4 + 4107) = 1;
  }
  v20 = *(_DWORD *)(v4 + 308);
  if ( v19 == 1 && v20 == 1 || !v19 && v20 == 2 )
  {
    result = msm_vidc_adjust_v4l2_properties(v4, v15, v16, v17, v18);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v22 = result;
        printk(&unk_850FB, "err ", v10, "msm_vb2_queue_setup", v21);
        return v22;
      }
      return result;
    }
  }
  if ( v19 <= 1 )
  {
    v23 = *a3;
    if ( (_DWORD)v23 )
    {
      v24 = v4 + 208LL * v19;
      if ( (_DWORD)v23 != *(unsigned __int8 *)(v24 + 572) )
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_85131, "err ", v4 + 340, "msm_vb2_queue_setup", v23);
        return 4294967274LL;
      }
      v11 = *a4;
      if ( (unsigned int)v11 < *(_DWORD *)(v24 + 412) )
      {
        if ( (msm_vidc_debug & 1) == 0 )
          return 4294967274LL;
        v12 = &unk_879AC;
        goto LABEL_10;
      }
    }
  }
  v25 = v4l2_type_to_driver(*(_DWORD *)a1, (__int64)"msm_vb2_queue_setup");
  if ( !v25 )
    return 4294967274LL;
  v26 = v25;
  result = msm_vidc_free_buffers(v4, v25);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return result;
    v27 = result;
    v28 = v4l2_type_name(*(_DWORD *)a1);
    v29 = &unk_95B10;
    goto LABEL_38;
  }
  buffers = msm_vidc_get_buffers(v4, v26, (__int64)"msm_vb2_queue_setup");
  if ( !buffers )
    return 4294967274LL;
  v31 = *(_QWORD *)(v5 + 6560);
  v32 = (_DWORD *)buffers;
  if ( v31 )
  {
    v31 = *(_QWORD *)(v31 + 56);
    if ( v31 )
    {
      if ( *(_DWORD *)(v31 - 4) != 1958436756 )
        __break(0x8228u);
      LODWORD(v31) = ((__int64 (__fastcall *)(__int64, _QWORD))v31)(v4, v26);
    }
  }
  v32[4] = v31;
  v33 = a2;
  v34 = a4;
  v35 = *(_QWORD *)(v5 + 6560);
  v36 = a3;
  if ( v35 && (v37 = *(_DWORD **)(v35 + 64)) != nullptr )
  {
    if ( *(v37 - 1) != 1958436756 )
      __break(0x822Cu);
    v38 = ((__int64 (__fastcall *)(__int64, _QWORD))v37)(v4, v26);
    LODWORD(v31) = v32[4];
    v36 = a3;
    v34 = a4;
    v33 = a2;
  }
  else
  {
    v38 = 0;
  }
  v32[5] = v38;
  v39 = v31 + v38;
  v40 = *v33;
  if ( *v33 < v39 )
  {
    v40 = v39;
    *v33 = v39;
  }
  v32[6] = v40;
  *v36 = 1;
  v41 = *(_QWORD *)(v5 + 6560);
  if ( v41 && (v42 = *(_DWORD **)(v41 + 48)) != nullptr )
  {
    if ( *(v42 - 1) != 1958436756 )
      __break(0x8228u);
    v43 = ((__int64 (__fastcall *)(__int64, _QWORD))v42)(v4, v26);
    v34 = a4;
    v33 = a2;
  }
  else
  {
    v43 = 0;
  }
  v32[7] = v43;
  if ( v19 > 1 )
  {
    if ( v19 == 2 )
    {
      v44 = *(_QWORD *)(v4 + 23336);
      *(_DWORD *)(v4 + 812) = v43;
      if ( v44 )
        v43 *= (_DWORD)v44;
    }
    else
    {
      if ( v19 != 3 )
        goto LABEL_69;
      *(_DWORD *)(v4 + 1020) = v43;
    }
  }
  else
  {
    *(_DWORD *)(v4 + 208LL * v19 + 412) = v43;
  }
  *v34 = v43;
LABEL_69:
  result = msm_vidc_allocate_buffers(v4, v26, *v33);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return result;
    v27 = result;
    v28 = v4l2_type_name(*(_DWORD *)a1);
    v29 = &unk_8DBE0;
LABEL_38:
    printk(v29, "err ", v10, "msm_vb2_queue_setup", v28);
    return v27;
  }
  v45 = *(_QWORD *)(v5 + 6568);
  if ( v45 && (v46 = *(_DWORD **)(v45 + 88)) != nullptr )
  {
    if ( *(v46 - 1) != 1120471144 )
      __break(0x8228u);
    v47 = ((__int64 (__fastcall *)(__int64, _QWORD))v46)(v4, v26);
  }
  else
  {
    v47 = 0;
  }
  context_bank_for_region = msm_vidc_get_context_bank_for_region(v5, v47);
  if ( context_bank_for_region )
  {
    v49 = msm_vidc_debug;
    *(_QWORD *)(a1 + 8) = *(_QWORD *)(context_bank_for_region + 24);
    if ( (v49 & 2) != 0 )
    {
      v50 = v4l2_type_name(*(_DWORD *)a1);
      printk(&unk_81861, "high", v10, v50, *a2);
    }
    return 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8B6CC, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_queue_setup");
    return 4294967291LL;
  }
}
