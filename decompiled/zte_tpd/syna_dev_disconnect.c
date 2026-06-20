__int64 __fastcall syna_dev_disconnect(__int64 a1, __int64 a2, __int64 a3)
{
  void *v3; // x0
  __int64 v4; // x20
  __int64 v5; // x19
  _DWORD *v6; // x8
  __int64 v7; // x21
  __int64 v8; // x0
  __int64 v9; // x2
  void *v10; // x0
  _DWORD *v11; // x8
  __int64 v12; // x22

  if ( *(_BYTE *)(a1 + 1410) )
  {
    v4 = *(_QWORD *)(a1 + 624);
    v5 = a1;
    if ( *(_DWORD *)(a1 + 1404) == 3 )
    {
      printk(&unk_398C3, "syna_dev_disconnect", a3);
      v6 = *(_DWORD **)(v4 + 384);
      if ( !v6 )
      {
LABEL_24:
        v3 = &unk_3604B;
        *(_DWORD *)(v5 + 1404) = 0;
        *(_BYTE *)(v5 + 1410) = 0;
        goto LABEL_25;
      }
LABEL_21:
      if ( *(v6 - 1) != 1596991531 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v6)(v4, 0);
      goto LABEL_24;
    }
    if ( *(_QWORD *)(a1 + 1072) )
    {
      cancel_delayed_work_sync(a1 + 968);
      _flush_workqueue(*(_QWORD *)(v5 + 1072));
      a1 = destroy_workqueue(*(_QWORD *)(v5 + 1072));
      *(_QWORD *)(v5 + 1072) = 0;
    }
    if ( *(_DWORD *)(v4 + 184) )
    {
      v7 = *(_QWORD *)(v5 + 624);
      v8 = syna_request_managed_device(a1);
      if ( v8 )
      {
        if ( *(int *)(v7 + 184) < 1 )
          goto LABEL_18;
        v11 = *(_DWORD **)(v7 + 64);
        if ( v11 )
        {
          v12 = v8;
          if ( *(v11 - 1) != 875454897 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v11)(v7 + 8, 0);
          v8 = v12;
        }
        devm_free_irq(v8);
        v10 = &unk_36071;
        *(_DWORD *)(v7 + 184) = 0;
        *(_BYTE *)(v7 + 188) = 0;
      }
      else
      {
        v10 = &unk_3BE43;
      }
      printk(v10, "syna_dev_release_irq", v9);
    }
LABEL_18:
    if ( *(_QWORD *)(v5 + 944) )
    {
      input_unregister_device();
      *(_QWORD *)(v5 + 944) = 0;
    }
    *(_QWORD *)(v5 + 952) = 0;
    *(_DWORD *)(v5 + 960) = 0;
    v6 = *(_DWORD **)(v4 + 384);
    if ( !v6 )
      goto LABEL_24;
    goto LABEL_21;
  }
  v3 = &unk_34798;
LABEL_25:
  printk(v3, "syna_dev_disconnect", "synaptics_tcm");
  return 0;
}
