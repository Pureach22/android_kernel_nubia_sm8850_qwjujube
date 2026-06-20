__int64 __fastcall synx_util_destroy_data(__int64 a1)
{
  _QWORD *v1; // x9
  _QWORD *v3; // x0
  __int64 v4; // x10
  _QWORD *v6; // x19

  v1 = *(_QWORD **)(a1 + 16);
  v3 = (_QWORD *)(a1 - 16);
  if ( v1 )
  {
    v4 = *(_QWORD *)(a1 + 8);
    *v1 = v4;
    if ( v4 )
      *(_QWORD *)(v4 + 8) = v1;
    *(_QWORD *)(a1 + 8) = 0;
    *(_QWORD *)(a1 + 16) = 0;
  }
  if ( (synx_debug & 0x80) != 0 )
  {
    v6 = v3;
    printk(&unk_26D9C, &unk_25D36, "synx_util_destroy_data", 1795, *v3, v3);
    v3 = v6;
  }
  return kfree(v3);
}
