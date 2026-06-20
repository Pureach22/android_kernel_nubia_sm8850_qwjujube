__int64 __fastcall devm_icc_clk_register(__int64 a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x19
  unsigned int v4; // w20
  int v5; // w8
  __int64 v6; // x22
  _BYTE *v7; // x23
  __int64 v8; // x21

  v2 = ((__int64 (*)(void))icc_clk_register)();
  v3 = v2;
  if ( v2 < 0xFFFFFFFFFFFFF001LL )
  {
    v4 = _devm_add_action(a1, devm_icc_release, v2, "devm_icc_release");
    if ( v4 )
    {
      icc_provider_deregister(v3);
      icc_nodes_remove(v3);
      v5 = *(_DWORD *)(v3 + 104);
      if ( v5 >= 1 )
      {
        v6 = 0;
        v7 = (_BYTE *)(v3 + 120);
        do
        {
          if ( *v7 == 1 )
          {
            v8 = *((_QWORD *)v7 - 1);
            clk_disable(v8);
            clk_unprepare(v8);
            v5 = *(_DWORD *)(v3 + 104);
          }
          ++v6;
          v7 += 16;
        }
        while ( v6 < v5 );
      }
    }
  }
  else
  {
    return (unsigned int)v2;
  }
  return v4;
}
