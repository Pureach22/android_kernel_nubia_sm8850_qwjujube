__int64 __fastcall gen8_receive_ack_cmd(__int64 a1, unsigned int *a2, unsigned int *a3)
{
  __int64 v5; // x0
  unsigned __int64 v6; // x8
  unsigned int v7; // w9
  unsigned int v8; // w21
  unsigned __int64 v9; // x8
  size_t v10; // x2
  __int64 v12; // x20
  size_t v13; // x21

  v5 = gen8_gmu_to_adreno(a1);
  if ( !a3 )
    return 4294967274LL;
  v6 = *a2;
  v7 = *a3 & 0xFFF7FFFF;
  v8 = a2[1] & 0xFFF7FFFF;
  *a3 = v7;
  if ( v7 == v8 )
  {
    v9 = v6 >> 6;
    v10 = v9 & 0x3FC;
    if ( (v9 & 0x3FC) >= 0x4D && (gen8_receive_ack_cmd___already_done & 1) == 0 )
    {
      gen8_receive_ack_cmd___already_done = 1;
      v13 = v9 & 0x3FC;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v10,
        "field \"&ret_cmd->results\" at ../vendor/qcom/opensource/graphics-kernel/adreno_gen8_hfi.c:252",
        0x4Cu);
      v10 = v13;
      __break(0x800u);
    }
    memcpy(a3 + 1, a2, v10);
    return 0;
  }
  else
  {
    v12 = v5;
    if ( (unsigned int)__ratelimit(&gen8_receive_ack_cmd__rs, "gen8_receive_ack_cmd") )
      dev_err(*(_QWORD *)(v12 + 1544) + 16LL, "HFI ACK: Cannot find sender for 0x%8.8x Waiter: 0x%8.8x\n", v8, *a3);
    gmu_core_fault_snapshot(v12, 4);
    return 4294967277LL;
  }
}
