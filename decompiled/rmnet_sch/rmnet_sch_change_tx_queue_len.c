__int64 __fastcall rmnet_sch_change_tx_queue_len(_DWORD *a1, unsigned int a2)
{
  unsigned int v4; // w10

  a1[134] = a2 / 0xA;
  a1[105] = 8 * (a2 / 0xA);
  v4 = 2 * (a2 / 0xA);
  a1[104] = 4 * (a2 / 0xA);
  a1[125] = 4 * (a2 / 0xA);
  a1[124] = v4;
  a1[114] = 3 * (a2 / 0xA);
  a1[115] = 6 * (a2 / 0xA);
  a1[135] = v4;
  return 0;
}
