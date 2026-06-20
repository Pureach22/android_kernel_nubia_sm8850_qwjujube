__int64 __fastcall gsi_ring_ch_ring_db(unsigned __int64 a1, __int64 a2)
{
  __int64 v2; // x20
  int v3; // w4
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x2
  __int64 v7; // x2

  if ( gsi_ctx )
  {
    if ( *(unsigned int *)(gsi_ctx + 28608) <= a1 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad chan_hdl=%lu\n", "gsi_ring_ch_ring_db", 2574, a1);
      return 4294967290LL;
    }
    else
    {
      if ( a1 >= 0x25 )
      {
        __break(0x5512u);
        JUMPOUT(0x1D410);
      }
      v2 = gsi_ctx + 448 * a1;
      v3 = *(_DWORD *)(v2 + 304);
      if ( v3 == 2 )
      {
        *(_QWORD *)(v2 + 352) = a2;
        gsihal_write_reg_nk(50, *(unsigned int *)(gsi_ctx + 20), *(unsigned __int8 *)(v2 + 192));
        v4 = *(_QWORD *)(v2 + 392);
        if ( v4 )
        {
          if ( !*(_DWORD *)(v2 + 188) )
          {
            v5 = gsi_ctx;
            v6 = *(unsigned __int8 *)(v4 + 132);
            *(_QWORD *)(v4 + 160) = *(_QWORD *)(v4 + 176);
            gsihal_write_reg_nk(17, *(unsigned int *)(v5 + 20), v6);
          }
        }
        v7 = *(unsigned __int8 *)(v2 + 192);
        *(_QWORD *)(v2 + 336) = *(_QWORD *)(v2 + 352);
        gsihal_write_reg_nk(18, *(unsigned int *)(gsi_ctx + 20), v7);
        return 0;
      }
      else
      {
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_ring_ch_ring_db", 2581, v3);
        return 4294967289LL;
      }
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_ring_ch_ring_db", 2569);
    return 4294967288LL;
  }
}
