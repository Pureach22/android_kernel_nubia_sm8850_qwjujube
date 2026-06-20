__int64 __fastcall bam_slave_config(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x11
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v12; // x11

  v2 = *(_QWORD *)(a1 + 256);
  v5 = *(_QWORD *)(v2 + 536);
  if ( v5 )
  {
    ipc_log_string(v5, "%s chan id:%d\n", "bam_slave_config", *(_DWORD *)(a1 + 264));
    v2 = *(_QWORD *)(a1 + 256);
  }
  _ftrace_dbg(*(_QWORD *)(v2 + 8), "%s chan id:%d\n");
  v6 = raw_spin_lock_irqsave(a1 + 160);
  *(_QWORD *)(a1 + 272) = *a2;
  v7 = a2[4];
  v8 = a2[1];
  v9 = a2[2];
  *(_QWORD *)(a1 + 296) = a2[3];
  *(_QWORD *)(a1 + 304) = v7;
  *(_QWORD *)(a1 + 280) = v8;
  *(_QWORD *)(a1 + 288) = v9;
  v10 = a2[8];
  v11 = a2[5];
  v12 = a2[6];
  *(_QWORD *)(a1 + 328) = a2[7];
  *(_QWORD *)(a1 + 336) = v10;
  *(_QWORD *)(a1 + 312) = v11;
  *(_QWORD *)(a1 + 320) = v12;
  *(_DWORD *)(a1 + 372) = 1;
  raw_spin_unlock_irqrestore(a1 + 160, v6);
  return 0;
}
