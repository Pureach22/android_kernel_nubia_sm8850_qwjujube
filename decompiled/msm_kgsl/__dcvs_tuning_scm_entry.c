__int64 __fastcall _dcvs_tuning_scm_entry(__int64 a1, int a2, int a3)
{
  unsigned int v4; // w22
  unsigned int v6; // w23
  __int64 v7; // x26
  unsigned int v8; // w24
  unsigned int v9; // w22

  v4 = a3 & 0x1F | 0x20;
  if ( a2 )
  {
    if ( a2 == 2 )
    {
      v6 = 0;
      v7 = 24512;
      v8 = a3 & 0x1F | 0x20;
    }
    else
    {
      v8 = 0;
      v7 = 24508;
      v6 = a3 & 0x1F | 0x20;
    }
    v4 = 0;
  }
  else
  {
    v7 = 24504;
    v6 = 0;
    v8 = 0;
  }
  if ( (unsigned int)mutex_trylock(a1 + 24456) )
  {
    v9 = qcom_scm_kgsl_dcvs_tuning(v4, v6, v8);
    if ( !v9 )
      *(_DWORD *)(a1 + v7) = a3;
    mutex_unlock(a1 + 24456);
  }
  else
  {
    return (unsigned int)-35;
  }
  return v9;
}
