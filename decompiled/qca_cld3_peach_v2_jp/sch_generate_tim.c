void __fastcall sch_generate_tim(__int64 a1, _BYTE **a2, _WORD *a3, char a4)
{
  _BYTE *v4; // x9
  char v5; // w10

  v4 = *a2;
  *a3 = 8;
  *v4 = 5;
  v5 = *(_BYTE *)a3;
  v4[2] = -1;
  v4[4] = -1;
  v4[3] = a4;
  v4[1] = v5;
  *a2 = v4 + 10;
}
