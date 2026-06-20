__int64 __fastcall kgsl_bus_update(__int64 a1, int a2)
{
  unsigned __int16 *v2; // x18
  __int64 v4; // x1
  unsigned int v5; // w8
  __int64 (__fastcall *v6)(__int64, __int64); // x8
  unsigned int v7; // w8
  int v8; // w8

  if ( a2 )
  {
    if ( (*(_QWORD *)(a1 + 9128) & 4) == 0 )
      return 0;
    if ( a2 > 2 )
    {
      if ( a2 == 3 )
      {
        *(_BYTE *)(a1 + 10944) = 0;
      }
      else if ( a2 == 4 )
      {
        *(_BYTE *)(a1 + 10944) = 1;
      }
    }
    else if ( a2 == 1 )
    {
      v7 = *(_DWORD *)(a1 + 10040);
      if ( v7 >= 0x20 )
      {
        __break(0x5512u);
        __ldxr(v2);
        return kgsl_icc_set_tag(a1);
      }
      v8 = *(_DWORD *)(a1 + 10372) + *(_DWORD *)(a1 + 28LL * v7 + 9148);
      if ( *(_DWORD *)(a1 + 9156) < v8 )
        v8 = *(_DWORD *)(a1 + 9156);
      if ( v8 <= 1 )
        v8 = 1;
      *(_DWORD *)(a1 + 10936) = v8;
    }
    else if ( a2 == 2 )
    {
      *(_QWORD *)(a1 + 10384) = 0;
      *(_DWORD *)(a1 + 10936) = 1;
      *(_QWORD *)(a1 + 10372) = 0;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 10936) = 0;
    *(_QWORD *)(a1 + 10372) = 0;
    *(_QWORD *)(a1 + 10384) = 0;
  }
  v4 = *(unsigned int *)(a1 + 10936);
  if ( *(_BYTE *)(a1 + 10944) == 1 )
  {
    v5 = *(_DWORD *)(a1 + 10940);
    if ( (unsigned int)v4 <= v5 )
      v4 = v5;
    else
      v4 = (unsigned int)v4;
  }
  v6 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 8752) + 256LL);
  if ( *((_DWORD *)v6 - 1) != -1639359510 )
    __break(0x8228u);
  return v6(a1, v4);
}
