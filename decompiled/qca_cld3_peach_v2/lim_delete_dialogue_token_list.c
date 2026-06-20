__int64 __fastcall lim_delete_dialogue_token_list(__int64 a1)
{
  __int64 result; // x0

  for ( result = *(_QWORD *)(a1 + 8904); result; result = *(_QWORD *)(a1 + 8904) )
  {
    *(_QWORD *)(a1 + 8904) = *(_QWORD *)(result + 8);
    _qdf_mem_free(result);
  }
  *(_QWORD *)(a1 + 8912) = 0;
  return result;
}
