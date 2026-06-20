__int64 __fastcall qbt_create_input_device(__int64 a1)
{
  _QWORD *device; // x0
  unsigned int v3; // w20

  device = (_QWORD *)input_allocate_device();
  *(_QWORD *)(a1 + 280) = device;
  if ( !device )
  {
    dev_err(*(_QWORD *)(a1 + 288), "%s: input_allocate_device() failed\n", "qbt_create_input_device");
    v3 = -12;
LABEL_6:
    input_free_device(*(_QWORD *)(a1 + 280));
    dev_err(*(_QWORD *)(a1 + 288), "%s: input_free_device rc:%d\n", "qbt_create_input_device", v3);
    goto LABEL_7;
  }
  *device = "qbt_key_input";
  *(_QWORD *)(*(_QWORD *)(a1 + 280) + 8LL) = 0;
  *(_WORD *)(*(_QWORD *)(a1 + 280) + 24LL) = 25;
  *(_WORD *)(*(_QWORD *)(a1 + 280) + 26LL) = 1;
  *(_WORD *)(*(_QWORD *)(a1 + 280) + 28LL) = 1;
  *(_WORD *)(*(_QWORD *)(a1 + 280) + 30LL) = 256;
  *(_QWORD *)(*(_QWORD *)(a1 + 280) + 40LL) = 10;
  *(_QWORD *)(*(_QWORD *)(a1 + 280) + 88LL) = 1024;
  *(_QWORD *)(*(_QWORD *)(a1 + 280) + 88LL) = 32;
  *(_QWORD *)(*(_QWORD *)(a1 + 280) + 64LL) |= 0x100000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 280) + 56LL) |= 0x4000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 280) + 56LL) |= 0x10000000000000uLL;
  input_set_abs_params(*(_QWORD *)(a1 + 280), 0, 0, 1000, 0, 0);
  input_set_abs_params(*(_QWORD *)(a1 + 280), 1, 0, 1000, 0, 0);
  v3 = input_register_device(*(_QWORD *)(a1 + 280));
  if ( v3 )
  {
    dev_err(*(_QWORD *)(a1 + 288), "%s: input_reg_dev() failed %d\n", "qbt_create_input_device", v3);
    goto LABEL_6;
  }
  printk(&unk_9EE5, "qbt_create_input_device");
LABEL_7:
  printk(&unk_9286, "qbt_create_input_device");
  return v3;
}
