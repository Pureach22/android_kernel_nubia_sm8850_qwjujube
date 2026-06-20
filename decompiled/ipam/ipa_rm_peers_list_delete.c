_QWORD *__fastcall ipa_rm_peers_list_delete(_QWORD *result)
{
  _QWORD *v1; // x19

  if ( result )
  {
    v1 = result;
    kfree(*result);
    return (_QWORD *)kfree(v1);
  }
  return result;
}
