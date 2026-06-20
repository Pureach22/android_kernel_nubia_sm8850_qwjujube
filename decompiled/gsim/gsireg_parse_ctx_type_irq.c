void __fastcall gsireg_parse_ctx_type_irq(__int64 a1, int *a2, unsigned int a3)
{
  a2[5] = (a3 >> 1) & 1;
  a2[6] = a3 & 1;
  a2[3] = (a3 >> 3) & 1;
  a2[4] = (a3 >> 2) & 1;
  a2[1] = (a3 >> 5) & 1;
  a2[2] = (a3 >> 4) & 1;
  *a2 = (a3 >> 6) & 1;
}
