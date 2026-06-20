__int64 __fastcall deinit_queues(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  __int64 v7; // x26
  _DWORD *v8; // x21
  _QWORD *v9; // x26
  _DWORD *v10; // t1
  unsigned __int64 v11; // x20
  __int64 *v12; // x27
  unsigned int v13; // w0
  unsigned int v14; // w0
  __int64 v15; // x3
  __int64 v16; // x4
  unsigned int v18; // w20
  __int64 v19; // x21
  __int64 v20; // x30
  unsigned int v21; // w19
  void *v22; // x0
  __int64 v23; // x2

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v18 = a1;
    v19 = a2;
    printk(&unk_1E83A, "deinit_queues", 755, a4, a5);
    a2 = v19;
    a1 = v18;
    if ( v18 < 4 )
      goto LABEL_3;
LABEL_20:
    printk(&unk_1D5EB, "deinit_queues", 758, v6, a1);
    return 4294967274LL;
  }
  if ( a1 >= 4 )
    goto LABEL_20;
LABEL_3:
  if ( a2 && (v7 = a2 + 176LL * a1, v10 = *(_DWORD **)(v7 + 144), v9 = (_QWORD *)(v7 + 144), (v8 = v10) != nullptr) )
  {
    if ( *v8 )
    {
      v11 = 0;
      v12 = (__int64 *)(v8 + 6);
      while ( v11 != 5 )
      {
        if ( v12 == &qword_10 )
        {
          printk(&unk_196A9, "deinit_queues", 773, v6, (unsigned int)v11);
        }
        else
        {
          v13 = set_param_hfi_queue(*(v12 - 1), 2u, 0, 0);
          if ( v13 )
          {
            v20 = v6;
            v21 = v13;
            v22 = &unk_1C33B;
            v23 = 782;
LABEL_23:
            printk(v22, "deinit_queues", v23, v20, (unsigned int)v11);
            return v21;
          }
          destroy_hfi_queue(*(v12 - 1));
          v14 = set_param_hfi_queue(*v12, 2u, 0, 0);
          if ( v14 )
          {
            v20 = v6;
            v21 = v14;
            v22 = &unk_1C8D2;
            v23 = 793;
            goto LABEL_23;
          }
          destroy_hfi_queue(*v12);
        }
        ++v11;
        v12 += 3;
        if ( v11 >= (unsigned int)*v8 )
          goto LABEL_15;
      }
      __break(0x5512u);
      return set_device_tx_buffer();
    }
    else
    {
LABEL_15:
      kfree(v8);
      *v9 = 0;
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "deinit_queues", 804, v15, v16);
      return 0;
    }
  }
  else
  {
    printk(&unk_1905C, "deinit_queues", 763, v6, a5);
    return 4294967274LL;
  }
}
