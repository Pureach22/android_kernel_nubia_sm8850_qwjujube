__int64 __fastcall pattern_show(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v4; // x22
  __int64 v5; // x0
  __int64 v6; // x20
  unsigned __int64 v7; // x24
  _DWORD *v8; // x25
  __int64 v10; // x0

  v4 = *(_DWORD **)(*(_QWORD *)(a1 + 152) + 336LL);
  v5 = mutex_lock(v4 + 2054);
  if ( v4[2066] && !v4[2071] )
  {
    v7 = 0;
    v6 = 0;
    v8 = v4 + 3;
    while ( v7 != 1024 )
    {
      v5 = scnprintf(a3 + v6, 4096 - v6, "%d %u ", *v8, *(v8 - 1));
      ++v7;
      v6 += (int)v5;
      v8 += 2;
      if ( v7 >= (unsigned int)v4[2066] )
      {
        *(_BYTE *)(a3 + v6 - 1) = 10;
        goto LABEL_8;
      }
    }
    __break(0x5512u);
    v10 = MEMORY[0x710D648](v5);
    return pattern_store(v10);
  }
  else
  {
    v6 = 0;
LABEL_8:
    mutex_unlock(v4 + 2054);
    return v6;
  }
}
