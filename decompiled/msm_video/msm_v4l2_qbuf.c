__int64 __fastcall msm_v4l2_qbuf(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 *v5; // x19
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 *inst_ref; // x0
  __int64 v9; // x19
  __int64 v10; // x4
  unsigned int v11; // w20
  void *v12; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4

  if ( !a1 )
  {
    v5 = nullptr;
    v6 = video_devdata(0);
    if ( a3 )
      goto LABEL_6;
LABEL_12:
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v12 = &unk_83321;
LABEL_19:
    printk(v12, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_qbuf");
    return 4294967274LL;
  }
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
    v5 = (__int64 *)(v4 - 1648);
  else
    v5 = nullptr;
  v6 = video_devdata(a1);
  if ( !a3 )
    goto LABEL_12;
LABEL_6:
  v7 = v6;
  inst_ref = get_inst_ref(g_core, v5);
  if ( !inst_ref )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v12 = &unk_961DD;
    goto LABEL_19;
  }
  v9 = (__int64)inst_ref;
  client_lock((__int64)inst_ref);
  inst_lock(v9);
  if ( *(_DWORD *)(v9 + 160) == 5 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_94D1A, "err ", v9 + 340, "msm_v4l2_qbuf", v10);
    v11 = -22;
  }
  else
  {
    v11 = msm_vidc_qbuf(v9, *(_QWORD *)(*(_QWORD *)(v7 + 1104) + 8LL), a3);
  }
  inst_unlock(v9);
  client_unlock(v9);
  put_inst(v9, v14, v15, v16, v17);
  return v11;
}
