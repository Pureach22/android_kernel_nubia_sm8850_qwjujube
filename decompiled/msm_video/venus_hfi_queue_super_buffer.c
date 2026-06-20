__int64 __fastcall venus_hfi_queue_super_buffer(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 v6; // x20
  __int64 v7; // x4
  _QWORD *v8; // x8
  _QWORD *v9; // x9
  void *v10; // x0
  unsigned int hfi_buffer; // w26
  int v12; // w23
  __int64 v13; // x8
  __int64 (__fastcall *v14)(__int64, __int64); // x9
  unsigned int v15; // w0
  unsigned int v16; // w24
  __int64 v17; // x4
  __int64 v18; // x8
  void *v19; // x0
  __int64 v20; // x2
  __int64 *v21; // x9
  int v22; // w25
  int v23; // w3
  __int64 v24; // x0
  unsigned int v25; // w1
  int v26; // w2
  unsigned int header; // w0
  unsigned int v28; // w1
  unsigned int *v29; // x26
  unsigned int v30; // w27
  __int64 v31; // x28
  int v32; // w10
  int hfi_port_from_buffer_type; // w0
  int v34; // w6
  unsigned int v35; // w1
  unsigned int *v36; // x26
  unsigned int v37; // w27
  int v38; // w10
  int v39; // w0
  int v40; // w6
  __int64 v41; // x27
  __int64 v42; // x28
  __int64 v43; // x1
  __int64 v44; // x2
  __int64 v45; // x3
  __int64 v46; // x4
  unsigned int (__fastcall *v47)(__int64, __int64); // x8
  int v49; // [xsp+Ch] [xbp-94h]
  __int64 v50; // [xsp+10h] [xbp-90h]
  _QWORD v51[2]; // [xsp+18h] [xbp-88h] BYREF
  __int64 v52; // [xsp+28h] [xbp-78h] BYREF
  __int64 v53; // [xsp+30h] [xbp-70h]
  unsigned __int64 v54; // [xsp+38h] [xbp-68h]
  __int64 v55; // [xsp+40h] [xbp-60h]
  __int64 v56; // [xsp+48h] [xbp-58h]
  __int64 v57; // [xsp+50h] [xbp-50h]
  _QWORD v58[2]; // [xsp+58h] [xbp-48h] BYREF
  __int64 v59; // [xsp+68h] [xbp-38h] BYREF
  __int64 v60; // [xsp+70h] [xbp-30h]
  unsigned __int64 v61; // [xsp+78h] [xbp-28h]
  __int64 v62; // [xsp+80h] [xbp-20h]
  __int64 v63; // [xsp+88h] [xbp-18h]
  __int64 v64; // [xsp+90h] [xbp-10h]
  __int64 v65; // [xsp+98h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 320);
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v58[0] = 0;
  v58[1] = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v51[0] = 0;
  v51[1] = 0;
  core_lock(v6);
  if ( !*(_QWORD *)(a1 + 368) )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_66;
    v10 = &unk_8DDBA;
    goto LABEL_13;
  }
  if ( (mutex_is_locked(v6 + 3856) & 1) == 0 )
  {
    __break(0x800u);
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_94E60, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_queue_super_buffer");
    goto LABEL_66;
  }
  v8 = (_QWORD *)(v6 + 3528);
  v9 = (_QWORD *)(v6 + 3528);
  do
    v9 = (_QWORD *)*v9;
  while ( v9 != (_QWORD *)a1 && v9 != v8 );
  if ( a1 && v9 == v8 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
    {
LABEL_66:
      hfi_buffer = -22;
      goto LABEL_67;
    }
    v10 = &unk_89648;
LABEL_13:
    printk(v10, "err ", a1 + 340, "venus_hfi_queue_super_buffer", v7);
    goto LABEL_66;
  }
  if ( v9 == v8 )
    goto LABEL_66;
  hfi_buffer = get_hfi_buffer(a1, (__int64)a2, (__int64)v58);
  if ( hfi_buffer )
    goto LABEL_67;
  if ( a3 )
  {
    hfi_buffer = get_hfi_buffer(a1, a3, (__int64)v51);
    if ( hfi_buffer )
      goto LABEL_67;
  }
  v12 = *(_DWORD *)(a1 + 23336);
  if ( v6 && (v13 = *(_QWORD *)(v6 + 6560)) != 0 )
  {
    v14 = *(__int64 (__fastcall **)(__int64, __int64))(v13 + 48);
    if ( v14 )
    {
      if ( *((_DWORD *)v14 - 1) != 1958436756 )
        __break(0x8229u);
      v15 = v14(a1, 1);
      v13 = *(_QWORD *)(v6 + 6560);
      v16 = v15;
      if ( !v13 )
        goto LABEL_26;
    }
    else
    {
      v16 = 0;
    }
    v47 = *(unsigned int (__fastcall **)(__int64, __int64))(v13 + 48);
    if ( v47 )
    {
      if ( *((_DWORD *)v47 - 1) != 1958436756 )
        __break(0x8228u);
      v17 = v47(a1, 3);
      goto LABEL_27;
    }
  }
  else
  {
    v16 = 0;
  }
