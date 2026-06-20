__int64 __fastcall _setup_ucregion_memory_map(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w2
  unsigned int v4; // w2
  __int64 v5; // x8
  __int64 (__fastcall *v6)(_QWORD); // x8

  _write_register(a1, 0xA0064u, *(_DWORD *)(a1 + 136));
  _write_register(a1, 0xA0068u, 0x400000u);
  _write_register(a1, 0xA0054u, *(_DWORD *)(a1 + 136));
  result = _write_register(a1, 0xA0050u, 1u);
  v3 = *(_DWORD *)(a1 + 664);
  if ( v3 )
    result = _write_register(a1, 0xA005Cu, v3);
  v4 = *(_DWORD *)(a1 + 488);
  if ( v4 )
    result = _write_register(a1, 0xA0060u, v4);
  v5 = *(_QWORD *)(a1 + 2512);
  if ( v5 )
  {
    v6 = *(__int64 (__fastcall **)(_QWORD))(v5 + 8);
    if ( v6 )
    {
      if ( *((_DWORD *)v6 - 1) != -639316779 )
        __break(0x8228u);
      return v6(a1);
    }
  }
  return result;
}
