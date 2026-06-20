__int64 __fastcall aw22xxx_task_irq_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "task_irq = %u\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) + 744LL));
}
