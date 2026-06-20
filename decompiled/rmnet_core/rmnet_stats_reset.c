__int64 __fastcall rmnet_stats_reset(__int64 a1)
{
  _QWORD *port; // x0

  port = (_QWORD *)rmnet_get_port(*(_QWORD *)(a1 + 2696));
  if ( !port )
    return 4294967274LL;
  port[342] = 0;
  port[341] = 0;
  port[340] = 0;
  port[339] = 0;
  port[338] = 0;
  port[337] = 0;
  port[336] = 0;
  port[335] = 0;
  port[334] = 0;
  port[333] = 0;
  port[332] = 0;
  port[331] = 0;
  port[330] = 0;
  port[329] = 0;
  port[328] = 0;
  port[327] = 0;
  port[326] = 0;
  port[325] = 0;
  port[324] = 0;
  port[323] = 0;
  port[322] = 0;
  port[321] = 0;
  port[320] = 0;
  port[319] = 0;
  port[318] = 0;
  port[317] = 0;
  port[316] = 0;
  port[315] = 0;
  port[314] = 0;
  port[313] = 0;
  port[312] = 0;
  memset((void *)(a1 + 2720), 0, 0x1C0u);
  return 0;
}
