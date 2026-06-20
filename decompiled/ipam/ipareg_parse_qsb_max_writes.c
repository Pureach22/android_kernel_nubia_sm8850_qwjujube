void __fastcall ipareg_parse_qsb_max_writes(__int64 a1, int *a2, unsigned __int8 a3)
{
  *a2 = a3 & 0xF;
  a2[1] = a3 >> 4;
}
