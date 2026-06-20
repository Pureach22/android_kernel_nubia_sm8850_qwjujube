__int64 __fastcall ipa_rm_dep_graph_remove(__int64 a1, unsigned int a2)
{
  if ( !a1 )
    return 4294967274LL;
  if ( a2 >= 0x16 )
  {
    __break(0x5512u);
    JUMPOUT(0xFFFFFFFFFA5C60D8LL);
  }
  *(_QWORD *)(a1 + 8LL * a2) = 0;
  return 0;
}
