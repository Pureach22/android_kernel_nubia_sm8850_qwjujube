__int64 __fastcall print_bam_test_bus_reg(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  __int64 v4; // x8
  __int64 v5; // x20
  int reg; // w21
  int reg_field; // w0
  unsigned int v8; // w20
  __int64 i; // x26
  __int64 v10; // x23
  int v11; // w24
  int v12; // w0
  unsigned int v13; // w23

  if ( !result )
    return result;
  v2 = result;
  v4 = sps;
  if ( a2 )
  {
    if ( sps )
    {
      ipc_log_string(
        *(_QWORD *)(sps + 280),
        "%s: \nsps:Specified TEST_BUS_SEL value: 0x%x\n",
        "print_bam_test_bus_reg",
        a2);
      if ( sps )
      {
        if ( !*(_QWORD *)(sps + 280) )
          printk(&unk_25CEE, "print_bam_test_bus_reg", a2);
      }
    }
    bam_write_reg_field(v2, 0x15u, 0, 0x7Fu, a2);
    if ( !sps )
      goto LABEL_15;
    v5 = *(_QWORD *)(sps + 280);
    reg = bam_read_reg(v2, 0x16u);
    reg_field = bam_read_reg_field(v2, 0x15u, 0, 0x7Fu);
    ipc_log_string(
      v5,
      "%s: sps:BAM_TEST_BUS_REG:0x%x for TEST_BUS_SEL:0x%x\n\n",
      "print_bam_test_bus_reg",
      reg,
      reg_field);
    v4 = sps;
    if ( !sps )
      goto LABEL_15;
    if ( *(_QWORD *)(sps + 280) )
      goto LABEL_12;
    v8 = bam_read_reg(v2, 0x16u);
    bam_read_reg_field(v2, 0x15u, 0, 0x7Fu);
    printk(&unk_277B2, "print_bam_test_bus_reg", v8);
    v4 = sps;
  }
  if ( v4 )
  {
LABEL_12:
    ipc_log_string(
      *(_QWORD *)(v4 + 280),
      "%s: %s",
      "print_bam_test_bus_reg",
      "\nsps:<testbus-begin> --- BAM TEST_BUS dump -----\n\n");
    if ( sps && !*(_QWORD *)(sps + 280) )
      printk(&unk_2919C, "print_bam_test_bus_reg", "\nsps:<testbus-begin> --- BAM TEST_BUS dump -----\n\n");
  }
LABEL_15:
  for ( i = 0; i != 136; i += 4 )
  {
    result = bam_write_reg_field(v2, 0x15u, 0, 0x7Fu, *(_DWORD *)((char *)&unk_2B280 + i));
    if ( sps )
    {
      v10 = *(_QWORD *)(sps + 280);
      v11 = bam_read_reg(v2, 0x16u);
      v12 = bam_read_reg_field(v2, 0x15u, 0, 0x7Fu);
      result = ipc_log_string(
                 v10,
                 "%s: sps:TEST_BUS_REG:0x%x\t  TEST_BUS_SEL:0x%x\n",
                 "print_bam_test_bus_reg",
                 v11,
                 v12);
      if ( sps )
      {
        if ( !*(_QWORD *)(sps + 280) )
        {
          v13 = bam_read_reg(v2, 0x16u);
          bam_read_reg_field(v2, 0x15u, 0, 0x7Fu);
          result = printk(&unk_269DD, "print_bam_test_bus_reg", v13);
        }
      }
    }
  }
  if ( sps )
  {
    result = ipc_log_string(
               *(_QWORD *)(sps + 280),
               "%s: %s",
               "print_bam_test_bus_reg",
               "\nsps:<testbus-end> --- BAM TEST_BUS dump -----\n\n");
    if ( sps )
    {
      if ( !*(_QWORD *)(sps + 280) )
        return printk(&unk_2919C, "print_bam_test_bus_reg", "\nsps:<testbus-end> --- BAM TEST_BUS dump -----\n\n");
    }
  }
  return result;
}
