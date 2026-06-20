__int64 __fastcall zte_ir_probe(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w22
  __int64 v5; // x23
  _DWORD *v6; // x20
  void *v7; // x21
  __int64 v8; // x0
  unsigned __int64 v9; // x0
  void *v10; // x2
  unsigned __int64 v17; // x9

  v2 = _kmalloc_large_noprof(80104, 3520);
  if ( !v2 )
    return (unsigned int)-12;
  v5 = v2 + 77824;
  v6 = (_DWORD *)v2;
  *(_QWORD *)(v2 + 80016) = a1;
  *(_DWORD *)(v2 + 80032) = 0;
  _mutex_init(v2 + 80040, "&zte_ir->buf_lock", &zte_ir_probe___key);
  v7 = (void *)(v5 + 2264);
  *(_QWORD *)(v5 + 2264) = v5 + 2264;
  *(_QWORD *)(v5 + 2272) = v5 + 2264;
  mutex_lock(&device_list_lock);
  if ( (minors & 1) != 0 )
  {
    dev_printk(&unk_6F3F, a1, "no minor number available!\n");
    v3 = -19;
    goto LABEL_13;
  }
  v8 = zte_ir_class;
  *v6 = spidev_major << 20;
  v9 = device_create(v8, a1);
  if ( v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    v3 = v9;
LABEL_13:
    mutex_unlock(&device_list_lock);
    *(_DWORD *)(v5 + 2184) = 608000;
    dev_printk(&unk_6F3F, a1, "zte_ir->speed_hz=%d\n", 608000);
    *(_DWORD *)(v5 + 2180) = 31;
    kfree(v6);
    return v3;
  }
  _X8 = &minors;
  __asm { PRFM            #0x11, [X8] }
  do
    v17 = __ldxr((unsigned __int64 *)&minors);
  while ( __stxr(v17 | 1, (unsigned __int64 *)&minors) );
  v10 = device_list;
  if ( device_list == v7 || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)device_list) != &device_list )
  {
    _list_add_valid_or_report(v5 + 2264, &device_list);
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)device_list) = v7;
    *(_QWORD *)(v5 + 2264) = v10;
    *(_QWORD *)(v5 + 2272) = &device_list;
    device_list = (_UNKNOWN *)(v5 + 2264);
  }
  mutex_unlock(&device_list_lock);
  *(_DWORD *)(v5 + 2184) = 608000;
  dev_printk(&unk_6F3F, a1, "zte_ir->speed_hz=%d\n", 608000);
  v3 = 0;
  *(_QWORD *)(a1 + 152) = v6;
  *(_DWORD *)(v5 + 2180) = 31;
  return v3;
}
