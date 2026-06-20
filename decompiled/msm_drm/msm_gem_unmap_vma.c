__int64 __fastcall msm_gem_unmap_vma(__int64 result)
{
  __int64 (*v1)(void); // x8

  if ( result )
  {
    v1 = *(__int64 (**)(void))(*(_QWORD *)(result + 272) + 8LL);
    if ( v1 )
    {
      if ( *((_DWORD *)v1 - 1) != 152639838 )
        __break(0x8228u);
      return v1();
    }
  }
  return result;
}
