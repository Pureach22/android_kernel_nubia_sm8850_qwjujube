__int64 __fastcall slim_alloc_device(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  __int16 v8; // w9
  __int64 v9; // x8
  __int64 v10; // x8
  int v11; // w2
  int v12; // w3
  int v13; // w4
  int v14; // w5

  v6 = _kmalloc_cache_noprof(printk, 3520, 960);
  v7 = v6;
  if ( v6 )
  {
    v8 = *(_WORD *)(a2 + 4);
    *(_DWORD *)(v6 + 912) = *(_DWORD *)a2;
    v9 = *a1;
    *(_WORD *)(v6 + 916) = v8;
    *(_QWORD *)(v6 + 96) = v9;
    *(_QWORD *)(v6 + 808) = slim_dev_release;
    *(_QWORD *)(v6 + 128) = &slimbus_bus;
    *(_QWORD *)(v6 + 136) = 0;
    *(_QWORD *)(v6 + 920) = a1;
    *(_QWORD *)(v6 + 936) = v6 + 936;
    *(_QWORD *)(v6 + 944) = v6 + 936;
    *(_DWORD *)(v6 + 952) = 0;
    _mutex_init(a1 + 39, "&ctrl->stream_lock", &slim_add_device___key);
    v10 = a3 + 24;
    v11 = *(unsigned __int16 *)(v7 + 916);
    v12 = *(unsigned __int16 *)(v7 + 914);
    v13 = *(unsigned __int8 *)(v7 + 913);
    v14 = *(unsigned __int8 *)(v7 + 912);
    if ( !a3 )
      v10 = 0;
    *(_QWORD *)(v7 + 744) = a3;
    *(_QWORD *)(v7 + 752) = v10;
    dev_set_name(v7, "%x:%x:%x:%x%s", v11, v12, v13, v14, "   ");
    if ( (unsigned int)device_register(v7) )
    {
      put_device(v7);
      return 0;
    }
  }
  return v7;
}
