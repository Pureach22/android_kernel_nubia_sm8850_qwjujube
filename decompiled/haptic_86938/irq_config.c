__int64 __fastcall irq_config(__int64 a1, __int64 a2)
{
  void (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0
  unsigned int v6; // w0
  __int64 result; // x0
  unsigned int v8; // w8
  unsigned int v9; // w19
  __int64 v10; // x0

  if ( (*(_DWORD *)(a2 + 80) & 0x80000000) != 0 || (*(_BYTE *)(a2 + 21) & 1) != 0 )
  {
    dev_info(a1, "skipping IRQ registration");
    *(_BYTE *)(a2 + 21) |= 1u;
    return 0;
  }
  else
  {
    v4 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a2 + 1480) + 264LL);
    if ( *((_DWORD *)v4 - 1) != -2072377296 )
      __break(0x8228u);
    v4(a2);
    v5 = gpio_to_desc(*(unsigned int *)(a2 + 80));
    v6 = gpiod_to_irq(v5);
    result = devm_request_threaded_irq(a1, v6, 0, irq_handle, 8194, "aw_haptic", a2);
    if ( (_DWORD)result )
    {
      v8 = *(_DWORD *)(a2 + 80);
      v9 = result;
      v10 = gpio_to_desc(v8);
      gpiod_to_irq(v10);
      printk(&unk_165C6, "haptic_hv", 1742, "irq_config");
      return v9;
    }
  }
  return result;
}
