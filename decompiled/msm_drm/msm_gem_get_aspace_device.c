_QWORD *__fastcall msm_gem_get_aspace_device(_QWORD *result)
{
  __int64 (*v1)(void); // x8

  if ( result )
  {
    result = (_QWORD *)result[32];
    if ( result )
    {
      v1 = *(__int64 (**)(void))(*result + 104LL);
      if ( v1 )
      {
        if ( *((_DWORD *)v1 - 1) != 64873426 )
          __break(0x8228u);
        return (_QWORD *)v1();
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}
