__int64 __fastcall debug_spmi_addr_get(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(unsigned int *)(a1 + 184);
  *a2 = v2;
  return 0;
}
