__int64 __fastcall gf_release(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  int v4; // w8
  __int64 v6; // x0

  printk(&unk_8A0D);
  mutex_lock(&device_list_lock);
  v3 = *(_QWORD *)(a2 + 32);
  *(_QWORD *)(a2 + 32) = 0;
  v4 = *(_DWORD *)(v3 + 56) - 1;
  *(_DWORD *)(v3 + 56) = v4;
  if ( !v4 )
  {
    printk(&unk_8FC8);
    irq_set_irq_wake(*(unsigned int *)(v3 + 72), 0);
    if ( *(_DWORD *)(v3 + 76) )
    {
      v6 = *(unsigned int *)(v3 + 72);
      *(_DWORD *)(v3 + 76) = 0;
      disable_irq(v6);
    }
    else
    {
      printk(&unk_8DA2);
    }
    free_irq(*(unsigned int *)(v3 + 72), v3);
    gf_cleanup(v3);
    *(_BYTE *)(v3 + 112) = 0;
  }
  mutex_unlock(&device_list_lock);
  return 0;
}
