void __fastcall ipareg_construct_idle_indication_cfg(__int64 a1, unsigned __int16 *a2, int *a3)
{
  int v3; // w8

  v3 = *a3 | *a2;
  *a3 = v3;
  *a3 = v3 | (*((unsigned __int8 *)a2 + 2) << 16);
}
