__int64 __fastcall sde_hw_pingpong_destroy(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    kfree(*(_QWORD *)(result + 56));
    return kfree(v1);
  }
  return result;
}
