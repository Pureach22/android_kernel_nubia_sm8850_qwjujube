__int64 __fastcall bam_issue_pending(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x10
  _QWORD *v6; // x9
  _QWORD *v7; // x11
  _QWORD *v8; // x12
  __int64 v9; // x8

  v1 = *(_QWORD *)(a1 + 256);
  v3 = *(_QWORD *)(v1 + 536);
  if ( v3 )
    ipc_log_string(v3, "%s chan id:%d\n", "bam_issue_pending", *(_DWORD *)(a1 + 264));
  _ftrace_dbg(*(_QWORD *)(v1 + 8), "%s chan id:%d\n");
  v4 = raw_spin_lock_irqsave(a1 + 160);
  v5 = *(_QWORD *)(a1 + 184);
  v6 = (_QWORD *)(a1 + 200);
  if ( v5 != a1 + 184 )
  {
    v7 = *(_QWORD **)(a1 + 208);
    v8 = *(_QWORD **)(a1 + 192);
    *(_QWORD *)(v5 + 8) = v7;
    *v7 = v5;
    *v8 = v6;
    *(_QWORD *)(a1 + 208) = v8;
    *(_QWORD *)(a1 + 184) = a1 + 184;
    *(_QWORD *)(a1 + 192) = a1 + 184;
  }
  if ( (_QWORD *)*v6 != v6 )
  {
    v9 = -4096;
    if ( *(_BYTE *)(v1 + 532) )
      v9 = -32;
    if ( (v9 | (*(unsigned __int16 *)(a1 + 362) - (unsigned __int64)*(unsigned __int16 *)(a1 + 360))) != 0xFFFFFFFFFFFFFFFFLL )
      bam_start_dma(a1);
  }
  return raw_spin_unlock_irqrestore(a1 + 160, v4);
}
