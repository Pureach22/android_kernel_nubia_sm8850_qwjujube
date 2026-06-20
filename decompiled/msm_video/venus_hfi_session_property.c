__int64 __fastcall venus_hfi_session_property(
        __int64 a1,
        int a2,
        int a3,
        int a4,
        int a5,
        const void *a6,
        unsigned int a7)
{
  __int64 v7; // x19
  __int64 v15; // x4
  _QWORD *v16; // x8
  _QWORD *v17; // x9
  void *v18; // x0
  int v19; // w3
  __int64 v20; // x0
  unsigned int v21; // w1
  int v22; // w2
  unsigned int header; // w23
  int v24; // w6
  unsigned int *v25; // x0
  unsigned int v26; // w1
  _DWORD *v27; // x21
  __int64 v29; // x21
  __int64 v30; // x20
  __int64 v31; // x1
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x4
  __int64 v35; // x0
  __int64 v36; // x4
  __int64 v37; // x2
  __int64 *v38; // x1
  __int64 v39; // x4
  __int64 v40; // x9

  v7 = *(_QWORD *)(a1 + 320);
  core_lock(v7);
  if ( !*(_QWORD *)(a1 + 368) )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_21;
    v18 = &unk_8DDBA;
    goto LABEL_13;
  }
  if ( (mutex_is_locked(v7 + 3856) & 1) == 0 )
  {
    __break(0x800u);
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_94E60, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_session_property");
    goto LABEL_21;
  }
  v16 = (_QWORD *)(v7 + 3528);
  v17 = (_QWORD *)(v7 + 3528);
  do
    v17 = (_QWORD *)*v17;
  while ( v17 != (_QWORD *)a1 && v17 != v16 );
  if ( a1 && v17 == v16 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
    {
LABEL_21:
      header = -22;
      goto LABEL_22;
    }
    v18 = &unk_89648;
LABEL_13:
    printk(v18, "err ", a1 + 340, "venus_hfi_session_property", v15);
    goto LABEL_21;
  }
  if ( v17 == v16 )
    goto LABEL_21;
  v19 = *(_DWORD *)(v7 + 6600);
  v20 = *(_QWORD *)(a1 + 368);
  v21 = *(_DWORD *)(a1 + 376);
  v22 = *(_DWORD *)(a1 + 332);
  *(_DWORD *)(v7 + 6600) = v19 + 1;
  header = hfi_create_header(v20, v21, v22, v19);
  if ( !header )
  {
    v24 = *(_DWORD *)(v7 + 6604);
    v25 = *(unsigned int **)(a1 + 368);
    v26 = *(_DWORD *)(a1 + 376);
    *(_DWORD *)(v7 + 6604) = v24 + 1;
    header = hfi_create_packet(v25, v26, a2, a3, a5, a4, v24, a6, a7);
    if ( !header )
    {
      if ( *(_BYTE *)(a1 + 1836) == 1 )
      {
        v27 = *(_DWORD **)(a1 + 368);
        if ( *v27 <= 0x1Fu )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_89997, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_cache_packet");
          goto LABEL_21;
        }
        v35 = msm_vidc_pool_alloc(a1, 4u);
        if ( v35 )
        {
          *(_QWORD *)v35 = v35;
          v37 = a1 + 4072;
          *(_QWORD *)(v35 + 8) = v35;
          v38 = *(__int64 **)(a1 + 4080);
          if ( v35 == a1 + 4072 || v38 == (__int64 *)v35 || *v38 != v37 )
          {
            _list_add_valid_or_report(v35);
            v35 = v40;
          }
          else
          {
            *(_QWORD *)(a1 + 4080) = v35;
            *(_QWORD *)v35 = v37;
            *(_QWORD *)(v35 + 8) = v38;
            *v38 = v35;
          }
          *(_QWORD *)(v35 + 16) = v35 + 24;
          v39 = (unsigned int)*v27;
          if ( (unsigned int)v39 < 0x401 )
          {
            memcpy(*(void **)(v35 + 16), *(const void **)(a1 + 368), (unsigned int)*v27);
            header = 0;
            goto LABEL_22;
          }
          if ( a1 && (msm_vidc_debug & 1) != 0 )
            printk(&unk_8477A, "err ", a1 + 340, "venus_hfi_cache_packet", v39);
          goto LABEL_21;
        }
        if ( a1 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_8EB32, "err ", a1 + 340, "venus_hfi_cache_packet", v36);
        header = -12;
      }
      else
      {
        v29 = *(_QWORD *)(a1 + 320);
        v30 = *(_QWORD *)(a1 + 368);
        header = _resume(v29);
        if ( !header )
        {
          header = venus_hfi_queue_cmd_write(v29, v30);
          if ( !header )
            _schedule_power_collapse_work(v29, v31, v32, v33, v34);
        }
      }
    }
  }
LABEL_22:
  core_unlock(v7);
  return header;
}
