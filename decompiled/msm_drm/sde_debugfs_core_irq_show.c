__int64 __fastcall sde_debugfs_core_irq_show(__int64 a1)
{
  __int64 v1; // x25
  unsigned int v3; // w20
  __int64 v4; // x1
  int v5; // w24
  int v6; // w22
  int v7; // w23
  _QWORD *v8; // x9

  v1 = *(_QWORD *)(a1 + 128);
  if ( v1 && *(_QWORD *)(v1 + 16) && *(_QWORD *)(v1 + 8) )
  {
    if ( *(_DWORD *)v1 )
    {
      v3 = 0;
      do
      {
        v4 = raw_spin_lock_irqsave(v1 + 32);
        v5 = -1;
        v6 = *(_DWORD *)(*(_QWORD *)(v1 + 24) + 4LL * (int)v3);
        v7 = *(_DWORD *)(*(_QWORD *)(v1 + 16) + 4LL * (int)v3);
        v8 = (_QWORD *)(*(_QWORD *)(v1 + 8) + 16LL * (int)v3);
        do
        {
          v8 = (_QWORD *)*v8;
          ++v5;
        }
        while ( v8 != (_QWORD *)(*(_QWORD *)(v1 + 8) + 16LL * (int)v3) );
        raw_spin_unlock_irqrestore(v1 + 32, v4);
        if ( v6 || v7 || v5 )
          seq_printf(a1, "idx:%d irq:%d enable:%d cb:%d\n", v3, v6, v7, v5);
        ++v3;
      }
      while ( v3 < *(_DWORD *)v1 );
    }
  }
  else
  {
    printk(&unk_27D28A, "sde_debugfs_core_irq_show");
  }
  return 0;
}
