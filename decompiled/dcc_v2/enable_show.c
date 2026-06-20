__int64 __fastcall enable_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  unsigned int v6; // w8
  _BYTE *v7; // x9
  _BOOL4 v8; // w3
  int v9; // w11
  unsigned int v10; // w10
  __int64 v11; // x19

  v3 = *(_QWORD *)(a1 + 152);
  mutex_lock(v3 + 24);
  v6 = *(_DWORD *)(v3 + 328);
  if ( v6 <= *(unsigned __int8 *)(v3 + 332) )
  {
    dev_err(a1, "Select link list to program using curr_list\n");
    v11 = -22;
  }
  else
  {
    v7 = *(_BYTE **)(v3 + 120);
    if ( (*v7 & 1) != 0 )
    {
      v8 = 1;
    }
    else
    {
      v9 = 1;
      do
      {
        v10 = v9;
        if ( v6 == v9 )
          break;
        ++v9;
      }
      while ( v7[v10] != 1 );
      v8 = v10 < v6;
    }
    v11 = (int)scnprintf(a3, 4096, "%u\n", v8);
  }
  mutex_unlock(v3 + 24);
  return v11;
}
