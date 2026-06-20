__int64 __fastcall dp_ctrl_put(__int64 result)
{
  if ( result )
    return devm_kfree(*(_QWORD *)(result + 128));
  return result;
}
