__int64 __fastcall ce_register_irq(__int64 a1, int a2)
{
  __int64 v2; // x25
  unsigned __int64 v5; // x21
  int v6; // w20
  __int64 v7; // x23
  int v8; // w0
  __int64 result; // x0

  v2 = *(unsigned int *)(a1 + 656);
  if ( (int)v2 >= 1 )
  {
    v5 = 0;
    v6 = 0;
    v7 = a1 + 26448;
    while ( 1 )
    {
      if ( ((1 << v5) & a2) != 0 )
      {
        if ( v5 >= 0xC )
        {
          __break(0x5512u);
          return hif_snoc_interrupt_handler();
        }
        if ( *(_BYTE *)(v7 + 44) == 1 )
        {
          v8 = pld_ce_request_irq(
                 *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL),
                 (unsigned int)v5,
                 hif_snoc_interrupt_handler,
                 1,
                 ce_name[v5],
                 v7);
          if ( v8 )
          {
            qdf_trace_msg(61, 2, "%s: cannot register CE %d irq handler, ret = %d", "ce_register_irq", v5, v8);
            ce_unregister_irq(a1, v6);
            return 5;
          }
          v6 |= 1 << v5;
        }
      }
      ++v5;
      v7 += 56;
      if ( v2 == v5 )
        goto LABEL_10;
    }
  }
  v6 = 0;
LABEL_10:
  result = 0;
  *(_DWORD *)(a1 + 27384) |= v6;
  return result;
}
