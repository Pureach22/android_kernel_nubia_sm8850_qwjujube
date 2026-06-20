__int64 __fastcall mem_objects_show(__int64 a1, __int64 a2, __int64 a3)
{
  _UNKNOWN **v4; // x23
  __int64 v5; // x20
  const char *v6; // x3
  int v7; // w0

  mutex_lock(&mo_list_mutex);
  v4 = (_UNKNOWN **)mo_list;
  if ( mo_list == (_UNKNOWN *)&mo_list )
  {
    v5 = 0;
  }
  else
  {
    v5 = 0;
    do
    {
      if ( v4 == (_UNKNOWN **)&unk_C8 )
      {
        v6 = "null";
      }
      else if ( v4 == &qword_C9 )
      {
        v6 = "root";
      }
      else if ( *(v4 - 25) )
      {
        v6 = (const char *)*(v4 - 25);
      }
      else
      {
        v6 = "noname";
      }
      v7 = scnprintf(
             a3 + v5,
             4096 - v5,
             "%s %u (%llx %zx) %d\n",
             v6,
             *((_DWORD *)v4 - 48),
             *(v4 - 3),
             (size_t)*(v4 - 2),
             *((_DWORD *)v4 - 10));
      v4 = (_UNKNOWN **)*v4;
      v5 += v7;
    }
    while ( v4 != &mo_list );
  }
  mutex_unlock(&mo_list_mutex);
  return v5;
}
