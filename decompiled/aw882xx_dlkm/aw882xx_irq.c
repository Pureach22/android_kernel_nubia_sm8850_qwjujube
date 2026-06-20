__int64 __fastcall aw882xx_irq(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 *v4; // x8
  __int64 v6; // x1
  __int64 v7; // x1

  if ( a2 )
  {
    v4 = (__int64 *)a2[8];
    v6 = v4[14];
    if ( !v6 )
      v6 = *v4;
    printk(&unk_26EB3, v6, "aw882xx_irq");
    aw882xx_dev_set_intmask(a2[12], 0);
    v7 = a2[13];
    if ( v7 )
      queue_delayed_work_on(32, v7, a2 + 27, 0);
    return 1;
  }
  else
  {
    printk(&unk_26452, "aw882xx_irq", a3);
    return 4294967274LL;
  }
}
