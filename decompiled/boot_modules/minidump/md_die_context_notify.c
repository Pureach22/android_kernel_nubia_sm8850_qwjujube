__int64 __fastcall md_die_context_notify(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x0
  __int64 v5; // x20
  __int64 v6; // x8

  if ( (md_in_oops_handler & 1) == 0 )
  {
    v3 = md_cntxt_seq_buf;
    md_in_oops_handler = 1;
    if ( md_cntxt_seq_buf )
    {
      die_cpu = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40);
      seq_buf_printf(v3, "\nDIE CPU : %d\n", die_cpu);
      v5 = *a3;
      if ( (*(_BYTE *)(v5 + 264) & 0xF) != 0 )
      {
        v6 = *(_QWORD *)(v5 + 256);
        if ( v6 )
        {
          md_dump_data(v6 - 128, "PC");
          md_dump_data(*(_QWORD *)(v5 + 240) - 128LL, "LR");
          md_dump_data(*(_QWORD *)(v5 + 248) - 128LL, "SP");
        }
      }
    }
    md_in_oops_handler = 0;
  }
  return 0;
}
