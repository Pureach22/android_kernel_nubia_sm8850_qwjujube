__int64 *__fastcall sde_kms_prepare_fence(
        __int64 *result,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v9; // x8
  __int64 v10; // x21
  __int64 v11; // x22
  __int64 v12; // x10
  __int64 v13; // x9

  if ( !result || !a2 || !a2[1] || !a2[9] )
    return (__int64 *)printk(&unk_253460, "sde_kms_prepare_fence");
  _ReadStatusReg(SP_EL0);
  v9 = a2[1];
  if ( *(int *)(v9 + 860) >= 1 )
  {
    v10 = 0;
    v11 = 0;
    do
    {
      v12 = a2[4];
      result = *(__int64 **)(v12 + v10);
      if ( result )
      {
        v13 = result[251];
        if ( (*(_BYTE *)(v13 + 9) & 1) != 0 || (*(_BYTE *)(v13 + 10) & 4) != 0 )
        {
          result = (__int64 *)sde_crtc_prepare_commit(result, *(_QWORD *)(v12 + v10 + 16), a3, a4, a5, a6, a7, a8);
          v9 = a2[1];
        }
      }
      ++v11;
      v10 += 56;
    }
    while ( v11 < *(int *)(v9 + 860) );
  }
  return result;
}
