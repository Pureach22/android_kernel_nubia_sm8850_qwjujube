__int64 __fastcall sub_4B87EC(__int64 a1, __int64 *a2)
{
  _QWORD *v6; // x1

  _T1 = *a2;
  v6 = a2 + 4;
  __asm { STGP            X7, X4, [X1],#0x20 }
  return dp_soc_init_wifi3(a1, v6);
}
