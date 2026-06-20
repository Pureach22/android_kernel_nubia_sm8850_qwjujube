unsigned __int64 __fastcall sde_cp_create_local_blob(_QWORD *a1, int a2, int a3)
{
  _QWORD *v3; // x9
  _QWORD *v4; // x19
  unsigned int v5; // w8
  unsigned __int64 result; // x0

  v3 = a1 + 565;
  v4 = a1 + 565;
  do
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == v3 )
    {
      v5 = *((_DWORD *)v4 - 9);
      goto LABEL_8;
    }
  }
  while ( *((_DWORD *)v4 - 8) != a2 );
  v5 = *((_DWORD *)v4 - 9);
  if ( (v5 & 2) == 0 )
  {
LABEL_8:
    _drm_err("local blob create failed prop found %d flags %d\n", v4 != v3, v5);
    return 4294967274LL;
  }
  result = drm_property_create_blob(*a1, a3, 0);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    *(v4 - 3) = result;
    return 0;
  }
  return result;
}
