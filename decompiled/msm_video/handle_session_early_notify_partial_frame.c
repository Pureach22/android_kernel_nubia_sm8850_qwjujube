__int64 __fastcall handle_session_early_notify_partial_frame(__int64 a1, __int64 a2)
{
  __int64 v2; // x4
  __int64 v5; // x23
  __int64 v7; // x4
  __int64 v8; // x20
  _QWORD *fence_from_id; // x0
  unsigned __int64 v10; // x21
  _QWORD *v11; // x22
  int *v12; // x24
  __int64 v13; // x8
  _DWORD *v14; // x8
  int v15; // w8

  v2 = *(unsigned int *)(a1 + 14936);
  if ( (_DWORD)v2 != 1 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_86E91, "err ", a1 + 340, "handle_session_early_notify_partial_frame", v2);
    goto LABEL_9;
  }
  v5 = *(_QWORD *)(a1 + 320);
  if ( (unsigned int)vidc_port_from_hfi(a1, *(_DWORD *)(a2 + 16)) >= 5 )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8A338, "err ", a1 + 340, "handle_session_early_notify_partial_frame", *(unsigned int *)(a2 + 16));
    }
LABEL_9:
    msm_vidc_change_state(a1, 5u, (__int64)"handle_session_early_notify_partial_frame");
    return 4294967274LL;
  }
  if ( (check_for_packet_payload(a1, (unsigned int *)a2, (__int64)"handle_session_early_notify_partial_frame") & 1) == 0 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8D263, "err ", a1 + 340, "handle_session_early_notify_partial_frame", v7);
    goto LABEL_9;
  }
  v8 = *(_QWORD *)(a2 + 32);
  fence_from_id = msm_vidc_get_fence_from_id(a1, (_QWORD *)(a1 + 38352), v8);
  if ( !fence_from_id )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8AE86, "err ", a1 + 340, "handle_session_early_notify_partial_frame", v8);
    goto LABEL_9;
  }
  v10 = fence_from_id[21];
  v11 = fence_from_id;
  v12 = (int *)(a1 + 38368);
  if ( v10 <= *(_QWORD *)(a1 + 38376) )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_86E2E, "err ", a1 + 340, "handle_session_early_notify_partial_frame", v10);
    goto LABEL_9;
  }
  print_fence_buffer(2, (__int64)"high", (__int64)"destroy", a1, 0, (__int64)fence_from_id);
  if ( v5 )
  {
    v13 = *(_QWORD *)(v5 + 6584);
    if ( v13 )
    {
      v14 = *(_DWORD **)(v13 + 48);
      if ( v14 )
      {
        if ( *(v14 - 1) != -1185588215 )
          __break(0x8228u);
        if ( ((unsigned int (__fastcall *)(__int64, _QWORD *, _QWORD))v14)(a1, v11, 0) )
        {
          if ( a1 && (msm_vidc_debug & 1) != 0 )
            printk(&unk_94112, "err ", a1 + 340, "handle_session_early_notify_partial_frame", v10);
          goto LABEL_9;
        }
      }
    }
  }
  v15 = *v12;
  *(_QWORD *)(a1 + 38376) = v10;
  *v12 = v15 + 1;
  if ( a1 && (msm_vidc_debug & 4) != 0 )
    printk(&unk_910EF, "low ", a1 + 340, "handle_session_early_notify_partial_frame", v10);
  return 0;
}
