__int64 __fastcall _append__async_reqs(__int64 a1)
{
  __int64 v2; // x0
  unsigned __int64 v3; // x1

  v2 = async_si_buffer();
  return prepare_objects(a1, v2, v3);
}
