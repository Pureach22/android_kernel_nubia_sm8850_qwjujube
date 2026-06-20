__int64 __fastcall adreno_probe(__int64 a1)
{
  __int64 matching_node_and_match; // x0
  __int64 v3; // x21
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  matching_node_and_match = of_find_matching_node_and_match(0, &adreno_component_match, 0);
  if ( matching_node_and_match )
  {
    v3 = matching_node_and_match;
    do
    {
      if ( (of_device_is_available(v3) & 1) != 0 )
        component_match_add_release(a1 + 16, v5, release_of, compare_of, v3);
      v3 = of_find_matching_node_and_match(v3, &adreno_component_match, 0);
    }
    while ( v3 );
  }
  if ( v5[0] )
    result = component_master_add_with_match(a1 + 16, adreno_ops);
  else
    result = 4294967277LL;
  _ReadStatusReg(SP_EL0);
  return result;
}
