unsigned __int64 __fastcall gen8_counter_read_norestore(_QWORD *a1, __int64 *a2, unsigned int a3)
{
  __int64 v3; // x20

  v3 = *a2;
  return *(_QWORD *)(v3 + 48LL * a3 + 32) + gen8_counter_read(a1);
}
