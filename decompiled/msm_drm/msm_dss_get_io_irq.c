__int64 __fastcall msm_dss_get_io_irq(__int64 a1, _QWORD *a2, int a3)
{
  __int64 v5; // x1
  unsigned int irq; // w20
  __int64 v7; // x0
  _QWORD *v8; // x2
  _QWORD *v9; // x8

  irq = platform_get_irq(a1, 0);
  if ( (irq & 0x80000000) != 0 )
  {
    printk(&unk_277948, v5);
  }
  else
  {
    v7 = _kmalloc_cache_noprof(wake_up_process, 3520, 24);
    if ( v7 )
    {
      v8 = (_QWORD *)*a2;
      *(_DWORD *)v7 = a3;
      *(_DWORD *)(v7 + 4) = irq;
      v9 = (_QWORD *)(v7 + 8);
      if ( (_QWORD *)v8[1] != a2 || v9 == a2 || v8 == v9 )
      {
        _list_add_valid_or_report(v7 + 8, a2);
        return 0;
      }
      else
      {
        irq = 0;
        v8[1] = v9;
        *(_QWORD *)(v7 + 8) = v8;
        *(_QWORD *)(v7 + 16) = a2;
        *a2 = v9;
      }
    }
    else
    {
      return (unsigned int)-12;
    }
  }
  return irq;
}
