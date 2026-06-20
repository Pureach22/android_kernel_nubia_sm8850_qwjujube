__int64 __fastcall store_second_vote_limit(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  int v7; // w0
  __int64 *v8; // x8
  __int64 v9; // x0
  int updated; // w0
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 8);
  if ( *(_BYTE *)(v4 + 84) == 1 )
  {
    v12 = 0;
    v7 = kstrtouint(a3, 10, &v12);
    if ( v7 < 0 )
    {
      a4 = v7;
    }
    else if ( v12 != *(_DWORD *)(v4 + 88) )
    {
      mutex_lock(a1 + 144);
      if ( v12 < *(_DWORD *)(a1 - 324) )
      {
        *(_DWORD *)(a1 - 324) = v12;
        v8 = *(__int64 **)(v4 + 56);
        v9 = v8[14];
        if ( !v9 )
          v9 = *v8;
        updated = qcom_dcvs_update_votes(v9, a1 - 336, 3, *(unsigned int *)(v4 + 68));
        if ( updated < 0 )
          dev_err(*(_QWORD *)(v4 + 56), "second vote update failed: %d\n", updated);
      }
      *(_DWORD *)(v4 + 88) = v12;
      mutex_unlock(a1 + 144);
    }
  }
  else
  {
    a4 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
