__int64 __fastcall synx_util_destroy_map_entry(__int64 a1)
{
  _QWORD *v1; // x8
  __int64 v3; // x9
  _QWORD *v4; // x19

  v1 = *(_QWORD **)(a1 + 56);
  if ( v1 )
  {
    v3 = *(_QWORD *)(a1 + 48);
    *v1 = v3;
    if ( v3 )
      *(_QWORD *)(v3 + 8) = v1;
    *(_QWORD *)(a1 + 48) = 0;
    *(_QWORD *)(a1 + 56) = 0;
  }
  if ( (synx_debug & 0x80) != 0 )
    printk(&unk_26861, &unk_25D36, "synx_util_destroy_map_entry", 1213, *(unsigned int *)(a1 + 8), a1 - 8);
  *(_QWORD *)(a1 + 16) = 0xFFFFFFFE00000LL;
  v4 = (_QWORD *)(a1 + 16);
  v4[1] = v4 + 1;
  v4[2] = v4 + 1;
  v4[3] = synx_util_destroy_map_entry_worker;
  return queue_work_on(32, *(_QWORD *)(synx_dev + 168), v4);
}
