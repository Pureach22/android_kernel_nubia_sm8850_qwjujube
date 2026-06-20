__int64 __fastcall syna_tcm_v1_terminate(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x19

  if ( !result )
    return printk(&unk_3365A, "syna_tcm_v1_terminate", a3);
  if ( *(_DWORD *)(result + 504) == 1 )
  {
    v3 = result;
    printk(&unk_3B33C, "syna_tcm_v1_terminate", *(unsigned __int8 *)(result + 508));
    *(_DWORD *)(v3 + 504) = 2;
    result = completion_done(v3 + 544);
    if ( (result & 1) == 0 )
      return complete(v3 + 544);
  }
  return result;
}
