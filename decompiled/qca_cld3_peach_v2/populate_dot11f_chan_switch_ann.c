void __fastcall populate_dot11f_chan_switch_ann(__int64 a1, _BYTE *a2, _BYTE *a3)
{
  char v3; // w9

  a2[1] = a3[7224];
  a2[2] = a3[7208];
  v3 = a3[7218];
  *a2 = 1;
  a2[3] = v3;
}
