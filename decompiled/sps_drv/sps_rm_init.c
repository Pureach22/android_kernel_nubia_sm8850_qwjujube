__int64 __fastcall sps_rm_init(_QWORD *a1)
{
  sps_rm = (__int64)a1;
  *a1 = a1;
  a1[1] = a1;
  _mutex_init(a1 + 2, "&sps_rm->lock", &sps_rm_init___key);
  return 0;
}
