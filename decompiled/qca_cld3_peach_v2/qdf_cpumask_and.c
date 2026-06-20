bool __fastcall qdf_cpumask_and(_QWORD *a1, _DWORD *a2, _DWORD *a3)
{
  _BOOL4 v3; // w8

  v3 = (*a2 & *a3) != 0;
  *a1 = (unsigned int)(*a2 & *a3);
  return v3;
}
