__int64 __fastcall venus_hfi_session_command_locked(
        __int64 a1,
        unsigned int a2,
        int a3,
        int a4,
        __int64 a5,
        int a6,
        const void *a7,
        unsigned int a8,
        __int64 a9)
{
  __int64 v10; // x22
  int v11; // w27
  _QWORD *v18; // x8
  _QWORD *v19; // x9
  void *v20; // x0
  int v21; // w3
  __int64 v22; // x0
  unsigned int v23; // w1
  __int64 result; // x0
  __int64 v25; // x4
  int v26; // w6
  unsigned int *v27; // x0
  unsigned int v28; // w1
  __int64 v29; // x23
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x2
  unsigned int v34; // w20

  if ( !*(_QWORD *)(a1 + 368) )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v20 = &unk_8DDBA;
    goto LABEL_13;
  }
  v10 = *(_QWORD *)(a1 + 320);
  v11 = a5;
  if ( (mutex_is_locked(v10 + 3856) & 1) == 0 )
  {
    __break(0x800u);
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_94E60, "err ", 0xFFFFFFFFLL, "codec", a9);
    return 4294967274LL;
  }
  v18 = (_QWORD *)(v10 + 3528);
  v19 = (_QWORD *)(v10 + 3528);
  do
    v19 = (_QWORD *)*v19;
  while ( v19 != (_QWORD *)a1 && v19 != v18 );
  if ( a1 && v19 == v18 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v20 = &unk_89648;
LABEL_13:
    printk(v20, "err ", a1 + 340, a9, a5);
    return 4294967274LL;
  }
  if ( v19 == v18 )
    return 4294967274LL;
  v21 = *(_DWORD *)(v10 + 6600);
  v22 = *(_QWORD *)(a1 + 368);
  v23 = *(_DWORD *)(a1 + 376);
  *(_DWORD *)(v10 + 6600) = v21 + 1;
  result = hfi_create_header(v22, v23, v11, v21);
  if ( (_DWORD)result )
    goto LABEL_19;
  v26 = *(_DWORD *)(v10 + 6604);
  v27 = *(unsigned int **)(a1 + 368);
  v28 = *(_DWORD *)(a1 + 376);
  *(_DWORD *)(v10 + 6604) = v26 + 1;
  result = hfi_create_packet(v27, v28, a2, a3, a6, a4, v26, a7, a8);
  if ( (_DWORD)result
    || (v29 = *(_QWORD *)(a1 + 368), result = _resume(v10), (_DWORD)result)
    || (result = venus_hfi_queue_cmd_write(v10, v29), (_DWORD)result) )
  {
LABEL_19:
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v33 = a1 + 340;
        v34 = result;
        printk(&unk_8474B, "err ", v33, a9, v25);
        return v34;
      }
    }
  }
  else
  {
    _schedule_power_collapse_work(v10, v30, v31, v32, v25);
    if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_82EB9, "high", a1 + 340, a9, a2);
      return 0;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
