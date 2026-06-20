__int64 __fastcall populate_dot11f_power_constraints(__int64 a1, _BYTE *a2)
{
  LOBYTE(a1) = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 4627LL);
  *a2 = 1;
  a2[1] = a1;
  return 0;
}
