void __fastcall gsireg_parse_cntxt_glob_irq_stts(__int64 a1, bool *a2, char a3)
{
  *a2 = (a3 & 8) != 0;
  a2[1] = (a3 & 4) != 0;
  a2[2] = (a3 & 2) != 0;
  a2[3] = a3 & 1;
}
