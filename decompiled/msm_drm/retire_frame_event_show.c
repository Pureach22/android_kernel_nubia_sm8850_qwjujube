__int64 __fastcall retire_frame_event_show(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a1 && a3 )
    return (int)scnprintf(a3, 4096, "RETIRE_FRAME_TIME=%llu\n", *(_QWORD *)(*(_QWORD *)(a1 + 152) + 4440LL));
  printk(&unk_2120FD, "retire_frame_event_show");
  return -11;
}
