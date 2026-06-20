bool __fastcall qdf_is_macaddr_zero_0(int *a1)
{
  int v1; // w8
  int v2; // w9

  _ReadStatusReg(SP_EL0);
  v1 = *a1;
  v2 = *((unsigned __int16 *)a1 + 2);
  _ReadStatusReg(SP_EL0);
  return (v1 | v2) == 0;
}
