__int64 __fastcall bam_pipe_init(const void **a1, unsigned int a2, unsigned __int16 *a3, unsigned int a4)
{
  __int64 v8; // x3
  int v10; // w24
  int v11; // w26
  int v12; // w25
  unsigned int v13; // w3
  char v14; // w8
  const char *v15; // x3
  const char *v16; // x2

  if ( a1 == &_ksymtab_sps_get_free_count )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&bam_pipe_init__rs, "bam_pipe_init")) )
    {
      printk(&unk_27124, "bam_pipe_init", 216);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: Failed to get dev for base addr 0x%pK\n",
        "bam_pipe_init",
        &_ksymtab_sps_get_free_count);
    return 0xFFFFFFFFLL;
  }
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
  {
    if ( print_limit_option )
      goto LABEL_58;
LABEL_41:
    printk(&unk_248D3, "bam_pipe_init", a1 - 24);
    goto LABEL_3;
  }
  while ( 1 )
  {
LABEL_3:
    if ( *((_DWORD *)a1 + 88) <= 2u )
      ipc_log_string(a1[41], "%s: sps: bam=%pa 0x%pK(va).pipe=%d\n", "bam_pipe_init", a1 - 24, *a1, a2);
    bam_write_reg((__int64)a1, 0x1Du, a2, 1u);
    bam_write_reg((__int64)a1, 0x1Du, a2, 0);
    bam_write_reg_field((__int64)a1, 0x19u, a4, 1 << a2, 1);
    bam_write_reg((__int64)a1, 0x21u, a2, *((_DWORD *)a3 + 1));
    bam_write_reg_field((__int64)a1, 0x1Cu, a2, 8u, *((_DWORD *)a3 + 2));
    bam_write_reg_field((__int64)a1, 0x1Cu, a2, 0x20u, *((_DWORD *)a3 + 3));
    bam_write_reg((__int64)a1, 0x2Eu, a2, *a3);
    bam_write_reg((__int64)a1, 0x2Cu, a2, *((_DWORD *)a3 + 6));
    bam_write_reg_field((__int64)a1, 0x2Fu, a2, 0xFFFFu, *((_DWORD *)a3 + 8));
    bam_write_reg_field((__int64)a1, 0x1Cu, a2, 0x10u, *((_DWORD *)a3 + 10));
    v8 = *((_DWORD *)a3 + 7) & 0xFLL;
    if ( v8 )
      bam_write_reg((__int64)a1, 0x2Du, a2, v8);
    bam_write_reg_field((__int64)a1, 0x1Cu, a2, 0x1F0000u, *((_DWORD *)a3 + 9));
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 4u
      && (!print_limit_option || (unsigned int)__ratelimit(&bam_pipe_init__rs_62, "bam_pipe_init")) )
    {
      printk(&unk_25C1D, "bam_pipe_init", *a1);
    }
    if ( *((_DWORD *)a1 + 88) )
    {
      if ( *((_DWORD *)a3 + 3) )
        goto LABEL_38;
    }
    else
    {
      ipc_log_string(
        a1[39],
        "%s: sps:bam=0x%pK(va).pipe=%d.lock_group=%d\n",
        "bam_pipe_init",
        *a1,
        a2,
        *((_DWORD *)a3 + 9));
      if ( *((_DWORD *)a3 + 3) )
        goto LABEL_38;
    }
    a4 = bam_type;
    if ( (unsigned int)bam_type < 4 )
      break;
    __break(0x5512u);
LABEL_57:
    __break(1u);
LABEL_58:
    if ( (unsigned int)__ratelimit(&bam_pipe_init__rs_61, "bam_pipe_init") )
      goto LABEL_41;
  }
  if ( bam_type == 3 )
    goto LABEL_57;
  v10 = *((_DWORD *)a3 + 12);
  v11 = *((_DWORD *)a3 + 13);
  v12 = bam_regmap[59 * bam_type + 40];
  bam_write_reg((__int64)a1, 0x2Au, a2, *((_DWORD *)a3 + 14));
  bam_write_reg_field((__int64)a1, 0x2Fu, a2, 0xFFFF0000, *((_DWORD *)a3 + 16));
  if ( (a3[34] & 1) != 0 )
  {
    v13 = *((_DWORD *)a3 + 12);
  }
  else
  {
    if ( a4 )
      v14 = 12;
    else
      v14 = 6;
    v13 = (v11 << v14) + v10 + v12;
  }
  bam_write_reg((__int64)a1, 0x26u, a2, v13);
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 2u
    && (!print_limit_option || (unsigned int)__ratelimit(&bam_pipe_init__rs_65, "bam_pipe_init")) )
  {
    printk(&unk_2569E, "bam_pipe_init", *a1);
  }
  if ( *((_DWORD *)a1 + 88) <= 2u )
    ipc_log_string(
      a1[41],
      "%s: sps:bam=0x%pK(va).pipe=%d.peer_bam=0x%x.peer_pipe=%d\n",
      "bam_pipe_init",
      *a1,
      a2,
      *((_DWORD *)a3 + 12),
      *((_DWORD *)a3 + 13));
  if ( (a3[30] & 0xF) != 0 )
  {
    bam_write_reg((__int64)a1, 0x27u, a2, 0);
    bam_write_reg((__int64)a1, 0x2Bu, a2, *((_DWORD *)a3 + 15) & 0xF);
  }
  bam_write_reg_field((__int64)a1, 0x1Cu, a2, 0x800u, *((_DWORD *)a3 + 4));
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 4u
    && (!print_limit_option || (unsigned int)__ratelimit(&bam_pipe_init__rs_68, "bam_pipe_init")) )
  {
    if ( *((_DWORD *)a3 + 4) )
      v16 = "Set";
    else
      v16 = "Do not set";
    printk(&unk_236A3, "bam_pipe_init", v16);
  }
  if ( !*((_DWORD *)a1 + 88) )
  {
    if ( *((_DWORD *)a3 + 4) )
      v15 = "Set";
    else
      v15 = "Do not set";
    ipc_log_string(a1[39], "%s: sps:%s WRITE_NWD bit for this bam2bam pipe\n", "bam_pipe_init", v15);
  }
LABEL_38:
  bam_write_reg_field((__int64)a1, 0x1Cu, a2, 2u, 1);
  return 0;
}
