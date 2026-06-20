__int64 __fastcall aw9620x_send_once_cmd(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4, unsigned int a5)
{
  unsigned int v10; // w8
  int v11; // w22
  unsigned int v12; // w23
  __int64 result; // x0

  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_send_once_cmd", 1915);
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64))dri_to_soc_pack_send)(
                       a1,
                       a2,
                       a3,
                       a5,
                       a4) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] UPDATE_START_CMD err\n", "aw9620x_send_once_cmd", 1921);
    return 0xFFFFFFFFLL;
  }
  if ( (unsigned int)aw9620x_i2c_write(a1, 0x1C10u, 536872960) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] REG_CMD_SEND_TIRG err\n", "aw9620x_send_once_cmd", 1927);
    return 0xFFFFFFFFLL;
  }
  if ( (unsigned int)aw9620x_i2c_write(a1, 0x4408u, 21) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] REG_CMD_SEND_TIRG err\n", "aw9620x_send_once_cmd", 1934);
    return 0xFFFFFFFFLL;
  }
  v10 = *(_DWORD *)(a1 + 36) - 1;
  if ( v10 > 4 )
  {
    v11 = 0;
    v12 = 0;
  }
  else
  {
    v11 = dword_15C80[v10];
    v12 = dword_15C94[v10];
  }
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] delay_ms_cnt = %d\n", "aw9620x_send_once_cmd", 1965, v12);
  msleep(v12);
  if ( (unsigned int)aw9620x_read_ack_irq(a1) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] read_ack_irq err\n", "aw9620x_send_once_cmd", 1972);
    return 0xFFFFFFFFLL;
  }
  result = soc_to_dri_pack_parse(a1, v11, a2, a3);
  if ( (_DWORD)result )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] soc_to_dri_pack_parse err\n", "aw9620x_send_once_cmd", 1979);
    return 0xFFFFFFFFLL;
  }
  return result;
}
