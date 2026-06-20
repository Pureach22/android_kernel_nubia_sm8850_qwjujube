__int64 __fastcall hw_pattern_show(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v4; // x22
  __int64 v5; // x0
  unsigned __int64 v6; // x24
  __int64 v7; // x20
  _DWORD *v8; // x25
  __int64 v10; // x0

  v4 = *(_DWORD **)(*(_QWORD *)(a1 + 152) + 336LL);
  v5 = mutex_lock(v4 + 2054);
  if ( v4[2066] && v4[2071] == 2 )
  {
    v6 = 0;
    v7 = 0;
    v8 = v4 + 3;
    while ( v6 != 1024 )
    {
      v5 = scnprintf(a3 + v7, 4096 - v7, "%d %u ", *v8, *(v8 - 1));
      ++v6;
      v7 += (int)v5;
      v8 += 2;
      if ( v6 >= (unsigned int)v4[2066] )
      {
        *(_BYTE *)(a3 + v7 - 1) = 10;
        goto LABEL_8;
      }
    }
    __break(0x5512u);
    v10 = MEMORY[0x710D858](v5);
    return hw_pattern_store(v10);
  }
  else
  {
    v7 = 0;
LABEL_8:
    mutex_unlock(v4 + 2054);
    return v7;
  }
}
