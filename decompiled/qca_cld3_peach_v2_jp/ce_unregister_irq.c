__int64 __fastcall ce_unregister_irq(__int64 a1, int a2)
{
  __int64 v3; // x24
  int v5; // w0
  int v6; // w8
  unsigned int v7; // w26
  unsigned __int64 v8; // x20
  __int64 v9; // x22
  int v10; // w0

  if ( a1 )
  {
    v3 = *(unsigned int *)(a1 + 656);
    v5 = hif_napi_event();
    if ( v5 )
      qdf_trace_msg(61, 2, "%s: napi_event INT_STATE returned %d", "ce_unregister_irq", v5);
    v6 = *(_DWORD *)(a1 + 27384);
    v7 = v6 & a2;
    if ( (int)v3 >= 1 )
    {
      v8 = 0;
      v9 = a1 + 26448;
      do
      {
        if ( ((v7 >> v8) & 1) != 0 )
        {
          if ( v8 >= 0xC )
          {
LABEL_17:
            __break(0x5512u);
            JUMPOUT(0x37E609C);
          }
          if ( *(_BYTE *)(v9 + 44) == 1 )
          {
            v10 = pld_ce_free_irq(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), (unsigned int)v8, v9);
            if ( v10 < 0 )
              qdf_trace_msg(61, 2, "%s: pld_unregister_irq error - ce_id = %d, ret = %d", "ce_unregister_irq", v8, v10);
          }
        }
        else if ( v8 > 0xB )
        {
          goto LABEL_17;
        }
        ce_disable_polling(*(_QWORD *)(a1 + 480 + 8 * v8++));
        v9 += 56;
      }
      while ( v3 != v8 );
      v6 = *(_DWORD *)(a1 + 27384);
    }
    *(_DWORD *)(a1 + 27384) = v6 & ~v7;
  }
  else
  {
    qdf_trace_msg(61, 3, "%s: hif_ce_state = NULL", "ce_unregister_irq");
  }
  return 0;
}
