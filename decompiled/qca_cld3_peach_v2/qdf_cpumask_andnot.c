bool __fastcall qdf_cpumask_andnot(_QWORD *a1, _DWORD *a2, _DWORD *a3)
{
  _BOOL4 v3; // w8

  v3 = (*a2 & ~*a3) != 0;
  *a1 = *a2 & (unsigned int)~*a3;
  return v3;
}
