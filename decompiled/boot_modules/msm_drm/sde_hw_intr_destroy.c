__int64 __fastcall sde_hw_intr_destroy(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    kfree(*(_QWORD *)(result + 320));
    kfree(*(_QWORD *)(v1 + 336));
    kfree(*(_QWORD *)(v1 + 296));
    return kfree(v1);
  }
  return result;
}
