__int64 __fastcall dp_print_nss(char *a1, _DWORD *a2)
{
  unsigned int v4; // w22
  __int64 v5; // x22
  __int64 v6; // x22
  __int64 v7; // x22
  __int64 v8; // x22
  __int64 v9; // x22
  int v10; // w0

  v4 = snprintf(a1, 0x30u, " %d", *a2);
  v5 = snprintf(&a1[v4], 48 - v4, " %d", a2[1]) + v4;
  v6 = (unsigned int)(snprintf(&a1[v5], (unsigned int)(48 - v5), " %d", a2[2]) + v5);
  v7 = (unsigned int)(snprintf(&a1[v6], (unsigned int)(48 - v6), " %d", a2[3]) + v6);
  v8 = (unsigned int)(snprintf(&a1[v7], (unsigned int)(48 - v7), " %d", a2[4]) + v7);
  v9 = (unsigned int)(snprintf(&a1[v8], (unsigned int)(48 - v8), " %d", a2[5]) + v8);
  v10 = snprintf(&a1[v9], (unsigned int)(48 - v9), " %d", a2[6]);
  return snprintf(&a1[(unsigned int)(v10 + v9)], (unsigned int)(48 - (v10 + v9)), " %d", a2[7]);
}
