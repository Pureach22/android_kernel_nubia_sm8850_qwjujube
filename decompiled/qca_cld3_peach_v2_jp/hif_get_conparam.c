__int64 __fastcall hif_get_conparam(__int64 result)
{
  if ( result )
    return *(unsigned int *)(result + 2552);
  return result;
}
