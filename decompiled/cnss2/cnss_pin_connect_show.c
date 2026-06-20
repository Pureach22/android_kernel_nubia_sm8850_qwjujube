__int64 __fastcall cnss_pin_connect_show(__int64 a1)
{
  _DWORD *v1; // x20

  v1 = *(_DWORD **)(a1 + 128);
  seq_write();
  seq_printf(a1, "FW power pin result: %04x\n", v1[1560]);
  seq_printf(a1, "FW PHY IO pin result: %04x\n", v1[1561]);
  seq_printf(a1, "FW RF pin result: %04x\n", v1[1562]);
  seq_printf(a1, "Host pin result: %04x\n", v1[1563]);
  seq_putc(a1, 10);
  return 0;
}
