__int64 __fastcall ipa_rm_dep_graph_get_resource(__int64 a1, unsigned int a2, _QWORD *a3)
{
  unsigned int v5; // w0
  __int64 v6; // x5
  void *v7; // x6
  __int64 v8; // x8
  __int64 result; // x0

  if ( !a1 )
    return 4294967274LL;
  if ( a2 <= 0x15 && (a2 & 1) == 0 )
  {
    v5 = ipa_rm_prod_index(a2);
    if ( v5 != -1 )
      goto LABEL_5;
    return 4294967274LL;
  }
  result = 4294967274LL;
  if ( (a2 & 1) == 0 || a2 > 0x15 )
    return result;
  v5 = ipa_rm_cons_index(a2);
  if ( v5 == -1 )
    return 4294967274LL;
LABEL_5:
  if ( v5 >= 0x16 )
  {
    __break(0x5512u);
    __arm_mte_set_tag((void *)(v6 + 2272), v7);
    __arm_mte_set_tag((void *)(v6 + 2288), v7);
    JUMPOUT(0x1A8D98);
  }
  v8 = *(_QWORD *)(a1 + 8LL * v5);
  *a3 = v8;
  if ( v8 )
    return 0;
  else
    return 4294967274LL;
}
