void __fastcall gsireg_construct_cntxt_gsi_irq_en(__int64 a1, _BYTE *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8

  v3 = *a3 | (8 * (*a2 != 0));
  *a3 = v3;
  v4 = v3 | (4 * (a2[1] != 0));
  *a3 = v4;
  v5 = v4 | (2 * (a2[2] != 0));
  *a3 = v5;
  *a3 = v5 | (a2[3] != 0);
}
