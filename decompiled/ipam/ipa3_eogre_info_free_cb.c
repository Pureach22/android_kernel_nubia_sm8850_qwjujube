__int64 __fastcall ipa3_eogre_info_free_cb(__int64 result)
{
  if ( result )
    return kfree(result);
  return result;
}
