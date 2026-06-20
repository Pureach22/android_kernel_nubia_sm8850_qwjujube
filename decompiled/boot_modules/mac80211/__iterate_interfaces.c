__int64 __fastcall _iterate_interfaces(
        __int64 result,
        char a2,
        __int64 (__fastcall *a3)(__int64, char *, __int64 *),
        __int64 a4)
{
  __int64 *v4; // x23
  __int64 v6; // x24
  __int64 v8; // x21
  int v10; // w25
  int v11; // w8
  __int64 v12; // x8

  v4 = *(__int64 **)(result + 4616);
  v6 = result + 4616;
  v8 = result;
  if ( v4 != (__int64 *)(result + 4616) )
  {
    v10 = a2 & 3;
    do
    {
      v11 = *((_DWORD *)v4 + 1180);
      if ( v11 != 4
        && (v11 != 6 || (v4[283] & 0x40) != 0)
        && (v10 != 2 || (v4[203] & 0x20) != 0)
        && ((a2 & 4) == 0 || (v4[203] & 0x20) != 0)
        && ((a2 & 2) == 0 || (v4[204] & 1) != 0) )
      {
        if ( *((_DWORD *)a3 - 1) != -354692697 )
          __break(0x8233u);
        result = a3(a4, (char *)v4 + 5842, v4 + 590);
      }
      v4 = (__int64 *)*v4;
    }
    while ( v4 != (__int64 *)v6 );
  }
  v12 = *(_QWORD *)(v8 + 5384);
  if ( v12 && (*(_QWORD *)(v8 + 96) & 0x1000) != 0 && ((a2 & 3) != 2 || (*(_BYTE *)(v12 + 1624) & 0x20) != 0) )
  {
    if ( *((_DWORD *)a3 - 1) != -354692697 )
      __break(0x8233u);
    return a3(a4, (char *)(v12 + 5842), (__int64 *)(v12 + 4720));
  }
  return result;
}
