__int64 ipa3_destroy_flt_tbl_idrs()
{
  __int64 result; // x0
  unsigned __int64 v1; // x19
  __int64 v2; // x21

  idr_destroy(ipa3_ctx + 28584);
  result = idr_destroy(ipa3_ctx + 28608);
  if ( *(_DWORD *)(ipa3_ctx + 34308) )
  {
    v1 = 0;
    v2 = 17928;
    do
    {
      result = ipa_is_ep_support_flt((unsigned int)v1);
      if ( (result & 1) != 0 )
      {
        if ( v1 > 0x23 )
        {
          __break(0x5512u);
          return ipa3_free_pkt_init_ex(result);
        }
        *(_QWORD *)(ipa3_ctx + v2 - 152) = 0;
        *(_QWORD *)(ipa3_ctx + v2) = 0;
      }
      ++v1;
      v2 += 304;
    }
    while ( v1 < *(unsigned int *)(ipa3_ctx + 34308) );
  }
  return result;
}
