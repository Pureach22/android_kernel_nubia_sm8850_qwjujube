void __fastcall ipareg_parse_hps_queue_weights(__int64 a1, int *a2, unsigned int a3)
{
  *a2 = a3 & 0xF;
  a2[1] = (unsigned __int8)a3 >> 4;
  a2[2] = (a3 >> 8) & 0xF;
  a2[3] = (unsigned __int16)a3 >> 12;
}
