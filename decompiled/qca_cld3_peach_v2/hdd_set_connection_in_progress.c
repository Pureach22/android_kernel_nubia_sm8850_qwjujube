__int64 __fastcall hdd_set_connection_in_progress(
        char a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  _QWORD *v11; // x20
  char v12; // w8
  char v13; // w19

  context = _cds_get_context(51, (__int64)"hdd_set_connection_in_progress", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v11 = context;
    raw_spin_lock(context + 179);
    v12 = v11[178] & a1;
    if ( (v12 & 1) == 0 )
      *((_BYTE *)v11 + 1424) = a1 & 1;
    v13 = v12 ^ 1;
    raw_spin_unlock(v11 + 179);
  }
  else
  {
    v13 = 0;
  }
  return v13 & 1;
}
