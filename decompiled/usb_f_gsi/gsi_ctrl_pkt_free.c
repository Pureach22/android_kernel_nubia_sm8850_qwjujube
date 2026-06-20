_QWORD *__fastcall gsi_ctrl_pkt_free(_QWORD *result)
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