LABEL_26:
  v17 = 0;
LABEL_27:
  if ( v16 * v12 != a2[10] )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_57;
    v19 = &unk_97C3A;
    v20 = a1 + 340;
    v17 = v16;
LABEL_36:
    printk(v19, "err ", v20, "venus_hfi_queue_super_buffer", v17);
LABEL_57:
    hfi_buffer = 0;
    goto LABEL_67;
  }
  v18 = *(_QWORD *)(a1 + 19472);
  if ( a3 )
  {
    if ( (unsigned int)(v17 * v12) > *(_DWORD *)(a3 + 40) )
    {
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        goto LABEL_57;
      v19 = &unk_85EBC;
      v20 = a1 + 340;
      goto LABEL_36;
    }
    HIDWORD(v60) = v16;
    v21 = &v52;
    LODWORD(v59) = 0;
    HIDWORD(v53) = v17;
  }
  else
  {
    HIDWORD(v60) = v16;
    v21 = &v59;
  }
  *(_DWORD *)v21 = 0;
  if ( !v12 )
    goto LABEL_57;
  v22 = 0;
  v49 = v17;
  v50 = 1000000 / (v18 >> 16);
  while ( 1 )
  {
    v23 = *(_DWORD *)(v6 + 6600);
    v24 = *(_QWORD *)(a1 + 368);
    v25 = *(_DWORD *)(a1 + 376);
    v26 = *(_DWORD *)(a1 + 332);
    *(_DWORD *)(v6 + 6600) = v23 + 1;
    header = hfi_create_header(v24, v25, v26, v23);
    if ( header )
      break;
    v28 = a2[6];
    v29 = *(unsigned int **)(a1 + 368);
    v30 = *(_DWORD *)(a1 + 376);
    v31 = v22 ? v50 : 0LL;
    v32 = v22 ? v16 : 0;
    LODWORD(v59) = v59 + v32;
    v61 = 1000 * (v31 + v61 / 0x3E8);
    hfi_port_from_buffer_type = get_hfi_port_from_buffer_type(a1, v28);
    v34 = *(_DWORD *)(v6 + 6604);
    *(_DWORD *)(v6 + 6604) = v34 + 1;
    header = hfi_create_packet(v29, v30, 16777225, 1, 5, hfi_port_from_buffer_type, v34, v58, 0x40u);
    if ( header )
      break;
    if ( a3 )
    {
      v35 = *(_DWORD *)(a3 + 24);
      v36 = *(unsigned int **)(a1 + 368);
      v37 = *(_DWORD *)(a1 + 376);
      v38 = v49;
      if ( !v22 )
        v38 = 0;
      LODWORD(v52) = v52 + v38;
      v54 = 1000 * (v31 + v54 / 0x3E8);
      v39 = get_hfi_port_from_buffer_type(a1, v35);
      v40 = *(_DWORD *)(v6 + 6604);
      *(_DWORD *)(v6 + 6604) = v40 + 1;
      header = hfi_create_packet(v36, v37, 16777225, 1, 5, v39, v40, v51, 0x40u);
      if ( header )
        break;
    }
    v41 = *(_QWORD *)(a1 + 320);
    v42 = *(_QWORD *)(a1 + 368);
    header = _resume(v41);
    if ( header )
      break;
    hfi_buffer = venus_hfi_queue_cmd_write_intr(v41, v42, v12 + v22 == 1);
    if ( !hfi_buffer )
    {
      _schedule_power_collapse_work(v41, v43, v44, v45, v46);
      msm_vidc_add_buffer_stats(a1, a2, v61);
      --v22;
      if ( v12 + v22 )
        continue;
    }
    goto LABEL_67;
  }
  hfi_buffer = header;
LABEL_67:
  core_unlock(v6);
  if ( a1 && hfi_buffer && (msm_vidc_debug & 1) != 0 )
    printk(&unk_94E94, "err ", a1 + 340, "venus_hfi_queue_super_buffer", hfi_buffer);
  _ReadStatusReg(SP_EL0);
  return hfi_buffer;
}
