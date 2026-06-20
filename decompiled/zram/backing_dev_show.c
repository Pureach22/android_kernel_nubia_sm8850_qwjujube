const char *__fastcall backing_dev_show(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 v4; // x22
  __int64 v5; // x0
  const char *v6; // x0
  const char *v7; // x20
  size_t v8; // x21

  v4 = *(_QWORD *)(*(_QWORD *)(a1 - 224) + 88LL);
  down_read(v4 + 32);
  v5 = *(_QWORD *)(v4 + 240);
  if ( v5 )
  {
    v6 = (const char *)file_path(v5, a3, 4095);
    v7 = v6;
    if ( (unsigned __int64)v6 < 0xFFFFFFFFFFFFF001LL )
    {
      v8 = strlen(v6);
      memmove(a3, v7, v8);
      v7 = (const char *)(v8 + 1);
      a3[v8] = 10;
    }
  }
  else
  {
    v7 = (_BYTE *)&unk_5;
    a3[4] = 10;
    *(_DWORD *)a3 = 1701736302;
  }
  up_read(v4 + 32);
  return v7;
}
