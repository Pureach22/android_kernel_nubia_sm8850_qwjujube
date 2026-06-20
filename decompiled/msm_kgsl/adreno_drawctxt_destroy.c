__int64 __fastcall adreno_drawctxt_destroy(__int64 result)
{
  __int64 v1; // x19
  void (*v2)(void); // x8

  if ( result )
  {
    v1 = result;
    v2 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 40) + 14264LL) + 40LL) + 248LL);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != -1413602428 )
        __break(0x8228u);
      v2();
    }
    return kfree(v1);
  }
  return result;
}
